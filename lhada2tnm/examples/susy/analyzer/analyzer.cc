//---------------------------------------------------------------------
// File:        analyzer.cc
// Description: Analyzer for LHADA analysis:
//
// LHADA file: ../../../doc/ATLASSUSY1605.03814_lhproc.lhada
// info block
//	experiment  	ATLAS
//	id          	SUSY-2013-15
//	publication 	Eur. Phys. J. C(2016) 76: 392
//	sqrtS       	13.0
//	lumi        	3.2
//	arXiv       	1605.03814
//	hepdata     	http://hepdata.cedar.ac.uk/view/ins1304456
//	doi         	10.1140/epjc/s10052-016-4184-8
//
// Created:     Fri May 18 15:33:25 2018 by lhada2tnm.py
//---------------------------------------------------------------------
#include "tnm.h"
#include "DelphesAdapter.h"
#include "analyzer_s.h"

using namespace std;
//---------------------------------------------------------------------
int main(int argc, char** argv)
{
  // If you want canvases to be visible during program execution, just
  // uncomment the line below
  //TApplication app("analyzer", &argc, argv);

  // Get command line arguments
  commandLine cl(argc, argv);
    
  // Get names of ntuple files to be processed
  vector<string> filenames = fileNames(cl.filelist);

  // Create tree reader
  itreestream stream(filenames, "Delphes");
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

  //---------------------------------------------------------------------
  // Define histograms
  //---------------------------------------------------------------------
  //setStyle();

  //---------------------------------------------------------------------
  // Create an event adapter to map input types to a standard internal 
  // type and create the analyzer
  //---------------------------------------------------------------------
  DelphesAdapter adapter;

  analyzer_s analyzer;

  //---------------------------------------------------------------------
  // Loop over events
  //---------------------------------------------------------------------
  for(int entry=0; entry < nevents; entry++)
    {
      // read an event into event buffer
      ev.read(entry);

      if ( entry % 10000 == 0 ) cout << entry << endl;


      // map external objects to internal ones
      std::vector<TEParticle> Delphes_Jet;
      adapter(ev, "Delphes_Jet", 	Delphes_Jet);
      std::vector<TEParticle> Delphes_Electron;
      adapter(ev, "Delphes_Electron", 	Delphes_Electron);
      TEParticle Delphes_MissingET;
      adapter(ev, "Delphes_MissingET", 	Delphes_MissingET);
      std::vector<TEParticle> Delphes_Muon;
      adapter(ev, "Delphes_Muon", 	Delphes_Muon);

      analyzer.run(Delphes_Jet,
                   Delphes_Electron,
                   Delphes_MissingET,
                   Delphes_Muon);

    }

  // summarize analysis
  analyzer.summary(of.file_, cout);

  ev.close();
  of.close();
  return 0;
}
