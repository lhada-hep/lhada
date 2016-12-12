#!/usr/bin/env python

import re
import argparse
import sys

block_start = re.compile(r'object|cut|region|function|table')
analysis_code_template = """

// -*- C++ -*-
#include "Rivet/Analysis.hh"

%INCLUDE_BLOCK%

namespace Rivet {


  class RivetAnalysis : public Analysis {
  public:

    /// Constructor
    RivetAnalysis()
      : Analysis("RivetAnalysis")
    {  }


    /// Book histograms and initialise projections before the run
    void init() {

      FinalState fs;
      VisibleFinalState visfs(fs);

      %PROJECTION_INIT%

      %COUNTER_INIT%
    }

    %FUNCTION_DEFINITIONS%

    /// Perform the per-event analysis
    void analyze(const Event& event) {

       %OBJECT_DEFINITIONS%

       %WEIGHT%

       %CUTS%

       %COUNTER_FILL%

    }


    /// Normalise histograms etc., after the run
    void finalize() {
    }


  private:

    /// @name Histograms
    %COUNTER_DECLARATION%
  };
  DECLARE_RIVET_PLUGIN(%ANALYSIS_NAME%)
}\n"""

include_block = ""
includes = [""]
proj_init = ""
counter_init = ""
obj_def = ""
weight_funcs = {}
counter_fill = ""
counter_decl = ""
outfile = None
names = {}
func_codes = []
tables = {}
table_types = ["events", "limits", "cutflow", "corr", "bkg"]
histo_booking = ""

#list of defined objects
objects = []

#list of defined cuts
cuts = []

#list of defined functions
functions = []

def unique_name(name):
    """Generate a unique name to be used in the analysis code as variable name or projection tag. If the name has not been used yet (first call with this value) the name is return as is, otherwise a sequential number is appended to it"""
    try:
        i = names[name] + 1
        names[name] = i
        return name + str(i)
    except KeyError:
        names[name] = 0
        return name
#enddef        

def mess(m):
    if args.verbose:
        sys.stderr.write("%s\n" % m);

def report_syntax_error(line_num, filename, line, message = ""):
    if message and len(message) > 0:
        message = " " + message + "."
    #endif    
    mess = "Syntax error in line %d of file %s.%s\n\t%s\n" % (line_num, filename, message, line)
    #sys.stderr.write(mess)
    raise RuntimeError(mess)

def gen_antikt(object_name, dR, ptmin, etamax):
    global proj_init, obj_def
    includes.append("Rivet/Projections/FastJets.hh")
    name = unique_name(object_name)
    projname = unique_name(object_name + "Proj")
    proj_init += 'addProjection(FastJets(fs, FastJets::ANTIKT, %g), "%s");\n' % (dR, name)
    obj_def   += multi_replace('''const FastJets& jetPro = applyProjection<FastJets>(event, "JETS");
const Jets JETS = jetPro.jetsByPt();\n''', {"JETS": name, "jetPro": projname})
    return name
    

def gen_part_per_id(self, object_name, pdg_id_string, ptmin, etamax, accept_tau_decay = True):
    global proj_init, obj_def
    name = unique_name(object_name)
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

def gen_electron(self, object_name, ptmin, etamax, accept_tau_decay = True):
    gen_part_per_id(object_name, "PID:ELECTRON", ptmin, etamax, accept_tau_decay = True)

def gen_muon(self, object_name, ptmin, etamax, accept_tau_decay = True):
    gen_part_per_id(object_name, "PID:MUON", ptmin, etamax, accept_tau_decay = True)

def gen_weight(self, object_name, func_name):
    global weight_func

    
def parse(infile):
    with open(infile) as f:
        il = 0
        while True :
            l = f.readline()
            mess("> " + l)
            il += 1
            if len(l) == 0:
                break;
#        for il, l in enumerate(f):
            l = preprocess_line(l)
            if len(l) == 0:
                continue
            #endif
            toks = l.split()
            if toks[0] == 'object':
                il = parse_object(l, il, f)
            elif toks[0] == 'cut':
                il = parse_cut(l, il, f)
            elif toks[0] == 'region':
                il = parse_region(l, il, f)
            elif toks[0] == 'function':
                il = parse_function(l, il, f)
            elif toks[0] == 'table':
                il = parse_table(l, il, f)
            else:
                report_syntax_error(il+1, infile, l, "Unknown keyword '%s'" % toks[0])
            #endif
    
def preprocess_line(l):
    """Trim spaces from beginning and end of a line and remove comments."""
    l = l.strip()
    pos = l.find('#')
    if pos < 0:
        return l
    else:
        mess("pos: %d" % pos)
        return l[:pos]

def multi_replace(s, replace_map):
    for key, value in replace_map.items():
#        mess(key, "->", value)
        s = s.replace(key, value)
    #next key. value
    return s

def block_replace(s, replace_map):
    '''Insert text blocks in a string at location indentified by keys. The block is indented and aligned to the key position. The key must start and end with a percent sign and should not contain space. s contains the text where substitution must be made and replace_map is an associative array with the keys and the corresponding text block'''
    r = ""
    for l in s.split("\n"):
        p1 = re.compile(r'([\s]*)(%[^\s]+%)(.*)')
        m = p1.match(l)
        if m:
            (indent, toks, tail) = m.groups()
            try:
                for l in replace_map[toks].split("\n"):
                    if l and len(l) > 0:
                        r += indent + l + "\n"
            except KeyError:
                pass
            #endtry
            if not re.search(tail, r'[\s]*'):
                r += tail + "\n"
            #endif
        else:
            r += l + "\n"
        #endif
    return r

def generate_cut(collection, observable, operator, value):
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


def generate_apply(object_name, func_name, args):
    mess("Generating code for apply %s(%s)" % (func_name, ", ".join(args)))

    #FIXME: support for multiple apply lines in same objet block: need to create intermediate objects
    if func_name == "antikt":
        args = check_args(args, {"dR": [float, 0.4], "ptmin": [float, 0], "etamax": [float, None]})
        return gen_antikt(object_name, args["dR"], args["ptmin"], args["etamax"])
    if func_name == "antikt_b":
        args = check_args(args, {"dR": [float, 0.4], "ptmin": [float, 0], "etamax": [float, None]})
        #FIXME: need to select b's!
        return gen_antikt(object_name, args["dR"], args["ptmin"], args["etamax"])            
    elif func_name == "electron":
        args = check_args(args, {"ptmin": [float, 0], "etamax": [float, None]})
        return gen_electron(object_name, args["ptmin"], args["etamax"])
    elif func_name == "muon":
        args = check_args(args, {"ptmin": [float, 0], "etamax": [float, None]})
        return gen_muon(object_name, args["ptmin"], args["etamax"])
        

def parse_object(line1, il, f):
    global weight_funcs
    mess("Parsing object block...")
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (il + 1, fname, l))
    #endif
    object_name = toks[1]
    mess("Object name: " + object_name)
    global objects
    if object_name in objects:
        raise RuntimeError("Duplicate definition of object %s found line %d of file %s.\t%s\n" % (il, f.name, line1))
    objects.append(object_name)
    pp = f.tell()
    line_offset = -1
    while True:
        p = f.tell()
        l = f.readline()
        if len(l) == 0:
            break
        line_offset += 1
#    for line_offset, l in enumerate(f):
#        p = pp
#        pp = f.tell()
        il += 1
        l = preprocess_line(l)
        if len(l) == 0:
            continue
        #endif
        if block_start.match(l):
            f.seek(p)
            mess("End of block object %s" % object_name)
            break;
        toks = l.split()
        input_collection = ""
        last_obj = None
        if line_offset == 0:
            if toks[0] != 'take':
                raise RuntimeError("Syntax error in line %d of file %s: the first statement of a object block must be a take statement specifying the input collection.\n\t" % (il + 1, f.name, l))
            #endif
            if len(toks) != 2:
                raise RuntimeError("Syntax error in line %d of file %s: the first statement of a object block must be a take statement specifying the input collection.\n\t" % (il + 1, f.name, l))
            #endif
            input_collection = toks[1]
            last_obj = input_collection
        else:
            if toks[0] == 'select':
                pattern = re.compile(r'select\s+([^\s<>=.]+).([^\s<>=.]+)\s*([<>=]+=?)\s*([^\s<>=]+)')
                m = pattern.match(l)
                if not m:
                    raise RuntimeError("Syntax error in line %d of file %s: select statement should follow the format 'select variable operator value.\n\t" % (il + 1, f.name,l))
                #endif
                (collection, observable, operator, value) = m.groups()
                generate_cut(collection, observable, operator, value)
                #endif
            elif toks[0] == 'apply':
                pattern = re.compile(r'apply\s+([^\s]+)\(([^)]*)\)')
                m = pattern.match(l)
                if not m:
                    raise RuntimeError("Syntax error in line %d of file %s: apply statement should follow the format 'apply function(args...).\n\t%s" % (il, f.name, l))
                (func_name, args) = m.groups()
                #split args into [ "param1=value1", "param2=value2",...]:
                args = "".join([ x for x in args if x not in [' ', '\t']]).split(",")
                #split args into { "param1": "value1", "param2": "value2", ...}
                args = dict(map(lambda(x): x.split("="), args))
                generate_apply(object_name, func_name, args)
            elif toks[0] == 'weight':
                pattern = re.compile(r'weight\s+([^\s]+)')
                m = pattern.match(l)
                (func_name) = m.groups()
                if not m:
                    raise RuntimeError("Syntax error in line %d of file %s: weight statement should follow the format 'weight function.\n\t%s" % (il, fname, l))
                weight_funcs[object_name] = func_name
    return line_offset

def parse_function(line1, il, f):
    """Parsing a function block. Information from functions blocks are not required by the translator, the block is skipped."""
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the function is missing a name.\n\t" % (il + 1, fname, l))
    #endif
    func_name = toks[1]
    mess("Function name: " + func_name)
    global functions
    functions.append(func_name)
    
    while True:
        p = f.tell()
        l = f.readline()
        if len(l) == 0:
            break
        il += 1
        l = preprocess_line(l)
        if len(l) == 0:
            continue;
        if block_start.match(l):
            f.seek(p)
            break
    return il

def parse_table(line1, il, f):
    """Parsing a table black and generate corresponding code"""
    global tables
    mess("Parsing table block...")
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (il + 1, fname, l))
    #endif
    table_name = toks[1]
    mess("Table name: " + table_name)
    if table_name in tables:
        raise RuntimeError("Duplicate definition of table %s found line %d of file %s.\t%s\n" % (il, f.name, line1))
    tables[table_name] = None
#    while True:
    line_offset = -1
    table_type = None
    columns = None
    contents = []
    while True:
        p = f.tell()
        l = f.readline()
        if len(l) == 0:
            break
        il += 1
        l = preprocess_line(l)
        if len(l) == 0:
            continue;
        if block_start.match(l):
            f.seek(p)
            break
        toks = l.split()
        if table_type is None:
            if toks[0] != "type":
                raise RuntimeError("Syntax error in line %d of file %s. The first statement of a table body should start with thre keyword 'type'.\n\t%s" % (il+1, f.name, l))
            else:
                table_type = toks[1]
                if table_type not in table_types:
                    raise RuntimeError("Syntax error in line %d of file %s. The name '%d' is not a valid type for a table. Supported types are %s.\n\t%s" % (il+1, f.name, ", ".join(table_types), l))
                #endif
            #endif
        elif columns is None:
            if toks[0] != "columns":
                raise RuntimeError("Syntax error in line %d of file %s. The second statement of a table body should start with the keyword 'columns'.\n\t%s" % (il+1, f.name, l))
            else:
                columns = toks[1:]
            #endif
        else:
            if toks[0] != "entry":
                raise RuntimeError("Syntax error in line %d of file %s. The third and following statements of a table body should start with the keyword 'entry'.\n\t%s" % (il+1, f.name, l))
            elif toks[1:].size() != columns.size():
                raise RuntimeError("Syntax error in line %d of file %s. Expecting %d values in the entry statement, while %d values were found.\n\t%s" % (il+1, f.name, columns.size(), toks[:1].size(), l))
            else:
                contents.append(toks[:1])
            #endif
        #endif
    tables[table_name] = [type, columns, contents]
    return il

        

def parse_cut(line1, il, f):
    """Parsing a cut block and generate corresponding code"""
    global cut_names
    global func_codes
    mess("Parsing cut block...")
    global cuts
    toks = line1.split()
    if len(toks) < 2:
        raise RuntimeError("Syntax error in line %d of file %s: the object is missing a name.\n\t" % (il + 1, fname, l))
    #endif
    cut_name = toks[1]
    mess("Cut name: " + cut_name)
    if cut_name in cuts:
        raise RuntimeError("Duplicate definition of object %s found line %d of file %s.\t%s\n" % (il, f.name, line1))
    cuts.append(cut_name)

    func_name = "cut_%s" % cut_name

    func_code = """bool %s(){
    bool r = true;
""" % func_name
    pp = f.tell()
    line_offset = -1
    while True:
        p = f.tell()
        l = f.readline()
        if len(l) == 0:
            break
        il += 1
        l = preprocess_line(l)
        if len(l) == 0:
            continue;
        if block_start.match(l):
            f.seek(p)
            break
        toks = l.split()
        if toks[0] != 'select':
            raise RuntimeError("Syntax error in line %d of file %s. Every line of the body of a cut block should start with the keyword 'select'.\n\t%s" % (il+1, f.name, l))
        #endif
        func_code += "    r &= " + parse_cut_line(" ".join(toks[1:]), il, f) + ";\n"
        #FIXME: handle duplicate names
    func_code += """    return r;
}"""
    func_codes.append(func_code)
    return il

def parse_cut_line(l, il, f):
    l.strip()
    r = ""
    toks_ = re.split("([\W]+)", l)
    #fixing some splitting failures:
    toks = []
    for t in toks_:
        tt = re.split("([\]\[()<>=])", t)
        toks.extend(tt)
    #next t
    print '>>>> tokens: ', toks
    ops = [ "+", "-", "/", "*", "^", "**"]
    r = ""
    trans = {
        "size": "size() ",
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
        "<": "< ",
        ">=": ">= ",
        "<=": ">= ",
        "+" : "+ ",
        "-": "- ",
        "*": "* ",
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
                continue
            #endif
            if tok in functions:
                r +=  tok
                continue
            raise RuntimeError("Entity '%s' referred line %d in file %s is not defined.\n\t%s\n" % (tok, il+1, f.name, l))
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

#under dev# def generate_histo_code():
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

def generate_code():
    global analysis_code_template, includes, include_block
    for i in includes:
        include_block += '#include "%s"\n' % i
    #next i
#    generate_histo_code()
    subst_map = {"%INCLUDE_BLOCK%": include_block, "%PROJECTION_INIT%": proj_init, "%COUNTER_INIT%": counter_init, "%OBJECT_DEFINITIONS%": obj_def, "%COUNTER_FILL%": counter_fill, "%COUNTER_DECLARATION%": counter_decl, "%ANALYSIS_NAME%": args.analysis_name, "%FUNCTION_DEFINITIONS%": "\n\n".join(func_codes)}
#    code = multi_replace(analysis_code_template, subst_map)
    code = block_replace(analysis_code_template, subst_map)
    with open(args.analysis_name + ".cc", "w") as f:
        f.write(code + "\n")


def main():
    parser = argparse.ArgumentParser(description='Produce Rivet code for an analysis decribed in LHADA format.')
    
    parser.add_argument('lhadafile', action='store', default=None,
                        help='File describing the analysis')

    parser.add_argument('analysis_name', action='store', default=None,
                        help='Analysis name')
    

    parser.add_argument('--verbose', action='store_true', default=False, help='Activate verbose mode')

    global args
    
    args = parser.parse_args()
    
    parse(args.lhadafile)

    generate_code()
    
                        
if __name__ == "__main__":
    main()
