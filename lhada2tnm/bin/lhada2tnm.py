#!/usr/bin/python
#--------------------------------------------------------------------------------
# Description: Prototype translator of a LHADA description to a TNM analyzer
# Created: 12-Dec-2017 Harrison B. Prosper & Sezen Sekmen
#          12-May-2018 HBP assume case insensitivity, remove dependence on loop
#                      keyword, better handling of mapping from vector<TEParticle>
#                      to vector<TLorentzVector>
#          14-May-2018 HBP add count histogram for each cut block
#--------------------------------------------------------------------------------
import sys, os, re, optparse, urllib
from time import ctime
from string import joinfields, split, replace, find, strip, lower
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
              'take', 'select', 'apply', 'reject']

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
tlorentz_vector = re.compile('vector\s*[<]\s*TLorentzVector\s*[>]')

# some objects are singletons. try to guess which ones
# this is very simpleminded; will have to do better later
single   = re.compile('missing|met|event|scalar')
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
    
SINGLETON_CACHE = set()

# C++ TNM analyzer template
TEMPLATE_CC =\
'''//---------------------------------------------------------------------------
// File:        %(name)s.cc
// Description: Analyzer for LHADA analysis:
%(info)s
// Created:     %(time)s by lhada2tnm.py
//----------------------------------------------------------------------------
#include <algorithm>
#include "tnm.h"
#include "TEParticle.h"
#include "%(adaptername)s.h"
%(includes)s
using namespace std;
//----------------------------------------------------------------------------
// The following functions, objects, and variables are globally visible.
//----------------------------------------------------------------------------
%(fundef)s
//----------------------------------------------------------------------------
%(vardef)s
//----------------------------------------------------------------------------
%(objdef)s
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

%(vobjects)s
%(vcuts)s
  // -------------------------------------------------------------------------
  // Loop over events
  // -------------------------------------------------------------------------
  for(int entry=0; entry < nevents; entry++)
    {
      // read an event into event buffer
      ev.read(entry);

      if ( entry %(percent)s 10000 == 0 ) cout << entry << endl;

%(extobjimpl)s
      // create filtered objects
      for(size_t c=0; c < objects.size(); c++) objects[c]->create();

%(varimpl)s
      // apply event level selections
      for(size_t c=0; c < cuts.size(); c++)
        { 
          cuts[c]->reset();
          cuts[c]->apply();
        }
    }

  // count summary
  std::cout << "event counts" << std::endl;
  for(size_t c=0; c < cuts.size(); c++)
    {
      cuts[c]->summary();
      cuts[c]->write(of);
    }   

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

        t[0] = None
    names = set(names)
    
    # 2) sort remaining blocks so that dependent blocks occur after the
    #    the blocks on which they depend
    for ii in xrange(len(objects)):
        for t in objects:
            name  = t[0]
            if name == None: continue
            words = t[1]                
            
            incomplete = len(words.intersection(names)) < len(words) 
            if incomplete: continue

            # the dependency of this block has been fully satisfied
            obs.append(deepcopy(t))
            names.add(name)
            t[0] = None
    return obs    
#--------------------------------------------------------------------------------
# Read LHADA file and extract blocks into a simple internal data structure
#--------------------------------------------------------------------------------
def extractBlocks(filename):
    if DEBUG > 0:
        print '\nBEGIN( extractBlocks )'
        
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

    #--------------------------------------------    
    # set up some simple regular expressions
    #--------------------------------------------    
    stripcomments = re.compile('[#].*')
    blocktypes = r'\b(%s)\b' % joinfields(BLOCKTYPES, '|')
    isblock    = re.compile(blocktypes)
    fcallname  = re.compile('[a-zA-Z_][\w_]*\s*(?=[(])')
    
    #--------------------------------------------    
    # loop over lhada records
    #--------------------------------------------    
    blocks = {}
    bname  = None
    funnames    = [] # keep track pf declared function names
    varnames    = [] # keep track of declared variables
    objectnames = [] # keep track of block names
    cutnames    = [] # keep track of cut names

    fullrecord = []
    for ii, record in enumerate(records):
        iline = ii+1
        # strip away comments from current record
        record = stripcomments.sub('', record)
        if strip(record) == '': continue

        # look for a block
        if isblock.findall(record) != []:

            # found a block; get its type and name
            t = split(record)
            if len(t) != 2:
                boohoo('problem at line\n%4d %s\n' % (iline, record))
            # block type, block name
            btype, bname = t

            # modify internal function and variable names in an
            # attempt to avoid name collisions
            if btype == 'function':
                bname = '_%s' % bname
            elif btype == 'variable':
                bname = '%s_' % bname

            # fall on sword if we have duplicate block names
            if blocks.has_key(bname):
                boohoo('duplicate block name %s at line'\
                           '\n%4d %s\n' % (bname, iline, record))
                            
            blocks[bname] = {'type': btype, 'body': []}
            if btype == 'object':
                objectnames.append(bname)
            elif btype == 'cut':
                cutnames.append(bname)
            elif btype == 'function':
                funnames.append(bname)
            elif btype == 'variable':
                varnames.append(bname)
            continue
        
        if bname == None:
            boohoo('problem at line\n%4d %s\n' % (iline, record))

        # lookahead to find end of statement
        fullrecord.append(strip(record))
        if ii < len(records)-1:
            t = split(records[ii+1])
            if len(t) == 0 or ((len(t) > 0) and (t[0] in KEYWORDS)):
                # next line is either blank or starts with a token, so current record
                # ends the statement
                blocks[bname]['body'].append(joinfields(fullrecord, ' '))
                fullrecord = []
        else:
            blocks[bname]['body'].append(joinfields(fullrecord, ' '))
            fullrecord = []
            
    # convert to sets for easier comparisons
    objectnames = set(objectnames)
    cutnames    = set(cutnames)
    varnames    = set(varnames)
    funnames    = set(funnames)
    
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
        # C = A and B. the remaining words will be used to sort
        # the blocks according to dependency
        if blocktype == 'object':
            words = objectnames.intersection(words)
        elif blocktype == 'cut':
            words = cutnames.intersection(words)
            
        blockmap[blocktype].append([key, deepcopy(words), deepcopy(body)])

    # for object and cut blocks modify names of internal variables
    # and functions in order to avoid name collisions
    for fname in funnames:
        # skip "_"
        edit = re.compile('\\b%s\\b\s*(?=[(])' % fname[1:])
        
        for btype in ['object', 'cut']:
            for jj, (bname, words, records) in enumerate(blockmap[btype]):
                for ii, record in enumerate(records):
                    records[ii] = edit.sub(fname, record)
                    if DEBUG > 1:
                        print "fun-change( %s ) -> ( %s )" \
                          % (strip(record), strip(records[ii]))
                blockmap[btype][jj][-1] = records
                
    for vname in varnames:
        # skip "_"
        edit = re.compile('\\b%s\\b(?!=[(])' % vname[:-1])
        
        for btype in ['object', 'cut']:
            for jj, (bname, words, records) in enumerate(blockmap[btype]):
                for ii, record in enumerate(records):
                    records[ii] = edit.sub(vname, record)
                    if DEBUG > 1:
                        print "var-change( %s ) -> ( %s )" \
                          % (strip(record), strip(records[ii]))
                blockmap[btype][jj][-1] = records
                
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
    if DEBUG > 0:
        print '\nBEGIN( process_function )'
        
    # extract headers to be included
    includeset = set()
    for name, words, records in blocks['function']:
        for record in records:
            t = split(record)
            token = t[0]
            if token != 'code': continue
            includeset.add(t[1])
            if DEBUG > 1:
                print "  FUNCTION( %s) CODE( %s )" % (name, t[1])
                
    includes = ''
    for record in includeset:
        includes += '#include "%s"\n' % record
    names['includes'] = includes

    # create functions
    fundef = '//\n// functions\n'
    functions = {}
    for name, words, records in blocks['function']:
        
        # NB: remove "_" from name, which was added in extractBlocks
        name = name[1:]

        # cache original name
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
        # prefix internal name with an "_"
        intname = '_%s' % replace(extname, '::', '_')

        if DEBUG > 0:
            print "  internal, external names( %s, %s )" % (intname, extname)
            
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
                
            # assume code declaratioin in within a header. find header
            code = strip(code)
            t = findHeaderFile(code, ['*'])
            if len(t) == 0:
                boohoo('unable to locate header: %s' % code)

            # header found, scan it to get details of functions
            include = t[0]
            if include == '':
                boohoo('problem getting header name: %s' % code)
                
            record = open(include).read()
            
            # find all function declarations in header
            t = getfunctions.findall(record)
            for x in t:
                
                # make a valiant attempt to decode function
                rtype, namen, argtypes, argnames = decodeFunction(x)
                
                if name == namen:
                    
                    # we have a match, so create internal function
                    if len(args) != len(argtypes):
                        boohoo('''argument count mismatch in function %s.
expected arguments %s, but %s found in LHADA file
''' % (origname, v, args))

                    # note: internal functions could have arguments
                    # such as vector<TEParticle> that map to
                    # vector<TLorentzVector>. unfortunately, even though
                    # TEParticle inherits from TLorentzVector, vector<TEParticle>
                    # is not type compatible with vector<TLorentzVector>. So,
                    # we need to copy each TEParticle to a TLorentzVector.
                    # however, a singleton TEParticle is type compatible with
                    # TLorentzVector and no copying is needed.
                    copyvars=''
                    argsrec = ''
                    argscall= ''
                    for ii, arg in enumerate(args):
                        argc = arg
                        # check for vector<TLorenzVector>
                        if tlorentz_vector.findall(argtypes[ii]) != []:
                            argc = arg + '_'
                            copyvars+='\n'
                            copyvars+='  vector<TLorentzVector> %s(%s.size());\n'\
                              % (argc, arg)
                            copyvars+='  copy(%s.begin(), %s.begin(), %s.begin());'\
                              % (arg, arg, argc)
                            argtypes[ii] = 'vector<TEParticle>&'
                            
                        argsrec += '%s %s, ' % (argtypes[ii], arg)
                        argscall+= '%s, ' % argc
                    if argsrec != '':
                        argsrec = argsrec[:-2]
                        argscall= argscall[:-2]
                    
                    fundef += '''inline\n%(rtype)s\t%(intname)s(%(args)s)
{%(copyvars)s
  return %(extname)s(%(argscall)s);
};

''' % {'rtype': rtype,
           'intname': intname,
           'extname': extname,
           'copyvars': copyvars,
           'args': argsrec,
           'argscall': argscall}
                    # cache function info
                    functions[origname] = (rtype, intname, extname, argtypes)
                    
                    if DEBUG > 0:
                        print '  function details( %s ); %s' % (origname,
                                                          functions[origname])
    names['fundef'] = fundef
    
    blocks['function_info'] = functions
#--------------------------------------------------------------------------------
# check whether to start an inner loop.
# we start an inner loop if the next record contains a variable
# of the form <objectname>.<variable> and objectname is not
# a singleton. for now we do not allow nested inner loops
def beginInnerLoop(records, index, blocktypes):
    if index >= len(records)-1: return None
        
    # get words from next record, including those of the form
    # <name>.<variable>
    index  += 1    
    record  = records[index]
    words   = set(getvars.findall(record))
    if DEBUG > 0:
        print "begin-LOOKAHEAD( %s )" % words

    # identify words of the form <name>.<variable> and check if the word
    # <name> appears in the list of non-singleton objects 
    objectnames = set(blocktypes['object'])
    for x in words:
        t = split(x, '.')
        if len(t) > 1:
            name = t[0]
            if name in objectnames:
                if name in SINGLETON_CACHE:
                    if DEBUG > 0:
                        print "\tfound singleton object( %s )" % name
                    return None
                else:
                    if DEBUG > 0:
                        print "\tloop over object( %s )" % name
                return name
    return None

# check if the next record fails to contain a variable from the list of
# variables within an inner loop. if the  record fails to contain such
# a variable it is assumed that the current inner loop should end.
def endInnerLoop(records, index, loopvar):
    if index >= len(records)-1: return True

    # get words from next record, including those of the form
    # <name>.<variable>        
    index += 1
    record = records[index]
    words  = set(getvars.findall(record))
    if DEBUG > 0:
        print "end-LOOKAHEAD( %s )" % words, loopvar
        
    t = words.intersection(loopvar)
    if len(t) == 0:
        if DEBUG > 0:
            print "\tend loop"
        return True
    else:
        return False
    
def convert2cpp(record, btype, blocktypes):
    # do some simple fixes
    record = replace(record, "|", "@")
    record = replace(record, "[", ";:")
    record = replace(record, "]", ":;")
    record = cppAND.sub('&&', record)
    record = cppOR.sub('||\n\t', record)

    # use a set to avoid recursive edits
    words  = set(getvars.findall(record))
    if DEBUG > 0:
        print "RECORD( %s )" % record
        print "\tWORDS( %s )" % words
        
    for name in words:
        # if this is an object block,
        # check if variable is of the form a.b
        # if it is, we make the replacement a.b -> a("b"). 
        # consider PT and e.PT
        # but we want
        #    PT    -> p("pt") if PT is not preceded by "e."
        #    e.PT  -> e("pt") if PT is preceded by "e."
        # if, however, this is a cut object, we make the following
        # changes: .size -> .size()
        #          a.b   -> a("b")
        
        t = split(name, '.')
        undotted = len(t) == 1
        oname = t[0]

        # check for singleton
        a_singleton = oname in SINGLETON_CACHE
        
        field = t[-1]
        newfield = field
        
        # need to handle things like PT and e.PT
        # also need to check for singleton objects
        if btype == 'object':
            if undotted:
                if not a_singleton: oname = "p"
                edit = re.compile('(?<![.])%s' % field)
            else:
                edit = re.compile('\\b%s\\b' % name)
            newfield = '%s("%s")' % (oname, lower(field))

            if DEBUG > 0:
                print "\tobject: oname( %s ) field( %s ) newfield( %s )" % \
                (oname, field, newfield)
                print "\t\told-record( %s )" % strip(record)
                
            record = edit.sub(newfield, record)
        
            if DEBUG > 0:
                print "\t\tnew-record( %s )" % strip(record)
            
        elif btype == 'apply':
            if undotted:
                if not a_singleton: oname = "p"
                edit = re.compile('(?<![.])%s' % field)
            else:
                if not a_singleton: oname = "q"
                edit = re.compile('\\b%s\\b' % name)
            newfield = '%s("%s")' % (oname, lower(field))
            
            if DEBUG > 0:
                print "\tapply: oname( %s ) field( %s ) newfield( %s )" % \
                (oname, field, newfield)
                print "\t\told-record( %s )" % strip(record)
                
            record = edit.sub(newfield, record)
        
            if DEBUG > 0:
                print "\t\tnew-record( %s )" % strip(record)
            
        elif btype == 'cut':
            if undotted:
                # check if this is the result of another section
                if name in blocktypes['cut']:
                    edit = re.compile('\\b%s\\b' % name)
                    newfield = 'cut_%s()' % name
                    if DEBUG > 0:
                        print "\tcut: oname( %s ) field( %s ) newfield( %s )" % \
                          (oname, field, newfield)
                          
                    record = edit.sub(newfield, record)
                    
                    if DEBUG > 0:
                        print "\t\told-record( %s )" % strip(record)
            else:
                edit = re.compile('\\b%s\\b' % name)
                if field == 'size':
                    newfield = '%s.%s()' % (oname, field)
                else:
                    newfield = '%s("%s")' % (oname, lower(field))
                    
                if DEBUG > 0:
                    print "\tapply: oname( %s ) field( %s ) newfield( %s )" % \
                    (oname, field, newfield)
                    print "\t\told-record( %s )" % strip(record)
                
                record = edit.sub(newfield, record)
        
                if DEBUG > 0:
                    print "\t\tnew-record( %s )" % strip(record)                    

    # final cleanup     
    record = replace(record, '@',  '|')
    record = replace(record, ';:', '[')
    record = replace(record, ':;', ']')

    if DEBUG > 0:
        print "\t\tcleaned-record( %s )" % record
        print '-'*80
    return record

def process_singleton_object(name, records, tab, blocktypes):
    if DEBUG > 0:
        print '\nBEGIN( process_singleton_object ) %s' % name
            
    objdef = ''
    for record in records:
        t = split(record)
        token = t[0]
        value = joinfields(t[1:], ' ')
        if   token == 'take':
            objdef += '%s%s = %s;\n' % (tab, name, value);
    return objdef

def process_multiple_objects(name, records, TAB, blocktypes):
    if DEBUG > 0:
        print '\nBEGIN( process_multiple_objects ) %s' % name
            
    tab     = TAB
    tab4    = ' '*4
    objdef  = '%s%s.clear();\n' % (tab, name)
    
    loopobj = None
    loopvar = set() # to cache loop variables
    
    # state booleans for handling inner loops
    active_inner_loop = False
    begin_inner_loop  = False
    
    if DEBUG > 0:
        print "\nNAME( %s )" % name
    
    for index in xrange(len(records)):
        record= records[index]
        t     = split(record)
        token = t[0]
        value = joinfields(t[1:], ' ')

        if DEBUG > 0:
            print "TOKEN( %s )\tvalue( %s )" % (token, value)

        objname = beginInnerLoop(records, index, blocktypes)
        if objname != None:
            begin_inner_loop  = True
            # cache name of object over which to loop in inner loop
            object_name = objname
            
            if DEBUG > 0:
                print '   BEGIN( INNER LOOP )'
                
        if   token == 'take':
            # --------------------------------------------            
            # TAKE
            # --------------------------------------------            
            objdef += '%sfor(size_t c=0; c < %s.size(); c++)\n' % (tab, value)
            objdef += '%s  {\n' % tab
            objdef += '%s%sTEParticle& p = %s[c];\n' % (tab, tab4, value)
            
        elif token == 'apply':
            # --------------------------------------------            
            # APPLY
            # --------------------------------------------
            
            if begin_inner_loop:
                begin_inner_loop  = False
                active_inner_loop = True
                loopvar = set()
                loopvar.add(object_name)
                
                # adjust tab
                tab = TAB + tab4
                
                objdef += '%sbool skip = false;\n' % tab
                objdef += '%sfor(size_t n=0; n < %s.size(); n++)\n' % \
                (tab, object_name)
                objdef += '%s  {\n' % tab
                objdef += '%s%sTEParticle& q = %s[n];\n' % (tab, tab4, object_name)

            # get function call and function name
            # check that function has been declared
            fcall  = joinfields(t[1:-1], ' ')
            if DEBUG > 0:
                print "\tfunction call( %s )" % fcall
                
            fname = strip(split(fcall, '(')[0])
            function_found = False
            for fnamen in blocktypes['function']:
                if fname == fnamen:
                    if DEBUG > 0:
                        print "\tfunction found( %s )" % fname
                    function_found = True
                    break
            if not function_found:
                boohoo('please use a function block to declare function %s' % fname)

            rvalue = t[-1]
            if fcall[-1] != ')':
                boohoo('''
%s
perhaps you're missing a return value in:
%s
''' % (objdef, record))

            a, b = split(fcall, '(')
            b = convert2cpp(b, 'apply', blocktypes)
            a = replace(a, '.', '_')
            fcall = '%s(%s' % (a, b)
            
            objdef += '%s%sdouble %s = %s;\n' % (tab, tab4, rvalue, fcall)
            objdef += '%s%sp("%s", %s);\n' % (tab, tab4, lower(rvalue), rvalue)
            
            # cache variables defined within loop
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
            if active_inner_loop:              
                objdef += '%s%sif ( %s )\n' % (tab, tab4,
                                                   convert2cpp(value,
                                                                   'object',
                                                                   blocktypes))
                objdef += '%s%s  {\n' % (tab, tab4)
                objdef += '%s%s    skip = true;\n' % (tab, tab4)
                objdef += '%s%s    break;\n' % (tab, tab4)
                objdef += '%s%s  }\n' % (tab, tab4)
            else:
                objdef += '%s%sif ( %s ) continue;\n' % (tab, tab4,
                                                    convert2cpp(value,
                                                                   'object',
                                                                   blocktypes))       
        if active_inner_loop:
            
            if endInnerLoop(records, index, loopvar):
            
                active_inner_loop = False
                begin_inner_loop = False
                tab = TAB
                
                if DEBUG > 0:
                    print '   END( INNER LOOP )'            
                # --------------------------------------
                # END INNER LOOP
                # --------------------------------------
                objdef += '%s%s  }\n' % (tab, tab4)
                objdef += '%s%sif ( skip ) continue;\n' % (tab, tab4)            
            
    objdef += '%s%s%s.push_back(p);\n' % (tab, tab4, name)
    objdef += '%s  }\n' % tab
    return objdef

def process_objects(names, blocks, blocktypes):
    if DEBUG > 0:
        print '\nBEGIN( process_objects )'
            
    from string import lower
    tab2 = ' '*2
    tab4 = ' '*4
    tab6 = ' '*6
    tab8 = ' '*8
    
    extobjdef = ''
    intobjdef = ''
    extobj = set()

    vobjects  = '%s// cache pointers to filtered objects\n' % tab2    
    vobjects += '%svector<lhadaThing*> objects;\n' % tab2

    for name, words, records in blocks['object']:
        if DEBUG > 0:
            print 'OBJECT( %s )' % name
            
        for record in records:
            t = split(record)
            token = t[0]
            if token == 'take':
                objname = t[1]
                if objname not in blocktypes['object']:
                    extobj.add(objname)
                    singleton = single.findall(lower(objname)) != []
                    if singleton:
                        extobjdef += '\nTEParticle %s;\n\n' % objname
                        SINGLETON_CACHE.add(name)
                        if DEBUG > 0:
                            print "\tsingleton object( %s )" % name
                    else:
                        extobjdef += 'vector<TEParticle> %s;\n' % objname
                            
        singleton = single.findall(lower(name)) != []
        if singleton:
            intobjdef += '\nTEParticle %s;\n\n' % name
        else:
            intobjdef += 'vector<TEParticle> %s;\n' % name

        vobjects += '%sobjects.push_back(&object_%s);\n' % (tab2, name)            
        
    objdef = '''// external objects
%s
// internal objects
%s
''' % (extobjdef, intobjdef)
    
    extobjimpl = '%s// get external objects\n' % tab6
    adapter = names['adapter']
    for name in extobj:
        extobjimpl += '%s%s(ev, "%s", \t%s);\n' % (tab6, adapter, name, name)
 
    # implement object selections
    objdef += '\n// object definitions\n'
    objdef += 'struct lhadaThing\n'
    objdef += '{\n'
    objdef += '  lhadaThing() {}\n'
    objdef += '  ~lhadaThing() {}\n'
    objdef += '  virtual void reset() {}\n'
    objdef += '  virtual void create() {}\n'
    objdef += '  virtual bool apply() { return true; }\n'
    objdef += '  virtual void write(outputFile& out) {}\n'
    objdef += '  virtual void summary() {}\n'
    objdef += '};\n\n'
    
    for name, words, records in blocks['object']:
        objdef += 'struct object_%s_s : public lhadaThing\n' % name
        objdef += '{\n'
        objdef += '%sobject_%s_s() : lhadaThing() {}\n' % (tab2, name)
        objdef += '%s~object_%s_s() {}\n' % (tab2, name) 
        objdef += '%svoid create()\n' % tab2
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
    names['vobjects']   = vobjects
#--------------------------------------------------------------------------------    
def process_variables(names, blocks):
    if DEBUG > 0:
        print '\nBEGIN( process_variables )'
            
    vardef  = '// variables\n'
    varimpl = '%s// compute event level variables\n' % SPACE6
    for name, words, records in blocks['variable']:
        if DEBUG > 0:
            print 'VARIABLE( %s )' % name
            
        for record in records:
            t = split(record)
            token = t[0]
            
            if token == 'apply':
                # found an apply token
                func  = joinfields(t[1:], ' ')
                fname = split(func, '(')[0]
                # strip away preceding _
                #if fname[0] == '_': fname = fname[1:]

                if not blocks['function_info'].has_key(fname):
                    boohoo('''
    variable %s uses the function %s, 
    but the latter may not have been defined in the LHADA file.
    ''' % (name, fname))
                rtype, intname, extname, argtypes = blocks['function_info'][fname]
                #func = replace(func, fname, intname)
                vardef  += '%s\t%s;\n' % (rtype, name)
                varimpl += '%s%s\t= %s;\n' % (SPACE6, name, func)
                
    names['vardef']  = vardef
    names['varimpl'] = varimpl
#--------------------------------------------------------------------------------    
def process_cuts(names, blocks, blocktypes):
    if DEBUG > 0:
        print '\nBEGIN( process_cuts )'
            
    cutdef  = '// selections\n'
    vcuts   = '  // cache pointers to cuts\n'
    vcuts  += '  vector<lhadaThing*> cuts;\n'
    for name, words, records in blocks['cut']:    
        vcuts += '  cuts.push_back(&cut_%s);\n' % name
    
    # implement selections
    tab2 = ' '*2
    tab4 = tab2*2
      
    for name, words, records in blocks['cut']:
        if DEBUG > 0:
            print 'CUT( %s )' % name
            
        cutdef += 'struct cut_%s_s : public lhadaThing\n' % name 
        cutdef += '{\n'
        cutdef += '  std::string name;\n'
        cutdef += '  double total;\n'
        cutdef += '  double dtotal;\n'
        cutdef += '  TH1F*  hcount;\n'
        cutdef += '  bool   done;\n'
        cutdef += '  bool   result;\n'
        cutdef += '  double weight;\n\n'
        cutdef += '  cut_%s_s()\n' % name
        cutdef += '''    : lhadaThing(),
      name("%s"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1)
''' % name
        cutdef += '''  {
    hcount = new TH1F(name.c_str(), "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);

    hcount->Fill("none", 0);
'''
        values = []
        for record in records:
            t = split(record)
            token = t[0]
            if token != 'select': continue
            value = joinfields(t[1:], ' ')
            values.append(value)
            cutdef += '    hcount->Fill("%s", 0);\n' % value        
        cutdef += '  }\n\n'
        cutdef += '  ~cut_%s_s() {}\n\n' % name
        cutdef += '  void summary()\n'
        cutdef += '  {\n'
        cutdef += '    printf("\\t%s-24s %s10.3f (%s10.3f)\\n",\n' % ('%', '%', '%')
        cutdef += '           name.c_str(), total, sqrt(dtotal));\n'
        cutdef += '  }\n'
        cutdef += '  void count(string c, double w=1)\t{ hcount->Fill(c.c_str(), w); }\n'
        cutdef += '  void write(outputFile& out)\t\t{ out.file_->cd(); hcount->Write(); }\n'
        cutdef += '  void reset()\t\t\t\t{ done = false; result = false; }\n'
        cutdef += '  bool operator()()\t{ return apply(); }\n\n'     
        cutdef += '  bool apply()\n'
        cutdef += '  {\n'
        cutdef +='''    if ( done ) return result;
    done   = true;
    result = false;
    count("none", weight);

'''       
        for value in values:
            # convert to C++
            cutdef += '%sif ( !(%s) ) return false;\n' % \
              (tab4, convert2cpp(value, 'cut', blocktypes))
            cutdef += '%scount("%s", weight);\n\n' % (tab4, value)
        cutdef += '%stotal  += weight;\n'  % tab4
        cutdef += '%sdtotal += weight * weight;\n'  % tab4
        cutdef += '%sresult  = true;\n' % tab4
        cutdef += '%sreturn true;\n' % tab4
        cutdef += '  }\n'            
        cutdef += '} cut_%s;\n\n' % name

    names['cutdef'] = cutdef
    names['vcuts']  = vcuts
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
    names['percent']  = '%'
    blocks = extractBlocks(filename)

    blocktypes = {}
    for btype in BLOCKTYPES:
        blocktypes[btype] = set()
        if not blocks.has_key(btype): continue
        for name, words, records in blocks[btype]:
            blocktypes[btype].add(name)

    if DEBUG > 0:
        printBlocks(blocks)
    
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
    
