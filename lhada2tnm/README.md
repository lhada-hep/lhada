# lhada2tnm

## Introduction

This program converts analysis descriptions given in the Analysis
Description Language (ADL) defined at the 2015 Les Houches Workshop
(with subsequent refinements) to a C++ program that runs within
__TheNtupleMaker__ (TNM) ROOT n-tuple analysis framework. The __lhada2tnm__
package is structured as follows,

| __Directory__  | __Description__                   |
| --------|-------------------|
| bin           |  location of __lhada2tnm.py__                                  |
| doc          |  location of ADL files |
| examples/monophoton |  analyzer for an ATLAS mono-photon analysis |
|examples/susy| analyzer for an ATLAS SUSY analysis|
| external   | external code is copied here |

This package depends on the github package __treestream__, which we recommend
you clone (download) to well-defined area on your machine (for
example, a directory called  __$HOME/external__) for external
packages such as __treestream__ using the command
```bash
	cd
	cd external
	git clone https://github.com/hbprosper/treestream
```
The package __treestream__ provides a simple convenient 	interface
to flat ROOT trees comprising single variables (branches) of the
standard types
__float__,  __int__, __double__, etc., and variable length arrays and STL
vectors of the same. Anything more complicated than
these types are unceremoniously dumped on the floor!

## Setup

The file __setup.sh__ should be executed once per terminal window
session to define the environment variable __LHAD2TNMP\_PATH__, which
points to the top level directory of __lhada2tnm__ and
adds $LHADA2PATH/bin to your PATH. Also make sure that you have
access to __treestream__ by executing the command
```bash
  source $HOME/external/setup.sh
```
again, once per terminal session. We've assumed you have cloned
__treestream__ to \$HOME/external as suggested.

## Example
In this example, we shall try to run the ATLAS mono-photon analysis,
described in the ADL file 

__doc/ATLASEXOT1704.0384\_Delphes.lhada__ 

on a CMS nano-AOD file, which we assume is called 

__ttjets\_NANOAOD.root__

and resides in the directory __examples__.
Go to the directory __examples/monophoton__  and execute the following
command
```bash
	mkvariables.py ../ttjets_NANOAOD.root
```
This should produce a file called __variables.txt__ listing all of the
variables in the first tree found in the ROOT file. For CMS nano-AODs,
this tree is called __Events__. Now execute the command
```bash
	mkanalyzer.py cmsnano
```
This should create a directory called __cmsnano__. Change to that
directory and do an __ls__. You should see a standard TNM release area:
```bash
Makefile     cmsnano.cc include    python     src
README     cmsnano.py lib           setup.sh   tmp
```
The programs __mkvariables.py__ and __mkanalyzer.py__ are found in __treestream__.

We are now going to overwrite __cmsnano.cc__ with a version that runs
the ATLAS mono-photon analysis on the CMS nano-AOD file
__ttjets\_NANOAOD.root__. Of course, we don't expect useful
results. This is just an exercise! To that end, run the command
```bash
	lhada2tnm.py -a cmsnano -e CMSNanoAODAdapter -t Events ../../../doc/ATLASEXOT1704.0384_Delphes.lhada
```
This command instructs __lhada2tnm.py__ to create a main program called
__cmsnano.cc__, which calls the code in __src/cmsnano_s.cc__, and to use
an __event adapter__ called __CMSNanoAODAdapter__ to map the input data
types, which are CMS nano-AOD types, to (in this example) __Delphes__
types.	Perhaps a better name for this event adapter would have been
__CMSnanoAOD2Delphes__. The __-t__ switch specifies which tree within
__ttjets\_NANOAOD.root__ is to be used and the file contains the ATLAS
mono-photon analysis described using the ADL.

The __lhada2tnm.py__ command creates
* cmsnano.cc
* include/cmsnano\_s.h
* src/cmsnano\_s.cc
updates
* Makefile
* include/linkdef

and copies some files to *include* and *src*. The real workhorse is the
C++ program __src/cmsnano_s.cc__, which is written to be human readable,
well at any rate readable by that perculiar variety of human called a
particle physicist. Now build the program using
```bash
	make
```
and run it by first specifying in the file __filelist.txt__ which file (or files) are to be read,
e.g., as follows,
```bash
	ls -1 ../../ttjets_NANOAOD.root > filelist.txt
```
then doing
```bash
	./cmsnano | tee summary.txt
```
You will see "no dictionary" warnings about complicated types that
__treestream__ ignores! More importantly, you should see a file called
__summary.txt__ containing cut-flow summaries of the analysis.

