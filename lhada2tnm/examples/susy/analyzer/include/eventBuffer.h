#ifndef EVENTBUFFER_H
#define EVENTBUFFER_H
//----------------------------------------------------------------------------
// File:        eventBuffer.h
// Description: Analyzer header for ntuples created by TheNtupleMaker
// Created:     Tue May 15 14:10:05 2018 by mkanalyzer.py
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
  std::vector<float>	EFlowNeutralHadron_E;
  std::vector<float>	EFlowNeutralHadron_ET;
  std::vector<float>	EFlowNeutralHadron_Eem;
  std::vector<float>	EFlowNeutralHadron_Ehad;
  std::vector<float>	EFlowNeutralHadron_Eta;
  std::vector<int>	EFlowNeutralHadron_NTimeHits;
  std::vector<float>	EFlowNeutralHadron_Phi;
  std::vector<float>	EFlowNeutralHadron_T;
  std::vector<int>	EFlowNeutralHadron_fBits;
  std::vector<int>	EFlowNeutralHadron_fUniqueID;
  std::vector<float>	EFlowPhoton_E;
  std::vector<float>	EFlowPhoton_ET;
  std::vector<float>	EFlowPhoton_Eem;
  std::vector<float>	EFlowPhoton_Ehad;
  std::vector<float>	EFlowPhoton_Eta;
  std::vector<int>	EFlowPhoton_NTimeHits;
  std::vector<float>	EFlowPhoton_Phi;
  std::vector<float>	EFlowPhoton_T;
  std::vector<int>	EFlowPhoton_fBits;
  std::vector<int>	EFlowPhoton_fUniqueID;
  std::vector<int>	EFlowTrack_Charge;
  std::vector<float>	EFlowTrack_CtgTheta;
  std::vector<float>	EFlowTrack_D0;
  std::vector<float>	EFlowTrack_DZ;
  std::vector<float>	EFlowTrack_ErrorCtgTheta;
  std::vector<float>	EFlowTrack_ErrorD0;
  std::vector<float>	EFlowTrack_ErrorDZ;
  std::vector<float>	EFlowTrack_ErrorP;
  std::vector<float>	EFlowTrack_ErrorPT;
  std::vector<float>	EFlowTrack_ErrorPhi;
  std::vector<float>	EFlowTrack_ErrorT;
  std::vector<float>	EFlowTrack_Eta;
  std::vector<float>	EFlowTrack_EtaOuter;
  std::vector<float>	EFlowTrack_L;
  std::vector<float>	EFlowTrack_P;
  std::vector<int>	EFlowTrack_PID;
  std::vector<float>	EFlowTrack_PT;
  std::vector<float>	EFlowTrack_Phi;
  std::vector<float>	EFlowTrack_PhiOuter;
  std::vector<float>	EFlowTrack_T;
  std::vector<float>	EFlowTrack_TOuter;
  std::vector<int>	EFlowTrack_VertexIndex;
  std::vector<float>	EFlowTrack_X;
  std::vector<float>	EFlowTrack_XOuter;
  std::vector<float>	EFlowTrack_Xd;
  std::vector<float>	EFlowTrack_Y;
  std::vector<float>	EFlowTrack_YOuter;
  std::vector<float>	EFlowTrack_Yd;
  std::vector<float>	EFlowTrack_Z;
  std::vector<float>	EFlowTrack_ZOuter;
  std::vector<float>	EFlowTrack_Zd;
  std::vector<int>	EFlowTrack_fBits;
  std::vector<int>	EFlowTrack_fUniqueID;
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
  std::vector<int>	Electron_fBits;
  std::vector<int>	Electron_fUniqueID;
  std::vector<int>	FatJet_BTag;
  std::vector<int>	FatJet_BTagAlgo;
  std::vector<int>	FatJet_BTagPhys;
  std::vector<float>	FatJet_Beta;
  std::vector<float>	FatJet_BetaStar;
  std::vector<int>	FatJet_Charge;
  std::vector<float>	FatJet_DeltaEta;
  std::vector<float>	FatJet_DeltaPhi;
  std::vector<float>	FatJet_EhadOverEem;
  std::vector<float>	FatJet_Eta;
  std::vector<int>	FatJet_Flavor;
  std::vector<int>	FatJet_FlavorAlgo;
  std::vector<int>	FatJet_FlavorPhys;
  std::vector<float>	FatJet_Mass;
  std::vector<float>	FatJet_MeanSqDeltaR;
  std::vector<int>	FatJet_NCharged;
  std::vector<int>	FatJet_NNeutrals;
  std::vector<int>	FatJet_NSubJetsPruned;
  std::vector<int>	FatJet_NSubJetsSoftDropped;
  std::vector<int>	FatJet_NSubJetsTrimmed;
  std::vector<float>	FatJet_PT;
  std::vector<float>	FatJet_PTD;
  std::vector<float>	FatJet_Phi;
  std::vector<float>	FatJet_T;
  std::vector<int>	FatJet_TauTag;
  std::vector<int>	FatJet_fBits;
  std::vector<int>	FatJet_fUniqueID;
  std::vector<int>	GenJet_BTag;
  std::vector<int>	GenJet_BTagAlgo;
  std::vector<int>	GenJet_BTagPhys;
  std::vector<float>	GenJet_Beta;
  std::vector<float>	GenJet_BetaStar;
  std::vector<int>	GenJet_Charge;
  std::vector<float>	GenJet_DeltaEta;
  std::vector<float>	GenJet_DeltaPhi;
  std::vector<float>	GenJet_EhadOverEem;
  std::vector<float>	GenJet_Eta;
  std::vector<int>	GenJet_Flavor;
  std::vector<int>	GenJet_FlavorAlgo;
  std::vector<int>	GenJet_FlavorPhys;
  std::vector<float>	GenJet_Mass;
  std::vector<float>	GenJet_MeanSqDeltaR;
  std::vector<int>	GenJet_NCharged;
  std::vector<int>	GenJet_NNeutrals;
  std::vector<int>	GenJet_NSubJetsPruned;
  std::vector<int>	GenJet_NSubJetsSoftDropped;
  std::vector<int>	GenJet_NSubJetsTrimmed;
  std::vector<float>	GenJet_PT;
  std::vector<float>	GenJet_PTD;
  std::vector<float>	GenJet_Phi;
  std::vector<float>	GenJet_T;
  std::vector<int>	GenJet_TauTag;
  std::vector<int>	GenJet_fBits;
  std::vector<int>	GenJet_fUniqueID;
  std::vector<int>	Jet_BTag;
  std::vector<int>	Jet_BTagAlgo;
  std::vector<int>	Jet_BTagPhys;
  std::vector<float>	Jet_Beta;
  std::vector<float>	Jet_BetaStar;
  std::vector<int>	Jet_Charge;
  std::vector<float>	Jet_DeltaEta;
  std::vector<float>	Jet_DeltaPhi;
  std::vector<float>	Jet_EhadOverEem;
  std::vector<float>	Jet_Eta;
  std::vector<int>	Jet_Flavor;
  std::vector<int>	Jet_FlavorAlgo;
  std::vector<int>	Jet_FlavorPhys;
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
  std::vector<int>	Jet_TauTag;
  std::vector<int>	Jet_fBits;
  std::vector<int>	Jet_fUniqueID;
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
  std::vector<int>	Muon_fBits;
  std::vector<int>	Muon_fUniqueID;
  std::vector<int>	Particle_Charge;
  std::vector<float>	Particle_CtgTheta;
  std::vector<float>	Particle_D0;
  std::vector<int>	Particle_D1;
  std::vector<int>	Particle_D2;
  std::vector<float>	Particle_DZ;
  std::vector<float>	Particle_E;
  std::vector<float>	Particle_Eta;
  std::vector<int>	Particle_IsPU;
  std::vector<int>	Particle_M1;
  std::vector<int>	Particle_M2;
  std::vector<float>	Particle_Mass;
  std::vector<float>	Particle_P;
  std::vector<int>	Particle_PID;
  std::vector<float>	Particle_PT;
  std::vector<float>	Particle_Phi;
  std::vector<float>	Particle_Px;
  std::vector<float>	Particle_Py;
  std::vector<float>	Particle_Pz;
  std::vector<float>	Particle_Rapidity;
  std::vector<int>	Particle_Status;
  std::vector<float>	Particle_T;
  std::vector<float>	Particle_X;
  std::vector<float>	Particle_Y;
  std::vector<float>	Particle_Z;
  std::vector<int>	Particle_fBits;
  std::vector<int>	Particle_fUniqueID;
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
  std::vector<int>	Photon_fBits;
  std::vector<int>	Photon_fUniqueID;
  std::vector<float>	Tower_E;
  std::vector<float>	Tower_ET;
  std::vector<float>	Tower_Eem;
  std::vector<float>	Tower_Ehad;
  std::vector<float>	Tower_Eta;
  std::vector<int>	Tower_NTimeHits;
  std::vector<float>	Tower_Phi;
  std::vector<float>	Tower_T;
  std::vector<int>	Tower_fBits;
  std::vector<int>	Tower_fUniqueID;
  std::vector<int>	Track_Charge;
  std::vector<float>	Track_CtgTheta;
  std::vector<float>	Track_D0;
  std::vector<float>	Track_DZ;
  std::vector<float>	Track_ErrorCtgTheta;
  std::vector<float>	Track_ErrorD0;
  std::vector<float>	Track_ErrorDZ;
  std::vector<float>	Track_ErrorP;
  std::vector<float>	Track_ErrorPT;
  std::vector<float>	Track_ErrorPhi;
  std::vector<float>	Track_ErrorT;
  std::vector<float>	Track_Eta;
  std::vector<float>	Track_EtaOuter;
  std::vector<float>	Track_L;
  std::vector<float>	Track_P;
  std::vector<int>	Track_PID;
  std::vector<float>	Track_PT;
  std::vector<float>	Track_Phi;
  std::vector<float>	Track_PhiOuter;
  std::vector<float>	Track_T;
  std::vector<float>	Track_TOuter;
  std::vector<int>	Track_VertexIndex;
  std::vector<float>	Track_X;
  std::vector<float>	Track_XOuter;
  std::vector<float>	Track_Xd;
  std::vector<float>	Track_Y;
  std::vector<float>	Track_YOuter;
  std::vector<float>	Track_Yd;
  std::vector<float>	Track_Z;
  std::vector<float>	Track_ZOuter;
  std::vector<float>	Track_Zd;
  std::vector<int>	Track_fBits;
  std::vector<int>	Track_fUniqueID;

  int	Tower_;
  int	MissingET_;
  int	Photon_;
  int	Track_;
  int	ScalarHT_;
  int	EFlowPhoton_;
  int	FatJet_;
  int	Event_;
  int	EFlowNeutralHadron_;
  int	Jet_;
  int	Muon_;
  int	Electron_;
  int	GenJet_;
  int	Particle_;
  int	GenMissingET_;
  int	EFlowTrack_;

  int	EFlowNeutralHadron_size;
  int	EFlowPhoton_size;
  int	EFlowTrack_size;
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
  int	Event_fBits;
  int	Event_fUniqueID;
  int	Event_size;
  int	FatJet_size;
  int	GenJet_size;
  float	GenMissingET_Eta;
  float	GenMissingET_MET;
  float	GenMissingET_Phi;
  int	GenMissingET_fBits;
  int	GenMissingET_fUniqueID;
  int	GenMissingET_size;
  int	Jet_size;
  float	MissingET_Eta;
  float	MissingET_MET;
  float	MissingET_Phi;
  int	MissingET_fBits;
  int	MissingET_fUniqueID;
  int	MissingET_size;
  int	Muon_size;
  int	Particle_size;
  int	Photon_size;
  float	ScalarHT_HT;
  int	ScalarHT_fBits;
  int	ScalarHT_fUniqueID;
  int	ScalarHT_size;
  int	Tower_size;
  int	Track_size;

  //--------------------------------------------------------------------------
  // --- Structs can be filled by calling fill(), or individual fill
  // --- methods, e.g., fillElectrons()
  // --- after the call to read(...)
  //----------- --------------------------------------------------------------
  struct EFlowNeutralHadron_s
  {
    float	E;
    float	ET;
    float	Eem;
    float	Ehad;
    float	Eta;
    int	NTimeHits;
    float	Phi;
    float	T;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "EFlowNeutralHadron" << std::endl;
      sprintf(r, "  %-32s: %f\n", "E", ( double)E); os << r;
      sprintf(r, "  %-32s: %f\n", "ET", ( double)ET); os << r;
      sprintf(r, "  %-32s: %f\n", "Eem", ( double)Eem); os << r;
      sprintf(r, "  %-32s: %f\n", "Ehad", ( double)Ehad); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "NTimeHits", ( double)NTimeHits); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct EFlowPhoton_s
  {
    float	E;
    float	ET;
    float	Eem;
    float	Ehad;
    float	Eta;
    int	NTimeHits;
    float	Phi;
    float	T;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "EFlowPhoton" << std::endl;
      sprintf(r, "  %-32s: %f\n", "E", ( double)E); os << r;
      sprintf(r, "  %-32s: %f\n", "ET", ( double)ET); os << r;
      sprintf(r, "  %-32s: %f\n", "Eem", ( double)Eem); os << r;
      sprintf(r, "  %-32s: %f\n", "Ehad", ( double)Ehad); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "NTimeHits", ( double)NTimeHits); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct EFlowTrack_s
  {
    int	Charge;
    float	CtgTheta;
    float	D0;
    float	DZ;
    float	ErrorCtgTheta;
    float	ErrorD0;
    float	ErrorDZ;
    float	ErrorP;
    float	ErrorPT;
    float	ErrorPhi;
    float	ErrorT;
    float	Eta;
    float	EtaOuter;
    float	L;
    float	P;
    int	PID;
    float	PT;
    float	Phi;
    float	PhiOuter;
    float	T;
    float	TOuter;
    int	VertexIndex;
    float	X;
    float	XOuter;
    float	Xd;
    float	Y;
    float	YOuter;
    float	Yd;
    float	Z;
    float	ZOuter;
    float	Zd;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "EFlowTrack" << std::endl;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "CtgTheta", ( double)CtgTheta); os << r;
      sprintf(r, "  %-32s: %f\n", "D0", ( double)D0); os << r;
      sprintf(r, "  %-32s: %f\n", "DZ", ( double)DZ); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorCtgTheta", ( double)ErrorCtgTheta); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorD0", ( double)ErrorD0); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorDZ", ( double)ErrorDZ); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorP", ( double)ErrorP); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorPT", ( double)ErrorPT); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorPhi", ( double)ErrorPhi); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorT", ( double)ErrorT); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "EtaOuter", ( double)EtaOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "L", ( double)L); os << r;
      sprintf(r, "  %-32s: %f\n", "P", ( double)P); os << r;
      sprintf(r, "  %-32s: %f\n", "PID", ( double)PID); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "PhiOuter", ( double)PhiOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "TOuter", ( double)TOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "VertexIndex", ( double)VertexIndex); os << r;
      sprintf(r, "  %-32s: %f\n", "X", ( double)X); os << r;
      sprintf(r, "  %-32s: %f\n", "XOuter", ( double)XOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "Xd", ( double)Xd); os << r;
      sprintf(r, "  %-32s: %f\n", "Y", ( double)Y); os << r;
      sprintf(r, "  %-32s: %f\n", "YOuter", ( double)YOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "Yd", ( double)Yd); os << r;
      sprintf(r, "  %-32s: %f\n", "Z", ( double)Z); os << r;
      sprintf(r, "  %-32s: %f\n", "ZOuter", ( double)ZOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "Zd", ( double)Zd); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

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
    int	fBits;
    int	fUniqueID;

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

  struct FatJet_s
  {
    int	BTag;
    int	BTagAlgo;
    int	BTagPhys;
    float	Beta;
    float	BetaStar;
    int	Charge;
    float	DeltaEta;
    float	DeltaPhi;
    float	EhadOverEem;
    float	Eta;
    int	Flavor;
    int	FlavorAlgo;
    int	FlavorPhys;
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
    int	TauTag;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "FatJet" << std::endl;
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

  struct GenJet_s
  {
    int	BTag;
    int	BTagAlgo;
    int	BTagPhys;
    float	Beta;
    float	BetaStar;
    int	Charge;
    float	DeltaEta;
    float	DeltaPhi;
    float	EhadOverEem;
    float	Eta;
    int	Flavor;
    int	FlavorAlgo;
    int	FlavorPhys;
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
    int	TauTag;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "GenJet" << std::endl;
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

  struct Jet_s
  {
    int	BTag;
    int	BTagAlgo;
    int	BTagPhys;
    float	Beta;
    float	BetaStar;
    int	Charge;
    float	DeltaEta;
    float	DeltaPhi;
    float	EhadOverEem;
    float	Eta;
    int	Flavor;
    int	FlavorAlgo;
    int	FlavorPhys;
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
    int	TauTag;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Jet" << std::endl;
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
    int	fBits;
    int	fUniqueID;

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

  struct Particle_s
  {
    int	Charge;
    float	CtgTheta;
    float	D0;
    int	D1;
    int	D2;
    float	DZ;
    float	E;
    float	Eta;
    int	IsPU;
    int	M1;
    int	M2;
    float	Mass;
    float	P;
    int	PID;
    float	PT;
    float	Phi;
    float	Px;
    float	Py;
    float	Pz;
    float	Rapidity;
    int	Status;
    float	T;
    float	X;
    float	Y;
    float	Z;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Particle" << std::endl;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "CtgTheta", ( double)CtgTheta); os << r;
      sprintf(r, "  %-32s: %f\n", "D0", ( double)D0); os << r;
      sprintf(r, "  %-32s: %f\n", "D1", ( double)D1); os << r;
      sprintf(r, "  %-32s: %f\n", "D2", ( double)D2); os << r;
      sprintf(r, "  %-32s: %f\n", "DZ", ( double)DZ); os << r;
      sprintf(r, "  %-32s: %f\n", "E", ( double)E); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "IsPU", ( double)IsPU); os << r;
      sprintf(r, "  %-32s: %f\n", "M1", ( double)M1); os << r;
      sprintf(r, "  %-32s: %f\n", "M2", ( double)M2); os << r;
      sprintf(r, "  %-32s: %f\n", "Mass", ( double)Mass); os << r;
      sprintf(r, "  %-32s: %f\n", "P", ( double)P); os << r;
      sprintf(r, "  %-32s: %f\n", "PID", ( double)PID); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "Px", ( double)Px); os << r;
      sprintf(r, "  %-32s: %f\n", "Py", ( double)Py); os << r;
      sprintf(r, "  %-32s: %f\n", "Pz", ( double)Pz); os << r;
      sprintf(r, "  %-32s: %f\n", "Rapidity", ( double)Rapidity); os << r;
      sprintf(r, "  %-32s: %f\n", "Status", ( double)Status); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "X", ( double)X); os << r;
      sprintf(r, "  %-32s: %f\n", "Y", ( double)Y); os << r;
      sprintf(r, "  %-32s: %f\n", "Z", ( double)Z); os << r;
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
    int	fBits;
    int	fUniqueID;

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

  struct Tower_s
  {
    float	E;
    float	ET;
    float	Eem;
    float	Ehad;
    float	Eta;
    int	NTimeHits;
    float	Phi;
    float	T;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Tower" << std::endl;
      sprintf(r, "  %-32s: %f\n", "E", ( double)E); os << r;
      sprintf(r, "  %-32s: %f\n", "ET", ( double)ET); os << r;
      sprintf(r, "  %-32s: %f\n", "Eem", ( double)Eem); os << r;
      sprintf(r, "  %-32s: %f\n", "Ehad", ( double)Ehad); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "NTimeHits", ( double)NTimeHits); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct Track_s
  {
    int	Charge;
    float	CtgTheta;
    float	D0;
    float	DZ;
    float	ErrorCtgTheta;
    float	ErrorD0;
    float	ErrorDZ;
    float	ErrorP;
    float	ErrorPT;
    float	ErrorPhi;
    float	ErrorT;
    float	Eta;
    float	EtaOuter;
    float	L;
    float	P;
    int	PID;
    float	PT;
    float	Phi;
    float	PhiOuter;
    float	T;
    float	TOuter;
    int	VertexIndex;
    float	X;
    float	XOuter;
    float	Xd;
    float	Y;
    float	YOuter;
    float	Yd;
    float	Z;
    float	ZOuter;
    float	Zd;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Track" << std::endl;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "CtgTheta", ( double)CtgTheta); os << r;
      sprintf(r, "  %-32s: %f\n", "D0", ( double)D0); os << r;
      sprintf(r, "  %-32s: %f\n", "DZ", ( double)DZ); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorCtgTheta", ( double)ErrorCtgTheta); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorD0", ( double)ErrorD0); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorDZ", ( double)ErrorDZ); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorP", ( double)ErrorP); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorPT", ( double)ErrorPT); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorPhi", ( double)ErrorPhi); os << r;
      sprintf(r, "  %-32s: %f\n", "ErrorT", ( double)ErrorT); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "EtaOuter", ( double)EtaOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "L", ( double)L); os << r;
      sprintf(r, "  %-32s: %f\n", "P", ( double)P); os << r;
      sprintf(r, "  %-32s: %f\n", "PID", ( double)PID); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "PhiOuter", ( double)PhiOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "TOuter", ( double)TOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "VertexIndex", ( double)VertexIndex); os << r;
      sprintf(r, "  %-32s: %f\n", "X", ( double)X); os << r;
      sprintf(r, "  %-32s: %f\n", "XOuter", ( double)XOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "Xd", ( double)Xd); os << r;
      sprintf(r, "  %-32s: %f\n", "Y", ( double)Y); os << r;
      sprintf(r, "  %-32s: %f\n", "YOuter", ( double)YOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "Yd", ( double)Yd); os << r;
      sprintf(r, "  %-32s: %f\n", "Z", ( double)Z); os << r;
      sprintf(r, "  %-32s: %f\n", "ZOuter", ( double)ZOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "Zd", ( double)Zd); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };


  void fillEFlowNeutralHadrons()
  {
    EFlowNeutralHadron.resize(EFlowNeutralHadron_E.size());
    for(unsigned int i=0; i < EFlowNeutralHadron.size(); ++i)
      {
        EFlowNeutralHadron[i].E	= EFlowNeutralHadron_E[i];
        EFlowNeutralHadron[i].ET	= EFlowNeutralHadron_ET[i];
        EFlowNeutralHadron[i].Eem	= EFlowNeutralHadron_Eem[i];
        EFlowNeutralHadron[i].Ehad	= EFlowNeutralHadron_Ehad[i];
        EFlowNeutralHadron[i].Eta	= EFlowNeutralHadron_Eta[i];
        EFlowNeutralHadron[i].NTimeHits	= EFlowNeutralHadron_NTimeHits[i];
        EFlowNeutralHadron[i].Phi	= EFlowNeutralHadron_Phi[i];
        EFlowNeutralHadron[i].T	= EFlowNeutralHadron_T[i];
        EFlowNeutralHadron[i].fBits	= EFlowNeutralHadron_fBits[i];
        EFlowNeutralHadron[i].fUniqueID	= EFlowNeutralHadron_fUniqueID[i];
      }
  }

  void fillEFlowPhotons()
  {
    EFlowPhoton.resize(EFlowPhoton_E.size());
    for(unsigned int i=0; i < EFlowPhoton.size(); ++i)
      {
        EFlowPhoton[i].E	= EFlowPhoton_E[i];
        EFlowPhoton[i].ET	= EFlowPhoton_ET[i];
        EFlowPhoton[i].Eem	= EFlowPhoton_Eem[i];
        EFlowPhoton[i].Ehad	= EFlowPhoton_Ehad[i];
        EFlowPhoton[i].Eta	= EFlowPhoton_Eta[i];
        EFlowPhoton[i].NTimeHits	= EFlowPhoton_NTimeHits[i];
        EFlowPhoton[i].Phi	= EFlowPhoton_Phi[i];
        EFlowPhoton[i].T	= EFlowPhoton_T[i];
        EFlowPhoton[i].fBits	= EFlowPhoton_fBits[i];
        EFlowPhoton[i].fUniqueID	= EFlowPhoton_fUniqueID[i];
      }
  }

  void fillEFlowTracks()
  {
    EFlowTrack.resize(EFlowTrack_Charge.size());
    for(unsigned int i=0; i < EFlowTrack.size(); ++i)
      {
        EFlowTrack[i].Charge	= EFlowTrack_Charge[i];
        EFlowTrack[i].CtgTheta	= EFlowTrack_CtgTheta[i];
        EFlowTrack[i].D0	= EFlowTrack_D0[i];
        EFlowTrack[i].DZ	= EFlowTrack_DZ[i];
        EFlowTrack[i].ErrorCtgTheta	= EFlowTrack_ErrorCtgTheta[i];
        EFlowTrack[i].ErrorD0	= EFlowTrack_ErrorD0[i];
        EFlowTrack[i].ErrorDZ	= EFlowTrack_ErrorDZ[i];
        EFlowTrack[i].ErrorP	= EFlowTrack_ErrorP[i];
        EFlowTrack[i].ErrorPT	= EFlowTrack_ErrorPT[i];
        EFlowTrack[i].ErrorPhi	= EFlowTrack_ErrorPhi[i];
        EFlowTrack[i].ErrorT	= EFlowTrack_ErrorT[i];
        EFlowTrack[i].Eta	= EFlowTrack_Eta[i];
        EFlowTrack[i].EtaOuter	= EFlowTrack_EtaOuter[i];
        EFlowTrack[i].L	= EFlowTrack_L[i];
        EFlowTrack[i].P	= EFlowTrack_P[i];
        EFlowTrack[i].PID	= EFlowTrack_PID[i];
        EFlowTrack[i].PT	= EFlowTrack_PT[i];
        EFlowTrack[i].Phi	= EFlowTrack_Phi[i];
        EFlowTrack[i].PhiOuter	= EFlowTrack_PhiOuter[i];
        EFlowTrack[i].T	= EFlowTrack_T[i];
        EFlowTrack[i].TOuter	= EFlowTrack_TOuter[i];
        EFlowTrack[i].VertexIndex	= EFlowTrack_VertexIndex[i];
        EFlowTrack[i].X	= EFlowTrack_X[i];
        EFlowTrack[i].XOuter	= EFlowTrack_XOuter[i];
        EFlowTrack[i].Xd	= EFlowTrack_Xd[i];
        EFlowTrack[i].Y	= EFlowTrack_Y[i];
        EFlowTrack[i].YOuter	= EFlowTrack_YOuter[i];
        EFlowTrack[i].Yd	= EFlowTrack_Yd[i];
        EFlowTrack[i].Z	= EFlowTrack_Z[i];
        EFlowTrack[i].ZOuter	= EFlowTrack_ZOuter[i];
        EFlowTrack[i].Zd	= EFlowTrack_Zd[i];
        EFlowTrack[i].fBits	= EFlowTrack_fBits[i];
        EFlowTrack[i].fUniqueID	= EFlowTrack_fUniqueID[i];
      }
  }

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

  void fillFatJets()
  {
    FatJet.resize(FatJet_BTag.size());
    for(unsigned int i=0; i < FatJet.size(); ++i)
      {
        FatJet[i].BTag	= FatJet_BTag[i];
        FatJet[i].BTagAlgo	= FatJet_BTagAlgo[i];
        FatJet[i].BTagPhys	= FatJet_BTagPhys[i];
        FatJet[i].Beta	= FatJet_Beta[i];
        FatJet[i].BetaStar	= FatJet_BetaStar[i];
        FatJet[i].Charge	= FatJet_Charge[i];
        FatJet[i].DeltaEta	= FatJet_DeltaEta[i];
        FatJet[i].DeltaPhi	= FatJet_DeltaPhi[i];
        FatJet[i].EhadOverEem	= FatJet_EhadOverEem[i];
        FatJet[i].Eta	= FatJet_Eta[i];
        FatJet[i].Flavor	= FatJet_Flavor[i];
        FatJet[i].FlavorAlgo	= FatJet_FlavorAlgo[i];
        FatJet[i].FlavorPhys	= FatJet_FlavorPhys[i];
        FatJet[i].Mass	= FatJet_Mass[i];
        FatJet[i].MeanSqDeltaR	= FatJet_MeanSqDeltaR[i];
        FatJet[i].NCharged	= FatJet_NCharged[i];
        FatJet[i].NNeutrals	= FatJet_NNeutrals[i];
        FatJet[i].NSubJetsPruned	= FatJet_NSubJetsPruned[i];
        FatJet[i].NSubJetsSoftDropped	= FatJet_NSubJetsSoftDropped[i];
        FatJet[i].NSubJetsTrimmed	= FatJet_NSubJetsTrimmed[i];
        FatJet[i].PT	= FatJet_PT[i];
        FatJet[i].PTD	= FatJet_PTD[i];
        FatJet[i].Phi	= FatJet_Phi[i];
        FatJet[i].T	= FatJet_T[i];
        FatJet[i].TauTag	= FatJet_TauTag[i];
        FatJet[i].fBits	= FatJet_fBits[i];
        FatJet[i].fUniqueID	= FatJet_fUniqueID[i];
      }
  }

  void fillGenJets()
  {
    GenJet.resize(GenJet_BTag.size());
    for(unsigned int i=0; i < GenJet.size(); ++i)
      {
        GenJet[i].BTag	= GenJet_BTag[i];
        GenJet[i].BTagAlgo	= GenJet_BTagAlgo[i];
        GenJet[i].BTagPhys	= GenJet_BTagPhys[i];
        GenJet[i].Beta	= GenJet_Beta[i];
        GenJet[i].BetaStar	= GenJet_BetaStar[i];
        GenJet[i].Charge	= GenJet_Charge[i];
        GenJet[i].DeltaEta	= GenJet_DeltaEta[i];
        GenJet[i].DeltaPhi	= GenJet_DeltaPhi[i];
        GenJet[i].EhadOverEem	= GenJet_EhadOverEem[i];
        GenJet[i].Eta	= GenJet_Eta[i];
        GenJet[i].Flavor	= GenJet_Flavor[i];
        GenJet[i].FlavorAlgo	= GenJet_FlavorAlgo[i];
        GenJet[i].FlavorPhys	= GenJet_FlavorPhys[i];
        GenJet[i].Mass	= GenJet_Mass[i];
        GenJet[i].MeanSqDeltaR	= GenJet_MeanSqDeltaR[i];
        GenJet[i].NCharged	= GenJet_NCharged[i];
        GenJet[i].NNeutrals	= GenJet_NNeutrals[i];
        GenJet[i].NSubJetsPruned	= GenJet_NSubJetsPruned[i];
        GenJet[i].NSubJetsSoftDropped	= GenJet_NSubJetsSoftDropped[i];
        GenJet[i].NSubJetsTrimmed	= GenJet_NSubJetsTrimmed[i];
        GenJet[i].PT	= GenJet_PT[i];
        GenJet[i].PTD	= GenJet_PTD[i];
        GenJet[i].Phi	= GenJet_Phi[i];
        GenJet[i].T	= GenJet_T[i];
        GenJet[i].TauTag	= GenJet_TauTag[i];
        GenJet[i].fBits	= GenJet_fBits[i];
        GenJet[i].fUniqueID	= GenJet_fUniqueID[i];
      }
  }

  void fillJets()
  {
    Jet.resize(Jet_BTag.size());
    for(unsigned int i=0; i < Jet.size(); ++i)
      {
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

  void fillParticles()
  {
    Particle.resize(Particle_Charge.size());
    for(unsigned int i=0; i < Particle.size(); ++i)
      {
        Particle[i].Charge	= Particle_Charge[i];
        Particle[i].CtgTheta	= Particle_CtgTheta[i];
        Particle[i].D0	= Particle_D0[i];
        Particle[i].D1	= Particle_D1[i];
        Particle[i].D2	= Particle_D2[i];
        Particle[i].DZ	= Particle_DZ[i];
        Particle[i].E	= Particle_E[i];
        Particle[i].Eta	= Particle_Eta[i];
        Particle[i].IsPU	= Particle_IsPU[i];
        Particle[i].M1	= Particle_M1[i];
        Particle[i].M2	= Particle_M2[i];
        Particle[i].Mass	= Particle_Mass[i];
        Particle[i].P	= Particle_P[i];
        Particle[i].PID	= Particle_PID[i];
        Particle[i].PT	= Particle_PT[i];
        Particle[i].Phi	= Particle_Phi[i];
        Particle[i].Px	= Particle_Px[i];
        Particle[i].Py	= Particle_Py[i];
        Particle[i].Pz	= Particle_Pz[i];
        Particle[i].Rapidity	= Particle_Rapidity[i];
        Particle[i].Status	= Particle_Status[i];
        Particle[i].T	= Particle_T[i];
        Particle[i].X	= Particle_X[i];
        Particle[i].Y	= Particle_Y[i];
        Particle[i].Z	= Particle_Z[i];
        Particle[i].fBits	= Particle_fBits[i];
        Particle[i].fUniqueID	= Particle_fUniqueID[i];
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

  void fillTowers()
  {
    Tower.resize(Tower_E.size());
    for(unsigned int i=0; i < Tower.size(); ++i)
      {
        Tower[i].E	= Tower_E[i];
        Tower[i].ET	= Tower_ET[i];
        Tower[i].Eem	= Tower_Eem[i];
        Tower[i].Ehad	= Tower_Ehad[i];
        Tower[i].Eta	= Tower_Eta[i];
        Tower[i].NTimeHits	= Tower_NTimeHits[i];
        Tower[i].Phi	= Tower_Phi[i];
        Tower[i].T	= Tower_T[i];
        Tower[i].fBits	= Tower_fBits[i];
        Tower[i].fUniqueID	= Tower_fUniqueID[i];
      }
  }

  void fillTracks()
  {
    Track.resize(Track_Charge.size());
    for(unsigned int i=0; i < Track.size(); ++i)
      {
        Track[i].Charge	= Track_Charge[i];
        Track[i].CtgTheta	= Track_CtgTheta[i];
        Track[i].D0	= Track_D0[i];
        Track[i].DZ	= Track_DZ[i];
        Track[i].ErrorCtgTheta	= Track_ErrorCtgTheta[i];
        Track[i].ErrorD0	= Track_ErrorD0[i];
        Track[i].ErrorDZ	= Track_ErrorDZ[i];
        Track[i].ErrorP	= Track_ErrorP[i];
        Track[i].ErrorPT	= Track_ErrorPT[i];
        Track[i].ErrorPhi	= Track_ErrorPhi[i];
        Track[i].ErrorT	= Track_ErrorT[i];
        Track[i].Eta	= Track_Eta[i];
        Track[i].EtaOuter	= Track_EtaOuter[i];
        Track[i].L	= Track_L[i];
        Track[i].P	= Track_P[i];
        Track[i].PID	= Track_PID[i];
        Track[i].PT	= Track_PT[i];
        Track[i].Phi	= Track_Phi[i];
        Track[i].PhiOuter	= Track_PhiOuter[i];
        Track[i].T	= Track_T[i];
        Track[i].TOuter	= Track_TOuter[i];
        Track[i].VertexIndex	= Track_VertexIndex[i];
        Track[i].X	= Track_X[i];
        Track[i].XOuter	= Track_XOuter[i];
        Track[i].Xd	= Track_Xd[i];
        Track[i].Y	= Track_Y[i];
        Track[i].YOuter	= Track_YOuter[i];
        Track[i].Yd	= Track_Yd[i];
        Track[i].Z	= Track_Z[i];
        Track[i].ZOuter	= Track_ZOuter[i];
        Track[i].Zd	= Track_Zd[i];
        Track[i].fBits	= Track_fBits[i];
        Track[i].fUniqueID	= Track_fUniqueID[i];
      }
  }


  std::vector<eventBuffer::EFlowNeutralHadron_s> EFlowNeutralHadron;
  std::vector<eventBuffer::EFlowPhoton_s> EFlowPhoton;
  std::vector<eventBuffer::EFlowTrack_s> EFlowTrack;
  std::vector<eventBuffer::Electron_s> Electron;
  std::vector<eventBuffer::FatJet_s> FatJet;
  std::vector<eventBuffer::GenJet_s> GenJet;
  std::vector<eventBuffer::Jet_s> Jet;
  std::vector<eventBuffer::Muon_s> Muon;
  std::vector<eventBuffer::Particle_s> Particle;
  std::vector<eventBuffer::Photon_s> Photon;
  std::vector<eventBuffer::Tower_s> Tower;
  std::vector<eventBuffer::Track_s> Track;

  void fillObjects()
  {
    fillEFlowNeutralHadrons();
    fillEFlowPhotons();
    fillEFlowTracks();
    fillElectrons();
    fillFatJets();
    fillGenJets();
    fillJets();
    fillMuons();
    fillParticles();
    fillPhotons();
    fillTowers();
    fillTracks();
  }

   //--------------------------------------------------------------------------
  // Save objects for which the select function was called
  void saveObjects()
  {
    int n = 0;

    n = 0;
    try
      {
         n = indexmap["EFlowNeutralHadron"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["EFlowNeutralHadron"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            EFlowNeutralHadron_E[i]	= EFlowNeutralHadron_E[j];
            EFlowNeutralHadron_ET[i]	= EFlowNeutralHadron_ET[j];
            EFlowNeutralHadron_Eem[i]	= EFlowNeutralHadron_Eem[j];
            EFlowNeutralHadron_Ehad[i]	= EFlowNeutralHadron_Ehad[j];
            EFlowNeutralHadron_Eta[i]	= EFlowNeutralHadron_Eta[j];
            EFlowNeutralHadron_NTimeHits[i]	= EFlowNeutralHadron_NTimeHits[j];
            EFlowNeutralHadron_Phi[i]	= EFlowNeutralHadron_Phi[j];
            EFlowNeutralHadron_T[i]	= EFlowNeutralHadron_T[j];
            EFlowNeutralHadron_fBits[i]	= EFlowNeutralHadron_fBits[j];
            EFlowNeutralHadron_fUniqueID[i]	= EFlowNeutralHadron_fUniqueID[j];
          }
      }
    EFlowNeutralHadron_ = n;

    n = 0;
    try
      {
         n = indexmap["EFlowPhoton"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["EFlowPhoton"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            EFlowPhoton_E[i]	= EFlowPhoton_E[j];
            EFlowPhoton_ET[i]	= EFlowPhoton_ET[j];
            EFlowPhoton_Eem[i]	= EFlowPhoton_Eem[j];
            EFlowPhoton_Ehad[i]	= EFlowPhoton_Ehad[j];
            EFlowPhoton_Eta[i]	= EFlowPhoton_Eta[j];
            EFlowPhoton_NTimeHits[i]	= EFlowPhoton_NTimeHits[j];
            EFlowPhoton_Phi[i]	= EFlowPhoton_Phi[j];
            EFlowPhoton_T[i]	= EFlowPhoton_T[j];
            EFlowPhoton_fBits[i]	= EFlowPhoton_fBits[j];
            EFlowPhoton_fUniqueID[i]	= EFlowPhoton_fUniqueID[j];
          }
      }
    EFlowPhoton_ = n;

    n = 0;
    try
      {
         n = indexmap["EFlowTrack"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["EFlowTrack"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            EFlowTrack_Charge[i]	= EFlowTrack_Charge[j];
            EFlowTrack_CtgTheta[i]	= EFlowTrack_CtgTheta[j];
            EFlowTrack_D0[i]	= EFlowTrack_D0[j];
            EFlowTrack_DZ[i]	= EFlowTrack_DZ[j];
            EFlowTrack_ErrorCtgTheta[i]	= EFlowTrack_ErrorCtgTheta[j];
            EFlowTrack_ErrorD0[i]	= EFlowTrack_ErrorD0[j];
            EFlowTrack_ErrorDZ[i]	= EFlowTrack_ErrorDZ[j];
            EFlowTrack_ErrorP[i]	= EFlowTrack_ErrorP[j];
            EFlowTrack_ErrorPT[i]	= EFlowTrack_ErrorPT[j];
            EFlowTrack_ErrorPhi[i]	= EFlowTrack_ErrorPhi[j];
            EFlowTrack_ErrorT[i]	= EFlowTrack_ErrorT[j];
            EFlowTrack_Eta[i]	= EFlowTrack_Eta[j];
            EFlowTrack_EtaOuter[i]	= EFlowTrack_EtaOuter[j];
            EFlowTrack_L[i]	= EFlowTrack_L[j];
            EFlowTrack_P[i]	= EFlowTrack_P[j];
            EFlowTrack_PID[i]	= EFlowTrack_PID[j];
            EFlowTrack_PT[i]	= EFlowTrack_PT[j];
            EFlowTrack_Phi[i]	= EFlowTrack_Phi[j];
            EFlowTrack_PhiOuter[i]	= EFlowTrack_PhiOuter[j];
            EFlowTrack_T[i]	= EFlowTrack_T[j];
            EFlowTrack_TOuter[i]	= EFlowTrack_TOuter[j];
            EFlowTrack_VertexIndex[i]	= EFlowTrack_VertexIndex[j];
            EFlowTrack_X[i]	= EFlowTrack_X[j];
            EFlowTrack_XOuter[i]	= EFlowTrack_XOuter[j];
            EFlowTrack_Xd[i]	= EFlowTrack_Xd[j];
            EFlowTrack_Y[i]	= EFlowTrack_Y[j];
            EFlowTrack_YOuter[i]	= EFlowTrack_YOuter[j];
            EFlowTrack_Yd[i]	= EFlowTrack_Yd[j];
            EFlowTrack_Z[i]	= EFlowTrack_Z[j];
            EFlowTrack_ZOuter[i]	= EFlowTrack_ZOuter[j];
            EFlowTrack_Zd[i]	= EFlowTrack_Zd[j];
            EFlowTrack_fBits[i]	= EFlowTrack_fBits[j];
            EFlowTrack_fUniqueID[i]	= EFlowTrack_fUniqueID[j];
          }
      }
    EFlowTrack_ = n;

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
         n = indexmap["FatJet"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["FatJet"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            FatJet_BTag[i]	= FatJet_BTag[j];
            FatJet_BTagAlgo[i]	= FatJet_BTagAlgo[j];
            FatJet_BTagPhys[i]	= FatJet_BTagPhys[j];
            FatJet_Beta[i]	= FatJet_Beta[j];
            FatJet_BetaStar[i]	= FatJet_BetaStar[j];
            FatJet_Charge[i]	= FatJet_Charge[j];
            FatJet_DeltaEta[i]	= FatJet_DeltaEta[j];
            FatJet_DeltaPhi[i]	= FatJet_DeltaPhi[j];
            FatJet_EhadOverEem[i]	= FatJet_EhadOverEem[j];
            FatJet_Eta[i]	= FatJet_Eta[j];
            FatJet_Flavor[i]	= FatJet_Flavor[j];
            FatJet_FlavorAlgo[i]	= FatJet_FlavorAlgo[j];
            FatJet_FlavorPhys[i]	= FatJet_FlavorPhys[j];
            FatJet_Mass[i]	= FatJet_Mass[j];
            FatJet_MeanSqDeltaR[i]	= FatJet_MeanSqDeltaR[j];
            FatJet_NCharged[i]	= FatJet_NCharged[j];
            FatJet_NNeutrals[i]	= FatJet_NNeutrals[j];
            FatJet_NSubJetsPruned[i]	= FatJet_NSubJetsPruned[j];
            FatJet_NSubJetsSoftDropped[i]	= FatJet_NSubJetsSoftDropped[j];
            FatJet_NSubJetsTrimmed[i]	= FatJet_NSubJetsTrimmed[j];
            FatJet_PT[i]	= FatJet_PT[j];
            FatJet_PTD[i]	= FatJet_PTD[j];
            FatJet_Phi[i]	= FatJet_Phi[j];
            FatJet_T[i]	= FatJet_T[j];
            FatJet_TauTag[i]	= FatJet_TauTag[j];
            FatJet_fBits[i]	= FatJet_fBits[j];
            FatJet_fUniqueID[i]	= FatJet_fUniqueID[j];
          }
      }
    FatJet_ = n;

    n = 0;
    try
      {
         n = indexmap["GenJet"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["GenJet"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            GenJet_BTag[i]	= GenJet_BTag[j];
            GenJet_BTagAlgo[i]	= GenJet_BTagAlgo[j];
            GenJet_BTagPhys[i]	= GenJet_BTagPhys[j];
            GenJet_Beta[i]	= GenJet_Beta[j];
            GenJet_BetaStar[i]	= GenJet_BetaStar[j];
            GenJet_Charge[i]	= GenJet_Charge[j];
            GenJet_DeltaEta[i]	= GenJet_DeltaEta[j];
            GenJet_DeltaPhi[i]	= GenJet_DeltaPhi[j];
            GenJet_EhadOverEem[i]	= GenJet_EhadOverEem[j];
            GenJet_Eta[i]	= GenJet_Eta[j];
            GenJet_Flavor[i]	= GenJet_Flavor[j];
            GenJet_FlavorAlgo[i]	= GenJet_FlavorAlgo[j];
            GenJet_FlavorPhys[i]	= GenJet_FlavorPhys[j];
            GenJet_Mass[i]	= GenJet_Mass[j];
            GenJet_MeanSqDeltaR[i]	= GenJet_MeanSqDeltaR[j];
            GenJet_NCharged[i]	= GenJet_NCharged[j];
            GenJet_NNeutrals[i]	= GenJet_NNeutrals[j];
            GenJet_NSubJetsPruned[i]	= GenJet_NSubJetsPruned[j];
            GenJet_NSubJetsSoftDropped[i]	= GenJet_NSubJetsSoftDropped[j];
            GenJet_NSubJetsTrimmed[i]	= GenJet_NSubJetsTrimmed[j];
            GenJet_PT[i]	= GenJet_PT[j];
            GenJet_PTD[i]	= GenJet_PTD[j];
            GenJet_Phi[i]	= GenJet_Phi[j];
            GenJet_T[i]	= GenJet_T[j];
            GenJet_TauTag[i]	= GenJet_TauTag[j];
            GenJet_fBits[i]	= GenJet_fBits[j];
            GenJet_fUniqueID[i]	= GenJet_fUniqueID[j];
          }
      }
    GenJet_ = n;

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
         n = indexmap["Particle"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Particle"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Particle_Charge[i]	= Particle_Charge[j];
            Particle_CtgTheta[i]	= Particle_CtgTheta[j];
            Particle_D0[i]	= Particle_D0[j];
            Particle_D1[i]	= Particle_D1[j];
            Particle_D2[i]	= Particle_D2[j];
            Particle_DZ[i]	= Particle_DZ[j];
            Particle_E[i]	= Particle_E[j];
            Particle_Eta[i]	= Particle_Eta[j];
            Particle_IsPU[i]	= Particle_IsPU[j];
            Particle_M1[i]	= Particle_M1[j];
            Particle_M2[i]	= Particle_M2[j];
            Particle_Mass[i]	= Particle_Mass[j];
            Particle_P[i]	= Particle_P[j];
            Particle_PID[i]	= Particle_PID[j];
            Particle_PT[i]	= Particle_PT[j];
            Particle_Phi[i]	= Particle_Phi[j];
            Particle_Px[i]	= Particle_Px[j];
            Particle_Py[i]	= Particle_Py[j];
            Particle_Pz[i]	= Particle_Pz[j];
            Particle_Rapidity[i]	= Particle_Rapidity[j];
            Particle_Status[i]	= Particle_Status[j];
            Particle_T[i]	= Particle_T[j];
            Particle_X[i]	= Particle_X[j];
            Particle_Y[i]	= Particle_Y[j];
            Particle_Z[i]	= Particle_Z[j];
            Particle_fBits[i]	= Particle_fBits[j];
            Particle_fUniqueID[i]	= Particle_fUniqueID[j];
          }
      }
    Particle_ = n;

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

    n = 0;
    try
      {
         n = indexmap["Tower"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Tower"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Tower_E[i]	= Tower_E[j];
            Tower_ET[i]	= Tower_ET[j];
            Tower_Eem[i]	= Tower_Eem[j];
            Tower_Ehad[i]	= Tower_Ehad[j];
            Tower_Eta[i]	= Tower_Eta[j];
            Tower_NTimeHits[i]	= Tower_NTimeHits[j];
            Tower_Phi[i]	= Tower_Phi[j];
            Tower_T[i]	= Tower_T[j];
            Tower_fBits[i]	= Tower_fBits[j];
            Tower_fUniqueID[i]	= Tower_fUniqueID[j];
          }
      }
    Tower_ = n;

    n = 0;
    try
      {
         n = indexmap["Track"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Track"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Track_Charge[i]	= Track_Charge[j];
            Track_CtgTheta[i]	= Track_CtgTheta[j];
            Track_D0[i]	= Track_D0[j];
            Track_DZ[i]	= Track_DZ[j];
            Track_ErrorCtgTheta[i]	= Track_ErrorCtgTheta[j];
            Track_ErrorD0[i]	= Track_ErrorD0[j];
            Track_ErrorDZ[i]	= Track_ErrorDZ[j];
            Track_ErrorP[i]	= Track_ErrorP[j];
            Track_ErrorPT[i]	= Track_ErrorPT[j];
            Track_ErrorPhi[i]	= Track_ErrorPhi[j];
            Track_ErrorT[i]	= Track_ErrorT[j];
            Track_Eta[i]	= Track_Eta[j];
            Track_EtaOuter[i]	= Track_EtaOuter[j];
            Track_L[i]	= Track_L[j];
            Track_P[i]	= Track_P[j];
            Track_PID[i]	= Track_PID[j];
            Track_PT[i]	= Track_PT[j];
            Track_Phi[i]	= Track_Phi[j];
            Track_PhiOuter[i]	= Track_PhiOuter[j];
            Track_T[i]	= Track_T[j];
            Track_TOuter[i]	= Track_TOuter[j];
            Track_VertexIndex[i]	= Track_VertexIndex[j];
            Track_X[i]	= Track_X[j];
            Track_XOuter[i]	= Track_XOuter[j];
            Track_Xd[i]	= Track_Xd[j];
            Track_Y[i]	= Track_Y[j];
            Track_YOuter[i]	= Track_YOuter[j];
            Track_Yd[i]	= Track_Yd[j];
            Track_Z[i]	= Track_Z[j];
            Track_ZOuter[i]	= Track_ZOuter[j];
            Track_Zd[i]	= Track_Zd[j];
            Track_fBits[i]	= Track_fBits[j];
            Track_fUniqueID[i]	= Track_fUniqueID[j];
          }
      }
    Track_ = n;
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
    choose["EFlowNeutralHadron.E"]	= DEFAULT;
    choose["EFlowNeutralHadron.ET"]	= DEFAULT;
    choose["EFlowNeutralHadron.Eem"]	= DEFAULT;
    choose["EFlowNeutralHadron.Ehad"]	= DEFAULT;
    choose["EFlowNeutralHadron.Eta"]	= DEFAULT;
    choose["EFlowNeutralHadron.NTimeHits"]	= DEFAULT;
    choose["EFlowNeutralHadron.Phi"]	= DEFAULT;
    choose["EFlowNeutralHadron.T"]	= DEFAULT;
    choose["EFlowNeutralHadron.fBits"]	= DEFAULT;
    choose["EFlowNeutralHadron.fUniqueID"]	= DEFAULT;
    choose["EFlowNeutralHadron_size"]	= DEFAULT;
    choose["EFlowPhoton.E"]	= DEFAULT;
    choose["EFlowPhoton.ET"]	= DEFAULT;
    choose["EFlowPhoton.Eem"]	= DEFAULT;
    choose["EFlowPhoton.Ehad"]	= DEFAULT;
    choose["EFlowPhoton.Eta"]	= DEFAULT;
    choose["EFlowPhoton.NTimeHits"]	= DEFAULT;
    choose["EFlowPhoton.Phi"]	= DEFAULT;
    choose["EFlowPhoton.T"]	= DEFAULT;
    choose["EFlowPhoton.fBits"]	= DEFAULT;
    choose["EFlowPhoton.fUniqueID"]	= DEFAULT;
    choose["EFlowPhoton_size"]	= DEFAULT;
    choose["EFlowTrack.Charge"]	= DEFAULT;
    choose["EFlowTrack.CtgTheta"]	= DEFAULT;
    choose["EFlowTrack.D0"]	= DEFAULT;
    choose["EFlowTrack.DZ"]	= DEFAULT;
    choose["EFlowTrack.ErrorCtgTheta"]	= DEFAULT;
    choose["EFlowTrack.ErrorD0"]	= DEFAULT;
    choose["EFlowTrack.ErrorDZ"]	= DEFAULT;
    choose["EFlowTrack.ErrorP"]	= DEFAULT;
    choose["EFlowTrack.ErrorPT"]	= DEFAULT;
    choose["EFlowTrack.ErrorPhi"]	= DEFAULT;
    choose["EFlowTrack.ErrorT"]	= DEFAULT;
    choose["EFlowTrack.Eta"]	= DEFAULT;
    choose["EFlowTrack.EtaOuter"]	= DEFAULT;
    choose["EFlowTrack.L"]	= DEFAULT;
    choose["EFlowTrack.P"]	= DEFAULT;
    choose["EFlowTrack.PID"]	= DEFAULT;
    choose["EFlowTrack.PT"]	= DEFAULT;
    choose["EFlowTrack.Phi"]	= DEFAULT;
    choose["EFlowTrack.PhiOuter"]	= DEFAULT;
    choose["EFlowTrack.T"]	= DEFAULT;
    choose["EFlowTrack.TOuter"]	= DEFAULT;
    choose["EFlowTrack.VertexIndex"]	= DEFAULT;
    choose["EFlowTrack.X"]	= DEFAULT;
    choose["EFlowTrack.XOuter"]	= DEFAULT;
    choose["EFlowTrack.Xd"]	= DEFAULT;
    choose["EFlowTrack.Y"]	= DEFAULT;
    choose["EFlowTrack.YOuter"]	= DEFAULT;
    choose["EFlowTrack.Yd"]	= DEFAULT;
    choose["EFlowTrack.Z"]	= DEFAULT;
    choose["EFlowTrack.ZOuter"]	= DEFAULT;
    choose["EFlowTrack.Zd"]	= DEFAULT;
    choose["EFlowTrack.fBits"]	= DEFAULT;
    choose["EFlowTrack.fUniqueID"]	= DEFAULT;
    choose["EFlowTrack_size"]	= DEFAULT;
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
    choose["FatJet.BTag"]	= DEFAULT;
    choose["FatJet.BTagAlgo"]	= DEFAULT;
    choose["FatJet.BTagPhys"]	= DEFAULT;
    choose["FatJet.Beta"]	= DEFAULT;
    choose["FatJet.BetaStar"]	= DEFAULT;
    choose["FatJet.Charge"]	= DEFAULT;
    choose["FatJet.DeltaEta"]	= DEFAULT;
    choose["FatJet.DeltaPhi"]	= DEFAULT;
    choose["FatJet.EhadOverEem"]	= DEFAULT;
    choose["FatJet.Eta"]	= DEFAULT;
    choose["FatJet.Flavor"]	= DEFAULT;
    choose["FatJet.FlavorAlgo"]	= DEFAULT;
    choose["FatJet.FlavorPhys"]	= DEFAULT;
    choose["FatJet.Mass"]	= DEFAULT;
    choose["FatJet.MeanSqDeltaR"]	= DEFAULT;
    choose["FatJet.NCharged"]	= DEFAULT;
    choose["FatJet.NNeutrals"]	= DEFAULT;
    choose["FatJet.NSubJetsPruned"]	= DEFAULT;
    choose["FatJet.NSubJetsSoftDropped"]	= DEFAULT;
    choose["FatJet.NSubJetsTrimmed"]	= DEFAULT;
    choose["FatJet.PT"]	= DEFAULT;
    choose["FatJet.PTD"]	= DEFAULT;
    choose["FatJet.Phi"]	= DEFAULT;
    choose["FatJet.T"]	= DEFAULT;
    choose["FatJet.TauTag"]	= DEFAULT;
    choose["FatJet.fBits"]	= DEFAULT;
    choose["FatJet.fUniqueID"]	= DEFAULT;
    choose["FatJet_size"]	= DEFAULT;
    choose["GenJet.BTag"]	= DEFAULT;
    choose["GenJet.BTagAlgo"]	= DEFAULT;
    choose["GenJet.BTagPhys"]	= DEFAULT;
    choose["GenJet.Beta"]	= DEFAULT;
    choose["GenJet.BetaStar"]	= DEFAULT;
    choose["GenJet.Charge"]	= DEFAULT;
    choose["GenJet.DeltaEta"]	= DEFAULT;
    choose["GenJet.DeltaPhi"]	= DEFAULT;
    choose["GenJet.EhadOverEem"]	= DEFAULT;
    choose["GenJet.Eta"]	= DEFAULT;
    choose["GenJet.Flavor"]	= DEFAULT;
    choose["GenJet.FlavorAlgo"]	= DEFAULT;
    choose["GenJet.FlavorPhys"]	= DEFAULT;
    choose["GenJet.Mass"]	= DEFAULT;
    choose["GenJet.MeanSqDeltaR"]	= DEFAULT;
    choose["GenJet.NCharged"]	= DEFAULT;
    choose["GenJet.NNeutrals"]	= DEFAULT;
    choose["GenJet.NSubJetsPruned"]	= DEFAULT;
    choose["GenJet.NSubJetsSoftDropped"]	= DEFAULT;
    choose["GenJet.NSubJetsTrimmed"]	= DEFAULT;
    choose["GenJet.PT"]	= DEFAULT;
    choose["GenJet.PTD"]	= DEFAULT;
    choose["GenJet.Phi"]	= DEFAULT;
    choose["GenJet.T"]	= DEFAULT;
    choose["GenJet.TauTag"]	= DEFAULT;
    choose["GenJet.fBits"]	= DEFAULT;
    choose["GenJet.fUniqueID"]	= DEFAULT;
    choose["GenJet_size"]	= DEFAULT;
    choose["GenMissingET.Eta"]	= DEFAULT;
    choose["GenMissingET.MET"]	= DEFAULT;
    choose["GenMissingET.Phi"]	= DEFAULT;
    choose["GenMissingET.fBits"]	= DEFAULT;
    choose["GenMissingET.fUniqueID"]	= DEFAULT;
    choose["GenMissingET_size"]	= DEFAULT;
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
    choose["Particle.Charge"]	= DEFAULT;
    choose["Particle.CtgTheta"]	= DEFAULT;
    choose["Particle.D0"]	= DEFAULT;
    choose["Particle.D1"]	= DEFAULT;
    choose["Particle.D2"]	= DEFAULT;
    choose["Particle.DZ"]	= DEFAULT;
    choose["Particle.E"]	= DEFAULT;
    choose["Particle.Eta"]	= DEFAULT;
    choose["Particle.IsPU"]	= DEFAULT;
    choose["Particle.M1"]	= DEFAULT;
    choose["Particle.M2"]	= DEFAULT;
    choose["Particle.Mass"]	= DEFAULT;
    choose["Particle.P"]	= DEFAULT;
    choose["Particle.PID"]	= DEFAULT;
    choose["Particle.PT"]	= DEFAULT;
    choose["Particle.Phi"]	= DEFAULT;
    choose["Particle.Px"]	= DEFAULT;
    choose["Particle.Py"]	= DEFAULT;
    choose["Particle.Pz"]	= DEFAULT;
    choose["Particle.Rapidity"]	= DEFAULT;
    choose["Particle.Status"]	= DEFAULT;
    choose["Particle.T"]	= DEFAULT;
    choose["Particle.X"]	= DEFAULT;
    choose["Particle.Y"]	= DEFAULT;
    choose["Particle.Z"]	= DEFAULT;
    choose["Particle.fBits"]	= DEFAULT;
    choose["Particle.fUniqueID"]	= DEFAULT;
    choose["Particle_size"]	= DEFAULT;
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
    choose["ScalarHT.HT"]	= DEFAULT;
    choose["ScalarHT.fBits"]	= DEFAULT;
    choose["ScalarHT.fUniqueID"]	= DEFAULT;
    choose["ScalarHT_size"]	= DEFAULT;
    choose["Tower.E"]	= DEFAULT;
    choose["Tower.ET"]	= DEFAULT;
    choose["Tower.Eem"]	= DEFAULT;
    choose["Tower.Ehad"]	= DEFAULT;
    choose["Tower.Eta"]	= DEFAULT;
    choose["Tower.NTimeHits"]	= DEFAULT;
    choose["Tower.Phi"]	= DEFAULT;
    choose["Tower.T"]	= DEFAULT;
    choose["Tower.fBits"]	= DEFAULT;
    choose["Tower.fUniqueID"]	= DEFAULT;
    choose["Tower_size"]	= DEFAULT;
    choose["Track.Charge"]	= DEFAULT;
    choose["Track.CtgTheta"]	= DEFAULT;
    choose["Track.D0"]	= DEFAULT;
    choose["Track.DZ"]	= DEFAULT;
    choose["Track.ErrorCtgTheta"]	= DEFAULT;
    choose["Track.ErrorD0"]	= DEFAULT;
    choose["Track.ErrorDZ"]	= DEFAULT;
    choose["Track.ErrorP"]	= DEFAULT;
    choose["Track.ErrorPT"]	= DEFAULT;
    choose["Track.ErrorPhi"]	= DEFAULT;
    choose["Track.ErrorT"]	= DEFAULT;
    choose["Track.Eta"]	= DEFAULT;
    choose["Track.EtaOuter"]	= DEFAULT;
    choose["Track.L"]	= DEFAULT;
    choose["Track.P"]	= DEFAULT;
    choose["Track.PID"]	= DEFAULT;
    choose["Track.PT"]	= DEFAULT;
    choose["Track.Phi"]	= DEFAULT;
    choose["Track.PhiOuter"]	= DEFAULT;
    choose["Track.T"]	= DEFAULT;
    choose["Track.TOuter"]	= DEFAULT;
    choose["Track.VertexIndex"]	= DEFAULT;
    choose["Track.X"]	= DEFAULT;
    choose["Track.XOuter"]	= DEFAULT;
    choose["Track.Xd"]	= DEFAULT;
    choose["Track.Y"]	= DEFAULT;
    choose["Track.YOuter"]	= DEFAULT;
    choose["Track.Yd"]	= DEFAULT;
    choose["Track.Z"]	= DEFAULT;
    choose["Track.ZOuter"]	= DEFAULT;
    choose["Track.Zd"]	= DEFAULT;
    choose["Track.fBits"]	= DEFAULT;
    choose["Track.fUniqueID"]	= DEFAULT;
    choose["Track_size"]	= DEFAULT;

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
    if ( choose["EFlowNeutralHadron.E"] )
      input->select("Delphes/EFlowNeutralHadron.E", 	EFlowNeutralHadron_E);
    if ( choose["EFlowNeutralHadron.ET"] )
      input->select("Delphes/EFlowNeutralHadron.ET",
                     EFlowNeutralHadron_ET);
    if ( choose["EFlowNeutralHadron.Eem"] )
      input->select("Delphes/EFlowNeutralHadron.Eem",
                     EFlowNeutralHadron_Eem);
    if ( choose["EFlowNeutralHadron.Ehad"] )
      input->select("Delphes/EFlowNeutralHadron.Ehad",
                     EFlowNeutralHadron_Ehad);
    if ( choose["EFlowNeutralHadron.Eta"] )
      input->select("Delphes/EFlowNeutralHadron.Eta",
                     EFlowNeutralHadron_Eta);
    if ( choose["EFlowNeutralHadron.NTimeHits"] )
      input->select("Delphes/EFlowNeutralHadron.NTimeHits",
                     EFlowNeutralHadron_NTimeHits);
    if ( choose["EFlowNeutralHadron.Phi"] )
      input->select("Delphes/EFlowNeutralHadron.Phi",
                     EFlowNeutralHadron_Phi);
    if ( choose["EFlowNeutralHadron.T"] )
      input->select("Delphes/EFlowNeutralHadron.T", 	EFlowNeutralHadron_T);
    if ( choose["EFlowNeutralHadron.fBits"] )
      input->select("Delphes/EFlowNeutralHadron.fBits",
                     EFlowNeutralHadron_fBits);
    if ( choose["EFlowNeutralHadron.fUniqueID"] )
      input->select("Delphes/EFlowNeutralHadron.fUniqueID",
                     EFlowNeutralHadron_fUniqueID);
    if ( choose["EFlowNeutralHadron_size"] )
      input->select("Delphes/EFlowNeutralHadron_size",
                     EFlowNeutralHadron_size);
    if ( choose["EFlowPhoton.E"] )
      input->select("Delphes/EFlowPhoton.E", 	EFlowPhoton_E);
    if ( choose["EFlowPhoton.ET"] )
      input->select("Delphes/EFlowPhoton.ET", 	EFlowPhoton_ET);
    if ( choose["EFlowPhoton.Eem"] )
      input->select("Delphes/EFlowPhoton.Eem", 	EFlowPhoton_Eem);
    if ( choose["EFlowPhoton.Ehad"] )
      input->select("Delphes/EFlowPhoton.Ehad", 	EFlowPhoton_Ehad);
    if ( choose["EFlowPhoton.Eta"] )
      input->select("Delphes/EFlowPhoton.Eta", 	EFlowPhoton_Eta);
    if ( choose["EFlowPhoton.NTimeHits"] )
      input->select("Delphes/EFlowPhoton.NTimeHits",
                     EFlowPhoton_NTimeHits);
    if ( choose["EFlowPhoton.Phi"] )
      input->select("Delphes/EFlowPhoton.Phi", 	EFlowPhoton_Phi);
    if ( choose["EFlowPhoton.T"] )
      input->select("Delphes/EFlowPhoton.T", 	EFlowPhoton_T);
    if ( choose["EFlowPhoton.fBits"] )
      input->select("Delphes/EFlowPhoton.fBits", 	EFlowPhoton_fBits);
    if ( choose["EFlowPhoton.fUniqueID"] )
      input->select("Delphes/EFlowPhoton.fUniqueID",
                     EFlowPhoton_fUniqueID);
    if ( choose["EFlowPhoton_size"] )
      input->select("Delphes/EFlowPhoton_size", 	EFlowPhoton_size);
    if ( choose["EFlowTrack.Charge"] )
      input->select("Delphes/EFlowTrack.Charge", 	EFlowTrack_Charge);
    if ( choose["EFlowTrack.CtgTheta"] )
      input->select("Delphes/EFlowTrack.CtgTheta", 	EFlowTrack_CtgTheta);
    if ( choose["EFlowTrack.D0"] )
      input->select("Delphes/EFlowTrack.D0", 	EFlowTrack_D0);
    if ( choose["EFlowTrack.DZ"] )
      input->select("Delphes/EFlowTrack.DZ", 	EFlowTrack_DZ);
    if ( choose["EFlowTrack.ErrorCtgTheta"] )
      input->select("Delphes/EFlowTrack.ErrorCtgTheta",
                     EFlowTrack_ErrorCtgTheta);
    if ( choose["EFlowTrack.ErrorD0"] )
      input->select("Delphes/EFlowTrack.ErrorD0", 	EFlowTrack_ErrorD0);
    if ( choose["EFlowTrack.ErrorDZ"] )
      input->select("Delphes/EFlowTrack.ErrorDZ", 	EFlowTrack_ErrorDZ);
    if ( choose["EFlowTrack.ErrorP"] )
      input->select("Delphes/EFlowTrack.ErrorP", 	EFlowTrack_ErrorP);
    if ( choose["EFlowTrack.ErrorPT"] )
      input->select("Delphes/EFlowTrack.ErrorPT", 	EFlowTrack_ErrorPT);
    if ( choose["EFlowTrack.ErrorPhi"] )
      input->select("Delphes/EFlowTrack.ErrorPhi", 	EFlowTrack_ErrorPhi);
    if ( choose["EFlowTrack.ErrorT"] )
      input->select("Delphes/EFlowTrack.ErrorT", 	EFlowTrack_ErrorT);
    if ( choose["EFlowTrack.Eta"] )
      input->select("Delphes/EFlowTrack.Eta", 	EFlowTrack_Eta);
    if ( choose["EFlowTrack.EtaOuter"] )
      input->select("Delphes/EFlowTrack.EtaOuter", 	EFlowTrack_EtaOuter);
    if ( choose["EFlowTrack.L"] )
      input->select("Delphes/EFlowTrack.L", 	EFlowTrack_L);
    if ( choose["EFlowTrack.P"] )
      input->select("Delphes/EFlowTrack.P", 	EFlowTrack_P);
    if ( choose["EFlowTrack.PID"] )
      input->select("Delphes/EFlowTrack.PID", 	EFlowTrack_PID);
    if ( choose["EFlowTrack.PT"] )
      input->select("Delphes/EFlowTrack.PT", 	EFlowTrack_PT);
    if ( choose["EFlowTrack.Phi"] )
      input->select("Delphes/EFlowTrack.Phi", 	EFlowTrack_Phi);
    if ( choose["EFlowTrack.PhiOuter"] )
      input->select("Delphes/EFlowTrack.PhiOuter", 	EFlowTrack_PhiOuter);
    if ( choose["EFlowTrack.T"] )
      input->select("Delphes/EFlowTrack.T", 	EFlowTrack_T);
    if ( choose["EFlowTrack.TOuter"] )
      input->select("Delphes/EFlowTrack.TOuter", 	EFlowTrack_TOuter);
    if ( choose["EFlowTrack.VertexIndex"] )
      input->select("Delphes/EFlowTrack.VertexIndex",
                     EFlowTrack_VertexIndex);
    if ( choose["EFlowTrack.X"] )
      input->select("Delphes/EFlowTrack.X", 	EFlowTrack_X);
    if ( choose["EFlowTrack.XOuter"] )
      input->select("Delphes/EFlowTrack.XOuter", 	EFlowTrack_XOuter);
    if ( choose["EFlowTrack.Xd"] )
      input->select("Delphes/EFlowTrack.Xd", 	EFlowTrack_Xd);
    if ( choose["EFlowTrack.Y"] )
      input->select("Delphes/EFlowTrack.Y", 	EFlowTrack_Y);
    if ( choose["EFlowTrack.YOuter"] )
      input->select("Delphes/EFlowTrack.YOuter", 	EFlowTrack_YOuter);
    if ( choose["EFlowTrack.Yd"] )
      input->select("Delphes/EFlowTrack.Yd", 	EFlowTrack_Yd);
    if ( choose["EFlowTrack.Z"] )
      input->select("Delphes/EFlowTrack.Z", 	EFlowTrack_Z);
    if ( choose["EFlowTrack.ZOuter"] )
      input->select("Delphes/EFlowTrack.ZOuter", 	EFlowTrack_ZOuter);
    if ( choose["EFlowTrack.Zd"] )
      input->select("Delphes/EFlowTrack.Zd", 	EFlowTrack_Zd);
    if ( choose["EFlowTrack.fBits"] )
      input->select("Delphes/EFlowTrack.fBits", 	EFlowTrack_fBits);
    if ( choose["EFlowTrack.fUniqueID"] )
      input->select("Delphes/EFlowTrack.fUniqueID", 	EFlowTrack_fUniqueID);
    if ( choose["EFlowTrack_size"] )
      input->select("Delphes/EFlowTrack_size", 	EFlowTrack_size);
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
    if ( choose["FatJet.BTag"] )
      input->select("Delphes/FatJet.BTag", 	FatJet_BTag);
    if ( choose["FatJet.BTagAlgo"] )
      input->select("Delphes/FatJet.BTagAlgo", 	FatJet_BTagAlgo);
    if ( choose["FatJet.BTagPhys"] )
      input->select("Delphes/FatJet.BTagPhys", 	FatJet_BTagPhys);
    if ( choose["FatJet.Beta"] )
      input->select("Delphes/FatJet.Beta", 	FatJet_Beta);
    if ( choose["FatJet.BetaStar"] )
      input->select("Delphes/FatJet.BetaStar", 	FatJet_BetaStar);
    if ( choose["FatJet.Charge"] )
      input->select("Delphes/FatJet.Charge", 	FatJet_Charge);
    if ( choose["FatJet.DeltaEta"] )
      input->select("Delphes/FatJet.DeltaEta", 	FatJet_DeltaEta);
    if ( choose["FatJet.DeltaPhi"] )
      input->select("Delphes/FatJet.DeltaPhi", 	FatJet_DeltaPhi);
    if ( choose["FatJet.EhadOverEem"] )
      input->select("Delphes/FatJet.EhadOverEem", 	FatJet_EhadOverEem);
    if ( choose["FatJet.Eta"] )
      input->select("Delphes/FatJet.Eta", 	FatJet_Eta);
    if ( choose["FatJet.Flavor"] )
      input->select("Delphes/FatJet.Flavor", 	FatJet_Flavor);
    if ( choose["FatJet.FlavorAlgo"] )
      input->select("Delphes/FatJet.FlavorAlgo", 	FatJet_FlavorAlgo);
    if ( choose["FatJet.FlavorPhys"] )
      input->select("Delphes/FatJet.FlavorPhys", 	FatJet_FlavorPhys);
    if ( choose["FatJet.Mass"] )
      input->select("Delphes/FatJet.Mass", 	FatJet_Mass);
    if ( choose["FatJet.MeanSqDeltaR"] )
      input->select("Delphes/FatJet.MeanSqDeltaR", 	FatJet_MeanSqDeltaR);
    if ( choose["FatJet.NCharged"] )
      input->select("Delphes/FatJet.NCharged", 	FatJet_NCharged);
    if ( choose["FatJet.NNeutrals"] )
      input->select("Delphes/FatJet.NNeutrals", 	FatJet_NNeutrals);
    if ( choose["FatJet.NSubJetsPruned"] )
      input->select("Delphes/FatJet.NSubJetsPruned",
                     FatJet_NSubJetsPruned);
    if ( choose["FatJet.NSubJetsSoftDropped"] )
      input->select("Delphes/FatJet.NSubJetsSoftDropped",
                     FatJet_NSubJetsSoftDropped);
    if ( choose["FatJet.NSubJetsTrimmed"] )
      input->select("Delphes/FatJet.NSubJetsTrimmed",
                     FatJet_NSubJetsTrimmed);
    if ( choose["FatJet.PT"] )
      input->select("Delphes/FatJet.PT", 	FatJet_PT);
    if ( choose["FatJet.PTD"] )
      input->select("Delphes/FatJet.PTD", 	FatJet_PTD);
    if ( choose["FatJet.Phi"] )
      input->select("Delphes/FatJet.Phi", 	FatJet_Phi);
    if ( choose["FatJet.T"] )
      input->select("Delphes/FatJet.T", 	FatJet_T);
    if ( choose["FatJet.TauTag"] )
      input->select("Delphes/FatJet.TauTag", 	FatJet_TauTag);
    if ( choose["FatJet.fBits"] )
      input->select("Delphes/FatJet.fBits", 	FatJet_fBits);
    if ( choose["FatJet.fUniqueID"] )
      input->select("Delphes/FatJet.fUniqueID", 	FatJet_fUniqueID);
    if ( choose["FatJet_size"] )
      input->select("Delphes/FatJet_size", 	FatJet_size);
    if ( choose["GenJet.BTag"] )
      input->select("Delphes/GenJet.BTag", 	GenJet_BTag);
    if ( choose["GenJet.BTagAlgo"] )
      input->select("Delphes/GenJet.BTagAlgo", 	GenJet_BTagAlgo);
    if ( choose["GenJet.BTagPhys"] )
      input->select("Delphes/GenJet.BTagPhys", 	GenJet_BTagPhys);
    if ( choose["GenJet.Beta"] )
      input->select("Delphes/GenJet.Beta", 	GenJet_Beta);
    if ( choose["GenJet.BetaStar"] )
      input->select("Delphes/GenJet.BetaStar", 	GenJet_BetaStar);
    if ( choose["GenJet.Charge"] )
      input->select("Delphes/GenJet.Charge", 	GenJet_Charge);
    if ( choose["GenJet.DeltaEta"] )
      input->select("Delphes/GenJet.DeltaEta", 	GenJet_DeltaEta);
    if ( choose["GenJet.DeltaPhi"] )
      input->select("Delphes/GenJet.DeltaPhi", 	GenJet_DeltaPhi);
    if ( choose["GenJet.EhadOverEem"] )
      input->select("Delphes/GenJet.EhadOverEem", 	GenJet_EhadOverEem);
    if ( choose["GenJet.Eta"] )
      input->select("Delphes/GenJet.Eta", 	GenJet_Eta);
    if ( choose["GenJet.Flavor"] )
      input->select("Delphes/GenJet.Flavor", 	GenJet_Flavor);
    if ( choose["GenJet.FlavorAlgo"] )
      input->select("Delphes/GenJet.FlavorAlgo", 	GenJet_FlavorAlgo);
    if ( choose["GenJet.FlavorPhys"] )
      input->select("Delphes/GenJet.FlavorPhys", 	GenJet_FlavorPhys);
    if ( choose["GenJet.Mass"] )
      input->select("Delphes/GenJet.Mass", 	GenJet_Mass);
    if ( choose["GenJet.MeanSqDeltaR"] )
      input->select("Delphes/GenJet.MeanSqDeltaR", 	GenJet_MeanSqDeltaR);
    if ( choose["GenJet.NCharged"] )
      input->select("Delphes/GenJet.NCharged", 	GenJet_NCharged);
    if ( choose["GenJet.NNeutrals"] )
      input->select("Delphes/GenJet.NNeutrals", 	GenJet_NNeutrals);
    if ( choose["GenJet.NSubJetsPruned"] )
      input->select("Delphes/GenJet.NSubJetsPruned",
                     GenJet_NSubJetsPruned);
    if ( choose["GenJet.NSubJetsSoftDropped"] )
      input->select("Delphes/GenJet.NSubJetsSoftDropped",
                     GenJet_NSubJetsSoftDropped);
    if ( choose["GenJet.NSubJetsTrimmed"] )
      input->select("Delphes/GenJet.NSubJetsTrimmed",
                     GenJet_NSubJetsTrimmed);
    if ( choose["GenJet.PT"] )
      input->select("Delphes/GenJet.PT", 	GenJet_PT);
    if ( choose["GenJet.PTD"] )
      input->select("Delphes/GenJet.PTD", 	GenJet_PTD);
    if ( choose["GenJet.Phi"] )
      input->select("Delphes/GenJet.Phi", 	GenJet_Phi);
    if ( choose["GenJet.T"] )
      input->select("Delphes/GenJet.T", 	GenJet_T);
    if ( choose["GenJet.TauTag"] )
      input->select("Delphes/GenJet.TauTag", 	GenJet_TauTag);
    if ( choose["GenJet.fBits"] )
      input->select("Delphes/GenJet.fBits", 	GenJet_fBits);
    if ( choose["GenJet.fUniqueID"] )
      input->select("Delphes/GenJet.fUniqueID", 	GenJet_fUniqueID);
    if ( choose["GenJet_size"] )
      input->select("Delphes/GenJet_size", 	GenJet_size);
    if ( choose["GenMissingET.Eta"] )
      input->select("Delphes/GenMissingET.Eta", 	GenMissingET_Eta);
    if ( choose["GenMissingET.MET"] )
      input->select("Delphes/GenMissingET.MET", 	GenMissingET_MET);
    if ( choose["GenMissingET.Phi"] )
      input->select("Delphes/GenMissingET.Phi", 	GenMissingET_Phi);
    if ( choose["GenMissingET.fBits"] )
      input->select("Delphes/GenMissingET.fBits", 	GenMissingET_fBits);
    if ( choose["GenMissingET.fUniqueID"] )
      input->select("Delphes/GenMissingET.fUniqueID",
                     GenMissingET_fUniqueID);
    if ( choose["GenMissingET_size"] )
      input->select("Delphes/GenMissingET_size", 	GenMissingET_size);
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
    if ( choose["Particle.Charge"] )
      input->select("Delphes/Particle.Charge", 	Particle_Charge);
    if ( choose["Particle.CtgTheta"] )
      input->select("Delphes/Particle.CtgTheta", 	Particle_CtgTheta);
    if ( choose["Particle.D0"] )
      input->select("Delphes/Particle.D0", 	Particle_D0);
    if ( choose["Particle.D1"] )
      input->select("Delphes/Particle.D1", 	Particle_D1);
    if ( choose["Particle.D2"] )
      input->select("Delphes/Particle.D2", 	Particle_D2);
    if ( choose["Particle.DZ"] )
      input->select("Delphes/Particle.DZ", 	Particle_DZ);
    if ( choose["Particle.E"] )
      input->select("Delphes/Particle.E", 	Particle_E);
    if ( choose["Particle.Eta"] )
      input->select("Delphes/Particle.Eta", 	Particle_Eta);
    if ( choose["Particle.IsPU"] )
      input->select("Delphes/Particle.IsPU", 	Particle_IsPU);
    if ( choose["Particle.M1"] )
      input->select("Delphes/Particle.M1", 	Particle_M1);
    if ( choose["Particle.M2"] )
      input->select("Delphes/Particle.M2", 	Particle_M2);
    if ( choose["Particle.Mass"] )
      input->select("Delphes/Particle.Mass", 	Particle_Mass);
    if ( choose["Particle.P"] )
      input->select("Delphes/Particle.P", 	Particle_P);
    if ( choose["Particle.PID"] )
      input->select("Delphes/Particle.PID", 	Particle_PID);
    if ( choose["Particle.PT"] )
      input->select("Delphes/Particle.PT", 	Particle_PT);
    if ( choose["Particle.Phi"] )
      input->select("Delphes/Particle.Phi", 	Particle_Phi);
    if ( choose["Particle.Px"] )
      input->select("Delphes/Particle.Px", 	Particle_Px);
    if ( choose["Particle.Py"] )
      input->select("Delphes/Particle.Py", 	Particle_Py);
    if ( choose["Particle.Pz"] )
      input->select("Delphes/Particle.Pz", 	Particle_Pz);
    if ( choose["Particle.Rapidity"] )
      input->select("Delphes/Particle.Rapidity", 	Particle_Rapidity);
    if ( choose["Particle.Status"] )
      input->select("Delphes/Particle.Status", 	Particle_Status);
    if ( choose["Particle.T"] )
      input->select("Delphes/Particle.T", 	Particle_T);
    if ( choose["Particle.X"] )
      input->select("Delphes/Particle.X", 	Particle_X);
    if ( choose["Particle.Y"] )
      input->select("Delphes/Particle.Y", 	Particle_Y);
    if ( choose["Particle.Z"] )
      input->select("Delphes/Particle.Z", 	Particle_Z);
    if ( choose["Particle.fBits"] )
      input->select("Delphes/Particle.fBits", 	Particle_fBits);
    if ( choose["Particle.fUniqueID"] )
      input->select("Delphes/Particle.fUniqueID", 	Particle_fUniqueID);
    if ( choose["Particle_size"] )
      input->select("Delphes/Particle_size", 	Particle_size);
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
    if ( choose["ScalarHT.HT"] )
      input->select("Delphes/ScalarHT.HT", 	ScalarHT_HT);
    if ( choose["ScalarHT.fBits"] )
      input->select("Delphes/ScalarHT.fBits", 	ScalarHT_fBits);
    if ( choose["ScalarHT.fUniqueID"] )
      input->select("Delphes/ScalarHT.fUniqueID", 	ScalarHT_fUniqueID);
    if ( choose["ScalarHT_size"] )
      input->select("Delphes/ScalarHT_size", 	ScalarHT_size);
    if ( choose["Tower.E"] )
      input->select("Delphes/Tower.E", 	Tower_E);
    if ( choose["Tower.ET"] )
      input->select("Delphes/Tower.ET", 	Tower_ET);
    if ( choose["Tower.Eem"] )
      input->select("Delphes/Tower.Eem", 	Tower_Eem);
    if ( choose["Tower.Ehad"] )
      input->select("Delphes/Tower.Ehad", 	Tower_Ehad);
    if ( choose["Tower.Eta"] )
      input->select("Delphes/Tower.Eta", 	Tower_Eta);
    if ( choose["Tower.NTimeHits"] )
      input->select("Delphes/Tower.NTimeHits", 	Tower_NTimeHits);
    if ( choose["Tower.Phi"] )
      input->select("Delphes/Tower.Phi", 	Tower_Phi);
    if ( choose["Tower.T"] )
      input->select("Delphes/Tower.T", 	Tower_T);
    if ( choose["Tower.fBits"] )
      input->select("Delphes/Tower.fBits", 	Tower_fBits);
    if ( choose["Tower.fUniqueID"] )
      input->select("Delphes/Tower.fUniqueID", 	Tower_fUniqueID);
    if ( choose["Tower_size"] )
      input->select("Delphes/Tower_size", 	Tower_size);
    if ( choose["Track.Charge"] )
      input->select("Delphes/Track.Charge", 	Track_Charge);
    if ( choose["Track.CtgTheta"] )
      input->select("Delphes/Track.CtgTheta", 	Track_CtgTheta);
    if ( choose["Track.D0"] )
      input->select("Delphes/Track.D0", 	Track_D0);
    if ( choose["Track.DZ"] )
      input->select("Delphes/Track.DZ", 	Track_DZ);
    if ( choose["Track.ErrorCtgTheta"] )
      input->select("Delphes/Track.ErrorCtgTheta", 	Track_ErrorCtgTheta);
    if ( choose["Track.ErrorD0"] )
      input->select("Delphes/Track.ErrorD0", 	Track_ErrorD0);
    if ( choose["Track.ErrorDZ"] )
      input->select("Delphes/Track.ErrorDZ", 	Track_ErrorDZ);
    if ( choose["Track.ErrorP"] )
      input->select("Delphes/Track.ErrorP", 	Track_ErrorP);
    if ( choose["Track.ErrorPT"] )
      input->select("Delphes/Track.ErrorPT", 	Track_ErrorPT);
    if ( choose["Track.ErrorPhi"] )
      input->select("Delphes/Track.ErrorPhi", 	Track_ErrorPhi);
    if ( choose["Track.ErrorT"] )
      input->select("Delphes/Track.ErrorT", 	Track_ErrorT);
    if ( choose["Track.Eta"] )
      input->select("Delphes/Track.Eta", 	Track_Eta);
    if ( choose["Track.EtaOuter"] )
      input->select("Delphes/Track.EtaOuter", 	Track_EtaOuter);
    if ( choose["Track.L"] )
      input->select("Delphes/Track.L", 	Track_L);
    if ( choose["Track.P"] )
      input->select("Delphes/Track.P", 	Track_P);
    if ( choose["Track.PID"] )
      input->select("Delphes/Track.PID", 	Track_PID);
    if ( choose["Track.PT"] )
      input->select("Delphes/Track.PT", 	Track_PT);
    if ( choose["Track.Phi"] )
      input->select("Delphes/Track.Phi", 	Track_Phi);
    if ( choose["Track.PhiOuter"] )
      input->select("Delphes/Track.PhiOuter", 	Track_PhiOuter);
    if ( choose["Track.T"] )
      input->select("Delphes/Track.T", 	Track_T);
    if ( choose["Track.TOuter"] )
      input->select("Delphes/Track.TOuter", 	Track_TOuter);
    if ( choose["Track.VertexIndex"] )
      input->select("Delphes/Track.VertexIndex", 	Track_VertexIndex);
    if ( choose["Track.X"] )
      input->select("Delphes/Track.X", 	Track_X);
    if ( choose["Track.XOuter"] )
      input->select("Delphes/Track.XOuter", 	Track_XOuter);
    if ( choose["Track.Xd"] )
      input->select("Delphes/Track.Xd", 	Track_Xd);
    if ( choose["Track.Y"] )
      input->select("Delphes/Track.Y", 	Track_Y);
    if ( choose["Track.YOuter"] )
      input->select("Delphes/Track.YOuter", 	Track_YOuter);
    if ( choose["Track.Yd"] )
      input->select("Delphes/Track.Yd", 	Track_Yd);
    if ( choose["Track.Z"] )
      input->select("Delphes/Track.Z", 	Track_Z);
    if ( choose["Track.ZOuter"] )
      input->select("Delphes/Track.ZOuter", 	Track_ZOuter);
    if ( choose["Track.Zd"] )
      input->select("Delphes/Track.Zd", 	Track_Zd);
    if ( choose["Track.fBits"] )
      input->select("Delphes/Track.fBits", 	Track_fBits);
    if ( choose["Track.fUniqueID"] )
      input->select("Delphes/Track.fUniqueID", 	Track_fUniqueID);
    if ( choose["Track_size"] )
      input->select("Delphes/Track_size", 	Track_size);

  }

  // A write-only buffer
  eventBuffer(otreestream& stream)
  : input(0),
    output(&stream)
  {
    initBuffers();

    output->add("Tower_", 	Tower_);
    output->add("MissingET_", 	MissingET_);
    output->add("Photon_", 	Photon_);
    output->add("Track_", 	Track_);
    output->add("ScalarHT_", 	ScalarHT_);
    output->add("EFlowPhoton_", 	EFlowPhoton_);
    output->add("FatJet_", 	FatJet_);
    output->add("Event_", 	Event_);
    output->add("EFlowNeutralHadron_", 	EFlowNeutralHadron_);
    output->add("Jet_", 	Jet_);
    output->add("Muon_", 	Muon_);
    output->add("Electron_", 	Electron_);
    output->add("GenJet_", 	GenJet_);
    output->add("Particle_", 	Particle_);
    output->add("GenMissingET_", 	GenMissingET_);
    output->add("EFlowTrack_", 	EFlowTrack_);
  
    output->add("Delphes/EFlowNeutralHadron.E[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_E);
    output->add("Delphes/EFlowNeutralHadron.ET[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_ET);
    output->add("Delphes/EFlowNeutralHadron.Eem[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Eem);
    output->add("Delphes/EFlowNeutralHadron.Ehad[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Ehad);
    output->add("Delphes/EFlowNeutralHadron.Eta[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Eta);
    output->add("Delphes/EFlowNeutralHadron.NTimeHits[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_NTimeHits);
    output->add("Delphes/EFlowNeutralHadron.Phi[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Phi);
    output->add("Delphes/EFlowNeutralHadron.T[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_T);
    output->add("Delphes/EFlowNeutralHadron.fBits[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_fBits);
    output->add("Delphes/EFlowNeutralHadron.fUniqueID[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_fUniqueID);
    output->add("Delphes/EFlowNeutralHadron_size",
                 EFlowNeutralHadron_size);
    output->add("Delphes/EFlowPhoton.E[EFlowPhoton_]", 	EFlowPhoton_E);
    output->add("Delphes/EFlowPhoton.ET[EFlowPhoton_]", 	EFlowPhoton_ET);
    output->add("Delphes/EFlowPhoton.Eem[EFlowPhoton_]", 	EFlowPhoton_Eem);
    output->add("Delphes/EFlowPhoton.Ehad[EFlowPhoton_]",
                 EFlowPhoton_Ehad);
    output->add("Delphes/EFlowPhoton.Eta[EFlowPhoton_]", 	EFlowPhoton_Eta);
    output->add("Delphes/EFlowPhoton.NTimeHits[EFlowPhoton_]",
                 EFlowPhoton_NTimeHits);
    output->add("Delphes/EFlowPhoton.Phi[EFlowPhoton_]", 	EFlowPhoton_Phi);
    output->add("Delphes/EFlowPhoton.T[EFlowPhoton_]", 	EFlowPhoton_T);
    output->add("Delphes/EFlowPhoton.fBits[EFlowPhoton_]",
                 EFlowPhoton_fBits);
    output->add("Delphes/EFlowPhoton.fUniqueID[EFlowPhoton_]",
                 EFlowPhoton_fUniqueID);
    output->add("Delphes/EFlowPhoton_size", 	EFlowPhoton_size);
    output->add("Delphes/EFlowTrack.Charge[EFlowTrack_]",
                 EFlowTrack_Charge);
    output->add("Delphes/EFlowTrack.CtgTheta[EFlowTrack_]",
                 EFlowTrack_CtgTheta);
    output->add("Delphes/EFlowTrack.D0[EFlowTrack_]", 	EFlowTrack_D0);
    output->add("Delphes/EFlowTrack.DZ[EFlowTrack_]", 	EFlowTrack_DZ);
    output->add("Delphes/EFlowTrack.ErrorCtgTheta[EFlowTrack_]",
                 EFlowTrack_ErrorCtgTheta);
    output->add("Delphes/EFlowTrack.ErrorD0[EFlowTrack_]",
                 EFlowTrack_ErrorD0);
    output->add("Delphes/EFlowTrack.ErrorDZ[EFlowTrack_]",
                 EFlowTrack_ErrorDZ);
    output->add("Delphes/EFlowTrack.ErrorP[EFlowTrack_]",
                 EFlowTrack_ErrorP);
    output->add("Delphes/EFlowTrack.ErrorPT[EFlowTrack_]",
                 EFlowTrack_ErrorPT);
    output->add("Delphes/EFlowTrack.ErrorPhi[EFlowTrack_]",
                 EFlowTrack_ErrorPhi);
    output->add("Delphes/EFlowTrack.ErrorT[EFlowTrack_]",
                 EFlowTrack_ErrorT);
    output->add("Delphes/EFlowTrack.Eta[EFlowTrack_]", 	EFlowTrack_Eta);
    output->add("Delphes/EFlowTrack.EtaOuter[EFlowTrack_]",
                 EFlowTrack_EtaOuter);
    output->add("Delphes/EFlowTrack.L[EFlowTrack_]", 	EFlowTrack_L);
    output->add("Delphes/EFlowTrack.P[EFlowTrack_]", 	EFlowTrack_P);
    output->add("Delphes/EFlowTrack.PID[EFlowTrack_]", 	EFlowTrack_PID);
    output->add("Delphes/EFlowTrack.PT[EFlowTrack_]", 	EFlowTrack_PT);
    output->add("Delphes/EFlowTrack.Phi[EFlowTrack_]", 	EFlowTrack_Phi);
    output->add("Delphes/EFlowTrack.PhiOuter[EFlowTrack_]",
                 EFlowTrack_PhiOuter);
    output->add("Delphes/EFlowTrack.T[EFlowTrack_]", 	EFlowTrack_T);
    output->add("Delphes/EFlowTrack.TOuter[EFlowTrack_]",
                 EFlowTrack_TOuter);
    output->add("Delphes/EFlowTrack.VertexIndex[EFlowTrack_]",
                 EFlowTrack_VertexIndex);
    output->add("Delphes/EFlowTrack.X[EFlowTrack_]", 	EFlowTrack_X);
    output->add("Delphes/EFlowTrack.XOuter[EFlowTrack_]",
                 EFlowTrack_XOuter);
    output->add("Delphes/EFlowTrack.Xd[EFlowTrack_]", 	EFlowTrack_Xd);
    output->add("Delphes/EFlowTrack.Y[EFlowTrack_]", 	EFlowTrack_Y);
    output->add("Delphes/EFlowTrack.YOuter[EFlowTrack_]",
                 EFlowTrack_YOuter);
    output->add("Delphes/EFlowTrack.Yd[EFlowTrack_]", 	EFlowTrack_Yd);
    output->add("Delphes/EFlowTrack.Z[EFlowTrack_]", 	EFlowTrack_Z);
    output->add("Delphes/EFlowTrack.ZOuter[EFlowTrack_]",
                 EFlowTrack_ZOuter);
    output->add("Delphes/EFlowTrack.Zd[EFlowTrack_]", 	EFlowTrack_Zd);
    output->add("Delphes/EFlowTrack.fBits[EFlowTrack_]", 	EFlowTrack_fBits);
    output->add("Delphes/EFlowTrack.fUniqueID[EFlowTrack_]",
                 EFlowTrack_fUniqueID);
    output->add("Delphes/EFlowTrack_size", 	EFlowTrack_size);
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
    output->add("Delphes/FatJet.BTag[FatJet_]", 	FatJet_BTag);
    output->add("Delphes/FatJet.BTagAlgo[FatJet_]", 	FatJet_BTagAlgo);
    output->add("Delphes/FatJet.BTagPhys[FatJet_]", 	FatJet_BTagPhys);
    output->add("Delphes/FatJet.Beta[FatJet_]", 	FatJet_Beta);
    output->add("Delphes/FatJet.BetaStar[FatJet_]", 	FatJet_BetaStar);
    output->add("Delphes/FatJet.Charge[FatJet_]", 	FatJet_Charge);
    output->add("Delphes/FatJet.DeltaEta[FatJet_]", 	FatJet_DeltaEta);
    output->add("Delphes/FatJet.DeltaPhi[FatJet_]", 	FatJet_DeltaPhi);
    output->add("Delphes/FatJet.EhadOverEem[FatJet_]", 	FatJet_EhadOverEem);
    output->add("Delphes/FatJet.Eta[FatJet_]", 	FatJet_Eta);
    output->add("Delphes/FatJet.Flavor[FatJet_]", 	FatJet_Flavor);
    output->add("Delphes/FatJet.FlavorAlgo[FatJet_]", 	FatJet_FlavorAlgo);
    output->add("Delphes/FatJet.FlavorPhys[FatJet_]", 	FatJet_FlavorPhys);
    output->add("Delphes/FatJet.Mass[FatJet_]", 	FatJet_Mass);
    output->add("Delphes/FatJet.MeanSqDeltaR[FatJet_]",
                 FatJet_MeanSqDeltaR);
    output->add("Delphes/FatJet.NCharged[FatJet_]", 	FatJet_NCharged);
    output->add("Delphes/FatJet.NNeutrals[FatJet_]", 	FatJet_NNeutrals);
    output->add("Delphes/FatJet.NSubJetsPruned[FatJet_]",
                 FatJet_NSubJetsPruned);
    output->add("Delphes/FatJet.NSubJetsSoftDropped[FatJet_]",
                 FatJet_NSubJetsSoftDropped);
    output->add("Delphes/FatJet.NSubJetsTrimmed[FatJet_]",
                 FatJet_NSubJetsTrimmed);
    output->add("Delphes/FatJet.PT[FatJet_]", 	FatJet_PT);
    output->add("Delphes/FatJet.PTD[FatJet_]", 	FatJet_PTD);
    output->add("Delphes/FatJet.Phi[FatJet_]", 	FatJet_Phi);
    output->add("Delphes/FatJet.T[FatJet_]", 	FatJet_T);
    output->add("Delphes/FatJet.TauTag[FatJet_]", 	FatJet_TauTag);
    output->add("Delphes/FatJet.fBits[FatJet_]", 	FatJet_fBits);
    output->add("Delphes/FatJet.fUniqueID[FatJet_]", 	FatJet_fUniqueID);
    output->add("Delphes/FatJet_size", 	FatJet_size);
    output->add("Delphes/GenJet.BTag[GenJet_]", 	GenJet_BTag);
    output->add("Delphes/GenJet.BTagAlgo[GenJet_]", 	GenJet_BTagAlgo);
    output->add("Delphes/GenJet.BTagPhys[GenJet_]", 	GenJet_BTagPhys);
    output->add("Delphes/GenJet.Beta[GenJet_]", 	GenJet_Beta);
    output->add("Delphes/GenJet.BetaStar[GenJet_]", 	GenJet_BetaStar);
    output->add("Delphes/GenJet.Charge[GenJet_]", 	GenJet_Charge);
    output->add("Delphes/GenJet.DeltaEta[GenJet_]", 	GenJet_DeltaEta);
    output->add("Delphes/GenJet.DeltaPhi[GenJet_]", 	GenJet_DeltaPhi);
    output->add("Delphes/GenJet.EhadOverEem[GenJet_]", 	GenJet_EhadOverEem);
    output->add("Delphes/GenJet.Eta[GenJet_]", 	GenJet_Eta);
    output->add("Delphes/GenJet.Flavor[GenJet_]", 	GenJet_Flavor);
    output->add("Delphes/GenJet.FlavorAlgo[GenJet_]", 	GenJet_FlavorAlgo);
    output->add("Delphes/GenJet.FlavorPhys[GenJet_]", 	GenJet_FlavorPhys);
    output->add("Delphes/GenJet.Mass[GenJet_]", 	GenJet_Mass);
    output->add("Delphes/GenJet.MeanSqDeltaR[GenJet_]",
                 GenJet_MeanSqDeltaR);
    output->add("Delphes/GenJet.NCharged[GenJet_]", 	GenJet_NCharged);
    output->add("Delphes/GenJet.NNeutrals[GenJet_]", 	GenJet_NNeutrals);
    output->add("Delphes/GenJet.NSubJetsPruned[GenJet_]",
                 GenJet_NSubJetsPruned);
    output->add("Delphes/GenJet.NSubJetsSoftDropped[GenJet_]",
                 GenJet_NSubJetsSoftDropped);
    output->add("Delphes/GenJet.NSubJetsTrimmed[GenJet_]",
                 GenJet_NSubJetsTrimmed);
    output->add("Delphes/GenJet.PT[GenJet_]", 	GenJet_PT);
    output->add("Delphes/GenJet.PTD[GenJet_]", 	GenJet_PTD);
    output->add("Delphes/GenJet.Phi[GenJet_]", 	GenJet_Phi);
    output->add("Delphes/GenJet.T[GenJet_]", 	GenJet_T);
    output->add("Delphes/GenJet.TauTag[GenJet_]", 	GenJet_TauTag);
    output->add("Delphes/GenJet.fBits[GenJet_]", 	GenJet_fBits);
    output->add("Delphes/GenJet.fUniqueID[GenJet_]", 	GenJet_fUniqueID);
    output->add("Delphes/GenJet_size", 	GenJet_size);
    output->add("Delphes/GenMissingET.Eta", 	GenMissingET_Eta);
    output->add("Delphes/GenMissingET.MET", 	GenMissingET_MET);
    output->add("Delphes/GenMissingET.Phi", 	GenMissingET_Phi);
    output->add("Delphes/GenMissingET.fBits", 	GenMissingET_fBits);
    output->add("Delphes/GenMissingET.fUniqueID", 	GenMissingET_fUniqueID);
    output->add("Delphes/GenMissingET_size", 	GenMissingET_size);
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
    output->add("Delphes/Particle.Charge[Particle_]", 	Particle_Charge);
    output->add("Delphes/Particle.CtgTheta[Particle_]", 	Particle_CtgTheta);
    output->add("Delphes/Particle.D0[Particle_]", 	Particle_D0);
    output->add("Delphes/Particle.D1[Particle_]", 	Particle_D1);
    output->add("Delphes/Particle.D2[Particle_]", 	Particle_D2);
    output->add("Delphes/Particle.DZ[Particle_]", 	Particle_DZ);
    output->add("Delphes/Particle.E[Particle_]", 	Particle_E);
    output->add("Delphes/Particle.Eta[Particle_]", 	Particle_Eta);
    output->add("Delphes/Particle.IsPU[Particle_]", 	Particle_IsPU);
    output->add("Delphes/Particle.M1[Particle_]", 	Particle_M1);
    output->add("Delphes/Particle.M2[Particle_]", 	Particle_M2);
    output->add("Delphes/Particle.Mass[Particle_]", 	Particle_Mass);
    output->add("Delphes/Particle.P[Particle_]", 	Particle_P);
    output->add("Delphes/Particle.PID[Particle_]", 	Particle_PID);
    output->add("Delphes/Particle.PT[Particle_]", 	Particle_PT);
    output->add("Delphes/Particle.Phi[Particle_]", 	Particle_Phi);
    output->add("Delphes/Particle.Px[Particle_]", 	Particle_Px);
    output->add("Delphes/Particle.Py[Particle_]", 	Particle_Py);
    output->add("Delphes/Particle.Pz[Particle_]", 	Particle_Pz);
    output->add("Delphes/Particle.Rapidity[Particle_]", 	Particle_Rapidity);
    output->add("Delphes/Particle.Status[Particle_]", 	Particle_Status);
    output->add("Delphes/Particle.T[Particle_]", 	Particle_T);
    output->add("Delphes/Particle.X[Particle_]", 	Particle_X);
    output->add("Delphes/Particle.Y[Particle_]", 	Particle_Y);
    output->add("Delphes/Particle.Z[Particle_]", 	Particle_Z);
    output->add("Delphes/Particle.fBits[Particle_]", 	Particle_fBits);
    output->add("Delphes/Particle.fUniqueID[Particle_]",
                 Particle_fUniqueID);
    output->add("Delphes/Particle_size", 	Particle_size);
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
    output->add("Delphes/ScalarHT.HT", 	ScalarHT_HT);
    output->add("Delphes/ScalarHT.fBits", 	ScalarHT_fBits);
    output->add("Delphes/ScalarHT.fUniqueID", 	ScalarHT_fUniqueID);
    output->add("Delphes/ScalarHT_size", 	ScalarHT_size);
    output->add("Delphes/Tower.E[Tower_]", 	Tower_E);
    output->add("Delphes/Tower.ET[Tower_]", 	Tower_ET);
    output->add("Delphes/Tower.Eem[Tower_]", 	Tower_Eem);
    output->add("Delphes/Tower.Ehad[Tower_]", 	Tower_Ehad);
    output->add("Delphes/Tower.Eta[Tower_]", 	Tower_Eta);
    output->add("Delphes/Tower.NTimeHits[Tower_]", 	Tower_NTimeHits);
    output->add("Delphes/Tower.Phi[Tower_]", 	Tower_Phi);
    output->add("Delphes/Tower.T[Tower_]", 	Tower_T);
    output->add("Delphes/Tower.fBits[Tower_]", 	Tower_fBits);
    output->add("Delphes/Tower.fUniqueID[Tower_]", 	Tower_fUniqueID);
    output->add("Delphes/Tower_size", 	Tower_size);
    output->add("Delphes/Track.Charge[Track_]", 	Track_Charge);
    output->add("Delphes/Track.CtgTheta[Track_]", 	Track_CtgTheta);
    output->add("Delphes/Track.D0[Track_]", 	Track_D0);
    output->add("Delphes/Track.DZ[Track_]", 	Track_DZ);
    output->add("Delphes/Track.ErrorCtgTheta[Track_]",
                 Track_ErrorCtgTheta);
    output->add("Delphes/Track.ErrorD0[Track_]", 	Track_ErrorD0);
    output->add("Delphes/Track.ErrorDZ[Track_]", 	Track_ErrorDZ);
    output->add("Delphes/Track.ErrorP[Track_]", 	Track_ErrorP);
    output->add("Delphes/Track.ErrorPT[Track_]", 	Track_ErrorPT);
    output->add("Delphes/Track.ErrorPhi[Track_]", 	Track_ErrorPhi);
    output->add("Delphes/Track.ErrorT[Track_]", 	Track_ErrorT);
    output->add("Delphes/Track.Eta[Track_]", 	Track_Eta);
    output->add("Delphes/Track.EtaOuter[Track_]", 	Track_EtaOuter);
    output->add("Delphes/Track.L[Track_]", 	Track_L);
    output->add("Delphes/Track.P[Track_]", 	Track_P);
    output->add("Delphes/Track.PID[Track_]", 	Track_PID);
    output->add("Delphes/Track.PT[Track_]", 	Track_PT);
    output->add("Delphes/Track.Phi[Track_]", 	Track_Phi);
    output->add("Delphes/Track.PhiOuter[Track_]", 	Track_PhiOuter);
    output->add("Delphes/Track.T[Track_]", 	Track_T);
    output->add("Delphes/Track.TOuter[Track_]", 	Track_TOuter);
    output->add("Delphes/Track.VertexIndex[Track_]", 	Track_VertexIndex);
    output->add("Delphes/Track.X[Track_]", 	Track_X);
    output->add("Delphes/Track.XOuter[Track_]", 	Track_XOuter);
    output->add("Delphes/Track.Xd[Track_]", 	Track_Xd);
    output->add("Delphes/Track.Y[Track_]", 	Track_Y);
    output->add("Delphes/Track.YOuter[Track_]", 	Track_YOuter);
    output->add("Delphes/Track.Yd[Track_]", 	Track_Yd);
    output->add("Delphes/Track.Z[Track_]", 	Track_Z);
    output->add("Delphes/Track.ZOuter[Track_]", 	Track_ZOuter);
    output->add("Delphes/Track.Zd[Track_]", 	Track_Zd);
    output->add("Delphes/Track.fBits[Track_]", 	Track_fBits);
    output->add("Delphes/Track.fUniqueID[Track_]", 	Track_fUniqueID);
    output->add("Delphes/Track_size", 	Track_size);

  }

  void initBuffers()
  {
    EFlowNeutralHadron_E	= std::vector<float>(230,0);
    EFlowNeutralHadron_ET	= std::vector<float>(230,0);
    EFlowNeutralHadron_Eem	= std::vector<float>(230,0);
    EFlowNeutralHadron_Ehad	= std::vector<float>(230,0);
    EFlowNeutralHadron_Eta	= std::vector<float>(230,0);
    EFlowNeutralHadron_NTimeHits	= std::vector<int>(230,0);
    EFlowNeutralHadron_Phi	= std::vector<float>(230,0);
    EFlowNeutralHadron_T	= std::vector<float>(230,0);
    EFlowNeutralHadron_fBits	= std::vector<int>(230,0);
    EFlowNeutralHadron_fUniqueID	= std::vector<int>(230,0);
    EFlowPhoton_E	= std::vector<float>(270,0);
    EFlowPhoton_ET	= std::vector<float>(270,0);
    EFlowPhoton_Eem	= std::vector<float>(270,0);
    EFlowPhoton_Ehad	= std::vector<float>(270,0);
    EFlowPhoton_Eta	= std::vector<float>(270,0);
    EFlowPhoton_NTimeHits	= std::vector<int>(270,0);
    EFlowPhoton_Phi	= std::vector<float>(270,0);
    EFlowPhoton_T	= std::vector<float>(270,0);
    EFlowPhoton_fBits	= std::vector<int>(270,0);
    EFlowPhoton_fUniqueID	= std::vector<int>(270,0);
    EFlowTrack_Charge	= std::vector<int>(395,0);
    EFlowTrack_CtgTheta	= std::vector<float>(395,0);
    EFlowTrack_D0	= std::vector<float>(395,0);
    EFlowTrack_DZ	= std::vector<float>(395,0);
    EFlowTrack_ErrorCtgTheta	= std::vector<float>(395,0);
    EFlowTrack_ErrorD0	= std::vector<float>(395,0);
    EFlowTrack_ErrorDZ	= std::vector<float>(395,0);
    EFlowTrack_ErrorP	= std::vector<float>(395,0);
    EFlowTrack_ErrorPT	= std::vector<float>(395,0);
    EFlowTrack_ErrorPhi	= std::vector<float>(395,0);
    EFlowTrack_ErrorT	= std::vector<float>(395,0);
    EFlowTrack_Eta	= std::vector<float>(395,0);
    EFlowTrack_EtaOuter	= std::vector<float>(395,0);
    EFlowTrack_L	= std::vector<float>(395,0);
    EFlowTrack_P	= std::vector<float>(395,0);
    EFlowTrack_PID	= std::vector<int>(395,0);
    EFlowTrack_PT	= std::vector<float>(395,0);
    EFlowTrack_Phi	= std::vector<float>(395,0);
    EFlowTrack_PhiOuter	= std::vector<float>(395,0);
    EFlowTrack_T	= std::vector<float>(395,0);
    EFlowTrack_TOuter	= std::vector<float>(395,0);
    EFlowTrack_VertexIndex	= std::vector<int>(395,0);
    EFlowTrack_X	= std::vector<float>(395,0);
    EFlowTrack_XOuter	= std::vector<float>(395,0);
    EFlowTrack_Xd	= std::vector<float>(395,0);
    EFlowTrack_Y	= std::vector<float>(395,0);
    EFlowTrack_YOuter	= std::vector<float>(395,0);
    EFlowTrack_Yd	= std::vector<float>(395,0);
    EFlowTrack_Z	= std::vector<float>(395,0);
    EFlowTrack_ZOuter	= std::vector<float>(395,0);
    EFlowTrack_Zd	= std::vector<float>(395,0);
    EFlowTrack_fBits	= std::vector<int>(395,0);
    EFlowTrack_fUniqueID	= std::vector<int>(395,0);
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
    Electron_fBits	= std::vector<int>(10,0);
    Electron_fUniqueID	= std::vector<int>(10,0);
    FatJet_BTag	= std::vector<int>(25,0);
    FatJet_BTagAlgo	= std::vector<int>(25,0);
    FatJet_BTagPhys	= std::vector<int>(25,0);
    FatJet_Beta	= std::vector<float>(25,0);
    FatJet_BetaStar	= std::vector<float>(25,0);
    FatJet_Charge	= std::vector<int>(25,0);
    FatJet_DeltaEta	= std::vector<float>(25,0);
    FatJet_DeltaPhi	= std::vector<float>(25,0);
    FatJet_EhadOverEem	= std::vector<float>(25,0);
    FatJet_Eta	= std::vector<float>(25,0);
    FatJet_Flavor	= std::vector<int>(25,0);
    FatJet_FlavorAlgo	= std::vector<int>(25,0);
    FatJet_FlavorPhys	= std::vector<int>(25,0);
    FatJet_Mass	= std::vector<float>(25,0);
    FatJet_MeanSqDeltaR	= std::vector<float>(25,0);
    FatJet_NCharged	= std::vector<int>(25,0);
    FatJet_NNeutrals	= std::vector<int>(25,0);
    FatJet_NSubJetsPruned	= std::vector<int>(25,0);
    FatJet_NSubJetsSoftDropped	= std::vector<int>(25,0);
    FatJet_NSubJetsTrimmed	= std::vector<int>(25,0);
    FatJet_PT	= std::vector<float>(25,0);
    FatJet_PTD	= std::vector<float>(25,0);
    FatJet_Phi	= std::vector<float>(25,0);
    FatJet_T	= std::vector<float>(25,0);
    FatJet_TauTag	= std::vector<int>(25,0);
    FatJet_fBits	= std::vector<int>(25,0);
    FatJet_fUniqueID	= std::vector<int>(25,0);
    GenJet_BTag	= std::vector<int>(45,0);
    GenJet_BTagAlgo	= std::vector<int>(45,0);
    GenJet_BTagPhys	= std::vector<int>(45,0);
    GenJet_Beta	= std::vector<float>(45,0);
    GenJet_BetaStar	= std::vector<float>(45,0);
    GenJet_Charge	= std::vector<int>(45,0);
    GenJet_DeltaEta	= std::vector<float>(45,0);
    GenJet_DeltaPhi	= std::vector<float>(45,0);
    GenJet_EhadOverEem	= std::vector<float>(45,0);
    GenJet_Eta	= std::vector<float>(45,0);
    GenJet_Flavor	= std::vector<int>(45,0);
    GenJet_FlavorAlgo	= std::vector<int>(45,0);
    GenJet_FlavorPhys	= std::vector<int>(45,0);
    GenJet_Mass	= std::vector<float>(45,0);
    GenJet_MeanSqDeltaR	= std::vector<float>(45,0);
    GenJet_NCharged	= std::vector<int>(45,0);
    GenJet_NNeutrals	= std::vector<int>(45,0);
    GenJet_NSubJetsPruned	= std::vector<int>(45,0);
    GenJet_NSubJetsSoftDropped	= std::vector<int>(45,0);
    GenJet_NSubJetsTrimmed	= std::vector<int>(45,0);
    GenJet_PT	= std::vector<float>(45,0);
    GenJet_PTD	= std::vector<float>(45,0);
    GenJet_Phi	= std::vector<float>(45,0);
    GenJet_T	= std::vector<float>(45,0);
    GenJet_TauTag	= std::vector<int>(45,0);
    GenJet_fBits	= std::vector<int>(45,0);
    GenJet_fUniqueID	= std::vector<int>(45,0);
    Jet_BTag	= std::vector<int>(40,0);
    Jet_BTagAlgo	= std::vector<int>(40,0);
    Jet_BTagPhys	= std::vector<int>(40,0);
    Jet_Beta	= std::vector<float>(40,0);
    Jet_BetaStar	= std::vector<float>(40,0);
    Jet_Charge	= std::vector<int>(40,0);
    Jet_DeltaEta	= std::vector<float>(40,0);
    Jet_DeltaPhi	= std::vector<float>(40,0);
    Jet_EhadOverEem	= std::vector<float>(40,0);
    Jet_Eta	= std::vector<float>(40,0);
    Jet_Flavor	= std::vector<int>(40,0);
    Jet_FlavorAlgo	= std::vector<int>(40,0);
    Jet_FlavorPhys	= std::vector<int>(40,0);
    Jet_Mass	= std::vector<float>(40,0);
    Jet_MeanSqDeltaR	= std::vector<float>(40,0);
    Jet_NCharged	= std::vector<int>(40,0);
    Jet_NNeutrals	= std::vector<int>(40,0);
    Jet_NSubJetsPruned	= std::vector<int>(40,0);
    Jet_NSubJetsSoftDropped	= std::vector<int>(40,0);
    Jet_NSubJetsTrimmed	= std::vector<int>(40,0);
    Jet_PT	= std::vector<float>(40,0);
    Jet_PTD	= std::vector<float>(40,0);
    Jet_Phi	= std::vector<float>(40,0);
    Jet_T	= std::vector<float>(40,0);
    Jet_TauTag	= std::vector<int>(40,0);
    Jet_fBits	= std::vector<int>(40,0);
    Jet_fUniqueID	= std::vector<int>(40,0);
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
    Muon_fBits	= std::vector<int>(10,0);
    Muon_fUniqueID	= std::vector<int>(10,0);
    Particle_Charge	= std::vector<int>(4325,0);
    Particle_CtgTheta	= std::vector<float>(4325,0);
    Particle_D0	= std::vector<float>(4325,0);
    Particle_D1	= std::vector<int>(4325,0);
    Particle_D2	= std::vector<int>(4325,0);
    Particle_DZ	= std::vector<float>(4325,0);
    Particle_E	= std::vector<float>(4325,0);
    Particle_Eta	= std::vector<float>(4325,0);
    Particle_IsPU	= std::vector<int>(4325,0);
    Particle_M1	= std::vector<int>(4325,0);
    Particle_M2	= std::vector<int>(4325,0);
    Particle_Mass	= std::vector<float>(4325,0);
    Particle_P	= std::vector<float>(4325,0);
    Particle_PID	= std::vector<int>(4325,0);
    Particle_PT	= std::vector<float>(4325,0);
    Particle_Phi	= std::vector<float>(4325,0);
    Particle_Px	= std::vector<float>(4325,0);
    Particle_Py	= std::vector<float>(4325,0);
    Particle_Pz	= std::vector<float>(4325,0);
    Particle_Rapidity	= std::vector<float>(4325,0);
    Particle_Status	= std::vector<int>(4325,0);
    Particle_T	= std::vector<float>(4325,0);
    Particle_X	= std::vector<float>(4325,0);
    Particle_Y	= std::vector<float>(4325,0);
    Particle_Z	= std::vector<float>(4325,0);
    Particle_fBits	= std::vector<int>(4325,0);
    Particle_fUniqueID	= std::vector<int>(4325,0);
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
    Photon_fBits	= std::vector<int>(10,0);
    Photon_fUniqueID	= std::vector<int>(10,0);
    Tower_E	= std::vector<float>(530,0);
    Tower_ET	= std::vector<float>(530,0);
    Tower_Eem	= std::vector<float>(530,0);
    Tower_Ehad	= std::vector<float>(530,0);
    Tower_Eta	= std::vector<float>(530,0);
    Tower_NTimeHits	= std::vector<int>(530,0);
    Tower_Phi	= std::vector<float>(530,0);
    Tower_T	= std::vector<float>(530,0);
    Tower_fBits	= std::vector<int>(530,0);
    Tower_fUniqueID	= std::vector<int>(530,0);
    Track_Charge	= std::vector<int>(395,0);
    Track_CtgTheta	= std::vector<float>(395,0);
    Track_D0	= std::vector<float>(395,0);
    Track_DZ	= std::vector<float>(395,0);
    Track_ErrorCtgTheta	= std::vector<float>(395,0);
    Track_ErrorD0	= std::vector<float>(395,0);
    Track_ErrorDZ	= std::vector<float>(395,0);
    Track_ErrorP	= std::vector<float>(395,0);
    Track_ErrorPT	= std::vector<float>(395,0);
    Track_ErrorPhi	= std::vector<float>(395,0);
    Track_ErrorT	= std::vector<float>(395,0);
    Track_Eta	= std::vector<float>(395,0);
    Track_EtaOuter	= std::vector<float>(395,0);
    Track_L	= std::vector<float>(395,0);
    Track_P	= std::vector<float>(395,0);
    Track_PID	= std::vector<int>(395,0);
    Track_PT	= std::vector<float>(395,0);
    Track_Phi	= std::vector<float>(395,0);
    Track_PhiOuter	= std::vector<float>(395,0);
    Track_T	= std::vector<float>(395,0);
    Track_TOuter	= std::vector<float>(395,0);
    Track_VertexIndex	= std::vector<int>(395,0);
    Track_X	= std::vector<float>(395,0);
    Track_XOuter	= std::vector<float>(395,0);
    Track_Xd	= std::vector<float>(395,0);
    Track_Y	= std::vector<float>(395,0);
    Track_YOuter	= std::vector<float>(395,0);
    Track_Yd	= std::vector<float>(395,0);
    Track_Z	= std::vector<float>(395,0);
    Track_ZOuter	= std::vector<float>(395,0);
    Track_Zd	= std::vector<float>(395,0);
    Track_fBits	= std::vector<int>(395,0);
    Track_fUniqueID	= std::vector<int>(395,0);
    EFlowNeutralHadron	= std::vector<eventBuffer::EFlowNeutralHadron_s>(230);
    EFlowPhoton	= std::vector<eventBuffer::EFlowPhoton_s>(270);
    EFlowTrack	= std::vector<eventBuffer::EFlowTrack_s>(395);
    Electron	= std::vector<eventBuffer::Electron_s>(10);
    FatJet	= std::vector<eventBuffer::FatJet_s>(25);
    GenJet	= std::vector<eventBuffer::GenJet_s>(45);
    Jet	= std::vector<eventBuffer::Jet_s>(40);
    Muon	= std::vector<eventBuffer::Muon_s>(10);
    Particle	= std::vector<eventBuffer::Particle_s>(4325);
    Photon	= std::vector<eventBuffer::Photon_s>(10);
    Tower	= std::vector<eventBuffer::Tower_s>(530);
    Track	= std::vector<eventBuffer::Track_s>(395);

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
