# lhada2tnm

## Introduction

This program converts analysis descriptions given in the Analysis
Description Language (ADL) defined at the 2015 Les Houches Workshop
(with subsequent refinements) to a C++ program that runs within
__TheNtupleMaker__ (TNM) ROOT n-tuple analysis framework developed by Sezen Sekmen and Harrison Prosper. This program is a proof of principle of the ADL concept The __lhada2tnm__
package is structured as follows,

| __Directory__  | __Description__                   |
| --------|-------------------|
| bin           |  location of __lhada2tnm.py__                                  |
| doc          |  location of ADL files |
| examples/monophoton |  analyzer for an ATLAS mono-photon analysis |
|examples/susy| analyzer for an ATLAS SUSY analysis|
| external   | external code is copied here |

This package depends on the github package __treestream__, which we recommend
you clone (download) to a standard area on your machine (for
example, a directory called  __$HOME/external__) for external
packages (such as treestream) using the command
```bash
	cd
	cd external
	git clone https://github.com/hbprosper/treestream
```
The package treestream provides a simple convenient interface
to flat __ROOT__ trees comprising branches of single variables of the
standard types
__float__,  __int__, __double__, etc., and variable length arrays and STL
vectors of the same. Anything more complicated than
these types are unceremoniously dumped onto the floor!

## Setup

The file __setup.sh__ in lhada2tnm should be executed once per terminal window
session to define the environment variable __LHADA2TNM\_PATH__, which
points to lhada2tnm and
adds $LHADA2TNM_PATH/bin to your __PATH__. Also make sure that you have
access to treestream by executing the commands
```bash
  source $HOME/external/treestream/setup.sh
```
again, once per terminal session. The above command also sets  the environment variable
__EXTERNAL__ to $HOME/external. To build treestream do
```bash
  cd $HOME/external/treestream
  make
```
We've assumed you have cloned
treestream to $HOME/external as suggested.

## Example
In this example, we shall try to run the __ATLAS mono-photon analysis__,
described in the ADL file 

__doc/ATLASEXOT1704.0384\_Delphes.adl__ 

on a __CMS nano-AOD__ file, which we assume is called 

__ttjets\_NANOAOD.root__

and which resides in the directory __examples__.
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
This should create a directory called __cmsnano__. Go to that
directory and list its contennts with __ls__. You should see a standard TNM release area:
```bash
Makefile     cmsnano.cc include    python     src
README     cmsnano.py lib           setup.sh   tmp
```
The programs __mkvariables.py__ and __mkanalyzer.py__ are found in __treestream__.

We are now going to overwrite __cmsnano.cc__ with a version that runs
the ATLAS mono-photon analysis on the CMS nano-AOD file. Of course, we don't expect useful
results, but this, after all, is just an exercise! To that end, run the command
```bash
	lhada2tnm.py -a cmsnano -e CMSNanoAODAdapter -t Events ../../../doc/ATLASEXOT1704.0384_Delphes.lhada
```
which instructs __lhada2tnm.py__ to create a main program called
__cmsnano.cc__, which calls the code in __src/cmsnano_s.cc__. The main program uses
an __event adapter__ called __CMSNanoAODAdapter__ to map the input data
types, which in this example are CMS nano-AOD types, to __Delphes__
types, which are the types used in the specified ADL file. With hindsight, perhaps a better name for this event adapter would have been
__CMSnanoAOD2Delphes__. Oh well! The __-t__ switch specifies which tree within
ttjets\_NANOAOD.root is to be used. The last item in the command is the name of the file containing the ATLAS
mono-photon analysis described using the ADL.

The __lhada2tnm.py__ command creates
* cmsnano.cc
* include/cmsnano\_s.h
* src/cmsnano\_s.cc

updates

* Makefile
* include/linkdef

and copies some files to the __include__ and __src__ directories. The real workhorse is the
C++ program __src/cmsnano_s.cc__, which is written to be human readable,
well at any rate readable by that perculiar variety of human called a
particle physicist. Now build the analyzer program __cmsnano__ using
```bash
	make
```
List, in the file __filelist.txt__, the names of the files to be read by cmsnano,
e.g., as follows,
```bash
	ls -1 ../../ttjets_NANOAOD.root > filelist.txt
```
then do
```bash
	./cmsnano | tee summary.dat
```
to run the analysis program.
You will see several "no dictionary" warnings about complicated types that
__treestream__ dutifully ignores! More importantly, you should see a file called
__summary.dat__ when the program completes containing cut-flow summaries of the ATLAS mono-photon analysis run on a CMS nano-AOD!

