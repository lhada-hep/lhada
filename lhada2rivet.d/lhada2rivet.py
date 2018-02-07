#!/usr/bin/env python

import re
import argparse
import sys
from collections import OrderedDict


indent = ' ' * 2

block_start = re.compile(r'object|cut|region|function|table')
re_indented = re.compile(r'^\s')

analysis_code_template = """// -*- C++ -*-
#include <iostream>
#include "Rivet/Analysis.hh"
#include "Rivet/Tools/Cutflow.hh"

%INCLUDE_BLOCK%

namespace Rivet {


  class %ANALYSIS_NAME%: public Analysis {
  public:

    ///Cut ids
    %CUT_IDS%

    /// Constructor
    %ANALYSIS_NAME%():
      Analysis("%ANALYSIS_NAME%"),
      cutflow("CutFlow", %CUTFLOW_INIT%)
    {  }


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
                 << cutflow << "\\n";
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

    ///Tracks the event counts after each cut
    Cutflow cutflow;

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

#list of cuts used to define object collection
obj_cuts = []

#list of cut ids used for to identify the cut in the cutflow
cut_ids = []

#list of objects defined in LHADA file. Associate object name with its c++-code name mapped_name
#In same rare case the two name can differ.
particles = "particles"
objects = OrderedDict([("external", particles), ("Particles", particles)])

#Map object (cpp name) to types including intermediat object, i.e. not defined in LHADA file.
types = { particles: "Particles"}

#list of defined cuts
cuts = []

#list of defined functions
functions = []

#return types of defined functions listed in functions
func_return_types = {}

def unique_name(name):
    """Generate a unique name to be used in the analysis code as variable name or projection tag. If the name has not been used yet (first call with this value) the name is return as is, otherwise a sequential number is appended to it"""
    global names
    try:
        i = names[name] + 1
        names[name] = i

        mess('%s already used and mapped to %s.\n List of names:' % (name, name+str(i)), names)
        
        return name + str(i)
    except KeyError:
        names[name] = 0
        return name
#enddef

def trans_func(code):
    '''Make the modifications of function c++ code read from LHADA input file required before inserting it in the Rivet analysis code'''
    #TODO: Check LHADPArticle -> Particle method mapping
    r = re.compile(r'\b(std::)vector\s*<\s*LHADAParticle\s*>')
    code = r.sub('Particles', code)
    print '///<', code
    r = re.compile(r'\bLHADAParticle\b')
    code = r.sub('Particle', code)
    print '///>', code
    return code

def get_func_code(file, func_name):
    '''Search for a function with name <func_name> in the c/c++ file <file>. Returns a list with in order the possible template defintion line, the function return type, the function name (i. e. func_name), and the function body without its curly brackets.'''
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
    func_body = ""
    template_line = ""
    r = None
    bra = 0
    for l in open(file):
        il += 1
        if comment_line.match(l):
            continue
        m = re_include.match(l)
        if m:
            file_to_include = m.groups()[0]
            if file_to_include not in includes:
                print "Adding c/c++ header file found in the file %s to  the list #include commands to put in the generated code." % file
                includes.append(file_to_include)
            #endif
            continue
        #endif m
        for t in re_split.split(l):
##            if len(t.strip()) > 0:
            ##                sys.stdout.write("\nState: %s; Next token: %s" % (state, t))
            ##else:
            ##    sys.stdout.write(".")
            t_stripped = t.strip()
            if re_c_comment_start.match(t) and state != "comment":
                prev_state = state
                state = "comment"
                continue
            if re_c_comment_stop.match(t) and state == "comment":
                state = prev_state
                continue
            if state in ["init", "return_type" ] and t_stripped == "template":
                prev_state = state
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
                    state = prev_state
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
                if t_stripped == "<" and bra > 0:
                    bra -= 1
                    return_type += t
                    continue
                if bra > 0:
                    return_type += t
                    continue
                if len(t_stripped) == 0:
                    return_type += t
                    continue
                state = "function_name"
                if t_stripped == func_name:
                    mess("Found the function %s we were looking for at line %d of file %s." % (func_name, il, file))
                    if func_found: #function was already found. multiple definition
                        raise RuntimeError("Found multiple definitions of function %s in the file %s. This is not supported (including overloaded function." % (func_name, file))
                    func_found = True
                continue
            if state == "function_name":
                if t_stripped == "(":
                    state = "args"
                    continue
                elif len(t_stripped) > 0:
                    raise RuntimeError("Syntax error in file %s, line %d."% (file, il))
                continue
            if state == "args":
                if t_stripped == ")":
                    prev_state = "function_body"
                    state = "{"
                    continue
                arg_list += t
                continue
            if state == "comma":
                if t != ",":
                    raise RuntimeError("Syntax error in file %s, line %d. A comma is missing." % (file, il))
                state = prev_state
                continue
            if state == "{":
                if len(t_stripped) == 0:
                    continue
                if t_stripped != "{":
                    raise RuntimeError("Syntax error in file %s, line %d. An opening curly bracket is missing."% (file, il))
                state = prev_state
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
                    if func_found:
                        #store result
                        r = (template_line, trans_func(return_type), func_name, trans_func(arg_list), trans_func(func_body))
                        func_found = False
                    (template_line, return_type, arg_list, func_body) = ("", "", "", "")
                    state = "init"
                    #endif func_found
                else:
                    func_body += t
                continue
            #endif state == "function_body"
        #next t(oken)
    #next l(ine)
    return r
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
    '''Generate code to perform an object cut using a combination of standard Rivet cuts. Returns None in the case the expression is too complex to express it that way.'''
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

    print '>>> combined cut: ', combined_cut
    
    if not r.match(combined_cut):
        return None
    
    includes.append('Rivet/Tools/Cuts.hh')
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

    print '>>>> combined_cut:', combined_cut
    
    return combined_cut

def gen_antikt(input_obj, dR, ptmin, etamax, cuts, output_obj):
    global proj_init, obj_def, particles, lhadafile

    #TODO: support for other inputs than external/particles?
    if input_obj != particles:
        raise RuntimeError("Error in line %d of file %s: antikt function is supported only for object with 'take external' or 'take particles'.\n" % (lhadafile.current_line, lhadafile.name))
    
    includes.append("Rivet/Projections/FastJets.hh")
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

    includes.append("Rivet/Projections/MissingMomentum.hh")
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
        if toks[0] == 'object':
            parse_object()
        elif toks[0] == 'cut':
            parse_cut()
        elif toks[0] == 'region':
            parse_region()
        elif toks[0] == 'function':
            parse_function()
        elif toks[0] == 'table':
            parse_table()
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
        mess(key + "->" + value)
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

def gen_cut(collection, observable, operator, value):
    mess("Generating code for cut %s.%s %s %s"  % (collection, observable, operator, value))
    
    
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
        if func_name not in functions:
            raise RuntimeError("Error in line %d of file %s: the function %s was not declared. A 'function' block must declare it before its usage." %(lhadafile.current_line, lhadafile.name, func_name))

        if cuts:
            tmp_obj = unique_name("filtered_" + input_obj)
            obj_def += gen_collection_filter_code(get_obj_type(input_obj), input_obj, cuts, tmp_obj) + "\n\n"
            input_obj = tmp_obj
        
        obj_def   += multi_replace('''%OUTPUT_OBJ% = %FUNC_NAME%(%ARGS%);''',
                                   {'%OUTPUT_OBJ%': output_obj,
                                    '%INPUT_OBJ%': input_obj,
                                    '%ARGS%': gen_arg_list(func_name, args),
                                    '%FUNC_NAME%': func_name});
        return (func_return_types[func_name], output_obj);
    
def gen_no_apply_object(input_obj, cuts, output_obj):
    """Generare code for an object block that does not have an apply statement"""
    global obj_def
    if len(cuts) == 0:
        obj_def = '''%s %s = %s;\n''' % (get_obj_type(input_obj), ouput_obj, input_obj)
    else:
        obj_def += gen_collection_filter_code(get_obj_type(input_obj), input_obj, cuts, output_obj)
    #endif
    return (get_obj_type(input_obj), output_obj)
        
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
####             includes.append('Rivet/Tools/Cuts.hh')
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

def gen_collection_filter_code(coltype, incol, cuts, outcol):
    '''Generate c++ code that filters the object collection <incol> by applying cuts listed in the parameter <cuts> to produce the new collection <outcol>. Returns the generated code.'''
    expr = ""
    op = ""
    simple_cut = re.compile(r"\s*\(?(pt|E|m|rapidity|\|\s*rapidity\s*\|charge|\|\s*charge\s*\|pid|\|\s*pid\s*\|phi)\s*(<|>|<=|>=|!=|==)\s*((0|[1-9]\d*)(\.\d*)?|\.\d+)([eE][+-]?\d+)?\)?")
    for c in cuts:
        subst_map = {
            r"|[\s]*eta[\s]*|": "p.abseta()",
            r"|[\s]*rapidity[\s]*|": "p.absrapidity()",
            "eta": "p.eta()",
            "pt" : "p.pt()",
            "rapidity": "p.rapidity()",
            "charge": "p.charge()"
        };
        subst_expr = multi_replace(c, subst_map)
        if not simple_cut.match(c):
            subst_expr = "(" + subst_expr + ")"
        expr += op + subst_expr
        op = "\n" + indent*2 + "&& ";
    #next c
    code = multi_replace('''%COLTYPE% %OUTCOL%;
for(const auto& p: %INCOL%){
%_%if(%EXPR%){
%_%%_%%OUTCOL%.push_back(p);
%_%}
}

''', {'%COLTYPE%': coltype,
       '%OUTCOL%': outcol,
       '%INCOL%': incol,
       '%EXPR%': expr,
       '%_%': indent})
    return code

def get_obj_type(cpp_obj_name):
    try:
        return types[cpp_obj_name]
    except KeyError:
        raise RuntimeError("Bug found in lhad2rivet while parsing line %d of file %s. Attempt to use object %s before its type was defined." % (lhadafile.current_line, lhadafile.name, cpp_obj_name))
                        
def parse_object():
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
    if object_name in functions:
        raise RuntimeError("Name %s was already used for a function and cannot be used in line %d of file %s to define an object.\t%s\n" % (object_name, lhadafile.current_line, lhadafile.name, line1))
    objects[object_name] = unique_name(object_name)
    lhadafile.save_pos()
    line_offset = -1
    apply_stmt = None
    cuts = []
    input_collection = ""
    last_obj = None
    last_non_empty_line = lhadafile.current_line
    while True:
        lhadafile.save_pos()
        l = lhadafile.readline()
        indented = re_indented.match(l) #must be checked before preprocess_line        
        if len(l) == 0:
            break
        line_offset += 1
        l = preprocess_line(l)
        if len(l) == 0:
            continue
        #endif
        toks = l.split()
        if not indented:
            mess("End of block object %s at line %d." % (object_name, last_non_empty_line))
            lhadafile.restore_pos()
            break
        #endif
        last_non_empty_line = lhadafile.current_line
        if line_offset == 0: #first statement of object block. It is required to be a 'take' statement.
            if toks[0] != 'take':
                raise RuntimeError("Syntax error in line %d of file %s: the first statement of a object block must be a take statement specifying the input collection.\n\t" % (lhadafile.current_line, lhadafile.name))
            #endif
            if len(toks) != 2:
                raise RuntimeError("Syntax error in line %d of file %s: the first statement of a object block must be a take statement specifying the input collection.\n\t" % (lhadafile.current_line, lhadafile.name))
            #endif
            input_collection = toks[1]
            if input_collection not in objects:
                raise RuntimeError("Warning, line %d of file %s: object block %s takes as input an object collection which was not previously defined. \n\n" % (lhadafile.current_line, lhadafile.name, object_name))
            last_obj = objects[input_collection]
        else:
            if toks[0] == 'select':
                #pattern = re.compile(r'select\s+([^\s<>=.]+).([^\s<>=.]+)\s*([<>=]+=?)\s*([^\s<>=]+)')
                #m = pattern.match(l)
                #if not m:
                #    raise RuntimeError("Syntax error in line %d of file %s: select statement should follow the format 'select variable operator value.\n\t" % (lhadfile.current_line, lhadafile.name,l))
                ##endif
                #(collection, observable, operator, value) = m.groups()
                #gen_cut(collection, observable, operator, value)
                pattern = re.compile(r'select\s+(.*)')
                m = pattern.match(l)
                if not m:
                    raise RuntimeError("Syntax error in line %d of file %s: select statement should follow the format 'select variable operator value.\n\t" % (lhadfile.current_line, lhadafile.name,l))
                #endif
                cuts.append(m.groups()[0])                
                #endif
            elif toks[0] == 'apply':
                pattern = re.compile(r'apply\s+([^\s]+)\(([^)]*)\)')
                m = pattern.match(l)
                if not m:
                    raise RuntimeError("Syntax error in line %d of file %s: apply statement should follow the format 'apply function(args...).\n\t%s" % (lhadfile.current_line, lhadafile.name, l))
                (func_name, args) = m.groups()
                #Insert the implicit argument:
                #split args into [ "param1=value1", "param2=value2",...]:
                args = "".join([ x for x in args if x not in [' ', '\t']]).split(",")
                if len(args) == 1 and len(args[0]) == 0:
                    args = []
                args.insert(0, "input_object=%s" % last_obj)
                #split args into { "param1": "value1", "param2": "value2", ...}
                args = OrderedDict(map(lambda(x): x.split("="), args))
                #endif
                #if an apply statement is pending, its code must be generated:
                if apply_stmt:
                    (obj_type, last_obj) = gen_apply(apply_stmt[0], apply_stmt[1], apply_stmt[2], cuts, None)
                    types[last_obj] = obj_type
                    cuts = []
                #if cuts are pending, corresponding code must be generated
                if cuts:
                    new_obj = unique_name("filtered_" + last_obj)
                    (obj_type, last_obj) = gen_no_apply_object(last_obj, cuts, new_obj)
                    cuts = []
                    types[last_obj] = obj_type
                #apply code is postponed to include possible cuts specified after
                #the apply statement.
                apply_stmt = (func_name, last_obj, args)
            elif toks[0] == 'weight':
                pattern = re.compile(r'weight\s+([^\s]+)')
                m = pattern.match(l)
                (func_name) = m.groups()
                if not m:
                    raise RuntimeError("Syntax error in line %d of file %s: weight statement should follow the format 'weight function.\n\t%s" % (lhadafile.current_line, lhadafile.name, l))
                weight_funcs[object_name] = func_name
            #endif
        #endif
    #endwhile
    if apply_stmt:
        (obj_type, last_obj) = gen_apply(apply_stmt[0], apply_stmt[1], apply_stmt[2], cuts, objects[object_name])
    else:
        (obj_type, last_obj) = gen_no_apply_object(last_obj, cuts, objects[object_name])
    #endif
    types[last_obj] = obj_type
    cuts = []
    return line_offset
#enddefk

def parse_function():
    """Parsing a function block. Information from the function block is not required by the translator, the block is skipped."""
    global functions, func_return_types, re_indented, lhadafile
    line1 = lhadafile.current_line_contents
    block_first_line = lhadafile.current_line
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the function is missing a name.\n\t" % (lhadafile.current_line, lhadafile.name, l))
    #endif
    func_name = toks[1]
    mess("Parsing function block, %s..." % line1)
    functions.append(func_name)
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
            #TODO: emit a warning if the function is not used..
            r = get_func_code(cpp_fname, func_name)
            if not r:
                raise RuntimeError("Function %s() defined line %d of LHADA file %s was not found in file %s" % (func_name, block_first_line, lhadafile.name, cpp_fname))
            else:
                (template_line, return_type, func_name, arg_list, func_body) = r
            code_template = '''%TEMPLATE_LINE%
%RETURN_TYPE% %FUNC_NAME%(%ARG_LIST%){
  %FUNC_BODY%
}'''
            subst_map = { "%TEMPLATE_LINE%": template_line,
                          "%RETURN_TYPE%": return_type,
                          "%FUNC_NAME%": func_name,
                          "%ARG_LIST%": arg_list,
                          "%FUNC_BODY%": func_body}
            code = block_replace(code_template, subst_map)
            func_codes.append(code)
            func_return_types[func_name] = r[1]
    #TODO: retrieve function code and copy it into generated files....
    #endwhile
    if not code_line_found:
         raise RuntimeError("Function block defined at line %d of file %s is missing the 'code' statement" % (block_first_line, lhadafile.name))
#enddef parse_function

def parse_table():
    """Parsing a table black and generate corresponding code"""
    global tables, lhadafile
    mess("Parsing table block...")
    line1 = lhadafile.current_line_contents
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (lhadafile.current_line, lhadafile.name, l))
    #endif
    table_name = toks[1]
    mess("Table name: " + table_name)
    if table_name in tables:
        raise RuntimeError("Duplicate definition of table %s found line %d of file %s.\t%s\n" % (lhadfile.current_line, lhadafile.name, line1))
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
                raise RuntimeError("Syntax error in line %d of file %s. The first statement of a table body should start with thre keyword 'type'.\n\t%s" % (lhadfile.current_line, lhadafile.name, l))
            else:
                table_type = toks[1]
                if table_type not in table_types:
                    raise RuntimeError("Syntax error in line %d of file %s. The name '%d' is not a valid type for a table. Supported types are %s.\n\t%s" % (lhadfile.current_line, lhadafile.name, ", ".join(table_types), l))
                #endif
            #endif
        elif columns is None:
            if toks[0] != "columns":
                raise RuntimeError("Syntax error in line %d of file %s. The second statement of a table body should start with the keyword 'columns'.\n\t%s" % (lhadfile.current_line, lhadafile.name, l))
            else:
                columns = toks[1:]
            #endif
        else:
            if toks[0] != "entry":
                raise RuntimeError("Syntax error in line %d of file %s. The third and following statements of a table body should start with the keyword 'entry'.\n\t%s" % (lhadfile.current_line, lhadafile.name, l))
            elif toks[1:].size() != columns.size():
                raise RuntimeError("Syntax error in line %d of file %s. Expecting %d values in the entry statement, while %d values were found.\n\t%s" % (lhadfile.current_line, lhadafile.name, columns.size(), toks[:1].size(), l))
            else:
                contents.append(toks[:1])
            #endif
        #endif
    tables[table_name] = [type, columns, contents]
        

def parse_cut():
    """Parsing a cut block and generate corresponding code"""
    global cut_names, func_codes, lhadafile
    mess("Parsing cut block...")
    global cuts
    line1 = lhadafile.current_line_contents
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (lhadafile.current_line, lhadafile.name, l))
    #endif
    cut_name = toks[1]
    mess("Cut name: " + cut_name)
    if cut_name in cuts:
        raise RuntimeError("Duplicate definition of object %s found line %d of file %s.\t%s\n" % (il, lhadafile.name, line1))
    cuts.append(cut_name)

    func_name = "cut_%s" % cut_name

    cutid = unique_name("k%s" % cut_name);
    cut_ids.append(cutid)
    
    func_code = """bool %s(){
    bool r = true;
""" % func_name
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
        if toks[0] != 'select':
            raise RuntimeError("Syntax error in line %d of file %s. Every line of the body of a cut block should start with the keyword 'select'.\n\t%s" % (lhadfile.current_line, lhadafile.name, l))
        #endif
        func_code += "    r &= " + parse_cut_line(" ".join(toks[1:])) + ";\n"
        #FIXME: handle duplicate names
    func_code += '''    return cutflow.fill(%s, r);
}''' % cutid
    func_codes.append(func_code)

def parse_cut_line(l):
    ''' '''
    l.strip()
    r = ""
    toks_ = re.split("([\W]+)", l)
    #fixing some splitting failures:
    toks = []
    for t in toks_:
        tt = re.split("([\]\[()<>=])", t)
        toks.extend(tt)
    #next t
    ops = [ "+", "-", "/", "*", "^", "**"]
    r = ""
    trans = {
        "size": "size()",
        "and": " && ",
        "or": " || ",
        "e": "E() ",
        "pt": "pt() ",
        "m": "mass() ",
        "phi": "phi() ",
        "px": "px() ",
        "py": "py() ",
        "pz": "pz() ",
        "theta": "theta() ",
        ".": ".",
        "(": "(",
        ")": ") ",
        ">": "> ",
        "<": " < ",
        ">=": " >= ",
        "<=": " >= ",
        "=": " == ",
        "==": " == ",
        "+" : " + ",
        "-": " - ",
        "*": " * ",
        ",": ", "
    };

    for tok in toks:
        tok = tok.strip()
        if len(tok) == 0:
            continue
        done = False
        for k, v in trans.iteritems():
            if tok == k:
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
            if tok in cuts:
                r += "cut_%s()" % tok
                continue
            #endif
            if tok in functions:
                r +=  tok
                continue
            raise RuntimeError("Entity '%s' referred line %d in file %s is not defined.\n\t%s\n" % (tok, lhadfile.current_line, lhadafile.name, l))
        #endif
        if tok == '[':
            r += "["
            continue
        if tok == ']':
            r += " - 1]"
            continue
            
        r += tok
        #TODO: handle function named arguments
    return r.rstrip()

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


def gen_cutid_decl_code():
    '''Generates c++ code which defines the cut ids used for the cutflow (cut_id_decl) and initialisation list for the Cutflow object (init). Returns (cut_id_decl, init) '''
    code_decl = "enum {"
    code_init = "{"
    s = ""
    for c in cut_ids:
        code_decl += s + c
        code_init += s + '"%s"' % c
        s = ", "
    #next c
    code_decl += "} CutIds;"
    code_init += "}"
    return (code_decl, code_init)
        

def gen_code():
    global analysis_code_template, includes, include_block, objects

    #Generate #include list block:
    for i in includes:
        if not i:
            continue
        if i[0] not in [ '"', '<' ]:
            i = '"' + i + '"'
        include_block += '#include %s\n' % i
    #next i

    #Generate histograming code:
#    gen_histo_code()

    analysis_name = canonize_analysis_name(args.analysis_name)


    (cutid_decl, cutid_init) = gen_cutid_decl_code()
    
    # we substitude the code block in two steps in
    # order to check if the instance 'particles' is used
    # before generating the code that creates it.
    
    # Inserts complete code blocks in the code template:
    subst_map = {"%INCLUDE_BLOCK%": include_block,
                 "%CUT_IDS%": cutid_decl,
                 "%PROJECTION_INIT%": proj_init,
                 "%COUNTER_INIT%": counter_init,
                 "%OBJECT_DEFINITIONS%": obj_def,
                 "%COUNTER_FILL%": counter_fill,
                 "%COUNTER_DECLARATION%": counter_decl,
                 "%OBJECT_CUTS%": "\n\n".join(obj_cuts), 
                 "%FUNCTION_DEFINITIONS%": "\n\n".join(func_codes),
                 "%WEIGHT%" : "",
                 "%CUTS%": "",
                 "%COUNTER_FILL%":""
    }

    print '>>>0', analysis_code_template
    
    code = block_replace(analysis_code_template, subst_map)

    print '>>>1', code

    subst_map = { "%ANALYSIS_NAME%": analysis_name,
                  "%CUTFLOW_INIT%": cutid_init}
    code = multi_replace(code, subst_map)
    print '>>>2', code
    
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

    gen_code()
    
                        
if __name__ == "__main__":
    try:
        main()
    except RuntimeError as e:
        if args.debug:
            raise
        else:
            print e

    
