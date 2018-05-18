#ifndef analyzer_s_HH
#define analyzer_s_HH
//---------------------------------------------------------------------
// File:        analyzer_s.h
// Description: Analyzer for LHADA analysis:
//
// LHADA file: ../../../doc/ATLASEXOT1704.0384_Delphes.lhada
// info block
//	experiment  	ATLAS
//	id          	EXOT-2016-32
//	publication 	Eur.Phys.J. C77 (2017) no.6, 393
//	sqrtS       	13.0
//	lumi        	36.1
//	arXiv       	1704.03848
//	hepdata     	https://www.hepdata.net/record/ins1591328
//	doi         	10.1140/epjc/s10052-017-4965-8
//
// Created:     Fri May 18 15:57:11 2018 by lhada2tnm.py
//---------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include "TFile.h"
#include "TH1F.h"
#include "TEParticle.h"
//---------------------------------------------------------------------
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
  void run(std::vector<TEParticle>& Delphes_Muon_,
           TEParticle& Delphes_MissingET_,
           std::vector<TEParticle>& Delphes_Electron_,
           std::vector<TEParticle>& Delphes_Jet_,
           TEParticle& Delphes_scalarHT_,
           std::vector<TEParticle>& Delphes_Photon_);
  void summary(TFile* fout, std::ostream& os);
};
#endif
