#ifndef EVENTBUFFER_H
#define EVENTBUFFER_H
//----------------------------------------------------------------------------
// File:        eventBuffer.h
// Description: Analyzer header for ntuples created by TheNtupleMaker
// Created:     Sat Mar 23 17:39:05 2019 by mkanalyzer.py v2.0.1 23-Mar-2019
// Author:      Shakespeare's ghost
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <cassert>
#include "treestream.h"

struct eventBuffer
{
  //--------------------------------------------------------------------------
  // --- Declare variables
  //--------------------------------------------------------------------------
  std::vector<int>	Electron_Charge;
  std::vector<float>	Electron_EhadOverEem;
  std::vector<float>	Electron_Eta;
  std::vector<float>	Electron_IsolationVar;
  std::vector<float>	Electron_IsolationVarRhoCorr;
  std::vector<float>	Electron_PT;
  std::vector<float>	Electron_Phi;
  std::vector<float>	Electron_SumPt;
  std::vector<float>	Electron_SumPtCharged;
  std::vector<float>	Electron_SumPtChargedPU;
  std::vector<float>	Electron_SumPtNeutral;
  std::vector<float>	Electron_T;
  std::vector<unsigned int>	Electron_fBits;
  std::vector<unsigned int>	Electron_fUniqueID;
  std::vector<unsigned int>	Jet_Area_fBits;
  std::vector<double>	Jet_Area_fE;
  std::vector<unsigned int>	Jet_Area_fP_fBits;
  std::vector<unsigned int>	Jet_Area_fP_fUniqueID;
  std::vector<double>	Jet_Area_fP_fX;
  std::vector<double>	Jet_Area_fP_fY;
  std::vector<double>	Jet_Area_fP_fZ;
  std::vector<unsigned int>	Jet_Area_fUniqueID;
  std::vector<unsigned int>	Jet_BTag;
  std::vector<unsigned int>	Jet_BTagAlgo;
  std::vector<unsigned int>	Jet_BTagPhys;
  std::vector<float>	Jet_Beta;
  std::vector<float>	Jet_BetaStar;
  std::vector<int>	Jet_Charge;
  std::vector<float>	Jet_DeltaEta;
  std::vector<float>	Jet_DeltaPhi;
  std::vector<float>	Jet_EhadOverEem;
  std::vector<float>	Jet_Eta;
  std::vector<unsigned int>	Jet_Flavor;
  std::vector<unsigned int>	Jet_FlavorAlgo;
  std::vector<unsigned int>	Jet_FlavorPhys;
  std::vector<float>	Jet_Mass;
  std::vector<float>	Jet_MeanSqDeltaR;
  std::vector<int>	Jet_NCharged;
  std::vector<int>	Jet_NNeutrals;
  std::vector<int>	Jet_NSubJetsPruned;
  std::vector<int>	Jet_NSubJetsSoftDropped;
  std::vector<int>	Jet_NSubJetsTrimmed;
  std::vector<float>	Jet_PT;
  std::vector<float>	Jet_PTD;
  std::vector<float>	Jet_Phi;
  std::vector<float>	Jet_T;
  std::vector<unsigned int>	Jet_TauTag;
  std::vector<unsigned int>	Jet_fBits;
  std::vector<unsigned int>	Jet_fUniqueID;
  std::vector<int>	Muon_Charge;
  std::vector<float>	Muon_Eta;
  std::vector<float>	Muon_IsolationVar;
  std::vector<float>	Muon_IsolationVarRhoCorr;
  std::vector<float>	Muon_PT;
  std::vector<float>	Muon_Phi;
  std::vector<float>	Muon_SumPt;
  std::vector<float>	Muon_SumPtCharged;
  std::vector<float>	Muon_SumPtChargedPU;
  std::vector<float>	Muon_SumPtNeutral;
  std::vector<float>	Muon_T;
  std::vector<unsigned int>	Muon_fBits;
  std::vector<unsigned int>	Muon_fUniqueID;
  std::vector<float>	Photon_E;
  std::vector<float>	Photon_EhadOverEem;
  std::vector<float>	Photon_Eta;
  std::vector<float>	Photon_IsolationVar;
  std::vector<float>	Photon_IsolationVarRhoCorr;
  std::vector<float>	Photon_PT;
  std::vector<float>	Photon_Phi;
  std::vector<float>	Photon_SumPt;
  std::vector<float>	Photon_SumPtCharged;
  std::vector<float>	Photon_SumPtChargedPU;
  std::vector<float>	Photon_SumPtNeutral;
  std::vector<float>	Photon_T;
  std::vector<unsigned int>	Photon_fBits;
  std::vector<unsigned int>	Photon_fUniqueID;

  int	MissingET_;
  int	Photon_;
  int	Event_;
  int	Jet_;
  int	Muon_;
  int	Electron_;

  int	Electron_size;
  float	Event_AlphaQCD;
  float	Event_AlphaQED;
  int	Event_ID1;
  int	Event_ID2;
  int	Event_MPI;
  long	Event_Number;
  float	Event_PDF1;
  float	Event_PDF2;
  float	Event_ProcTime;
  int	Event_ProcessID;
  float	Event_ReadTime;
  float	Event_Scale;
  float	Event_ScalePDF;
  float	Event_Weight;
  float	Event_X1;
  float	Event_X2;
  unsigned int	Event_fBits;
  unsigned int	Event_fUniqueID;
  int	Event_size;
  int	Jet_size;
  float	MissingET_Eta;
  float	MissingET_MET;
  float	MissingET_Phi;
  unsigned int	MissingET_fBits;
  unsigned int	MissingET_fUniqueID;
  int	MissingET_size;
  int	Muon_size;
  int	Photon_size;

  //--------------------------------------------------------------------------
  // --- Structs can be filled by calling fill(), or individual fill
  // --- methods, e.g., fillElectrons()
  // --- after the call to read(...)
  //----------- --------------------------------------------------------------
  struct Electron_s
  {
    int	Charge;
    float	EhadOverEem;
    float	Eta;
    float	IsolationVar;
    float	IsolationVarRhoCorr;
    float	PT;
    float	Phi;
    float	SumPt;
    float	SumPtCharged;
    float	SumPtChargedPU;
    float	SumPtNeutral;
    float	T;
    unsigned int	fBits;
    unsigned int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Electron" << std::endl;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "EhadOverEem", ( double)EhadOverEem); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "IsolationVar", ( double)IsolationVar); os << r;
      sprintf(r, "  %-32s: %f\n", "IsolationVarRhoCorr", ( double)IsolationVarRhoCorr); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPt", ( double)SumPt); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtCharged", ( double)SumPtCharged); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtChargedPU", ( double)SumPtChargedPU); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtNeutral", ( double)SumPtNeutral); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct Jet_s
  {
    unsigned int	Area_fBits;
    double	Area_fE;
    unsigned int	Area_fP_fBits;
    unsigned int	Area_fP_fUniqueID;
    double	Area_fP_fX;
    double	Area_fP_fY;
    double	Area_fP_fZ;
    unsigned int	Area_fUniqueID;
    unsigned int	BTag;
    unsigned int	BTagAlgo;
    unsigned int	BTagPhys;
    float	Beta;
    float	BetaStar;
    int	Charge;
    float	DeltaEta;
    float	DeltaPhi;
    float	EhadOverEem;
    float	Eta;
    unsigned int	Flavor;
    unsigned int	FlavorAlgo;
    unsigned int	FlavorPhys;
    float	Mass;
    float	MeanSqDeltaR;
    int	NCharged;
    int	NNeutrals;
    int	NSubJetsPruned;
    int	NSubJetsSoftDropped;
    int	NSubJetsTrimmed;
    float	PT;
    float	PTD;
    float	Phi;
    float	T;
    unsigned int	TauTag;
    unsigned int	fBits;
    unsigned int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Jet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "Area_fBits", ( double)Area_fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "Area_fE", ( double)Area_fE); os << r;
      sprintf(r, "  %-32s: %f\n", "Area_fP_fBits", ( double)Area_fP_fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "Area_fP_fUniqueID", ( double)Area_fP_fUniqueID); os << r;
      sprintf(r, "  %-32s: %f\n", "Area_fP_fX", ( double)Area_fP_fX); os << r;
      sprintf(r, "  %-32s: %f\n", "Area_fP_fY", ( double)Area_fP_fY); os << r;
      sprintf(r, "  %-32s: %f\n", "Area_fP_fZ", ( double)Area_fP_fZ); os << r;
      sprintf(r, "  %-32s: %f\n", "Area_fUniqueID", ( double)Area_fUniqueID); os << r;
      sprintf(r, "  %-32s: %f\n", "BTag", ( double)BTag); os << r;
      sprintf(r, "  %-32s: %f\n", "BTagAlgo", ( double)BTagAlgo); os << r;
      sprintf(r, "  %-32s: %f\n", "BTagPhys", ( double)BTagPhys); os << r;
      sprintf(r, "  %-32s: %f\n", "Beta", ( double)Beta); os << r;
      sprintf(r, "  %-32s: %f\n", "BetaStar", ( double)BetaStar); os << r;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaEta", ( double)DeltaEta); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaPhi", ( double)DeltaPhi); os << r;
      sprintf(r, "  %-32s: %f\n", "EhadOverEem", ( double)EhadOverEem); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "Flavor", ( double)Flavor); os << r;
      sprintf(r, "  %-32s: %f\n", "FlavorAlgo", ( double)FlavorAlgo); os << r;
      sprintf(r, "  %-32s: %f\n", "FlavorPhys", ( double)FlavorPhys); os << r;
      sprintf(r, "  %-32s: %f\n", "Mass", ( double)Mass); os << r;
      sprintf(r, "  %-32s: %f\n", "MeanSqDeltaR", ( double)MeanSqDeltaR); os << r;
      sprintf(r, "  %-32s: %f\n", "NCharged", ( double)NCharged); os << r;
      sprintf(r, "  %-32s: %f\n", "NNeutrals", ( double)NNeutrals); os << r;
      sprintf(r, "  %-32s: %f\n", "NSubJetsPruned", ( double)NSubJetsPruned); os << r;
      sprintf(r, "  %-32s: %f\n", "NSubJetsSoftDropped", ( double)NSubJetsSoftDropped); os << r;
      sprintf(r, "  %-32s: %f\n", "NSubJetsTrimmed", ( double)NSubJetsTrimmed); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "PTD", ( double)PTD); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "TauTag", ( double)TauTag); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct Muon_s
  {
    int	Charge;
    float	Eta;
    float	IsolationVar;
    float	IsolationVarRhoCorr;
    float	PT;
    float	Phi;
    float	SumPt;
    float	SumPtCharged;
    float	SumPtChargedPU;
    float	SumPtNeutral;
    float	T;
    unsigned int	fBits;
    unsigned int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Muon" << std::endl;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "IsolationVar", ( double)IsolationVar); os << r;
      sprintf(r, "  %-32s: %f\n", "IsolationVarRhoCorr", ( double)IsolationVarRhoCorr); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPt", ( double)SumPt); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtCharged", ( double)SumPtCharged); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtChargedPU", ( double)SumPtChargedPU); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtNeutral", ( double)SumPtNeutral); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct Photon_s
  {
    float	E;
    float	EhadOverEem;
    float	Eta;
    float	IsolationVar;
    float	IsolationVarRhoCorr;
    float	PT;
    float	Phi;
    float	SumPt;
    float	SumPtCharged;
    float	SumPtChargedPU;
    float	SumPtNeutral;
    float	T;
    unsigned int	fBits;
    unsigned int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Photon" << std::endl;
      sprintf(r, "  %-32s: %f\n", "E", ( double)E); os << r;
      sprintf(r, "  %-32s: %f\n", "EhadOverEem", ( double)EhadOverEem); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "IsolationVar", ( double)IsolationVar); os << r;
      sprintf(r, "  %-32s: %f\n", "IsolationVarRhoCorr", ( double)IsolationVarRhoCorr); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPt", ( double)SumPt); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtCharged", ( double)SumPtCharged); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtChargedPU", ( double)SumPtChargedPU); os << r;
      sprintf(r, "  %-32s: %f\n", "SumPtNeutral", ( double)SumPtNeutral); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };


  void fillElectrons()
  {
    Electron.resize(Electron_Charge.size());
    for(unsigned int i=0; i < Electron.size(); ++i)
      {
        Electron[i].Charge	= Electron_Charge[i];
        Electron[i].EhadOverEem	= Electron_EhadOverEem[i];
        Electron[i].Eta	= Electron_Eta[i];
        Electron[i].IsolationVar	= Electron_IsolationVar[i];
        Electron[i].IsolationVarRhoCorr	= Electron_IsolationVarRhoCorr[i];
        Electron[i].PT	= Electron_PT[i];
        Electron[i].Phi	= Electron_Phi[i];
        Electron[i].SumPt	= Electron_SumPt[i];
        Electron[i].SumPtCharged	= Electron_SumPtCharged[i];
        Electron[i].SumPtChargedPU	= Electron_SumPtChargedPU[i];
        Electron[i].SumPtNeutral	= Electron_SumPtNeutral[i];
        Electron[i].T	= Electron_T[i];
        Electron[i].fBits	= Electron_fBits[i];
        Electron[i].fUniqueID	= Electron_fUniqueID[i];
      }
  }

  void fillJets()
  {
    Jet.resize(Jet_Area_fBits.size());
    for(unsigned int i=0; i < Jet.size(); ++i)
      {
        Jet[i].Area_fBits	= Jet_Area_fBits[i];
        Jet[i].Area_fE	= Jet_Area_fE[i];
        Jet[i].Area_fP_fBits	= Jet_Area_fP_fBits[i];
        Jet[i].Area_fP_fUniqueID	= Jet_Area_fP_fUniqueID[i];
        Jet[i].Area_fP_fX	= Jet_Area_fP_fX[i];
        Jet[i].Area_fP_fY	= Jet_Area_fP_fY[i];
        Jet[i].Area_fP_fZ	= Jet_Area_fP_fZ[i];
        Jet[i].Area_fUniqueID	= Jet_Area_fUniqueID[i];
        Jet[i].BTag	= Jet_BTag[i];
        Jet[i].BTagAlgo	= Jet_BTagAlgo[i];
        Jet[i].BTagPhys	= Jet_BTagPhys[i];
        Jet[i].Beta	= Jet_Beta[i];
        Jet[i].BetaStar	= Jet_BetaStar[i];
        Jet[i].Charge	= Jet_Charge[i];
        Jet[i].DeltaEta	= Jet_DeltaEta[i];
        Jet[i].DeltaPhi	= Jet_DeltaPhi[i];
        Jet[i].EhadOverEem	= Jet_EhadOverEem[i];
        Jet[i].Eta	= Jet_Eta[i];
        Jet[i].Flavor	= Jet_Flavor[i];
        Jet[i].FlavorAlgo	= Jet_FlavorAlgo[i];
        Jet[i].FlavorPhys	= Jet_FlavorPhys[i];
        Jet[i].Mass	= Jet_Mass[i];
        Jet[i].MeanSqDeltaR	= Jet_MeanSqDeltaR[i];
        Jet[i].NCharged	= Jet_NCharged[i];
        Jet[i].NNeutrals	= Jet_NNeutrals[i];
        Jet[i].NSubJetsPruned	= Jet_NSubJetsPruned[i];
        Jet[i].NSubJetsSoftDropped	= Jet_NSubJetsSoftDropped[i];
        Jet[i].NSubJetsTrimmed	= Jet_NSubJetsTrimmed[i];
        Jet[i].PT	= Jet_PT[i];
        Jet[i].PTD	= Jet_PTD[i];
        Jet[i].Phi	= Jet_Phi[i];
        Jet[i].T	= Jet_T[i];
        Jet[i].TauTag	= Jet_TauTag[i];
        Jet[i].fBits	= Jet_fBits[i];
        Jet[i].fUniqueID	= Jet_fUniqueID[i];
      }
  }

  void fillMuons()
  {
    Muon.resize(Muon_Charge.size());
    for(unsigned int i=0; i < Muon.size(); ++i)
      {
        Muon[i].Charge	= Muon_Charge[i];
        Muon[i].Eta	= Muon_Eta[i];
        Muon[i].IsolationVar	= Muon_IsolationVar[i];
        Muon[i].IsolationVarRhoCorr	= Muon_IsolationVarRhoCorr[i];
        Muon[i].PT	= Muon_PT[i];
        Muon[i].Phi	= Muon_Phi[i];
        Muon[i].SumPt	= Muon_SumPt[i];
        Muon[i].SumPtCharged	= Muon_SumPtCharged[i];
        Muon[i].SumPtChargedPU	= Muon_SumPtChargedPU[i];
        Muon[i].SumPtNeutral	= Muon_SumPtNeutral[i];
        Muon[i].T	= Muon_T[i];
        Muon[i].fBits	= Muon_fBits[i];
        Muon[i].fUniqueID	= Muon_fUniqueID[i];
      }
  }

  void fillPhotons()
  {
    Photon.resize(Photon_E.size());
    for(unsigned int i=0; i < Photon.size(); ++i)
      {
        Photon[i].E	= Photon_E[i];
        Photon[i].EhadOverEem	= Photon_EhadOverEem[i];
        Photon[i].Eta	= Photon_Eta[i];
        Photon[i].IsolationVar	= Photon_IsolationVar[i];
        Photon[i].IsolationVarRhoCorr	= Photon_IsolationVarRhoCorr[i];
        Photon[i].PT	= Photon_PT[i];
        Photon[i].Phi	= Photon_Phi[i];
        Photon[i].SumPt	= Photon_SumPt[i];
        Photon[i].SumPtCharged	= Photon_SumPtCharged[i];
        Photon[i].SumPtChargedPU	= Photon_SumPtChargedPU[i];
        Photon[i].SumPtNeutral	= Photon_SumPtNeutral[i];
        Photon[i].T	= Photon_T[i];
        Photon[i].fBits	= Photon_fBits[i];
        Photon[i].fUniqueID	= Photon_fUniqueID[i];
      }
  }


  std::vector<eventBuffer::Electron_s> Electron;
  std::vector<eventBuffer::Jet_s> Jet;
  std::vector<eventBuffer::Muon_s> Muon;
  std::vector<eventBuffer::Photon_s> Photon;

  void fillObjects()
  {
    fillElectrons();
    fillJets();
    fillMuons();
    fillPhotons();
  }

   //--------------------------------------------------------------------------
  // Save objects for which the select function was called
  void saveObjects()
  {
    int n = 0;

    n = 0;
    try
      {
         n = indexmap["Electron"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Electron"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Electron_Charge[i]	= Electron_Charge[j];
            Electron_EhadOverEem[i]	= Electron_EhadOverEem[j];
            Electron_Eta[i]	= Electron_Eta[j];
            Electron_IsolationVar[i]	= Electron_IsolationVar[j];
            Electron_IsolationVarRhoCorr[i]	= Electron_IsolationVarRhoCorr[j];
            Electron_PT[i]	= Electron_PT[j];
            Electron_Phi[i]	= Electron_Phi[j];
            Electron_SumPt[i]	= Electron_SumPt[j];
            Electron_SumPtCharged[i]	= Electron_SumPtCharged[j];
            Electron_SumPtChargedPU[i]	= Electron_SumPtChargedPU[j];
            Electron_SumPtNeutral[i]	= Electron_SumPtNeutral[j];
            Electron_T[i]	= Electron_T[j];
            Electron_fBits[i]	= Electron_fBits[j];
            Electron_fUniqueID[i]	= Electron_fUniqueID[j];
          }
      }
    Electron_ = n;

    n = 0;
    try
      {
         n = indexmap["Jet"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Jet"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Jet_Area_fBits[i]	= Jet_Area_fBits[j];
            Jet_Area_fE[i]	= Jet_Area_fE[j];
            Jet_Area_fP_fBits[i]	= Jet_Area_fP_fBits[j];
            Jet_Area_fP_fUniqueID[i]	= Jet_Area_fP_fUniqueID[j];
            Jet_Area_fP_fX[i]	= Jet_Area_fP_fX[j];
            Jet_Area_fP_fY[i]	= Jet_Area_fP_fY[j];
            Jet_Area_fP_fZ[i]	= Jet_Area_fP_fZ[j];
            Jet_Area_fUniqueID[i]	= Jet_Area_fUniqueID[j];
            Jet_BTag[i]	= Jet_BTag[j];
            Jet_BTagAlgo[i]	= Jet_BTagAlgo[j];
            Jet_BTagPhys[i]	= Jet_BTagPhys[j];
            Jet_Beta[i]	= Jet_Beta[j];
            Jet_BetaStar[i]	= Jet_BetaStar[j];
            Jet_Charge[i]	= Jet_Charge[j];
            Jet_DeltaEta[i]	= Jet_DeltaEta[j];
            Jet_DeltaPhi[i]	= Jet_DeltaPhi[j];
            Jet_EhadOverEem[i]	= Jet_EhadOverEem[j];
            Jet_Eta[i]	= Jet_Eta[j];
            Jet_Flavor[i]	= Jet_Flavor[j];
            Jet_FlavorAlgo[i]	= Jet_FlavorAlgo[j];
            Jet_FlavorPhys[i]	= Jet_FlavorPhys[j];
            Jet_Mass[i]	= Jet_Mass[j];
            Jet_MeanSqDeltaR[i]	= Jet_MeanSqDeltaR[j];
            Jet_NCharged[i]	= Jet_NCharged[j];
            Jet_NNeutrals[i]	= Jet_NNeutrals[j];
            Jet_NSubJetsPruned[i]	= Jet_NSubJetsPruned[j];
            Jet_NSubJetsSoftDropped[i]	= Jet_NSubJetsSoftDropped[j];
            Jet_NSubJetsTrimmed[i]	= Jet_NSubJetsTrimmed[j];
            Jet_PT[i]	= Jet_PT[j];
            Jet_PTD[i]	= Jet_PTD[j];
            Jet_Phi[i]	= Jet_Phi[j];
            Jet_T[i]	= Jet_T[j];
            Jet_TauTag[i]	= Jet_TauTag[j];
            Jet_fBits[i]	= Jet_fBits[j];
            Jet_fUniqueID[i]	= Jet_fUniqueID[j];
          }
      }
    Jet_ = n;

    n = 0;
    try
      {
         n = indexmap["Muon"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Muon"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Muon_Charge[i]	= Muon_Charge[j];
            Muon_Eta[i]	= Muon_Eta[j];
            Muon_IsolationVar[i]	= Muon_IsolationVar[j];
            Muon_IsolationVarRhoCorr[i]	= Muon_IsolationVarRhoCorr[j];
            Muon_PT[i]	= Muon_PT[j];
            Muon_Phi[i]	= Muon_Phi[j];
            Muon_SumPt[i]	= Muon_SumPt[j];
            Muon_SumPtCharged[i]	= Muon_SumPtCharged[j];
            Muon_SumPtChargedPU[i]	= Muon_SumPtChargedPU[j];
            Muon_SumPtNeutral[i]	= Muon_SumPtNeutral[j];
            Muon_T[i]	= Muon_T[j];
            Muon_fBits[i]	= Muon_fBits[j];
            Muon_fUniqueID[i]	= Muon_fUniqueID[j];
          }
      }
    Muon_ = n;

    n = 0;
    try
      {
         n = indexmap["Photon"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Photon"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Photon_E[i]	= Photon_E[j];
            Photon_EhadOverEem[i]	= Photon_EhadOverEem[j];
            Photon_Eta[i]	= Photon_Eta[j];
            Photon_IsolationVar[i]	= Photon_IsolationVar[j];
            Photon_IsolationVarRhoCorr[i]	= Photon_IsolationVarRhoCorr[j];
            Photon_PT[i]	= Photon_PT[j];
            Photon_Phi[i]	= Photon_Phi[j];
            Photon_SumPt[i]	= Photon_SumPt[j];
            Photon_SumPtCharged[i]	= Photon_SumPtCharged[j];
            Photon_SumPtChargedPU[i]	= Photon_SumPtChargedPU[j];
            Photon_SumPtNeutral[i]	= Photon_SumPtNeutral[j];
            Photon_T[i]	= Photon_T[j];
            Photon_fBits[i]	= Photon_fBits[j];
            Photon_fUniqueID[i]	= Photon_fUniqueID[j];
          }
      }
    Photon_ = n;
  }

  //--------------------------------------------------------------------------
  // A read-only buffer 
  eventBuffer() : input(0), output(0), choose(std::map<std::string, bool>()) {}
  eventBuffer(itreestream& stream, std::string varlist="")
  : input(&stream),
    output(0),
    choose(std::map<std::string, bool>())
  {
    if ( !input->good() ) 
      {
        std::cout << "eventBuffer - please check stream!" 
                  << std::endl;
	    exit(0);
      }

    initBuffers();
    
    // default is to select all branches      
    bool DEFAULT = varlist == "";
    choose["Electron.Charge"]	= DEFAULT;
    choose["Electron.EhadOverEem"]	= DEFAULT;
    choose["Electron.Eta"]	= DEFAULT;
    choose["Electron.IsolationVar"]	= DEFAULT;
    choose["Electron.IsolationVarRhoCorr"]	= DEFAULT;
    choose["Electron.PT"]	= DEFAULT;
    choose["Electron.Phi"]	= DEFAULT;
    choose["Electron.SumPt"]	= DEFAULT;
    choose["Electron.SumPtCharged"]	= DEFAULT;
    choose["Electron.SumPtChargedPU"]	= DEFAULT;
    choose["Electron.SumPtNeutral"]	= DEFAULT;
    choose["Electron.T"]	= DEFAULT;
    choose["Electron.fBits"]	= DEFAULT;
    choose["Electron.fUniqueID"]	= DEFAULT;
    choose["Electron_size"]	= DEFAULT;
    choose["Event.AlphaQCD"]	= DEFAULT;
    choose["Event.AlphaQED"]	= DEFAULT;
    choose["Event.ID1"]	= DEFAULT;
    choose["Event.ID2"]	= DEFAULT;
    choose["Event.MPI"]	= DEFAULT;
    choose["Event.Number"]	= DEFAULT;
    choose["Event.PDF1"]	= DEFAULT;
    choose["Event.PDF2"]	= DEFAULT;
    choose["Event.ProcTime"]	= DEFAULT;
    choose["Event.ProcessID"]	= DEFAULT;
    choose["Event.ReadTime"]	= DEFAULT;
    choose["Event.Scale"]	= DEFAULT;
    choose["Event.ScalePDF"]	= DEFAULT;
    choose["Event.Weight"]	= DEFAULT;
    choose["Event.X1"]	= DEFAULT;
    choose["Event.X2"]	= DEFAULT;
    choose["Event.fBits"]	= DEFAULT;
    choose["Event.fUniqueID"]	= DEFAULT;
    choose["Event_size"]	= DEFAULT;
    choose["Jet.Area.fBits"]	= DEFAULT;
    choose["Jet.Area.fE"]	= DEFAULT;
    choose["Jet.Area.fP.fBits"]	= DEFAULT;
    choose["Jet.Area.fP.fUniqueID"]	= DEFAULT;
    choose["Jet.Area.fP.fX"]	= DEFAULT;
    choose["Jet.Area.fP.fY"]	= DEFAULT;
    choose["Jet.Area.fP.fZ"]	= DEFAULT;
    choose["Jet.Area.fUniqueID"]	= DEFAULT;
    choose["Jet.BTag"]	= DEFAULT;
    choose["Jet.BTagAlgo"]	= DEFAULT;
    choose["Jet.BTagPhys"]	= DEFAULT;
    choose["Jet.Beta"]	= DEFAULT;
    choose["Jet.BetaStar"]	= DEFAULT;
    choose["Jet.Charge"]	= DEFAULT;
    choose["Jet.DeltaEta"]	= DEFAULT;
    choose["Jet.DeltaPhi"]	= DEFAULT;
    choose["Jet.EhadOverEem"]	= DEFAULT;
    choose["Jet.Eta"]	= DEFAULT;
    choose["Jet.Flavor"]	= DEFAULT;
    choose["Jet.FlavorAlgo"]	= DEFAULT;
    choose["Jet.FlavorPhys"]	= DEFAULT;
    choose["Jet.Mass"]	= DEFAULT;
    choose["Jet.MeanSqDeltaR"]	= DEFAULT;
    choose["Jet.NCharged"]	= DEFAULT;
    choose["Jet.NNeutrals"]	= DEFAULT;
    choose["Jet.NSubJetsPruned"]	= DEFAULT;
    choose["Jet.NSubJetsSoftDropped"]	= DEFAULT;
    choose["Jet.NSubJetsTrimmed"]	= DEFAULT;
    choose["Jet.PT"]	= DEFAULT;
    choose["Jet.PTD"]	= DEFAULT;
    choose["Jet.Phi"]	= DEFAULT;
    choose["Jet.T"]	= DEFAULT;
    choose["Jet.TauTag"]	= DEFAULT;
    choose["Jet.fBits"]	= DEFAULT;
    choose["Jet.fUniqueID"]	= DEFAULT;
    choose["Jet_size"]	= DEFAULT;
    choose["MissingET.Eta"]	= DEFAULT;
    choose["MissingET.MET"]	= DEFAULT;
    choose["MissingET.Phi"]	= DEFAULT;
    choose["MissingET.fBits"]	= DEFAULT;
    choose["MissingET.fUniqueID"]	= DEFAULT;
    choose["MissingET_size"]	= DEFAULT;
    choose["Muon.Charge"]	= DEFAULT;
    choose["Muon.Eta"]	= DEFAULT;
    choose["Muon.IsolationVar"]	= DEFAULT;
    choose["Muon.IsolationVarRhoCorr"]	= DEFAULT;
    choose["Muon.PT"]	= DEFAULT;
    choose["Muon.Phi"]	= DEFAULT;
    choose["Muon.SumPt"]	= DEFAULT;
    choose["Muon.SumPtCharged"]	= DEFAULT;
    choose["Muon.SumPtChargedPU"]	= DEFAULT;
    choose["Muon.SumPtNeutral"]	= DEFAULT;
    choose["Muon.T"]	= DEFAULT;
    choose["Muon.fBits"]	= DEFAULT;
    choose["Muon.fUniqueID"]	= DEFAULT;
    choose["Muon_size"]	= DEFAULT;
    choose["Photon.E"]	= DEFAULT;
    choose["Photon.EhadOverEem"]	= DEFAULT;
    choose["Photon.Eta"]	= DEFAULT;
    choose["Photon.IsolationVar"]	= DEFAULT;
    choose["Photon.IsolationVarRhoCorr"]	= DEFAULT;
    choose["Photon.PT"]	= DEFAULT;
    choose["Photon.Phi"]	= DEFAULT;
    choose["Photon.SumPt"]	= DEFAULT;
    choose["Photon.SumPtCharged"]	= DEFAULT;
    choose["Photon.SumPtChargedPU"]	= DEFAULT;
    choose["Photon.SumPtNeutral"]	= DEFAULT;
    choose["Photon.T"]	= DEFAULT;
    choose["Photon.fBits"]	= DEFAULT;
    choose["Photon.fUniqueID"]	= DEFAULT;
    choose["Photon_size"]	= DEFAULT;

    if ( DEFAULT )
      {
        std::cout << std::endl
                  << "eventBuffer - All branches selected"
                  << std::endl;
      }
    else
      {
        std::cout << "eventBuffer - branches selected:"
                  << std::endl;      
        std::istringstream sin(varlist);
        while ( sin )
          {
            std::string key;
            sin >> key;
            if ( sin )
              {
                if ( choose.find(key) != choose.end() )
                  {
                    choose[key] = true;
                    std::cout << "	" << key << std::endl;
                  }
                else
                  {
                    std::cout << "	** error ** unknown branch: "
                              << key
                              << std::endl
                              << "Please fix and try again. Bye!"
                              << std::endl;
                    exit(0);
                  }
              }
          }
      }
    if ( choose["Electron.Charge"] )
      input->select("Delphes/Electron.Charge", 	Electron_Charge);
    if ( choose["Electron.EhadOverEem"] )
      input->select("Delphes/Electron.EhadOverEem", 	Electron_EhadOverEem);
    if ( choose["Electron.Eta"] )
      input->select("Delphes/Electron.Eta", 	Electron_Eta);
    if ( choose["Electron.IsolationVar"] )
      input->select("Delphes/Electron.IsolationVar",
                     Electron_IsolationVar);
    if ( choose["Electron.IsolationVarRhoCorr"] )
      input->select("Delphes/Electron.IsolationVarRhoCorr",
                     Electron_IsolationVarRhoCorr);
    if ( choose["Electron.PT"] )
      input->select("Delphes/Electron.PT", 	Electron_PT);
    if ( choose["Electron.Phi"] )
      input->select("Delphes/Electron.Phi", 	Electron_Phi);
    if ( choose["Electron.SumPt"] )
      input->select("Delphes/Electron.SumPt", 	Electron_SumPt);
    if ( choose["Electron.SumPtCharged"] )
      input->select("Delphes/Electron.SumPtCharged",
                     Electron_SumPtCharged);
    if ( choose["Electron.SumPtChargedPU"] )
      input->select("Delphes/Electron.SumPtChargedPU",
                     Electron_SumPtChargedPU);
    if ( choose["Electron.SumPtNeutral"] )
      input->select("Delphes/Electron.SumPtNeutral",
                     Electron_SumPtNeutral);
    if ( choose["Electron.T"] )
      input->select("Delphes/Electron.T", 	Electron_T);
    if ( choose["Electron.fBits"] )
      input->select("Delphes/Electron.fBits", 	Electron_fBits);
    if ( choose["Electron.fUniqueID"] )
      input->select("Delphes/Electron.fUniqueID", 	Electron_fUniqueID);
    if ( choose["Electron_size"] )
      input->select("Delphes/Electron_size", 	Electron_size);
    if ( choose["Event.AlphaQCD"] )
      input->select("Delphes/Event.AlphaQCD", 	Event_AlphaQCD);
    if ( choose["Event.AlphaQED"] )
      input->select("Delphes/Event.AlphaQED", 	Event_AlphaQED);
    if ( choose["Event.ID1"] )
      input->select("Delphes/Event.ID1", 	Event_ID1);
    if ( choose["Event.ID2"] )
      input->select("Delphes/Event.ID2", 	Event_ID2);
    if ( choose["Event.MPI"] )
      input->select("Delphes/Event.MPI", 	Event_MPI);
    if ( choose["Event.Number"] )
      input->select("Delphes/Event.Number", 	Event_Number);
    if ( choose["Event.PDF1"] )
      input->select("Delphes/Event.PDF1", 	Event_PDF1);
    if ( choose["Event.PDF2"] )
      input->select("Delphes/Event.PDF2", 	Event_PDF2);
    if ( choose["Event.ProcTime"] )
      input->select("Delphes/Event.ProcTime", 	Event_ProcTime);
    if ( choose["Event.ProcessID"] )
      input->select("Delphes/Event.ProcessID", 	Event_ProcessID);
    if ( choose["Event.ReadTime"] )
      input->select("Delphes/Event.ReadTime", 	Event_ReadTime);
    if ( choose["Event.Scale"] )
      input->select("Delphes/Event.Scale", 	Event_Scale);
    if ( choose["Event.ScalePDF"] )
      input->select("Delphes/Event.ScalePDF", 	Event_ScalePDF);
    if ( choose["Event.Weight"] )
      input->select("Delphes/Event.Weight", 	Event_Weight);
    if ( choose["Event.X1"] )
      input->select("Delphes/Event.X1", 	Event_X1);
    if ( choose["Event.X2"] )
      input->select("Delphes/Event.X2", 	Event_X2);
    if ( choose["Event.fBits"] )
      input->select("Delphes/Event.fBits", 	Event_fBits);
    if ( choose["Event.fUniqueID"] )
      input->select("Delphes/Event.fUniqueID", 	Event_fUniqueID);
    if ( choose["Event_size"] )
      input->select("Delphes/Event_size", 	Event_size);
    if ( choose["Jet.Area.fBits"] )
      input->select("Delphes/Jet.Area.fBits", 	Jet_Area_fBits);
    if ( choose["Jet.Area.fE"] )
      input->select("Delphes/Jet.Area.fE", 	Jet_Area_fE);
    if ( choose["Jet.Area.fP.fBits"] )
      input->select("Delphes/Jet.Area.fP.fBits", 	Jet_Area_fP_fBits);
    if ( choose["Jet.Area.fP.fUniqueID"] )
      input->select("Delphes/Jet.Area.fP.fUniqueID",
                     Jet_Area_fP_fUniqueID);
    if ( choose["Jet.Area.fP.fX"] )
      input->select("Delphes/Jet.Area.fP.fX", 	Jet_Area_fP_fX);
    if ( choose["Jet.Area.fP.fY"] )
      input->select("Delphes/Jet.Area.fP.fY", 	Jet_Area_fP_fY);
    if ( choose["Jet.Area.fP.fZ"] )
      input->select("Delphes/Jet.Area.fP.fZ", 	Jet_Area_fP_fZ);
    if ( choose["Jet.Area.fUniqueID"] )
      input->select("Delphes/Jet.Area.fUniqueID", 	Jet_Area_fUniqueID);
    if ( choose["Jet.BTag"] )
      input->select("Delphes/Jet.BTag", 	Jet_BTag);
    if ( choose["Jet.BTagAlgo"] )
      input->select("Delphes/Jet.BTagAlgo", 	Jet_BTagAlgo);
    if ( choose["Jet.BTagPhys"] )
      input->select("Delphes/Jet.BTagPhys", 	Jet_BTagPhys);
    if ( choose["Jet.Beta"] )
      input->select("Delphes/Jet.Beta", 	Jet_Beta);
    if ( choose["Jet.BetaStar"] )
      input->select("Delphes/Jet.BetaStar", 	Jet_BetaStar);
    if ( choose["Jet.Charge"] )
      input->select("Delphes/Jet.Charge", 	Jet_Charge);
    if ( choose["Jet.DeltaEta"] )
      input->select("Delphes/Jet.DeltaEta", 	Jet_DeltaEta);
    if ( choose["Jet.DeltaPhi"] )
      input->select("Delphes/Jet.DeltaPhi", 	Jet_DeltaPhi);
    if ( choose["Jet.EhadOverEem"] )
      input->select("Delphes/Jet.EhadOverEem", 	Jet_EhadOverEem);
    if ( choose["Jet.Eta"] )
      input->select("Delphes/Jet.Eta", 	Jet_Eta);
    if ( choose["Jet.Flavor"] )
      input->select("Delphes/Jet.Flavor", 	Jet_Flavor);
    if ( choose["Jet.FlavorAlgo"] )
      input->select("Delphes/Jet.FlavorAlgo", 	Jet_FlavorAlgo);
    if ( choose["Jet.FlavorPhys"] )
      input->select("Delphes/Jet.FlavorPhys", 	Jet_FlavorPhys);
    if ( choose["Jet.Mass"] )
      input->select("Delphes/Jet.Mass", 	Jet_Mass);
    if ( choose["Jet.MeanSqDeltaR"] )
      input->select("Delphes/Jet.MeanSqDeltaR", 	Jet_MeanSqDeltaR);
    if ( choose["Jet.NCharged"] )
      input->select("Delphes/Jet.NCharged", 	Jet_NCharged);
    if ( choose["Jet.NNeutrals"] )
      input->select("Delphes/Jet.NNeutrals", 	Jet_NNeutrals);
    if ( choose["Jet.NSubJetsPruned"] )
      input->select("Delphes/Jet.NSubJetsPruned", 	Jet_NSubJetsPruned);
    if ( choose["Jet.NSubJetsSoftDropped"] )
      input->select("Delphes/Jet.NSubJetsSoftDropped",
                     Jet_NSubJetsSoftDropped);
    if ( choose["Jet.NSubJetsTrimmed"] )
      input->select("Delphes/Jet.NSubJetsTrimmed", 	Jet_NSubJetsTrimmed);
    if ( choose["Jet.PT"] )
      input->select("Delphes/Jet.PT", 	Jet_PT);
    if ( choose["Jet.PTD"] )
      input->select("Delphes/Jet.PTD", 	Jet_PTD);
    if ( choose["Jet.Phi"] )
      input->select("Delphes/Jet.Phi", 	Jet_Phi);
    if ( choose["Jet.T"] )
      input->select("Delphes/Jet.T", 	Jet_T);
    if ( choose["Jet.TauTag"] )
      input->select("Delphes/Jet.TauTag", 	Jet_TauTag);
    if ( choose["Jet.fBits"] )
      input->select("Delphes/Jet.fBits", 	Jet_fBits);
    if ( choose["Jet.fUniqueID"] )
      input->select("Delphes/Jet.fUniqueID", 	Jet_fUniqueID);
    if ( choose["Jet_size"] )
      input->select("Delphes/Jet_size", 	Jet_size);
    if ( choose["MissingET.Eta"] )
      input->select("Delphes/MissingET.Eta", 	MissingET_Eta);
    if ( choose["MissingET.MET"] )
      input->select("Delphes/MissingET.MET", 	MissingET_MET);
    if ( choose["MissingET.Phi"] )
      input->select("Delphes/MissingET.Phi", 	MissingET_Phi);
    if ( choose["MissingET.fBits"] )
      input->select("Delphes/MissingET.fBits", 	MissingET_fBits);
    if ( choose["MissingET.fUniqueID"] )
      input->select("Delphes/MissingET.fUniqueID", 	MissingET_fUniqueID);
    if ( choose["MissingET_size"] )
      input->select("Delphes/MissingET_size", 	MissingET_size);
    if ( choose["Muon.Charge"] )
      input->select("Delphes/Muon.Charge", 	Muon_Charge);
    if ( choose["Muon.Eta"] )
      input->select("Delphes/Muon.Eta", 	Muon_Eta);
    if ( choose["Muon.IsolationVar"] )
      input->select("Delphes/Muon.IsolationVar", 	Muon_IsolationVar);
    if ( choose["Muon.IsolationVarRhoCorr"] )
      input->select("Delphes/Muon.IsolationVarRhoCorr",
                     Muon_IsolationVarRhoCorr);
    if ( choose["Muon.PT"] )
      input->select("Delphes/Muon.PT", 	Muon_PT);
    if ( choose["Muon.Phi"] )
      input->select("Delphes/Muon.Phi", 	Muon_Phi);
    if ( choose["Muon.SumPt"] )
      input->select("Delphes/Muon.SumPt", 	Muon_SumPt);
    if ( choose["Muon.SumPtCharged"] )
      input->select("Delphes/Muon.SumPtCharged", 	Muon_SumPtCharged);
    if ( choose["Muon.SumPtChargedPU"] )
      input->select("Delphes/Muon.SumPtChargedPU", 	Muon_SumPtChargedPU);
    if ( choose["Muon.SumPtNeutral"] )
      input->select("Delphes/Muon.SumPtNeutral", 	Muon_SumPtNeutral);
    if ( choose["Muon.T"] )
      input->select("Delphes/Muon.T", 	Muon_T);
    if ( choose["Muon.fBits"] )
      input->select("Delphes/Muon.fBits", 	Muon_fBits);
    if ( choose["Muon.fUniqueID"] )
      input->select("Delphes/Muon.fUniqueID", 	Muon_fUniqueID);
    if ( choose["Muon_size"] )
      input->select("Delphes/Muon_size", 	Muon_size);
    if ( choose["Photon.E"] )
      input->select("Delphes/Photon.E", 	Photon_E);
    if ( choose["Photon.EhadOverEem"] )
      input->select("Delphes/Photon.EhadOverEem", 	Photon_EhadOverEem);
    if ( choose["Photon.Eta"] )
      input->select("Delphes/Photon.Eta", 	Photon_Eta);
    if ( choose["Photon.IsolationVar"] )
      input->select("Delphes/Photon.IsolationVar", 	Photon_IsolationVar);
    if ( choose["Photon.IsolationVarRhoCorr"] )
      input->select("Delphes/Photon.IsolationVarRhoCorr",
                     Photon_IsolationVarRhoCorr);
    if ( choose["Photon.PT"] )
      input->select("Delphes/Photon.PT", 	Photon_PT);
    if ( choose["Photon.Phi"] )
      input->select("Delphes/Photon.Phi", 	Photon_Phi);
    if ( choose["Photon.SumPt"] )
      input->select("Delphes/Photon.SumPt", 	Photon_SumPt);
    if ( choose["Photon.SumPtCharged"] )
      input->select("Delphes/Photon.SumPtCharged", 	Photon_SumPtCharged);
    if ( choose["Photon.SumPtChargedPU"] )
      input->select("Delphes/Photon.SumPtChargedPU",
                     Photon_SumPtChargedPU);
    if ( choose["Photon.SumPtNeutral"] )
      input->select("Delphes/Photon.SumPtNeutral", 	Photon_SumPtNeutral);
    if ( choose["Photon.T"] )
      input->select("Delphes/Photon.T", 	Photon_T);
    if ( choose["Photon.fBits"] )
      input->select("Delphes/Photon.fBits", 	Photon_fBits);
    if ( choose["Photon.fUniqueID"] )
      input->select("Delphes/Photon.fUniqueID", 	Photon_fUniqueID);
    if ( choose["Photon_size"] )
      input->select("Delphes/Photon_size", 	Photon_size);

  }

  // A write-only buffer
  eventBuffer(otreestream& stream)
  : input(0),
    output(&stream)
  {
    initBuffers();

    output->add("MissingET_", 	MissingET_);
    output->add("Photon_", 	Photon_);
    output->add("Event_", 	Event_);
    output->add("Jet_", 	Jet_);
    output->add("Muon_", 	Muon_);
    output->add("Electron_", 	Electron_);
  
    output->add("Delphes/Electron.Charge[Electron_]", 	Electron_Charge);
    output->add("Delphes/Electron.EhadOverEem[Electron_]",
                 Electron_EhadOverEem);
    output->add("Delphes/Electron.Eta[Electron_]", 	Electron_Eta);
    output->add("Delphes/Electron.IsolationVar[Electron_]",
                 Electron_IsolationVar);
    output->add("Delphes/Electron.IsolationVarRhoCorr[Electron_]",
                 Electron_IsolationVarRhoCorr);
    output->add("Delphes/Electron.PT[Electron_]", 	Electron_PT);
    output->add("Delphes/Electron.Phi[Electron_]", 	Electron_Phi);
    output->add("Delphes/Electron.SumPt[Electron_]", 	Electron_SumPt);
    output->add("Delphes/Electron.SumPtCharged[Electron_]",
                 Electron_SumPtCharged);
    output->add("Delphes/Electron.SumPtChargedPU[Electron_]",
                 Electron_SumPtChargedPU);
    output->add("Delphes/Electron.SumPtNeutral[Electron_]",
                 Electron_SumPtNeutral);
    output->add("Delphes/Electron.T[Electron_]", 	Electron_T);
    output->add("Delphes/Electron.fBits[Electron_]", 	Electron_fBits);
    output->add("Delphes/Electron.fUniqueID[Electron_]",
                 Electron_fUniqueID);
    output->add("Delphes/Electron_size", 	Electron_size);
    output->add("Delphes/Event.AlphaQCD", 	Event_AlphaQCD);
    output->add("Delphes/Event.AlphaQED", 	Event_AlphaQED);
    output->add("Delphes/Event.ID1", 	Event_ID1);
    output->add("Delphes/Event.ID2", 	Event_ID2);
    output->add("Delphes/Event.MPI", 	Event_MPI);
    output->add("Delphes/Event.Number", 	Event_Number);
    output->add("Delphes/Event.PDF1", 	Event_PDF1);
    output->add("Delphes/Event.PDF2", 	Event_PDF2);
    output->add("Delphes/Event.ProcTime", 	Event_ProcTime);
    output->add("Delphes/Event.ProcessID", 	Event_ProcessID);
    output->add("Delphes/Event.ReadTime", 	Event_ReadTime);
    output->add("Delphes/Event.Scale", 	Event_Scale);
    output->add("Delphes/Event.ScalePDF", 	Event_ScalePDF);
    output->add("Delphes/Event.Weight", 	Event_Weight);
    output->add("Delphes/Event.X1", 	Event_X1);
    output->add("Delphes/Event.X2", 	Event_X2);
    output->add("Delphes/Event.fBits", 	Event_fBits);
    output->add("Delphes/Event.fUniqueID", 	Event_fUniqueID);
    output->add("Delphes/Event_size", 	Event_size);
    output->add("Delphes/Jet.Area.fBits[Jet_]", 	Jet_Area_fBits);
    output->add("Delphes/Jet.Area.fE[Jet_]", 	Jet_Area_fE);
    output->add("Delphes/Jet.Area.fP.fBits[Jet_]", 	Jet_Area_fP_fBits);
    output->add("Delphes/Jet.Area.fP.fUniqueID[Jet_]",
                 Jet_Area_fP_fUniqueID);
    output->add("Delphes/Jet.Area.fP.fX[Jet_]", 	Jet_Area_fP_fX);
    output->add("Delphes/Jet.Area.fP.fY[Jet_]", 	Jet_Area_fP_fY);
    output->add("Delphes/Jet.Area.fP.fZ[Jet_]", 	Jet_Area_fP_fZ);
    output->add("Delphes/Jet.Area.fUniqueID[Jet_]", 	Jet_Area_fUniqueID);
    output->add("Delphes/Jet.BTag[Jet_]", 	Jet_BTag);
    output->add("Delphes/Jet.BTagAlgo[Jet_]", 	Jet_BTagAlgo);
    output->add("Delphes/Jet.BTagPhys[Jet_]", 	Jet_BTagPhys);
    output->add("Delphes/Jet.Beta[Jet_]", 	Jet_Beta);
    output->add("Delphes/Jet.BetaStar[Jet_]", 	Jet_BetaStar);
    output->add("Delphes/Jet.Charge[Jet_]", 	Jet_Charge);
    output->add("Delphes/Jet.DeltaEta[Jet_]", 	Jet_DeltaEta);
    output->add("Delphes/Jet.DeltaPhi[Jet_]", 	Jet_DeltaPhi);
    output->add("Delphes/Jet.EhadOverEem[Jet_]", 	Jet_EhadOverEem);
    output->add("Delphes/Jet.Eta[Jet_]", 	Jet_Eta);
    output->add("Delphes/Jet.Flavor[Jet_]", 	Jet_Flavor);
    output->add("Delphes/Jet.FlavorAlgo[Jet_]", 	Jet_FlavorAlgo);
    output->add("Delphes/Jet.FlavorPhys[Jet_]", 	Jet_FlavorPhys);
    output->add("Delphes/Jet.Mass[Jet_]", 	Jet_Mass);
    output->add("Delphes/Jet.MeanSqDeltaR[Jet_]", 	Jet_MeanSqDeltaR);
    output->add("Delphes/Jet.NCharged[Jet_]", 	Jet_NCharged);
    output->add("Delphes/Jet.NNeutrals[Jet_]", 	Jet_NNeutrals);
    output->add("Delphes/Jet.NSubJetsPruned[Jet_]", 	Jet_NSubJetsPruned);
    output->add("Delphes/Jet.NSubJetsSoftDropped[Jet_]",
                 Jet_NSubJetsSoftDropped);
    output->add("Delphes/Jet.NSubJetsTrimmed[Jet_]", 	Jet_NSubJetsTrimmed);
    output->add("Delphes/Jet.PT[Jet_]", 	Jet_PT);
    output->add("Delphes/Jet.PTD[Jet_]", 	Jet_PTD);
    output->add("Delphes/Jet.Phi[Jet_]", 	Jet_Phi);
    output->add("Delphes/Jet.T[Jet_]", 	Jet_T);
    output->add("Delphes/Jet.TauTag[Jet_]", 	Jet_TauTag);
    output->add("Delphes/Jet.fBits[Jet_]", 	Jet_fBits);
    output->add("Delphes/Jet.fUniqueID[Jet_]", 	Jet_fUniqueID);
    output->add("Delphes/Jet_size", 	Jet_size);
    output->add("Delphes/MissingET.Eta", 	MissingET_Eta);
    output->add("Delphes/MissingET.MET", 	MissingET_MET);
    output->add("Delphes/MissingET.Phi", 	MissingET_Phi);
    output->add("Delphes/MissingET.fBits", 	MissingET_fBits);
    output->add("Delphes/MissingET.fUniqueID", 	MissingET_fUniqueID);
    output->add("Delphes/MissingET_size", 	MissingET_size);
    output->add("Delphes/Muon.Charge[Muon_]", 	Muon_Charge);
    output->add("Delphes/Muon.Eta[Muon_]", 	Muon_Eta);
    output->add("Delphes/Muon.IsolationVar[Muon_]", 	Muon_IsolationVar);
    output->add("Delphes/Muon.IsolationVarRhoCorr[Muon_]",
                 Muon_IsolationVarRhoCorr);
    output->add("Delphes/Muon.PT[Muon_]", 	Muon_PT);
    output->add("Delphes/Muon.Phi[Muon_]", 	Muon_Phi);
    output->add("Delphes/Muon.SumPt[Muon_]", 	Muon_SumPt);
    output->add("Delphes/Muon.SumPtCharged[Muon_]", 	Muon_SumPtCharged);
    output->add("Delphes/Muon.SumPtChargedPU[Muon_]", 	Muon_SumPtChargedPU);
    output->add("Delphes/Muon.SumPtNeutral[Muon_]", 	Muon_SumPtNeutral);
    output->add("Delphes/Muon.T[Muon_]", 	Muon_T);
    output->add("Delphes/Muon.fBits[Muon_]", 	Muon_fBits);
    output->add("Delphes/Muon.fUniqueID[Muon_]", 	Muon_fUniqueID);
    output->add("Delphes/Muon_size", 	Muon_size);
    output->add("Delphes/Photon.E[Photon_]", 	Photon_E);
    output->add("Delphes/Photon.EhadOverEem[Photon_]", 	Photon_EhadOverEem);
    output->add("Delphes/Photon.Eta[Photon_]", 	Photon_Eta);
    output->add("Delphes/Photon.IsolationVar[Photon_]",
                 Photon_IsolationVar);
    output->add("Delphes/Photon.IsolationVarRhoCorr[Photon_]",
                 Photon_IsolationVarRhoCorr);
    output->add("Delphes/Photon.PT[Photon_]", 	Photon_PT);
    output->add("Delphes/Photon.Phi[Photon_]", 	Photon_Phi);
    output->add("Delphes/Photon.SumPt[Photon_]", 	Photon_SumPt);
    output->add("Delphes/Photon.SumPtCharged[Photon_]",
                 Photon_SumPtCharged);
    output->add("Delphes/Photon.SumPtChargedPU[Photon_]",
                 Photon_SumPtChargedPU);
    output->add("Delphes/Photon.SumPtNeutral[Photon_]",
                 Photon_SumPtNeutral);
    output->add("Delphes/Photon.T[Photon_]", 	Photon_T);
    output->add("Delphes/Photon.fBits[Photon_]", 	Photon_fBits);
    output->add("Delphes/Photon.fUniqueID[Photon_]", 	Photon_fUniqueID);
    output->add("Delphes/Photon_size", 	Photon_size);

  }

  void initBuffers()
  {
    Electron_Charge	= std::vector<int>(10,0);
    Electron_EhadOverEem	= std::vector<float>(10,0);
    Electron_Eta	= std::vector<float>(10,0);
    Electron_IsolationVar	= std::vector<float>(10,0);
    Electron_IsolationVarRhoCorr	= std::vector<float>(10,0);
    Electron_PT	= std::vector<float>(10,0);
    Electron_Phi	= std::vector<float>(10,0);
    Electron_SumPt	= std::vector<float>(10,0);
    Electron_SumPtCharged	= std::vector<float>(10,0);
    Electron_SumPtChargedPU	= std::vector<float>(10,0);
    Electron_SumPtNeutral	= std::vector<float>(10,0);
    Electron_T	= std::vector<float>(10,0);
    Electron_fBits	= std::vector<unsigned int>(10,0);
    Electron_fUniqueID	= std::vector<unsigned int>(10,0);
    Jet_Area_fBits	= std::vector<unsigned int>(35,0);
    Jet_Area_fE	= std::vector<double>(35,0);
    Jet_Area_fP_fBits	= std::vector<unsigned int>(35,0);
    Jet_Area_fP_fUniqueID	= std::vector<unsigned int>(35,0);
    Jet_Area_fP_fX	= std::vector<double>(35,0);
    Jet_Area_fP_fY	= std::vector<double>(35,0);
    Jet_Area_fP_fZ	= std::vector<double>(35,0);
    Jet_Area_fUniqueID	= std::vector<unsigned int>(35,0);
    Jet_BTag	= std::vector<unsigned int>(35,0);
    Jet_BTagAlgo	= std::vector<unsigned int>(35,0);
    Jet_BTagPhys	= std::vector<unsigned int>(35,0);
    Jet_Beta	= std::vector<float>(35,0);
    Jet_BetaStar	= std::vector<float>(35,0);
    Jet_Charge	= std::vector<int>(35,0);
    Jet_DeltaEta	= std::vector<float>(35,0);
    Jet_DeltaPhi	= std::vector<float>(35,0);
    Jet_EhadOverEem	= std::vector<float>(35,0);
    Jet_Eta	= std::vector<float>(35,0);
    Jet_Flavor	= std::vector<unsigned int>(35,0);
    Jet_FlavorAlgo	= std::vector<unsigned int>(35,0);
    Jet_FlavorPhys	= std::vector<unsigned int>(35,0);
    Jet_Mass	= std::vector<float>(35,0);
    Jet_MeanSqDeltaR	= std::vector<float>(35,0);
    Jet_NCharged	= std::vector<int>(35,0);
    Jet_NNeutrals	= std::vector<int>(35,0);
    Jet_NSubJetsPruned	= std::vector<int>(35,0);
    Jet_NSubJetsSoftDropped	= std::vector<int>(35,0);
    Jet_NSubJetsTrimmed	= std::vector<int>(35,0);
    Jet_PT	= std::vector<float>(35,0);
    Jet_PTD	= std::vector<float>(35,0);
    Jet_Phi	= std::vector<float>(35,0);
    Jet_T	= std::vector<float>(35,0);
    Jet_TauTag	= std::vector<unsigned int>(35,0);
    Jet_fBits	= std::vector<unsigned int>(35,0);
    Jet_fUniqueID	= std::vector<unsigned int>(35,0);
    Muon_Charge	= std::vector<int>(10,0);
    Muon_Eta	= std::vector<float>(10,0);
    Muon_IsolationVar	= std::vector<float>(10,0);
    Muon_IsolationVarRhoCorr	= std::vector<float>(10,0);
    Muon_PT	= std::vector<float>(10,0);
    Muon_Phi	= std::vector<float>(10,0);
    Muon_SumPt	= std::vector<float>(10,0);
    Muon_SumPtCharged	= std::vector<float>(10,0);
    Muon_SumPtChargedPU	= std::vector<float>(10,0);
    Muon_SumPtNeutral	= std::vector<float>(10,0);
    Muon_T	= std::vector<float>(10,0);
    Muon_fBits	= std::vector<unsigned int>(10,0);
    Muon_fUniqueID	= std::vector<unsigned int>(10,0);
    Photon_E	= std::vector<float>(10,0);
    Photon_EhadOverEem	= std::vector<float>(10,0);
    Photon_Eta	= std::vector<float>(10,0);
    Photon_IsolationVar	= std::vector<float>(10,0);
    Photon_IsolationVarRhoCorr	= std::vector<float>(10,0);
    Photon_PT	= std::vector<float>(10,0);
    Photon_Phi	= std::vector<float>(10,0);
    Photon_SumPt	= std::vector<float>(10,0);
    Photon_SumPtCharged	= std::vector<float>(10,0);
    Photon_SumPtChargedPU	= std::vector<float>(10,0);
    Photon_SumPtNeutral	= std::vector<float>(10,0);
    Photon_T	= std::vector<float>(10,0);
    Photon_fBits	= std::vector<unsigned int>(10,0);
    Photon_fUniqueID	= std::vector<unsigned int>(10,0);
    Electron	= std::vector<eventBuffer::Electron_s>(10);
    Jet	= std::vector<eventBuffer::Jet_s>(35);
    Muon	= std::vector<eventBuffer::Muon_s>(10);
    Photon	= std::vector<eventBuffer::Photon_s>(10);

  }
      
  void read(int entry)
  {
    if ( !input ) 
      { 
        std::cout << "** eventBuffer::read - first  call read-only constructor!"
                  << std::endl;
        assert(0);
      }
    input->read(entry);

    // clear indexmap
    for(std::map<std::string, std::vector<int> >::iterator
    item=indexmap.begin(); 
    item != indexmap.end();
    ++item)
    item->second.clear();
  }

  void select(std::string objname)
  {
    indexmap[objname] = std::vector<int>();
  }

  void select(std::string objname, int index)
  {
    try
     {
       indexmap[objname].push_back(index);
     }
    catch (...)
     {
       std::cout << "** eventBuffer::select - first call select(""" 
                 << objname << """)" 
                 << std::endl;
       assert(0);
    }
  }

 void ls()
 {
   if( input ) input->ls();
 }

 int size()
 {
   if( input ) 
     return input->size();
   else
     return 0;
 }

 void close()
 {
   if( input )   input->close();
   if( output ) output->close();
 }

 // --- indexmap keeps track of which objects have been flagged for selection
 std::map<std::string, std::vector<int> > indexmap;

 // to read events
 itreestream* input;

 // to write events
 otreestream* output;

 // switches for choosing branches
 std::map<std::string, bool> choose;

}; 
#endif
