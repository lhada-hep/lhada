#ifndef EVENTBUFFER_H
#define EVENTBUFFER_H
//----------------------------------------------------------------------------
// File:        eventBuffer.h
// Description: Analyzer header for ntuples created by TheNtupleMaker
// Created:     Fri Feb  2 16:31:49 2018 by mkanalyzer.py
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
  std::vector<float>	EFlowNeutralHadron_Phi;
  std::vector<float>	EFlowNeutralHadron_T;
  std::vector<int>	EFlowNeutralHadron_fBits;
  std::vector<int>	EFlowNeutralHadron_fUniqueID;
  std::vector<float>	EFlowPhoton_E;
  std::vector<float>	EFlowPhoton_ET;
  std::vector<float>	EFlowPhoton_Eem;
  std::vector<float>	EFlowPhoton_Ehad;
  std::vector<float>	EFlowPhoton_Eta;
  std::vector<float>	EFlowPhoton_Phi;
  std::vector<float>	EFlowPhoton_T;
  std::vector<int>	EFlowPhoton_fBits;
  std::vector<int>	EFlowPhoton_fUniqueID;
  std::vector<int>	EFlowTrack_Charge;
  std::vector<float>	EFlowTrack_Dxy;
  std::vector<float>	EFlowTrack_Eta;
  std::vector<float>	EFlowTrack_EtaOuter;
  std::vector<int>	EFlowTrack_PID;
  std::vector<float>	EFlowTrack_PT;
  std::vector<float>	EFlowTrack_Phi;
  std::vector<float>	EFlowTrack_PhiOuter;
  std::vector<float>	EFlowTrack_SDxy;
  std::vector<float>	EFlowTrack_T;
  std::vector<float>	EFlowTrack_TOuter;
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
  std::vector<float>	Electron_PT;
  std::vector<float>	Electron_Phi;
  std::vector<float>	Electron_T;
  std::vector<int>	Electron_fBits;
  std::vector<int>	Electron_fUniqueID;
  std::vector<int>	GenJet_BTag;
  std::vector<float>	GenJet_Beta;
  std::vector<float>	GenJet_BetaStar;
  std::vector<int>	GenJet_Charge;
  std::vector<float>	GenJet_DeltaEta;
  std::vector<float>	GenJet_DeltaPhi;
  std::vector<float>	GenJet_EhadOverEem;
  std::vector<float>	GenJet_Eta;
  std::vector<float>	GenJet_Mass;
  std::vector<float>	GenJet_MeanSqDeltaR;
  std::vector<int>	GenJet_NCharged;
  std::vector<int>	GenJet_NNeutrals;
  std::vector<float>	GenJet_PT;
  std::vector<float>	GenJet_PTD;
  std::vector<float>	GenJet_Phi;
  std::vector<float>	GenJet_T;
  std::vector<float>	GenJet_Tau1;
  std::vector<float>	GenJet_Tau2;
  std::vector<float>	GenJet_Tau3;
  std::vector<float>	GenJet_Tau4;
  std::vector<float>	GenJet_Tau5;
  std::vector<int>	GenJet_TauTag;
  std::vector<int>	GenJet_fBits;
  std::vector<int>	GenJet_fUniqueID;
  std::vector<int>	Jet2_BTag;
  std::vector<float>	Jet2_Beta;
  std::vector<float>	Jet2_BetaStar;
  std::vector<int>	Jet2_Charge;
  std::vector<float>	Jet2_DeltaEta;
  std::vector<float>	Jet2_DeltaPhi;
  std::vector<float>	Jet2_EhadOverEem;
  std::vector<float>	Jet2_Eta;
  std::vector<float>	Jet2_Mass;
  std::vector<float>	Jet2_MeanSqDeltaR;
  std::vector<int>	Jet2_NCharged;
  std::vector<int>	Jet2_NNeutrals;
  std::vector<float>	Jet2_PT;
  std::vector<float>	Jet2_PTD;
  std::vector<float>	Jet2_Phi;
  std::vector<float>	Jet2_T;
  std::vector<float>	Jet2_Tau1;
  std::vector<float>	Jet2_Tau2;
  std::vector<float>	Jet2_Tau3;
  std::vector<float>	Jet2_Tau4;
  std::vector<float>	Jet2_Tau5;
  std::vector<int>	Jet2_TauTag;
  std::vector<int>	Jet2_fBits;
  std::vector<int>	Jet2_fUniqueID;
  std::vector<int>	Jet_BTag;
  std::vector<float>	Jet_Beta;
  std::vector<float>	Jet_BetaStar;
  std::vector<int>	Jet_Charge;
  std::vector<float>	Jet_DeltaEta;
  std::vector<float>	Jet_DeltaPhi;
  std::vector<float>	Jet_EhadOverEem;
  std::vector<float>	Jet_Eta;
  std::vector<float>	Jet_Mass;
  std::vector<float>	Jet_MeanSqDeltaR;
  std::vector<int>	Jet_NCharged;
  std::vector<int>	Jet_NNeutrals;
  std::vector<float>	Jet_PT;
  std::vector<float>	Jet_PTD;
  std::vector<float>	Jet_Phi;
  std::vector<float>	Jet_T;
  std::vector<float>	Jet_Tau1;
  std::vector<float>	Jet_Tau2;
  std::vector<float>	Jet_Tau3;
  std::vector<float>	Jet_Tau4;
  std::vector<float>	Jet_Tau5;
  std::vector<int>	Jet_TauTag;
  std::vector<int>	Jet_fBits;
  std::vector<int>	Jet_fUniqueID;
  std::vector<int>	Muon_Charge;
  std::vector<float>	Muon_Eta;
  std::vector<float>	Muon_PT;
  std::vector<float>	Muon_Phi;
  std::vector<float>	Muon_T;
  std::vector<int>	Muon_fBits;
  std::vector<int>	Muon_fUniqueID;
  std::vector<int>	Particle_Charge;
  std::vector<int>	Particle_D1;
  std::vector<int>	Particle_D2;
  std::vector<float>	Particle_E;
  std::vector<float>	Particle_Eta;
  std::vector<int>	Particle_IsPU;
  std::vector<int>	Particle_M1;
  std::vector<int>	Particle_M2;
  std::vector<float>	Particle_Mass;
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
  std::vector<float>	Photon_PT;
  std::vector<float>	Photon_Phi;
  std::vector<float>	Photon_T;
  std::vector<int>	Photon_fBits;
  std::vector<int>	Photon_fUniqueID;
  std::vector<float>	Tower_E;
  std::vector<float>	Tower_ET;
  std::vector<float>	Tower_Eem;
  std::vector<float>	Tower_Ehad;
  std::vector<float>	Tower_Eta;
  std::vector<float>	Tower_Phi;
  std::vector<float>	Tower_T;
  std::vector<int>	Tower_fBits;
  std::vector<int>	Tower_fUniqueID;
  std::vector<int>	Track_Charge;
  std::vector<float>	Track_Dxy;
  std::vector<float>	Track_Eta;
  std::vector<float>	Track_EtaOuter;
  std::vector<int>	Track_PID;
  std::vector<float>	Track_PT;
  std::vector<float>	Track_Phi;
  std::vector<float>	Track_PhiOuter;
  std::vector<float>	Track_SDxy;
  std::vector<float>	Track_T;
  std::vector<float>	Track_TOuter;
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
  int	EFlowPhoton_;
  int	ScalarHT_;
  int	Jet2_;
  int	Event_;
  int	EFlowNeutralHadron_;
  int	Jet_;
  int	Muon_;
  int	Electron_;
  int	GenJet_;
  int	Particle_;
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
  int	GenJet_size;
  int	Jet2_size;
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
    float	Dxy;
    float	Eta;
    float	EtaOuter;
    int	PID;
    float	PT;
    float	Phi;
    float	PhiOuter;
    float	SDxy;
    float	T;
    float	TOuter;
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
      sprintf(r, "  %-32s: %f\n", "Dxy", ( double)Dxy); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "EtaOuter", ( double)EtaOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "PID", ( double)PID); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "PhiOuter", ( double)PhiOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "SDxy", ( double)SDxy); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "TOuter", ( double)TOuter); os << r;
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
    float	PT;
    float	Phi;
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
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct GenJet_s
  {
    int	BTag;
    float	Beta;
    float	BetaStar;
    int	Charge;
    float	DeltaEta;
    float	DeltaPhi;
    float	EhadOverEem;
    float	Eta;
    float	Mass;
    float	MeanSqDeltaR;
    int	NCharged;
    int	NNeutrals;
    float	PT;
    float	PTD;
    float	Phi;
    float	T;
    float	Tau1;
    float	Tau2;
    float	Tau3;
    float	Tau4;
    float	Tau5;
    int	TauTag;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "GenJet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "BTag", ( double)BTag); os << r;
      sprintf(r, "  %-32s: %f\n", "Beta", ( double)Beta); os << r;
      sprintf(r, "  %-32s: %f\n", "BetaStar", ( double)BetaStar); os << r;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaEta", ( double)DeltaEta); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaPhi", ( double)DeltaPhi); os << r;
      sprintf(r, "  %-32s: %f\n", "EhadOverEem", ( double)EhadOverEem); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "Mass", ( double)Mass); os << r;
      sprintf(r, "  %-32s: %f\n", "MeanSqDeltaR", ( double)MeanSqDeltaR); os << r;
      sprintf(r, "  %-32s: %f\n", "NCharged", ( double)NCharged); os << r;
      sprintf(r, "  %-32s: %f\n", "NNeutrals", ( double)NNeutrals); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "PTD", ( double)PTD); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau1", ( double)Tau1); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau2", ( double)Tau2); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau3", ( double)Tau3); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau4", ( double)Tau4); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau5", ( double)Tau5); os << r;
      sprintf(r, "  %-32s: %f\n", "TauTag", ( double)TauTag); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct Jet_s
  {
    int	BTag;
    float	Beta;
    float	BetaStar;
    int	Charge;
    float	DeltaEta;
    float	DeltaPhi;
    float	EhadOverEem;
    float	Eta;
    float	Mass;
    float	MeanSqDeltaR;
    int	NCharged;
    int	NNeutrals;
    float	PT;
    float	PTD;
    float	Phi;
    float	T;
    float	Tau1;
    float	Tau2;
    float	Tau3;
    float	Tau4;
    float	Tau5;
    int	TauTag;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Jet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "BTag", ( double)BTag); os << r;
      sprintf(r, "  %-32s: %f\n", "Beta", ( double)Beta); os << r;
      sprintf(r, "  %-32s: %f\n", "BetaStar", ( double)BetaStar); os << r;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaEta", ( double)DeltaEta); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaPhi", ( double)DeltaPhi); os << r;
      sprintf(r, "  %-32s: %f\n", "EhadOverEem", ( double)EhadOverEem); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "Mass", ( double)Mass); os << r;
      sprintf(r, "  %-32s: %f\n", "MeanSqDeltaR", ( double)MeanSqDeltaR); os << r;
      sprintf(r, "  %-32s: %f\n", "NCharged", ( double)NCharged); os << r;
      sprintf(r, "  %-32s: %f\n", "NNeutrals", ( double)NNeutrals); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "PTD", ( double)PTD); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau1", ( double)Tau1); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau2", ( double)Tau2); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau3", ( double)Tau3); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau4", ( double)Tau4); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau5", ( double)Tau5); os << r;
      sprintf(r, "  %-32s: %f\n", "TauTag", ( double)TauTag); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct Jet2_s
  {
    int	BTag;
    float	Beta;
    float	BetaStar;
    int	Charge;
    float	DeltaEta;
    float	DeltaPhi;
    float	EhadOverEem;
    float	Eta;
    float	Mass;
    float	MeanSqDeltaR;
    int	NCharged;
    int	NNeutrals;
    float	PT;
    float	PTD;
    float	Phi;
    float	T;
    float	Tau1;
    float	Tau2;
    float	Tau3;
    float	Tau4;
    float	Tau5;
    int	TauTag;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Jet2" << std::endl;
      sprintf(r, "  %-32s: %f\n", "BTag", ( double)BTag); os << r;
      sprintf(r, "  %-32s: %f\n", "Beta", ( double)Beta); os << r;
      sprintf(r, "  %-32s: %f\n", "BetaStar", ( double)BetaStar); os << r;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaEta", ( double)DeltaEta); os << r;
      sprintf(r, "  %-32s: %f\n", "DeltaPhi", ( double)DeltaPhi); os << r;
      sprintf(r, "  %-32s: %f\n", "EhadOverEem", ( double)EhadOverEem); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "Mass", ( double)Mass); os << r;
      sprintf(r, "  %-32s: %f\n", "MeanSqDeltaR", ( double)MeanSqDeltaR); os << r;
      sprintf(r, "  %-32s: %f\n", "NCharged", ( double)NCharged); os << r;
      sprintf(r, "  %-32s: %f\n", "NNeutrals", ( double)NNeutrals); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "PTD", ( double)PTD); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau1", ( double)Tau1); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau2", ( double)Tau2); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau3", ( double)Tau3); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau4", ( double)Tau4); os << r;
      sprintf(r, "  %-32s: %f\n", "Tau5", ( double)Tau5); os << r;
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
    float	PT;
    float	Phi;
    float	T;
    int	fBits;
    int	fUniqueID;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Muon" << std::endl;
      sprintf(r, "  %-32s: %f\n", "Charge", ( double)Charge); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "fBits", ( double)fBits); os << r;
      sprintf(r, "  %-32s: %f\n", "fUniqueID", ( double)fUniqueID); os << r;
      return os;
    }
  };

  struct Particle_s
  {
    int	Charge;
    int	D1;
    int	D2;
    float	E;
    float	Eta;
    int	IsPU;
    int	M1;
    int	M2;
    float	Mass;
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
      sprintf(r, "  %-32s: %f\n", "D1", ( double)D1); os << r;
      sprintf(r, "  %-32s: %f\n", "D2", ( double)D2); os << r;
      sprintf(r, "  %-32s: %f\n", "E", ( double)E); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "IsPU", ( double)IsPU); os << r;
      sprintf(r, "  %-32s: %f\n", "M1", ( double)M1); os << r;
      sprintf(r, "  %-32s: %f\n", "M2", ( double)M2); os << r;
      sprintf(r, "  %-32s: %f\n", "Mass", ( double)Mass); os << r;
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
    float	PT;
    float	Phi;
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
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
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
    float	Dxy;
    float	Eta;
    float	EtaOuter;
    int	PID;
    float	PT;
    float	Phi;
    float	PhiOuter;
    float	SDxy;
    float	T;
    float	TOuter;
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
      sprintf(r, "  %-32s: %f\n", "Dxy", ( double)Dxy); os << r;
      sprintf(r, "  %-32s: %f\n", "Eta", ( double)Eta); os << r;
      sprintf(r, "  %-32s: %f\n", "EtaOuter", ( double)EtaOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "PID", ( double)PID); os << r;
      sprintf(r, "  %-32s: %f\n", "PT", ( double)PT); os << r;
      sprintf(r, "  %-32s: %f\n", "Phi", ( double)Phi); os << r;
      sprintf(r, "  %-32s: %f\n", "PhiOuter", ( double)PhiOuter); os << r;
      sprintf(r, "  %-32s: %f\n", "SDxy", ( double)SDxy); os << r;
      sprintf(r, "  %-32s: %f\n", "T", ( double)T); os << r;
      sprintf(r, "  %-32s: %f\n", "TOuter", ( double)TOuter); os << r;
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
        EFlowTrack[i].Dxy	= EFlowTrack_Dxy[i];
        EFlowTrack[i].Eta	= EFlowTrack_Eta[i];
        EFlowTrack[i].EtaOuter	= EFlowTrack_EtaOuter[i];
        EFlowTrack[i].PID	= EFlowTrack_PID[i];
        EFlowTrack[i].PT	= EFlowTrack_PT[i];
        EFlowTrack[i].Phi	= EFlowTrack_Phi[i];
        EFlowTrack[i].PhiOuter	= EFlowTrack_PhiOuter[i];
        EFlowTrack[i].SDxy	= EFlowTrack_SDxy[i];
        EFlowTrack[i].T	= EFlowTrack_T[i];
        EFlowTrack[i].TOuter	= EFlowTrack_TOuter[i];
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
        Electron[i].PT	= Electron_PT[i];
        Electron[i].Phi	= Electron_Phi[i];
        Electron[i].T	= Electron_T[i];
        Electron[i].fBits	= Electron_fBits[i];
        Electron[i].fUniqueID	= Electron_fUniqueID[i];
      }
  }

  void fillGenJets()
  {
    GenJet.resize(GenJet_BTag.size());
    for(unsigned int i=0; i < GenJet.size(); ++i)
      {
        GenJet[i].BTag	= GenJet_BTag[i];
        GenJet[i].Beta	= GenJet_Beta[i];
        GenJet[i].BetaStar	= GenJet_BetaStar[i];
        GenJet[i].Charge	= GenJet_Charge[i];
        GenJet[i].DeltaEta	= GenJet_DeltaEta[i];
        GenJet[i].DeltaPhi	= GenJet_DeltaPhi[i];
        GenJet[i].EhadOverEem	= GenJet_EhadOverEem[i];
        GenJet[i].Eta	= GenJet_Eta[i];
        GenJet[i].Mass	= GenJet_Mass[i];
        GenJet[i].MeanSqDeltaR	= GenJet_MeanSqDeltaR[i];
        GenJet[i].NCharged	= GenJet_NCharged[i];
        GenJet[i].NNeutrals	= GenJet_NNeutrals[i];
        GenJet[i].PT	= GenJet_PT[i];
        GenJet[i].PTD	= GenJet_PTD[i];
        GenJet[i].Phi	= GenJet_Phi[i];
        GenJet[i].T	= GenJet_T[i];
        GenJet[i].Tau1	= GenJet_Tau1[i];
        GenJet[i].Tau2	= GenJet_Tau2[i];
        GenJet[i].Tau3	= GenJet_Tau3[i];
        GenJet[i].Tau4	= GenJet_Tau4[i];
        GenJet[i].Tau5	= GenJet_Tau5[i];
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
        Jet[i].Beta	= Jet_Beta[i];
        Jet[i].BetaStar	= Jet_BetaStar[i];
        Jet[i].Charge	= Jet_Charge[i];
        Jet[i].DeltaEta	= Jet_DeltaEta[i];
        Jet[i].DeltaPhi	= Jet_DeltaPhi[i];
        Jet[i].EhadOverEem	= Jet_EhadOverEem[i];
        Jet[i].Eta	= Jet_Eta[i];
        Jet[i].Mass	= Jet_Mass[i];
        Jet[i].MeanSqDeltaR	= Jet_MeanSqDeltaR[i];
        Jet[i].NCharged	= Jet_NCharged[i];
        Jet[i].NNeutrals	= Jet_NNeutrals[i];
        Jet[i].PT	= Jet_PT[i];
        Jet[i].PTD	= Jet_PTD[i];
        Jet[i].Phi	= Jet_Phi[i];
        Jet[i].T	= Jet_T[i];
        Jet[i].Tau1	= Jet_Tau1[i];
        Jet[i].Tau2	= Jet_Tau2[i];
        Jet[i].Tau3	= Jet_Tau3[i];
        Jet[i].Tau4	= Jet_Tau4[i];
        Jet[i].Tau5	= Jet_Tau5[i];
        Jet[i].TauTag	= Jet_TauTag[i];
        Jet[i].fBits	= Jet_fBits[i];
        Jet[i].fUniqueID	= Jet_fUniqueID[i];
      }
  }

  void fillJet2s()
  {
    Jet2.resize(Jet2_BTag.size());
    for(unsigned int i=0; i < Jet2.size(); ++i)
      {
        Jet2[i].BTag	= Jet2_BTag[i];
        Jet2[i].Beta	= Jet2_Beta[i];
        Jet2[i].BetaStar	= Jet2_BetaStar[i];
        Jet2[i].Charge	= Jet2_Charge[i];
        Jet2[i].DeltaEta	= Jet2_DeltaEta[i];
        Jet2[i].DeltaPhi	= Jet2_DeltaPhi[i];
        Jet2[i].EhadOverEem	= Jet2_EhadOverEem[i];
        Jet2[i].Eta	= Jet2_Eta[i];
        Jet2[i].Mass	= Jet2_Mass[i];
        Jet2[i].MeanSqDeltaR	= Jet2_MeanSqDeltaR[i];
        Jet2[i].NCharged	= Jet2_NCharged[i];
        Jet2[i].NNeutrals	= Jet2_NNeutrals[i];
        Jet2[i].PT	= Jet2_PT[i];
        Jet2[i].PTD	= Jet2_PTD[i];
        Jet2[i].Phi	= Jet2_Phi[i];
        Jet2[i].T	= Jet2_T[i];
        Jet2[i].Tau1	= Jet2_Tau1[i];
        Jet2[i].Tau2	= Jet2_Tau2[i];
        Jet2[i].Tau3	= Jet2_Tau3[i];
        Jet2[i].Tau4	= Jet2_Tau4[i];
        Jet2[i].Tau5	= Jet2_Tau5[i];
        Jet2[i].TauTag	= Jet2_TauTag[i];
        Jet2[i].fBits	= Jet2_fBits[i];
        Jet2[i].fUniqueID	= Jet2_fUniqueID[i];
      }
  }

  void fillMuons()
  {
    Muon.resize(Muon_Charge.size());
    for(unsigned int i=0; i < Muon.size(); ++i)
      {
        Muon[i].Charge	= Muon_Charge[i];
        Muon[i].Eta	= Muon_Eta[i];
        Muon[i].PT	= Muon_PT[i];
        Muon[i].Phi	= Muon_Phi[i];
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
        Particle[i].D1	= Particle_D1[i];
        Particle[i].D2	= Particle_D2[i];
        Particle[i].E	= Particle_E[i];
        Particle[i].Eta	= Particle_Eta[i];
        Particle[i].IsPU	= Particle_IsPU[i];
        Particle[i].M1	= Particle_M1[i];
        Particle[i].M2	= Particle_M2[i];
        Particle[i].Mass	= Particle_Mass[i];
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
        Photon[i].PT	= Photon_PT[i];
        Photon[i].Phi	= Photon_Phi[i];
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
        Track[i].Dxy	= Track_Dxy[i];
        Track[i].Eta	= Track_Eta[i];
        Track[i].EtaOuter	= Track_EtaOuter[i];
        Track[i].PID	= Track_PID[i];
        Track[i].PT	= Track_PT[i];
        Track[i].Phi	= Track_Phi[i];
        Track[i].PhiOuter	= Track_PhiOuter[i];
        Track[i].SDxy	= Track_SDxy[i];
        Track[i].T	= Track_T[i];
        Track[i].TOuter	= Track_TOuter[i];
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
  std::vector<eventBuffer::GenJet_s> GenJet;
  std::vector<eventBuffer::Jet_s> Jet;
  std::vector<eventBuffer::Jet2_s> Jet2;
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
    fillGenJets();
    fillJets();
    fillJet2s();
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
            EFlowTrack_Dxy[i]	= EFlowTrack_Dxy[j];
            EFlowTrack_Eta[i]	= EFlowTrack_Eta[j];
            EFlowTrack_EtaOuter[i]	= EFlowTrack_EtaOuter[j];
            EFlowTrack_PID[i]	= EFlowTrack_PID[j];
            EFlowTrack_PT[i]	= EFlowTrack_PT[j];
            EFlowTrack_Phi[i]	= EFlowTrack_Phi[j];
            EFlowTrack_PhiOuter[i]	= EFlowTrack_PhiOuter[j];
            EFlowTrack_SDxy[i]	= EFlowTrack_SDxy[j];
            EFlowTrack_T[i]	= EFlowTrack_T[j];
            EFlowTrack_TOuter[i]	= EFlowTrack_TOuter[j];
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
            Electron_PT[i]	= Electron_PT[j];
            Electron_Phi[i]	= Electron_Phi[j];
            Electron_T[i]	= Electron_T[j];
            Electron_fBits[i]	= Electron_fBits[j];
            Electron_fUniqueID[i]	= Electron_fUniqueID[j];
          }
      }
    Electron_ = n;

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
            GenJet_Beta[i]	= GenJet_Beta[j];
            GenJet_BetaStar[i]	= GenJet_BetaStar[j];
            GenJet_Charge[i]	= GenJet_Charge[j];
            GenJet_DeltaEta[i]	= GenJet_DeltaEta[j];
            GenJet_DeltaPhi[i]	= GenJet_DeltaPhi[j];
            GenJet_EhadOverEem[i]	= GenJet_EhadOverEem[j];
            GenJet_Eta[i]	= GenJet_Eta[j];
            GenJet_Mass[i]	= GenJet_Mass[j];
            GenJet_MeanSqDeltaR[i]	= GenJet_MeanSqDeltaR[j];
            GenJet_NCharged[i]	= GenJet_NCharged[j];
            GenJet_NNeutrals[i]	= GenJet_NNeutrals[j];
            GenJet_PT[i]	= GenJet_PT[j];
            GenJet_PTD[i]	= GenJet_PTD[j];
            GenJet_Phi[i]	= GenJet_Phi[j];
            GenJet_T[i]	= GenJet_T[j];
            GenJet_Tau1[i]	= GenJet_Tau1[j];
            GenJet_Tau2[i]	= GenJet_Tau2[j];
            GenJet_Tau3[i]	= GenJet_Tau3[j];
            GenJet_Tau4[i]	= GenJet_Tau4[j];
            GenJet_Tau5[i]	= GenJet_Tau5[j];
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
            Jet_Beta[i]	= Jet_Beta[j];
            Jet_BetaStar[i]	= Jet_BetaStar[j];
            Jet_Charge[i]	= Jet_Charge[j];
            Jet_DeltaEta[i]	= Jet_DeltaEta[j];
            Jet_DeltaPhi[i]	= Jet_DeltaPhi[j];
            Jet_EhadOverEem[i]	= Jet_EhadOverEem[j];
            Jet_Eta[i]	= Jet_Eta[j];
            Jet_Mass[i]	= Jet_Mass[j];
            Jet_MeanSqDeltaR[i]	= Jet_MeanSqDeltaR[j];
            Jet_NCharged[i]	= Jet_NCharged[j];
            Jet_NNeutrals[i]	= Jet_NNeutrals[j];
            Jet_PT[i]	= Jet_PT[j];
            Jet_PTD[i]	= Jet_PTD[j];
            Jet_Phi[i]	= Jet_Phi[j];
            Jet_T[i]	= Jet_T[j];
            Jet_Tau1[i]	= Jet_Tau1[j];
            Jet_Tau2[i]	= Jet_Tau2[j];
            Jet_Tau3[i]	= Jet_Tau3[j];
            Jet_Tau4[i]	= Jet_Tau4[j];
            Jet_Tau5[i]	= Jet_Tau5[j];
            Jet_TauTag[i]	= Jet_TauTag[j];
            Jet_fBits[i]	= Jet_fBits[j];
            Jet_fUniqueID[i]	= Jet_fUniqueID[j];
          }
      }
    Jet_ = n;

    n = 0;
    try
      {
         n = indexmap["Jet2"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Jet2"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Jet2_BTag[i]	= Jet2_BTag[j];
            Jet2_Beta[i]	= Jet2_Beta[j];
            Jet2_BetaStar[i]	= Jet2_BetaStar[j];
            Jet2_Charge[i]	= Jet2_Charge[j];
            Jet2_DeltaEta[i]	= Jet2_DeltaEta[j];
            Jet2_DeltaPhi[i]	= Jet2_DeltaPhi[j];
            Jet2_EhadOverEem[i]	= Jet2_EhadOverEem[j];
            Jet2_Eta[i]	= Jet2_Eta[j];
            Jet2_Mass[i]	= Jet2_Mass[j];
            Jet2_MeanSqDeltaR[i]	= Jet2_MeanSqDeltaR[j];
            Jet2_NCharged[i]	= Jet2_NCharged[j];
            Jet2_NNeutrals[i]	= Jet2_NNeutrals[j];
            Jet2_PT[i]	= Jet2_PT[j];
            Jet2_PTD[i]	= Jet2_PTD[j];
            Jet2_Phi[i]	= Jet2_Phi[j];
            Jet2_T[i]	= Jet2_T[j];
            Jet2_Tau1[i]	= Jet2_Tau1[j];
            Jet2_Tau2[i]	= Jet2_Tau2[j];
            Jet2_Tau3[i]	= Jet2_Tau3[j];
            Jet2_Tau4[i]	= Jet2_Tau4[j];
            Jet2_Tau5[i]	= Jet2_Tau5[j];
            Jet2_TauTag[i]	= Jet2_TauTag[j];
            Jet2_fBits[i]	= Jet2_fBits[j];
            Jet2_fUniqueID[i]	= Jet2_fUniqueID[j];
          }
      }
    Jet2_ = n;

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
            Muon_PT[i]	= Muon_PT[j];
            Muon_Phi[i]	= Muon_Phi[j];
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
            Particle_D1[i]	= Particle_D1[j];
            Particle_D2[i]	= Particle_D2[j];
            Particle_E[i]	= Particle_E[j];
            Particle_Eta[i]	= Particle_Eta[j];
            Particle_IsPU[i]	= Particle_IsPU[j];
            Particle_M1[i]	= Particle_M1[j];
            Particle_M2[i]	= Particle_M2[j];
            Particle_Mass[i]	= Particle_Mass[j];
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
            Photon_PT[i]	= Photon_PT[j];
            Photon_Phi[i]	= Photon_Phi[j];
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
            Track_Dxy[i]	= Track_Dxy[j];
            Track_Eta[i]	= Track_Eta[j];
            Track_EtaOuter[i]	= Track_EtaOuter[j];
            Track_PID[i]	= Track_PID[j];
            Track_PT[i]	= Track_PT[j];
            Track_Phi[i]	= Track_Phi[j];
            Track_PhiOuter[i]	= Track_PhiOuter[j];
            Track_SDxy[i]	= Track_SDxy[j];
            Track_T[i]	= Track_T[j];
            Track_TOuter[i]	= Track_TOuter[j];
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
    choose["EFlowPhoton.Phi"]	= DEFAULT;
    choose["EFlowPhoton.T"]	= DEFAULT;
    choose["EFlowPhoton.fBits"]	= DEFAULT;
    choose["EFlowPhoton.fUniqueID"]	= DEFAULT;
    choose["EFlowPhoton_size"]	= DEFAULT;
    choose["EFlowTrack.Charge"]	= DEFAULT;
    choose["EFlowTrack.Dxy"]	= DEFAULT;
    choose["EFlowTrack.Eta"]	= DEFAULT;
    choose["EFlowTrack.EtaOuter"]	= DEFAULT;
    choose["EFlowTrack.PID"]	= DEFAULT;
    choose["EFlowTrack.PT"]	= DEFAULT;
    choose["EFlowTrack.Phi"]	= DEFAULT;
    choose["EFlowTrack.PhiOuter"]	= DEFAULT;
    choose["EFlowTrack.SDxy"]	= DEFAULT;
    choose["EFlowTrack.T"]	= DEFAULT;
    choose["EFlowTrack.TOuter"]	= DEFAULT;
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
    choose["Electron.PT"]	= DEFAULT;
    choose["Electron.Phi"]	= DEFAULT;
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
    choose["GenJet.BTag"]	= DEFAULT;
    choose["GenJet.Beta"]	= DEFAULT;
    choose["GenJet.BetaStar"]	= DEFAULT;
    choose["GenJet.Charge"]	= DEFAULT;
    choose["GenJet.DeltaEta"]	= DEFAULT;
    choose["GenJet.DeltaPhi"]	= DEFAULT;
    choose["GenJet.EhadOverEem"]	= DEFAULT;
    choose["GenJet.Eta"]	= DEFAULT;
    choose["GenJet.Mass"]	= DEFAULT;
    choose["GenJet.MeanSqDeltaR"]	= DEFAULT;
    choose["GenJet.NCharged"]	= DEFAULT;
    choose["GenJet.NNeutrals"]	= DEFAULT;
    choose["GenJet.PT"]	= DEFAULT;
    choose["GenJet.PTD"]	= DEFAULT;
    choose["GenJet.Phi"]	= DEFAULT;
    choose["GenJet.T"]	= DEFAULT;
    choose["GenJet.Tau1"]	= DEFAULT;
    choose["GenJet.Tau2"]	= DEFAULT;
    choose["GenJet.Tau3"]	= DEFAULT;
    choose["GenJet.Tau4"]	= DEFAULT;
    choose["GenJet.Tau5"]	= DEFAULT;
    choose["GenJet.TauTag"]	= DEFAULT;
    choose["GenJet.fBits"]	= DEFAULT;
    choose["GenJet.fUniqueID"]	= DEFAULT;
    choose["GenJet_size"]	= DEFAULT;
    choose["Jet2.BTag"]	= DEFAULT;
    choose["Jet2.Beta"]	= DEFAULT;
    choose["Jet2.BetaStar"]	= DEFAULT;
    choose["Jet2.Charge"]	= DEFAULT;
    choose["Jet2.DeltaEta"]	= DEFAULT;
    choose["Jet2.DeltaPhi"]	= DEFAULT;
    choose["Jet2.EhadOverEem"]	= DEFAULT;
    choose["Jet2.Eta"]	= DEFAULT;
    choose["Jet2.Mass"]	= DEFAULT;
    choose["Jet2.MeanSqDeltaR"]	= DEFAULT;
    choose["Jet2.NCharged"]	= DEFAULT;
    choose["Jet2.NNeutrals"]	= DEFAULT;
    choose["Jet2.PT"]	= DEFAULT;
    choose["Jet2.PTD"]	= DEFAULT;
    choose["Jet2.Phi"]	= DEFAULT;
    choose["Jet2.T"]	= DEFAULT;
    choose["Jet2.Tau1"]	= DEFAULT;
    choose["Jet2.Tau2"]	= DEFAULT;
    choose["Jet2.Tau3"]	= DEFAULT;
    choose["Jet2.Tau4"]	= DEFAULT;
    choose["Jet2.Tau5"]	= DEFAULT;
    choose["Jet2.TauTag"]	= DEFAULT;
    choose["Jet2.fBits"]	= DEFAULT;
    choose["Jet2.fUniqueID"]	= DEFAULT;
    choose["Jet2_size"]	= DEFAULT;
    choose["Jet.BTag"]	= DEFAULT;
    choose["Jet.Beta"]	= DEFAULT;
    choose["Jet.BetaStar"]	= DEFAULT;
    choose["Jet.Charge"]	= DEFAULT;
    choose["Jet.DeltaEta"]	= DEFAULT;
    choose["Jet.DeltaPhi"]	= DEFAULT;
    choose["Jet.EhadOverEem"]	= DEFAULT;
    choose["Jet.Eta"]	= DEFAULT;
    choose["Jet.Mass"]	= DEFAULT;
    choose["Jet.MeanSqDeltaR"]	= DEFAULT;
    choose["Jet.NCharged"]	= DEFAULT;
    choose["Jet.NNeutrals"]	= DEFAULT;
    choose["Jet.PT"]	= DEFAULT;
    choose["Jet.PTD"]	= DEFAULT;
    choose["Jet.Phi"]	= DEFAULT;
    choose["Jet.T"]	= DEFAULT;
    choose["Jet.Tau1"]	= DEFAULT;
    choose["Jet.Tau2"]	= DEFAULT;
    choose["Jet.Tau3"]	= DEFAULT;
    choose["Jet.Tau4"]	= DEFAULT;
    choose["Jet.Tau5"]	= DEFAULT;
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
    choose["Muon.PT"]	= DEFAULT;
    choose["Muon.Phi"]	= DEFAULT;
    choose["Muon.T"]	= DEFAULT;
    choose["Muon.fBits"]	= DEFAULT;
    choose["Muon.fUniqueID"]	= DEFAULT;
    choose["Muon_size"]	= DEFAULT;
    choose["Particle.Charge"]	= DEFAULT;
    choose["Particle.D1"]	= DEFAULT;
    choose["Particle.D2"]	= DEFAULT;
    choose["Particle.E"]	= DEFAULT;
    choose["Particle.Eta"]	= DEFAULT;
    choose["Particle.IsPU"]	= DEFAULT;
    choose["Particle.M1"]	= DEFAULT;
    choose["Particle.M2"]	= DEFAULT;
    choose["Particle.Mass"]	= DEFAULT;
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
    choose["Photon.PT"]	= DEFAULT;
    choose["Photon.Phi"]	= DEFAULT;
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
    choose["Tower.Phi"]	= DEFAULT;
    choose["Tower.T"]	= DEFAULT;
    choose["Tower.fBits"]	= DEFAULT;
    choose["Tower.fUniqueID"]	= DEFAULT;
    choose["Tower_size"]	= DEFAULT;
    choose["Track.Charge"]	= DEFAULT;
    choose["Track.Dxy"]	= DEFAULT;
    choose["Track.Eta"]	= DEFAULT;
    choose["Track.EtaOuter"]	= DEFAULT;
    choose["Track.PID"]	= DEFAULT;
    choose["Track.PT"]	= DEFAULT;
    choose["Track.Phi"]	= DEFAULT;
    choose["Track.PhiOuter"]	= DEFAULT;
    choose["Track.SDxy"]	= DEFAULT;
    choose["Track.T"]	= DEFAULT;
    choose["Track.TOuter"]	= DEFAULT;
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
      input->select("EFlowNeutralHadron.E", 	EFlowNeutralHadron_E);
    if ( choose["EFlowNeutralHadron.ET"] )
      input->select("EFlowNeutralHadron.ET", 	EFlowNeutralHadron_ET);
    if ( choose["EFlowNeutralHadron.Eem"] )
      input->select("EFlowNeutralHadron.Eem", 	EFlowNeutralHadron_Eem);
    if ( choose["EFlowNeutralHadron.Ehad"] )
      input->select("EFlowNeutralHadron.Ehad", 	EFlowNeutralHadron_Ehad);
    if ( choose["EFlowNeutralHadron.Eta"] )
      input->select("EFlowNeutralHadron.Eta", 	EFlowNeutralHadron_Eta);
    if ( choose["EFlowNeutralHadron.Phi"] )
      input->select("EFlowNeutralHadron.Phi", 	EFlowNeutralHadron_Phi);
    if ( choose["EFlowNeutralHadron.T"] )
      input->select("EFlowNeutralHadron.T", 	EFlowNeutralHadron_T);
    if ( choose["EFlowNeutralHadron.fBits"] )
      input->select("EFlowNeutralHadron.fBits", 	EFlowNeutralHadron_fBits);
    if ( choose["EFlowNeutralHadron.fUniqueID"] )
      input->select("EFlowNeutralHadron.fUniqueID",
                     EFlowNeutralHadron_fUniqueID);
    if ( choose["EFlowNeutralHadron_size"] )
      input->select("EFlowNeutralHadron_size", 	EFlowNeutralHadron_size);
    if ( choose["EFlowPhoton.E"] )
      input->select("EFlowPhoton.E", 	EFlowPhoton_E);
    if ( choose["EFlowPhoton.ET"] )
      input->select("EFlowPhoton.ET", 	EFlowPhoton_ET);
    if ( choose["EFlowPhoton.Eem"] )
      input->select("EFlowPhoton.Eem", 	EFlowPhoton_Eem);
    if ( choose["EFlowPhoton.Ehad"] )
      input->select("EFlowPhoton.Ehad", 	EFlowPhoton_Ehad);
    if ( choose["EFlowPhoton.Eta"] )
      input->select("EFlowPhoton.Eta", 	EFlowPhoton_Eta);
    if ( choose["EFlowPhoton.Phi"] )
      input->select("EFlowPhoton.Phi", 	EFlowPhoton_Phi);
    if ( choose["EFlowPhoton.T"] )
      input->select("EFlowPhoton.T", 	EFlowPhoton_T);
    if ( choose["EFlowPhoton.fBits"] )
      input->select("EFlowPhoton.fBits", 	EFlowPhoton_fBits);
    if ( choose["EFlowPhoton.fUniqueID"] )
      input->select("EFlowPhoton.fUniqueID", 	EFlowPhoton_fUniqueID);
    if ( choose["EFlowPhoton_size"] )
      input->select("EFlowPhoton_size", 	EFlowPhoton_size);
    if ( choose["EFlowTrack.Charge"] )
      input->select("EFlowTrack.Charge", 	EFlowTrack_Charge);
    if ( choose["EFlowTrack.Dxy"] )
      input->select("EFlowTrack.Dxy", 	EFlowTrack_Dxy);
    if ( choose["EFlowTrack.Eta"] )
      input->select("EFlowTrack.Eta", 	EFlowTrack_Eta);
    if ( choose["EFlowTrack.EtaOuter"] )
      input->select("EFlowTrack.EtaOuter", 	EFlowTrack_EtaOuter);
    if ( choose["EFlowTrack.PID"] )
      input->select("EFlowTrack.PID", 	EFlowTrack_PID);
    if ( choose["EFlowTrack.PT"] )
      input->select("EFlowTrack.PT", 	EFlowTrack_PT);
    if ( choose["EFlowTrack.Phi"] )
      input->select("EFlowTrack.Phi", 	EFlowTrack_Phi);
    if ( choose["EFlowTrack.PhiOuter"] )
      input->select("EFlowTrack.PhiOuter", 	EFlowTrack_PhiOuter);
    if ( choose["EFlowTrack.SDxy"] )
      input->select("EFlowTrack.SDxy", 	EFlowTrack_SDxy);
    if ( choose["EFlowTrack.T"] )
      input->select("EFlowTrack.T", 	EFlowTrack_T);
    if ( choose["EFlowTrack.TOuter"] )
      input->select("EFlowTrack.TOuter", 	EFlowTrack_TOuter);
    if ( choose["EFlowTrack.X"] )
      input->select("EFlowTrack.X", 	EFlowTrack_X);
    if ( choose["EFlowTrack.XOuter"] )
      input->select("EFlowTrack.XOuter", 	EFlowTrack_XOuter);
    if ( choose["EFlowTrack.Xd"] )
      input->select("EFlowTrack.Xd", 	EFlowTrack_Xd);
    if ( choose["EFlowTrack.Y"] )
      input->select("EFlowTrack.Y", 	EFlowTrack_Y);
    if ( choose["EFlowTrack.YOuter"] )
      input->select("EFlowTrack.YOuter", 	EFlowTrack_YOuter);
    if ( choose["EFlowTrack.Yd"] )
      input->select("EFlowTrack.Yd", 	EFlowTrack_Yd);
    if ( choose["EFlowTrack.Z"] )
      input->select("EFlowTrack.Z", 	EFlowTrack_Z);
    if ( choose["EFlowTrack.ZOuter"] )
      input->select("EFlowTrack.ZOuter", 	EFlowTrack_ZOuter);
    if ( choose["EFlowTrack.Zd"] )
      input->select("EFlowTrack.Zd", 	EFlowTrack_Zd);
    if ( choose["EFlowTrack.fBits"] )
      input->select("EFlowTrack.fBits", 	EFlowTrack_fBits);
    if ( choose["EFlowTrack.fUniqueID"] )
      input->select("EFlowTrack.fUniqueID", 	EFlowTrack_fUniqueID);
    if ( choose["EFlowTrack_size"] )
      input->select("EFlowTrack_size", 	EFlowTrack_size);
    if ( choose["Electron.Charge"] )
      input->select("Electron.Charge", 	Electron_Charge);
    if ( choose["Electron.EhadOverEem"] )
      input->select("Electron.EhadOverEem", 	Electron_EhadOverEem);
    if ( choose["Electron.Eta"] )
      input->select("Electron.Eta", 	Electron_Eta);
    if ( choose["Electron.PT"] )
      input->select("Electron.PT", 	Electron_PT);
    if ( choose["Electron.Phi"] )
      input->select("Electron.Phi", 	Electron_Phi);
    if ( choose["Electron.T"] )
      input->select("Electron.T", 	Electron_T);
    if ( choose["Electron.fBits"] )
      input->select("Electron.fBits", 	Electron_fBits);
    if ( choose["Electron.fUniqueID"] )
      input->select("Electron.fUniqueID", 	Electron_fUniqueID);
    if ( choose["Electron_size"] )
      input->select("Electron_size", 	Electron_size);
    if ( choose["Event.AlphaQCD"] )
      input->select("Event.AlphaQCD", 	Event_AlphaQCD);
    if ( choose["Event.AlphaQED"] )
      input->select("Event.AlphaQED", 	Event_AlphaQED);
    if ( choose["Event.ID1"] )
      input->select("Event.ID1", 	Event_ID1);
    if ( choose["Event.ID2"] )
      input->select("Event.ID2", 	Event_ID2);
    if ( choose["Event.MPI"] )
      input->select("Event.MPI", 	Event_MPI);
    if ( choose["Event.Number"] )
      input->select("Event.Number", 	Event_Number);
    if ( choose["Event.PDF1"] )
      input->select("Event.PDF1", 	Event_PDF1);
    if ( choose["Event.PDF2"] )
      input->select("Event.PDF2", 	Event_PDF2);
    if ( choose["Event.ProcTime"] )
      input->select("Event.ProcTime", 	Event_ProcTime);
    if ( choose["Event.ProcessID"] )
      input->select("Event.ProcessID", 	Event_ProcessID);
    if ( choose["Event.ReadTime"] )
      input->select("Event.ReadTime", 	Event_ReadTime);
    if ( choose["Event.Scale"] )
      input->select("Event.Scale", 	Event_Scale);
    if ( choose["Event.ScalePDF"] )
      input->select("Event.ScalePDF", 	Event_ScalePDF);
    if ( choose["Event.Weight"] )
      input->select("Event.Weight", 	Event_Weight);
    if ( choose["Event.X1"] )
      input->select("Event.X1", 	Event_X1);
    if ( choose["Event.X2"] )
      input->select("Event.X2", 	Event_X2);
    if ( choose["Event.fBits"] )
      input->select("Event.fBits", 	Event_fBits);
    if ( choose["Event.fUniqueID"] )
      input->select("Event.fUniqueID", 	Event_fUniqueID);
    if ( choose["Event_size"] )
      input->select("Event_size", 	Event_size);
    if ( choose["GenJet.BTag"] )
      input->select("GenJet.BTag", 	GenJet_BTag);
    if ( choose["GenJet.Beta"] )
      input->select("GenJet.Beta", 	GenJet_Beta);
    if ( choose["GenJet.BetaStar"] )
      input->select("GenJet.BetaStar", 	GenJet_BetaStar);
    if ( choose["GenJet.Charge"] )
      input->select("GenJet.Charge", 	GenJet_Charge);
    if ( choose["GenJet.DeltaEta"] )
      input->select("GenJet.DeltaEta", 	GenJet_DeltaEta);
    if ( choose["GenJet.DeltaPhi"] )
      input->select("GenJet.DeltaPhi", 	GenJet_DeltaPhi);
    if ( choose["GenJet.EhadOverEem"] )
      input->select("GenJet.EhadOverEem", 	GenJet_EhadOverEem);
    if ( choose["GenJet.Eta"] )
      input->select("GenJet.Eta", 	GenJet_Eta);
    if ( choose["GenJet.Mass"] )
      input->select("GenJet.Mass", 	GenJet_Mass);
    if ( choose["GenJet.MeanSqDeltaR"] )
      input->select("GenJet.MeanSqDeltaR", 	GenJet_MeanSqDeltaR);
    if ( choose["GenJet.NCharged"] )
      input->select("GenJet.NCharged", 	GenJet_NCharged);
    if ( choose["GenJet.NNeutrals"] )
      input->select("GenJet.NNeutrals", 	GenJet_NNeutrals);
    if ( choose["GenJet.PT"] )
      input->select("GenJet.PT", 	GenJet_PT);
    if ( choose["GenJet.PTD"] )
      input->select("GenJet.PTD", 	GenJet_PTD);
    if ( choose["GenJet.Phi"] )
      input->select("GenJet.Phi", 	GenJet_Phi);
    if ( choose["GenJet.T"] )
      input->select("GenJet.T", 	GenJet_T);
    if ( choose["GenJet.Tau1"] )
      input->select("GenJet.Tau1", 	GenJet_Tau1);
    if ( choose["GenJet.Tau2"] )
      input->select("GenJet.Tau2", 	GenJet_Tau2);
    if ( choose["GenJet.Tau3"] )
      input->select("GenJet.Tau3", 	GenJet_Tau3);
    if ( choose["GenJet.Tau4"] )
      input->select("GenJet.Tau4", 	GenJet_Tau4);
    if ( choose["GenJet.Tau5"] )
      input->select("GenJet.Tau5", 	GenJet_Tau5);
    if ( choose["GenJet.TauTag"] )
      input->select("GenJet.TauTag", 	GenJet_TauTag);
    if ( choose["GenJet.fBits"] )
      input->select("GenJet.fBits", 	GenJet_fBits);
    if ( choose["GenJet.fUniqueID"] )
      input->select("GenJet.fUniqueID", 	GenJet_fUniqueID);
    if ( choose["GenJet_size"] )
      input->select("GenJet_size", 	GenJet_size);
    if ( choose["Jet2.BTag"] )
      input->select("Jet2.BTag", 	Jet2_BTag);
    if ( choose["Jet2.Beta"] )
      input->select("Jet2.Beta", 	Jet2_Beta);
    if ( choose["Jet2.BetaStar"] )
      input->select("Jet2.BetaStar", 	Jet2_BetaStar);
    if ( choose["Jet2.Charge"] )
      input->select("Jet2.Charge", 	Jet2_Charge);
    if ( choose["Jet2.DeltaEta"] )
      input->select("Jet2.DeltaEta", 	Jet2_DeltaEta);
    if ( choose["Jet2.DeltaPhi"] )
      input->select("Jet2.DeltaPhi", 	Jet2_DeltaPhi);
    if ( choose["Jet2.EhadOverEem"] )
      input->select("Jet2.EhadOverEem", 	Jet2_EhadOverEem);
    if ( choose["Jet2.Eta"] )
      input->select("Jet2.Eta", 	Jet2_Eta);
    if ( choose["Jet2.Mass"] )
      input->select("Jet2.Mass", 	Jet2_Mass);
    if ( choose["Jet2.MeanSqDeltaR"] )
      input->select("Jet2.MeanSqDeltaR", 	Jet2_MeanSqDeltaR);
    if ( choose["Jet2.NCharged"] )
      input->select("Jet2.NCharged", 	Jet2_NCharged);
    if ( choose["Jet2.NNeutrals"] )
      input->select("Jet2.NNeutrals", 	Jet2_NNeutrals);
    if ( choose["Jet2.PT"] )
      input->select("Jet2.PT", 	Jet2_PT);
    if ( choose["Jet2.PTD"] )
      input->select("Jet2.PTD", 	Jet2_PTD);
    if ( choose["Jet2.Phi"] )
      input->select("Jet2.Phi", 	Jet2_Phi);
    if ( choose["Jet2.T"] )
      input->select("Jet2.T", 	Jet2_T);
    if ( choose["Jet2.Tau1"] )
      input->select("Jet2.Tau1", 	Jet2_Tau1);
    if ( choose["Jet2.Tau2"] )
      input->select("Jet2.Tau2", 	Jet2_Tau2);
    if ( choose["Jet2.Tau3"] )
      input->select("Jet2.Tau3", 	Jet2_Tau3);
    if ( choose["Jet2.Tau4"] )
      input->select("Jet2.Tau4", 	Jet2_Tau4);
    if ( choose["Jet2.Tau5"] )
      input->select("Jet2.Tau5", 	Jet2_Tau5);
    if ( choose["Jet2.TauTag"] )
      input->select("Jet2.TauTag", 	Jet2_TauTag);
    if ( choose["Jet2.fBits"] )
      input->select("Jet2.fBits", 	Jet2_fBits);
    if ( choose["Jet2.fUniqueID"] )
      input->select("Jet2.fUniqueID", 	Jet2_fUniqueID);
    if ( choose["Jet2_size"] )
      input->select("Jet2_size", 	Jet2_size);
    if ( choose["Jet.BTag"] )
      input->select("Jet.BTag", 	Jet_BTag);
    if ( choose["Jet.Beta"] )
      input->select("Jet.Beta", 	Jet_Beta);
    if ( choose["Jet.BetaStar"] )
      input->select("Jet.BetaStar", 	Jet_BetaStar);
    if ( choose["Jet.Charge"] )
      input->select("Jet.Charge", 	Jet_Charge);
    if ( choose["Jet.DeltaEta"] )
      input->select("Jet.DeltaEta", 	Jet_DeltaEta);
    if ( choose["Jet.DeltaPhi"] )
      input->select("Jet.DeltaPhi", 	Jet_DeltaPhi);
    if ( choose["Jet.EhadOverEem"] )
      input->select("Jet.EhadOverEem", 	Jet_EhadOverEem);
    if ( choose["Jet.Eta"] )
      input->select("Jet.Eta", 	Jet_Eta);
    if ( choose["Jet.Mass"] )
      input->select("Jet.Mass", 	Jet_Mass);
    if ( choose["Jet.MeanSqDeltaR"] )
      input->select("Jet.MeanSqDeltaR", 	Jet_MeanSqDeltaR);
    if ( choose["Jet.NCharged"] )
      input->select("Jet.NCharged", 	Jet_NCharged);
    if ( choose["Jet.NNeutrals"] )
      input->select("Jet.NNeutrals", 	Jet_NNeutrals);
    if ( choose["Jet.PT"] )
      input->select("Jet.PT", 	Jet_PT);
    if ( choose["Jet.PTD"] )
      input->select("Jet.PTD", 	Jet_PTD);
    if ( choose["Jet.Phi"] )
      input->select("Jet.Phi", 	Jet_Phi);
    if ( choose["Jet.T"] )
      input->select("Jet.T", 	Jet_T);
    if ( choose["Jet.Tau1"] )
      input->select("Jet.Tau1", 	Jet_Tau1);
    if ( choose["Jet.Tau2"] )
      input->select("Jet.Tau2", 	Jet_Tau2);
    if ( choose["Jet.Tau3"] )
      input->select("Jet.Tau3", 	Jet_Tau3);
    if ( choose["Jet.Tau4"] )
      input->select("Jet.Tau4", 	Jet_Tau4);
    if ( choose["Jet.Tau5"] )
      input->select("Jet.Tau5", 	Jet_Tau5);
    if ( choose["Jet.TauTag"] )
      input->select("Jet.TauTag", 	Jet_TauTag);
    if ( choose["Jet.fBits"] )
      input->select("Jet.fBits", 	Jet_fBits);
    if ( choose["Jet.fUniqueID"] )
      input->select("Jet.fUniqueID", 	Jet_fUniqueID);
    if ( choose["Jet_size"] )
      input->select("Jet_size", 	Jet_size);
    if ( choose["MissingET.Eta"] )
      input->select("MissingET.Eta", 	MissingET_Eta);
    if ( choose["MissingET.MET"] )
      input->select("MissingET.MET", 	MissingET_MET);
    if ( choose["MissingET.Phi"] )
      input->select("MissingET.Phi", 	MissingET_Phi);
    if ( choose["MissingET.fBits"] )
      input->select("MissingET.fBits", 	MissingET_fBits);
    if ( choose["MissingET.fUniqueID"] )
      input->select("MissingET.fUniqueID", 	MissingET_fUniqueID);
    if ( choose["MissingET_size"] )
      input->select("MissingET_size", 	MissingET_size);
    if ( choose["Muon.Charge"] )
      input->select("Muon.Charge", 	Muon_Charge);
    if ( choose["Muon.Eta"] )
      input->select("Muon.Eta", 	Muon_Eta);
    if ( choose["Muon.PT"] )
      input->select("Muon.PT", 	Muon_PT);
    if ( choose["Muon.Phi"] )
      input->select("Muon.Phi", 	Muon_Phi);
    if ( choose["Muon.T"] )
      input->select("Muon.T", 	Muon_T);
    if ( choose["Muon.fBits"] )
      input->select("Muon.fBits", 	Muon_fBits);
    if ( choose["Muon.fUniqueID"] )
      input->select("Muon.fUniqueID", 	Muon_fUniqueID);
    if ( choose["Muon_size"] )
      input->select("Muon_size", 	Muon_size);
    if ( choose["Particle.Charge"] )
      input->select("Particle.Charge", 	Particle_Charge);
    if ( choose["Particle.D1"] )
      input->select("Particle.D1", 	Particle_D1);
    if ( choose["Particle.D2"] )
      input->select("Particle.D2", 	Particle_D2);
    if ( choose["Particle.E"] )
      input->select("Particle.E", 	Particle_E);
    if ( choose["Particle.Eta"] )
      input->select("Particle.Eta", 	Particle_Eta);
    if ( choose["Particle.IsPU"] )
      input->select("Particle.IsPU", 	Particle_IsPU);
    if ( choose["Particle.M1"] )
      input->select("Particle.M1", 	Particle_M1);
    if ( choose["Particle.M2"] )
      input->select("Particle.M2", 	Particle_M2);
    if ( choose["Particle.Mass"] )
      input->select("Particle.Mass", 	Particle_Mass);
    if ( choose["Particle.PID"] )
      input->select("Particle.PID", 	Particle_PID);
    if ( choose["Particle.PT"] )
      input->select("Particle.PT", 	Particle_PT);
    if ( choose["Particle.Phi"] )
      input->select("Particle.Phi", 	Particle_Phi);
    if ( choose["Particle.Px"] )
      input->select("Particle.Px", 	Particle_Px);
    if ( choose["Particle.Py"] )
      input->select("Particle.Py", 	Particle_Py);
    if ( choose["Particle.Pz"] )
      input->select("Particle.Pz", 	Particle_Pz);
    if ( choose["Particle.Rapidity"] )
      input->select("Particle.Rapidity", 	Particle_Rapidity);
    if ( choose["Particle.Status"] )
      input->select("Particle.Status", 	Particle_Status);
    if ( choose["Particle.T"] )
      input->select("Particle.T", 	Particle_T);
    if ( choose["Particle.X"] )
      input->select("Particle.X", 	Particle_X);
    if ( choose["Particle.Y"] )
      input->select("Particle.Y", 	Particle_Y);
    if ( choose["Particle.Z"] )
      input->select("Particle.Z", 	Particle_Z);
    if ( choose["Particle.fBits"] )
      input->select("Particle.fBits", 	Particle_fBits);
    if ( choose["Particle.fUniqueID"] )
      input->select("Particle.fUniqueID", 	Particle_fUniqueID);
    if ( choose["Particle_size"] )
      input->select("Particle_size", 	Particle_size);
    if ( choose["Photon.E"] )
      input->select("Photon.E", 	Photon_E);
    if ( choose["Photon.EhadOverEem"] )
      input->select("Photon.EhadOverEem", 	Photon_EhadOverEem);
    if ( choose["Photon.Eta"] )
      input->select("Photon.Eta", 	Photon_Eta);
    if ( choose["Photon.PT"] )
      input->select("Photon.PT", 	Photon_PT);
    if ( choose["Photon.Phi"] )
      input->select("Photon.Phi", 	Photon_Phi);
    if ( choose["Photon.T"] )
      input->select("Photon.T", 	Photon_T);
    if ( choose["Photon.fBits"] )
      input->select("Photon.fBits", 	Photon_fBits);
    if ( choose["Photon.fUniqueID"] )
      input->select("Photon.fUniqueID", 	Photon_fUniqueID);
    if ( choose["Photon_size"] )
      input->select("Photon_size", 	Photon_size);
    if ( choose["ScalarHT.HT"] )
      input->select("ScalarHT.HT", 	ScalarHT_HT);
    if ( choose["ScalarHT.fBits"] )
      input->select("ScalarHT.fBits", 	ScalarHT_fBits);
    if ( choose["ScalarHT.fUniqueID"] )
      input->select("ScalarHT.fUniqueID", 	ScalarHT_fUniqueID);
    if ( choose["ScalarHT_size"] )
      input->select("ScalarHT_size", 	ScalarHT_size);
    if ( choose["Tower.E"] )
      input->select("Tower.E", 	Tower_E);
    if ( choose["Tower.ET"] )
      input->select("Tower.ET", 	Tower_ET);
    if ( choose["Tower.Eem"] )
      input->select("Tower.Eem", 	Tower_Eem);
    if ( choose["Tower.Ehad"] )
      input->select("Tower.Ehad", 	Tower_Ehad);
    if ( choose["Tower.Eta"] )
      input->select("Tower.Eta", 	Tower_Eta);
    if ( choose["Tower.Phi"] )
      input->select("Tower.Phi", 	Tower_Phi);
    if ( choose["Tower.T"] )
      input->select("Tower.T", 	Tower_T);
    if ( choose["Tower.fBits"] )
      input->select("Tower.fBits", 	Tower_fBits);
    if ( choose["Tower.fUniqueID"] )
      input->select("Tower.fUniqueID", 	Tower_fUniqueID);
    if ( choose["Tower_size"] )
      input->select("Tower_size", 	Tower_size);
    if ( choose["Track.Charge"] )
      input->select("Track.Charge", 	Track_Charge);
    if ( choose["Track.Dxy"] )
      input->select("Track.Dxy", 	Track_Dxy);
    if ( choose["Track.Eta"] )
      input->select("Track.Eta", 	Track_Eta);
    if ( choose["Track.EtaOuter"] )
      input->select("Track.EtaOuter", 	Track_EtaOuter);
    if ( choose["Track.PID"] )
      input->select("Track.PID", 	Track_PID);
    if ( choose["Track.PT"] )
      input->select("Track.PT", 	Track_PT);
    if ( choose["Track.Phi"] )
      input->select("Track.Phi", 	Track_Phi);
    if ( choose["Track.PhiOuter"] )
      input->select("Track.PhiOuter", 	Track_PhiOuter);
    if ( choose["Track.SDxy"] )
      input->select("Track.SDxy", 	Track_SDxy);
    if ( choose["Track.T"] )
      input->select("Track.T", 	Track_T);
    if ( choose["Track.TOuter"] )
      input->select("Track.TOuter", 	Track_TOuter);
    if ( choose["Track.X"] )
      input->select("Track.X", 	Track_X);
    if ( choose["Track.XOuter"] )
      input->select("Track.XOuter", 	Track_XOuter);
    if ( choose["Track.Xd"] )
      input->select("Track.Xd", 	Track_Xd);
    if ( choose["Track.Y"] )
      input->select("Track.Y", 	Track_Y);
    if ( choose["Track.YOuter"] )
      input->select("Track.YOuter", 	Track_YOuter);
    if ( choose["Track.Yd"] )
      input->select("Track.Yd", 	Track_Yd);
    if ( choose["Track.Z"] )
      input->select("Track.Z", 	Track_Z);
    if ( choose["Track.ZOuter"] )
      input->select("Track.ZOuter", 	Track_ZOuter);
    if ( choose["Track.Zd"] )
      input->select("Track.Zd", 	Track_Zd);
    if ( choose["Track.fBits"] )
      input->select("Track.fBits", 	Track_fBits);
    if ( choose["Track.fUniqueID"] )
      input->select("Track.fUniqueID", 	Track_fUniqueID);
    if ( choose["Track_size"] )
      input->select("Track_size", 	Track_size);

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
    output->add("EFlowPhoton_", 	EFlowPhoton_);
    output->add("ScalarHT_", 	ScalarHT_);
    output->add("Jet2_", 	Jet2_);
    output->add("Event_", 	Event_);
    output->add("EFlowNeutralHadron_", 	EFlowNeutralHadron_);
    output->add("Jet_", 	Jet_);
    output->add("Muon_", 	Muon_);
    output->add("Electron_", 	Electron_);
    output->add("GenJet_", 	GenJet_);
    output->add("Particle_", 	Particle_);
    output->add("EFlowTrack_", 	EFlowTrack_);
  
    output->add("EFlowNeutralHadron.E[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_E);
    output->add("EFlowNeutralHadron.ET[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_ET);
    output->add("EFlowNeutralHadron.Eem[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Eem);
    output->add("EFlowNeutralHadron.Ehad[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Ehad);
    output->add("EFlowNeutralHadron.Eta[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Eta);
    output->add("EFlowNeutralHadron.Phi[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_Phi);
    output->add("EFlowNeutralHadron.T[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_T);
    output->add("EFlowNeutralHadron.fBits[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_fBits);
    output->add("EFlowNeutralHadron.fUniqueID[EFlowNeutralHadron_]",
                 EFlowNeutralHadron_fUniqueID);
    output->add("EFlowNeutralHadron_size", 	EFlowNeutralHadron_size);
    output->add("EFlowPhoton.E[EFlowPhoton_]", 	EFlowPhoton_E);
    output->add("EFlowPhoton.ET[EFlowPhoton_]", 	EFlowPhoton_ET);
    output->add("EFlowPhoton.Eem[EFlowPhoton_]", 	EFlowPhoton_Eem);
    output->add("EFlowPhoton.Ehad[EFlowPhoton_]", 	EFlowPhoton_Ehad);
    output->add("EFlowPhoton.Eta[EFlowPhoton_]", 	EFlowPhoton_Eta);
    output->add("EFlowPhoton.Phi[EFlowPhoton_]", 	EFlowPhoton_Phi);
    output->add("EFlowPhoton.T[EFlowPhoton_]", 	EFlowPhoton_T);
    output->add("EFlowPhoton.fBits[EFlowPhoton_]", 	EFlowPhoton_fBits);
    output->add("EFlowPhoton.fUniqueID[EFlowPhoton_]",
                 EFlowPhoton_fUniqueID);
    output->add("EFlowPhoton_size", 	EFlowPhoton_size);
    output->add("EFlowTrack.Charge[EFlowTrack_]", 	EFlowTrack_Charge);
    output->add("EFlowTrack.Dxy[EFlowTrack_]", 	EFlowTrack_Dxy);
    output->add("EFlowTrack.Eta[EFlowTrack_]", 	EFlowTrack_Eta);
    output->add("EFlowTrack.EtaOuter[EFlowTrack_]", 	EFlowTrack_EtaOuter);
    output->add("EFlowTrack.PID[EFlowTrack_]", 	EFlowTrack_PID);
    output->add("EFlowTrack.PT[EFlowTrack_]", 	EFlowTrack_PT);
    output->add("EFlowTrack.Phi[EFlowTrack_]", 	EFlowTrack_Phi);
    output->add("EFlowTrack.PhiOuter[EFlowTrack_]", 	EFlowTrack_PhiOuter);
    output->add("EFlowTrack.SDxy[EFlowTrack_]", 	EFlowTrack_SDxy);
    output->add("EFlowTrack.T[EFlowTrack_]", 	EFlowTrack_T);
    output->add("EFlowTrack.TOuter[EFlowTrack_]", 	EFlowTrack_TOuter);
    output->add("EFlowTrack.X[EFlowTrack_]", 	EFlowTrack_X);
    output->add("EFlowTrack.XOuter[EFlowTrack_]", 	EFlowTrack_XOuter);
    output->add("EFlowTrack.Xd[EFlowTrack_]", 	EFlowTrack_Xd);
    output->add("EFlowTrack.Y[EFlowTrack_]", 	EFlowTrack_Y);
    output->add("EFlowTrack.YOuter[EFlowTrack_]", 	EFlowTrack_YOuter);
    output->add("EFlowTrack.Yd[EFlowTrack_]", 	EFlowTrack_Yd);
    output->add("EFlowTrack.Z[EFlowTrack_]", 	EFlowTrack_Z);
    output->add("EFlowTrack.ZOuter[EFlowTrack_]", 	EFlowTrack_ZOuter);
    output->add("EFlowTrack.Zd[EFlowTrack_]", 	EFlowTrack_Zd);
    output->add("EFlowTrack.fBits[EFlowTrack_]", 	EFlowTrack_fBits);
    output->add("EFlowTrack.fUniqueID[EFlowTrack_]", 	EFlowTrack_fUniqueID);
    output->add("EFlowTrack_size", 	EFlowTrack_size);
    output->add("Electron.Charge[Electron_]", 	Electron_Charge);
    output->add("Electron.EhadOverEem[Electron_]", 	Electron_EhadOverEem);
    output->add("Electron.Eta[Electron_]", 	Electron_Eta);
    output->add("Electron.PT[Electron_]", 	Electron_PT);
    output->add("Electron.Phi[Electron_]", 	Electron_Phi);
    output->add("Electron.T[Electron_]", 	Electron_T);
    output->add("Electron.fBits[Electron_]", 	Electron_fBits);
    output->add("Electron.fUniqueID[Electron_]", 	Electron_fUniqueID);
    output->add("Electron_size", 	Electron_size);
    output->add("Event.AlphaQCD", 	Event_AlphaQCD);
    output->add("Event.AlphaQED", 	Event_AlphaQED);
    output->add("Event.ID1", 	Event_ID1);
    output->add("Event.ID2", 	Event_ID2);
    output->add("Event.MPI", 	Event_MPI);
    output->add("Event.Number", 	Event_Number);
    output->add("Event.PDF1", 	Event_PDF1);
    output->add("Event.PDF2", 	Event_PDF2);
    output->add("Event.ProcTime", 	Event_ProcTime);
    output->add("Event.ProcessID", 	Event_ProcessID);
    output->add("Event.ReadTime", 	Event_ReadTime);
    output->add("Event.Scale", 	Event_Scale);
    output->add("Event.ScalePDF", 	Event_ScalePDF);
    output->add("Event.Weight", 	Event_Weight);
    output->add("Event.X1", 	Event_X1);
    output->add("Event.X2", 	Event_X2);
    output->add("Event.fBits", 	Event_fBits);
    output->add("Event.fUniqueID", 	Event_fUniqueID);
    output->add("Event_size", 	Event_size);
    output->add("GenJet.BTag[GenJet_]", 	GenJet_BTag);
    output->add("GenJet.Beta[GenJet_]", 	GenJet_Beta);
    output->add("GenJet.BetaStar[GenJet_]", 	GenJet_BetaStar);
    output->add("GenJet.Charge[GenJet_]", 	GenJet_Charge);
    output->add("GenJet.DeltaEta[GenJet_]", 	GenJet_DeltaEta);
    output->add("GenJet.DeltaPhi[GenJet_]", 	GenJet_DeltaPhi);
    output->add("GenJet.EhadOverEem[GenJet_]", 	GenJet_EhadOverEem);
    output->add("GenJet.Eta[GenJet_]", 	GenJet_Eta);
    output->add("GenJet.Mass[GenJet_]", 	GenJet_Mass);
    output->add("GenJet.MeanSqDeltaR[GenJet_]", 	GenJet_MeanSqDeltaR);
    output->add("GenJet.NCharged[GenJet_]", 	GenJet_NCharged);
    output->add("GenJet.NNeutrals[GenJet_]", 	GenJet_NNeutrals);
    output->add("GenJet.PT[GenJet_]", 	GenJet_PT);
    output->add("GenJet.PTD[GenJet_]", 	GenJet_PTD);
    output->add("GenJet.Phi[GenJet_]", 	GenJet_Phi);
    output->add("GenJet.T[GenJet_]", 	GenJet_T);
    output->add("GenJet.Tau1[GenJet_]", 	GenJet_Tau1);
    output->add("GenJet.Tau2[GenJet_]", 	GenJet_Tau2);
    output->add("GenJet.Tau3[GenJet_]", 	GenJet_Tau3);
    output->add("GenJet.Tau4[GenJet_]", 	GenJet_Tau4);
    output->add("GenJet.Tau5[GenJet_]", 	GenJet_Tau5);
    output->add("GenJet.TauTag[GenJet_]", 	GenJet_TauTag);
    output->add("GenJet.fBits[GenJet_]", 	GenJet_fBits);
    output->add("GenJet.fUniqueID[GenJet_]", 	GenJet_fUniqueID);
    output->add("GenJet_size", 	GenJet_size);
    output->add("Jet2.BTag[Jet2_]", 	Jet2_BTag);
    output->add("Jet2.Beta[Jet2_]", 	Jet2_Beta);
    output->add("Jet2.BetaStar[Jet2_]", 	Jet2_BetaStar);
    output->add("Jet2.Charge[Jet2_]", 	Jet2_Charge);
    output->add("Jet2.DeltaEta[Jet2_]", 	Jet2_DeltaEta);
    output->add("Jet2.DeltaPhi[Jet2_]", 	Jet2_DeltaPhi);
    output->add("Jet2.EhadOverEem[Jet2_]", 	Jet2_EhadOverEem);
    output->add("Jet2.Eta[Jet2_]", 	Jet2_Eta);
    output->add("Jet2.Mass[Jet2_]", 	Jet2_Mass);
    output->add("Jet2.MeanSqDeltaR[Jet2_]", 	Jet2_MeanSqDeltaR);
    output->add("Jet2.NCharged[Jet2_]", 	Jet2_NCharged);
    output->add("Jet2.NNeutrals[Jet2_]", 	Jet2_NNeutrals);
    output->add("Jet2.PT[Jet2_]", 	Jet2_PT);
    output->add("Jet2.PTD[Jet2_]", 	Jet2_PTD);
    output->add("Jet2.Phi[Jet2_]", 	Jet2_Phi);
    output->add("Jet2.T[Jet2_]", 	Jet2_T);
    output->add("Jet2.Tau1[Jet2_]", 	Jet2_Tau1);
    output->add("Jet2.Tau2[Jet2_]", 	Jet2_Tau2);
    output->add("Jet2.Tau3[Jet2_]", 	Jet2_Tau3);
    output->add("Jet2.Tau4[Jet2_]", 	Jet2_Tau4);
    output->add("Jet2.Tau5[Jet2_]", 	Jet2_Tau5);
    output->add("Jet2.TauTag[Jet2_]", 	Jet2_TauTag);
    output->add("Jet2.fBits[Jet2_]", 	Jet2_fBits);
    output->add("Jet2.fUniqueID[Jet2_]", 	Jet2_fUniqueID);
    output->add("Jet2_size", 	Jet2_size);
    output->add("Jet.BTag[Jet_]", 	Jet_BTag);
    output->add("Jet.Beta[Jet_]", 	Jet_Beta);
    output->add("Jet.BetaStar[Jet_]", 	Jet_BetaStar);
    output->add("Jet.Charge[Jet_]", 	Jet_Charge);
    output->add("Jet.DeltaEta[Jet_]", 	Jet_DeltaEta);
    output->add("Jet.DeltaPhi[Jet_]", 	Jet_DeltaPhi);
    output->add("Jet.EhadOverEem[Jet_]", 	Jet_EhadOverEem);
    output->add("Jet.Eta[Jet_]", 	Jet_Eta);
    output->add("Jet.Mass[Jet_]", 	Jet_Mass);
    output->add("Jet.MeanSqDeltaR[Jet_]", 	Jet_MeanSqDeltaR);
    output->add("Jet.NCharged[Jet_]", 	Jet_NCharged);
    output->add("Jet.NNeutrals[Jet_]", 	Jet_NNeutrals);
    output->add("Jet.PT[Jet_]", 	Jet_PT);
    output->add("Jet.PTD[Jet_]", 	Jet_PTD);
    output->add("Jet.Phi[Jet_]", 	Jet_Phi);
    output->add("Jet.T[Jet_]", 	Jet_T);
    output->add("Jet.Tau1[Jet_]", 	Jet_Tau1);
    output->add("Jet.Tau2[Jet_]", 	Jet_Tau2);
    output->add("Jet.Tau3[Jet_]", 	Jet_Tau3);
    output->add("Jet.Tau4[Jet_]", 	Jet_Tau4);
    output->add("Jet.Tau5[Jet_]", 	Jet_Tau5);
    output->add("Jet.TauTag[Jet_]", 	Jet_TauTag);
    output->add("Jet.fBits[Jet_]", 	Jet_fBits);
    output->add("Jet.fUniqueID[Jet_]", 	Jet_fUniqueID);
    output->add("Jet_size", 	Jet_size);
    output->add("MissingET.Eta", 	MissingET_Eta);
    output->add("MissingET.MET", 	MissingET_MET);
    output->add("MissingET.Phi", 	MissingET_Phi);
    output->add("MissingET.fBits", 	MissingET_fBits);
    output->add("MissingET.fUniqueID", 	MissingET_fUniqueID);
    output->add("MissingET_size", 	MissingET_size);
    output->add("Muon.Charge[Muon_]", 	Muon_Charge);
    output->add("Muon.Eta[Muon_]", 	Muon_Eta);
    output->add("Muon.PT[Muon_]", 	Muon_PT);
    output->add("Muon.Phi[Muon_]", 	Muon_Phi);
    output->add("Muon.T[Muon_]", 	Muon_T);
    output->add("Muon.fBits[Muon_]", 	Muon_fBits);
    output->add("Muon.fUniqueID[Muon_]", 	Muon_fUniqueID);
    output->add("Muon_size", 	Muon_size);
    output->add("Particle.Charge[Particle_]", 	Particle_Charge);
    output->add("Particle.D1[Particle_]", 	Particle_D1);
    output->add("Particle.D2[Particle_]", 	Particle_D2);
    output->add("Particle.E[Particle_]", 	Particle_E);
    output->add("Particle.Eta[Particle_]", 	Particle_Eta);
    output->add("Particle.IsPU[Particle_]", 	Particle_IsPU);
    output->add("Particle.M1[Particle_]", 	Particle_M1);
    output->add("Particle.M2[Particle_]", 	Particle_M2);
    output->add("Particle.Mass[Particle_]", 	Particle_Mass);
    output->add("Particle.PID[Particle_]", 	Particle_PID);
    output->add("Particle.PT[Particle_]", 	Particle_PT);
    output->add("Particle.Phi[Particle_]", 	Particle_Phi);
    output->add("Particle.Px[Particle_]", 	Particle_Px);
    output->add("Particle.Py[Particle_]", 	Particle_Py);
    output->add("Particle.Pz[Particle_]", 	Particle_Pz);
    output->add("Particle.Rapidity[Particle_]", 	Particle_Rapidity);
    output->add("Particle.Status[Particle_]", 	Particle_Status);
    output->add("Particle.T[Particle_]", 	Particle_T);
    output->add("Particle.X[Particle_]", 	Particle_X);
    output->add("Particle.Y[Particle_]", 	Particle_Y);
    output->add("Particle.Z[Particle_]", 	Particle_Z);
    output->add("Particle.fBits[Particle_]", 	Particle_fBits);
    output->add("Particle.fUniqueID[Particle_]", 	Particle_fUniqueID);
    output->add("Particle_size", 	Particle_size);
    output->add("Photon.E[Photon_]", 	Photon_E);
    output->add("Photon.EhadOverEem[Photon_]", 	Photon_EhadOverEem);
    output->add("Photon.Eta[Photon_]", 	Photon_Eta);
    output->add("Photon.PT[Photon_]", 	Photon_PT);
    output->add("Photon.Phi[Photon_]", 	Photon_Phi);
    output->add("Photon.T[Photon_]", 	Photon_T);
    output->add("Photon.fBits[Photon_]", 	Photon_fBits);
    output->add("Photon.fUniqueID[Photon_]", 	Photon_fUniqueID);
    output->add("Photon_size", 	Photon_size);
    output->add("ScalarHT.HT", 	ScalarHT_HT);
    output->add("ScalarHT.fBits", 	ScalarHT_fBits);
    output->add("ScalarHT.fUniqueID", 	ScalarHT_fUniqueID);
    output->add("ScalarHT_size", 	ScalarHT_size);
    output->add("Tower.E[Tower_]", 	Tower_E);
    output->add("Tower.ET[Tower_]", 	Tower_ET);
    output->add("Tower.Eem[Tower_]", 	Tower_Eem);
    output->add("Tower.Ehad[Tower_]", 	Tower_Ehad);
    output->add("Tower.Eta[Tower_]", 	Tower_Eta);
    output->add("Tower.Phi[Tower_]", 	Tower_Phi);
    output->add("Tower.T[Tower_]", 	Tower_T);
    output->add("Tower.fBits[Tower_]", 	Tower_fBits);
    output->add("Tower.fUniqueID[Tower_]", 	Tower_fUniqueID);
    output->add("Tower_size", 	Tower_size);
    output->add("Track.Charge[Track_]", 	Track_Charge);
    output->add("Track.Dxy[Track_]", 	Track_Dxy);
    output->add("Track.Eta[Track_]", 	Track_Eta);
    output->add("Track.EtaOuter[Track_]", 	Track_EtaOuter);
    output->add("Track.PID[Track_]", 	Track_PID);
    output->add("Track.PT[Track_]", 	Track_PT);
    output->add("Track.Phi[Track_]", 	Track_Phi);
    output->add("Track.PhiOuter[Track_]", 	Track_PhiOuter);
    output->add("Track.SDxy[Track_]", 	Track_SDxy);
    output->add("Track.T[Track_]", 	Track_T);
    output->add("Track.TOuter[Track_]", 	Track_TOuter);
    output->add("Track.X[Track_]", 	Track_X);
    output->add("Track.XOuter[Track_]", 	Track_XOuter);
    output->add("Track.Xd[Track_]", 	Track_Xd);
    output->add("Track.Y[Track_]", 	Track_Y);
    output->add("Track.YOuter[Track_]", 	Track_YOuter);
    output->add("Track.Yd[Track_]", 	Track_Yd);
    output->add("Track.Z[Track_]", 	Track_Z);
    output->add("Track.ZOuter[Track_]", 	Track_ZOuter);
    output->add("Track.Zd[Track_]", 	Track_Zd);
    output->add("Track.fBits[Track_]", 	Track_fBits);
    output->add("Track.fUniqueID[Track_]", 	Track_fUniqueID);
    output->add("Track_size", 	Track_size);

  }

  void initBuffers()
  {
    EFlowNeutralHadron_E	= std::vector<float>(240,0);
    EFlowNeutralHadron_ET	= std::vector<float>(240,0);
    EFlowNeutralHadron_Eem	= std::vector<float>(240,0);
    EFlowNeutralHadron_Ehad	= std::vector<float>(240,0);
    EFlowNeutralHadron_Eta	= std::vector<float>(240,0);
    EFlowNeutralHadron_Phi	= std::vector<float>(240,0);
    EFlowNeutralHadron_T	= std::vector<float>(240,0);
    EFlowNeutralHadron_fBits	= std::vector<int>(240,0);
    EFlowNeutralHadron_fUniqueID	= std::vector<int>(240,0);
    EFlowPhoton_E	= std::vector<float>(305,0);
    EFlowPhoton_ET	= std::vector<float>(305,0);
    EFlowPhoton_Eem	= std::vector<float>(305,0);
    EFlowPhoton_Ehad	= std::vector<float>(305,0);
    EFlowPhoton_Eta	= std::vector<float>(305,0);
    EFlowPhoton_Phi	= std::vector<float>(305,0);
    EFlowPhoton_T	= std::vector<float>(305,0);
    EFlowPhoton_fBits	= std::vector<int>(305,0);
    EFlowPhoton_fUniqueID	= std::vector<int>(305,0);
    EFlowTrack_Charge	= std::vector<int>(230,0);
    EFlowTrack_Dxy	= std::vector<float>(230,0);
    EFlowTrack_Eta	= std::vector<float>(230,0);
    EFlowTrack_EtaOuter	= std::vector<float>(230,0);
    EFlowTrack_PID	= std::vector<int>(230,0);
    EFlowTrack_PT	= std::vector<float>(230,0);
    EFlowTrack_Phi	= std::vector<float>(230,0);
    EFlowTrack_PhiOuter	= std::vector<float>(230,0);
    EFlowTrack_SDxy	= std::vector<float>(230,0);
    EFlowTrack_T	= std::vector<float>(230,0);
    EFlowTrack_TOuter	= std::vector<float>(230,0);
    EFlowTrack_X	= std::vector<float>(230,0);
    EFlowTrack_XOuter	= std::vector<float>(230,0);
    EFlowTrack_Xd	= std::vector<float>(230,0);
    EFlowTrack_Y	= std::vector<float>(230,0);
    EFlowTrack_YOuter	= std::vector<float>(230,0);
    EFlowTrack_Yd	= std::vector<float>(230,0);
    EFlowTrack_Z	= std::vector<float>(230,0);
    EFlowTrack_ZOuter	= std::vector<float>(230,0);
    EFlowTrack_Zd	= std::vector<float>(230,0);
    EFlowTrack_fBits	= std::vector<int>(230,0);
    EFlowTrack_fUniqueID	= std::vector<int>(230,0);
    Electron_Charge	= std::vector<int>(15,0);
    Electron_EhadOverEem	= std::vector<float>(15,0);
    Electron_Eta	= std::vector<float>(15,0);
    Electron_PT	= std::vector<float>(15,0);
    Electron_Phi	= std::vector<float>(15,0);
    Electron_T	= std::vector<float>(15,0);
    Electron_fBits	= std::vector<int>(15,0);
    Electron_fUniqueID	= std::vector<int>(15,0);
    GenJet_BTag	= std::vector<int>(35,0);
    GenJet_Beta	= std::vector<float>(35,0);
    GenJet_BetaStar	= std::vector<float>(35,0);
    GenJet_Charge	= std::vector<int>(35,0);
    GenJet_DeltaEta	= std::vector<float>(35,0);
    GenJet_DeltaPhi	= std::vector<float>(35,0);
    GenJet_EhadOverEem	= std::vector<float>(35,0);
    GenJet_Eta	= std::vector<float>(35,0);
    GenJet_Mass	= std::vector<float>(35,0);
    GenJet_MeanSqDeltaR	= std::vector<float>(35,0);
    GenJet_NCharged	= std::vector<int>(35,0);
    GenJet_NNeutrals	= std::vector<int>(35,0);
    GenJet_PT	= std::vector<float>(35,0);
    GenJet_PTD	= std::vector<float>(35,0);
    GenJet_Phi	= std::vector<float>(35,0);
    GenJet_T	= std::vector<float>(35,0);
    GenJet_Tau1	= std::vector<float>(35,0);
    GenJet_Tau2	= std::vector<float>(35,0);
    GenJet_Tau3	= std::vector<float>(35,0);
    GenJet_Tau4	= std::vector<float>(35,0);
    GenJet_Tau5	= std::vector<float>(35,0);
    GenJet_TauTag	= std::vector<int>(35,0);
    GenJet_fBits	= std::vector<int>(35,0);
    GenJet_fUniqueID	= std::vector<int>(35,0);
    Jet2_BTag	= std::vector<int>(15,0);
    Jet2_Beta	= std::vector<float>(15,0);
    Jet2_BetaStar	= std::vector<float>(15,0);
    Jet2_Charge	= std::vector<int>(15,0);
    Jet2_DeltaEta	= std::vector<float>(15,0);
    Jet2_DeltaPhi	= std::vector<float>(15,0);
    Jet2_EhadOverEem	= std::vector<float>(15,0);
    Jet2_Eta	= std::vector<float>(15,0);
    Jet2_Mass	= std::vector<float>(15,0);
    Jet2_MeanSqDeltaR	= std::vector<float>(15,0);
    Jet2_NCharged	= std::vector<int>(15,0);
    Jet2_NNeutrals	= std::vector<int>(15,0);
    Jet2_PT	= std::vector<float>(15,0);
    Jet2_PTD	= std::vector<float>(15,0);
    Jet2_Phi	= std::vector<float>(15,0);
    Jet2_T	= std::vector<float>(15,0);
    Jet2_Tau1	= std::vector<float>(15,0);
    Jet2_Tau2	= std::vector<float>(15,0);
    Jet2_Tau3	= std::vector<float>(15,0);
    Jet2_Tau4	= std::vector<float>(15,0);
    Jet2_Tau5	= std::vector<float>(15,0);
    Jet2_TauTag	= std::vector<int>(15,0);
    Jet2_fBits	= std::vector<int>(15,0);
    Jet2_fUniqueID	= std::vector<int>(15,0);
    Jet_BTag	= std::vector<int>(30,0);
    Jet_Beta	= std::vector<float>(30,0);
    Jet_BetaStar	= std::vector<float>(30,0);
    Jet_Charge	= std::vector<int>(30,0);
    Jet_DeltaEta	= std::vector<float>(30,0);
    Jet_DeltaPhi	= std::vector<float>(30,0);
    Jet_EhadOverEem	= std::vector<float>(30,0);
    Jet_Eta	= std::vector<float>(30,0);
    Jet_Mass	= std::vector<float>(30,0);
    Jet_MeanSqDeltaR	= std::vector<float>(30,0);
    Jet_NCharged	= std::vector<int>(30,0);
    Jet_NNeutrals	= std::vector<int>(30,0);
    Jet_PT	= std::vector<float>(30,0);
    Jet_PTD	= std::vector<float>(30,0);
    Jet_Phi	= std::vector<float>(30,0);
    Jet_T	= std::vector<float>(30,0);
    Jet_Tau1	= std::vector<float>(30,0);
    Jet_Tau2	= std::vector<float>(30,0);
    Jet_Tau3	= std::vector<float>(30,0);
    Jet_Tau4	= std::vector<float>(30,0);
    Jet_Tau5	= std::vector<float>(30,0);
    Jet_TauTag	= std::vector<int>(30,0);
    Jet_fBits	= std::vector<int>(30,0);
    Jet_fUniqueID	= std::vector<int>(30,0);
    Muon_Charge	= std::vector<int>(20,0);
    Muon_Eta	= std::vector<float>(20,0);
    Muon_PT	= std::vector<float>(20,0);
    Muon_Phi	= std::vector<float>(20,0);
    Muon_T	= std::vector<float>(20,0);
    Muon_fBits	= std::vector<int>(20,0);
    Muon_fUniqueID	= std::vector<int>(20,0);
    Particle_Charge	= std::vector<int>(4460,0);
    Particle_D1	= std::vector<int>(4460,0);
    Particle_D2	= std::vector<int>(4460,0);
    Particle_E	= std::vector<float>(4460,0);
    Particle_Eta	= std::vector<float>(4460,0);
    Particle_IsPU	= std::vector<int>(4460,0);
    Particle_M1	= std::vector<int>(4460,0);
    Particle_M2	= std::vector<int>(4460,0);
    Particle_Mass	= std::vector<float>(4460,0);
    Particle_PID	= std::vector<int>(4460,0);
    Particle_PT	= std::vector<float>(4460,0);
    Particle_Phi	= std::vector<float>(4460,0);
    Particle_Px	= std::vector<float>(4460,0);
    Particle_Py	= std::vector<float>(4460,0);
    Particle_Pz	= std::vector<float>(4460,0);
    Particle_Rapidity	= std::vector<float>(4460,0);
    Particle_Status	= std::vector<int>(4460,0);
    Particle_T	= std::vector<float>(4460,0);
    Particle_X	= std::vector<float>(4460,0);
    Particle_Y	= std::vector<float>(4460,0);
    Particle_Z	= std::vector<float>(4460,0);
    Particle_fBits	= std::vector<int>(4460,0);
    Particle_fUniqueID	= std::vector<int>(4460,0);
    Photon_E	= std::vector<float>(15,0);
    Photon_EhadOverEem	= std::vector<float>(15,0);
    Photon_Eta	= std::vector<float>(15,0);
    Photon_PT	= std::vector<float>(15,0);
    Photon_Phi	= std::vector<float>(15,0);
    Photon_T	= std::vector<float>(15,0);
    Photon_fBits	= std::vector<int>(15,0);
    Photon_fUniqueID	= std::vector<int>(15,0);
    Tower_E	= std::vector<float>(505,0);
    Tower_ET	= std::vector<float>(505,0);
    Tower_Eem	= std::vector<float>(505,0);
    Tower_Ehad	= std::vector<float>(505,0);
    Tower_Eta	= std::vector<float>(505,0);
    Tower_Phi	= std::vector<float>(505,0);
    Tower_T	= std::vector<float>(505,0);
    Tower_fBits	= std::vector<int>(505,0);
    Tower_fUniqueID	= std::vector<int>(505,0);
    Track_Charge	= std::vector<int>(230,0);
    Track_Dxy	= std::vector<float>(230,0);
    Track_Eta	= std::vector<float>(230,0);
    Track_EtaOuter	= std::vector<float>(230,0);
    Track_PID	= std::vector<int>(230,0);
    Track_PT	= std::vector<float>(230,0);
    Track_Phi	= std::vector<float>(230,0);
    Track_PhiOuter	= std::vector<float>(230,0);
    Track_SDxy	= std::vector<float>(230,0);
    Track_T	= std::vector<float>(230,0);
    Track_TOuter	= std::vector<float>(230,0);
    Track_X	= std::vector<float>(230,0);
    Track_XOuter	= std::vector<float>(230,0);
    Track_Xd	= std::vector<float>(230,0);
    Track_Y	= std::vector<float>(230,0);
    Track_YOuter	= std::vector<float>(230,0);
    Track_Yd	= std::vector<float>(230,0);
    Track_Z	= std::vector<float>(230,0);
    Track_ZOuter	= std::vector<float>(230,0);
    Track_Zd	= std::vector<float>(230,0);
    Track_fBits	= std::vector<int>(230,0);
    Track_fUniqueID	= std::vector<int>(230,0);
    EFlowNeutralHadron	= std::vector<eventBuffer::EFlowNeutralHadron_s>(240);
    EFlowPhoton	= std::vector<eventBuffer::EFlowPhoton_s>(305);
    EFlowTrack	= std::vector<eventBuffer::EFlowTrack_s>(230);
    Electron	= std::vector<eventBuffer::Electron_s>(15);
    GenJet	= std::vector<eventBuffer::GenJet_s>(35);
    Jet	= std::vector<eventBuffer::Jet_s>(30);
    Jet2	= std::vector<eventBuffer::Jet2_s>(15);
    Muon	= std::vector<eventBuffer::Muon_s>(20);
    Particle	= std::vector<eventBuffer::Particle_s>(4460);
    Photon	= std::vector<eventBuffer::Photon_s>(15);
    Tower	= std::vector<eventBuffer::Tower_s>(505);
    Track	= std::vector<eventBuffer::Track_s>(230);

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
