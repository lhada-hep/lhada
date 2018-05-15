//---------------------------------------------------------------------------
// File:        analyzer.cc
// Description: Analyzer for LHADA analysis:
//
// LHADA file: ../../../doc/ATLASSUSY1605.03814.lhada
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
// Created:     Tue May 15 14:41:26 2018 by lhada2tnm.py
//----------------------------------------------------------------------------
#include <algorithm>
#include "tnm.h"
#include "TEParticle.h"
#include "DelphesAdapter.h"
#include "ATLASSUSY1605.03814_functions.h"

using namespace std;
//----------------------------------------------------------------------------
// The following functions, objects, and variables are globally visible.
//----------------------------------------------------------------------------
//
// functions
inline
double	_dphijNjle3METmin(vector<TEParticle>& jetsSR, TLorentzVector& MET)
{
  vector<TLorentzVector> jetsSR_(jetsSR.size());
  copy(jetsSR.begin(), jetsSR.begin(), jetsSR_.begin());
  return dphijNjle3METmin(jetsSR_, MET);
};

inline
double	_aplanarity(vector<TEParticle>& jetsSR)
{
  vector<TLorentzVector> jetsSR_(jetsSR.size());
  copy(jetsSR.begin(), jetsSR.begin(), jetsSR_.begin());
  return aplanarity(jetsSR_);
};

inline
double	_dphijNjgt3METmin(vector<TEParticle>& jetsSR, TLorentzVector& MET)
{
  vector<TLorentzVector> jetsSR_(jetsSR.size());
  copy(jetsSR.begin(), jetsSR.begin(), jetsSR_.begin());
  return dphijNjgt3METmin(jetsSR_, MET);
};

inline
double	_Meff(vector<TEParticle>& jetsSR, TLorentzVector& MET)
{
  vector<TLorentzVector> jetsSR_(jetsSR.size());
  copy(jetsSR.begin(), jetsSR.begin(), jetsSR_.begin());
  return Meff(jetsSR_, MET);
};

inline
double	_METovermeffNJ(vector<TEParticle>& jetsSR, int njets, TLorentzVector& MET)
{
  vector<TLorentzVector> jetsSR_(jetsSR.size());
  copy(jetsSR.begin(), jetsSR.begin(), jetsSR_.begin());
  return METovermeffNJ(jetsSR_, njets, MET);
};

inline
double	_dR(double Eta1, double Phi1, double Eta2, double Phi2)
{
  return dR(Eta1, Phi1, Eta2, Phi2);
};

inline
double	_METoversqrtHT(vector<TEParticle>& jetsSR, TLorentzVector& MET)
{
  vector<TLorentzVector> jetsSR_(jetsSR.size());
  copy(jetsSR.begin(), jetsSR.begin(), jetsSR_.begin());
  return METoversqrtHT(jetsSR_, MET);
};


//----------------------------------------------------------------------------
// variables
double	dphijNjgt3METmin_;
double	aplanarity_;
double	METovermeff6j_;
double	METovermeff4j_;
double	METovermeff5j_;
double	Meff_;
double	METovermeff2j_;
double	dphijNjle3METmin_;
double	METoversqrtHT_;

//----------------------------------------------------------------------------
// external objects
vector<TEParticle> Delphes_Muon;
vector<TEParticle> Delphes_Jet;

TEParticle Delphes_MissingET;

vector<TEParticle> Delphes_Electron;

// internal objects
vector<TEParticle> muons;
vector<TEParticle> jets;

TEParticle MET;

vector<TEParticle> electrons;
vector<TEParticle> bjets;
vector<TEParticle> cleanjets;
vector<TEParticle> jetsSR;
vector<TEParticle> cleanmuons;
vector<TEParticle> cleanelectrons;
vector<TEParticle> verycleanelectrons;


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
        if ( !(p("pt") > 10) ) continue;
        if ( !(p("|eta|") < 2.7) ) continue;
        if ( !(p("isolationvarrhocorr") < 0.1) ) continue;
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
        if ( !(p("|eta|") < 2.8) ) continue;
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
        if ( !(p("pt") > 10) ) continue;
        if ( !(p("|eta|") < 2.47) ) continue;
        electrons.push_back(p);
      }
  };
} object_electrons;

struct object_bjets_s : public lhadaThing
{
  object_bjets_s() : lhadaThing() {}
  ~object_bjets_s() {}
  void create()
  {
    bjets.clear();
    for(size_t c=0; c < jets.size(); c++)
      {
        TEParticle& p = jets[c];
        if ( !(p("btag") == 1) ) continue;
        if ( !(p("pt") > 50) ) continue;
        if ( !(p("|eta|") < 2.5) ) continue;
        bjets.push_back(p);
      }
  };
} object_bjets;

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
        if ( !(p("pt") > 50) ) continue;
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
            double dRlj = _dR(p("eta"), p("phi"), q("eta"), q("phi"));
            p("drlj", dRlj);
            if ( p("drlj") < 0.4 )
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
            double dRlj = _dR(p("eta"), p("phi"), q("eta"), q("phi"));
            p("drlj", dRlj);
            if ( p("drlj") < 0.4 )
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

struct object_verycleanelectrons_s : public lhadaThing
{
  object_verycleanelectrons_s() : lhadaThing() {}
  ~object_verycleanelectrons_s() {}
  void create()
  {
    verycleanelectrons.clear();
    for(size_t c=0; c < cleanelectrons.size(); c++)
      {
        TEParticle& p = cleanelectrons[c];
        bool skip = false;
        for(size_t n=0; n < cleanelectrons.size(); n++)
          {
            TEParticle& q = cleanelectrons[n];
            double dRee = _dR(p("eta"), p("phi"), q("eta"), q("phi"));
            p("dree", dRee);
            if ( (p("dree") < 0.05) && (p("pt") < q("pt")) )
              {
                skip = true;
                break;
              }
          }
        if ( skip ) continue;
        verycleanelectrons.push_back(p);
      }
  };
} object_verycleanelectrons;


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

  int    ncuts;

  cut_preselection_s()
    : lhadaThing(),
      name("preselection"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(2)
  {
    hcount = new TH1F("cutflow_preselection", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("MET.PT > 200", 0);
    hcount->Fill("jetsSR.size > 0", 0);
  }

  ~cut_preselection_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(MET("pt") > 200) ) return false;
    count("MET.PT > 200");

    if ( !(jetsSR.size() > 0) ) return false;
    count("jetsSR.size > 0");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_preselection;

struct cut_2jt_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  int    ncuts;

  cut_2jt_s()
    : lhadaThing(),
      name("2jt"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(7)
  {
    hcount = new TH1F("cutflow_2jt", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("jetsSR.size >= 2", 0);
    hcount->Fill("jetsSR[0].PT > 200", 0);
    hcount->Fill("jetsSR[1].PT > 200", 0);
    hcount->Fill("dphijNjle3METmin > 0.8", 0);
    hcount->Fill("METoversqrtHT > 20", 0);
    hcount->Fill("Meff > 2000", 0);
  }

  ~cut_2jt_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(cut_preselection()) ) return false;
    count("preselection");

    if ( !(jetsSR.size() >= 2) ) return false;
    count("jetsSR.size >= 2");

    if ( !(jetsSR[0]("pt") > 200) ) return false;
    count("jetsSR[0].PT > 200");

    if ( !(jetsSR[1]("pt") > 200) ) return false;
    count("jetsSR[1].PT > 200");

    if ( !(dphijNjle3METmin_ > 0.8) ) return false;
    count("dphijNjle3METmin > 0.8");

    if ( !(METoversqrtHT_ > 20) ) return false;
    count("METoversqrtHT > 20");

    if ( !(Meff_ > 2000) ) return false;
    count("Meff > 2000");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_2jt;

struct cut_2jm_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  int    ncuts;

  cut_2jm_s()
    : lhadaThing(),
      name("2jm"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(7)
  {
    hcount = new TH1F("cutflow_2jm", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("jetsSR.size >= 2", 0);
    hcount->Fill("jetsSR[0].PT > 300", 0);
    hcount->Fill("jetsSR[1].PT > 50", 0);
    hcount->Fill("dphijNjle3METmin > 0.4", 0);
    hcount->Fill("METoversqrtHT > 15", 0);
    hcount->Fill("Meff > 1600", 0);
  }

  ~cut_2jm_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(cut_preselection()) ) return false;
    count("preselection");

    if ( !(jetsSR.size() >= 2) ) return false;
    count("jetsSR.size >= 2");

    if ( !(jetsSR[0]("pt") > 300) ) return false;
    count("jetsSR[0].PT > 300");

    if ( !(jetsSR[1]("pt") > 50) ) return false;
    count("jetsSR[1].PT > 50");

    if ( !(dphijNjle3METmin_ > 0.4) ) return false;
    count("dphijNjle3METmin > 0.4");

    if ( !(METoversqrtHT_ > 15) ) return false;
    count("METoversqrtHT > 15");

    if ( !(Meff_ > 1600) ) return false;
    count("Meff > 1600");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_2jm;

struct cut_2jl_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  int    ncuts;

  cut_2jl_s()
    : lhadaThing(),
      name("2jl"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(7)
  {
    hcount = new TH1F("cutflow_2jl", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("jetsSR.size >= 2", 0);
    hcount->Fill("jetsSR[0].PT > 200", 0);
    hcount->Fill("jetsSR[1].PT > 200", 0);
    hcount->Fill("dphijNjle3METmin > 0.8", 0);
    hcount->Fill("METoversqrtHT > 15", 0);
    hcount->Fill("Meff > 1200", 0);
  }

  ~cut_2jl_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(cut_preselection()) ) return false;
    count("preselection");

    if ( !(jetsSR.size() >= 2) ) return false;
    count("jetsSR.size >= 2");

    if ( !(jetsSR[0]("pt") > 200) ) return false;
    count("jetsSR[0].PT > 200");

    if ( !(jetsSR[1]("pt") > 200) ) return false;
    count("jetsSR[1].PT > 200");

    if ( !(dphijNjle3METmin_ > 0.8) ) return false;
    count("dphijNjle3METmin > 0.8");

    if ( !(METoversqrtHT_ > 15) ) return false;
    count("METoversqrtHT > 15");

    if ( !(Meff_ > 1200) ) return false;
    count("Meff > 1200");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_2jl;

struct cut_6jt_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  int    ncuts;

  cut_6jt_s()
    : lhadaThing(),
      name("6jt"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(13)
  {
    hcount = new TH1F("cutflow_6jt", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("jetsSR.size >= 6", 0);
    hcount->Fill("jetsSR[0].PT > 200", 0);
    hcount->Fill("jetsSR[1].PT > 100", 0);
    hcount->Fill("jetsSR[2].PT > 100", 0);
    hcount->Fill("jetsSR[3].PT > 100", 0);
    hcount->Fill("jetsSR[4].PT > 50", 0);
    hcount->Fill("jetsSR[5].PT > 50", 0);
    hcount->Fill("dphijNjle3METmin > 0.4", 0);
    hcount->Fill("dphijNjgt3METmin > 0.2", 0);
    hcount->Fill("aplanarity > 0.04", 0);
    hcount->Fill("METovermeff6j > 0.2", 0);
    hcount->Fill("Meff > 2000", 0);
  }

  ~cut_6jt_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(cut_preselection()) ) return false;
    count("preselection");

    if ( !(jetsSR.size() >= 6) ) return false;
    count("jetsSR.size >= 6");

    if ( !(jetsSR[0]("pt") > 200) ) return false;
    count("jetsSR[0].PT > 200");

    if ( !(jetsSR[1]("pt") > 100) ) return false;
    count("jetsSR[1].PT > 100");

    if ( !(jetsSR[2]("pt") > 100) ) return false;
    count("jetsSR[2].PT > 100");

    if ( !(jetsSR[3]("pt") > 100) ) return false;
    count("jetsSR[3].PT > 100");

    if ( !(jetsSR[4]("pt") > 50) ) return false;
    count("jetsSR[4].PT > 50");

    if ( !(jetsSR[5]("pt") > 50) ) return false;
    count("jetsSR[5].PT > 50");

    if ( !(dphijNjle3METmin_ > 0.4) ) return false;
    count("dphijNjle3METmin > 0.4");

    if ( !(dphijNjgt3METmin_ > 0.2) ) return false;
    count("dphijNjgt3METmin > 0.2");

    if ( !(aplanarity_ > 0.04) ) return false;
    count("aplanarity > 0.04");

    if ( !(METovermeff6j_ > 0.2) ) return false;
    count("METovermeff6j > 0.2");

    if ( !(Meff_ > 2000) ) return false;
    count("Meff > 2000");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_6jt;

struct cut_6jm_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  int    ncuts;

  cut_6jm_s()
    : lhadaThing(),
      name("6jm"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(13)
  {
    hcount = new TH1F("cutflow_6jm", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("jetsSR.size >= 6", 0);
    hcount->Fill("jetsSR[0].PT > 200", 0);
    hcount->Fill("jetsSR[1].PT > 100", 0);
    hcount->Fill("jetsSR[2].PT > 100", 0);
    hcount->Fill("jetsSR[3].PT > 100", 0);
    hcount->Fill("jetsSR[4].PT > 50", 0);
    hcount->Fill("jetsSR[5].PT > 50", 0);
    hcount->Fill("dphijNjle3METmin > 0.4", 0);
    hcount->Fill("dphijNjgt3METmin > 0.2", 0);
    hcount->Fill("aplanarity > 0.04", 0);
    hcount->Fill("METovermeff6j > 0.25", 0);
    hcount->Fill("Meff > 1600", 0);
  }

  ~cut_6jm_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(cut_preselection()) ) return false;
    count("preselection");

    if ( !(jetsSR.size() >= 6) ) return false;
    count("jetsSR.size >= 6");

    if ( !(jetsSR[0]("pt") > 200) ) return false;
    count("jetsSR[0].PT > 200");

    if ( !(jetsSR[1]("pt") > 100) ) return false;
    count("jetsSR[1].PT > 100");

    if ( !(jetsSR[2]("pt") > 100) ) return false;
    count("jetsSR[2].PT > 100");

    if ( !(jetsSR[3]("pt") > 100) ) return false;
    count("jetsSR[3].PT > 100");

    if ( !(jetsSR[4]("pt") > 50) ) return false;
    count("jetsSR[4].PT > 50");

    if ( !(jetsSR[5]("pt") > 50) ) return false;
    count("jetsSR[5].PT > 50");

    if ( !(dphijNjle3METmin_ > 0.4) ) return false;
    count("dphijNjle3METmin > 0.4");

    if ( !(dphijNjgt3METmin_ > 0.2) ) return false;
    count("dphijNjgt3METmin > 0.2");

    if ( !(aplanarity_ > 0.04) ) return false;
    count("aplanarity > 0.04");

    if ( !(METovermeff6j_ > 0.25) ) return false;
    count("METovermeff6j > 0.25");

    if ( !(Meff_ > 1600) ) return false;
    count("Meff > 1600");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_6jm;

struct cut_5j_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  int    ncuts;

  cut_5j_s()
    : lhadaThing(),
      name("5j"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(12)
  {
    hcount = new TH1F("cutflow_5j", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("jetsSR.size >= 5", 0);
    hcount->Fill("jetsSR[0].PT > 200", 0);
    hcount->Fill("jetsSR[1].PT > 100", 0);
    hcount->Fill("jetsSR[2].PT > 100", 0);
    hcount->Fill("jetsSR[3].PT > 100", 0);
    hcount->Fill("jetsSR[4].PT > 50", 0);
    hcount->Fill("dphijNjle3METmin > 0.4", 0);
    hcount->Fill("dphijNjgt3METmin > 0.2", 0);
    hcount->Fill("aplanarity > 0.04", 0);
    hcount->Fill("METovermeff5j > 0.25", 0);
    hcount->Fill("Meff > 1600", 0);
  }

  ~cut_5j_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(cut_preselection()) ) return false;
    count("preselection");

    if ( !(jetsSR.size() >= 5) ) return false;
    count("jetsSR.size >= 5");

    if ( !(jetsSR[0]("pt") > 200) ) return false;
    count("jetsSR[0].PT > 200");

    if ( !(jetsSR[1]("pt") > 100) ) return false;
    count("jetsSR[1].PT > 100");

    if ( !(jetsSR[2]("pt") > 100) ) return false;
    count("jetsSR[2].PT > 100");

    if ( !(jetsSR[3]("pt") > 100) ) return false;
    count("jetsSR[3].PT > 100");

    if ( !(jetsSR[4]("pt") > 50) ) return false;
    count("jetsSR[4].PT > 50");

    if ( !(dphijNjle3METmin_ > 0.4) ) return false;
    count("dphijNjle3METmin > 0.4");

    if ( !(dphijNjgt3METmin_ > 0.2) ) return false;
    count("dphijNjgt3METmin > 0.2");

    if ( !(aplanarity_ > 0.04) ) return false;
    count("aplanarity > 0.04");

    if ( !(METovermeff5j_ > 0.25) ) return false;
    count("METovermeff5j > 0.25");

    if ( !(Meff_ > 1600) ) return false;
    count("Meff > 1600");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_5j;

struct cut_4jt_s : public lhadaThing
{
  std::string name;
  double total;
  double dtotal;
  TH1F*  hcount;
  bool   done;
  bool   result;
  double weight;

  int    ncuts;

  cut_4jt_s()
    : lhadaThing(),
      name("4jt"),
      total(0),
      dtotal(0),
      hcount(0),
      done(false),
      result(false),
      weight(1),
      ncuts(11)
  {
    hcount = new TH1F("cutflow_4jt", "", 1, 0, 1);
    hcount->SetCanExtend(1);
    hcount->SetStats(0);
    hcount->Sumw2();

    hcount->Fill("none", 0);
    hcount->Fill("preselection", 0);
    hcount->Fill("jetsSR.size >= 4", 0);
    hcount->Fill("jetsSR[0].PT > 200", 0);
    hcount->Fill("jetsSR[1].PT > 100", 0);
    hcount->Fill("jetsSR[2].PT > 100", 0);
    hcount->Fill("jetsSR[3].PT > 100", 0);
    hcount->Fill("dphijNjle3METmin > 0.4", 0);
    hcount->Fill("dphijNjgt3METmin > 0.2", 0);
    hcount->Fill("aplanarity > 0.04", 0);
    hcount->Fill("METovermeff4j > 0.2", 0);
    hcount->Fill("Meff > 2200", 0);
  }

  ~cut_4jt_s() {}

  void summary()
  {
    cout << name << endl;
    double gtotal = hcount->GetBinContent(1);
    for(int c=0; c <= ncuts; c++)
      {
        double value(hcount->GetBinContent(c+1));
        double error(hcount->GetBinError(c+1));
        double efficiency=0;
        if ( gtotal > 0 ) efficiency = value/gtotal;
        printf(" %2d %-45s: %9.2f +/- %5.1f %6.3f\n",
               c+1, hcount->GetXaxis()->GetBinLabel(c+1), value, error, efficiency);
      }
    cout << endl;
  }
  void count(string c)		{ hcount->Fill(c.c_str(), weight); }
  void write(outputFile& out)	{ out.file_->cd(); hcount->Write(); }
  void reset()			{ done = false; result = false; }
  bool operator()()		{ return apply(); }

  bool apply()
  {
    if ( done ) return result;
    done   = true;
    result = false;
    count("none");

    if ( !(cut_preselection()) ) return false;
    count("preselection");

    if ( !(jetsSR.size() >= 4) ) return false;
    count("jetsSR.size >= 4");

    if ( !(jetsSR[0]("pt") > 200) ) return false;
    count("jetsSR[0].PT > 200");

    if ( !(jetsSR[1]("pt") > 100) ) return false;
    count("jetsSR[1].PT > 100");

    if ( !(jetsSR[2]("pt") > 100) ) return false;
    count("jetsSR[2].PT > 100");

    if ( !(jetsSR[3]("pt") > 100) ) return false;
    count("jetsSR[3].PT > 100");

    if ( !(dphijNjle3METmin_ > 0.4) ) return false;
    count("dphijNjle3METmin > 0.4");

    if ( !(dphijNjgt3METmin_ > 0.2) ) return false;
    count("dphijNjgt3METmin > 0.2");

    if ( !(aplanarity_ > 0.04) ) return false;
    count("aplanarity > 0.04");

    if ( !(METovermeff4j_ > 0.2) ) return false;
    count("METovermeff4j > 0.2");

    if ( !(Meff_ > 2200) ) return false;
    count("Meff > 2200");

    total  += weight;
    dtotal += weight * weight;

    // NB: remember to update result cache
    result  = true;
    return true;
  }
} cut_4jt;


//----------------------------------------------------------------------------
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
  objects.push_back(&object_muons);
  objects.push_back(&object_jets);
  objects.push_back(&object_MET);
  objects.push_back(&object_electrons);
  objects.push_back(&object_bjets);
  objects.push_back(&object_cleanjets);
  objects.push_back(&object_jetsSR);
  objects.push_back(&object_cleanmuons);
  objects.push_back(&object_cleanelectrons);
  objects.push_back(&object_verycleanelectrons);

  // cache pointers to cuts
  vector<lhadaThing*> cuts;
  cuts.push_back(&cut_preselection);
  cuts.push_back(&cut_2jt);
  cuts.push_back(&cut_2jm);
  cuts.push_back(&cut_2jl);
  cuts.push_back(&cut_6jt);
  cuts.push_back(&cut_6jm);
  cuts.push_back(&cut_5j);
  cuts.push_back(&cut_4jt);

  // -------------------------------------------------------------------------
  // Loop over events
  // -------------------------------------------------------------------------
  for(int entry=0; entry < nevents; entry++)
    {
      // read an event into event buffer
      ev.read(entry);

      if ( entry % 10000 == 0 ) cout << entry << endl;

      // get external objects
      adapter(ev, "Delphes_Jet", 	Delphes_Jet);
      adapter(ev, "Delphes_Electron", 	Delphes_Electron);
      adapter(ev, "Delphes_MissingET", 	Delphes_MissingET);
      adapter(ev, "Delphes_Muon", 	Delphes_Muon);

      // create filtered objects
      for(size_t c=0; c < objects.size(); c++) objects[c]->create();

      // compute event level variables
      dphijNjgt3METmin_	= _dphijNjgt3METmin(jetsSR, MET);
      aplanarity_	= _aplanarity(jetsSR);
      METovermeff6j_	= _METovermeffNJ(jetsSR, 6, MET);
      METovermeff4j_	= _METovermeffNJ(jetsSR, 4, MET);
      METovermeff5j_	= _METovermeffNJ(jetsSR, 5, MET);
      Meff_	= _Meff(jetsSR, MET);
      METovermeff2j_	= _METovermeffNJ(jetsSR, 2, MET);
      dphijNjle3METmin_	= _dphijNjle3METmin(jetsSR, MET);
      METoversqrtHT_	= _METoversqrtHT(jetsSR, MET);

      // apply event level selections
      for(size_t c=0; c < cuts.size(); c++)
        { 
          cuts[c]->reset();
          cuts[c]->apply();
        }
    }

  // count summary
  cout << "Summary" << endl << endl;
  for(size_t c=0; c < cuts.size(); c++)
    {
      cuts[c]->summary();
      cuts[c]->write(of);
    }   

  ev.close();
  of.close();
  return 0;
}
