#ifndef analyzer_s_HH
#define analyzer_s_HH
//------------------------------------------------------------------
// File:        analyzer_s.h
// Description: Analyzer for ADL-based analysis:
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
// Created:     Sat Mar 23 17:39:26 2019 by lhada2tnm.py v1.0.3
//------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include "TFile.h"
#include "TH1F.h"
#include "TEParticle.h"
//------------------------------------------------------------------
struct lhadaThing
{
  lhadaThing() {}
  virtual ~lhadaThing() {}
  virtual void reset() {}
  virtual void create() {}
  virtual bool apply() { return true; }
  virtual void write(TFile* fout) {}
  virtual void summary(std::ostream& os) {}
};
    
struct analyzer_s
{
  std::vector<lhadaThing*> objects;
  std::vector<lhadaThing*> cuts;

  analyzer_s();
  ~analyzer_s();
  void run(std::vector<TEParticle>& Delphes_Jet_,
           std::vector<TEParticle>& Delphes_Electron_,
           TEParticle& Delphes_MissingET_,
           std::vector<TEParticle>& Delphes_Muon_);
  void summary(TFile* fout, std::ostream& os);
};
#endif
