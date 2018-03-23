#!/usr/bin/env python

import re
import argparse
import sys
import os.path
import subprocess
from collections import OrderedDict


# TOTO:
# Generate code to protect for out-of-range index in selection expressions
# Improve cutflow

indent = ' ' * 2

block_start = re.compile(r'object|collection|variable|cut|region|function|table')
re_indented = re.compile(r'^\s')

analysis_code_template = """// -*- C++ -*-
#include <iostream>
#include "Rivet/Analysis.hh"
#include "Rivet/Tools/Cutflow.hh"

%INCLUDE_BLOCK%

namespace Rivet {


  class %ANALYSIS_NAME%: public Analysis {
  public:

    ///Cut flow ids
    %DECL_CF_IDS%

    /// Constructor
    %ANALYSIS_NAME%():
      Analysis("%ANALYSIS_NAME%")
    {  
       %CFS_INIT%
    }


    /// Book histograms and initialise projections before the run
    void init() {

      FinalState fs;
      VisibleFinalState visfs(fs);

      %FS_PROJ_INIT%

      %PROJECTION_INIT%

      %COUNTER_INIT%
    }

    %OBJECT_CUTS%

    %FUNCTION_DEFINITIONS%

    /// Perform the per-event analysis
    void analyze(const Event& event) {

       %PARTICLES_DEFINITION%

       %OBJECT_DEFINITIONS%

       %WEIGHT%

       %CUTS%

       %COUNTER_FILL%

    }


    /// Normalise histograms etc., after the run
    void finalize() {
       std::cout << "Analsyis cut flow:\\n"
                 << "-----------------\\n\\n"
                 << cutflows << "\\n";
    }


  protected:

    //@{
    /** Collections and variables
     */
    //@}
     %OBJECT_DECLARATION%

    //@{
    /** Histograms
     */
    %COUNTER_DECLARATION%
    //@}

    %CFS_DECL%

  };
  DECLARE_RIVET_PLUGIN(%ANALYSIS_NAME%);
}\n"""

class FileReader:
    def __init__(self, filename):
       self.name = filename
       self.f = open(filename)
       self.stored_pos = 0
       self.current_line = 0
       self.stored_line = 0
       self.current_line_contents = ""
       
    def save_pos(self):
        self.stored_pos = self.f.tell()
        self.stored_line = self.current_line

    def restore_pos(self):
        self.f.seek(self.stored_pos)
        self.current_line = self.stored_line

    def readline(self):
        self.current_line_contents = self.f.readline()
        self.current_line += 1
        return self.current_line_contents

class FuncDef:
    def __init__(self, template_line = None, return_type = None, name = None, arg_list = None, body = None, source_file = None):
        self.template_line = template_line
        self.return_type = return_type
        self.name = name
        self.arg_list = arg_list  # (type, name)
        self.body = body
        self.source_file = source_file
    #enddef __init__
    
    def rivet_code(self):
        '''Generate c++ code to incluse in the Rivet analysis class'''
        code_template = '''%TEMPLATE_LINE%
%RETURN_TYPE% %FUNC_NAME%(%ARG_LIST%){
%FUNC_BODY%
}'''

        subst_map = { "%TEMPLATE_LINE%": self.template_line,  \
                      "%RETURN_TYPE%": self.return_type, \
                      "%FUNC_NAME%": self.name, \
                      "%ARG_LIST%": self.arg_list, \
                      "%FUNC_BODY%": self.body}
        
        return block_replace(code_template, subst_map)
    #endef rivet_code
#end class FuncDef

class CutNode:
    def __init__(self, name):
        self.name = name
        self._dependencies = [] #list of cut blocks this block depends on
        self.endpoint = True    #True if no other cut block depends on this one
        self.cuts = []          #List of selection conditions
        self.cutflows = []      #list of cut flows (identified by their endpoint cut) this cut is in.
        self.order = 0          #number of single cut preceeding the first cut of this cut block in any cut flow.
    #enddef __init__
    def add_dependency(self, c):
        if len(self._dependencies) > 0:
            raise Runtime("The cut block %s violates the rule requiring that a cut block depends on maximum another cut block." % name)
        c.endpoint = False
        self._dependencies.append(c)
    #enddef add_dependency
    def add_dependencies(self, cc):
        for c in cc:
            self.add_dependency(c)
        #next c
    #enddef add_dependencies
    def dependencies(self):
        return self._dependencies
    #enddef dependencies
#end class CutNode

include_block = ""
includes = []
proj_init = ""
counter_init = ""
obj_def = ""
weight_funcs = {}
counter_fill = ""
counter_decl = ""
outfile = None
names = {"cutflow": 0, "CutIds": 0}
func_codes = []
tables = {}
table_types = ["events", "limits", "cutflow", "corr", "bkg"]
histo_booking = ""

#command to compile provided c++ code
compile_cmd = ["g++", "-c", "-Wall", "-Werror", "-I../code_lib/include" ]

#Meta information on the analysis read from "info analysis" Lhada block
ana_info = {}

#list of cuts used to define object collection
obj_cuts = []

#list of cut ids used for to identify the cut in the cutflow
#cut_ids = []

#list of objects defined in LHADA file. Associate object name with its c++-code name mapped_name
#In same rare case the two name can differ.
particles = "particles"
objects = OrderedDict([("Particles", particles)])

#Map object (cpp name) to types including intermediat object, i.e. not defined in LHADA file.
types = { particles: "Particles"}

#list of defined cuts with their dependencu on other cut block
# key: cut block name, value: CutNode object
cutblocks = {}

# List of cutflows.
# key: cut flow name, [cut list]
cutflows = OrderedDict()

#list of functions defined in the lhada file
#the list maps function names to its FuncDef object instance
funcs_lhada = {}

#list of all functions read from c++ files references in the function blocks
#elements
funcs_all = []

#List of c++ files read to fill the funcs_all list
cpp_files = []

#return types of defined functions listed in functions
#If the value (v) is a int then it refers to the type of
#the (v+1)-nth argument: the function is templated and
#returns an instance of the same type as this argument.
#In case of a fixed return type the c type name is specified
#as a string
#func_return_types = {}

jetAk04Eta48Proj = None
atlasCaloFs = None

#Flag indicating if a cast operator from Vector3 to FourMomentum is required
vector3ToFourMometum = False

#List of code files accompagnying the lhada description
#Code validity is checked before adding the file to the list
code_files = []

#different ways to call a LHADA object block:
object_aliases = ["object", "variable", "collection"]

#list of include files to exclude from generated code
#(because of replacement with Rivet functionnality)
excluded_includes = [ "LhadaParticle.h", "LhadaJet.h", "FourMomentum.h", "lhada_tools.h" ]

def tonth(i):
    '''convert number 1, 2, 3, etc. to 1st, 2nd, 3rd, etc'''
    a = ["0th", "1st", "2nd", "3rd" ]
    if i < len(a):
        return a[i]
    else:
        return "%dth" % i

def gen_RecoObj(object, partName, etaAcc, effTag, smearTag, cuts, localVar):
    global proj_init, obj_def
    insert_include("Rivet/Tools/SmearingFunctions.hh")
    insert_include("Rivet/Projections/PromptFinalState.hh")
    insert_include("Rivet/Projections/SmearedParticles.hh")
    pidName = partName.upper()
    truthParts = unique_name("Truth%ss" % partName)
    truthPartFS = unique_name("Truth%sFS" % partName)
    if localVar:
        type_decl = "Particles "
    else:
        type_decl = ""
    #endif
    proj_init += multi_replace('''PromptFinalState %TRUTH_PART_FS%(Cuts::abseta < %ETA_ACC% && Cuts::abspid == PID::%PID_NAME%, true, true);
declare(%TRUTH_PART_FS%, "%TRUTH_PARTS%");
declare(SmearedParticles(%TRUTH_PART_FS%, %EFF_TAG%, %SMEAR_TAG%), "%OBJECT%");\n''',
                                { "%TRUTH_PART_FS%": truthPartFS, \
                                  "%EFF_TAG%": effTag, \
                                  "%SMEAR_TAG%": smearTag, \
                                  "%ETA_ACC%": etaAcc, \
                                  "%PID_NAME%": pidName, \
                                  "%TRUTH_PARTS%": truthParts, \
                                  "%OBJECT%": object}
    )
    #FIXME: postpone the projection until the object is used, so we can includes the cuts
    #and avoid an intermediate object ?
    if cuts is None:
        cuts = ""
    obj_def += multi_replace('''%TYPE_DECL%%OBJECT% = applyProjection<ParticleFinder>(event, "%OBJECT%").particles(%CUTS%);
''', { "%OBJECT%": object, \
       "%CUTS%": cuts, \
       "%TYPE_DECL%": type_decl});
    return ("Particles", object)
#enddef

def gen_ElectronAtlas_00(object, cuts, localVar):
    return gen_RecoObj(object, "Electron", "2.5", "ELECTRON_EFF_ATLAS_RUN2", "ELECTRON_SMEAR_ATLAS_RUN2", cuts, localVar)

def gen_MuonAtlas_00(object, cuts, localVar):
    return gen_RecoObj(object, "Muon", "2.7", "MUON_EFF_ATLAS_RUN2", "MUON_SMEAR_ATLAS_RUN2", cuts, localVar)

def gen_ElectronCms_00(object, cuts, localVar):
    return gen_RecoObj(object, "Electron", "2.5", "ELECTRON_EFF_CMS_RUN2", "ELECTRON_SMEAR_CMS_RUN2", cuts, localVar)

def gen_MuonCms_00(object, cuts, localVar):
    return gen_RecoObj(object, "Muon", "2.7", "MUON_EFF_CMS_RUN2", "MUON_SMEAR_CMS_RUN2", cuts, localVar)


### def gen_ElectronAtlas_00(object):
###     truthElectrons = unique_name("TruthElectrons")
###     truthElectronFS = unique_name("TruthElectronFS") 
###     proj_init = multi_replace('''PromptFinalState es(Cuts::abseta < 2.5 && Cuts::abspid == PID::ELECTRON, true, true);
### declare(%TRUTH_ELECTRON_FS%, "%TRUTH_ELECTRONS%");
### declare(SmearedParticles(es, ELECTRON_EFF_ATLAS_RUN2, ELECTRON_SMEAR_ATLAS_RUN2), %OBJECT%)''',
###                                 { "%TRUTH_ELECTRON_FS%": truthElectronFS, \
###                                   "%TRUTH_ELECTRONS%": truthElectrons, \
###                                   "%OBJECT%", object
###                                 })
###     #FIXME: postpone the projection until the object is used, so we can includes the cuts
###     #and avoid an intermediate object ?
###     obj_def = multi_replace('''%OBJECT% = apply<ParticleFinder>(event, "%OBJECT%").particles()
### ''', { "%OBJECT%": object});
###     return ("Particles", object)
### #enddef
### 
### def gen_MuonAtlas_00(object, uid):
###     truthMuons = unique_name("TruthMuons")
###     truthMuonFS = unique_name("TruthMuonFS") 
###     proj_init = multi_replace('''PromptFinalState es(Cuts::abseta < 2.5 && Cuts::abspid == PID::MUON, true, true);
### declare(%TRUTH_MUON_FS%, "%TRUTH_MUONS%");
### declare(SmearedParticles(es, MUON_EFF_ATLAS_RUN2, MUON_SMEAR_ATLAS_RUN2), %OBJECT%)''',
###                                 { "%TRUTH_MUON_FS%": truthMuonFS, \
###                                   "%TRUTH_MUONS%": truthMuons, \
###                                   "%OBJECT%", object
###                                 })
###     #FIXME: postpone the projection until the object is used, so we can includes the cuts
###     #and avoid an intermediate object ?
###     obj_def = multi_replace('''%OBJECT% = apply<ParticleFinder>(event, "%OBJECT%").particles()
### ''', { "%OBJECT%": object});
###     return ("Particles", object)
### #enddef

def getAtlasCaloFs():
    global atlasCaloFs, proj_init
    if not atlasCaloFs:
        atlasCaloFS = unique_name("caloFS")
        proj_init += multi_replace('''FinalState %CALO_FS%(Cuts::abseta < 4.8);
''', { "%CALO_FS%": atlasCaloFS })
    #endif
    return atlasCaloFS
        
def getJetAk04Eta48Proj():
    global jetAk04Eta48Proj, proj_init
    if not jetAk04Eta48Proj:
        caloFS = getAtlasCaloFs()
        jetAk04Eta48Proj = unique_name("jetAk04Eta48Proj")
        includes.append("Rivet/Projections/FastJets.hh")
        proj_init += multi_replace('''FastJets %JET_PROJ%(%CALO_FS%, FastJets::ANTIKT, 0.4);
declare(%JET_PROJ%, "%JET_PROJ%");
''',  { "%CALO_FS%": caloFS, \
        "%JET_PROJ%": jetAk04Eta48Proj})
    #endif
    return jetAk04Eta48Proj
    
    
def gen_MetAtlas_00(object, cuts, localVar):
    global proj_init, obj_def, vector3ToFourMometum
    truthMET   = unique_name("TruthMET")
    caloFS = getAtlasCaloFs()
    if cuts:
        raise RuntimeError("Error file %s, line %d. reject/select directive cannot be applied on MET" %  (lhadafile.current_line, lhadafile.name))
    #endif
    insert_include("Rivet/Projections/SmearedMET.hh")
    insert_include("Rivet/Projections/MissingMomentum.hh")
    if localVar:
        type_decl = "FourMomentum "
    else:
        type_decl = ""
    #endif
    proj_init += multi_replace('''MissingMomentum %TRUTH_MET%(%CALO_FS%);
declare(%TRUTH_MET%, "%TRUTH_MET%");
declare(SmearedMET(%TRUTH_MET%, MET_SMEAR_ATLAS_RUN2), "%RECO_MET%");
''',  { "%CALO_FS%": caloFS, \
        "%TRUTH_MET%": truthMET, \
        "%RECO_MET%": object})
    obj_def += multi_replace('''%TYPE_DECL%%OBJECT% = - toFourMomentum(applyProjection<SmearedMET>(event, "%RECO_MET%").vectorMPT());
''', { "%OBJECT%": object, \
       "%RECO_MET%": object, \
       "%TYPE_DECL%": type_decl})
    vector3ToFourMometum = True
    return ("FourMomentum", object)
#enddef    

jetAk04Atlas_00_proj = None
def getJetAk04Atlas_00_proj():
    global jetAk04Atlas_00_proj, proj_init, obj_def
    insert_include("Rivet/Projections/SmearedJets.hh")
    if not jetAk04Atlas_00_proj:
        jetAk04Atlas_00_proj = unique_name("recoJetAk04")
        genJetProj = getJetAk04Eta48Proj()
        proj_init += multi_replace('''declare(SmearedJets(%GEN_JET_PROJ%, JET_SMEAR_ATLAS_RUN2, JET_BTAG_ATLAS_RUN2_MV2C20), "%RECO_JET_PROJ%");
''', { "%GEN_JET_PROJ%": genJetProj, \
       "%RECO_JET_PROJ%": jetAk04Atlas_00_proj})
    obj_def += multi_replace('''SmearedJets %RECO_JET_PROJ% = applyProjection<SmearedJets>(event, "%RECO_JET_PROJ%");
''', {"%RECO_JET_PROJ%": jetAk04Atlas_00_proj})
    #endif
    return jetAk04Atlas_00_proj
    
def gen_JetAk04Atlas_00(object, cuts, localVar):
    global obj_def
    if cuts is None:
        cuts = ""
    if localVar:
        type_decl = "Jets "
    else:
        type_decl = ""
    #endif
    recoJetProj = getJetAk04Atlas_00_proj()
    obj_def += multi_replace('''%TYPE_DECL%%OBJECT% = %PROJ%.jetsByPt(%CUTS%);
''', {"%OBJECT%": object, \
      "%CUTS%": cuts, \
      "%PROJ%": recoJetProj, \
      "%TYPE_DECL%": type_decl})
    return ("Jets", object)
    
#Supported 'external' object and map with the function that generates the Rivet code
external_objs= { \
#         "Particle": gen_Particle, \
#         "JetAk04-00": gen_JetAk04_00, \
#         "JetAk05-00": gen_JetAk05_00, \
#         "JetAk08-00": gen_JetAk08_00, \
#         "Photon-Cms-00": gen_PhotonCms_00, \
#         "Electron-Cms-00": gen_ElectronCms_00, \
#         "Muon-Cms-00": gen_MuonCms_00, \
#         "Met-Cms-00": gen_MetCms_00, \
#         "Jet-CmsAk05-00": gen_JetCmsAk05_00, \
#         "Photon-Atlas-00": gen_PhotonAtlas_00, \
         "Electron-AtlasRun2-00": gen_ElectronAtlas_00, \
         "Muon-AtlasRun2-00": gen_MuonAtlas_00, \
         "Met-AtlasRun2-00": gen_MetAtlas_00, \
         "JetAk04-AtlasRun2-00": gen_JetAk04Atlas_00, \
#         "JetAk06-00": gen_JetAtlasAk06_00, \
         #         "ST-Atlas-00": gen_STAtlas_00 \
}

def unique_name(name):
    """Generate a unique name to be used in the analysis code as variable name or projection tag. If the name has not been used yet (first call with this value) the name is return as is, otherwise a sequential number is appended to it"""
    global names
    try:
        i = names[name] + 1
        names[name] = i

#        mess('%s already used and mapped to %s.\n List of names:' % (name, name+str(i), ",".join(names)))
        
        return name + str(i)
    except KeyError:
        names[name] = 0
        return name
#enddef

def check_code(filename):
    '''Check validity of a source file by trying to compile it with g++'''
    #Check first availability of the compiler:
    cmd = [compile_cmd[0], "--version"]
    try:
        rc = subprocess.call(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    except OSError:
        rc = 1
    if rc != 0:
        raise RuntimeError("Compiler %s is required, while it was not found. Please check it is available in the default search paths defined by PATH environment variable." \
                           % cmd)
        
    cmd = compile_cmd
    cmd.extend(["-I", os.path.dirname(lhadafile.name)])
    cmd.append(filename)
    rc = subprocess.call(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if rc != 0:
        raise RuntimeError("C++ code in file %s is not valid. Please to check it can be compiled with the following command:\n %s" \
                           % (filename, " ".join(cmd)))
    #endif
#enddef

def trans_func(code):
    '''Make the modifications of function c++ code read from LHADA input file required before inserting it in the Rivet analysis code'''
    #TODO: Check LHADPArticle -> Particle method mapping
    for (lhada_t, rivet_t) in (("LhadaParticle", "Particle"), ("LhadaJet", "Jet")):
        r = re.compile(r'\b(std::)vector\s*<\s*%s\s*>' % lhada_t)
        code = r.sub('%ss' % rivet_t, code)
        r = re.compile(r'\b%s\b' % lhada_t)
        code = r.sub(rivet_t, code)
    return code



def get_func_code(file, func_name):
    '''Search for a function with name <func_name> in the c/c++ file <file>. Returns FuncDef object.'''
    global funcs_all
    read_cpp_file(file)
    r = None
    for f in funcs_all:
        if f.name == func_name and f.source_file != file:
            print '>>2', func_name, f.source_file, file
        if f.name == func_name and f.source_file == file:
            if r:
                for f in funcs_all:
                    print f.name, f.source_file
                raise RuntimeError("Error. The function %s was declared multiple times in the file %s. A function defined in the lhada file should be uniquely defined in the provided source file and overloading (functions with same name and differenet argument list) is not possible." % (func_name, file))
            r = f
        #endif
    #next f
    return r
#enddef

#def get_func_code(file, func_name):
#    '''Search for a function with name <func_name> in the c/c++ file <file>. Returns a list with in order the possible template defintion line, the function return type, the function name (i. e. func_name), and the function body without its curly brackets.'''
def read_cpp_file(file):
    '''Read a C++ code file to store the function definitions'''
    global cpp_files, funcs_all
    if file in cpp_files:
        return
    else:
        cpp_files.append(file)
    
    state = "init"
    comment_line = re.compile(r'^\s*//')
    il = 0
    re_split = re.compile(r"([{}<>\s()])")
    re_id = re.compile(r"[a-zA-Z_][a-zA-Z0-9_]*")
    re_include = re.compile(r'^\s*#include\s+(<[^>]+>|"[^"]+")')
    re_c_comment_start = re.compile(r'^/\*')
    re_c_comment_stop = re.compile(r'\*/$')
    func_found = False
    arg_list = ""
    func_name = ""
    func_body = ""
    template_line = ""
    r = None
    bra = 0
    if file not in code_files:
        check_code(file)
        code_files.append(file)
    for l in open(file):
        il += 1
        if comment_line.match(l):
            continue
        m = re_include.match(l)
        if m:
            file_to_include = m.groups()[0]
            insert_include(file_to_include)
            continue
        #endif m
        for t in re_split.split(l):
##            if len(t.strip()) > 0:
            ##                sys.stdout.write("\nState: %s; Next token: %s" % (state, t))
            ##else:
            ##    sys.stdout.write(".")
            t_stripped = t.strip()
            if re_c_comment_start.match(t) and state != "comment":
                stored_state = state
                state = "comment"
                continue
            if re_c_comment_stop.match(t) and state == "comment":
                state = stored_state
                continue
            if state in ["init", "return_type" ] and t_stripped == "template":
                stored_state = state
                state = "template"
                template_line = t
                continue
            if state == "init" and t_stripped == "class":
                #TODO: we could skip the class definition....
                raise RuntimeError("A class definition was found line %d of file %s. Provided c++ code should not contain class definition outside a function body." % (il, file))
            if state == "template":
                template_line += t
                if t_stripped == "<":
                    state = "template_arg"
                    continue
                else:
                    raise RuntimeError("Syntax error in file %s, line %."% (file, il))
            if state == "template_arg":
                template_line += t
                if t_stripped == ">":
                    template_line += "\n"
                    state = stored_state
                continue
            if len(t_stripped) > 0 and state == "init":
                return_type = t
                state = "return_type"
                continue
            if state == "return_type":
                if t in ["const", "static"]:
                    return_type += t
                    continue
                if t_stripped == "<":
                    bra += 1
                    return_type += t
                    continue
                if t_stripped == ">" and bra > 0:
                    bra -= 1
                    return_type += t
                    continue
                if bra > 0:
                    return_type += t
                    continue
                if len(t_stripped) == 0:
                    return_type += t
                    continue
                state = "look_for_("
                func_name = t_stripped
#                if this_func == func_name:
#                    mess("Found the function %s we were looking for at line %d of file %s." % (func_name, il, file))
#                    if func_found: #function was already found. multiple definition
#                        raise RuntimeError("Found multiple definitions of function %s in the file %s. This is not supported (including overloaded function." % (func_name, file))
#                    func_found = True
                continue
            if state == "look_for_(":
                if t_stripped == "(":
                    state = "args"
                    continue
                elif len(t_stripped) > 0:
                    raise RuntimeError("Syntax error in file %s, line %d."% (file, il))
                continue
            if state == "args":
                if t_stripped == ")":
                    stored_state = "function_body"
                    state = "look_for_{"
                    continue
                arg_list += t
                continue
            if state == "comma":
                if t != ",":
                    raise RuntimeError("Syntax error in file %s, line %d. A comma is missing." % (file, il))
                state = stored_state
                continue
            if state == "look_for_{":
                if len(t_stripped) == 0:
                    continue
                if t_stripped != "{":
                    raise RuntimeError("Syntax error in file %s, line %d. An opening curly bracket is missing."% (file, il))
                state = stored_state
                nopened_curly_brackets = 1
                continue
            if state == "function_body":
                if t_stripped == "{":
                    nopened_curly_brackets += 1
                if t_stripped == "}":
                    nopened_curly_brackets -= 1
                if nopened_curly_brackets == 0:
                    #TODO: check for multideclaration of function?
                    #TODO: check for arguments and support overloaded functions ?
                    f = FuncDef(template_line = template_line, \
                                return_type = trans_func(return_type), \
                                name = func_name, \
                                arg_list = trans_func(arg_list), \
                                body = trans_func(func_body), \
                                source_file = file)
                    funcs_all.append(f)
                    #if func_found:
                    #    #store result
                    #    r = (template_line, trans_func(return_type), func_name, trans_func(arg_list), trans_func(func_body))
                    #    func_found = False
                    (template_line, return_type, arg_list, func_body) = ("", "", "", "")
                    state = "init"
                    #endif func_found
                else:
                    func_body += t
                continue
            #endif state == "function_body"
        #next t(oken)
    #next l(ine)
#    return r
#enddef


def mess(m):
    if args.verbose:
        sys.stderr.write("%s\n" % m);

def insert_include(filepath):
    """Add a header file to the list of files to include"""
    if filepath not in includes: #File not already included
        includes.append(filepath)
    #endif
#enddef

def report_syntax_error(line_num, filename, line, message = ""):
    if message and len(message) > 0:
        message = " " + message + "."
    #endif    
    mess = "Syntax error in line %d of file %s.%s\n\t%s\n" % (line_num, filename, message, line)
    #sys.stderr.write(mess)
    raise RuntimeError(mess)

def compose_rivet_cuts(cuts):
    '''Generate code to perform an object cut using a combination of standard Rivet cuts. Returns None in the case the expression is too complex.'''
    #TODO add support to parentheses.
    cut = r"\s*\(?(pt|E|m|rapidity|\|\s*rapidity\s*\|charge|\|\s*charge\s*\|pid|\|\s*pid\s*\|phi)\s*(<|>|<=|>=|!=|==)\s*((0|[1-9]\d*)(\.\d*)?|\.\d+)([eE][+-]?\d+)?\)?"
    r = re.compile(r"^%s\s*((&&|\|\||and|or)\s*%s)*$" % (cut, cut))

    combined_cut = ""
    op = ""
    for c in cuts:
        #TODO omit parentheses when they are not needed
        combined_cut += "%s(%s)" % (op, c)
        op = " && "
    #next c

    if not r.match(combined_cut):
        return None
    
    insert_include('Rivet/Tools/Cuts.hh')
    re.sub(r"\bpt\b", "Cuts::pT", combined_cut)
    re.sub(r"\bE\b", "Cuts::E", combined_cut)
    re.sub(r"\bm\b", "Cuts::mass", combined_cut)
    re.sub(r"\brapidity\b", "Cuts::rap", combined_cut)
    re.sub(r"\b\|\s*rapidity\s*\|\b", "Cuts::absrap", combined_cut)
    re.sub(r"\bcharge\b", "Cuts::charge", combined_cut)
    re.sub(r"\b\|\s*charge\s*\|\b", "Cuts::abscharge", combined_cut)
    re.sub(r"\bpid\b", "Cuts::pid", combined_cut)
    re.sub(r"\b\|\s*pid\s*\|\b", "Cuts::abspid", combined_cut)
    re.sub(r"\bphi\b", "Cuts::phi", combined_cut)
    re.sub(r"\band\b", "&&", combined_cut)
    re.sub(r"\bor\b", "||", combined_cut)

    return combined_cut


def gen_antikt(input_obj, dR, ptmin, etamax, cuts, output_obj):
    global proj_init, obj_def, particles, lhadafile

    #TODO: support for other inputs than external/particles?
    if input_obj != particles:
        raise RuntimeError("Error in line %d of file %s: antikt function is supported only for object with 'take external' or 'take particles'.\n" % (lhadafile.current_line, lhadafile.name))
    
    insert_include("Rivet/Projections/FastJets.hh")
    name = output_obj
    projname = unique_name(output_obj + "Proj")
    proj_init += 'addProjection(FastJets(fs, FastJets::ANTIKT, %g), "%s");\n' % (dR, name)
#    cutname = output_obj + "Cut"
    if cuts:
        cut_expr = compose_rivet_cuts(cuts)
    else:
        cut_expr = ""
    #TODO: support for complex cuts
    if cut_expr is None:
        #TODO: check lhada file line number and fix it if not correct
        raise RuntimeError("Error while generating for the object %s defined line %d of file %s. Only standard cuts are supported for jet inputs." % (output_obj, lhadafile.current_line, lhadafile.name))
    obj_def += multi_replace('''const FastJets& jetPro = applyProjection<FastJets>(event, "JETS");
OBJ_TYPE JETS = jetPro.jetsByPt(CUTS);\n''',
                             {"OBJ_TYPE": "Jets",
                              "JETS": name,
                              "jetPro": projname,
                              "CUTS": cut_expr})
    insert_include('Rivet/Projections/FastJets.hh')
    return ("Jets", name)

def gen_met(input_obj, cuts, output_obj):
    '''Generate code to produce missing ET quadrivector'''
    global proj_init, obj_def, lhadafile

    #TODO: support for other inputs than external/particles?
    if input_obj != particles:
        raise RuntimeError("Error in line %d of file %s: antikt function is supported only for object with 'take external' or 'take particles'.\n" % (lhadafile.current_line, lhadafile.name))

    insert_include("Rivet/Projections/MissingMomentum.hh")
    name = output_obj
    projname = unique_name(output_obj + "Proj")
    proj_init += 'addProjection(MissingMomentum(fs), "%s");\n' % name
    obj_def   += multi_replace('''const MissingMomentum PROJ = applyProjection<MissingMomentum>(event, "OBJ");
OBJ = PROJ.missingMomentum();\n''', {"OBJ": name, "PROJ": projname})    
    insert_include('Rivet/Projections/MissingMomentum.hh')
    return ("FourMomentum", name)


def gen_part_per_id(self, object_name, pdg_id_string, ptmin, etamax, accept_tau_decay = True):
    global proj_init, obj_def
    name = object_name
    id_name = unique_name(object_name + "Id")
    acceptTauDecayFlag = "false"
    if accept_tau_decay:
        acceptTauDecayFlag = "true"

    cuts = []
    if ptmin and ptmin > 0:
        cuts.append("Cuts::pT > %d*GeV" % ptmin)
    if etamax:
        cuts.append("Cuts:eta < %d" % etamax)
    cuts = " && ".join(cuts)
    proj_init += '''

//%s
IdentifiedFinalState elId(fs);
elId.acceptIdPair(PID::ELECTRON);

PromptFinalState electrons(elId);
electrons.acceptTauDecays(acceptTauDecayFlag);
addProjection(electrons, "electrons")
'''
    proj_init = multi_replace(proj_init, {"elId": id_name, "electrons": name, "acceptTauDecayFlag": acceptTauDecayFlag})
    obj_def += multi_replace('''
///electrons
const Particles electrons = applyProjection<FinalState>(event, "electrons").particlesByPt(cuts);\n''',
                             {"electrons": name, "ptMin": ptmin, "etaMax": etamax, "cuts": cuts})
    return (types[particle], name)

def gen_electron(self, object_name, ptmin, etamax, accept_tau_decay = True):
    return gen_part_per_id(object_name, "PID:ELECTRON", ptmin, etamax, accept_tau_decay = True)

def gen_muon(self, object_name, ptmin, etamax, accept_tau_decay = True):
    return gen_part_per_id(object_name, "PID:MUON", ptmin, etamax, accept_tau_decay = True)

def gen_weight(self, object_name, func_name):
    global weight_func
    
def parse(infile):
    global lhadafile
    lhadafile = FileReader(infile)
    while True :
        l = lhadafile.readline()
        mess("> " + l)
        if len(l) == 0:
            break;
        l = preprocess_line(l)
        if len(l) == 0:
            continue
        #endif
        toks = l.split()
        if toks[0] in object_aliases:
            parse_object_block()
        elif toks[0] == 'cut':
            parse_cut_block()
        elif toks[0] == 'region':
            parse_region_block()
        elif toks[0] == 'function':
            parse_function_block()
        elif toks[0] == 'table':
            parse_table_block()
        elif toks[0] == 'info':
            parse_info_block()
        else:
            report_syntax_error(lhadafile.current_line, lhadafile.name, l, "Unknown keyword '%s'" % toks[0])
        #endif
#endef parse

def preprocess_line(l):
    """Trim spaces from beginning and end of a line and remove comments."""
    l = l.strip()
    pos = l.find('#')
    if pos < 0:
        return l
    else:
        return l[:pos]

def multi_replace(s, replace_map):
    for key, value in replace_map.items():
        mess(key + "->" + str(value))
        if value is None:
            sys.stderr.write("Missing value for the key '%s'.\n" % key)
        s = s.replace(key, value)
    #next key. value
    return s

def block_replace(s, replace_map):
    '''Insert text blocks in a string at location indentified by keys. The block is indented and aligned to the key position. The key must start and end with a percent sign and should not contain space. s contains the text where substitution must be made and replace_map is an associative array with the keys and the corresponding text block'''
    r = ""
    swallow_empty_line = False
    for l in s.split("\n"):
        p1 = re.compile(r'([\s]*)(%[^\s]+%)(.*)')
        m = p1.match(l)
        if m:
            (indent, toks, tail) = m.groups()
            try:
                first_line = True
                for ll in replace_map[toks].split("\n"):
                    if first_line:
                        first_line = False
                    else:
                        r += '\n'
                    if ll:
                        r += indent + ll
                        swallow_empty_line = False
                    else:
                        swallow_empty_line = True
            except KeyError:
                tail = l
                pass
            #endtry
            tail_ = multi_replace(tail, replace_map)
            r += tail_
            #endif
        else:
            if len(l.strip()) == 0 and swallow_empty_line:
                pass
            else:
                r += l + "\n"
                swallow_empty_line = False
        #endif
    return r

#def gen_cut(collection, observable, operator, value):
#    mess("Generating code for cut %s.%s %s %s"  % (collection, observable, operator, value))   
    
def check_args(args, specs):
    args_ = {}
    for k,v in args.items():
        try:
            type = specs[k][0]
            try:
                if type == int:
                    v_ = int(v)
                elif type == float:
                    v_ = float(v)
                elif type == bool:
                    v_ = bool(v)
                else:
                    v_ = None
            except ValueError:
                raise RuntimeError("Value type error for argument %s. %s" % (k, v))
            args_[k] =  v_
            
        except KeyError:
            raise RuntimeError("%s is not a valid parameter" % k)
    #Assigned default value for unspecified parameters:
    for k, v in specs.items():
        if k not in args_:
            args_[k] = v[1]
            
    return args_

def gen_arg_list(func_name, args):
    '''Generate argument list to call a given function'''
    #TODO Check argument names and order them
    #TODO Record if Particles is used in order to include the particles Rivet analysis member only
    #     when it is used.
    l = ""
    for k, v in args.iteritems():
        if l:
            l += ", "
        l += v
    #next k, v
    return l
    
def gen_apply(func_name, input_obj, args, cuts, output_obj):
    global obj_def
    
    mess("Generating code for apply %s(%s)" % (func_name, ", ".join(args)))

    if func_name not in names:
        names[func_name] = 0
        
    if not output_obj:
        output_obj = unique_name(func_name)
    else:
        output_obj = unique_name(output_obj)

        
    #FIXME: support for multiple apply lines in same objet block: need to create intermediate objects
    if func_name == "antikt":
        args = check_args(args, {"input_object": [None, None], "dR": [float, 0.4], "ptmin": [float, 0], "etamax": [float, None]})
        return gen_antikt(input_obj, args["dR"], args["ptmin"], args["etamax"], cuts, output_obj)
    if func_name == "antikt_b":
        args = check_args(args, {"input_object": [None, None], "dR": [float, 0.4], "ptmin": [float, 0], "etamax": [float, None]})
        #FIXME: need to select b's!
        return gen_antikt(input_obj, args["dR"], args["ptmin"], args["etamax"], cuts, output_obj)            
    elif func_name == "electron":
        args = check_args(args, {"input_object": [None, None], "ptmin": [float, 0], "etamax": [float, None]})
        return gen_electron(input_obj, args["ptmin"], args["etamax"], cuts, output_obj)
    elif func_name == "muon":
        args = check_args(args, {"input_object": [None, None], "ptmin": [float, 0], "etamax": [float, None]})
        return gen_muon(input_obj, args["ptmin"], args["etamax"], cuts, output_obj)
    elif func_name == "met":
        if len(cuts) > 0:
            raise RuntimeError("Error in line %d of file %s: cut statements cannot be applied on a MET object.\n\t%s\n" % (lhadafile.current_line, lhadafile.name, l))
        return gen_met(input_obj, cuts, output_obj)
    else:
        if func_name not in funcs_lhada:
            raise RuntimeError("Error in line %d of file %s: the function %s was not declared. A 'function' block must declare it before its usage." %(lhadafile.current_line, lhadafile.name, func_name))

        if cuts:
            tmp_obj = unique_name("filtered_" + input_obj)
            obj_def += gen_collection_filter_code(get_obj_type(input_obj), input_obj, cuts, tmp_obj, True) + "\n\n"
            input_obj = tmp_obj
        
        obj_def   += multi_replace('''%OUTPUT_OBJ% = %FUNC_NAME%(%ARGS%);\n\n''',
                                   {'%OUTPUT_OBJ%': output_obj,
                                    '%ARGS%': gen_arg_list(func_name, args),
                                    '%FUNC_NAME%': func_name});
        return (funcs_lhada[func_name].return_type, output_obj);
    
def gen_no_apply_object(input_obj, cuts, output_obj):
    """Generare code for an object block that does not have an apply statement"""
    output_obj = unique_name(output_obj)
    global obj_def
    if len(cuts) == 0:
        obj_def = '''%s %s = %s;\n''' % (get_obj_type(input_obj), output_obj, input_obj)
    else:
        obj_def += gen_collection_filter_code(get_obj_type(input_obj), input_obj, cuts, output_obj, False)
    #endif
    return (get_obj_type(input_obj), output_obj)

def gen_external(external_object_name, internal_object_name, cuts):
    global lhadafile, external_objs, obj_def
    rivet_cut = None
    tmpObj = False
    if len(cuts) > 0:
        rivet_cut = compose_rivet_cuts(cuts)
        if rivet_cut:
            obj_name = unique_name(internal_object_name)
        else:
            #cuts could not be expressed as a rivet cut object
            #and will be applied as a second step
            obj_name = unique_name("pre%s" % internal_object_name.capitalize())
            tmpObj = True
    else:
        obj_name = unique_name(internal_object_name)
    try:
        gen_func = external_objs[external_object_name]
    except KeyError:
        raise RuntimeError("Error. File %s, line %d. External object '%s' is not supported" % (lhadafile.name, lhadafile.current_line, external_object_name))
    #FIXME: treatement of cuts...
    (obj_type, obj_name) =  gen_func(obj_name, rivet_cut, tmpObj)
    
    if len(cuts) > 0 and not rivet_cut:
        #cuts could not be expressed as a rivet cut object
        pre_obj = obj_name
        obj_name = unique_name(internal_object_name)
        obj_def += gen_collection_filter_code(obj_type, pre_obj, cuts, obj_name, False)
    #endif
    return (obj_type, obj_name)

#### def gen_cut_obj(cutname, cuts):
####     """Generate code that defined a Cut class to be used in an object collection definitions."""
####     expr = ""
####     op = ""
####     op2 = ""
####     combined_cut = ""
####     simple_cut = re.compile(r"\s*\(?(pt|E|m|rapidity|\|\s*rapidity\s*\|charge|\|\s*charge\s*\|pid|\|\s*pid\s*\|phi)\s*(<|>|<=|>=|!=|==)\s*((0|[1-9]\d*)(\.\d*)?|\.\d+)([eE][+-]?\d+)?\)?")
####     for c in cuts:
####         subst_map = {
####             r"|[\s]*eta[\s]*|": "p.abseta()",
####             r"|[\s]*rapidity[\s]*|": "p.absrapidity()",
####             "eta": "p.eta()",
####             "pt" : "p.pt()",
####             "rapidity": "p.rapidity()",
####             "charge": "p.charge()"
####             };
####         subst_expr = "(" + multi_replace(c, subst_map) + ")"
####         decorted_c = c
####         if not simple_cut.match(c):
####             subst_expr = "(" + subst_expr + ")"
####             decorated_c = "(" + c + ")"
####         expr += op + subst_expr
####         combined_cut = op2 + decorated_c
####         op = "\n" + " "*4 + "&& ";
####         op2 = " && ";
####     cut_expr = compose_rivet_cuts(cutname, combined_cut)
####     if not cut_expr:
####         if len(cuts) == 0:
####             cut_expr = ""
####         else:
####             insert_include('Rivet/Tools/Cuts.hh')
####             subst_map = {"%CUTNAME%": cutname, "%EXPR%": expr, "%_%": indent};
####             code = multi_replace(
####                 """class %CUTNAME%: public CutBase {
#### 
#### public:
#### 
#### %_%bool operator==(const Cut& c) const {
#### %_%%_%return false;
#### %_%}
#### 
#### protected:
#### 
#### %_%template <typename ClassToCheck>
#### %_%bool _accept(const ClassToCheck& p){
#### %_%%_%return %EXPR%;
#### %_%}
#### 
#### };
#### """, subst_map)
####             obj_cuts.append(code);
####             cut_expr = cutname
####         #endif
####     #endif
####     return cut_expr

def gen_collection_filter_code(coltype, incol, cuts, outcol, localVar):
    '''Generate c++ code that filters the object collection <incol> by applying cuts listed in the parameter <cuts> to produce the new collection <outcol>. Returns the generated code.'''
    expr = ""
    op = ""
    simple_cut = re.compile(r"\s*\(?(pt|E|m|rapidity|\|\s*rapidity\s*\|charge|\|\s*charge\s*\|pid|\|\s*pid\s*\|phi)\s*(<|>|<=|>=|!=|==)\s*((0|[1-9]\d*)(\.\d*)?|\.\d+)([eE][+-]?\d+)?\)?")
    if localVar:
        type_decl = coltype + " " + outcol + ";\n"
    else:
        type_decl = ""
    for c in cuts:
#        subst_map = {
#            r"\|[\s]*eta[\s]*\|": "p.abseta()",
#            r"\|[\s]*rapidity[\s]*\|": "p.absrapidity()",
#            "eta": "p.eta()",
#            "pt" : "p.pt()",
#            "rapidity": "p.rapidity()",
#            "charge": "p.charge()"
#        };
#        for k,v in subst_map:
#            subst_expr = re.subn(v, k)
#        subst_expr = multi_replace(c, subst_map)
        subst_expr = parse_cut_line(c, "p.")[0]
        if not simple_cut.match(c):
            subst_expr = "(" + subst_expr + ")"
        expr += op + subst_expr
        op = "\n" + indent*2 + "&& ";
    #next c
    code = multi_replace('''%TYPE_DECL%for(const auto& p: %INCOL%){
%_%if(%EXPR%){
%_%%_%%OUTCOL%.push_back(p);
%_%}
}

''', {'%TYPE_DECL%': type_decl, \
      '%INCOL%': incol, \
      '%EXPR%': expr, \
      '%OUTCOL%': outcol, \
       '%_%': indent})
    return code

def get_obj_type(cpp_obj_name):
    try:
        return types[cpp_obj_name]
    except KeyError:
        raise RuntimeError("Bug found in lhad2rivet while parsing line %d of file %s. Attempt to use object %s before its type was defined." % (lhadafile.current_line, lhadafile.name, cpp_obj_name))

def parse_info_block():
    global lhadafile, ana_info
    #FIXME: support for 'info anlysis' split on several lines ?
    line1 = preprocess_line(lhadafile.current_line_contents)
    if not re.match(r'info\s+analysis', line1):
        sys.stderr.write("Warning. Block starting at line %d of file %s will be ignored. Only analysis type of info block are supported.\n" % (lhadafile.current_line, lhadafile.name))
        return
    p = re.compile(r'(\w+)\s+(.*)')
    l = ""
    while True:
        ll = lhadafile.readline()
        #skip comment lines:
        if re.match(r'^\s*#', ll):
            continue

        l += ll
        
        indented = re_indented.match(l) #must be checked before preprocess_line
        l = preprocess_line(l)

        if (not indented) or len(l) == 0:
            mess("End of block info analysis at line %d." % (lhadafile.current_line))            
            break
        
        if l[-1] == '\\':
            continue;
        
        m = p.match(l)
        if m:
            (key, value) = m.groups()
            if key in ana_info.keys():
                syst.stderr.write("Warning, line %d of file %s will be ignored. Previously defined analysis information %s is overwritten here.\n" % (lhadafile.current_line, lhadafile.name, key))
            ana_info[key] = value
        l = ""
    #end while
    
def parse_object_block():
    global weight_funcs, objects, types, lhadafile
    line1 = lhadafile.current_line_contents
    mess("Parsing block %s..." % line1)
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (lhadafile.current_line, lhadafile.name, l))
    #endif
    object_name = toks[1]
    mess("Object name: " + object_name)
    if object_name in objects:
        raise RuntimeError("Duplicate definition of object %s found line %d of file %s.\t%s\n" % (lhadafile.current_line, lhadafile.name, line1))
    if object_name in funcs_lhada:
        raise RuntimeError("Name %s was already used to name a function and cannot be used in line %d of file %s to define an object.\t%s\n" % (object_name, lhadafile.current_line, lhadafile.name, line1))
    lhadafile.save_pos()
    apply_stmt = None
    cuts = []
    input_collection = ""
    last_obj = None
    last_non_empty_line = lhadafile.current_line
    istatement = 0
    while True:
        lhadafile.save_pos()
        l = lhadafile.readline()
        indented = re_indented.match(l) #must be checked before preprocess_line        
        if len(l) == 0:
            break
        l = preprocess_line(l)
        if len(l) == 0:
            continue
        #endif
        istatement += 1
        toks = l.split()
        if not indented:
            mess("End of block object %s at line %d." % (object_name, last_non_empty_line))
            lhadafile.restore_pos()
            break
        #endif
        last_non_empty_line = lhadafile.current_line
        if toks[0] == 'take':
            if input_collection:
                raise RuntimeError("Syntax error in line %d of file %s: multiple take line. An object block can contain only one take statement." % (lhadafile.current_line, lhadafile.name))
            elif istatement != 1:
                raise RuntimeError("Syntax error in line %d of file %s: the 'take' line must be the first non-comment statement of an object block." % (lhadafile.current_line, lhadafile.name))
            elif len(toks) == 3 and toks[1] == "external":
                last_obj = "external"
                input_collection = toks[2]
            elif len(toks) == 2:
                input_collection = toks[1]
                if input_collection == "external":
                    raise RuntimeError("Error in line %d of file %s: lhada2rivet requires an object id from https://github.com/lhada-hep/lhada/blob/master/objects/object_list.md to be specified after the 'external' keyword.\n" % (lhadafile.current_line, lhadafile.name))
                elif input_collection not in objects.keys():
                    raise RuntimeError("Warning, line %d of file %s: object '%s' is not defined. Object definitions must precede their usage.\n\n" % (lhadafile.current_line, lhadafile.name, input_collection))
                #endif
                last_obj = objects[input_collection]
            else:
                raise RuntimeError("Syntax error in line %d of file %s: a take statement must be followed by either exactly one argument or 'external' and one argument." % (lhadafile.current_line, lhadafile.name))
            #endif input_collection                
        elif toks[0] in ['select', 'reject']:
            pattern = re.compile(r'(select|reject)\s+(.*)')
            m = pattern.match(l)
            if not m:
                raise RuntimeError("Syntax error in line %d of file %s: select statement should follow the format 'select variable operator value." % (lhadafile.current_line, lhadafile.name))
            #endif
            if toks[0] == 'select': #inverted cut
                #FIXME add code to simplify the expression ?
                cuts.append("!(%s)" % m.groups()[1])
            else:
                cuts.append(m.groups()[1])
            #endif            
        elif toks[0] == 'apply':
            pattern = re.compile(r'apply\s+([^\s]+)\(([^)]*)\)')
            m = pattern.match(l)
            if not m:
                raise RuntimeError("Syntax error in line %d of file %s: apply statement should follow the format 'apply function(args...)." % (lhadafile.current_line, lhadafile.name))
            (func_name, args) = m.groups()
            #Insert the implicit argument:
            #split args into [ "param1=value1", "param2=value2",...]:
            if len(args) > 0:
                args = "".join([ x for x in args if x not in [' ', '\t']]).split(",")
            else:
                args = []

            #check args
            parg = re.compile(r'[^\s]+=[^\s]+')
            for i, a in enumerate(args):
                if not parg.match(a):
                    raise RuntimeError("Syntax error in line %d of file %s, %s argument: function argument must follow the format <argument_name>=<value>.\n\n" % (lhadafile.current_line, lhadafile.name, tonth(i+1)))

            if last_obj:
                #FIXME: handle case of presence of last_obj not used in
                #the function
                args.insert(0, "input_object=%s" % last_obj)
            #split args into { "param1": "value1", "param2": "value2", ...}
            args = OrderedDict(map(lambda(x): x.split("="), args))
            #endif
            #if last object is external, code to produce it must be generated:
            if last_obj == "external":
                (obj_type, last_obj) = gen_external(input_collection, input_collection, cuts)
                types[last_obj] = obj_type
            #if an apply statement is pending, its code must be generated:
            elif apply_stmt:
                (obj_type, last_obj) = gen_apply(apply_stmt[0], apply_stmt[1], apply_stmt[2], cuts, None)
                types[last_obj] = obj_type
            #if cuts are pending, corresponding code must be generated
            elif cuts:
                new_obj = unique_name("filtered_" + last_obj)
                (obj_type, last_obj) = gen_no_apply_object(last_obj, cuts, new_obj)
                types[last_obj] = obj_type
            #endif
            cuts = [] #cuts processed by one of the three gen_xx commands
            #apply code is postponed to include possible cuts specified after
            #the apply statement.
            apply_stmt = (func_name, last_obj, args)
        elif toks[0] == 'weight':
            pattern = re.compile(r'weight\s+([^\s]+)')
            m = pattern.match(l)
            (func_name) = m.groups()
            if not m: 
                raise RuntimeError("Syntax error in line %d of file %s: weight statement should follow the format 'weight function.\n\t%s" % (lhadafile.current_line, lhadafile.name))
            weight_funcs[object_name] = func_name
        else:
            raise RuntimeError("Syntax error in line %d of file %s: '%s' is not a valid keyword to start a statement in an object block." % (lhadafile.current_line, lhadafile.name, toks[0]))
        #endif
    #endwhile
    if last_obj == "external":
        (obj_type, last_obj) = gen_external(input_collection, object_name, cuts)
    elif apply_stmt:
        (obj_type, last_obj) = gen_apply(apply_stmt[0], apply_stmt[1], apply_stmt[2], cuts, object_name)
    else:
        (obj_type, last_obj) = gen_no_apply_object(last_obj, cuts, object_name)
    #endif
    objects[object_name] = last_obj
    types[last_obj] = obj_type
    cuts = []
#enddef

def parse_function_block():
    """Parsing a function block. Information from the function block is not required by the translator, the block is skipped."""
    global funcs_lhada, re_indented, lhadafile
    line1 = lhadafile.current_line_contents
    block_first_line = lhadafile.current_line
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the function is missing a name.\n\t" % (lhadafile.current_line, lhadafile.name, l))
    #endif
    func_name = toks[1]
    mess("Parsing function block, %s..." % line1.strip())
#    funcs_lhada.append(func_name)
    code_line = re.compile(r'^code\s+(.*)')
    code_line_found = False
    while True:
        lhadafile.save_pos()
        l = lhadafile.readline()
        if len(l) == 0:
            break
        indented = re_indented.match(l) #must be checked before preprocess_line        
        l = preprocess_line(l)
        if len(l) == 0:
            continue;
        if not indented:
            lhadafile.restore_pos()
            break
        m = code_line.match(l)
        if m:
            code_line_found = True
            #TODO: support for htpp://....
            cpp_fname = m.groups()[0]
            #in case of relative path, the path is assumed to be relative to the input lhada file location:
            if not os.path.isabs(cpp_fname):
                cpp_fname = os.path.normpath(os.path.join(os.path.dirname(lhadafile.name), cpp_fname))
            #TODO: emit a warning if the function is not used..
            r = get_func_code(cpp_fname, func_name)
            if not r:
                raise RuntimeError("Function %s() defined line %d of LHADA file %s was not found in file %s" % (func_name, block_first_line, lhadafile.name, cpp_fname))
            #endif
            funcs_lhada[func_name] = r
#                (template_line, return_type, func_name, arg_list, func_body) = r
#            code_template = '''%TEMPLATE_LINE%
#%RETURN_TYPE% %FUNC_NAME%(%ARG_LIST%){
#  %FUNC_BODY%
#}'''
#            subst_map = { "%TEMPLATE_LINE%": template_line,
#                          "%RETURN_TYPE%": return_type,
#                          "%FUNC_NAME%": func_name,
#                          "%ARG_LIST%": arg_list,
#                          "%FUNC_BODY%": func_body}
#            code = block_replace(code_template, subst_map)
#            func_codes.append(code)
#            func_return_types[func_name] = r[1]
    #TODO: retrieve function code and copy it into generated files....
    #endwhile
    if not code_line_found:
         raise RuntimeError("Function block defined at line %d of file %s is missing the 'code' statement" % (block_first_line, lhadafile.name))
#enddef parse_function


def gen_func_block():
    '''Generate code of function defined in the auxilary c++ source files'''

    #functions defined in Lhada files and therefore called in the code
    #generated from the other lhada block are grouped at the end of
    #the function definition block
    
    code = []
    for f in funcs_all:
        if f not in funcs_lhada.values():
            code.append(f.rivet_code())
        #endif
    #next f

    for fname, fdef in funcs_lhada.iteritems():
        code.append(fdef.rivet_code())
    #next f

    return code
#enddef gen_func_block


def parse_table_block():
    """Parsing a table black and generate corresponding code"""
    global tables, lhadafile
    mess("Parsing table block...")
    line1 = lhadafile.current_line_contents
    toks = line1.strip().split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (lhadafile.current_line, lhadafile.name, l))
    #endif
    table_name = toks[1]
    mess("Table name: " + table_name)
    if table_name in tables:
        raise RuntimeError("Duplicate definition of table %s found line %d of file %s.\t%s\n" % (lhadafile.current_line, lhadafile.name, line1))
    tables[table_name] = None
#    while True:
    line_offset = -1
    table_type = None
    columns = None
    contents = []
    while True:
        lhadafile.save_pos()
        l = lhadafile.readline()
        if len(l) == 0:
            break
        l = preprocess_line(l)
        if len(l) == 0:
            continue;
        if block_start.match(l):
            lhadafile.restore_pos()
            break
        toks = l.split()
        if table_type is None:
            if toks[0] != "type":
                raise RuntimeError("Syntax error in line %d of file %s. The first statement of a table body should start with thre keyword 'type'.\n\t%s" % (lhadafile.current_line, lhadafile.name, l))
            else:
                table_type = toks[1]
                if table_type not in table_types:
                    raise RuntimeError("Syntax error in line %d of file %s. The name '%d' is not a valid type for a table. Supported types are %s.\n\t%s" % (lhadafile.current_line, lhadafile.name, ", ".join(table_types), l))
                #endif
            #endif
        elif columns is None:
            if toks[0] != "columns":
                raise RuntimeError("Syntax error in line %d of file %s. The second statement of a table body should start with the keyword 'columns'.\n\t%s" % (lhadafile.current_line, lhadafile.name, l))
            else:
                columns = toks[1:]
            #endif
        else:
            if toks[0] != "entry":
                raise RuntimeError("Syntax error in line %d of file %s. The third and following statements of a table body should start with the keyword 'entry'.\n\t%s" % (lhadafile.current_line, lhadafile.name, l))
            elif len(toks[1:]) != len(columns):
                raise RuntimeError("Syntax error in line %d of file %s. Expecting %d values in the entry statement, while %d values were found.\n\t%s" % (lhadafile.current_line, lhadafile.name, len(columns), len(toks[:1]), l))
            else:
                contents.append(toks[:1])
            #endif
        #endif
    tables[table_name] = [type, columns, contents]
        

def parse_cut_block():
    """Parsing a cut block and generate corresponding code"""
    global cut_names, func_codes, lhadafile, cutblocks
    mess("Parsing cut block...")
    dependencies = []
    line1 = lhadafile.current_line_contents
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (lhadafile.current_line, lhadafile.name, l))
    #endif
    cut_name = toks[1]
    mess("Cut name: " + cut_name)
    if cut_name in cutblocks:
        raise RuntimeError("Duplicate definition of object %s found line %d of file %s.\t%s\n" % (il, lhadafile.name, line1))
    cutblocks[cut_name] = CutNode(cut_name)

#    func_name = "cut_%s" % cut_name

#    cutid = unique_name("k%s" % cut_name);
#    cut_ids.append(cutid)
    
#    func_code = """bool %s(){
#    bool r = true;
#""" % func_name
    line_offset = -1
    while True:
        lhadafile.save_pos()
        l = lhadafile.readline()
        if len(l) == 0:
            break
        l = preprocess_line(l)
        if len(l) == 0:
            continue;
        if block_start.match(l):
            lhadafile.restore_pos()
            break
        toks = l.split()
        if toks[0] in ['select', 'reject']:
            (expr, extra_dependencies) = parse_cut_line(" ".join(toks[1:]), "")
            cutblocks[cut_name].add_dependencies(extra_dependencies)
            if toks[0] == 'select':
                cutblocks[cut_name].cuts.append(expr)
            elif toks[0] == 'reject':
                cutblocks[cut_name].cuts.append(expr)
            #endif
        else:
            raise RuntimeError("Syntax error in line %d of file %s. Every line of the body of a cut block should start with the keyword 'select'.\n\t%s" % (lhadafile.current_line, lhadafile.name, l))
        #endif
        #FIXME: handle duplicate names
        

def invert_cond(expr):
    '''Invert a mathematical condition expression'''
    r = re.compile(r'([^()+-^*/&|=<>]+)(=|==|!=|<|>|<=|>=)([^()+-^*/&|=<>]+)')
    ops = (('==','!='), ('<', '>='), ('<=', '>'))
    newop = None
    if r.match(expr):
        l, op, r = r.groups()
        if op == '=':
            op = '=='
        for op1, op2 in ops:
            if op == op1:
                newop = op2
                break;
            elif op == op2:
                newop = op1
                break;
            #endif
        #next op1,op2
    #endif
    if newop:
        return l + newop + r;
    else:
        return "!(%s)" % expr
#endif invert_cond
    
    
def parse_cut_line(l, pref):
    ''' '''
    dependencies = []
    l = l.strip()
    r = ""
    toks_ = re.split("([\W]+)", l)
    #fixing some splitting failures:
    toks = []
    for t in toks_:
        tt = re.split(r"(<=|>=|[\]\[()=<>])", t)
        toks.extend(tt)
    #next t
    toks_ = toks
    toks = []
    state = "init"
    for t in toks_:
        if state == "init" and t.strip() == "|":
            state = "first|"
        elif state == "first|" and t.strip() == "|":
            toks[-1] = "|" + toks[-1] + "|"
            state = "init"
        else:
            toks.append(t)
        #endif
    #next t

    ops = [ "+", "-", "/", "*", "^", "**"]
    r = ""

    trans = {
        r"^\|\s*eta\s*\|$": "%sabseta()",
        r"^eta$": "%seta() ",
        r"^\|\s*rapidity[\s]*\|$": "%sabsrapidity()",
        r"^rapidity$": "%srap() ",
        r"^theta$": "%stheta() ",
        r"^size$": "%ssize()",
        r"^and$": " && ",
        r"^or$": " || ",
        r"^e$": "%sE() ",
        r"^pt$": "%spt() ",
        r"^m$": "%smass() ",
        r"^phi$": "%sphi() ",
        r"^px$": "%spx() ",
        r"^py$": "%spy() ",
        r"^pz$": "%spz() ",
        r"^\.$": ".",
        r"^\($": "(",
        r"^\)$": ") ",
        r"^>$": "> ",
        r"^<$": " < ",
        r"^>=$": " >= ",
        r"^<=$": " >= ",
        r"^=$": " == ",
        r"^==$": " == ",
        r"^\+" : " + ",
        r"^-$": " - ",
        r"^\*$": " * ",
        r"^,$": ", "
    };

    for (k,v) in trans.iteritems():
        trans[k] = v.replace("%s", pref)

    for tok in toks:
        tok = tok.strip()
        if len(tok) == 0:
            continue
        done = False
        for k, v in trans.iteritems():
            if re.match(k, tok):
                r += v
                done = True
                break
            #endif
        #next k,v
        if done:
            continue
        p = re.match(r'[a-zA-Z_][a-zA-Z_0-9]', tok)
        if p:
            if tok in objects:
                r += tok
                continue
            #endif
            if tok in cutblocks:
                r += "cut_%s(w)" % tok
                dependencies.append(cutblocks[tok])
                continue
            #endif
            if tok in funcs_lhada:
                r +=  tok
                continue
            raise RuntimeError("Entity '%s' referred line %d in file %s is not defined.\n\t%s\n" % (tok, lhadafile.current_line, lhadafile.name, l))
        #endif
        if tok == '[':
            r += "["
            continue
        if tok == ']':
            r += " - 1]"
            continue
        r += tok
        #TODO: handle function named arguments
    return (r.rstrip(), dependencies)

#under dev# def gen_histo_code():
#under dev#     """Generates the code to book and fill histograms of the analysis. For a cut and count analysis, an histogram with one enty per region is filled"""
#under dev#     table_type, columns, contents = t
#under dev#     ihist = 1
#under dev#     for table_name, t in tables.iteritems():
#under dev#         [table_type, columns, contents] = t
#under dev#         if table_type != "events":
#under dev#             continue
#under dev#         iobs = -1
#under dev#         idobs = -1
#under dev#         ibkg = -1
#under dev#         idbkg = -1
#under dev#         for i, c in enumerate(columns):
#under dev#             if c == 'obs':
#under dev#                 iobs = i
#under dev#             if c == 'dobs':
#under dev#                 idobs = i
#under dev#             if c == 'bkg':
#under dev#                 ibkg = i
#under dev#             if c == 'dbkg':
#under dev#                 idbkg = i
#under dev#             col_index[c] = i
#under dev#         #next i,c
#under dev#         if iobs < -1:
#under dev#             sys.stderr.write("Warning. Table %s is missing obs column. The table will be ignored.\n")
#under dev#             continue
#under dev#         if ibkg < -1:
#under dev#             sys.stderr.write("Warning. Table %s is missing bkg column. The table will be ignored.\n")
#under dev#             continue
#under dev#         if dobs < -1:
#under dev#             sys.stderr.write("Warning. Table %s is missing dobs column. sqrt(obs) will be used as uncertainty.\n")
#under dev#             continue
#under dev#         if dsig < -1:
#under dev#             sys.stderr.write("Warning. Table %s is missing dobs column. sqrt(sig) will be used as uncertainty.\n")
#under dev#         nregions = len(contents)
#under dev#         histo_booking += 'bookHisto1D(%s, %d, 0.5, %f, "%s", "Region", "Event count");\n' % (table_name, nregions, nregions + 0.5)
#under dev#         yoda_file += '''BEGIN YODA_SCATTER2D ''' + hist_path + '''
#under dev# IsRef=1
#under dev# Path=''' + hist_path + '''
#under dev# Title=
#under dev# Type=Scatter2D
#under dev# # xval\txerr-\txerr+\tyval\tyerr-\tyerr+'''
#under dev#         hist_path= '/REF/%s/d%02d-x01-y01' % (analysis_name, ihist)
#under dev#         for r in contents
#under dev#             for il, l in enumerate(content):
#under dev#                 sig = contents[isig]
#under dev#                 bkg = contents[isig]
#under dev#                 if idsig >= 0:
#under dev#                     dsig = contents[idsig]
#under dev#                 else:
#under dev#                     dsig = sqrt(sig)
#under dev#                 if idsig >= 0:
#under dev#                     dsig = contents[idsig]
#under dev#                 else:
#under dev#                     dsig = sqrt(sig)                
#under dev#                 yoda_file += "%g\t5.000000e-01\t5.000000e-01\t%g\t%g\t%g\n"
#under dev#                 % (il, obs, 0.5*dobs, 0.5*dobs)
#under dev# '''END YODA_SCATTER2D
#under dev# '''
#under dev# 
#under dev# 
#under dev# 
#under dev#             
#under dev#             ## WRITE HERE THE YODA FILE
#under dev#         ihist += 1

def gen_object_decl():
    '''Generates the code that declares LHADA objects instance as members of the Rivet analysis class'''
    code = '''/** Analysis objects
 * @{
 */'''
    for lhada_obj, cpp_obj in objects.iteritems():
        cpp_type = types[cpp_obj]
        code += "\n%s %s;\n" % (cpp_type, cpp_obj)
    code += '''/** @}
*/'''
    #next
    return code
#enddef gen_object_decl

def canonize_analysis_name(name):
    toreplace = re.compile("[^a-zA-Z0-9_]")
    digit = re.compile("[0-9]")
    name  = toreplace.sub("_", name)
    if name and digit.match(name[0]):
        name = "A" + name
    return name


def gen_cutflow_decl_code():
    '''Generates c++ code which defines the ids used for the cutflow (cut_id_decl) and initialisation list for the Cutflow object (init). Returns (cut_id_decl, init) '''
    decl_cf_ids = "enum {" + ", ".join([ "k%s" % x.capitalize() for x in cutflows]) + "} CutFlowIds;"
    cfs_init = ""
    sep = ""
    for cf, cl in cutflows.iteritems():
        cfs_init += 'cutflows.addCutflow("%s", {%s});\n' % (cf, ", ".join([ '"%s"' % x.name for x in cl]))
    #next c
    cfs_decl = '''///Tracks the event counts after each cut
Cutflows cutflows;'''
    
    return (decl_cf_ids, cfs_decl, cfs_init)

def gen_cut_func_code():
    '''Generate c++ code for the 'cut' block.'''
    # Algorithm: we pass through the sequence of cut blocks one cut
    # flow after the other and generate the c++ code of a cut block
    # the first time it appears in the pass.
    # That allows us to determine the cut order. By construction
    # a given cut should appear in the same sequence order for all
    # the cut flows it is in.
    code = ""
    implemented_cut_blocks = []
    for cf, cl in cutflows.iteritems():
        cut_order = 0
        for cutblock in cl:
            make_code = (cutblock.name not in implemented_cut_blocks)
            if make_code:
                func_name  = unique_name("cut_%s" % cutblock.name)
                implemented_cut_blocks.append(cutblock.name)
                cutblock.order = cut_order
                code += multi_replace('''bool %FUNC%(double w){
%I%std::vector<int> cfs = {%CUTFLOW_LIST%};
%I%bool r = true;
''', {"%I%": indent, \
      "%FUNC%": func_name, \
      "%CUTFLOW_LIST%": ", ".join(["k%s" % x.name for x in cutblock.cutflows])})
            else: #code already generated
                if cutblock.order != cut_order:
                    raise RuntimeError("Error detected in the cut flows. The numbers of cuts preceeding the cuts of cut block %s dependes on the cut flow, while it is expected that Lhada17 rules prevent this situation." % cutblock.name)
            #endif make_code
            for expr in cutblock.cuts:
                if make_code:
                    code += multi_replace('''
%I%r = r && fillCutFlows(cfs, %CUT_ORDER%,
%I%                      %EXPR%,
%I%                      w);''',  {"%I%": indent, \
       "%CUT_ORDER%": str(cut_order), \
        "%EXPR%": expr})
                #endif make_code
                cut_order += 1 #expr. sequence order in the cut flow
            #next expr
            if make_code:
                code += "\n%sreturn r;\n};\n\n" % indent
        #next cutblock
    #next cf, cl
    return code
#enddef gen_cut_func_code

def gen_code():
    global analysis_code_template, includes, include_block, objects, func_codes, vector3ToFourMometum

    #Generate #include list block:
    for i in includes:
        if not i:
            continue
        if i[0] not in [ '"', '<' ]:
            i = '"' + i + '"'
        if i.strip('"') not in excluded_includes:
            include_block += '#include %s\n' % i
    #next i

    #Generate histograming code:
#    gen_histo_code()

    analysis_name = canonize_analysis_name(args.analysis_name)

    #FIXME
    #    (cutid_decl, cutid_init) = gen_cutid_decl_code()
    (decl_cf_ids, cfs_decl, cfs_init) = gen_cutflow_decl_code()
    
    #Inplement the vector3 -> FourMometum cast operator
    #if it is used:
    if vector3ToFourMometum:
        cast_op = '''static FourMomentum toFourMomentum(const Vector3& v){
%sreturn FourMomentum(v.x(), v.y(), v.z(), v.mod());
}
''' % indent
        func_codes.insert(0, cast_op)
    #endif

    func_codes.extend(gen_func_block())

    func_codes.append(gen_cutflowfill_func_code())

    func_codes.append(gen_cut_func_code())

    # we substitute the code block in two steps in
    # order to check if the instance 'particles' is used
    # before generating the code that creates it.
    
    # Inserts complete code blocks in the code template:
    subst_map = {"%INCLUDE_BLOCK%": include_block,
                 "%DECL_CF_IDS%": decl_cf_ids,
                 "%CFS_DECL%": cfs_decl,
                 "%CFS_INIT%": cfs_init,
                 "%PROJECTION_INIT%": proj_init,
                 "%COUNTER_INIT%": counter_init,
                 "%OBJECT_DEFINITIONS%": obj_def,
                 "%COUNTER_FILL%": counter_fill,
                 "%COUNTER_DECLARATION%": counter_decl,
                 "%OBJECT_CUTS%": "\n\n".join(obj_cuts), 
                 "%FUNCTION_DEFINITIONS%": "\n\n".join(func_codes),
                 "%WEIGHT%" : "",
                 "%CUTS%": gen_cut_call_code(),
                 "%COUNTER_FILL%":""
    }

    code = block_replace(analysis_code_template, subst_map)
    subst_map = { "%ANALYSIS_NAME%": analysis_name}
    code = multi_replace(code, subst_map)
    #check if particles objet is used
    re_particles = re.compile(r'\bparticle\b')
    re_particles_func = re.compile(r'\bparticle\s*\(')
    #we remove particle() function call and look for a remaining particle word:
    if re_particles.match(re_particles_func.sub("", code)):
        particles_def = '''particles = applyProjection<FinalState>(event, "fs");'''
        fs_proj_init = '''addProjection(fs, "fs")'''
    else:
        particles_def = ""
        fs_proj_init = ""
        objects = OrderedDict([(k, v) for k, v in objects.iteritems() if v != "particles"])

    obj_decl = gen_object_decl()

    subst_map = {"%FS_PROJ_INIT%": fs_proj_init,
                 "%PARTICLES_DEFINITION%": particles_def,
                 "%OBJECT_DECLARATION%":  obj_decl}

    code = block_replace(code, subst_map)
    
        
    with open(analysis_name + ".cc", "w") as f:
        f.write(code + "\n")
        
    if args.debug and code.find("%") > 0:
        sys.stderr.write("Warning: genrated code contains a % character.\n")

        

def main():
    parser = argparse.ArgumentParser(description='Produce Rivet code for an analysis decribed in LHADA format.')
    
    parser.add_argument('lhadafile', action='store', default=None,
                        help='File describing the analysis')

    parser.add_argument('analysis_name', action='store', default=None,
                        help='Analysis name')
    

    parser.add_argument('-v', '--verbose', action='store_true', default=False, help='Activate verbose mode')

    parser.add_argument('-d', '--debug', action='store_true', default = False, help='Activate debug mode.')

    global args
    
    args = parser.parse_args()

    parse(args.lhadafile)

    build_cutflows()
    
    gen_code()

def build_cutflows():
    '''Build the cutflow. To be called once the CutNode tree is built. This function modified the CutNode's stored in cutblocks.'''
    global cutblocks, cutflows
    for v in cutblocks.values():
        if v.endpoint:
            cut_sequence = []
            c = v
            while c:
                c.cutflows.append(v)
                cut_sequence.insert(0, c)
                if len(c.dependencies()) > 0:
                    c = c.dependencies()[0]
                else:
                    c = None
            cutflows[v.name] = cut_sequence
            #endwhile
        #endif
    #next v


def gen_cut_call_code():
    code = '''double w = event.weight();
cutflows.fillinit();
'''
    for cf in cutflows:
        code += "cut_%s(w);\n" % cf
    code += "\n"
    return code
#enddef

def gen_cutflowfill_func_code():
    '''Generate c++ code for the fillCutFlows function'''
    return multi_replace('''bool fillCutFlows(const std::vector<int>& cfs, int icut, bool passed, double w){
%I%for(auto& icf: cfs) cutflows[icf].fill(icut, passed, w);
%I%return passed;
}\n\n''', { "%I%": indent})
    
def print_dependencies():
    '''Help function for debugging'''
    for v in cutblocks.values():
        if v.endpoint:
            sys.stdout.write("%s " % v.name)
            print_dep(v, 0)


def print_dep(c, level):
    '''Help function for debugging'''
    for d in c.dependencies():
        sys.stdout.write("%s-> %s" % ( "  " * level, d.name))
        print_dep(d, level + 1)
        sys.stdout.write("\n")
    
if __name__ == "__main__":
    try:
        main()
    except RuntimeError as e:
        if args.debug:
            raise
        else:
            print e

    
