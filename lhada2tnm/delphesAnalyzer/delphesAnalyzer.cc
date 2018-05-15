//---------------------------------------------------------------------------
// File:        delphesAnalyzer.cc
// Description: Analyzer for LHADA analysis:
//
// LHADA file: ../doc/ATLASEXOT1704.0384_Delphes.lhada
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
// Created:     Tue May 15 03:16:45 2018 by lhada2tnm.py
//----------------------------------------------------------------------------
#include <algorithm>
#include "tnm.h"
#include "TEParticle.h"
#include "DelphesAdapter.h"
#include "ATLASSUSY1605.03814_functions.h"
#include "ATLASEXOT1704.0384_functions.h"

using namespace std;
//----------------------------------------------------------------------------
// The following functions, objects, and variables are globally visible.
//----------------------------------------------------------------------------
//
// functions
inline
double	_Meff(vector<TEParticle>& jets, TLorentzVector& MET)
{
  vector<TLorentzVector> jets_(jets.size());
  copy(jets.begin(), jets.begin(), jets_.begin());
  return Meff(jets_, MET);
};

inline
double	_dR(double Eta1, double Phi1, double Eta2, double Phi2)
{
  return dR(Eta1, Phi1, Eta2, Phi2);
};

inline
double	_METoverSqrtSumET(TLorentzVector& MET, double scalarHT)
{
  return METoverSqrtSumET(MET, scalarHT);
};

inline
double	_dPhi(double Phi1, double Phi2)
{
  return dPhi(Phi1, Phi2);
};


//----------------------------------------------------------------------------
// variables
double	METoverSqrtSumET_;

//----------------------------------------------------------------------------
// external objects

TEParticle Delphes_scalarHT;

vector<TEParticle> Delphes_Photon;
vector<TEParticle> Delphes_Muon;
vector<TEParticle> Delphes_Jet;

TEParticle Delphes_MissingET;

vector<TEParticle> Delphes_Electron;

// internal objects

TEParticle scalarHT;

vector<TEParticle> photons;
vector<TEParticle> muons;
vector<TEParticle> jets;

TEParticle MET;

vector<TEParticle> electrons;
vector<TEParticle> tightphotons;
vector<TEParticle> cleanjets;
vector<TEParticle> cleanelectrons;
vector<TEParticle> jetsSR;
vector<TEParticle> cleanmuons;


// object definitions
struct lhadaThing
{
  lhadaThing() {}
  ~lhadaThing() {}
  virtual void reset() {}
  virtual void create() {}
  virtual bool apply() { return true; }
  virtual void write(outputFile& out) {}
  virtual void summary() {}
};

struct object_scalarHT_s : public lhadaThing
{
  object_scalarHT_s() : lhadaThing() {}
  ~object_scalarHT_s() {}
  void create()
  {
    scalarHT = Delphes_scalarHT;
  };
} object_scalarHT;

struct object_photons_s : public lhadaThing
{
  object_photons_s() : lhadaThing() {}
  ~object_photons_s() {}
  void create()
  {
    photons.clear();
    for(size_t c=0; c < Delphes_Photon.size(); c++)
      {
        TEParticle& p = Delphes_Photon[c];
        if ( !(p("pt") > 10) ) continue;
        if ( !(p("|eta|") < 2.37) ) continue;
        photons.push_back(p);
      }
  };
} object_photons;

struct object_muons_s : public lhadaThing
{
  object_muons_s() : lhadaThing() {}
  ~object_muons_s() {}
  void create()
  {
    muons.clear();
    for(size_t c=0; c < Delphes_Muon.size(); c++)
      {
        TEParticle& p = Delphes_Muon[c];
        if ( !(p("pt") > 6) ) continue;
        if ( !(p("|eta|") < 2.7) ) continue;
        muons.push_back(p);
      }
  };
} object_muons;

struct object_jets_s : public lhadaThing
{
  object_jets_s() : lhadaThing() {}
  ~object_jets_s() {}
  void create()
  {
    jets.clear();
    for(size_t c=0; c < Delphes_Jet.size(); c++)
      {
        TEParticle& p = Delphes_Jet[c];
        if ( !(p("pt") > 20) ) continue;
        if ( !(p("|eta|") < 4.5) ) continue;
        jets.push_back(p);
      }
  };
} object_jets;

struct object_MET_s : public lhadaThing
{
  object_MET_s() : lhadaThing() {}
  ~object_MET_s() {}
  void create()
  {
    MET = Delphes_MissingET;
  };
} object_MET;

struct object_electrons_s : public lhadaThing
{
  object_electrons_s() : lhadaThing() {}
  ~object_electrons_s() {}
  void create()
  {
    electrons.clear();
    for(size_t c=0; c < Delphes_Electron.size(); c++)
      {
        TEParticle& p = Delphes_Electron[c];
        if ( !(p("pt") > 7) ) continue;
        if ( !(p("|eta|") < 2.47) ) continue;
        electrons.push_back(p);
      }
  };
} object_electrons;

struct object_tightphotons_s : public lhadaThing
{
  object_tightphotons_s() : lhadaThing() {}
  ~object_tightphotons_s() {}
  void create()
  {
    tightphotons.clear();
    for(size_t c=0; c < photons.size(); c++)
      {
        TEParticle& p = photons[c];
        if ( !((p("|eta|") < 1.37) ||
	 ((p("|eta|") > 1.52) && (p("|eta|") < 2.37))) ) continue;
        tightphotons.push_back(p);
      }
  };
} object_tightphotons;

struct object_cleanjets_s : public lhadaThing
{
  object_cleanjets_s() : lhadaThing() {}
  ~object_cleanjets_s() {}
  void create()
  {
    cleanjets.clear();
    for(size_t c=0; c < jets.size(); c++)
      {
        TEParticle& p = jets[c];
        bool skip = false;
        for(size_t n=0; n < electrons.size(); n++)
          {
            TEParticle& q = electrons[n];
            double dRje = _dR(p("eta"), p("phi"), q("eta"), q("phi"));
            p("drje", dRje);
            if ( p("drje") < 0.2 )
              {
                skip = true;
                break;
              }
          }
        if ( skip ) continue;
        cleanjets.push_back(p);
      }
  };
} object_cleanjets;

struct object_cleanelectrons_s : public lhadaThing
{
  object_cleanelectrons_s() : lhadaThing() {}
  ~object_cleanelectrons_s() {}
  void create()
  {
    cleanelectrons.clear();
    for(size_t c=0; c < electrons.size(); c++)
      {
        TEParticle& p = electrons[c];
        bool skip = false;
        for(size_t n=0; n < cleanjets.size(); n++)
          {
            TEParticle& q = cleanjets[n];
            double dRej = _dR(p("eta"), p("phi"), q("eta"), q("phi"));
            p("drej", dRej);
            if ( p("drej") < 0.4 )
              {
                skip = true;
                break;
              }
          }
        if ( skip ) continue;
        cleanelectrons.push_back(p);
      }
  };
} object_cleanelectrons;

struct object_jetsSR_s : public lhadaThing
{
  object_jetsSR_s() : lhadaThing() {}
  ~object_jetsSR_s() {}
  void create()
  {
    jetsSR.clear();
    for(size_t c=0; c < cleanjets.size(); c++)
      {
        TEParticle& p = cleanjets[c];
        if ( !(p("pt") > 30) ) continue;
        bool skip = false;
        for(size_t n=0; n < photons.size(); n++)
          {
            TEParticle& q = photons[n];
            double dRjp = _dR(p("eta"), p("phi"), q("eta"), q("phi"));
            p("drjp", dRjp);
            if ( p("drjp") < 0.4 )
              {
                skip = true;
                break;
              }
          }
        if ( skip ) continue;
        double dphijmet = _dPhi(p("phi"), MET("phi"));
        p("dphijmet", dphijmet);
        if ( p("dphijmet") < 0.4 ) continue;
        jetsSR.push_back(p);
      }
  };
} object_jetsSR;

struct object_cleanmuons_s : public lhadaThing
{
  object_cleanmuons_s() : lhadaThing() {}
  ~object_cleanmuons_s() {}
  void create()
  {
    cleanmuons.clear();
    for(size_t c=0; c < muons.size(); c++)
      {
        TEParticle& p = muons[c];
        bool skip = false;
        for(size_t n=0; n < cleanjets.size(); n++)
          {
            TEParticle& q = cleanjets[n];
            double dRmuj = _dR(p("eta"), p("phi"), q("eta"), q("phi"));
            p("drmuj", dRmuj);
            if ( p("drmuj") < 0.4 )
              {
                skip = true;
                break;
              }
          }
        if ( skip ) continue;
        cleanmuons.push_back(p);
      }
  };
} object_cleanmuons;


//----------------------------------------------------------------------------
// selections
struct cut_preselection_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  cut_preselection_s()
    : lhadaThing(),
      name("preselection"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1)
  {
    hcount = new TH1F(name.c_str(), "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);

    hcount->Fill("none", 0);
    hcount->Fill("tightphotons.size > 0", 0);
    hcount->Fill("tightphotons[0].PT > 150", 0);
    hcount->Fill("_dPhi(tightphotons[0].Phi, MET.Phi) > 0.4", 0);
    hcount->Fill("METoverSqrtSumET_ > 8.5", 0);
    hcount->Fill("cleanmuons.size == 0", 0);
    hcount->Fill("cleanelectrons.size == 0", 0);
  }

  ~cut_preselection_s() {}

  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), total, sqrt(dtotal));
  }
  void count(string c, double w=1)	{ hcount->Fill(c.c_str(), w); }
  void write(outputFile& out)		{ out.file_->cd(); hcount->Write(); }
  void reset()				{ done = false; result = false; }
  bool operator()()	{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none", weight);

    if ( !(tightphotons.size() > 0) ) return false;
    count("tightphotons.size > 0", weight);

    if ( !(tightphotons[0]("pt") > 150) ) return false;
    count("tightphotons[0].PT > 150", weight);

    if ( !(_dPhi(tightphotons[0]("phi"), MET("phi")) > 0.4) ) return false;
    count("_dPhi(tightphotons[0].Phi, MET.Phi) > 0.4", weight);

    if ( !(METoverSqrtSumET_ > 8.5) ) return false;
    count("METoverSqrtSumET_ > 8.5", weight);

    if ( !(cleanmuons.size() == 0) ) return false;
    count("cleanmuons.size == 0", weight);

    if ( !(cleanelectrons.size() == 0) ) return false;
    count("cleanelectrons.size == 0", weight);

    total  += weight;
    dtotal += weight * weight;
    result  = true;
    return true;
  }
} cut_preselection;

struct cut_SRE2_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  cut_SRE2_s()
    : lhadaThing(),
      name("SRE2"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1)
  {
    hcount = new TH1F(name.c_str(), "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("MET.PT > 225 and MET.PT < 300", 0);
  }

  ~cut_SRE2_s() {}

  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), total, sqrt(dtotal));
  }
  void count(string c, double w=1)	{ hcount->Fill(c.c_str(), w); }
  void write(outputFile& out)		{ out.file_->cd(); hcount->Write(); }
  void reset()				{ done = false; result = false; }
  bool operator()()	{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none", weight);

    if ( !(cut_preselection()) ) return false;
    count("preselection", weight);

    if ( !(MET("pt") > 225 && MET("pt") < 300) ) return false;
    count("MET.PT > 225 and MET.PT < 300", weight);

    total  += weight;
    dtotal += weight * weight;
    result  = true;
    return true;
  }
} cut_SRE2;

struct cut_SRI1_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  cut_SRI1_s()
    : lhadaThing(),
      name("SRI1"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1)
  {
    hcount = new TH1F(name.c_str(), "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("MET.PT > 150", 0);
  }

  ~cut_SRI1_s() {}

  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), total, sqrt(dtotal));
  }
  void count(string c, double w=1)	{ hcount->Fill(c.c_str(), w); }
  void write(outputFile& out)		{ out.file_->cd(); hcount->Write(); }
  void reset()				{ done = false; result = false; }
  bool operator()()	{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none", weight);

    if ( !(cut_preselection()) ) return false;
    count("preselection", weight);

    if ( !(MET("pt") > 150) ) return false;
    count("MET.PT > 150", weight);

    total  += weight;
    dtotal += weight * weight;
    result  = true;
    return true;
  }
} cut_SRI1;

struct cut_SRI2_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  cut_SRI2_s()
    : lhadaThing(),
      name("SRI2"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1)
  {
    hcount = new TH1F(name.c_str(), "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("MET.PT > 225", 0);
  }

  ~cut_SRI2_s() {}

  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), total, sqrt(dtotal));
  }
  void count(string c, double w=1)	{ hcount->Fill(c.c_str(), w); }
  void write(outputFile& out)		{ out.file_->cd(); hcount->Write(); }
  void reset()				{ done = false; result = false; }
  bool operator()()	{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none", weight);

    if ( !(cut_preselection()) ) return false;
    count("preselection", weight);

    if ( !(MET("pt") > 225) ) return false;
    count("MET.PT > 225", weight);

    total  += weight;
    dtotal += weight * weight;
    result  = true;
    return true;
  }
} cut_SRI2;

struct cut_SRI3_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  cut_SRI3_s()
    : lhadaThing(),
      name("SRI3"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1)
  {
    hcount = new TH1F(name.c_str(), "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("MET.PT > 300", 0);
  }

  ~cut_SRI3_s() {}

  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), total, sqrt(dtotal));
  }
  void count(string c, double w=1)	{ hcount->Fill(c.c_str(), w); }
  void write(outputFile& out)		{ out.file_->cd(); hcount->Write(); }
  void reset()				{ done = false; result = false; }
  bool operator()()	{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none", weight);

    if ( !(cut_preselection()) ) return false;
    count("preselection", weight);

    if ( !(MET("pt") > 300) ) return false;
    count("MET.PT > 300", weight);

    total  += weight;
    dtotal += weight * weight;
    result  = true;
    return true;
  }
} cut_SRI3;

struct cut_SRE1_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  cut_SRE1_s()
    : lhadaThing(),
      name("SRE1"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1)
  {
    hcount = new TH1F(name.c_str(), "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("MET.PT > 150 and MET.PT < 225", 0);
  }

  ~cut_SRE1_s() {}

  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), total, sqrt(dtotal));
  }
  void count(string c, double w=1)	{ hcount->Fill(c.c_str(), w); }
  void write(outputFile& out)		{ out.file_->cd(); hcount->Write(); }
  void reset()				{ done = false; result = false; }
  bool operator()()	{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none", weight);

    if ( !(cut_preselection()) ) return false;
    count("preselection", weight);

    if ( !(MET("pt") > 150 && MET("pt") < 225) ) return false;
    count("MET.PT > 150 and MET.PT < 225", weight);

    total  += weight;
    dtotal += weight * weight;
    result  = true;
    return true;
  }
} cut_SRE1;


//----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  // If you want canvases to be visible during program execution, just
  // uncomment the line below
  //TApplication app("delphesAnalyzer", &argc, argv);

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

  // -------------------------------------------------------------------------
  // Define histograms
  // -------------------------------------------------------------------------
  //setStyle();

  // -------------------------------------------------------------------------
  // Create an appropriate event adapter
  // -------------------------------------------------------------------------
  DelphesAdapter adapter;

  // cache pointers to filtered objects
  vector<lhadaThing*> objects;
  objects.push_back(&object_scalarHT);
  objects.push_back(&object_photons);
  objects.push_back(&object_muons);
  objects.push_back(&object_jets);
  objects.push_back(&object_MET);
  objects.push_back(&object_electrons);
  objects.push_back(&object_tightphotons);
  objects.push_back(&object_cleanjets);
  objects.push_back(&object_cleanelectrons);
  objects.push_back(&object_jetsSR);
  objects.push_back(&object_cleanmuons);

  // cache pointers to cuts
  vector<lhadaThing*> cuts;
  cuts.push_back(&cut_preselection);
  cuts.push_back(&cut_SRE2);
  cuts.push_back(&cut_SRI1);
  cuts.push_back(&cut_SRI2);
  cuts.push_back(&cut_SRI3);
  cuts.push_back(&cut_SRE1);

  // -------------------------------------------------------------------------
  // Loop over events
  // -------------------------------------------------------------------------
  for(int entry=0; entry < nevents; entry++)
    {
      // read an event into event buffer
      ev.read(entry);

      if ( entry % 10000 == 0 ) cout << entry << endl;

      // get external objects
      adapter(ev, "Delphes_Muon", 	Delphes_Muon);
      adapter(ev, "Delphes_MissingET", 	Delphes_MissingET);
      adapter(ev, "Delphes_Electron", 	Delphes_Electron);
      adapter(ev, "Delphes_Jet", 	Delphes_Jet);
      adapter(ev, "Delphes_scalarHT", 	Delphes_scalarHT);
      adapter(ev, "Delphes_Photon", 	Delphes_Photon);

      // create filtered objects
      for(size_t c=0; c < objects.size(); c++) objects[c]->create();

      // compute event level variables
      METoverSqrtSumET_	= METoverSqrtSumET(MET, scalarHT);

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
