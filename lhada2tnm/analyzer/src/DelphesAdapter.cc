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


void DelphesAdapter::operator()(eventBuffer& ev, std::string name, std::vector<TEParticle>& p)
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
	  p.back().Value["Charge"] = ev.Muon_Charge[c];
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
	  p.back().Value["Charge"] = ev.Electron_Charge[c];	  
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
	  p.back().Value["BTag"] = ev.Jet_BTag[c];
	  p.back().Value["Beta"] = ev.Jet_Beta[c];
	  p.back().Value["Charge"] = ev.Jet_Charge[c];
	  p.back().Value["BetaStar"] = ev.Jet_BetaStar[c];
	  p.back().Value["DeltaEta"] = ev.Jet_DeltaEta[c];
	  p.back().Value["DeltaPhi"] = ev.Jet_DeltaPhi[c];
	  p.back().Value["EhadOverEem"] = ev.Jet_EhadOverEem[c];
	  p.back().Value["MeanSqDeltaR"] = ev.Jet_MeanSqDeltaR[c];
	  p.back().Value["NCharged"] = ev.Jet_NCharged[c];
	  p.back().Value["NNeutrals"] = ev.Jet_NNeutrals[c];
	  p.back().Value["Tau1"] = ev.Jet_Tau1[c];
	  p.back().Value["Tau2"] = ev.Jet_Tau2[c];
	  p.back().Value["Tau3"] = ev.Jet_Tau3[c];
	  p.back().Value["Tau4"] = ev.Jet_Tau4[c];
	  p.back().Value["Tau5"] = ev.Jet_Tau5[c];
	  p.back().Value["TauTag"] = ev.Jet_TauTag[c];
	}      
    }
}
void DelphesAdapter::operator()(eventBuffer& ev, std::string name, TEParticle& p)
{
  TString key(name.c_str());
  key.ToLower();  
  if ( key.Contains("met") )
    {
      TEParticle q(81, ev.MissingET_MET, ev.MissingET_Eta, ev.MissingET_Phi, 0);
      p = q;
    }
}
