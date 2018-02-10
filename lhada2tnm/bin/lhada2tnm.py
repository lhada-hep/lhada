#!/usr/bin/python
#--------------------------------------------------------------------------------
# Description: Prototype translator of a LHADA description to a TNM analyzer
# Created: 12-Dec-2017 Harrison B. Prosper & Sezen Sekmen
#--------------------------------------------------------------------------------
import sys, os, re, optparse, urllib
from time import ctime
from string import joinfields, split, replace, find, strip
#--------------------------------------------------------------------------------
DEBUG = 0

# LHADA Block types
BLOCKTYPES = ['info', 'table', 'function', 'object', 'variable', 'cut']

# LHADA keywords
KEYWORDS   = ['experiment',
              'id',
              'publication',
              'sqrtS',
              'lumi',
              'arXiv',
              'hepdata',
              'doi',
              'arg',
              'code',
              'take', 'loop', 'select', 'apply', 'reject']



SPACE6   = ' '*6

# some simple regular expression to dissect lhada file
KWORDS   = r'\b(%s)\b' % joinfields(KEYWORDS, '|')
exclude  = re.compile(KWORDS)
getwords = re.compile('lha[.][a-zA-Z0-9]+|[a-zA-Z][a-zA-Z0-9_]*')
getvars  = re.compile('@?[a-zA-Z][a-zA-Z0-9_.;:]*@?')
getdvars = re.compile('[a-zA-Z]+[a-zA-Z0-9;:]*[.]')
cppAND   = re.compile(r'\band|AND\b')
cppOR    = re.compile(r'\bor|OR\b')
cppEQEQ  = re.compile('(?<!=|[>]|[<])=')
scrubdot = re.compile('[a-zA-Z]+[.]')
getfunctions = re.compile('^\s*[\w_]+\s+[a-zA-Z][\w_]+\s*[(][^{]+', re.M)
#--------------------------------------------------------------------------------
NAMES = {'name': 'analyzer',
             'treename': 'Delphes',
             'info': '//',
             'time': ctime(),
             'aoddef': '',
             'aodimpl': '',
             'adapter': 'adapter',
             'analysis': ''
             }

# C++ TNM analyzer template
TEMPLATE_CC =\
'''//---------------------------------------------------------------------------
// File:        %(name)s.cc
// Description: Analyzer for LHADA analysis:
%(info)s
// Created:     %(time)s by lhada2tnm.py
//----------------------------------------------------------------------------
#include "tnm.h"
#include "LHParticle.h"
#include "%(adaptername)s.h"
%(includes)s
using namespace std;
//----------------------------------------------------------------------------
// The following functions, objects, and variables are globally visible.
//----------------------------------------------------------------------------
%(fundef)s
//----------------------------------------------------------------------------
%(objdef)s
//----------------------------------------------------------------------------
%(vardef)s
//----------------------------------------------------------------------------
%(cutdef)s
//----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  // If you want canvases to be visible during program execution, just
  // uncomment the line below
  //TApplication app("%(name)s", &argc, argv);

  // Get command line arguments
  commandLine cl(argc, argv);
    
  // Get names of ntuple files to be processed
  vector<string> filenames = fileNames(cl.filelist);

  // Create tree reader
  itreestream stream(filenames, "%(treename)s");
  if ( !stream.good() ) error("can't read root input files");

  // Create a buffer to receive events from the stream
  // The default is to select all branches
  // Use second argument to select specific branches
  // Example:
  //   varlist = 'Jet_PT Jet_Eta Jet_Phi'
  //   ev = eventBuffer(stream, varlist)

  eventBuffer ev(stream);
  int nevents = ev.size();
  cout << "number of events: " << nevents << endl;

  // Create output file for histograms; see notes in header 
  outputFile of(cl.outputfilename);

  // -------------------------------------------------------------------------
  // Define histograms
  // -------------------------------------------------------------------------
  //setStyle();

  // -------------------------------------------------------------------------
  // Create an appropriate event adapter
  // -------------------------------------------------------------------------
  %(adaptername)s %(adapter)s;

  // -------------------------------------------------------------------------
  // Loop over events
  // ------------------------------------------------------------------

  for(int entry=0; entry < nevents; entry++)
    {
      // read an event into event buffer
      ev.read(entry);

%(extobjimpl)s
%(intobjimpl)s
%(varimpl)s
%(cutimpl)s
    }   
%(summary)s
  ev.close();
  of.close();
  return 0;
}
'''
#--------------------------------------------------------------------------------
VERSION = 'v1.0.0'
USAGE ='''
    Usage:
       lhada2tnm.py [options] LHADA-file-name

    Options:
    -a name of analyzer to be created [delphesAnalyzer]
    -e name of event adapter          [DelphesAdapter]
    -t name of TNM ROOT tree          [Delphes]
    '''
def decodeCommandLine():

    parser = optparse.OptionParser(usage=USAGE, version=VERSION)
            
    parser.add_option("-a", "--analyzer",
                      action="store",
                      dest="name",
                      type="string",
                      default='delphesAnalyzer',
                      help="name of analyzer to be created")

    parser.add_option("-e", "--eventadapter",
                      action="store",
                      dest="adaptername",
                      type="string",
                      default='DelphesAdapter',
                      help="name of event adapter")

    parser.add_option("-t", "--tree",
                      action="store",
                      dest="treename",
                      type="string",
                      default='Delphes',
                      help="name of ROOT tree")

    options, args = parser.parse_args()
    if len(args) == 0:
        sys.exit(USAGE)
        
    # get inspire command
    filename = args[0]
    return (filename, options)

def nameonly(s):
    return posixpath.splitext(posixpath.split(s)[1])[0]

def join(left, a, right):
    s = ""
    for x in a:
        s = s + "%s%s%s" % (left, x, right)
    return s

def getWords(records):
    words = []
    for record in records:
        words += split(record)
    # exclude LHADA keywords
    record = joinfields(words, ' ')
    words  = split(exclude.sub('', record))
    return words

def boohoo(message):
    sys.exit('** lhada2tnm.py * %s' % message)
#------------------------------------------------------------------------------
# Look for header file on given list of search paths
def findHeaderFile(infile, incs):
	file = strip(os.popen("find %s 2>/dev/null" % infile).readline())    
	if file != "":
		filepath = file
		for includepath in incs:
			tmp = splitfields(filepath, includepath + '/',1)
			if len(tmp) == 2:
				base, file = tmp
			else:
				base = ''
				file = tmp[0]

			if base == '': return (filepath, file)
		return (filepath, filepath)

	file = infile
	for includepath in incs:
		filepath = includepath + "/" + file
		filepath = strip(os.popen("find %s 2>/dev/null" % filepath).readline())
		if filepath != "": return (filepath, file)

		filepath = includepath + "/include/" + file
		filepath = strip(os.popen("find %s 2>/dev/null" % filepath).readline())
		if filepath != "": return (filepath, file)

	return ("","")
#------------------------------------------------------------------------------
funcname = re.compile('[a-zA-Z]+[\w\<:,\>]*(?=[(])')
findtemparg = re.compile('(?<=[<]).+(?=[>])')
def decodeFunction(record):
    record = replace(record, "\n", " ")
    fname  = funcname.findall(record)
    if len(fname) == 0:
        boohoo("can't decode %s" % record)
    fname = fname[0]
    rtype, args = split(record, fname)
    rtype = strip(rtype)
    args  = strip(args)[1:-1]
    
    # since template arguments can include commas, hide them before
    # splitting using commas
    targs  = findtemparg.findall(args)
    hidden = []
    for ii, t in enumerate(targs):
        orig = '<%s>' % t
        temp = '@%d' % ii
        hidden.append((orig, temp))
        args = replace(args, orig, temp)

    # replace commas by "#" and go back to original types
    # and split at "#"
    args = map(strip, split(args, ","))
    args = joinfields(args, '#')
    for orig, temp in hidden:
        args = replace(args, temp, orig)

    # ok, now get types etc.
    args = map(strip, split(args, "#"))
    argtypes = []
    argnames = []
    for arg in args:
        t = split(arg, ' ')
        if len(t) == 1:
            argtypes.append(t[0])
            argnames.append('')
        elif len(t) > 1:
            argtypes.append(joinfields(t[:-1], ' '))
            argnames.append(t[-1])
    return (rtype, fname, argtypes, argnames)
#-----------------------------------------------------------------------------
# use a simple bubble-like sort to sort blocks according to dependency
def sortObjects(objects):
    from copy import deepcopy
    # 1) get blocks with no dependencies on internal blocks
    obs = []
    names = []
    for t in objects:
        name  = t[0]
        words = t[1]
        if len(words) > 0: continue
        # this block has no internal dependencies
        obs.append(deepcopy(t))
        names.append(name)
        #print "%-16s\t%s" % (name, words)
        t[0] = None
    names = set(names)
    #print '-'*80    
    #print names
    #print '-'*80
    
    # 2) sort remaining blocks so that dependent blocks occur after the
    #    the blocks on which they depend
    for ii in xrange(len(objects)):
        for t in objects:
            name  = t[0]
            if name == None: continue
            words = t[1]                
            
            incomplete = len(words.intersection(names)) < len(words) 
            if incomplete: continue
            #print "%-16s\t%s" % (name, words)
            # the dependency of this block has been fully satisfied
            obs.append(deepcopy(t))
            names.add(name)
            t[0] = None
    return obs    
#--------------------------------------------------------------------------------
# Read LHADA file and extract blocks into a simple internal data structure
#--------------------------------------------------------------------------------
def extractBlocks(filename):
    from copy import deepcopy
    import re
    from string import rstrip, split, strip    
    #--------------------------------------------
    # read LHADA file
    #--------------------------------------------    
    try:
        records = open(filename).readlines()
    except:
        boohoo('unable to open LHADA file %s' % filename)
    records = map(rstrip, records)

    #--------------------------------------------    
    # set up some simple regular expressions
    #--------------------------------------------    
    stripcomments = re.compile('[#].*')
    blocktypes = r'\b(%s)\b' % joinfields(BLOCKTYPES, '|')
    isblock = re.compile(blocktypes)

    #--------------------------------------------    
    # look over lhada records
    #--------------------------------------------    
    blocks = {}
    bname  = None
    objectnames = [] # keep track of block names
    cutnames    = [] # keep track of cut names
    for ii, record in enumerate(records):
        iline = ii+1
        # strip away comments from current record
        record = stripcomments.sub('', record)
        if strip(record) == '': continue

        # look for a block
        if isblock.findall(record) != []:

            # found a block and get its type and name
            t = split(record)
            if len(t) != 2:
                boohoo('problem at line\n%4d %s\n' % (iline, record))
            btype, bname = t

            # do not allow duplicate block names
            if blocks.has_key(bname):
                boohoo('duplicate block name %s at line'\
                           '\n%4d %s\n' % (bname, iline, record))
            blocks[bname] = {'type': btype, 'body': []}
            if btype == 'object':
                objectnames.append(bname)
            elif btype == 'cut':
                cutnames.append(bname)
            continue
        
        if bname == None:
            boohoo('problem at line\n%4d %s\n' % (iline, record))
            
        blocks[bname]['body'].append(record)

    # convert list of object names to a set for easier comparisons
    objectnames = set(objectnames)
    cutnames    = set(cutnames)
    
    # reorganize the blocks
    blockmap = {}
    for key in blocks.keys():
        block = blocks[key]
        blocktype = block['type']
        if not blockmap.has_key(blocktype):
            blockmap[blocktype] = []
        body  = block['body']
        words = joinfields(getWords(body), ' ')
        words = set(getwords.findall(words))

        # if block type is object, strip away words within this
        # block that are not object names using set intersection:
        # C = A and B
        if blocktype == 'object':
            words = objectnames.intersection(words)
        elif blocktype == 'cut':
            words = cutnames.intersection(words)
            
        blockmap[blocktype].append([key, deepcopy(words), deepcopy(body)])

    # sort object blocks so that a block that depends on other blocks
    # is placed after those blocks.
    if blockmap.has_key('object'):
        blockmap['object'] = sortObjects(blockmap['object'])

    # sort cut blocks so that a block that depends on other blocks
    # is placed after those blocks.
    if blockmap.has_key('cut'):
        blockmap['cut'] = sortObjects(blockmap['cut'])        
    return blockmap
#--------------------------------------------------------------------------------
def printBlocks(blocks):
    out = open('blocks.log', 'w')
    for blocktype in BLOCKTYPES:
        if not blocks.has_key(blocktype): continue
        record = "[%s]" % blocktype
        out.write('%s\n' % record)
        record = '-'*80
        out.write('%s\n' % record)
        for name, words, body in blocks[blocktype]:
            record = "%-12s\t%s" % (name, words)
            out.write('%s\n' % record)
            for record in body:
                record = "\t%s" % record
                out.write('%s\n' % record)
            record = '-'*80
            out.write('%s\n' % record)
    out.close()
#--------------------------------------------------------------------------------
# The following functions convert LHADA blocks to C++
#--------------------------------------------------------------------------------
def process_info(names, blocks):
    info = '//\n// LHADA file: %(filename)s\n' % names
    info+= '// info block\n'
    name, words, body = blocks['info'][0]
    for record in body:
        t = split(record)
        record = '//\t%-12s\t%s\n' % (t[0], joinfields(t[1:], ' '))
        info += record
    info += '//'
    names['info'] = info
#--------------------------------------------------------------------------------
def process_functions(names, blocks):
    # extract headers to be included
    includeset = set()
    for name, words, records in blocks['function']:
        for record in records:
            t = split(record)
            token = t[0]
            if token != 'code': continue
            includeset.add(t[1])
    includes = ''
    for record in includeset:
        includes += '#include "%s"\n' % record
    names['includes'] = includes

    # create functions
    fundef = '//\n// functions\n'
    functions = {}
    for name, words, records in blocks['function']:
        origname = name
        # this function could be within a namespace:
        # <namespace>.[<namespace>.]<function>
        t = split(name, '.')
        name = t[-1] # assume function name is last field
        if len(t) > 1:
            namespace = joinfields(t[:-1], '::') + '::'
        else:
            namespace = ''
        extname = namespace + name
        intname = replace(extname, '::', '_')

        # get details of external function
        args = []
        for record in records:
            t = split(record)
            token = t[0]
            if token == 'arg':
                args.append(t[1])
                continue
            elif token != 'code':
                continue

            # got code. could be inline or external (via a header)
            code  = t[1]
            # internal code not yet implemented
            if code == 'c++': continue
                
            # assume this is a header. find it
            t = findHeaderFile(code, ['*'])
            include = t[0]
            record = open(include).read()
            t = getfunctions.findall(record)
            for x in t:
                rtype, namen, argtypes, argnames = decodeFunction(x)
                if name == namen:
                    # we have a match, so create function
                    if len(args) != len(argtypes):
                        sys.exit('''
**lhad2tnm.py** argument count mismatch in function %s.
expected arguments %s, but %s found in LHADA file
''' % (origname, v, args))
                    argsrec = ''
                    argscall= ''
                    for ii, arg in enumerate(args):
                       argsrec += '%s %s, ' % (argtypes[ii], arg)
                       argscall+= '%s, ' % arg
                    if argsrec != '':
                        argsrec = argsrec[:-2]
                        argscall= argscall[:-2]
                    
                    fundef += '''%(rtype)s\t%(intname)s(%(args)s)
{
  return %(extname)s(%(argscall)s);
};
''' % {'rtype': rtype,
           'intname': intname,
           'extname': extname,
           'args': argsrec,
           'argscall': argscall}
                    # cache function info
                    functions[origname] = (rtype, intname, extname, argtypes)
    names['fundef'] = fundef
    
    blocks['function_info'] = functions
#--------------------------------------------------------------------------------
# check whether current record is within an inner loop
def withinLoop(record, loopvar):
    from copy import deepcopy
    words = set(getvars.findall(record))
    extra = deepcopy(words)
    for word in words:
        t = getdvars.findall(word)
        if len(t) == 0: continue
        for x in t: extra.add(x)
    t = extra.intersection(loopvar)
    within = len(t) > 0
    return within

def convert2cpp(record, btype, blocktypes):
    #print record
    # do some simple fixes
    record = replace(record, "|", "@")
    record = replace(record, "[", ";:")
    record = replace(record, "]", ":;")
    record = cppAND.sub('&&', record)
    record = cppOR.sub('||', record)
    record = cppEQEQ.sub('==', record)

    words  = getvars.findall(record)
    if DEBUG > 0:
        print record
        print "\t", words
        
    for name in words:
        # if this is an object block,
        # check if variable is of the form a.b
        # if it is, we make the replacement a.b -> a("b"). 
        # consider PT and e.PT
        # but we want
        #    PT    -> p("PT") if PT is not preceded by "e."
        #    e.PT  -> e("PT") if PT is preceded by "e."
        # if, however, this is a cut object, we make the following
        # changes: .size -> .size()
        #          a.b   -> a("b")
        
        t = split(name, '.')
        undotted = len(t) == 1
        oname = t[0]
        field = t[-1]
        newfield = field
        
        # need to handle things like PT and e.PT
        if btype == 'object':
            if undotted:
                oname = "p"
                edit = re.compile('(?<![.])%s' % field)
            else:
                edit = re.compile('\\b%s\\b' % name)
            newfield = '%s("%s")' % (oname, field)
            record = edit.sub(newfield, record)
        elif btype == 'apply':
            if undotted:
                oname = "p"
                edit = re.compile('(?<![.])%s' % field)
            else:
                edit = re.compile('\\b%s\\b' % name)
            newfield = '%s("%s")' % (oname, field)
            record = edit.sub(newfield, record)            
        elif btype == 'cut':
            if undotted:
                # check if this is the result of another section
                if name in blocktypes['cut']:
                    edit = re.compile('\\b%s\\b' % name)
                    newfield = 'cut_%s()' % name
                    record = edit.sub(newfield, record)
            else:
                edit = re.compile('\\b%s\\b' % name)
                if field == 'size':
                    newfield = '%s.%s()' % (oname, field)
                else:
                    newfield = '%s("%s")' % (oname, field)
                record = edit.sub(newfield, record)
                
        #print "oname( %s ) field( %s ) newfield( %s )" % (oname, field, newfield)        
        # some final cleanup
        record = replace(record, '@',  '|')
        record = replace(record, ';:', '[')
        record = replace(record, ':;', ']')
    #print record
    #print '-'*80
    if DEBUG > 0:
        print "\t\t", record
        print '-'*80
    return record

def process_singleton_object(name, records, tab, blocktypes):
    objdef = ''
    for record in records:
        t = split(record)
        token = t[0]
        value = joinfields(t[1:], ' ')
        if   token == 'take':
            objdef += '%s%s = %s;\n' % (tab, name, value);
    return objdef

def process_multiple_objects(name, records, TAB, blocktypes):
    tab     = TAB
    tab4    = ' '*4
    objdef  = '%s%s.clear();\n' % (tab, name)
    
    loopobj = None
    loopidx = None
    loopvar = set() # to cache loop variables
    
    # booleans for handling inner loops
    activeLoop = False # for inner loops

    if DEBUG > 0:
        print "\nNAME: %s" % name
    
    for index in xrange(len(records)):
        record= records[index]
        t     = split(record)
        token = t[0]
        value = joinfields(t[1:], ' ')

        if DEBUG > 0:
            print "\tTOKEN: %s\tVALUE: %s" % (token, value)
    
        if   token == 'take':
            # --------------------------------------------            
            # TAKE
            # --------------------------------------------            
            objdef += '%sfor(size_t c=0; c < %s.size(); c++)\n' % (tab, value)
            objdef += '%s  {\n' % tab
            objdef += '%s%sLHParticle& p = %s[c];\n' % (tab, tab4, value)

        elif token == 'loop':
            # --------------------------------------------            
            # LOOP
            # --------------------------------------------            
            try:
                loopobj, loopidx = t[1:]
            except:
                sys.exit(''' 
**lhada2tnm.py** 
%s
perhaps you're missing a loop variable in:
%s
''' % (objdef, record))
                
            # adjust tab
            tab = TAB + tab4
            activeLoop = True
            loopvar = set()
            
            objdef += '%sbool skip = false;\n' % tab
            objdef += '%sfor(size_t %sc=0; %sc < %s.size(); %sc++)\n' % \
              (tab, loopidx, loopidx, loopobj, loopidx)
            objdef += '%s  {\n' % tab
            objdef += '%s%sLHParticle& %s = %s[%sc];\n' % \
              (tab, tab4, loopidx, loopobj, loopidx)

            # cache loop variables
            loopvar.add('%s.' % loopidx)
            
        elif token == 'apply':
            # --------------------------------------------            
            # APPLY
            # --------------------------------------------
            fcall  = joinfields(t[1:-1], ' ')
            rvalue = t[-1]
            if fcall[-1] != ')':
                sys.exit(''' 
**lhada2tnm.py** 
%s
perhaps you're missing a return value in:
%s
''' % (objdef, record))

            a, b = split(fcall, '(')
            b = convert2cpp(b, 'apply', blocktypes)
            a = replace(a, '.', '_')
            fcall = '%s(%s' % (a, b)
            
            objdef += '%s%sdouble %s = %s;\n' % (tab, tab4, rvalue, fcall)
            objdef += '%s%sp("%s", %s);\n' % (tab, tab4, rvalue, rvalue)
            # cache loop variables
            loopvar.add(rvalue)
            
        elif token == 'select':
            # --------------------------------------------            
            # SELECT
            # --------------------------------------------
            objdef += '%s%sif ( !(%s) ) continue;\n' % \
              (tab, tab4,
                   convert2cpp(value, 'object', blocktypes))

        elif token == 'reject':
            # --------------------------------------------            
            # REJECT
            # --------------------------------------------
            objdef += '%s%sif ( %s )\n' % (tab, tab4,
                                               convert2cpp(value, 'object', blocktypes))
            objdef += '%s%s  {\n' % (tab, tab4)
            objdef += '%s%s    skip = true;\n' % (tab, tab4)
            objdef += '%s%s    break;\n' % (tab, tab4)
            objdef += '%s%s  }\n' % (tab, tab4)
        else:
            pass
        
        # get next record
        EOR = index >= len(records)-1

        if EOR:
            # this is the last record. if activeLoop is true
            # this means we are within an active inner loop
            # in which case we should close the loop and
            # add a skip command.
            if activeLoop:
                activeLoop = False
                tab = TAB
                objdef += '%s%s  };\n' % (tab, tab4)
                objdef += '%s%sif ( skip ) continue;\n' % (tab, tab4)            
        else:
            record= records[index+1]
            t     = split(record)
            token = t[0]
            value = joinfields(t[1:], ' ')

            # if activeLoop is true, check if next record terminates the
            # current inner loop. if the next record does not depend on
            # variables defined within the current innder loop, we assume
            # that the loop should be terminated. it would of course be
            # better to have a explicit endloop keyword.
            if activeLoop:
                if withinLoop(value, loopvar):
                    tab = TAB + tab4
                else:
                    activeLoop = False
                    tab = TAB
            
    objdef += '%s%s%s.push_back(p);\n' % (tab, tab4, name)
    objdef += '%s  }\n' % tab
    return objdef

def process_objects(names, blocks, blocktypes):
    from string import lower
    tab2 = ' '*2
    tab4 = ' '*4
    tab6 = ' '*6
    tab8 = ' '*8
    # some objects are singletons. try to guess which ones
    single = re.compile('missing.*et|met|event')
    extobjdef = ''
    intobjdef = ''
    extobj = set()
    
    extobjimpl = ''
    intobjimpl = '%s// create internal objects\n' % tab6
    
    for name, words, records in blocks['object']:
        for record in records:
            t = split(record)
            token = t[0]
            if token == 'take':
                objname = t[1]
                if objname not in blocktypes['object']:
                    extobj.add(objname)
                    if single.findall(lower(objname)) == []:
                        extobjdef += 'vector<LHParticle> %s;\n' % objname
                    else:
                        extobjdef += '\nLHParticle %s;\n\n' % objname

        if single.findall(lower(name)) == []:                        
            intobjdef += 'vector<LHParticle> %s;\n' % name
        else:
            intobjdef += '\nLHParticle %s;\n\n' % name
            
        intobjimpl += '%sobject_%s();\n' % (tab6, name)
        
    objdef = '''// external objects
%s
// internal objects
%s
''' % (extobjdef, intobjdef)
    
    extobjimpl = '%s// get external objects\n' % tab8
    adapter = names['adapter']
    for name in extobj:
        extobjimpl += '%s%s(ev, "%s", \t%s);\n' % (tab8, adapter, name, name)
 
    # implement object selections
    objdef += '\n// object definitions\n'
    objdef += 'struct lhadaThing\n'
    objdef += '{\n'
    objdef += '  lhadaThing() {}\n'
    objdef += '  ~lhadaThing() {}\n'
    objdef += '  virtual void summary() {}\n'    
    objdef += '};\n\n'
    
    for name, words, records in blocks['object']:
        objdef += 'struct object_%s_s : public lhadaThing\n' % name
        objdef += '{\n'
        objdef += '%sobject_%s_s() : lhadaThing() {}\n' % (tab2, name)
        objdef += '%s~object_%s_s() {}\n' % (tab2, name) 
        objdef += '%svoid operator()()\n' % tab2
        objdef += '%s{\n' % tab2
        singleton = single.findall(lower(name)) != []
        
        if singleton:
            objdef += process_singleton_object(name, records, tab4, blocktypes)
        else:
            objdef += process_multiple_objects(name, records, tab4, blocktypes)

        objdef += '%s};\n' % tab2
        objdef += '} object_%s;\n\n' % name
        
    names['objdef']     = objdef   
    names['extobjimpl'] = extobjimpl
    names['intobjimpl'] = intobjimpl
#--------------------------------------------------------------------------------    
def process_variables(names, blocks):
    vardef  = '// variables\n'
    varimpl = '%s// compute event level variables\n' % SPACE6
    for name, words, records in blocks['variable']:
        for record in records:
            t = split(record)
            token = t[0]
            if token != 'apply': continue
                
            # found an apply token
            func  = joinfields(t[1:], ' ')
            fname = split(func, '(')[0]
            if not blocks['function_info'].has_key(fname):
                sys.exit('''
**lhad2tnm.py** variable %s uses the function %s, 
but the latter may not have been defined in the LHADA file.
''' % (name, fname))
            rtype, intname, extname, argtypes = blocks['function_info'][fname]
            func = replace(func, fname, intname)
            vardef  += '%s\t%s;\n' % (rtype, name)
            varimpl += '%s%s\t= %s;\n' % (SPACE6, name, func)
    names['vardef']  = vardef
    names['varimpl'] = varimpl
#--------------------------------------------------------------------------------    
def process_cuts(names, blocks, blocktypes):
    cutdef  = '// selections\n'
    cutimpl = '%s// apply event level selections\n' % SPACE6
    summary = '  // count summary\n'
    summary += '  vector<lhadaThing*> cut;\n'
    for name, words, records in blocks['cut']:    
        summary += '  cut.push_back(&cut_%s);\n' % name
    summary += '\n'
    summary += '  std::cout << "event counts" << std::endl;\n'
    summary += '  for(size_t c=0; c < cut.size(); c++)\n'
    summary += '    cut[c]->summary();\n'       
    
    # implement selections
    tab2 = ' '*2
    tab4 = tab2*2
      
    for name, words, records in blocks['cut']:
        cutdef += 'struct cut_%s_s : public lhadaThing\n' % name 
        cutdef += '{\n'
        cutdef += '  std::string name;\n'
        cutdef += '  double count;\n'
        cutdef += '  double dcount;\n'
        cutdef += '  cut_%s_s() : lhadaThing(), name("%s"), count(0), dcount(0) {}\n' \
          % (name, name)
        cutdef += '  ~cut_%s_s() {}\n' % name

        cutdef += '  void summary()\n'
        cutdef += '  {\n'
        cutdef += '    printf("\\t%s-24s %s10.3f (%s10.3f)\\n",\n' % ('%', '%', '%')
        cutdef += '           name.c_str(), count, sqrt(dcount));\n'
        cutdef += '  }\n';      
        cutdef += '  bool operator()(double weight=1)\n'
        cutdef += '  {\n'
        for record in records:
            t = split(record)
            token = t[0]
            if token != 'select': continue
            value = joinfields(t[1:], ' ')
            # decode
            cutdef += '%sif ( !(%s) ) return false;\n' % \
              (tab4, convert2cpp(value, 'cut', blocktypes))
        cutdef += '%scount  += weight;\n'  % tab4
        cutdef += '%sdcount += weight * weight;\n'  % tab4
        cutdef += '%sreturn true;\n' % tab4
        cutdef += '  }\n'            
        cutdef += '} cut_%s;\n\n' % name
        cutimpl += '%scut_%s();\n' % (SPACE6, name)

    names['cutdef']  = cutdef
    names['cutimpl'] = cutimpl
    names['summary'] = summary
#--------------------------------------------------------------------------------
def main():
    filename, option = decodeCommandLine()
    names  = NAMES
    names['filename']    = filename
    names['name']        = option.name    
    names['treename']    = option.treename
    names['adaptername'] = option.adaptername
    
    names['fundef']   = ''
    names['objdef']   = ''
    names['vardef']   = ''
    names['aodimpl']  = ''
    names['analysis'] = ''
    
    blocks = extractBlocks(filename)

    blocktypes = {}
    for btype in BLOCKTYPES:
        blocktypes[btype] = set()
        if not blocks.has_key(btype): continue
        for name, words, records in blocks[btype]:
            blocktypes[btype].add(name)
            
    #printBlocks(blocks)
    
    process_info(names,      blocks)
    
    process_functions(names, blocks)

    process_objects(names,   blocks, blocktypes)

    process_variables(names, blocks)

    process_cuts(names,      blocks, blocktypes)
    
    # write out C++ function
    
    record = TEMPLATE_CC % names
    open('%(name)s.cc' % names, 'w').write(record)
#--------------------------------------------------------------------------------        
try:
    main()
except KeyboardInterrupt:
    print
    print "ciao!"
    
