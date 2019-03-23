// ---------------------------------------------------------------------------
// File: DelphesAdapter.cc
// Description: map Delphes objects to TEParticles
// created: 02-Feb-2018 Harrison B. Prosper
// ---------------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include "TString.h"
#include "DelphesAdapter.h"

using namespace std;

DelphesAdapter::DelphesAdapter()
{
}

DelphesAdapter::~DelphesAdapter()
{
}


void DelphesAdapter::operator()(eventBuffer& ev, std::string name,
				std::vector<TEParticle>& p)
{
  TString key(name.c_str());
  key.ToLower();
  p.clear();
  
  if      ( key.Contains("muon") )
    {
      for (size_t c=0; c < ev.Muon_PT.size(); c++)
	{
	  p.push_back(TEParticle(-13*ev.Muon_Charge[c],
				 ev.Muon_PT[c],
				 ev.Muon_Eta[c],
				 ev.Muon_Phi[c],
				 0));
	  p.back().Value["charge"] = ev.Muon_Charge[c];
	  p.back().Value["isolationvar"] = ev.Muon_IsolationVar[c];
	  p.back().Value["isolationvarrhocorr"] = ev.Muon_IsolationVarRhoCorr[c];
	}
    }
  else if ( key.Contains("electron") )
    {
      for (size_t c=0; c < ev.Electron_PT.size(); c++)
	{
	  p.push_back(TEParticle(-11*ev.Electron_Charge[c],
				 ev.Electron_PT[c],
				 ev.Electron_Eta[c],
				 ev.Electron_Phi[c],
				 0));
	  p.back().Value["charge"] = ev.Electron_Charge[c];
	  p.back().Value["isolationvar"] = ev.Electron_IsolationVar[c];	  
	  p.back().Value["isolationvarrhocorr"] = ev.Electron_IsolationVarRhoCorr[c];	  
	}      
    }
  else if ( key.Contains("photon") )
    {
      for (size_t c=0; c < ev.Photon_PT.size(); c++)
	{
	  p.push_back(TEParticle(22,
				 ev.Photon_PT[c],
				 ev.Photon_Eta[c],
				 ev.Photon_Phi[c],
				 0));
	  p.back().Value["charge"] = 0;
	  p.back().Value["isolationvar"] = ev.Photon_IsolationVar[c];	  
	  p.back().Value["isolationvarrhocorr"] = ev.Photon_IsolationVarRhoCorr[c];	  
	}      
    }  
  else if ( key.Contains("jet") )
    {
      for (size_t c=0; c < ev.Jet_PT.size(); c++)
	{
	  p.push_back(TEParticle(81,
				 ev.Jet_PT[c],
				 ev.Jet_Eta[c],
				 ev.Jet_Phi[c],
				 ev.Jet_Mass[c]));
	  p.back().Value["btag"] = ev.Jet_BTag[c];
	  p.back().Value["beta"] = ev.Jet_Beta[c];
	  p.back().Value["charge"] = ev.Jet_Charge[c];
	  p.back().Value["betastar"] = ev.Jet_BetaStar[c];
	  p.back().Value["deltaeta"] = ev.Jet_DeltaEta[c];
	  p.back().Value["deltaphi"] = ev.Jet_DeltaPhi[c];
	  p.back().Value["ehadovereem"] = ev.Jet_EhadOverEem[c];
	  p.back().Value["meansqdeltar"] = ev.Jet_MeanSqDeltaR[c];
	  p.back().Value["vvharged"] = ev.Jet_NCharged[c];
	  p.back().Value["nneutrals"] = ev.Jet_NNeutrals[c];

	  // p.back().Value["tau1"] = ev.Jet_Tau1[c];
	  // p.back().Value["tau2"] = ev.Jet_Tau2[c];
	  // p.back().Value["tau3"] = ev.Jet_Tau3[c];
	  // p.back().Value["tau4"] = ev.Jet_Tau4[c];
	  // p.back().Value["tau5"] = ev.Jet_Tau5[c];
	  // p.back().Value["tautag"] = ev.Jet_TauTag[c];
	}      
    }
  else
    {
      cout << "** DelphesAdapter ** unknown type: " << key << endl;
      exit(0);
    }
}

void DelphesAdapter::operator()(eventBuffer& ev, std::string name, TEParticle& p)
{
  TString key(name.c_str());
  key.ToLower();
  if ( key.Contains("met") || key.Contains("missinget") )
    {
      TEParticle q(81, ev.MissingET_MET, ev.MissingET_Eta, ev.MissingET_Phi, 0);
      q.Value["phi"] = q.Phi();
      q.Value["pt"]  = q.Pt();
      q.Value["met"] = q.Pt();
      p = q;
    }

#ifdef WITH_SCALARHT
  if ( key.Contains("scalarht") || key.Contains("ht") )
    {
      TEParticle q(82, ev.ScalarHT_HT, 0, 0, 0);
      q.Value["ht"]  = ev.ScalarHT_HT;
      q.Value["pt"]  = ev.ScalarHT_HT;
      p = q;
    }
#endif
}
