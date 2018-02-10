//---------------------------------------------------------------------------
// File:        delphesAnalyzer.cc
// Description: Analyzer for LHADA analysis:
//
// LHADA file: ../doc/ATLASSUSY1605.03814.lhada
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
// Created:     Fri Feb  9 23:00:30 2018 by lhada2tnm.py
//----------------------------------------------------------------------------
#include "tnm.h"
#include "LHParticle.h"
#include "DelphesAdapter.h"
#include "ATLASSUSY1605.03814_functions.h"

using namespace std;
//----------------------------------------------------------------------------
// The following functions, objects, and variables are globally visible.
//----------------------------------------------------------------------------
//
// functions
double	lha_aplanarity(std::vector<LHParticle>& jetsSR)
{
  return lha::aplanarity(jetsSR);
};
double	lha_Meff(std::vector<LHParticle>& jetsSR, LHParticle& MET)
{
  return lha::Meff(jetsSR, MET);
};
double	lha_dR(double Eta1, double Phi1, double Eta2, double Phi2)
{
  return lha::dR(Eta1, Phi1, Eta2, Phi2);
};
double	lha_METovermeffNJ(std::vector<LHParticle>& jetsSR, int njets, LHParticle& MET)
{
  return lha::METovermeffNJ(jetsSR, njets, MET);
};
double	lha_dphijNjgt3METmin(std::vector<LHParticle>& jetsSR, LHParticle& MET)
{
  return lha::dphijNjgt3METmin(jetsSR, MET);
};
double	lha_METoversqrtHT(std::vector<LHParticle>& jetsSR, LHParticle& MET)
{
  return lha::METoversqrtHT(jetsSR, MET);
};
double	lha_dphijNjle3METmin(std::vector<LHParticle>& jetsSR, LHParticle& MET)
{
  return lha::dphijNjle3METmin(jetsSR, MET);
};

//----------------------------------------------------------------------------
// external objects
vector<LHParticle> Delphes_Muon;
vector<LHParticle> Delphes_Electron;
vector<LHParticle> Delphes_Jet;

LHParticle Delphes_MissingET;


// internal objects
vector<LHParticle> muons;
vector<LHParticle> electrons;
vector<LHParticle> jets;

LHParticle MET;

vector<LHParticle> bjets;
vector<LHParticle> cleanjets;
vector<LHParticle> cleanelectrons;
vector<LHParticle> verycleanelectrons;
vector<LHParticle> jetsSR;
vector<LHParticle> cleanmuons;


// object definitions
struct lhadaThing
{
  lhadaThing() {}
  ~lhadaThing() {}
  virtual void summary() {}
};

struct object_muons_s : public lhadaThing
{
  object_muons_s() : lhadaThing() {}
  ~object_muons_s() {}
  void operator()()
  {
    muons.clear();
    for(size_t c=0; c < Delphes_Muon.size(); c++)
      {
        LHParticle& p = Delphes_Muon[c];
        if ( !(p("PT") > 10) ) continue;
        if ( !(p("|Eta|") < 2.7) ) continue;
        if ( !(p("IsolationVarRhoCorr") < 0.1) ) continue;
        muons.push_back(p);
      }
  };
} object_muons;

struct object_electrons_s : public lhadaThing
{
  object_electrons_s() : lhadaThing() {}
  ~object_electrons_s() {}
  void operator()()
  {
    electrons.clear();
    for(size_t c=0; c < Delphes_Electron.size(); c++)
      {
        LHParticle& p = Delphes_Electron[c];
        if ( !(p("PT") > 10) ) continue;
        if ( !(p("|Eta|") < 2.47) ) continue;
        electrons.push_back(p);
      }
  };
} object_electrons;

struct object_jets_s : public lhadaThing
{
  object_jets_s() : lhadaThing() {}
  ~object_jets_s() {}
  void operator()()
  {
    jets.clear();
    for(size_t c=0; c < Delphes_Jet.size(); c++)
      {
        LHParticle& p = Delphes_Jet[c];
        if ( !(p("PT") > 20) ) continue;
        if ( !(p("|Eta|") < 2.8) ) continue;
        jets.push_back(p);
      }
  };
} object_jets;

struct object_MET_s : public lhadaThing
{
  object_MET_s() : lhadaThing() {}
  ~object_MET_s() {}
  void operator()()
  {
    MET = Delphes_MissingET;
  };
} object_MET;

struct object_bjets_s : public lhadaThing
{
  object_bjets_s() : lhadaThing() {}
  ~object_bjets_s() {}
  void operator()()
  {
    bjets.clear();
    for(size_t c=0; c < jets.size(); c++)
      {
        LHParticle& p = jets[c];
        if ( !(p("BTag") == 1) ) continue;
        if ( !(p("PT") > 50) ) continue;
        if ( !(p("|Eta|") < 2.5) ) continue;
        bjets.push_back(p);
      }
  };
} object_bjets;

struct object_cleanjets_s : public lhadaThing
{
  object_cleanjets_s() : lhadaThing() {}
  ~object_cleanjets_s() {}
  void operator()()
  {
    cleanjets.clear();
    for(size_t c=0; c < jets.size(); c++)
      {
        LHParticle& p = jets[c];
        bool skip = false;
        for(size_t ec=0; ec < electrons.size(); ec++)
          {
            LHParticle& e = electrons[ec];
            double dRje = lha_dR(p("Eta"), p("Phi"), e("Eta"), e("Phi"));
            p("dRje", dRje);
            if ( p("dRje") < 0.2 )
              {
                skip = true;
                break;
              }
          };
        if ( skip ) continue;
        cleanjets.push_back(p);
      }
  };
} object_cleanjets;

struct object_cleanelectrons_s : public lhadaThing
{
  object_cleanelectrons_s() : lhadaThing() {}
  ~object_cleanelectrons_s() {}
  void operator()()
  {
    cleanelectrons.clear();
    for(size_t c=0; c < electrons.size(); c++)
      {
        LHParticle& p = electrons[c];
        bool skip = false;
        for(size_t jc=0; jc < cleanjets.size(); jc++)
          {
            LHParticle& j = cleanjets[jc];
            double dRlj = lha_dR(p("Eta"), p("Phi"), j("Eta"), j("Phi"));
            p("dRlj", dRlj);
            if ( p("dRlj") < 0.4 )
              {
                skip = true;
                break;
              }
          };
        if ( skip ) continue;
        cleanelectrons.push_back(p);
      }
  };
} object_cleanelectrons;

struct object_verycleanelectrons_s : public lhadaThing
{
  object_verycleanelectrons_s() : lhadaThing() {}
  ~object_verycleanelectrons_s() {}
  void operator()()
  {
    verycleanelectrons.clear();
    for(size_t c=0; c < cleanelectrons.size(); c++)
      {
        LHParticle& p = cleanelectrons[c];
        bool skip = false;
        for(size_t ec=0; ec < cleanelectrons.size(); ec++)
          {
            LHParticle& e = cleanelectrons[ec];
            double dRee = lha_dR(p("Eta"), p("Phi"), e("Eta"), e("Phi"));
            p("dRee", dRee);
            if ( (p("dRee") < 0.05) && (p("PT") < e("PT")) )
              {
                skip = true;
                break;
              }
          };
        if ( skip ) continue;
        verycleanelectrons.push_back(p);
      }
  };
} object_verycleanelectrons;

struct object_jetsSR_s : public lhadaThing
{
  object_jetsSR_s() : lhadaThing() {}
  ~object_jetsSR_s() {}
  void operator()()
  {
    jetsSR.clear();
    for(size_t c=0; c < cleanjets.size(); c++)
      {
        LHParticle& p = cleanjets[c];
        if ( !(p("PT") > 50) ) continue;
        jetsSR.push_back(p);
      }
  };
} object_jetsSR;

struct object_cleanmuons_s : public lhadaThing
{
  object_cleanmuons_s() : lhadaThing() {}
  ~object_cleanmuons_s() {}
  void operator()()
  {
    cleanmuons.clear();
    for(size_t c=0; c < muons.size(); c++)
      {
        LHParticle& p = muons[c];
        bool skip = false;
        for(size_t jc=0; jc < cleanjets.size(); jc++)
          {
            LHParticle& j = cleanjets[jc];
            double dRlj = lha_dR(p("Eta"), p("Phi"), j("Eta"), j("Phi"));
            p("dRlj", dRlj);
            if ( p("dRlj") < 0.4 )
              {
                skip = true;
                break;
              }
          };
        if ( skip ) continue;
        cleanmuons.push_back(p);
      }
  };
} object_cleanmuons;


//----------------------------------------------------------------------------
// variables
double	Meff;
double	METoversqrtHT;
double	dphijNjle3METmin;
double	METovermeff5j;
double	dphijNjgt3METmin;
double	aplanarity;
double	METovermeff4j;
double	METovermeff2j;
double	METovermeff6j;

//----------------------------------------------------------------------------
// selections
struct cut_preselection_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_preselection_s() : lhadaThing(), name("preselection"), count(0), dcount(0) {}
  ~cut_preselection_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(MET("PT") > 200) ) return false;
    if ( !(jetsSR.size() > 0) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_preselection;

struct cut_2jt_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_2jt_s() : lhadaThing(), name("2jt"), count(0), dcount(0) {}
  ~cut_2jt_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(cut_preselection()) ) return false;
    if ( !(jetsSR.size() >= 2) ) return false;
    if ( !(jetsSR[0]("PT") > 200) ) return false;
    if ( !(jetsSR[1]("PT") > 200) ) return false;
    if ( !(dphijNjle3METmin > 0.8) ) return false;
    if ( !(METoversqrtHT > 20) ) return false;
    if ( !(Meff > 2000) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_2jt;

struct cut_4jt_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_4jt_s() : lhadaThing(), name("4jt"), count(0), dcount(0) {}
  ~cut_4jt_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(cut_preselection()) ) return false;
    if ( !(jetsSR.size() >= 4) ) return false;
    if ( !(jetsSR[0]("PT") > 200) ) return false;
    if ( !(jetsSR[1]("PT") > 100) ) return false;
    if ( !(jetsSR[2]("PT") > 100) ) return false;
    if ( !(jetsSR[3]("PT") > 100) ) return false;
    if ( !(dphijNjle3METmin > 0.4) ) return false;
    if ( !(dphijNjgt3METmin > 0.2) ) return false;
    if ( !(aplanarity > 0.04) ) return false;
    if ( !(METovermeff4j > 0.2) ) return false;
    if ( !(Meff > 2200) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_4jt;

struct cut_2jm_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_2jm_s() : lhadaThing(), name("2jm"), count(0), dcount(0) {}
  ~cut_2jm_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(cut_preselection()) ) return false;
    if ( !(jetsSR.size() >= 2) ) return false;
    if ( !(jetsSR[0]("PT") > 300) ) return false;
    if ( !(jetsSR[1]("PT") > 50) ) return false;
    if ( !(dphijNjle3METmin > 0.4) ) return false;
    if ( !(METoversqrtHT > 15) ) return false;
    if ( !(Meff > 1600) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_2jm;

struct cut_2jl_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_2jl_s() : lhadaThing(), name("2jl"), count(0), dcount(0) {}
  ~cut_2jl_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(cut_preselection()) ) return false;
    if ( !(jetsSR.size() >= 2) ) return false;
    if ( !(jetsSR[0]("PT") > 200) ) return false;
    if ( !(jetsSR[1]("PT") > 200) ) return false;
    if ( !(dphijNjle3METmin > 0.8) ) return false;
    if ( !(METoversqrtHT > 15) ) return false;
    if ( !(Meff > 1200) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_2jl;

struct cut_6jt_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_6jt_s() : lhadaThing(), name("6jt"), count(0), dcount(0) {}
  ~cut_6jt_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(cut_preselection()) ) return false;
    if ( !(jetsSR.size() >= 6) ) return false;
    if ( !(jetsSR[0]("PT") > 200) ) return false;
    if ( !(jetsSR[1]("PT") > 100) ) return false;
    if ( !(jetsSR[2]("PT") > 100) ) return false;
    if ( !(jetsSR[3]("PT") > 100) ) return false;
    if ( !(jetsSR[4]("PT") > 50) ) return false;
    if ( !(jetsSR[5]("PT") > 50) ) return false;
    if ( !(dphijNjle3METmin > 0.4) ) return false;
    if ( !(dphijNjgt3METmin > 0.2) ) return false;
    if ( !(aplanarity > 0.04) ) return false;
    if ( !(METovermeff6j > 0.2) ) return false;
    if ( !(Meff > 2000) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_6jt;

struct cut_6jm_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_6jm_s() : lhadaThing(), name("6jm"), count(0), dcount(0) {}
  ~cut_6jm_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(cut_preselection()) ) return false;
    if ( !(jetsSR.size() >= 6) ) return false;
    if ( !(jetsSR[0]("PT") > 200) ) return false;
    if ( !(jetsSR[1]("PT") > 100) ) return false;
    if ( !(jetsSR[2]("PT") > 100) ) return false;
    if ( !(jetsSR[3]("PT") > 100) ) return false;
    if ( !(jetsSR[4]("PT") > 50) ) return false;
    if ( !(jetsSR[5]("PT") > 50) ) return false;
    if ( !(dphijNjle3METmin > 0.4) ) return false;
    if ( !(dphijNjgt3METmin > 0.2) ) return false;
    if ( !(aplanarity > 0.04) ) return false;
    if ( !(METovermeff6j > 0.25) ) return false;
    if ( !(Meff > 1600) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_6jm;

struct cut_5j_s : public lhadaThing
{
  std::string name;
  double count;
  double dcount;
  cut_5j_s() : lhadaThing(), name("5j"), count(0), dcount(0) {}
  ~cut_5j_s() {}
  void summary()
  {
    printf("\t%-24s %10.3f (%10.3f)\n",
           name.c_str(), count, sqrt(dcount));
  }
  bool operator()(double weight=1)
  {
    if ( !(cut_preselection()) ) return false;
    if ( !(jetsSR.size() >= 5) ) return false;
    if ( !(jetsSR[0]("PT") > 200) ) return false;
    if ( !(jetsSR[1]("PT") > 100) ) return false;
    if ( !(jetsSR[2]("PT") > 100) ) return false;
    if ( !(jetsSR[3]("PT") > 100) ) return false;
    if ( !(jetsSR[4]("PT") > 50) ) return false;
    if ( !(dphijNjle3METmin > 0.4) ) return false;
    if ( !(dphijNjgt3METmin > 0.2) ) return false;
    if ( !(aplanarity > 0.04) ) return false;
    if ( !(METovermeff5j > 0.25) ) return false;
    if ( !(Meff > 1600) ) return false;
    count  += weight;
    dcount += weight * weight;
    return true;
  }
} cut_5j;


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

  // -------------------------------------------------------------------------
  // Loop over events
  // ------------------------------------------------------------------

  for(int entry=0; entry < nevents; entry++)
    {
      // read an event into event buffer
      ev.read(entry);

        // get external objects
        adapter(ev, "Delphes_Electron", 	Delphes_Electron);
        adapter(ev, "Delphes_Jet", 	Delphes_Jet);
        adapter(ev, "Delphes_MissingET", 	Delphes_MissingET);
        adapter(ev, "Delphes_Muon", 	Delphes_Muon);

      // create internal objects
      object_muons();
      object_electrons();
      object_jets();
      object_MET();
      object_bjets();
      object_cleanjets();
      object_cleanelectrons();
      object_verycleanelectrons();
      object_jetsSR();
      object_cleanmuons();

      // compute event level variables
      Meff	= lha_Meff(jetsSR, MET);
      METoversqrtHT	= lha_METoversqrtHT(jetsSR, MET);
      dphijNjle3METmin	= lha_dphijNjle3METmin(jetsSR, MET);
      METovermeff5j	= lha_METovermeffNJ(jetsSR, 5, MET);
      dphijNjgt3METmin	= lha_dphijNjgt3METmin(jetsSR, MET);
      aplanarity	= lha_aplanarity(jetsSR);
      METovermeff4j	= lha_METovermeffNJ(jetsSR, 4, MET);
      METovermeff2j	= lha_METovermeffNJ(jetsSR, 2, MET);
      METovermeff6j	= lha_METovermeffNJ(jetsSR, 6, MET);

      // apply event level selections
      cut_preselection();
      cut_2jt();
      cut_4jt();
      cut_2jm();
      cut_2jl();
      cut_6jt();
      cut_6jm();
      cut_5j();

    }   
  // count summary
  vector<lhadaThing*> cut;
  cut.push_back(&cut_preselection);
  cut.push_back(&cut_2jt);
  cut.push_back(&cut_4jt);
  cut.push_back(&cut_2jm);
  cut.push_back(&cut_2jl);
  cut.push_back(&cut_6jt);
  cut.push_back(&cut_6jm);
  cut.push_back(&cut_5j);

  std::cout << "event counts" << std::endl;
  for(size_t c=0; c < cut.size(); c++)
    cut[c]->summary();

  ev.close();
  of.close();
  return 0;
}
