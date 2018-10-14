// ---------------------------------------------------------------------------
// File: CMSNanoAODAdapter.cc
// Description: map CMSNanoAOD objects to TEParticles
// created: 25-Sep-2018 Harrison B. Prosper
// ---------------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include "TString.h"
#include "CMSNanoAODAdapter.h"

using namespace std;

CMSNanoAODAdapter::CMSNanoAODAdapter()
{
}

CMSNanoAODAdapter::~CMSNanoAODAdapter()
{
}

void CMSNanoAODAdapter::operator()(eventBuffer& ev, std::string name,
				   std::vector<TEParticle>& p)
{
  TString key(name.c_str());
  key.ToLower();
  p.clear();
  
  if      ( key.Contains("muon") )
    {
      for (size_t c=0; c < ev.Muon_pt.size(); c++)
	{
	  p.push_back(TEParticle(-13*ev.Muon_charge[c],
				 ev.Muon_pt[c],
				 ev.Muon_eta[c],
				 ev.Muon_phi[c],
				 ev.Muon_mass[c]));
	  p.back().Value["Charge"] = ev.Muon_charge[c];
	  p.back().Value["charge"] = ev.Muon_charge[c];

	}
    }
  else if ( key.Contains("electron") )
    {
      for (size_t c=0; c < ev.Electron_pt.size(); c++)
	{
	  p.push_back(TEParticle(-11*ev.Electron_charge[c],
				 ev.Electron_pt[c],
				 ev.Electron_eta[c],
				 ev.Electron_phi[c],
				 ev.Electron_mass[c]));
	  p.back().Value["Charge"] = ev.Electron_charge[c];
	  p.back().Value["charge"] = ev.Electron_charge[c];	  
 
	}      
    }
  else if ( key.Contains("photon") )
    {
      for (size_t c=0; c < ev.Photon_pt.size(); c++)
	{
	  p.push_back(TEParticle(22,
				 ev.Photon_pt[c],
				 ev.Photon_eta[c],
				 ev.Photon_phi[c],
				 0));
	}      
    }  
  else if ( key.Contains("jet") )
    {
      for (size_t c=0; c < ev.Jet_pt.size(); c++)
	{
	  p.push_back(TEParticle(81,
				 ev.Jet_pt[c],
				 ev.Jet_eta[c],
				 ev.Jet_phi[c],
				 ev.Jet_mass[c]));

	  p.back().Value["area"]      = ev.Jet_area[c];
	  p.back().Value["bReg"]      = ev.Jet_bReg[c];
	  p.back().Value["btagCMVA"]  = ev.Jet_btagCMVA[c];
	  p.back().Value["btagCSVV2"] = ev.Jet_btagCSVV2[c];
	  p.back().Value["btagDeepB"] = ev.Jet_btagDeepB[c];
	  p.back().Value["btagDeepC"] = ev.Jet_btagDeepC[c];
	  p.back().Value["btagDeepFlavB"] = ev.Jet_btagDeepFlavB[c];
	  p.back().Value["chEmEF"]    = ev.Jet_chEmEF[c];
	  p.back().Value["chHEF"]     = ev.Jet_chHEF[c];
	}      
    }
  else
    {
      cout << "** CMSNanoAODAdapter ** unknown type: " << key << endl;
      exit(0);
    }
}

void CMSNanoAODAdapter::operator()(eventBuffer& ev, std::string name, TEParticle& p)
{
  TString key(name.c_str());
  key.ToLower();  
  if ( key.Contains("met") || key.Contains("missinget") )
    {
      TEParticle q(81, ev.MET_pt, 0, ev.MET_phi, 0);
      q.Value["met"] = q.Pt();
      q.Value["sumEt"] = ev.MET_sumEt;
      q.Value["significance"] = ev.MET_significance;
      p = q;
    }
  else if ( key.Contains("scalarht") || key.Contains("ht") )
    {
      // There is no Delphes-like scalerHT variable in the CMS nano-AOD. 
      // Ideally, we should use the precise definition of this variable, which is
      // more easily enforced using an external function. For now, we do
      // something very rough.
      float HT = 0.0;
      {
	vector<float>& pt = ev.Jet_pt; // make alias, not a copy
	for (size_t c=0; c < pt.size(); c++)
	  {
	    if ( ! (pt[c] > 10) ) continue;
	    HT += pt[c];
	  }
      }

      {
	vector<float>& pt = ev.Photon_pt;   // make alias, not a copy
	for (size_t c=0; c < pt.size(); c++)
	  {
	    if ( ! (pt[c] > 10) ) continue;
	    HT += pt[c];
	  }
      }

      {
	vector<float>& pt = ev.Electron_pt; // make alias, not a copy
	for (size_t c=0; c < pt.size(); c++)
	  {
	    if ( ! (pt[c] > 10) ) continue;
	    HT += pt[c];
	  }
      }

      {
	vector<float>& pt = ev.Muon_pt;    // make alias, not a copy
	for (size_t c=0; c < pt.size(); c++)
	  {
	    if ( ! (pt[c] > 10) ) continue;
	    HT += pt[c];
	  }
      }
      
      TEParticle q(82, HT, 0, 0, 0);
      q.Value["ht"]  = HT;
      q.Value["HT"]  = HT;
      p = q;
    }  
}
