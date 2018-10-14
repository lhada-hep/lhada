#ifndef EVENTBUFFER_H
#define EVENTBUFFER_H
//----------------------------------------------------------------------------
// File:        eventBuffer.h
// Description: Analyzer header for ntuples created by TheNtupleMaker
// Created:     Sun Oct 14 12:58:39 2018 by mkanalyzer.py
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
  std::vector<int>	Electron_charge;
  std::vector<int>	Electron_cleanmask;
  std::vector<bool>	Electron_convVeto;
  std::vector<int>	Electron_cutBased;
  std::vector<bool>	Electron_cutBased_HEEP;
  std::vector<float>	Electron_deltaEtaSC;
  std::vector<float>	Electron_dr03EcalRecHitSumEt;
  std::vector<float>	Electron_dr03HcalDepth1TowerSumEt;
  std::vector<float>	Electron_dr03TkSumPt;
  std::vector<float>	Electron_dxy;
  std::vector<float>	Electron_dxyErr;
  std::vector<float>	Electron_dz;
  std::vector<float>	Electron_dzErr;
  std::vector<float>	Electron_eCorr;
  std::vector<float>	Electron_eInvMinusPInv;
  std::vector<float>	Electron_energyErr;
  std::vector<float>	Electron_eta;
  std::vector<int>	Electron_genPartFlav;
  std::vector<int>	Electron_genPartIdx;
  std::vector<float>	Electron_hoe;
  std::vector<float>	Electron_ip3d;
  std::vector<bool>	Electron_isPFcand;
  std::vector<int>	Electron_jetIdx;
  std::vector<int>	Electron_lostHits;
  std::vector<float>	Electron_mass;
  std::vector<float>	Electron_miniPFRelIso_all;
  std::vector<float>	Electron_miniPFRelIso_chg;
  std::vector<float>	Electron_mvaFall17Iso;
  std::vector<bool>	Electron_mvaFall17Iso_WP80;
  std::vector<bool>	Electron_mvaFall17Iso_WP90;
  std::vector<bool>	Electron_mvaFall17Iso_WPL;
  std::vector<float>	Electron_mvaFall17noIso;
  std::vector<bool>	Electron_mvaFall17noIso_WP80;
  std::vector<bool>	Electron_mvaFall17noIso_WP90;
  std::vector<bool>	Electron_mvaFall17noIso_WPL;
  std::vector<float>	Electron_mvaTTH;
  std::vector<int>	Electron_pdgId;
  std::vector<float>	Electron_pfRelIso03_all;
  std::vector<float>	Electron_pfRelIso03_chg;
  std::vector<float>	Electron_phi;
  std::vector<int>	Electron_photonIdx;
  std::vector<float>	Electron_pt;
  std::vector<float>	Electron_r9;
  std::vector<float>	Electron_sieie;
  std::vector<float>	Electron_sip3d;
  std::vector<int>	Electron_tightCharge;
  std::vector<int>	Electron_vidNestedWPBitmap;
  std::vector<float>	FatJet_area;
  std::vector<float>	FatJet_btagCMVA;
  std::vector<float>	FatJet_btagCSVV2;
  std::vector<float>	FatJet_btagDeepB;
  std::vector<float>	FatJet_btagHbb;
  std::vector<float>	FatJet_eta;
  std::vector<int>	FatJet_jetId;
  std::vector<float>	FatJet_mass;
  std::vector<float>	FatJet_msoftdrop;
  std::vector<float>	FatJet_n2b1;
  std::vector<float>	FatJet_n3b1;
  std::vector<float>	FatJet_phi;
  std::vector<float>	FatJet_pt;
  std::vector<int>	FatJet_subJetIdx1;
  std::vector<int>	FatJet_subJetIdx2;
  std::vector<float>	FatJet_tau1;
  std::vector<float>	FatJet_tau2;
  std::vector<float>	FatJet_tau3;
  std::vector<float>	FatJet_tau4;
  std::vector<float>	GenDressedLepton_eta;
  std::vector<float>	GenDressedLepton_mass;
  std::vector<int>	GenDressedLepton_pdgId;
  std::vector<float>	GenDressedLepton_phi;
  std::vector<float>	GenDressedLepton_pt;
  std::vector<float>	GenJetAK8_eta;
  std::vector<int>	GenJetAK8_hadronFlavour;
  std::vector<float>	GenJetAK8_mass;
  std::vector<int>	GenJetAK8_partonFlavour;
  std::vector<float>	GenJetAK8_phi;
  std::vector<float>	GenJetAK8_pt;
  std::vector<float>	GenJet_eta;
  std::vector<int>	GenJet_hadronFlavour;
  std::vector<float>	GenJet_mass;
  std::vector<int>	GenJet_partonFlavour;
  std::vector<float>	GenJet_phi;
  std::vector<float>	GenJet_pt;
  std::vector<float>	GenPart_eta;
  std::vector<int>	GenPart_genPartIdxMother;
  std::vector<float>	GenPart_mass;
  std::vector<int>	GenPart_pdgId;
  std::vector<float>	GenPart_phi;
  std::vector<float>	GenPart_pt;
  std::vector<int>	GenPart_status;
  std::vector<int>	GenPart_statusFlags;
  std::vector<int>	GenVisTau_charge;
  std::vector<float>	GenVisTau_eta;
  std::vector<int>	GenVisTau_genPartIdxMother;
  std::vector<float>	GenVisTau_mass;
  std::vector<float>	GenVisTau_phi;
  std::vector<float>	GenVisTau_pt;
  std::vector<int>	GenVisTau_status;
  std::vector<float>	IsoTrack_dxy;
  std::vector<float>	IsoTrack_dz;
  std::vector<float>	IsoTrack_eta;
  std::vector<bool>	IsoTrack_isHighPurityTrack;
  std::vector<bool>	IsoTrack_isPFcand;
  std::vector<float>	IsoTrack_miniPFRelIso_all;
  std::vector<float>	IsoTrack_miniPFRelIso_chg;
  std::vector<int>	IsoTrack_pdgId;
  std::vector<float>	IsoTrack_pfRelIso03_all;
  std::vector<float>	IsoTrack_pfRelIso03_chg;
  std::vector<float>	IsoTrack_phi;
  std::vector<float>	IsoTrack_pt;
  std::vector<float>	Jet_area;
  std::vector<float>	Jet_bReg;
  std::vector<float>	Jet_btagCMVA;
  std::vector<float>	Jet_btagCSVV2;
  std::vector<float>	Jet_btagDeepB;
  std::vector<float>	Jet_btagDeepC;
  std::vector<float>	Jet_btagDeepFlavB;
  std::vector<float>	Jet_chEmEF;
  std::vector<float>	Jet_chHEF;
  std::vector<int>	Jet_cleanmask;
  std::vector<int>	Jet_electronIdx1;
  std::vector<int>	Jet_electronIdx2;
  std::vector<float>	Jet_eta;
  std::vector<int>	Jet_genJetIdx;
  std::vector<int>	Jet_hadronFlavour;
  std::vector<int>	Jet_jetId;
  std::vector<float>	Jet_mass;
  std::vector<int>	Jet_muonIdx1;
  std::vector<int>	Jet_muonIdx2;
  std::vector<int>	Jet_nConstituents;
  std::vector<int>	Jet_nElectrons;
  std::vector<int>	Jet_nMuons;
  std::vector<float>	Jet_neEmEF;
  std::vector<float>	Jet_neHEF;
  std::vector<int>	Jet_partonFlavour;
  std::vector<float>	Jet_phi;
  std::vector<float>	Jet_pt;
  std::vector<int>	Jet_puId;
  std::vector<float>	Jet_qgl;
  std::vector<float>	Jet_rawFactor;
  std::vector<float>	LHEPart_eta;
  std::vector<float>	LHEPart_mass;
  std::vector<int>	LHEPart_pdgId;
  std::vector<float>	LHEPart_phi;
  std::vector<float>	LHEPart_pt;
  std::vector<float>	LHEPdfWeight;
  std::vector<float>	LHEScaleWeight;
  std::vector<int>	Muon_charge;
  std::vector<int>	Muon_cleanmask;
  std::vector<float>	Muon_dxy;
  std::vector<float>	Muon_dxyErr;
  std::vector<float>	Muon_dz;
  std::vector<float>	Muon_dzErr;
  std::vector<float>	Muon_eta;
  std::vector<int>	Muon_genPartFlav;
  std::vector<int>	Muon_genPartIdx;
  std::vector<int>	Muon_highPtId;
  std::vector<float>	Muon_ip3d;
  std::vector<bool>	Muon_isPFcand;
  std::vector<int>	Muon_jetIdx;
  std::vector<float>	Muon_mass;
  std::vector<bool>	Muon_mediumId;
  std::vector<float>	Muon_miniPFRelIso_all;
  std::vector<float>	Muon_miniPFRelIso_chg;
  std::vector<float>	Muon_mvaTTH;
  std::vector<int>	Muon_nStations;
  std::vector<int>	Muon_nTrackerLayers;
  std::vector<int>	Muon_pdgId;
  std::vector<float>	Muon_pfRelIso03_all;
  std::vector<float>	Muon_pfRelIso03_chg;
  std::vector<float>	Muon_pfRelIso04_all;
  std::vector<float>	Muon_phi;
  std::vector<float>	Muon_pt;
  std::vector<float>	Muon_ptErr;
  std::vector<float>	Muon_segmentComp;
  std::vector<float>	Muon_sip3d;
  std::vector<bool>	Muon_softId;
  std::vector<int>	Muon_tightCharge;
  std::vector<bool>	Muon_tightId;
  std::vector<float>	OtherPV_z;
  std::vector<int>	Photon_charge;
  std::vector<int>	Photon_cleanmask;
  std::vector<int>	Photon_cutBasedBitmap;
  std::vector<float>	Photon_eCorr;
  std::vector<int>	Photon_electronIdx;
  std::vector<bool>	Photon_electronVeto;
  std::vector<float>	Photon_energyErr;
  std::vector<float>	Photon_eta;
  std::vector<int>	Photon_genPartFlav;
  std::vector<int>	Photon_genPartIdx;
  std::vector<float>	Photon_hoe;
  std::vector<bool>	Photon_isScEtaEB;
  std::vector<bool>	Photon_isScEtaEE;
  std::vector<int>	Photon_jetIdx;
  std::vector<float>	Photon_mass;
  std::vector<float>	Photon_mvaID;
  std::vector<bool>	Photon_mvaID_WP80;
  std::vector<bool>	Photon_mvaID_WP90;
  std::vector<int>	Photon_pdgId;
  std::vector<float>	Photon_pfRelIso03_all;
  std::vector<float>	Photon_pfRelIso03_chg;
  std::vector<float>	Photon_phi;
  std::vector<bool>	Photon_pixelSeed;
  std::vector<float>	Photon_pt;
  std::vector<float>	Photon_r9;
  std::vector<float>	Photon_sieie;
  std::vector<int>	Photon_vidNestedWPBitmap;
  std::vector<float>	SV_chi2;
  std::vector<float>	SV_dlen;
  std::vector<float>	SV_dlenSig;
  std::vector<float>	SV_eta;
  std::vector<float>	SV_mass;
  std::vector<float>	SV_ndof;
  std::vector<float>	SV_pAngle;
  std::vector<float>	SV_phi;
  std::vector<float>	SV_pt;
  std::vector<float>	SV_x;
  std::vector<float>	SV_y;
  std::vector<float>	SV_z;
  std::vector<float>	SoftActivityJet_eta;
  std::vector<float>	SoftActivityJet_phi;
  std::vector<float>	SoftActivityJet_pt;
  std::vector<float>	SubGenJetAK8_eta;
  std::vector<float>	SubGenJetAK8_mass;
  std::vector<float>	SubGenJetAK8_phi;
  std::vector<float>	SubGenJetAK8_pt;
  std::vector<float>	SubJet_btagCMVA;
  std::vector<float>	SubJet_btagCSVV2;
  std::vector<float>	SubJet_btagDeepB;
  std::vector<float>	SubJet_eta;
  std::vector<float>	SubJet_mass;
  std::vector<float>	SubJet_n2b1;
  std::vector<float>	SubJet_n3b1;
  std::vector<float>	SubJet_phi;
  std::vector<float>	SubJet_pt;
  std::vector<float>	SubJet_tau1;
  std::vector<float>	SubJet_tau2;
  std::vector<float>	SubJet_tau3;
  std::vector<float>	SubJet_tau4;
  std::vector<int>	Tau_charge;
  std::vector<float>	Tau_chargedIso;
  std::vector<int>	Tau_cleanmask;
  std::vector<int>	Tau_decayMode;
  std::vector<float>	Tau_dxy;
  std::vector<float>	Tau_dz;
  std::vector<float>	Tau_eta;
  std::vector<int>	Tau_genPartFlav;
  std::vector<int>	Tau_genPartIdx;
  std::vector<int>	Tau_idAntiEle;
  std::vector<int>	Tau_idAntiMu;
  std::vector<bool>	Tau_idDecayMode;
  std::vector<bool>	Tau_idDecayModeNewDMs;
  std::vector<int>	Tau_idMVAnewDM2017v2;
  std::vector<int>	Tau_idMVAoldDM;
  std::vector<int>	Tau_idMVAoldDM2017v1;
  std::vector<int>	Tau_idMVAoldDM2017v2;
  std::vector<int>	Tau_idMVAoldDMdR032017v2;
  std::vector<int>	Tau_jetIdx;
  std::vector<float>	Tau_leadTkDeltaEta;
  std::vector<float>	Tau_leadTkDeltaPhi;
  std::vector<float>	Tau_leadTkPtOverTauPt;
  std::vector<float>	Tau_mass;
  std::vector<float>	Tau_neutralIso;
  std::vector<float>	Tau_phi;
  std::vector<float>	Tau_photonsOutsideSignalCone;
  std::vector<float>	Tau_pt;
  std::vector<float>	Tau_puCorr;
  std::vector<float>	Tau_rawAntiEle;
  std::vector<int>	Tau_rawAntiEleCat;
  std::vector<float>	Tau_rawIso;
  std::vector<float>	Tau_rawIsodR03;
  std::vector<float>	Tau_rawMVAnewDM2017v2;
  std::vector<float>	Tau_rawMVAoldDM;
  std::vector<float>	Tau_rawMVAoldDM2017v1;
  std::vector<float>	Tau_rawMVAoldDM2017v2;
  std::vector<float>	Tau_rawMVAoldDMdR032017v2;
  std::vector<float>	TrigObj_eta;
  std::vector<int>	TrigObj_filterBits;
  std::vector<int>	TrigObj_id;
  std::vector<int>	TrigObj_l1charge;
  std::vector<int>	TrigObj_l1iso;
  std::vector<float>	TrigObj_l1pt;
  std::vector<float>	TrigObj_l1pt_2;
  std::vector<float>	TrigObj_l2pt;
  std::vector<float>	TrigObj_phi;
  std::vector<float>	TrigObj_pt;

  int	nTau;
  int	nPhoton;
  int	nSubGenJetAK8;
  int	nMuon;
  int	nElectron;
  int	nGenJet;
  int	nLHEScaleWeight;
  int	nLHEPdfWeight;
  int	nFatJet;
  int	nLHEPart;
  int	nGenVisTau;
  int	nTrigObj;
  int	nSoftActivityJet;
  int	nOtherPV;
  int	nGenPart;
  int	nGenJetAK8;
  int	nSubJet;
  int	nIsoTrack;
  int	nGenDressedLepton;
  int	nSV;
  int	nJet;

  float	CaloMET_phi;
  float	CaloMET_pt;
  float	CaloMET_sumEt;
  bool	Flag_BadChargedCandidateFilter;
  bool	Flag_BadChargedCandidateSummer16Filter;
  bool	Flag_BadPFMuonFilter;
  bool	Flag_BadPFMuonSummer16Filter;
  bool	Flag_CSCTightHalo2015Filter;
  bool	Flag_CSCTightHaloFilter;
  bool	Flag_CSCTightHaloTrkMuUnvetoFilter;
  bool	Flag_EcalDeadCellBoundaryEnergyFilter;
  bool	Flag_EcalDeadCellTriggerPrimitiveFilter;
  bool	Flag_HBHENoiseFilter;
  bool	Flag_HBHENoiseIsoFilter;
  bool	Flag_HcalStripHaloFilter;
  bool	Flag_METFilters;
  bool	Flag_chargedHadronTrackResolutionFilter;
  bool	Flag_ecalBadCalibFilter;
  bool	Flag_ecalLaserCorrFilter;
  bool	Flag_eeBadScFilter;
  bool	Flag_globalSuperTightHalo2016Filter;
  bool	Flag_globalTightHalo2016Filter;
  bool	Flag_goodVertices;
  bool	Flag_hcalLaserEventFilter;
  bool	Flag_muonBadTrackFilter;
  bool	Flag_trkPOGFilters;
  bool	Flag_trkPOG_logErrorTooManyClusters;
  bool	Flag_trkPOG_manystripclus53X;
  bool	Flag_trkPOG_toomanystripclus53X;
  float	GenMET_phi;
  float	GenMET_pt;
  float	Generator_binvar;
  int	Generator_id1;
  int	Generator_id2;
  float	Generator_scalePDF;
  float	Generator_weight;
  float	Generator_x1;
  float	Generator_x2;
  float	Generator_xpdf1;
  float	Generator_xpdf2;
  bool	HLT_AK4CaloJet100;
  bool	HLT_AK4CaloJet120;
  bool	HLT_AK4CaloJet30;
  bool	HLT_AK4CaloJet40;
  bool	HLT_AK4CaloJet50;
  bool	HLT_AK4CaloJet80;
  bool	HLT_AK4PFJet100;
  bool	HLT_AK4PFJet120;
  bool	HLT_AK4PFJet30;
  bool	HLT_AK4PFJet50;
  bool	HLT_AK4PFJet80;
  bool	HLT_AK8PFHT750_TrimMass50;
  bool	HLT_AK8PFHT800_TrimMass50;
  bool	HLT_AK8PFHT850_TrimMass50;
  bool	HLT_AK8PFHT900_TrimMass50;
  bool	HLT_AK8PFJet140;
  bool	HLT_AK8PFJet200;
  bool	HLT_AK8PFJet260;
  bool	HLT_AK8PFJet320;
  bool	HLT_AK8PFJet330_PFAK8BTagCSV_p1;
  bool	HLT_AK8PFJet330_PFAK8BTagCSV_p17;
  bool	HLT_AK8PFJet360_TrimMass30;
  bool	HLT_AK8PFJet380_TrimMass30;
  bool	HLT_AK8PFJet40;
  bool	HLT_AK8PFJet400;
  bool	HLT_AK8PFJet400_TrimMass30;
  bool	HLT_AK8PFJet420_TrimMass30;
  bool	HLT_AK8PFJet450;
  bool	HLT_AK8PFJet500;
  bool	HLT_AK8PFJet550;
  bool	HLT_AK8PFJet60;
  bool	HLT_AK8PFJet80;
  bool	HLT_AK8PFJetFwd140;
  bool	HLT_AK8PFJetFwd200;
  bool	HLT_AK8PFJetFwd260;
  bool	HLT_AK8PFJetFwd320;
  bool	HLT_AK8PFJetFwd40;
  bool	HLT_AK8PFJetFwd400;
  bool	HLT_AK8PFJetFwd450;
  bool	HLT_AK8PFJetFwd500;
  bool	HLT_AK8PFJetFwd60;
  bool	HLT_AK8PFJetFwd80;
  bool	HLT_BTagMu_AK4DiJet110_Mu5;
  bool	HLT_BTagMu_AK4DiJet170_Mu5;
  bool	HLT_BTagMu_AK4DiJet20_Mu5;
  bool	HLT_BTagMu_AK4DiJet40_Mu5;
  bool	HLT_BTagMu_AK4DiJet70_Mu5;
  bool	HLT_BTagMu_AK4Jet300_Mu5;
  bool	HLT_BTagMu_AK8DiJet170_Mu5;
  bool	HLT_BTagMu_AK8Jet300_Mu5;
  bool	HLT_CaloJet500_NoJetID;
  bool	HLT_CaloJet550_NoJetID;
  bool	HLT_CaloMET100_HBHECleaned;
  bool	HLT_CaloMET100_NotCleaned;
  bool	HLT_CaloMET110_NotCleaned;
  bool	HLT_CaloMET250_HBHECleaned;
  bool	HLT_CaloMET250_NotCleaned;
  bool	HLT_CaloMET300_HBHECleaned;
  bool	HLT_CaloMET350_HBHECleaned;
  bool	HLT_CaloMET70_HBHECleaned;
  bool	HLT_CaloMET80_HBHECleaned;
  bool	HLT_CaloMET80_NotCleaned;
  bool	HLT_CaloMET90_HBHECleaned;
  bool	HLT_CaloMET90_NotCleaned;
  bool	HLT_CaloMHT90;
  bool	HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;
  bool	HLT_DiJet110_35_Mjj650_PFMET110;
  bool	HLT_DiJet110_35_Mjj650_PFMET120;
  bool	HLT_DiJet110_35_Mjj650_PFMET130;
  bool	HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
  bool	HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;
  bool	HLT_DiPFJet15_FBEta3_NoCaloMatched;
  bool	HLT_DiPFJet15_NoCaloMatched;
  bool	HLT_DiPFJet25_FBEta3_NoCaloMatched;
  bool	HLT_DiPFJet25_NoCaloMatched;
  bool	HLT_DiPFJetAve100_HFJEC;
  bool	HLT_DiPFJetAve140;
  bool	HLT_DiPFJetAve15_HFJEC;
  bool	HLT_DiPFJetAve160_HFJEC;
  bool	HLT_DiPFJetAve200;
  bool	HLT_DiPFJetAve220_HFJEC;
  bool	HLT_DiPFJetAve25_HFJEC;
  bool	HLT_DiPFJetAve260;
  bool	HLT_DiPFJetAve300_HFJEC;
  bool	HLT_DiPFJetAve320;
  bool	HLT_DiPFJetAve35_HFJEC;
  bool	HLT_DiPFJetAve40;
  bool	HLT_DiPFJetAve400;
  bool	HLT_DiPFJetAve500;
  bool	HLT_DiPFJetAve60;
  bool	HLT_DiPFJetAve60_HFJEC;
  bool	HLT_DiPFJetAve80;
  bool	HLT_DiPFJetAve80_HFJEC;
  bool	HLT_DiSC30_18_EIso_AND_HE_Mass70;
  bool	HLT_Dimuon0_Jpsi;
  bool	HLT_Dimuon0_Jpsi3p5_Muon2;
  bool	HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;
  bool	HLT_Dimuon0_Jpsi_L1_NoOS;
  bool	HLT_Dimuon0_Jpsi_NoVertexing;
  bool	HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;
  bool	HLT_Dimuon0_Jpsi_NoVertexing_NoOS;
  bool	HLT_Dimuon0_LowMass;
  bool	HLT_Dimuon0_LowMass_L1_0er1p5;
  bool	HLT_Dimuon0_LowMass_L1_0er1p5R;
  bool	HLT_Dimuon0_LowMass_L1_4;
  bool	HLT_Dimuon0_LowMass_L1_4R;
  bool	HLT_Dimuon0_LowMass_L1_TM530;
  bool	HLT_Dimuon0_Upsilon_L1_4p5;
  bool	HLT_Dimuon0_Upsilon_L1_4p5NoOS;
  bool	HLT_Dimuon0_Upsilon_L1_4p5er2p0;
  bool	HLT_Dimuon0_Upsilon_L1_4p5er2p0M;
  bool	HLT_Dimuon0_Upsilon_L1_5;
  bool	HLT_Dimuon0_Upsilon_L1_5M;
  bool	HLT_Dimuon0_Upsilon_Muon_L1_TM0;
  bool	HLT_Dimuon0_Upsilon_Muon_NoL1Mass;
  bool	HLT_Dimuon0_Upsilon_NoVertexing;
  bool	HLT_Dimuon10_PsiPrime_Barrel_Seagulls;
  bool	HLT_Dimuon10_Upsilon_Barrel_Seagulls;
  bool	HLT_Dimuon12_Upsilon_eta1p5;
  bool	HLT_Dimuon14_Phi_Barrel_Seagulls;
  bool	HLT_Dimuon18_PsiPrime;
  bool	HLT_Dimuon18_PsiPrime_noCorrL1;
  bool	HLT_Dimuon20_Jpsi_Barrel_Seagulls;
  bool	HLT_Dimuon24_Phi_noCorrL1;
  bool	HLT_Dimuon24_Upsilon_noCorrL1;
  bool	HLT_Dimuon25_Jpsi;
  bool	HLT_Dimuon25_Jpsi_noCorrL1;
  bool	HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
  bool	HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
  bool	HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
  bool	HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
  bool	HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
  bool	HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
  bool	HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
  bool	HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
  bool	HLT_DoubleEle24_eta2p1_WPTight_Gsf;
  bool	HLT_DoubleEle25_CaloIdL_MW;
  bool	HLT_DoubleEle27_CaloIdL_MW;
  bool	HLT_DoubleEle33_CaloIdL_MW;
  bool	HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;
  bool	HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;
  bool	HLT_DoubleIsoMu20_eta2p1;
  bool	HLT_DoubleIsoMu24_eta2p1;
  bool	HLT_DoubleL2Mu50;
  bool	HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
  bool	HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg;
  bool	HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;
  bool	HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg;
  bool	HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
  bool	HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg;
  bool	HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;
  bool	HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg;
  bool	HLT_DoubleMu20_7_Mass0to30_L1_DM4;
  bool	HLT_DoubleMu20_7_Mass0to30_L1_DM4EG;
  bool	HLT_DoubleMu20_7_Mass0to30_Photon23;
  bool	HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi;
  bool	HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi;
  bool	HLT_DoubleMu3_DCA_PFMET50_PFMHT60;
  bool	HLT_DoubleMu3_DZ_PFMET50_PFMHT60;
  bool	HLT_DoubleMu3_DZ_PFMET70_PFMHT70;
  bool	HLT_DoubleMu3_DZ_PFMET90_PFMHT90;
  bool	HLT_DoubleMu3_Trk_Tau3mu;
  bool	HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;
  bool	HLT_DoubleMu43NoFiltersNoVtx;
  bool	HLT_DoubleMu48NoFiltersNoVtx;
  bool	HLT_DoubleMu4_3_Bs;
  bool	HLT_DoubleMu4_3_Jpsi_Displaced;
  bool	HLT_DoubleMu4_JpsiTrkTrk_Displaced;
  bool	HLT_DoubleMu4_JpsiTrk_Displaced;
  bool	HLT_DoubleMu4_Jpsi_Displaced;
  bool	HLT_DoubleMu4_Jpsi_NoVertexing;
  bool	HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;
  bool	HLT_DoubleMu4_Mass8_DZ_PFHT350;
  bool	HLT_DoubleMu4_PsiPrimeTrk_Displaced;
  bool	HLT_DoubleMu8_Mass8_PFHT350;
  bool	HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33;
  bool	HLT_DoublePFJets100_CaloBTagCSV_p33;
  bool	HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33;
  bool	HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33;
  bool	HLT_DoublePFJets200_CaloBTagCSV_p33;
  bool	HLT_DoublePFJets350_CaloBTagCSV_p33;
  bool	HLT_DoublePFJets40_CaloBTagCSV_p33;
  bool	HLT_DoublePhoton33_CaloIdL;
  bool	HLT_DoublePhoton70;
  bool	HLT_DoublePhoton85;
  bool	HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
  bool	HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg;
  bool	HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;
  bool	HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg;
  bool	HLT_ECALHT800;
  bool	HLT_EcalCalibration;
  bool	HLT_Ele115_CaloIdVT_GsfTrkIdT;
  bool	HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
  bool	HLT_Ele135_CaloIdVT_GsfTrkIdT;
  bool	HLT_Ele145_CaloIdVT_GsfTrkIdT;
  bool	HLT_Ele15_IsoVVVL_PFHT450;
  bool	HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5;
  bool	HLT_Ele15_IsoVVVL_PFHT450_PFMET50;
  bool	HLT_Ele15_IsoVVVL_PFHT600;
  bool	HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
  bool	HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
  bool	HLT_Ele200_CaloIdVT_GsfTrkIdT;
  bool	HLT_Ele20_WPLoose_Gsf;
  bool	HLT_Ele20_WPTight_Gsf;
  bool	HLT_Ele20_eta2p1_WPLoose_Gsf;
  bool	HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
  bool	HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
  bool	HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
  bool	HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
  bool	HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1;
  bool	HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1;
  bool	HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1;
  bool	HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1;
  bool	HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1;
  bool	HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1;
  bool	HLT_Ele250_CaloIdVT_GsfTrkIdT;
  bool	HLT_Ele27_Ele37_CaloIdL_MW;
  bool	HLT_Ele27_WPTight_Gsf;
  bool	HLT_Ele28_HighEta_SC20_Mass55;
  bool	HLT_Ele28_eta2p1_WPTight_Gsf_HT150;
  bool	HLT_Ele300_CaloIdVT_GsfTrkIdT;
  bool	HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;
  bool	HLT_Ele32_WPTight_Gsf;
  bool	HLT_Ele32_WPTight_Gsf_L1DoubleEG;
  bool	HLT_Ele35_WPTight_Gsf;
  bool	HLT_Ele35_WPTight_Gsf_L1EGMT;
  bool	HLT_Ele38_WPTight_Gsf;
  bool	HLT_Ele40_WPTight_Gsf;
  bool	HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;
  bool	HLT_Ele50_IsoVVVL_PFHT450;
  bool	HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
  bool	HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
  bool	HLT_FullTrack_Multiplicity100;
  bool	HLT_FullTrack_Multiplicity130;
  bool	HLT_FullTrack_Multiplicity155;
  bool	HLT_FullTrack_Multiplicity85;
  bool	HLT_HISinglePhoton10_Eta3p1ForPPRef;
  bool	HLT_HISinglePhoton20_Eta3p1ForPPRef;
  bool	HLT_HISinglePhoton30_Eta3p1ForPPRef;
  bool	HLT_HISinglePhoton40_Eta3p1ForPPRef;
  bool	HLT_HISinglePhoton50_Eta3p1ForPPRef;
  bool	HLT_HISinglePhoton60_Eta3p1ForPPRef;
  bool	HLT_HT300_Beamspot;
  bool	HLT_HT400_DisplacedDijet40_DisplacedTrack;
  bool	HLT_HT425;
  bool	HLT_HT430_DisplacedDijet40_DisplacedTrack;
  bool	HLT_HT430_DisplacedDijet60_DisplacedTrack;
  bool	HLT_HT430_DisplacedDijet80_DisplacedTrack;
  bool	HLT_HT450_Beamspot;
  bool	HLT_HT550_DisplacedDijet60_Inclusive;
  bool	HLT_HT550_DisplacedDijet80_Inclusive;
  bool	HLT_HT650_DisplacedDijet60_Inclusive;
  bool	HLT_HT650_DisplacedDijet80_Inclusive;
  bool	HLT_HT750_DisplacedDijet80_Inclusive;
  bool	HLT_HcalCalibration;
  bool	HLT_HcalIsolatedbunch;
  bool	HLT_HcalNZS;
  bool	HLT_HcalPhiSym;
  bool	HLT_IsoMu20;
  bool	HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1;
  bool	HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1;
  bool	HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1;
  bool	HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1;
  bool	HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1;
  bool	HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1;
  bool	HLT_IsoMu24;
  bool	HLT_IsoMu24_eta2p1;
  bool	HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1;
  bool	HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1;
  bool	HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1;
  bool	HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1;
  bool	HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
  bool	HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1;
  bool	HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1;
  bool	HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1;
  bool	HLT_IsoMu27;
  bool	HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1;
  bool	HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1;
  bool	HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1;
  bool	HLT_IsoMu30;
  bool	HLT_IsoTrackHB;
  bool	HLT_IsoTrackHE;
  bool	HLT_L1ETMHadSeeds;
  bool	HLT_L1MinimumBiasHF0OR;
  bool	HLT_L1MinimumBiasHF_OR;
  bool	HLT_L1NotBptxOR;
  bool	HLT_L1SingleMu18;
  bool	HLT_L1SingleMu25;
  bool	HLT_L1UnpairedBunchBptxMinus;
  bool	HLT_L1UnpairedBunchBptxPlus;
  bool	HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
  bool	HLT_L1_DoubleJet30_Mass_Min400_Mu10;
  bool	HLT_L2Mu10;
  bool	HLT_L2Mu10_NoVertex_NoBPTX;
  bool	HLT_L2Mu10_NoVertex_NoBPTX3BX;
  bool	HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;
  bool	HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;
  bool	HLT_L2Mu50;
  bool	HLT_MET105_IsoTrk50;
  bool	HLT_MET120_IsoTrk50;
  bool	HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1;
  bool	HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr;
  bool	HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
  bool	HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100;
  bool	HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110;
  bool	HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120;
  bool	HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130;
  bool	HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90;
  bool	HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight;
  bool	HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;
  bool	HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight;
  bool	HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight;
  bool	HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60;
  bool	HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33;
  bool	HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33;
  bool	HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33;
  bool	HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33;
  bool	HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33;
  bool	HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33;
  bool	HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33;
  bool	HLT_Mu12_DoublePhoton20;
  bool	HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
  bool	HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
  bool	HLT_Mu15_IsoVVVL_PFHT450;
  bool	HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5;
  bool	HLT_Mu15_IsoVVVL_PFHT450_PFMET50;
  bool	HLT_Mu15_IsoVVVL_PFHT600;
  bool	HLT_Mu17;
  bool	HLT_Mu17_Photon30_IsoCaloId;
  bool	HLT_Mu17_TrkIsoVVL;
  bool	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
  bool	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
  bool	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
  bool	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;
  bool	HLT_Mu18_Mu9;
  bool	HLT_Mu18_Mu9_DZ;
  bool	HLT_Mu18_Mu9_SameSign;
  bool	HLT_Mu18_Mu9_SameSign_DZ;
  bool	HLT_Mu19;
  bool	HLT_Mu19_TrkIsoVVL;
  bool	HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;
  bool	HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;
  bool	HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;
  bool	HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;
  bool	HLT_Mu20;
  bool	HLT_Mu20_Mu10;
  bool	HLT_Mu20_Mu10_DZ;
  bool	HLT_Mu20_Mu10_SameSign;
  bool	HLT_Mu20_Mu10_SameSign_DZ;
  bool	HLT_Mu20_TkMu0_Phi;
  bool	HLT_Mu23_Mu12;
  bool	HLT_Mu23_Mu12_DZ;
  bool	HLT_Mu23_Mu12_SameSign;
  bool	HLT_Mu23_Mu12_SameSign_DZ;
  bool	HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
  bool	HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
  bool	HLT_Mu25_TkMu0_Onia;
  bool	HLT_Mu25_TkMu0_Phi;
  bool	HLT_Mu27;
  bool	HLT_Mu27_Ele37_CaloIdL_MW;
  bool	HLT_Mu30_TkMu0_Onia;
  bool	HLT_Mu37_Ele27_CaloIdL_MW;
  bool	HLT_Mu37_TkMu27;
  bool	HLT_Mu3_PFJet40;
  bool	HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;
  bool	HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;
  bool	HLT_Mu50;
  bool	HLT_Mu50_IsoVVVL_PFHT450;
  bool	HLT_Mu55;
  bool	HLT_Mu7p5_L2Mu2_Jpsi;
  bool	HLT_Mu7p5_L2Mu2_Upsilon;
  bool	HLT_Mu7p5_Track2_Jpsi;
  bool	HLT_Mu7p5_Track2_Upsilon;
  bool	HLT_Mu7p5_Track3p5_Jpsi;
  bool	HLT_Mu7p5_Track3p5_Upsilon;
  bool	HLT_Mu7p5_Track7_Jpsi;
  bool	HLT_Mu7p5_Track7_Upsilon;
  bool	HLT_Mu8;
  bool	HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
  bool	HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;
  bool	HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;
  bool	HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;
  bool	HLT_Mu8_TrkIsoVVL;
  bool	HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;
  bool	HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
  bool	HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
  bool	HLT_OldMu100;
  bool	HLT_PFHT1050;
  bool	HLT_PFHT180;
  bool	HLT_PFHT250;
  bool	HLT_PFHT300PT30_QuadPFJet_75_60_45_40;
  bool	HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0;
  bool	HLT_PFHT350;
  bool	HLT_PFHT350MinPFJet15;
  bool	HLT_PFHT370;
  bool	HLT_PFHT380_SixPFJet32;
  bool	HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2;
  bool	HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2;
  bool	HLT_PFHT430;
  bool	HLT_PFHT430_SixPFJet40;
  bool	HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5;
  bool	HLT_PFHT500_PFMET100_PFMHT100_IDTight;
  bool	HLT_PFHT500_PFMET110_PFMHT110_IDTight;
  bool	HLT_PFHT510;
  bool	HLT_PFHT590;
  bool	HLT_PFHT680;
  bool	HLT_PFHT700_PFMET85_PFMHT85_IDTight;
  bool	HLT_PFHT700_PFMET95_PFMHT95_IDTight;
  bool	HLT_PFHT780;
  bool	HLT_PFHT800_PFMET75_PFMHT75_IDTight;
  bool	HLT_PFHT800_PFMET85_PFMHT85_IDTight;
  bool	HLT_PFHT890;
  bool	HLT_PFJet140;
  bool	HLT_PFJet200;
  bool	HLT_PFJet260;
  bool	HLT_PFJet320;
  bool	HLT_PFJet40;
  bool	HLT_PFJet400;
  bool	HLT_PFJet450;
  bool	HLT_PFJet500;
  bool	HLT_PFJet550;
  bool	HLT_PFJet60;
  bool	HLT_PFJet80;
  bool	HLT_PFJetFwd140;
  bool	HLT_PFJetFwd200;
  bool	HLT_PFJetFwd260;
  bool	HLT_PFJetFwd320;
  bool	HLT_PFJetFwd40;
  bool	HLT_PFJetFwd400;
  bool	HLT_PFJetFwd450;
  bool	HLT_PFJetFwd500;
  bool	HLT_PFJetFwd60;
  bool	HLT_PFJetFwd80;
  bool	HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1;
  bool	HLT_PFMET100_PFMHT100_IDTight_PFHT60;
  bool	HLT_PFMET110_PFMHT110_IDTight;
  bool	HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1;
  bool	HLT_PFMET120_PFMHT120_IDTight;
  bool	HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1;
  bool	HLT_PFMET120_PFMHT120_IDTight_PFHT60;
  bool	HLT_PFMET130_PFMHT130_IDTight;
  bool	HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1;
  bool	HLT_PFMET140_PFMHT140_IDTight;
  bool	HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1;
  bool	HLT_PFMET200_HBHECleaned;
  bool	HLT_PFMET200_HBHE_BeamHaloCleaned;
  bool	HLT_PFMET200_NotCleaned;
  bool	HLT_PFMET250_HBHECleaned;
  bool	HLT_PFMET300_HBHECleaned;
  bool	HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;
  bool	HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;
  bool	HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
  bool	HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;
  bool	HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;
  bool	HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;
  bool	HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;
  bool	HLT_PFMETTypeOne110_PFMHT110_IDTight;
  bool	HLT_PFMETTypeOne120_PFMHT120_IDTight;
  bool	HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;
  bool	HLT_PFMETTypeOne130_PFMHT130_IDTight;
  bool	HLT_PFMETTypeOne140_PFMHT140_IDTight;
  bool	HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned;
  bool	HLT_Photon120;
  bool	HLT_Photon120_R9Id90_HE10_IsoM;
  bool	HLT_Photon150;
  bool	HLT_Photon165_R9Id90_HE10_IsoM;
  bool	HLT_Photon175;
  bool	HLT_Photon200;
  bool	HLT_Photon20_HoverELoose;
  bool	HLT_Photon25;
  bool	HLT_Photon300_NoHE;
  bool	HLT_Photon30_HoverELoose;
  bool	HLT_Photon33;
  bool	HLT_Photon40_HoverELoose;
  bool	HLT_Photon50;
  bool	HLT_Photon50_HoverELoose;
  bool	HLT_Photon50_R9Id90_HE10_IsoM;
  bool	HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50;
  bool	HLT_Photon60_HoverELoose;
  bool	HLT_Photon60_R9Id90_CaloIdL_IsoL;
  bool	HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL;
  bool	HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15;
  bool	HLT_Photon75;
  bool	HLT_Photon75_R9Id90_HE10_IsoM;
  bool	HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;
  bool	HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3;
  bool	HLT_Photon90;
  bool	HLT_Photon90_CaloIdL_PFHT700;
  bool	HLT_Photon90_R9Id90_HE10_IsoM;
  bool	HLT_Physics;
  bool	HLT_Physics_part0;
  bool	HLT_Physics_part1;
  bool	HLT_Physics_part2;
  bool	HLT_Physics_part3;
  bool	HLT_Physics_part4;
  bool	HLT_Physics_part5;
  bool	HLT_Physics_part6;
  bool	HLT_Physics_part7;
  bool	HLT_QuadPFJet103_88_75_15;
  bool	HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2;
  bool	HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1;
  bool	HLT_QuadPFJet105_88_76_15;
  bool	HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2;
  bool	HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1;
  bool	HLT_QuadPFJet111_90_80_15;
  bool	HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2;
  bool	HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1;
  bool	HLT_QuadPFJet98_83_71_15;
  bool	HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2;
  bool	HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1;
  bool	HLT_Random;
  bool	HLT_Rsq0p35;
  bool	HLT_Rsq0p40;
  bool	HLT_RsqMR300_Rsq0p09_MR200;
  bool	HLT_RsqMR300_Rsq0p09_MR200_4jet;
  bool	HLT_RsqMR320_Rsq0p09_MR200;
  bool	HLT_RsqMR320_Rsq0p09_MR200_4jet;
  bool	HLT_SingleJet30_Mu12_SinglePFJet40;
  bool	HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;
  bool	HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;
  bool	HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;
  bool	HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;
  bool	HLT_TkMu100;
  bool	HLT_Trimuon5_3p5_2_Upsilon_Muon;
  bool	HLT_TripleJet110_35_35_Mjj650_PFMET110;
  bool	HLT_TripleJet110_35_35_Mjj650_PFMET120;
  bool	HLT_TripleJet110_35_35_Mjj650_PFMET130;
  bool	HLT_TripleMu_10_5_5_DZ;
  bool	HLT_TripleMu_12_10_5;
  bool	HLT_TripleMu_5_3_3_Mass3p8to60_DCA;
  bool	HLT_TripleMu_5_3_3_Mass3p8to60_DZ;
  bool	HLT_TriplePhoton_20_20_20_CaloIdLV2;
  bool	HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL;
  bool	HLT_TriplePhoton_30_30_10_CaloIdLV2;
  bool	HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL;
  bool	HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL;
  bool	HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;
  bool	HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx;
  bool	HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx;
  bool	HLT_UncorrectedJetE30_NoBPTX;
  bool	HLT_UncorrectedJetE30_NoBPTX3BX;
  bool	HLT_UncorrectedJetE60_NoBPTX3BX;
  bool	HLT_UncorrectedJetE70_NoBPTX3BX;
  bool	HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg;
  bool	HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg;
  bool	HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg;
  bool	HLT_ZeroBias;
  bool	HLT_ZeroBias_FirstBXAfterTrain;
  bool	HLT_ZeroBias_FirstCollisionAfterAbortGap;
  bool	HLT_ZeroBias_FirstCollisionInTrain;
  bool	HLT_ZeroBias_IsolatedBunches;
  bool	HLT_ZeroBias_LastCollisionInTrain;
  bool	HLT_ZeroBias_part0;
  bool	HLT_ZeroBias_part1;
  bool	HLT_ZeroBias_part2;
  bool	HLT_ZeroBias_part3;
  bool	HLT_ZeroBias_part4;
  bool	HLT_ZeroBias_part5;
  bool	HLT_ZeroBias_part6;
  bool	HLT_ZeroBias_part7;
  bool	HLTriggerFinalPath;
  bool	HLTriggerFirstPath;
  bool	L1simulation_step;
  float	LHEWeight_originalXWGTUP;
  float	LHE_HT;
  float	LHE_HTIncoming;
  int	LHE_Nb;
  int	LHE_Nc;
  int	LHE_Nglu;
  int	LHE_Njets;
  int	LHE_NpLO;
  int	LHE_NpNLO;
  int	LHE_Nuds;
  float	LHE_Vpt;
  float	MET_MetUnclustEnUpDeltaX;
  float	MET_MetUnclustEnUpDeltaY;
  float	MET_covXX;
  float	MET_covXY;
  float	MET_covYY;
  float	MET_fiducialGenPhi;
  float	MET_fiducialGenPt;
  float	MET_phi;
  float	MET_pt;
  float	MET_significance;
  float	MET_sumEt;
  float	PV_chi2;
  float	PV_ndof;
  int	PV_npvs;
  int	PV_npvsGood;
  float	PV_score;
  float	PV_x;
  float	PV_y;
  float	PV_z;
  int	Pileup_nPU;
  float	Pileup_nTrueInt;
  int	Pileup_sumEOOT;
  int	Pileup_sumLOOT;
  float	PuppiMET_phi;
  float	PuppiMET_pt;
  float	PuppiMET_sumEt;
  float	RawMET_phi;
  float	RawMET_pt;
  float	RawMET_sumEt;
  float	SoftActivityJetHT;
  float	SoftActivityJetHT10;
  float	SoftActivityJetHT2;
  float	SoftActivityJetHT5;
  int	SoftActivityJetNjets10;
  int	SoftActivityJetNjets2;
  int	SoftActivityJetNjets5;
  float	TkMET_phi;
  float	TkMET_pt;
  float	TkMET_sumEt;
  long	event;
  float	fixedGridRhoFastjetAll;
  float	fixedGridRhoFastjetCentralCalo;
  float	fixedGridRhoFastjetCentralNeutral;
  int	genTtbarId;
  float	genWeight;
  unsigned int	luminosityBlock;
  unsigned int	run;

  //--------------------------------------------------------------------------
  // --- Structs can be filled by calling fill(), or individual fill
  // --- methods, e.g., fillElectrons()
  // --- after the call to read(...)
  //----------- --------------------------------------------------------------
  struct Electron_s
  {
    int	charge;
    int	cleanmask;
    bool	convVeto;
    int	cutBased;
    bool	cutBased_HEEP;
    float	deltaEtaSC;
    float	dr03EcalRecHitSumEt;
    float	dr03HcalDepth1TowerSumEt;
    float	dr03TkSumPt;
    float	dxy;
    float	dxyErr;
    float	dz;
    float	dzErr;
    float	eCorr;
    float	eInvMinusPInv;
    float	energyErr;
    float	eta;
    int	genPartFlav;
    int	genPartIdx;
    float	hoe;
    float	ip3d;
    bool	isPFcand;
    int	jetIdx;
    int	lostHits;
    float	mass;
    float	miniPFRelIso_all;
    float	miniPFRelIso_chg;
    float	mvaFall17Iso;
    bool	mvaFall17Iso_WP80;
    bool	mvaFall17Iso_WP90;
    bool	mvaFall17Iso_WPL;
    float	mvaFall17noIso;
    bool	mvaFall17noIso_WP80;
    bool	mvaFall17noIso_WP90;
    bool	mvaFall17noIso_WPL;
    float	mvaTTH;
    int	pdgId;
    float	pfRelIso03_all;
    float	pfRelIso03_chg;
    float	phi;
    int	photonIdx;
    float	pt;
    float	r9;
    float	sieie;
    float	sip3d;
    int	tightCharge;
    int	vidNestedWPBitmap;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Electron" << std::endl;
      sprintf(r, "  %-32s: %f\n", "charge", ( double)charge); os << r;
      sprintf(r, "  %-32s: %f\n", "cleanmask", ( double)cleanmask); os << r;
      sprintf(r, "  %-32s: %f\n", "convVeto", ( double)convVeto); os << r;
      sprintf(r, "  %-32s: %f\n", "cutBased", ( double)cutBased); os << r;
      sprintf(r, "  %-32s: %f\n", "cutBased_HEEP", ( double)cutBased_HEEP); os << r;
      sprintf(r, "  %-32s: %f\n", "deltaEtaSC", ( double)deltaEtaSC); os << r;
      sprintf(r, "  %-32s: %f\n", "dr03EcalRecHitSumEt", ( double)dr03EcalRecHitSumEt); os << r;
      sprintf(r, "  %-32s: %f\n", "dr03HcalDepth1TowerSumEt", ( double)dr03HcalDepth1TowerSumEt); os << r;
      sprintf(r, "  %-32s: %f\n", "dr03TkSumPt", ( double)dr03TkSumPt); os << r;
      sprintf(r, "  %-32s: %f\n", "dxy", ( double)dxy); os << r;
      sprintf(r, "  %-32s: %f\n", "dxyErr", ( double)dxyErr); os << r;
      sprintf(r, "  %-32s: %f\n", "dz", ( double)dz); os << r;
      sprintf(r, "  %-32s: %f\n", "dzErr", ( double)dzErr); os << r;
      sprintf(r, "  %-32s: %f\n", "eCorr", ( double)eCorr); os << r;
      sprintf(r, "  %-32s: %f\n", "eInvMinusPInv", ( double)eInvMinusPInv); os << r;
      sprintf(r, "  %-32s: %f\n", "energyErr", ( double)energyErr); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartFlav", ( double)genPartFlav); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartIdx", ( double)genPartIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "hoe", ( double)hoe); os << r;
      sprintf(r, "  %-32s: %f\n", "ip3d", ( double)ip3d); os << r;
      sprintf(r, "  %-32s: %f\n", "isPFcand", ( double)isPFcand); os << r;
      sprintf(r, "  %-32s: %f\n", "jetIdx", ( double)jetIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "lostHits", ( double)lostHits); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "miniPFRelIso_all", ( double)miniPFRelIso_all); os << r;
      sprintf(r, "  %-32s: %f\n", "miniPFRelIso_chg", ( double)miniPFRelIso_chg); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17Iso", ( double)mvaFall17Iso); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17Iso_WP80", ( double)mvaFall17Iso_WP80); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17Iso_WP90", ( double)mvaFall17Iso_WP90); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17Iso_WPL", ( double)mvaFall17Iso_WPL); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17noIso", ( double)mvaFall17noIso); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17noIso_WP80", ( double)mvaFall17noIso_WP80); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17noIso_WP90", ( double)mvaFall17noIso_WP90); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaFall17noIso_WPL", ( double)mvaFall17noIso_WPL); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaTTH", ( double)mvaTTH); os << r;
      sprintf(r, "  %-32s: %f\n", "pdgId", ( double)pdgId); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_all", ( double)pfRelIso03_all); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_chg", ( double)pfRelIso03_chg); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "photonIdx", ( double)photonIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "r9", ( double)r9); os << r;
      sprintf(r, "  %-32s: %f\n", "sieie", ( double)sieie); os << r;
      sprintf(r, "  %-32s: %f\n", "sip3d", ( double)sip3d); os << r;
      sprintf(r, "  %-32s: %f\n", "tightCharge", ( double)tightCharge); os << r;
      sprintf(r, "  %-32s: %f\n", "vidNestedWPBitmap", ( double)vidNestedWPBitmap); os << r;
      return os;
    }
  };

  struct FatJet_s
  {
    float	area;
    float	btagCMVA;
    float	btagCSVV2;
    float	btagDeepB;
    float	btagHbb;
    float	eta;
    int	jetId;
    float	mass;
    float	msoftdrop;
    float	n2b1;
    float	n3b1;
    float	phi;
    float	pt;
    int	subJetIdx1;
    int	subJetIdx2;
    float	tau1;
    float	tau2;
    float	tau3;
    float	tau4;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "FatJet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "area", ( double)area); os << r;
      sprintf(r, "  %-32s: %f\n", "btagCMVA", ( double)btagCMVA); os << r;
      sprintf(r, "  %-32s: %f\n", "btagCSVV2", ( double)btagCSVV2); os << r;
      sprintf(r, "  %-32s: %f\n", "btagDeepB", ( double)btagDeepB); os << r;
      sprintf(r, "  %-32s: %f\n", "btagHbb", ( double)btagHbb); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "jetId", ( double)jetId); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "msoftdrop", ( double)msoftdrop); os << r;
      sprintf(r, "  %-32s: %f\n", "n2b1", ( double)n2b1); os << r;
      sprintf(r, "  %-32s: %f\n", "n3b1", ( double)n3b1); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "subJetIdx1", ( double)subJetIdx1); os << r;
      sprintf(r, "  %-32s: %f\n", "subJetIdx2", ( double)subJetIdx2); os << r;
      sprintf(r, "  %-32s: %f\n", "tau1", ( double)tau1); os << r;
      sprintf(r, "  %-32s: %f\n", "tau2", ( double)tau2); os << r;
      sprintf(r, "  %-32s: %f\n", "tau3", ( double)tau3); os << r;
      sprintf(r, "  %-32s: %f\n", "tau4", ( double)tau4); os << r;
      return os;
    }
  };

  struct GenDressedLepton_s
  {
    float	eta;
    float	mass;
    int	pdgId;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "GenDressedLepton" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "pdgId", ( double)pdgId); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };

  struct GenJet_s
  {
    float	eta;
    int	hadronFlavour;
    float	mass;
    int	partonFlavour;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "GenJet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "hadronFlavour", ( double)hadronFlavour); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "partonFlavour", ( double)partonFlavour); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };

  struct GenJetAK8_s
  {
    float	eta;
    int	hadronFlavour;
    float	mass;
    int	partonFlavour;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "GenJetAK8" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "hadronFlavour", ( double)hadronFlavour); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "partonFlavour", ( double)partonFlavour); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };

  struct GenPart_s
  {
    float	eta;
    int	genPartIdxMother;
    float	mass;
    int	pdgId;
    float	phi;
    float	pt;
    int	status;
    int	statusFlags;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "GenPart" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartIdxMother", ( double)genPartIdxMother); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "pdgId", ( double)pdgId); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "status", ( double)status); os << r;
      sprintf(r, "  %-32s: %f\n", "statusFlags", ( double)statusFlags); os << r;
      return os;
    }
  };

  struct GenVisTau_s
  {
    int	charge;
    float	eta;
    int	genPartIdxMother;
    float	mass;
    float	phi;
    float	pt;
    int	status;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "GenVisTau" << std::endl;
      sprintf(r, "  %-32s: %f\n", "charge", ( double)charge); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartIdxMother", ( double)genPartIdxMother); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "status", ( double)status); os << r;
      return os;
    }
  };

  struct IsoTrack_s
  {
    float	dxy;
    float	dz;
    float	eta;
    bool	isHighPurityTrack;
    bool	isPFcand;
    float	miniPFRelIso_all;
    float	miniPFRelIso_chg;
    int	pdgId;
    float	pfRelIso03_all;
    float	pfRelIso03_chg;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "IsoTrack" << std::endl;
      sprintf(r, "  %-32s: %f\n", "dxy", ( double)dxy); os << r;
      sprintf(r, "  %-32s: %f\n", "dz", ( double)dz); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "isHighPurityTrack", ( double)isHighPurityTrack); os << r;
      sprintf(r, "  %-32s: %f\n", "isPFcand", ( double)isPFcand); os << r;
      sprintf(r, "  %-32s: %f\n", "miniPFRelIso_all", ( double)miniPFRelIso_all); os << r;
      sprintf(r, "  %-32s: %f\n", "miniPFRelIso_chg", ( double)miniPFRelIso_chg); os << r;
      sprintf(r, "  %-32s: %f\n", "pdgId", ( double)pdgId); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_all", ( double)pfRelIso03_all); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_chg", ( double)pfRelIso03_chg); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };

  struct Jet_s
  {
    float	area;
    float	bReg;
    float	btagCMVA;
    float	btagCSVV2;
    float	btagDeepB;
    float	btagDeepC;
    float	btagDeepFlavB;
    float	chEmEF;
    float	chHEF;
    int	cleanmask;
    int	electronIdx1;
    int	electronIdx2;
    float	eta;
    int	genJetIdx;
    int	hadronFlavour;
    int	jetId;
    float	mass;
    int	muonIdx1;
    int	muonIdx2;
    int	nConstituents;
    int	nElectrons;
    int	nMuons;
    float	neEmEF;
    float	neHEF;
    int	partonFlavour;
    float	phi;
    float	pt;
    int	puId;
    float	qgl;
    float	rawFactor;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Jet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "area", ( double)area); os << r;
      sprintf(r, "  %-32s: %f\n", "bReg", ( double)bReg); os << r;
      sprintf(r, "  %-32s: %f\n", "btagCMVA", ( double)btagCMVA); os << r;
      sprintf(r, "  %-32s: %f\n", "btagCSVV2", ( double)btagCSVV2); os << r;
      sprintf(r, "  %-32s: %f\n", "btagDeepB", ( double)btagDeepB); os << r;
      sprintf(r, "  %-32s: %f\n", "btagDeepC", ( double)btagDeepC); os << r;
      sprintf(r, "  %-32s: %f\n", "btagDeepFlavB", ( double)btagDeepFlavB); os << r;
      sprintf(r, "  %-32s: %f\n", "chEmEF", ( double)chEmEF); os << r;
      sprintf(r, "  %-32s: %f\n", "chHEF", ( double)chHEF); os << r;
      sprintf(r, "  %-32s: %f\n", "cleanmask", ( double)cleanmask); os << r;
      sprintf(r, "  %-32s: %f\n", "electronIdx1", ( double)electronIdx1); os << r;
      sprintf(r, "  %-32s: %f\n", "electronIdx2", ( double)electronIdx2); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "genJetIdx", ( double)genJetIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "hadronFlavour", ( double)hadronFlavour); os << r;
      sprintf(r, "  %-32s: %f\n", "jetId", ( double)jetId); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "muonIdx1", ( double)muonIdx1); os << r;
      sprintf(r, "  %-32s: %f\n", "muonIdx2", ( double)muonIdx2); os << r;
      sprintf(r, "  %-32s: %f\n", "nConstituents", ( double)nConstituents); os << r;
      sprintf(r, "  %-32s: %f\n", "nElectrons", ( double)nElectrons); os << r;
      sprintf(r, "  %-32s: %f\n", "nMuons", ( double)nMuons); os << r;
      sprintf(r, "  %-32s: %f\n", "neEmEF", ( double)neEmEF); os << r;
      sprintf(r, "  %-32s: %f\n", "neHEF", ( double)neHEF); os << r;
      sprintf(r, "  %-32s: %f\n", "partonFlavour", ( double)partonFlavour); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "puId", ( double)puId); os << r;
      sprintf(r, "  %-32s: %f\n", "qgl", ( double)qgl); os << r;
      sprintf(r, "  %-32s: %f\n", "rawFactor", ( double)rawFactor); os << r;
      return os;
    }
  };

  struct LHEPart_s
  {
    float	eta;
    float	mass;
    int	pdgId;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "LHEPart" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "pdgId", ( double)pdgId); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };

  struct Muon_s
  {
    int	charge;
    int	cleanmask;
    float	dxy;
    float	dxyErr;
    float	dz;
    float	dzErr;
    float	eta;
    int	genPartFlav;
    int	genPartIdx;
    int	highPtId;
    float	ip3d;
    bool	isPFcand;
    int	jetIdx;
    float	mass;
    bool	mediumId;
    float	miniPFRelIso_all;
    float	miniPFRelIso_chg;
    float	mvaTTH;
    int	nStations;
    int	nTrackerLayers;
    int	pdgId;
    float	pfRelIso03_all;
    float	pfRelIso03_chg;
    float	pfRelIso04_all;
    float	phi;
    float	pt;
    float	ptErr;
    float	segmentComp;
    float	sip3d;
    bool	softId;
    int	tightCharge;
    bool	tightId;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Muon" << std::endl;
      sprintf(r, "  %-32s: %f\n", "charge", ( double)charge); os << r;
      sprintf(r, "  %-32s: %f\n", "cleanmask", ( double)cleanmask); os << r;
      sprintf(r, "  %-32s: %f\n", "dxy", ( double)dxy); os << r;
      sprintf(r, "  %-32s: %f\n", "dxyErr", ( double)dxyErr); os << r;
      sprintf(r, "  %-32s: %f\n", "dz", ( double)dz); os << r;
      sprintf(r, "  %-32s: %f\n", "dzErr", ( double)dzErr); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartFlav", ( double)genPartFlav); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartIdx", ( double)genPartIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "highPtId", ( double)highPtId); os << r;
      sprintf(r, "  %-32s: %f\n", "ip3d", ( double)ip3d); os << r;
      sprintf(r, "  %-32s: %f\n", "isPFcand", ( double)isPFcand); os << r;
      sprintf(r, "  %-32s: %f\n", "jetIdx", ( double)jetIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "mediumId", ( double)mediumId); os << r;
      sprintf(r, "  %-32s: %f\n", "miniPFRelIso_all", ( double)miniPFRelIso_all); os << r;
      sprintf(r, "  %-32s: %f\n", "miniPFRelIso_chg", ( double)miniPFRelIso_chg); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaTTH", ( double)mvaTTH); os << r;
      sprintf(r, "  %-32s: %f\n", "nStations", ( double)nStations); os << r;
      sprintf(r, "  %-32s: %f\n", "nTrackerLayers", ( double)nTrackerLayers); os << r;
      sprintf(r, "  %-32s: %f\n", "pdgId", ( double)pdgId); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_all", ( double)pfRelIso03_all); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_chg", ( double)pfRelIso03_chg); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso04_all", ( double)pfRelIso04_all); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "ptErr", ( double)ptErr); os << r;
      sprintf(r, "  %-32s: %f\n", "segmentComp", ( double)segmentComp); os << r;
      sprintf(r, "  %-32s: %f\n", "sip3d", ( double)sip3d); os << r;
      sprintf(r, "  %-32s: %f\n", "softId", ( double)softId); os << r;
      sprintf(r, "  %-32s: %f\n", "tightCharge", ( double)tightCharge); os << r;
      sprintf(r, "  %-32s: %f\n", "tightId", ( double)tightId); os << r;
      return os;
    }
  };

  struct Photon_s
  {
    int	charge;
    int	cleanmask;
    int	cutBasedBitmap;
    float	eCorr;
    int	electronIdx;
    bool	electronVeto;
    float	energyErr;
    float	eta;
    int	genPartFlav;
    int	genPartIdx;
    float	hoe;
    bool	isScEtaEB;
    bool	isScEtaEE;
    int	jetIdx;
    float	mass;
    float	mvaID;
    bool	mvaID_WP80;
    bool	mvaID_WP90;
    int	pdgId;
    float	pfRelIso03_all;
    float	pfRelIso03_chg;
    float	phi;
    bool	pixelSeed;
    float	pt;
    float	r9;
    float	sieie;
    int	vidNestedWPBitmap;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Photon" << std::endl;
      sprintf(r, "  %-32s: %f\n", "charge", ( double)charge); os << r;
      sprintf(r, "  %-32s: %f\n", "cleanmask", ( double)cleanmask); os << r;
      sprintf(r, "  %-32s: %f\n", "cutBasedBitmap", ( double)cutBasedBitmap); os << r;
      sprintf(r, "  %-32s: %f\n", "eCorr", ( double)eCorr); os << r;
      sprintf(r, "  %-32s: %f\n", "electronIdx", ( double)electronIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "electronVeto", ( double)electronVeto); os << r;
      sprintf(r, "  %-32s: %f\n", "energyErr", ( double)energyErr); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartFlav", ( double)genPartFlav); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartIdx", ( double)genPartIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "hoe", ( double)hoe); os << r;
      sprintf(r, "  %-32s: %f\n", "isScEtaEB", ( double)isScEtaEB); os << r;
      sprintf(r, "  %-32s: %f\n", "isScEtaEE", ( double)isScEtaEE); os << r;
      sprintf(r, "  %-32s: %f\n", "jetIdx", ( double)jetIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaID", ( double)mvaID); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaID_WP80", ( double)mvaID_WP80); os << r;
      sprintf(r, "  %-32s: %f\n", "mvaID_WP90", ( double)mvaID_WP90); os << r;
      sprintf(r, "  %-32s: %f\n", "pdgId", ( double)pdgId); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_all", ( double)pfRelIso03_all); os << r;
      sprintf(r, "  %-32s: %f\n", "pfRelIso03_chg", ( double)pfRelIso03_chg); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pixelSeed", ( double)pixelSeed); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "r9", ( double)r9); os << r;
      sprintf(r, "  %-32s: %f\n", "sieie", ( double)sieie); os << r;
      sprintf(r, "  %-32s: %f\n", "vidNestedWPBitmap", ( double)vidNestedWPBitmap); os << r;
      return os;
    }
  };

  struct SV_s
  {
    float	chi2;
    float	dlen;
    float	dlenSig;
    float	eta;
    float	mass;
    float	ndof;
    float	pAngle;
    float	phi;
    float	pt;
    float	x;
    float	y;
    float	z;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "SV" << std::endl;
      sprintf(r, "  %-32s: %f\n", "chi2", ( double)chi2); os << r;
      sprintf(r, "  %-32s: %f\n", "dlen", ( double)dlen); os << r;
      sprintf(r, "  %-32s: %f\n", "dlenSig", ( double)dlenSig); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "ndof", ( double)ndof); os << r;
      sprintf(r, "  %-32s: %f\n", "pAngle", ( double)pAngle); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "x", ( double)x); os << r;
      sprintf(r, "  %-32s: %f\n", "y", ( double)y); os << r;
      sprintf(r, "  %-32s: %f\n", "z", ( double)z); os << r;
      return os;
    }
  };

  struct SoftActivityJet_s
  {
    float	eta;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "SoftActivityJet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };

  struct SubGenJetAK8_s
  {
    float	eta;
    float	mass;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "SubGenJetAK8" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };

  struct SubJet_s
  {
    float	btagCMVA;
    float	btagCSVV2;
    float	btagDeepB;
    float	eta;
    float	mass;
    float	n2b1;
    float	n3b1;
    float	phi;
    float	pt;
    float	tau1;
    float	tau2;
    float	tau3;
    float	tau4;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "SubJet" << std::endl;
      sprintf(r, "  %-32s: %f\n", "btagCMVA", ( double)btagCMVA); os << r;
      sprintf(r, "  %-32s: %f\n", "btagCSVV2", ( double)btagCSVV2); os << r;
      sprintf(r, "  %-32s: %f\n", "btagDeepB", ( double)btagDeepB); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "n2b1", ( double)n2b1); os << r;
      sprintf(r, "  %-32s: %f\n", "n3b1", ( double)n3b1); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "tau1", ( double)tau1); os << r;
      sprintf(r, "  %-32s: %f\n", "tau2", ( double)tau2); os << r;
      sprintf(r, "  %-32s: %f\n", "tau3", ( double)tau3); os << r;
      sprintf(r, "  %-32s: %f\n", "tau4", ( double)tau4); os << r;
      return os;
    }
  };

  struct Tau_s
  {
    int	charge;
    float	chargedIso;
    int	cleanmask;
    int	decayMode;
    float	dxy;
    float	dz;
    float	eta;
    int	genPartFlav;
    int	genPartIdx;
    int	idAntiEle;
    int	idAntiMu;
    bool	idDecayMode;
    bool	idDecayModeNewDMs;
    int	idMVAnewDM2017v2;
    int	idMVAoldDM;
    int	idMVAoldDM2017v1;
    int	idMVAoldDM2017v2;
    int	idMVAoldDMdR032017v2;
    int	jetIdx;
    float	leadTkDeltaEta;
    float	leadTkDeltaPhi;
    float	leadTkPtOverTauPt;
    float	mass;
    float	neutralIso;
    float	phi;
    float	photonsOutsideSignalCone;
    float	pt;
    float	puCorr;
    float	rawAntiEle;
    int	rawAntiEleCat;
    float	rawIso;
    float	rawIsodR03;
    float	rawMVAnewDM2017v2;
    float	rawMVAoldDM;
    float	rawMVAoldDM2017v1;
    float	rawMVAoldDM2017v2;
    float	rawMVAoldDMdR032017v2;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "Tau" << std::endl;
      sprintf(r, "  %-32s: %f\n", "charge", ( double)charge); os << r;
      sprintf(r, "  %-32s: %f\n", "chargedIso", ( double)chargedIso); os << r;
      sprintf(r, "  %-32s: %f\n", "cleanmask", ( double)cleanmask); os << r;
      sprintf(r, "  %-32s: %f\n", "decayMode", ( double)decayMode); os << r;
      sprintf(r, "  %-32s: %f\n", "dxy", ( double)dxy); os << r;
      sprintf(r, "  %-32s: %f\n", "dz", ( double)dz); os << r;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartFlav", ( double)genPartFlav); os << r;
      sprintf(r, "  %-32s: %f\n", "genPartIdx", ( double)genPartIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "idAntiEle", ( double)idAntiEle); os << r;
      sprintf(r, "  %-32s: %f\n", "idAntiMu", ( double)idAntiMu); os << r;
      sprintf(r, "  %-32s: %f\n", "idDecayMode", ( double)idDecayMode); os << r;
      sprintf(r, "  %-32s: %f\n", "idDecayModeNewDMs", ( double)idDecayModeNewDMs); os << r;
      sprintf(r, "  %-32s: %f\n", "idMVAnewDM2017v2", ( double)idMVAnewDM2017v2); os << r;
      sprintf(r, "  %-32s: %f\n", "idMVAoldDM", ( double)idMVAoldDM); os << r;
      sprintf(r, "  %-32s: %f\n", "idMVAoldDM2017v1", ( double)idMVAoldDM2017v1); os << r;
      sprintf(r, "  %-32s: %f\n", "idMVAoldDM2017v2", ( double)idMVAoldDM2017v2); os << r;
      sprintf(r, "  %-32s: %f\n", "idMVAoldDMdR032017v2", ( double)idMVAoldDMdR032017v2); os << r;
      sprintf(r, "  %-32s: %f\n", "jetIdx", ( double)jetIdx); os << r;
      sprintf(r, "  %-32s: %f\n", "leadTkDeltaEta", ( double)leadTkDeltaEta); os << r;
      sprintf(r, "  %-32s: %f\n", "leadTkDeltaPhi", ( double)leadTkDeltaPhi); os << r;
      sprintf(r, "  %-32s: %f\n", "leadTkPtOverTauPt", ( double)leadTkPtOverTauPt); os << r;
      sprintf(r, "  %-32s: %f\n", "mass", ( double)mass); os << r;
      sprintf(r, "  %-32s: %f\n", "neutralIso", ( double)neutralIso); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "photonsOutsideSignalCone", ( double)photonsOutsideSignalCone); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      sprintf(r, "  %-32s: %f\n", "puCorr", ( double)puCorr); os << r;
      sprintf(r, "  %-32s: %f\n", "rawAntiEle", ( double)rawAntiEle); os << r;
      sprintf(r, "  %-32s: %f\n", "rawAntiEleCat", ( double)rawAntiEleCat); os << r;
      sprintf(r, "  %-32s: %f\n", "rawIso", ( double)rawIso); os << r;
      sprintf(r, "  %-32s: %f\n", "rawIsodR03", ( double)rawIsodR03); os << r;
      sprintf(r, "  %-32s: %f\n", "rawMVAnewDM2017v2", ( double)rawMVAnewDM2017v2); os << r;
      sprintf(r, "  %-32s: %f\n", "rawMVAoldDM", ( double)rawMVAoldDM); os << r;
      sprintf(r, "  %-32s: %f\n", "rawMVAoldDM2017v1", ( double)rawMVAoldDM2017v1); os << r;
      sprintf(r, "  %-32s: %f\n", "rawMVAoldDM2017v2", ( double)rawMVAoldDM2017v2); os << r;
      sprintf(r, "  %-32s: %f\n", "rawMVAoldDMdR032017v2", ( double)rawMVAoldDMdR032017v2); os << r;
      return os;
    }
  };

  struct TrigObj_s
  {
    float	eta;
    int	filterBits;
    int	id;
    int	l1charge;
    int	l1iso;
    float	l1pt;
    float	l1pt_2;
    float	l2pt;
    float	phi;
    float	pt;

    std::ostream& operator<<(std::ostream& os)
    {
      char r[1024];
      os << "TrigObj" << std::endl;
      sprintf(r, "  %-32s: %f\n", "eta", ( double)eta); os << r;
      sprintf(r, "  %-32s: %f\n", "filterBits", ( double)filterBits); os << r;
      sprintf(r, "  %-32s: %f\n", "id", ( double)id); os << r;
      sprintf(r, "  %-32s: %f\n", "l1charge", ( double)l1charge); os << r;
      sprintf(r, "  %-32s: %f\n", "l1iso", ( double)l1iso); os << r;
      sprintf(r, "  %-32s: %f\n", "l1pt", ( double)l1pt); os << r;
      sprintf(r, "  %-32s: %f\n", "l1pt_2", ( double)l1pt_2); os << r;
      sprintf(r, "  %-32s: %f\n", "l2pt", ( double)l2pt); os << r;
      sprintf(r, "  %-32s: %f\n", "phi", ( double)phi); os << r;
      sprintf(r, "  %-32s: %f\n", "pt", ( double)pt); os << r;
      return os;
    }
  };


  void fillElectrons()
  {
    Electron.resize(Electron_charge.size());
    for(unsigned int i=0; i < Electron.size(); ++i)
      {
        Electron[i].charge	= Electron_charge[i];
        Electron[i].cleanmask	= Electron_cleanmask[i];
        Electron[i].convVeto	= (bool)Electron_convVeto[i];
        Electron[i].cutBased	= Electron_cutBased[i];
        Electron[i].cutBased_HEEP	= (bool)Electron_cutBased_HEEP[i];
        Electron[i].deltaEtaSC	= Electron_deltaEtaSC[i];
        Electron[i].dr03EcalRecHitSumEt	= Electron_dr03EcalRecHitSumEt[i];
        Electron[i].dr03HcalDepth1TowerSumEt	= Electron_dr03HcalDepth1TowerSumEt[i];
        Electron[i].dr03TkSumPt	= Electron_dr03TkSumPt[i];
        Electron[i].dxy	= Electron_dxy[i];
        Electron[i].dxyErr	= Electron_dxyErr[i];
        Electron[i].dz	= Electron_dz[i];
        Electron[i].dzErr	= Electron_dzErr[i];
        Electron[i].eCorr	= Electron_eCorr[i];
        Electron[i].eInvMinusPInv	= Electron_eInvMinusPInv[i];
        Electron[i].energyErr	= Electron_energyErr[i];
        Electron[i].eta	= Electron_eta[i];
        Electron[i].genPartFlav	= Electron_genPartFlav[i];
        Electron[i].genPartIdx	= Electron_genPartIdx[i];
        Electron[i].hoe	= Electron_hoe[i];
        Electron[i].ip3d	= Electron_ip3d[i];
        Electron[i].isPFcand	= (bool)Electron_isPFcand[i];
        Electron[i].jetIdx	= Electron_jetIdx[i];
        Electron[i].lostHits	= Electron_lostHits[i];
        Electron[i].mass	= Electron_mass[i];
        Electron[i].miniPFRelIso_all	= Electron_miniPFRelIso_all[i];
        Electron[i].miniPFRelIso_chg	= Electron_miniPFRelIso_chg[i];
        Electron[i].mvaFall17Iso	= Electron_mvaFall17Iso[i];
        Electron[i].mvaFall17Iso_WP80	= (bool)Electron_mvaFall17Iso_WP80[i];
        Electron[i].mvaFall17Iso_WP90	= (bool)Electron_mvaFall17Iso_WP90[i];
        Electron[i].mvaFall17Iso_WPL	= (bool)Electron_mvaFall17Iso_WPL[i];
        Electron[i].mvaFall17noIso	= Electron_mvaFall17noIso[i];
        Electron[i].mvaFall17noIso_WP80	= (bool)Electron_mvaFall17noIso_WP80[i];
        Electron[i].mvaFall17noIso_WP90	= (bool)Electron_mvaFall17noIso_WP90[i];
        Electron[i].mvaFall17noIso_WPL	= (bool)Electron_mvaFall17noIso_WPL[i];
        Electron[i].mvaTTH	= Electron_mvaTTH[i];
        Electron[i].pdgId	= Electron_pdgId[i];
        Electron[i].pfRelIso03_all	= Electron_pfRelIso03_all[i];
        Electron[i].pfRelIso03_chg	= Electron_pfRelIso03_chg[i];
        Electron[i].phi	= Electron_phi[i];
        Electron[i].photonIdx	= Electron_photonIdx[i];
        Electron[i].pt	= Electron_pt[i];
        Electron[i].r9	= Electron_r9[i];
        Electron[i].sieie	= Electron_sieie[i];
        Electron[i].sip3d	= Electron_sip3d[i];
        Electron[i].tightCharge	= Electron_tightCharge[i];
        Electron[i].vidNestedWPBitmap	= Electron_vidNestedWPBitmap[i];
      }
  }

  void fillFatJets()
  {
    FatJet.resize(FatJet_area.size());
    for(unsigned int i=0; i < FatJet.size(); ++i)
      {
        FatJet[i].area	= FatJet_area[i];
        FatJet[i].btagCMVA	= FatJet_btagCMVA[i];
        FatJet[i].btagCSVV2	= FatJet_btagCSVV2[i];
        FatJet[i].btagDeepB	= FatJet_btagDeepB[i];
        FatJet[i].btagHbb	= FatJet_btagHbb[i];
        FatJet[i].eta	= FatJet_eta[i];
        FatJet[i].jetId	= FatJet_jetId[i];
        FatJet[i].mass	= FatJet_mass[i];
        FatJet[i].msoftdrop	= FatJet_msoftdrop[i];
        FatJet[i].n2b1	= FatJet_n2b1[i];
        FatJet[i].n3b1	= FatJet_n3b1[i];
        FatJet[i].phi	= FatJet_phi[i];
        FatJet[i].pt	= FatJet_pt[i];
        FatJet[i].subJetIdx1	= FatJet_subJetIdx1[i];
        FatJet[i].subJetIdx2	= FatJet_subJetIdx2[i];
        FatJet[i].tau1	= FatJet_tau1[i];
        FatJet[i].tau2	= FatJet_tau2[i];
        FatJet[i].tau3	= FatJet_tau3[i];
        FatJet[i].tau4	= FatJet_tau4[i];
      }
  }

  void fillGenDressedLeptons()
  {
    GenDressedLepton.resize(GenDressedLepton_eta.size());
    for(unsigned int i=0; i < GenDressedLepton.size(); ++i)
      {
        GenDressedLepton[i].eta	= GenDressedLepton_eta[i];
        GenDressedLepton[i].mass	= GenDressedLepton_mass[i];
        GenDressedLepton[i].pdgId	= GenDressedLepton_pdgId[i];
        GenDressedLepton[i].phi	= GenDressedLepton_phi[i];
        GenDressedLepton[i].pt	= GenDressedLepton_pt[i];
      }
  }

  void fillGenJets()
  {
    GenJet.resize(GenJet_eta.size());
    for(unsigned int i=0; i < GenJet.size(); ++i)
      {
        GenJet[i].eta	= GenJet_eta[i];
        GenJet[i].hadronFlavour	= GenJet_hadronFlavour[i];
        GenJet[i].mass	= GenJet_mass[i];
        GenJet[i].partonFlavour	= GenJet_partonFlavour[i];
        GenJet[i].phi	= GenJet_phi[i];
        GenJet[i].pt	= GenJet_pt[i];
      }
  }

  void fillGenJetAK8s()
  {
    GenJetAK8.resize(GenJetAK8_eta.size());
    for(unsigned int i=0; i < GenJetAK8.size(); ++i)
      {
        GenJetAK8[i].eta	= GenJetAK8_eta[i];
        GenJetAK8[i].hadronFlavour	= GenJetAK8_hadronFlavour[i];
        GenJetAK8[i].mass	= GenJetAK8_mass[i];
        GenJetAK8[i].partonFlavour	= GenJetAK8_partonFlavour[i];
        GenJetAK8[i].phi	= GenJetAK8_phi[i];
        GenJetAK8[i].pt	= GenJetAK8_pt[i];
      }
  }

  void fillGenParts()
  {
    GenPart.resize(GenPart_eta.size());
    for(unsigned int i=0; i < GenPart.size(); ++i)
      {
        GenPart[i].eta	= GenPart_eta[i];
        GenPart[i].genPartIdxMother	= GenPart_genPartIdxMother[i];
        GenPart[i].mass	= GenPart_mass[i];
        GenPart[i].pdgId	= GenPart_pdgId[i];
        GenPart[i].phi	= GenPart_phi[i];
        GenPart[i].pt	= GenPart_pt[i];
        GenPart[i].status	= GenPart_status[i];
        GenPart[i].statusFlags	= GenPart_statusFlags[i];
      }
  }

  void fillGenVisTaus()
  {
    GenVisTau.resize(GenVisTau_charge.size());
    for(unsigned int i=0; i < GenVisTau.size(); ++i)
      {
        GenVisTau[i].charge	= GenVisTau_charge[i];
        GenVisTau[i].eta	= GenVisTau_eta[i];
        GenVisTau[i].genPartIdxMother	= GenVisTau_genPartIdxMother[i];
        GenVisTau[i].mass	= GenVisTau_mass[i];
        GenVisTau[i].phi	= GenVisTau_phi[i];
        GenVisTau[i].pt	= GenVisTau_pt[i];
        GenVisTau[i].status	= GenVisTau_status[i];
      }
  }

  void fillIsoTracks()
  {
    IsoTrack.resize(IsoTrack_dxy.size());
    for(unsigned int i=0; i < IsoTrack.size(); ++i)
      {
        IsoTrack[i].dxy	= IsoTrack_dxy[i];
        IsoTrack[i].dz	= IsoTrack_dz[i];
        IsoTrack[i].eta	= IsoTrack_eta[i];
        IsoTrack[i].isHighPurityTrack	= (bool)IsoTrack_isHighPurityTrack[i];
        IsoTrack[i].isPFcand	= (bool)IsoTrack_isPFcand[i];
        IsoTrack[i].miniPFRelIso_all	= IsoTrack_miniPFRelIso_all[i];
        IsoTrack[i].miniPFRelIso_chg	= IsoTrack_miniPFRelIso_chg[i];
        IsoTrack[i].pdgId	= IsoTrack_pdgId[i];
        IsoTrack[i].pfRelIso03_all	= IsoTrack_pfRelIso03_all[i];
        IsoTrack[i].pfRelIso03_chg	= IsoTrack_pfRelIso03_chg[i];
        IsoTrack[i].phi	= IsoTrack_phi[i];
        IsoTrack[i].pt	= IsoTrack_pt[i];
      }
  }

  void fillJets()
  {
    Jet.resize(Jet_area.size());
    for(unsigned int i=0; i < Jet.size(); ++i)
      {
        Jet[i].area	= Jet_area[i];
        Jet[i].bReg	= Jet_bReg[i];
        Jet[i].btagCMVA	= Jet_btagCMVA[i];
        Jet[i].btagCSVV2	= Jet_btagCSVV2[i];
        Jet[i].btagDeepB	= Jet_btagDeepB[i];
        Jet[i].btagDeepC	= Jet_btagDeepC[i];
        Jet[i].btagDeepFlavB	= Jet_btagDeepFlavB[i];
        Jet[i].chEmEF	= Jet_chEmEF[i];
        Jet[i].chHEF	= Jet_chHEF[i];
        Jet[i].cleanmask	= Jet_cleanmask[i];
        Jet[i].electronIdx1	= Jet_electronIdx1[i];
        Jet[i].electronIdx2	= Jet_electronIdx2[i];
        Jet[i].eta	= Jet_eta[i];
        Jet[i].genJetIdx	= Jet_genJetIdx[i];
        Jet[i].hadronFlavour	= Jet_hadronFlavour[i];
        Jet[i].jetId	= Jet_jetId[i];
        Jet[i].mass	= Jet_mass[i];
        Jet[i].muonIdx1	= Jet_muonIdx1[i];
        Jet[i].muonIdx2	= Jet_muonIdx2[i];
        Jet[i].nConstituents	= Jet_nConstituents[i];
        Jet[i].nElectrons	= Jet_nElectrons[i];
        Jet[i].nMuons	= Jet_nMuons[i];
        Jet[i].neEmEF	= Jet_neEmEF[i];
        Jet[i].neHEF	= Jet_neHEF[i];
        Jet[i].partonFlavour	= Jet_partonFlavour[i];
        Jet[i].phi	= Jet_phi[i];
        Jet[i].pt	= Jet_pt[i];
        Jet[i].puId	= Jet_puId[i];
        Jet[i].qgl	= Jet_qgl[i];
        Jet[i].rawFactor	= Jet_rawFactor[i];
      }
  }

  void fillLHEParts()
  {
    LHEPart.resize(LHEPart_eta.size());
    for(unsigned int i=0; i < LHEPart.size(); ++i)
      {
        LHEPart[i].eta	= LHEPart_eta[i];
        LHEPart[i].mass	= LHEPart_mass[i];
        LHEPart[i].pdgId	= LHEPart_pdgId[i];
        LHEPart[i].phi	= LHEPart_phi[i];
        LHEPart[i].pt	= LHEPart_pt[i];
      }
  }

  void fillMuons()
  {
    Muon.resize(Muon_charge.size());
    for(unsigned int i=0; i < Muon.size(); ++i)
      {
        Muon[i].charge	= Muon_charge[i];
        Muon[i].cleanmask	= Muon_cleanmask[i];
        Muon[i].dxy	= Muon_dxy[i];
        Muon[i].dxyErr	= Muon_dxyErr[i];
        Muon[i].dz	= Muon_dz[i];
        Muon[i].dzErr	= Muon_dzErr[i];
        Muon[i].eta	= Muon_eta[i];
        Muon[i].genPartFlav	= Muon_genPartFlav[i];
        Muon[i].genPartIdx	= Muon_genPartIdx[i];
        Muon[i].highPtId	= Muon_highPtId[i];
        Muon[i].ip3d	= Muon_ip3d[i];
        Muon[i].isPFcand	= (bool)Muon_isPFcand[i];
        Muon[i].jetIdx	= Muon_jetIdx[i];
        Muon[i].mass	= Muon_mass[i];
        Muon[i].mediumId	= (bool)Muon_mediumId[i];
        Muon[i].miniPFRelIso_all	= Muon_miniPFRelIso_all[i];
        Muon[i].miniPFRelIso_chg	= Muon_miniPFRelIso_chg[i];
        Muon[i].mvaTTH	= Muon_mvaTTH[i];
        Muon[i].nStations	= Muon_nStations[i];
        Muon[i].nTrackerLayers	= Muon_nTrackerLayers[i];
        Muon[i].pdgId	= Muon_pdgId[i];
        Muon[i].pfRelIso03_all	= Muon_pfRelIso03_all[i];
        Muon[i].pfRelIso03_chg	= Muon_pfRelIso03_chg[i];
        Muon[i].pfRelIso04_all	= Muon_pfRelIso04_all[i];
        Muon[i].phi	= Muon_phi[i];
        Muon[i].pt	= Muon_pt[i];
        Muon[i].ptErr	= Muon_ptErr[i];
        Muon[i].segmentComp	= Muon_segmentComp[i];
        Muon[i].sip3d	= Muon_sip3d[i];
        Muon[i].softId	= (bool)Muon_softId[i];
        Muon[i].tightCharge	= Muon_tightCharge[i];
        Muon[i].tightId	= (bool)Muon_tightId[i];
      }
  }

  void fillPhotons()
  {
    Photon.resize(Photon_charge.size());
    for(unsigned int i=0; i < Photon.size(); ++i)
      {
        Photon[i].charge	= Photon_charge[i];
        Photon[i].cleanmask	= Photon_cleanmask[i];
        Photon[i].cutBasedBitmap	= Photon_cutBasedBitmap[i];
        Photon[i].eCorr	= Photon_eCorr[i];
        Photon[i].electronIdx	= Photon_electronIdx[i];
        Photon[i].electronVeto	= (bool)Photon_electronVeto[i];
        Photon[i].energyErr	= Photon_energyErr[i];
        Photon[i].eta	= Photon_eta[i];
        Photon[i].genPartFlav	= Photon_genPartFlav[i];
        Photon[i].genPartIdx	= Photon_genPartIdx[i];
        Photon[i].hoe	= Photon_hoe[i];
        Photon[i].isScEtaEB	= (bool)Photon_isScEtaEB[i];
        Photon[i].isScEtaEE	= (bool)Photon_isScEtaEE[i];
        Photon[i].jetIdx	= Photon_jetIdx[i];
        Photon[i].mass	= Photon_mass[i];
        Photon[i].mvaID	= Photon_mvaID[i];
        Photon[i].mvaID_WP80	= (bool)Photon_mvaID_WP80[i];
        Photon[i].mvaID_WP90	= (bool)Photon_mvaID_WP90[i];
        Photon[i].pdgId	= Photon_pdgId[i];
        Photon[i].pfRelIso03_all	= Photon_pfRelIso03_all[i];
        Photon[i].pfRelIso03_chg	= Photon_pfRelIso03_chg[i];
        Photon[i].phi	= Photon_phi[i];
        Photon[i].pixelSeed	= (bool)Photon_pixelSeed[i];
        Photon[i].pt	= Photon_pt[i];
        Photon[i].r9	= Photon_r9[i];
        Photon[i].sieie	= Photon_sieie[i];
        Photon[i].vidNestedWPBitmap	= Photon_vidNestedWPBitmap[i];
      }
  }

  void fillSVs()
  {
    SV.resize(SV_chi2.size());
    for(unsigned int i=0; i < SV.size(); ++i)
      {
        SV[i].chi2	= SV_chi2[i];
        SV[i].dlen	= SV_dlen[i];
        SV[i].dlenSig	= SV_dlenSig[i];
        SV[i].eta	= SV_eta[i];
        SV[i].mass	= SV_mass[i];
        SV[i].ndof	= SV_ndof[i];
        SV[i].pAngle	= SV_pAngle[i];
        SV[i].phi	= SV_phi[i];
        SV[i].pt	= SV_pt[i];
        SV[i].x	= SV_x[i];
        SV[i].y	= SV_y[i];
        SV[i].z	= SV_z[i];
      }
  }

  void fillSoftActivityJets()
  {
    SoftActivityJet.resize(SoftActivityJet_eta.size());
    for(unsigned int i=0; i < SoftActivityJet.size(); ++i)
      {
        SoftActivityJet[i].eta	= SoftActivityJet_eta[i];
        SoftActivityJet[i].phi	= SoftActivityJet_phi[i];
        SoftActivityJet[i].pt	= SoftActivityJet_pt[i];
      }
  }

  void fillSubGenJetAK8s()
  {
    SubGenJetAK8.resize(SubGenJetAK8_eta.size());
    for(unsigned int i=0; i < SubGenJetAK8.size(); ++i)
      {
        SubGenJetAK8[i].eta	= SubGenJetAK8_eta[i];
        SubGenJetAK8[i].mass	= SubGenJetAK8_mass[i];
        SubGenJetAK8[i].phi	= SubGenJetAK8_phi[i];
        SubGenJetAK8[i].pt	= SubGenJetAK8_pt[i];
      }
  }

  void fillSubJets()
  {
    SubJet.resize(SubJet_btagCMVA.size());
    for(unsigned int i=0; i < SubJet.size(); ++i)
      {
        SubJet[i].btagCMVA	= SubJet_btagCMVA[i];
        SubJet[i].btagCSVV2	= SubJet_btagCSVV2[i];
        SubJet[i].btagDeepB	= SubJet_btagDeepB[i];
        SubJet[i].eta	= SubJet_eta[i];
        SubJet[i].mass	= SubJet_mass[i];
        SubJet[i].n2b1	= SubJet_n2b1[i];
        SubJet[i].n3b1	= SubJet_n3b1[i];
        SubJet[i].phi	= SubJet_phi[i];
        SubJet[i].pt	= SubJet_pt[i];
        SubJet[i].tau1	= SubJet_tau1[i];
        SubJet[i].tau2	= SubJet_tau2[i];
        SubJet[i].tau3	= SubJet_tau3[i];
        SubJet[i].tau4	= SubJet_tau4[i];
      }
  }

  void fillTaus()
  {
    Tau.resize(Tau_charge.size());
    for(unsigned int i=0; i < Tau.size(); ++i)
      {
        Tau[i].charge	= Tau_charge[i];
        Tau[i].chargedIso	= Tau_chargedIso[i];
        Tau[i].cleanmask	= Tau_cleanmask[i];
        Tau[i].decayMode	= Tau_decayMode[i];
        Tau[i].dxy	= Tau_dxy[i];
        Tau[i].dz	= Tau_dz[i];
        Tau[i].eta	= Tau_eta[i];
        Tau[i].genPartFlav	= Tau_genPartFlav[i];
        Tau[i].genPartIdx	= Tau_genPartIdx[i];
        Tau[i].idAntiEle	= Tau_idAntiEle[i];
        Tau[i].idAntiMu	= Tau_idAntiMu[i];
        Tau[i].idDecayMode	= (bool)Tau_idDecayMode[i];
        Tau[i].idDecayModeNewDMs	= (bool)Tau_idDecayModeNewDMs[i];
        Tau[i].idMVAnewDM2017v2	= Tau_idMVAnewDM2017v2[i];
        Tau[i].idMVAoldDM	= Tau_idMVAoldDM[i];
        Tau[i].idMVAoldDM2017v1	= Tau_idMVAoldDM2017v1[i];
        Tau[i].idMVAoldDM2017v2	= Tau_idMVAoldDM2017v2[i];
        Tau[i].idMVAoldDMdR032017v2	= Tau_idMVAoldDMdR032017v2[i];
        Tau[i].jetIdx	= Tau_jetIdx[i];
        Tau[i].leadTkDeltaEta	= Tau_leadTkDeltaEta[i];
        Tau[i].leadTkDeltaPhi	= Tau_leadTkDeltaPhi[i];
        Tau[i].leadTkPtOverTauPt	= Tau_leadTkPtOverTauPt[i];
        Tau[i].mass	= Tau_mass[i];
        Tau[i].neutralIso	= Tau_neutralIso[i];
        Tau[i].phi	= Tau_phi[i];
        Tau[i].photonsOutsideSignalCone	= Tau_photonsOutsideSignalCone[i];
        Tau[i].pt	= Tau_pt[i];
        Tau[i].puCorr	= Tau_puCorr[i];
        Tau[i].rawAntiEle	= Tau_rawAntiEle[i];
        Tau[i].rawAntiEleCat	= Tau_rawAntiEleCat[i];
        Tau[i].rawIso	= Tau_rawIso[i];
        Tau[i].rawIsodR03	= Tau_rawIsodR03[i];
        Tau[i].rawMVAnewDM2017v2	= Tau_rawMVAnewDM2017v2[i];
        Tau[i].rawMVAoldDM	= Tau_rawMVAoldDM[i];
        Tau[i].rawMVAoldDM2017v1	= Tau_rawMVAoldDM2017v1[i];
        Tau[i].rawMVAoldDM2017v2	= Tau_rawMVAoldDM2017v2[i];
        Tau[i].rawMVAoldDMdR032017v2	= Tau_rawMVAoldDMdR032017v2[i];
      }
  }

  void fillTrigObjs()
  {
    TrigObj.resize(TrigObj_eta.size());
    for(unsigned int i=0; i < TrigObj.size(); ++i)
      {
        TrigObj[i].eta	= TrigObj_eta[i];
        TrigObj[i].filterBits	= TrigObj_filterBits[i];
        TrigObj[i].id	= TrigObj_id[i];
        TrigObj[i].l1charge	= TrigObj_l1charge[i];
        TrigObj[i].l1iso	= TrigObj_l1iso[i];
        TrigObj[i].l1pt	= TrigObj_l1pt[i];
        TrigObj[i].l1pt_2	= TrigObj_l1pt_2[i];
        TrigObj[i].l2pt	= TrigObj_l2pt[i];
        TrigObj[i].phi	= TrigObj_phi[i];
        TrigObj[i].pt	= TrigObj_pt[i];
      }
  }


  std::vector<eventBuffer::Electron_s> Electron;
  std::vector<eventBuffer::FatJet_s> FatJet;
  std::vector<eventBuffer::GenDressedLepton_s> GenDressedLepton;
  std::vector<eventBuffer::GenJet_s> GenJet;
  std::vector<eventBuffer::GenJetAK8_s> GenJetAK8;
  std::vector<eventBuffer::GenPart_s> GenPart;
  std::vector<eventBuffer::GenVisTau_s> GenVisTau;
  std::vector<eventBuffer::IsoTrack_s> IsoTrack;
  std::vector<eventBuffer::Jet_s> Jet;
  std::vector<eventBuffer::LHEPart_s> LHEPart;
  std::vector<eventBuffer::Muon_s> Muon;
  std::vector<eventBuffer::Photon_s> Photon;
  std::vector<eventBuffer::SV_s> SV;
  std::vector<eventBuffer::SoftActivityJet_s> SoftActivityJet;
  std::vector<eventBuffer::SubGenJetAK8_s> SubGenJetAK8;
  std::vector<eventBuffer::SubJet_s> SubJet;
  std::vector<eventBuffer::Tau_s> Tau;
  std::vector<eventBuffer::TrigObj_s> TrigObj;

  void fillObjects()
  {
    fillElectrons();
    fillFatJets();
    fillGenDressedLeptons();
    fillGenJets();
    fillGenJetAK8s();
    fillGenParts();
    fillGenVisTaus();
    fillIsoTracks();
    fillJets();
    fillLHEParts();
    fillMuons();
    fillPhotons();
    fillSVs();
    fillSoftActivityJets();
    fillSubGenJetAK8s();
    fillSubJets();
    fillTaus();
    fillTrigObjs();
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
            Electron_charge[i]	= Electron_charge[j];
            Electron_cleanmask[i]	= Electron_cleanmask[j];
            Electron_convVeto[i]	= Electron_convVeto[j];
            Electron_cutBased[i]	= Electron_cutBased[j];
            Electron_cutBased_HEEP[i]	= Electron_cutBased_HEEP[j];
            Electron_deltaEtaSC[i]	= Electron_deltaEtaSC[j];
            Electron_dr03EcalRecHitSumEt[i]	= Electron_dr03EcalRecHitSumEt[j];
            Electron_dr03HcalDepth1TowerSumEt[i]	= Electron_dr03HcalDepth1TowerSumEt[j];
            Electron_dr03TkSumPt[i]	= Electron_dr03TkSumPt[j];
            Electron_dxy[i]	= Electron_dxy[j];
            Electron_dxyErr[i]	= Electron_dxyErr[j];
            Electron_dz[i]	= Electron_dz[j];
            Electron_dzErr[i]	= Electron_dzErr[j];
            Electron_eCorr[i]	= Electron_eCorr[j];
            Electron_eInvMinusPInv[i]	= Electron_eInvMinusPInv[j];
            Electron_energyErr[i]	= Electron_energyErr[j];
            Electron_eta[i]	= Electron_eta[j];
            Electron_genPartFlav[i]	= Electron_genPartFlav[j];
            Electron_genPartIdx[i]	= Electron_genPartIdx[j];
            Electron_hoe[i]	= Electron_hoe[j];
            Electron_ip3d[i]	= Electron_ip3d[j];
            Electron_isPFcand[i]	= Electron_isPFcand[j];
            Electron_jetIdx[i]	= Electron_jetIdx[j];
            Electron_lostHits[i]	= Electron_lostHits[j];
            Electron_mass[i]	= Electron_mass[j];
            Electron_miniPFRelIso_all[i]	= Electron_miniPFRelIso_all[j];
            Electron_miniPFRelIso_chg[i]	= Electron_miniPFRelIso_chg[j];
            Electron_mvaFall17Iso[i]	= Electron_mvaFall17Iso[j];
            Electron_mvaFall17Iso_WP80[i]	= Electron_mvaFall17Iso_WP80[j];
            Electron_mvaFall17Iso_WP90[i]	= Electron_mvaFall17Iso_WP90[j];
            Electron_mvaFall17Iso_WPL[i]	= Electron_mvaFall17Iso_WPL[j];
            Electron_mvaFall17noIso[i]	= Electron_mvaFall17noIso[j];
            Electron_mvaFall17noIso_WP80[i]	= Electron_mvaFall17noIso_WP80[j];
            Electron_mvaFall17noIso_WP90[i]	= Electron_mvaFall17noIso_WP90[j];
            Electron_mvaFall17noIso_WPL[i]	= Electron_mvaFall17noIso_WPL[j];
            Electron_mvaTTH[i]	= Electron_mvaTTH[j];
            Electron_pdgId[i]	= Electron_pdgId[j];
            Electron_pfRelIso03_all[i]	= Electron_pfRelIso03_all[j];
            Electron_pfRelIso03_chg[i]	= Electron_pfRelIso03_chg[j];
            Electron_phi[i]	= Electron_phi[j];
            Electron_photonIdx[i]	= Electron_photonIdx[j];
            Electron_pt[i]	= Electron_pt[j];
            Electron_r9[i]	= Electron_r9[j];
            Electron_sieie[i]	= Electron_sieie[j];
            Electron_sip3d[i]	= Electron_sip3d[j];
            Electron_tightCharge[i]	= Electron_tightCharge[j];
            Electron_vidNestedWPBitmap[i]	= Electron_vidNestedWPBitmap[j];
          }
      }
    nElectron = n;

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
            FatJet_area[i]	= FatJet_area[j];
            FatJet_btagCMVA[i]	= FatJet_btagCMVA[j];
            FatJet_btagCSVV2[i]	= FatJet_btagCSVV2[j];
            FatJet_btagDeepB[i]	= FatJet_btagDeepB[j];
            FatJet_btagHbb[i]	= FatJet_btagHbb[j];
            FatJet_eta[i]	= FatJet_eta[j];
            FatJet_jetId[i]	= FatJet_jetId[j];
            FatJet_mass[i]	= FatJet_mass[j];
            FatJet_msoftdrop[i]	= FatJet_msoftdrop[j];
            FatJet_n2b1[i]	= FatJet_n2b1[j];
            FatJet_n3b1[i]	= FatJet_n3b1[j];
            FatJet_phi[i]	= FatJet_phi[j];
            FatJet_pt[i]	= FatJet_pt[j];
            FatJet_subJetIdx1[i]	= FatJet_subJetIdx1[j];
            FatJet_subJetIdx2[i]	= FatJet_subJetIdx2[j];
            FatJet_tau1[i]	= FatJet_tau1[j];
            FatJet_tau2[i]	= FatJet_tau2[j];
            FatJet_tau3[i]	= FatJet_tau3[j];
            FatJet_tau4[i]	= FatJet_tau4[j];
          }
      }
    nFatJet = n;

    n = 0;
    try
      {
         n = indexmap["GenDressedLepton"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["GenDressedLepton"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            GenDressedLepton_eta[i]	= GenDressedLepton_eta[j];
            GenDressedLepton_mass[i]	= GenDressedLepton_mass[j];
            GenDressedLepton_pdgId[i]	= GenDressedLepton_pdgId[j];
            GenDressedLepton_phi[i]	= GenDressedLepton_phi[j];
            GenDressedLepton_pt[i]	= GenDressedLepton_pt[j];
          }
      }
    nGenDressedLepton = n;

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
            GenJet_eta[i]	= GenJet_eta[j];
            GenJet_hadronFlavour[i]	= GenJet_hadronFlavour[j];
            GenJet_mass[i]	= GenJet_mass[j];
            GenJet_partonFlavour[i]	= GenJet_partonFlavour[j];
            GenJet_phi[i]	= GenJet_phi[j];
            GenJet_pt[i]	= GenJet_pt[j];
          }
      }
    nGenJet = n;

    n = 0;
    try
      {
         n = indexmap["GenJetAK8"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["GenJetAK8"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            GenJetAK8_eta[i]	= GenJetAK8_eta[j];
            GenJetAK8_hadronFlavour[i]	= GenJetAK8_hadronFlavour[j];
            GenJetAK8_mass[i]	= GenJetAK8_mass[j];
            GenJetAK8_partonFlavour[i]	= GenJetAK8_partonFlavour[j];
            GenJetAK8_phi[i]	= GenJetAK8_phi[j];
            GenJetAK8_pt[i]	= GenJetAK8_pt[j];
          }
      }
    nGenJetAK8 = n;

    n = 0;
    try
      {
         n = indexmap["GenPart"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["GenPart"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            GenPart_eta[i]	= GenPart_eta[j];
            GenPart_genPartIdxMother[i]	= GenPart_genPartIdxMother[j];
            GenPart_mass[i]	= GenPart_mass[j];
            GenPart_pdgId[i]	= GenPart_pdgId[j];
            GenPart_phi[i]	= GenPart_phi[j];
            GenPart_pt[i]	= GenPart_pt[j];
            GenPart_status[i]	= GenPart_status[j];
            GenPart_statusFlags[i]	= GenPart_statusFlags[j];
          }
      }
    nGenPart = n;

    n = 0;
    try
      {
         n = indexmap["GenVisTau"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["GenVisTau"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            GenVisTau_charge[i]	= GenVisTau_charge[j];
            GenVisTau_eta[i]	= GenVisTau_eta[j];
            GenVisTau_genPartIdxMother[i]	= GenVisTau_genPartIdxMother[j];
            GenVisTau_mass[i]	= GenVisTau_mass[j];
            GenVisTau_phi[i]	= GenVisTau_phi[j];
            GenVisTau_pt[i]	= GenVisTau_pt[j];
            GenVisTau_status[i]	= GenVisTau_status[j];
          }
      }
    nGenVisTau = n;

    n = 0;
    try
      {
         n = indexmap["IsoTrack"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["IsoTrack"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            IsoTrack_dxy[i]	= IsoTrack_dxy[j];
            IsoTrack_dz[i]	= IsoTrack_dz[j];
            IsoTrack_eta[i]	= IsoTrack_eta[j];
            IsoTrack_isHighPurityTrack[i]	= IsoTrack_isHighPurityTrack[j];
            IsoTrack_isPFcand[i]	= IsoTrack_isPFcand[j];
            IsoTrack_miniPFRelIso_all[i]	= IsoTrack_miniPFRelIso_all[j];
            IsoTrack_miniPFRelIso_chg[i]	= IsoTrack_miniPFRelIso_chg[j];
            IsoTrack_pdgId[i]	= IsoTrack_pdgId[j];
            IsoTrack_pfRelIso03_all[i]	= IsoTrack_pfRelIso03_all[j];
            IsoTrack_pfRelIso03_chg[i]	= IsoTrack_pfRelIso03_chg[j];
            IsoTrack_phi[i]	= IsoTrack_phi[j];
            IsoTrack_pt[i]	= IsoTrack_pt[j];
          }
      }
    nIsoTrack = n;

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
            Jet_area[i]	= Jet_area[j];
            Jet_bReg[i]	= Jet_bReg[j];
            Jet_btagCMVA[i]	= Jet_btagCMVA[j];
            Jet_btagCSVV2[i]	= Jet_btagCSVV2[j];
            Jet_btagDeepB[i]	= Jet_btagDeepB[j];
            Jet_btagDeepC[i]	= Jet_btagDeepC[j];
            Jet_btagDeepFlavB[i]	= Jet_btagDeepFlavB[j];
            Jet_chEmEF[i]	= Jet_chEmEF[j];
            Jet_chHEF[i]	= Jet_chHEF[j];
            Jet_cleanmask[i]	= Jet_cleanmask[j];
            Jet_electronIdx1[i]	= Jet_electronIdx1[j];
            Jet_electronIdx2[i]	= Jet_electronIdx2[j];
            Jet_eta[i]	= Jet_eta[j];
            Jet_genJetIdx[i]	= Jet_genJetIdx[j];
            Jet_hadronFlavour[i]	= Jet_hadronFlavour[j];
            Jet_jetId[i]	= Jet_jetId[j];
            Jet_mass[i]	= Jet_mass[j];
            Jet_muonIdx1[i]	= Jet_muonIdx1[j];
            Jet_muonIdx2[i]	= Jet_muonIdx2[j];
            Jet_nConstituents[i]	= Jet_nConstituents[j];
            Jet_nElectrons[i]	= Jet_nElectrons[j];
            Jet_nMuons[i]	= Jet_nMuons[j];
            Jet_neEmEF[i]	= Jet_neEmEF[j];
            Jet_neHEF[i]	= Jet_neHEF[j];
            Jet_partonFlavour[i]	= Jet_partonFlavour[j];
            Jet_phi[i]	= Jet_phi[j];
            Jet_pt[i]	= Jet_pt[j];
            Jet_puId[i]	= Jet_puId[j];
            Jet_qgl[i]	= Jet_qgl[j];
            Jet_rawFactor[i]	= Jet_rawFactor[j];
          }
      }
    nJet = n;

    n = 0;
    try
      {
         n = indexmap["LHEPart"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["LHEPart"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            LHEPart_eta[i]	= LHEPart_eta[j];
            LHEPart_mass[i]	= LHEPart_mass[j];
            LHEPart_pdgId[i]	= LHEPart_pdgId[j];
            LHEPart_phi[i]	= LHEPart_phi[j];
            LHEPart_pt[i]	= LHEPart_pt[j];
          }
      }
    nLHEPart = n;

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
            Muon_charge[i]	= Muon_charge[j];
            Muon_cleanmask[i]	= Muon_cleanmask[j];
            Muon_dxy[i]	= Muon_dxy[j];
            Muon_dxyErr[i]	= Muon_dxyErr[j];
            Muon_dz[i]	= Muon_dz[j];
            Muon_dzErr[i]	= Muon_dzErr[j];
            Muon_eta[i]	= Muon_eta[j];
            Muon_genPartFlav[i]	= Muon_genPartFlav[j];
            Muon_genPartIdx[i]	= Muon_genPartIdx[j];
            Muon_highPtId[i]	= Muon_highPtId[j];
            Muon_ip3d[i]	= Muon_ip3d[j];
            Muon_isPFcand[i]	= Muon_isPFcand[j];
            Muon_jetIdx[i]	= Muon_jetIdx[j];
            Muon_mass[i]	= Muon_mass[j];
            Muon_mediumId[i]	= Muon_mediumId[j];
            Muon_miniPFRelIso_all[i]	= Muon_miniPFRelIso_all[j];
            Muon_miniPFRelIso_chg[i]	= Muon_miniPFRelIso_chg[j];
            Muon_mvaTTH[i]	= Muon_mvaTTH[j];
            Muon_nStations[i]	= Muon_nStations[j];
            Muon_nTrackerLayers[i]	= Muon_nTrackerLayers[j];
            Muon_pdgId[i]	= Muon_pdgId[j];
            Muon_pfRelIso03_all[i]	= Muon_pfRelIso03_all[j];
            Muon_pfRelIso03_chg[i]	= Muon_pfRelIso03_chg[j];
            Muon_pfRelIso04_all[i]	= Muon_pfRelIso04_all[j];
            Muon_phi[i]	= Muon_phi[j];
            Muon_pt[i]	= Muon_pt[j];
            Muon_ptErr[i]	= Muon_ptErr[j];
            Muon_segmentComp[i]	= Muon_segmentComp[j];
            Muon_sip3d[i]	= Muon_sip3d[j];
            Muon_softId[i]	= Muon_softId[j];
            Muon_tightCharge[i]	= Muon_tightCharge[j];
            Muon_tightId[i]	= Muon_tightId[j];
          }
      }
    nMuon = n;

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
            Photon_charge[i]	= Photon_charge[j];
            Photon_cleanmask[i]	= Photon_cleanmask[j];
            Photon_cutBasedBitmap[i]	= Photon_cutBasedBitmap[j];
            Photon_eCorr[i]	= Photon_eCorr[j];
            Photon_electronIdx[i]	= Photon_electronIdx[j];
            Photon_electronVeto[i]	= Photon_electronVeto[j];
            Photon_energyErr[i]	= Photon_energyErr[j];
            Photon_eta[i]	= Photon_eta[j];
            Photon_genPartFlav[i]	= Photon_genPartFlav[j];
            Photon_genPartIdx[i]	= Photon_genPartIdx[j];
            Photon_hoe[i]	= Photon_hoe[j];
            Photon_isScEtaEB[i]	= Photon_isScEtaEB[j];
            Photon_isScEtaEE[i]	= Photon_isScEtaEE[j];
            Photon_jetIdx[i]	= Photon_jetIdx[j];
            Photon_mass[i]	= Photon_mass[j];
            Photon_mvaID[i]	= Photon_mvaID[j];
            Photon_mvaID_WP80[i]	= Photon_mvaID_WP80[j];
            Photon_mvaID_WP90[i]	= Photon_mvaID_WP90[j];
            Photon_pdgId[i]	= Photon_pdgId[j];
            Photon_pfRelIso03_all[i]	= Photon_pfRelIso03_all[j];
            Photon_pfRelIso03_chg[i]	= Photon_pfRelIso03_chg[j];
            Photon_phi[i]	= Photon_phi[j];
            Photon_pixelSeed[i]	= Photon_pixelSeed[j];
            Photon_pt[i]	= Photon_pt[j];
            Photon_r9[i]	= Photon_r9[j];
            Photon_sieie[i]	= Photon_sieie[j];
            Photon_vidNestedWPBitmap[i]	= Photon_vidNestedWPBitmap[j];
          }
      }
    nPhoton = n;

    n = 0;
    try
      {
         n = indexmap["SV"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["SV"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            SV_chi2[i]	= SV_chi2[j];
            SV_dlen[i]	= SV_dlen[j];
            SV_dlenSig[i]	= SV_dlenSig[j];
            SV_eta[i]	= SV_eta[j];
            SV_mass[i]	= SV_mass[j];
            SV_ndof[i]	= SV_ndof[j];
            SV_pAngle[i]	= SV_pAngle[j];
            SV_phi[i]	= SV_phi[j];
            SV_pt[i]	= SV_pt[j];
            SV_x[i]	= SV_x[j];
            SV_y[i]	= SV_y[j];
            SV_z[i]	= SV_z[j];
          }
      }
    nSV = n;

    n = 0;
    try
      {
         n = indexmap["SoftActivityJet"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["SoftActivityJet"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            SoftActivityJet_eta[i]	= SoftActivityJet_eta[j];
            SoftActivityJet_phi[i]	= SoftActivityJet_phi[j];
            SoftActivityJet_pt[i]	= SoftActivityJet_pt[j];
          }
      }
    nSoftActivityJet = n;

    n = 0;
    try
      {
         n = indexmap["SubGenJetAK8"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["SubGenJetAK8"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            SubGenJetAK8_eta[i]	= SubGenJetAK8_eta[j];
            SubGenJetAK8_mass[i]	= SubGenJetAK8_mass[j];
            SubGenJetAK8_phi[i]	= SubGenJetAK8_phi[j];
            SubGenJetAK8_pt[i]	= SubGenJetAK8_pt[j];
          }
      }
    nSubGenJetAK8 = n;

    n = 0;
    try
      {
         n = indexmap["SubJet"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["SubJet"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            SubJet_btagCMVA[i]	= SubJet_btagCMVA[j];
            SubJet_btagCSVV2[i]	= SubJet_btagCSVV2[j];
            SubJet_btagDeepB[i]	= SubJet_btagDeepB[j];
            SubJet_eta[i]	= SubJet_eta[j];
            SubJet_mass[i]	= SubJet_mass[j];
            SubJet_n2b1[i]	= SubJet_n2b1[j];
            SubJet_n3b1[i]	= SubJet_n3b1[j];
            SubJet_phi[i]	= SubJet_phi[j];
            SubJet_pt[i]	= SubJet_pt[j];
            SubJet_tau1[i]	= SubJet_tau1[j];
            SubJet_tau2[i]	= SubJet_tau2[j];
            SubJet_tau3[i]	= SubJet_tau3[j];
            SubJet_tau4[i]	= SubJet_tau4[j];
          }
      }
    nSubJet = n;

    n = 0;
    try
      {
         n = indexmap["Tau"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["Tau"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            Tau_charge[i]	= Tau_charge[j];
            Tau_chargedIso[i]	= Tau_chargedIso[j];
            Tau_cleanmask[i]	= Tau_cleanmask[j];
            Tau_decayMode[i]	= Tau_decayMode[j];
            Tau_dxy[i]	= Tau_dxy[j];
            Tau_dz[i]	= Tau_dz[j];
            Tau_eta[i]	= Tau_eta[j];
            Tau_genPartFlav[i]	= Tau_genPartFlav[j];
            Tau_genPartIdx[i]	= Tau_genPartIdx[j];
            Tau_idAntiEle[i]	= Tau_idAntiEle[j];
            Tau_idAntiMu[i]	= Tau_idAntiMu[j];
            Tau_idDecayMode[i]	= Tau_idDecayMode[j];
            Tau_idDecayModeNewDMs[i]	= Tau_idDecayModeNewDMs[j];
            Tau_idMVAnewDM2017v2[i]	= Tau_idMVAnewDM2017v2[j];
            Tau_idMVAoldDM[i]	= Tau_idMVAoldDM[j];
            Tau_idMVAoldDM2017v1[i]	= Tau_idMVAoldDM2017v1[j];
            Tau_idMVAoldDM2017v2[i]	= Tau_idMVAoldDM2017v2[j];
            Tau_idMVAoldDMdR032017v2[i]	= Tau_idMVAoldDMdR032017v2[j];
            Tau_jetIdx[i]	= Tau_jetIdx[j];
            Tau_leadTkDeltaEta[i]	= Tau_leadTkDeltaEta[j];
            Tau_leadTkDeltaPhi[i]	= Tau_leadTkDeltaPhi[j];
            Tau_leadTkPtOverTauPt[i]	= Tau_leadTkPtOverTauPt[j];
            Tau_mass[i]	= Tau_mass[j];
            Tau_neutralIso[i]	= Tau_neutralIso[j];
            Tau_phi[i]	= Tau_phi[j];
            Tau_photonsOutsideSignalCone[i]	= Tau_photonsOutsideSignalCone[j];
            Tau_pt[i]	= Tau_pt[j];
            Tau_puCorr[i]	= Tau_puCorr[j];
            Tau_rawAntiEle[i]	= Tau_rawAntiEle[j];
            Tau_rawAntiEleCat[i]	= Tau_rawAntiEleCat[j];
            Tau_rawIso[i]	= Tau_rawIso[j];
            Tau_rawIsodR03[i]	= Tau_rawIsodR03[j];
            Tau_rawMVAnewDM2017v2[i]	= Tau_rawMVAnewDM2017v2[j];
            Tau_rawMVAoldDM[i]	= Tau_rawMVAoldDM[j];
            Tau_rawMVAoldDM2017v1[i]	= Tau_rawMVAoldDM2017v1[j];
            Tau_rawMVAoldDM2017v2[i]	= Tau_rawMVAoldDM2017v2[j];
            Tau_rawMVAoldDMdR032017v2[i]	= Tau_rawMVAoldDMdR032017v2[j];
          }
      }
    nTau = n;

    n = 0;
    try
      {
         n = indexmap["TrigObj"].size();
      }
    catch (...)
      {}
    if ( n > 0 )
      {
        std::vector<int>& index = indexmap["TrigObj"];
        for(int i=0; i < n; ++i)
          {
            int j = index[i];
            TrigObj_eta[i]	= TrigObj_eta[j];
            TrigObj_filterBits[i]	= TrigObj_filterBits[j];
            TrigObj_id[i]	= TrigObj_id[j];
            TrigObj_l1charge[i]	= TrigObj_l1charge[j];
            TrigObj_l1iso[i]	= TrigObj_l1iso[j];
            TrigObj_l1pt[i]	= TrigObj_l1pt[j];
            TrigObj_l1pt_2[i]	= TrigObj_l1pt_2[j];
            TrigObj_l2pt[i]	= TrigObj_l2pt[j];
            TrigObj_phi[i]	= TrigObj_phi[j];
            TrigObj_pt[i]	= TrigObj_pt[j];
          }
      }
    nTrigObj = n;
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
    choose["Events/CaloMET_phi"]	= DEFAULT;
    choose["Events/CaloMET_pt"]	= DEFAULT;
    choose["Events/CaloMET_sumEt"]	= DEFAULT;
    choose["Events/Electron_charge"]	= DEFAULT;
    choose["Events/Electron_cleanmask"]	= DEFAULT;
    choose["Events/Electron_convVeto"]	= DEFAULT;
    choose["Events/Electron_cutBased"]	= DEFAULT;
    choose["Events/Electron_cutBased_HEEP"]	= DEFAULT;
    choose["Events/Electron_deltaEtaSC"]	= DEFAULT;
    choose["Events/Electron_dr03EcalRecHitSumEt"]	= DEFAULT;
    choose["Events/Electron_dr03HcalDepth1TowerSumEt"]	= DEFAULT;
    choose["Events/Electron_dr03TkSumPt"]	= DEFAULT;
    choose["Events/Electron_dxy"]	= DEFAULT;
    choose["Events/Electron_dxyErr"]	= DEFAULT;
    choose["Events/Electron_dz"]	= DEFAULT;
    choose["Events/Electron_dzErr"]	= DEFAULT;
    choose["Events/Electron_eCorr"]	= DEFAULT;
    choose["Events/Electron_eInvMinusPInv"]	= DEFAULT;
    choose["Events/Electron_energyErr"]	= DEFAULT;
    choose["Events/Electron_eta"]	= DEFAULT;
    choose["Events/Electron_genPartFlav"]	= DEFAULT;
    choose["Events/Electron_genPartIdx"]	= DEFAULT;
    choose["Events/Electron_hoe"]	= DEFAULT;
    choose["Events/Electron_ip3d"]	= DEFAULT;
    choose["Events/Electron_isPFcand"]	= DEFAULT;
    choose["Events/Electron_jetIdx"]	= DEFAULT;
    choose["Events/Electron_lostHits"]	= DEFAULT;
    choose["Events/Electron_mass"]	= DEFAULT;
    choose["Events/Electron_miniPFRelIso_all"]	= DEFAULT;
    choose["Events/Electron_miniPFRelIso_chg"]	= DEFAULT;
    choose["Events/Electron_mvaFall17Iso"]	= DEFAULT;
    choose["Events/Electron_mvaFall17Iso_WP80"]	= DEFAULT;
    choose["Events/Electron_mvaFall17Iso_WP90"]	= DEFAULT;
    choose["Events/Electron_mvaFall17Iso_WPL"]	= DEFAULT;
    choose["Events/Electron_mvaFall17noIso"]	= DEFAULT;
    choose["Events/Electron_mvaFall17noIso_WP80"]	= DEFAULT;
    choose["Events/Electron_mvaFall17noIso_WP90"]	= DEFAULT;
    choose["Events/Electron_mvaFall17noIso_WPL"]	= DEFAULT;
    choose["Events/Electron_mvaTTH"]	= DEFAULT;
    choose["Events/Electron_pdgId"]	= DEFAULT;
    choose["Events/Electron_pfRelIso03_all"]	= DEFAULT;
    choose["Events/Electron_pfRelIso03_chg"]	= DEFAULT;
    choose["Events/Electron_phi"]	= DEFAULT;
    choose["Events/Electron_photonIdx"]	= DEFAULT;
    choose["Events/Electron_pt"]	= DEFAULT;
    choose["Events/Electron_r9"]	= DEFAULT;
    choose["Events/Electron_sieie"]	= DEFAULT;
    choose["Events/Electron_sip3d"]	= DEFAULT;
    choose["Events/Electron_tightCharge"]	= DEFAULT;
    choose["Events/Electron_vidNestedWPBitmap"]	= DEFAULT;
    choose["Events/FatJet_area"]	= DEFAULT;
    choose["Events/FatJet_btagCMVA"]	= DEFAULT;
    choose["Events/FatJet_btagCSVV2"]	= DEFAULT;
    choose["Events/FatJet_btagDeepB"]	= DEFAULT;
    choose["Events/FatJet_btagHbb"]	= DEFAULT;
    choose["Events/FatJet_eta"]	= DEFAULT;
    choose["Events/FatJet_jetId"]	= DEFAULT;
    choose["Events/FatJet_mass"]	= DEFAULT;
    choose["Events/FatJet_msoftdrop"]	= DEFAULT;
    choose["Events/FatJet_n2b1"]	= DEFAULT;
    choose["Events/FatJet_n3b1"]	= DEFAULT;
    choose["Events/FatJet_phi"]	= DEFAULT;
    choose["Events/FatJet_pt"]	= DEFAULT;
    choose["Events/FatJet_subJetIdx1"]	= DEFAULT;
    choose["Events/FatJet_subJetIdx2"]	= DEFAULT;
    choose["Events/FatJet_tau1"]	= DEFAULT;
    choose["Events/FatJet_tau2"]	= DEFAULT;
    choose["Events/FatJet_tau3"]	= DEFAULT;
    choose["Events/FatJet_tau4"]	= DEFAULT;
    choose["Events/Flag_BadChargedCandidateFilter"]	= DEFAULT;
    choose["Events/Flag_BadChargedCandidateSummer16Filter"]	= DEFAULT;
    choose["Events/Flag_BadPFMuonFilter"]	= DEFAULT;
    choose["Events/Flag_BadPFMuonSummer16Filter"]	= DEFAULT;
    choose["Events/Flag_CSCTightHalo2015Filter"]	= DEFAULT;
    choose["Events/Flag_CSCTightHaloFilter"]	= DEFAULT;
    choose["Events/Flag_CSCTightHaloTrkMuUnvetoFilter"]	= DEFAULT;
    choose["Events/Flag_EcalDeadCellBoundaryEnergyFilter"]	= DEFAULT;
    choose["Events/Flag_EcalDeadCellTriggerPrimitiveFilter"]	= DEFAULT;
    choose["Events/Flag_HBHENoiseFilter"]	= DEFAULT;
    choose["Events/Flag_HBHENoiseIsoFilter"]	= DEFAULT;
    choose["Events/Flag_HcalStripHaloFilter"]	= DEFAULT;
    choose["Events/Flag_METFilters"]	= DEFAULT;
    choose["Events/Flag_chargedHadronTrackResolutionFilter"]	= DEFAULT;
    choose["Events/Flag_ecalBadCalibFilter"]	= DEFAULT;
    choose["Events/Flag_ecalLaserCorrFilter"]	= DEFAULT;
    choose["Events/Flag_eeBadScFilter"]	= DEFAULT;
    choose["Events/Flag_globalSuperTightHalo2016Filter"]	= DEFAULT;
    choose["Events/Flag_globalTightHalo2016Filter"]	= DEFAULT;
    choose["Events/Flag_goodVertices"]	= DEFAULT;
    choose["Events/Flag_hcalLaserEventFilter"]	= DEFAULT;
    choose["Events/Flag_muonBadTrackFilter"]	= DEFAULT;
    choose["Events/Flag_trkPOGFilters"]	= DEFAULT;
    choose["Events/Flag_trkPOG_logErrorTooManyClusters"]	= DEFAULT;
    choose["Events/Flag_trkPOG_manystripclus53X"]	= DEFAULT;
    choose["Events/Flag_trkPOG_toomanystripclus53X"]	= DEFAULT;
    choose["Events/GenDressedLepton_eta"]	= DEFAULT;
    choose["Events/GenDressedLepton_mass"]	= DEFAULT;
    choose["Events/GenDressedLepton_pdgId"]	= DEFAULT;
    choose["Events/GenDressedLepton_phi"]	= DEFAULT;
    choose["Events/GenDressedLepton_pt"]	= DEFAULT;
    choose["Events/GenJetAK8_eta"]	= DEFAULT;
    choose["Events/GenJetAK8_hadronFlavour"]	= DEFAULT;
    choose["Events/GenJetAK8_mass"]	= DEFAULT;
    choose["Events/GenJetAK8_partonFlavour"]	= DEFAULT;
    choose["Events/GenJetAK8_phi"]	= DEFAULT;
    choose["Events/GenJetAK8_pt"]	= DEFAULT;
    choose["Events/GenJet_eta"]	= DEFAULT;
    choose["Events/GenJet_hadronFlavour"]	= DEFAULT;
    choose["Events/GenJet_mass"]	= DEFAULT;
    choose["Events/GenJet_partonFlavour"]	= DEFAULT;
    choose["Events/GenJet_phi"]	= DEFAULT;
    choose["Events/GenJet_pt"]	= DEFAULT;
    choose["Events/GenMET_phi"]	= DEFAULT;
    choose["Events/GenMET_pt"]	= DEFAULT;
    choose["Events/GenPart_eta"]	= DEFAULT;
    choose["Events/GenPart_genPartIdxMother"]	= DEFAULT;
    choose["Events/GenPart_mass"]	= DEFAULT;
    choose["Events/GenPart_pdgId"]	= DEFAULT;
    choose["Events/GenPart_phi"]	= DEFAULT;
    choose["Events/GenPart_pt"]	= DEFAULT;
    choose["Events/GenPart_status"]	= DEFAULT;
    choose["Events/GenPart_statusFlags"]	= DEFAULT;
    choose["Events/GenVisTau_charge"]	= DEFAULT;
    choose["Events/GenVisTau_eta"]	= DEFAULT;
    choose["Events/GenVisTau_genPartIdxMother"]	= DEFAULT;
    choose["Events/GenVisTau_mass"]	= DEFAULT;
    choose["Events/GenVisTau_phi"]	= DEFAULT;
    choose["Events/GenVisTau_pt"]	= DEFAULT;
    choose["Events/GenVisTau_status"]	= DEFAULT;
    choose["Events/Generator_binvar"]	= DEFAULT;
    choose["Events/Generator_id1"]	= DEFAULT;
    choose["Events/Generator_id2"]	= DEFAULT;
    choose["Events/Generator_scalePDF"]	= DEFAULT;
    choose["Events/Generator_weight"]	= DEFAULT;
    choose["Events/Generator_x1"]	= DEFAULT;
    choose["Events/Generator_x2"]	= DEFAULT;
    choose["Events/Generator_xpdf1"]	= DEFAULT;
    choose["Events/Generator_xpdf2"]	= DEFAULT;
    choose["Events/HLT_AK4CaloJet100"]	= DEFAULT;
    choose["Events/HLT_AK4CaloJet120"]	= DEFAULT;
    choose["Events/HLT_AK4CaloJet30"]	= DEFAULT;
    choose["Events/HLT_AK4CaloJet40"]	= DEFAULT;
    choose["Events/HLT_AK4CaloJet50"]	= DEFAULT;
    choose["Events/HLT_AK4CaloJet80"]	= DEFAULT;
    choose["Events/HLT_AK4PFJet100"]	= DEFAULT;
    choose["Events/HLT_AK4PFJet120"]	= DEFAULT;
    choose["Events/HLT_AK4PFJet30"]	= DEFAULT;
    choose["Events/HLT_AK4PFJet50"]	= DEFAULT;
    choose["Events/HLT_AK4PFJet80"]	= DEFAULT;
    choose["Events/HLT_AK8PFHT750_TrimMass50"]	= DEFAULT;
    choose["Events/HLT_AK8PFHT800_TrimMass50"]	= DEFAULT;
    choose["Events/HLT_AK8PFHT850_TrimMass50"]	= DEFAULT;
    choose["Events/HLT_AK8PFHT900_TrimMass50"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet140"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet200"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet260"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet320"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet330_PFAK8BTagCSV_p1"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet330_PFAK8BTagCSV_p17"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet360_TrimMass30"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet380_TrimMass30"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet40"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet400"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet400_TrimMass30"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet420_TrimMass30"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet450"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet500"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet550"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet60"]	= DEFAULT;
    choose["Events/HLT_AK8PFJet80"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd140"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd200"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd260"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd320"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd40"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd400"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd450"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd500"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd60"]	= DEFAULT;
    choose["Events/HLT_AK8PFJetFwd80"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK4DiJet110_Mu5"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK4DiJet170_Mu5"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK4DiJet20_Mu5"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK4DiJet40_Mu5"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK4DiJet70_Mu5"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK4Jet300_Mu5"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK8DiJet170_Mu5"]	= DEFAULT;
    choose["Events/HLT_BTagMu_AK8Jet300_Mu5"]	= DEFAULT;
    choose["Events/HLT_CaloJet500_NoJetID"]	= DEFAULT;
    choose["Events/HLT_CaloJet550_NoJetID"]	= DEFAULT;
    choose["Events/HLT_CaloMET100_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET100_NotCleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET110_NotCleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET250_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET250_NotCleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET300_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET350_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET70_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET80_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET80_NotCleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET90_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMET90_NotCleaned"]	= DEFAULT;
    choose["Events/HLT_CaloMHT90"]	= DEFAULT;
    choose["Events/HLT_DiEle27_WPTightCaloOnly_L1DoubleEG"]	= DEFAULT;
    choose["Events/HLT_DiJet110_35_Mjj650_PFMET110"]	= DEFAULT;
    choose["Events/HLT_DiJet110_35_Mjj650_PFMET120"]	= DEFAULT;
    choose["Events/HLT_DiJet110_35_Mjj650_PFMET130"]	= DEFAULT;
    choose["Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL"]	= DEFAULT;
    choose["Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ"]	= DEFAULT;
    choose["Events/HLT_DiPFJet15_FBEta3_NoCaloMatched"]	= DEFAULT;
    choose["Events/HLT_DiPFJet15_NoCaloMatched"]	= DEFAULT;
    choose["Events/HLT_DiPFJet25_FBEta3_NoCaloMatched"]	= DEFAULT;
    choose["Events/HLT_DiPFJet25_NoCaloMatched"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve100_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve140"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve15_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve160_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve200"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve220_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve25_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve260"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve300_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve320"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve35_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve40"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve400"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve500"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve60"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve60_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve80"]	= DEFAULT;
    choose["Events/HLT_DiPFJetAve80_HFJEC"]	= DEFAULT;
    choose["Events/HLT_DiSC30_18_EIso_AND_HE_Mass70"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Jpsi"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Jpsi3p5_Muon2"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Jpsi_L1_4R_0er1p5R"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Jpsi_L1_NoOS"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Jpsi_NoVertexing"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Jpsi_NoVertexing_NoOS"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_LowMass"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_LowMass_L1_0er1p5"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_LowMass_L1_0er1p5R"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_LowMass_L1_4"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_LowMass_L1_4R"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_LowMass_L1_TM530"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_L1_4p5"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_L1_4p5NoOS"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0M"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_L1_5"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_L1_5M"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_Muon_L1_TM0"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_Muon_NoL1Mass"]	= DEFAULT;
    choose["Events/HLT_Dimuon0_Upsilon_NoVertexing"]	= DEFAULT;
    choose["Events/HLT_Dimuon10_PsiPrime_Barrel_Seagulls"]	= DEFAULT;
    choose["Events/HLT_Dimuon10_Upsilon_Barrel_Seagulls"]	= DEFAULT;
    choose["Events/HLT_Dimuon12_Upsilon_eta1p5"]	= DEFAULT;
    choose["Events/HLT_Dimuon14_Phi_Barrel_Seagulls"]	= DEFAULT;
    choose["Events/HLT_Dimuon18_PsiPrime"]	= DEFAULT;
    choose["Events/HLT_Dimuon18_PsiPrime_noCorrL1"]	= DEFAULT;
    choose["Events/HLT_Dimuon20_Jpsi_Barrel_Seagulls"]	= DEFAULT;
    choose["Events/HLT_Dimuon24_Phi_noCorrL1"]	= DEFAULT;
    choose["Events/HLT_Dimuon24_Upsilon_noCorrL1"]	= DEFAULT;
    choose["Events/HLT_Dimuon25_Jpsi"]	= DEFAULT;
    choose["Events/HLT_Dimuon25_Jpsi_noCorrL1"]	= DEFAULT;
    choose["Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55"]	= DEFAULT;
    choose["Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55"]	= DEFAULT;
    choose["Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55"]	= DEFAULT;
    choose["Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55"]	= DEFAULT;
    choose["Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55"]	= DEFAULT;
    choose["Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55"]	= DEFAULT;
    choose["Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90"]	= DEFAULT;
    choose["Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95"]	= DEFAULT;
    choose["Events/HLT_DoubleEle24_eta2p1_WPTight_Gsf"]	= DEFAULT;
    choose["Events/HLT_DoubleEle25_CaloIdL_MW"]	= DEFAULT;
    choose["Events/HLT_DoubleEle27_CaloIdL_MW"]	= DEFAULT;
    choose["Events/HLT_DoubleEle33_CaloIdL_MW"]	= DEFAULT;
    choose["Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350"]	= DEFAULT;
    choose["Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350"]	= DEFAULT;
    choose["Events/HLT_DoubleIsoMu20_eta2p1"]	= DEFAULT;
    choose["Events/HLT_DoubleIsoMu24_eta2p1"]	= DEFAULT;
    choose["Events/HLT_DoubleL2Mu50"]	= DEFAULT;
    choose["Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4"]	= DEFAULT;
    choose["Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4EG"]	= DEFAULT;
    choose["Events/HLT_DoubleMu20_7_Mass0to30_Photon23"]	= DEFAULT;
    choose["Events/HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi"]	= DEFAULT;
    choose["Events/HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi"]	= DEFAULT;
    choose["Events/HLT_DoubleMu3_DCA_PFMET50_PFMHT60"]	= DEFAULT;
    choose["Events/HLT_DoubleMu3_DZ_PFMET50_PFMHT60"]	= DEFAULT;
    choose["Events/HLT_DoubleMu3_DZ_PFMET70_PFMHT70"]	= DEFAULT;
    choose["Events/HLT_DoubleMu3_DZ_PFMET90_PFMHT90"]	= DEFAULT;
    choose["Events/HLT_DoubleMu3_Trk_Tau3mu"]	= DEFAULT;
    choose["Events/HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass"]	= DEFAULT;
    choose["Events/HLT_DoubleMu43NoFiltersNoVtx"]	= DEFAULT;
    choose["Events/HLT_DoubleMu48NoFiltersNoVtx"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_3_Bs"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_3_Jpsi_Displaced"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_JpsiTrkTrk_Displaced"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_JpsiTrk_Displaced"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_Jpsi_Displaced"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_Jpsi_NoVertexing"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_LowMassNonResonantTrk_Displaced"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_Mass8_DZ_PFHT350"]	= DEFAULT;
    choose["Events/HLT_DoubleMu4_PsiPrimeTrk_Displaced"]	= DEFAULT;
    choose["Events/HLT_DoubleMu8_Mass8_PFHT350"]	= DEFAULT;
    choose["Events/HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_DoublePFJets100_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_DoublePFJets200_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_DoublePFJets350_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_DoublePFJets40_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_DoublePhoton33_CaloIdL"]	= DEFAULT;
    choose["Events/HLT_DoublePhoton70"]	= DEFAULT;
    choose["Events/HLT_DoublePhoton85"]	= DEFAULT;
    choose["Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_ECALHT800"]	= DEFAULT;
    choose["Events/HLT_EcalCalibration"]	= DEFAULT;
    choose["Events/HLT_Ele115_CaloIdVT_GsfTrkIdT"]	= DEFAULT;
    choose["Events/HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30"]	= DEFAULT;
    choose["Events/HLT_Ele135_CaloIdVT_GsfTrkIdT"]	= DEFAULT;
    choose["Events/HLT_Ele145_CaloIdVT_GsfTrkIdT"]	= DEFAULT;
    choose["Events/HLT_Ele15_IsoVVVL_PFHT450"]	= DEFAULT;
    choose["Events/HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5"]	= DEFAULT;
    choose["Events/HLT_Ele15_IsoVVVL_PFHT450_PFMET50"]	= DEFAULT;
    choose["Events/HLT_Ele15_IsoVVVL_PFHT600"]	= DEFAULT;
    choose["Events/HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL"]	= DEFAULT;
    choose["Events/HLT_Ele17_CaloIdM_TrackIdM_PFJet30"]	= DEFAULT;
    choose["Events/HLT_Ele200_CaloIdVT_GsfTrkIdT"]	= DEFAULT;
    choose["Events/HLT_Ele20_WPLoose_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele20_WPTight_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele20_eta2p1_WPLoose_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30"]	= DEFAULT;
    choose["Events/HLT_Ele23_CaloIdM_TrackIdM_PFJet30"]	= DEFAULT;
    choose["Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"]	= DEFAULT;
    choose["Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"]	= DEFAULT;
    choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1"]	= DEFAULT;
    choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1"]	= DEFAULT;
    choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1"]	= DEFAULT;
    choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1"]	= DEFAULT;
    choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1"]	= DEFAULT;
    choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1"]	= DEFAULT;
    choose["Events/HLT_Ele250_CaloIdVT_GsfTrkIdT"]	= DEFAULT;
    choose["Events/HLT_Ele27_Ele37_CaloIdL_MW"]	= DEFAULT;
    choose["Events/HLT_Ele27_WPTight_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele28_HighEta_SC20_Mass55"]	= DEFAULT;
    choose["Events/HLT_Ele28_eta2p1_WPTight_Gsf_HT150"]	= DEFAULT;
    choose["Events/HLT_Ele300_CaloIdVT_GsfTrkIdT"]	= DEFAULT;
    choose["Events/HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned"]	= DEFAULT;
    choose["Events/HLT_Ele32_WPTight_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele32_WPTight_Gsf_L1DoubleEG"]	= DEFAULT;
    choose["Events/HLT_Ele35_WPTight_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele35_WPTight_Gsf_L1EGMT"]	= DEFAULT;
    choose["Events/HLT_Ele38_WPTight_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele40_WPTight_Gsf"]	= DEFAULT;
    choose["Events/HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165"]	= DEFAULT;
    choose["Events/HLT_Ele50_IsoVVVL_PFHT450"]	= DEFAULT;
    choose["Events/HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30"]	= DEFAULT;
    choose["Events/HLT_Ele8_CaloIdM_TrackIdM_PFJet30"]	= DEFAULT;
    choose["Events/HLT_FullTrack_Multiplicity100"]	= DEFAULT;
    choose["Events/HLT_FullTrack_Multiplicity130"]	= DEFAULT;
    choose["Events/HLT_FullTrack_Multiplicity155"]	= DEFAULT;
    choose["Events/HLT_FullTrack_Multiplicity85"]	= DEFAULT;
    choose["Events/HLT_HISinglePhoton10_Eta3p1ForPPRef"]	= DEFAULT;
    choose["Events/HLT_HISinglePhoton20_Eta3p1ForPPRef"]	= DEFAULT;
    choose["Events/HLT_HISinglePhoton30_Eta3p1ForPPRef"]	= DEFAULT;
    choose["Events/HLT_HISinglePhoton40_Eta3p1ForPPRef"]	= DEFAULT;
    choose["Events/HLT_HISinglePhoton50_Eta3p1ForPPRef"]	= DEFAULT;
    choose["Events/HLT_HISinglePhoton60_Eta3p1ForPPRef"]	= DEFAULT;
    choose["Events/HLT_HT300_Beamspot"]	= DEFAULT;
    choose["Events/HLT_HT400_DisplacedDijet40_DisplacedTrack"]	= DEFAULT;
    choose["Events/HLT_HT425"]	= DEFAULT;
    choose["Events/HLT_HT430_DisplacedDijet40_DisplacedTrack"]	= DEFAULT;
    choose["Events/HLT_HT430_DisplacedDijet60_DisplacedTrack"]	= DEFAULT;
    choose["Events/HLT_HT430_DisplacedDijet80_DisplacedTrack"]	= DEFAULT;
    choose["Events/HLT_HT450_Beamspot"]	= DEFAULT;
    choose["Events/HLT_HT550_DisplacedDijet60_Inclusive"]	= DEFAULT;
    choose["Events/HLT_HT550_DisplacedDijet80_Inclusive"]	= DEFAULT;
    choose["Events/HLT_HT650_DisplacedDijet60_Inclusive"]	= DEFAULT;
    choose["Events/HLT_HT650_DisplacedDijet80_Inclusive"]	= DEFAULT;
    choose["Events/HLT_HT750_DisplacedDijet80_Inclusive"]	= DEFAULT;
    choose["Events/HLT_HcalCalibration"]	= DEFAULT;
    choose["Events/HLT_HcalIsolatedbunch"]	= DEFAULT;
    choose["Events/HLT_HcalNZS"]	= DEFAULT;
    choose["Events/HLT_HcalPhiSym"]	= DEFAULT;
    choose["Events/HLT_IsoMu20"]	= DEFAULT;
    choose["Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu27"]	= DEFAULT;
    choose["Events/HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1"]	= DEFAULT;
    choose["Events/HLT_IsoMu30"]	= DEFAULT;
    choose["Events/HLT_IsoTrackHB"]	= DEFAULT;
    choose["Events/HLT_IsoTrackHE"]	= DEFAULT;
    choose["Events/HLT_L1ETMHadSeeds"]	= DEFAULT;
    choose["Events/HLT_L1MinimumBiasHF0OR"]	= DEFAULT;
    choose["Events/HLT_L1MinimumBiasHF_OR"]	= DEFAULT;
    choose["Events/HLT_L1NotBptxOR"]	= DEFAULT;
    choose["Events/HLT_L1SingleMu18"]	= DEFAULT;
    choose["Events/HLT_L1SingleMu25"]	= DEFAULT;
    choose["Events/HLT_L1UnpairedBunchBptxMinus"]	= DEFAULT;
    choose["Events/HLT_L1UnpairedBunchBptxPlus"]	= DEFAULT;
    choose["Events/HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142"]	= DEFAULT;
    choose["Events/HLT_L1_DoubleJet30_Mass_Min400_Mu10"]	= DEFAULT;
    choose["Events/HLT_L2Mu10"]	= DEFAULT;
    choose["Events/HLT_L2Mu10_NoVertex_NoBPTX"]	= DEFAULT;
    choose["Events/HLT_L2Mu10_NoVertex_NoBPTX3BX"]	= DEFAULT;
    choose["Events/HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX"]	= DEFAULT;
    choose["Events/HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX"]	= DEFAULT;
    choose["Events/HLT_L2Mu50"]	= DEFAULT;
    choose["Events/HLT_MET105_IsoTrk50"]	= DEFAULT;
    choose["Events/HLT_MET120_IsoTrk50"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130"]	= DEFAULT;
    choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90"]	= DEFAULT;
    choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight"]	= DEFAULT;
    choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight"]	= DEFAULT;
    choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight"]	= DEFAULT;
    choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight"]	= DEFAULT;
    choose["Events/HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33"]	= DEFAULT;
    choose["Events/HLT_Mu12_DoublePhoton20"]	= DEFAULT;
    choose["Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"]	= DEFAULT;
    choose["Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu15_IsoVVVL_PFHT450"]	= DEFAULT;
    choose["Events/HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5"]	= DEFAULT;
    choose["Events/HLT_Mu15_IsoVVVL_PFHT450_PFMET50"]	= DEFAULT;
    choose["Events/HLT_Mu15_IsoVVVL_PFHT600"]	= DEFAULT;
    choose["Events/HLT_Mu17"]	= DEFAULT;
    choose["Events/HLT_Mu17_Photon30_IsoCaloId"]	= DEFAULT;
    choose["Events/HLT_Mu17_TrkIsoVVL"]	= DEFAULT;
    choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"]	= DEFAULT;
    choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8"]	= DEFAULT;
    choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8"]	= DEFAULT;
    choose["Events/HLT_Mu18_Mu9"]	= DEFAULT;
    choose["Events/HLT_Mu18_Mu9_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu18_Mu9_SameSign"]	= DEFAULT;
    choose["Events/HLT_Mu18_Mu9_SameSign_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu19"]	= DEFAULT;
    choose["Events/HLT_Mu19_TrkIsoVVL"]	= DEFAULT;
    choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL"]	= DEFAULT;
    choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8"]	= DEFAULT;
    choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8"]	= DEFAULT;
    choose["Events/HLT_Mu20"]	= DEFAULT;
    choose["Events/HLT_Mu20_Mu10"]	= DEFAULT;
    choose["Events/HLT_Mu20_Mu10_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu20_Mu10_SameSign"]	= DEFAULT;
    choose["Events/HLT_Mu20_Mu10_SameSign_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu20_TkMu0_Phi"]	= DEFAULT;
    choose["Events/HLT_Mu23_Mu12"]	= DEFAULT;
    choose["Events/HLT_Mu23_Mu12_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu23_Mu12_SameSign"]	= DEFAULT;
    choose["Events/HLT_Mu23_Mu12_SameSign_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"]	= DEFAULT;
    choose["Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu25_TkMu0_Onia"]	= DEFAULT;
    choose["Events/HLT_Mu25_TkMu0_Phi"]	= DEFAULT;
    choose["Events/HLT_Mu27"]	= DEFAULT;
    choose["Events/HLT_Mu27_Ele37_CaloIdL_MW"]	= DEFAULT;
    choose["Events/HLT_Mu30_TkMu0_Onia"]	= DEFAULT;
    choose["Events/HLT_Mu37_Ele27_CaloIdL_MW"]	= DEFAULT;
    choose["Events/HLT_Mu37_TkMu27"]	= DEFAULT;
    choose["Events/HLT_Mu3_PFJet40"]	= DEFAULT;
    choose["Events/HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL"]	= DEFAULT;
    choose["Events/HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL"]	= DEFAULT;
    choose["Events/HLT_Mu50"]	= DEFAULT;
    choose["Events/HLT_Mu50_IsoVVVL_PFHT450"]	= DEFAULT;
    choose["Events/HLT_Mu55"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_L2Mu2_Jpsi"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_L2Mu2_Upsilon"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_Track2_Jpsi"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_Track2_Upsilon"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_Track3p5_Jpsi"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_Track3p5_Upsilon"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_Track7_Jpsi"]	= DEFAULT;
    choose["Events/HLT_Mu7p5_Track7_Upsilon"]	= DEFAULT;
    choose["Events/HLT_Mu8"]	= DEFAULT;
    choose["Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL"]	= DEFAULT;
    choose["Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350"]	= DEFAULT;
    choose["Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ"]	= DEFAULT;
    choose["Events/HLT_Mu8_TrkIsoVVL"]	= DEFAULT;
    choose["Events/HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60"]	= DEFAULT;
    choose["Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"]	= DEFAULT;
    choose["Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"]	= DEFAULT;
    choose["Events/HLT_OldMu100"]	= DEFAULT;
    choose["Events/HLT_PFHT1050"]	= DEFAULT;
    choose["Events/HLT_PFHT180"]	= DEFAULT;
    choose["Events/HLT_PFHT250"]	= DEFAULT;
    choose["Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40"]	= DEFAULT;
    choose["Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0"]	= DEFAULT;
    choose["Events/HLT_PFHT350"]	= DEFAULT;
    choose["Events/HLT_PFHT350MinPFJet15"]	= DEFAULT;
    choose["Events/HLT_PFHT370"]	= DEFAULT;
    choose["Events/HLT_PFHT380_SixPFJet32"]	= DEFAULT;
    choose["Events/HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2"]	= DEFAULT;
    choose["Events/HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2"]	= DEFAULT;
    choose["Events/HLT_PFHT430"]	= DEFAULT;
    choose["Events/HLT_PFHT430_SixPFJet40"]	= DEFAULT;
    choose["Events/HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5"]	= DEFAULT;
    choose["Events/HLT_PFHT500_PFMET100_PFMHT100_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFHT500_PFMET110_PFMHT110_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFHT510"]	= DEFAULT;
    choose["Events/HLT_PFHT590"]	= DEFAULT;
    choose["Events/HLT_PFHT680"]	= DEFAULT;
    choose["Events/HLT_PFHT700_PFMET85_PFMHT85_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFHT700_PFMET95_PFMHT95_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFHT780"]	= DEFAULT;
    choose["Events/HLT_PFHT800_PFMET75_PFMHT75_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFHT800_PFMET85_PFMHT85_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFHT890"]	= DEFAULT;
    choose["Events/HLT_PFJet140"]	= DEFAULT;
    choose["Events/HLT_PFJet200"]	= DEFAULT;
    choose["Events/HLT_PFJet260"]	= DEFAULT;
    choose["Events/HLT_PFJet320"]	= DEFAULT;
    choose["Events/HLT_PFJet40"]	= DEFAULT;
    choose["Events/HLT_PFJet400"]	= DEFAULT;
    choose["Events/HLT_PFJet450"]	= DEFAULT;
    choose["Events/HLT_PFJet500"]	= DEFAULT;
    choose["Events/HLT_PFJet550"]	= DEFAULT;
    choose["Events/HLT_PFJet60"]	= DEFAULT;
    choose["Events/HLT_PFJet80"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd140"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd200"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd260"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd320"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd40"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd400"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd450"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd500"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd60"]	= DEFAULT;
    choose["Events/HLT_PFJetFwd80"]	= DEFAULT;
    choose["Events/HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1"]	= DEFAULT;
    choose["Events/HLT_PFMET100_PFMHT100_IDTight_PFHT60"]	= DEFAULT;
    choose["Events/HLT_PFMET110_PFMHT110_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1"]	= DEFAULT;
    choose["Events/HLT_PFMET120_PFMHT120_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1"]	= DEFAULT;
    choose["Events/HLT_PFMET120_PFMHT120_IDTight_PFHT60"]	= DEFAULT;
    choose["Events/HLT_PFMET130_PFMHT130_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1"]	= DEFAULT;
    choose["Events/HLT_PFMET140_PFMHT140_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1"]	= DEFAULT;
    choose["Events/HLT_PFMET200_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_PFMET200_HBHE_BeamHaloCleaned"]	= DEFAULT;
    choose["Events/HLT_PFMET200_NotCleaned"]	= DEFAULT;
    choose["Events/HLT_PFMET250_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_PFMET300_HBHECleaned"]	= DEFAULT;
    choose["Events/HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60"]	= DEFAULT;
    choose["Events/HLT_PFMETNoMu110_PFMHTNoMu110_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60"]	= DEFAULT;
    choose["Events/HLT_PFMETNoMu130_PFMHTNoMu130_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETNoMu140_PFMHTNoMu140_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60"]	= DEFAULT;
    choose["Events/HLT_PFMETTypeOne110_PFMHT110_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETTypeOne120_PFMHT120_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60"]	= DEFAULT;
    choose["Events/HLT_PFMETTypeOne130_PFMHT130_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETTypeOne140_PFMHT140_IDTight"]	= DEFAULT;
    choose["Events/HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned"]	= DEFAULT;
    choose["Events/HLT_Photon120"]	= DEFAULT;
    choose["Events/HLT_Photon120_R9Id90_HE10_IsoM"]	= DEFAULT;
    choose["Events/HLT_Photon150"]	= DEFAULT;
    choose["Events/HLT_Photon165_R9Id90_HE10_IsoM"]	= DEFAULT;
    choose["Events/HLT_Photon175"]	= DEFAULT;
    choose["Events/HLT_Photon200"]	= DEFAULT;
    choose["Events/HLT_Photon20_HoverELoose"]	= DEFAULT;
    choose["Events/HLT_Photon25"]	= DEFAULT;
    choose["Events/HLT_Photon300_NoHE"]	= DEFAULT;
    choose["Events/HLT_Photon30_HoverELoose"]	= DEFAULT;
    choose["Events/HLT_Photon33"]	= DEFAULT;
    choose["Events/HLT_Photon40_HoverELoose"]	= DEFAULT;
    choose["Events/HLT_Photon50"]	= DEFAULT;
    choose["Events/HLT_Photon50_HoverELoose"]	= DEFAULT;
    choose["Events/HLT_Photon50_R9Id90_HE10_IsoM"]	= DEFAULT;
    choose["Events/HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50"]	= DEFAULT;
    choose["Events/HLT_Photon60_HoverELoose"]	= DEFAULT;
    choose["Events/HLT_Photon60_R9Id90_CaloIdL_IsoL"]	= DEFAULT;
    choose["Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL"]	= DEFAULT;
    choose["Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15"]	= DEFAULT;
    choose["Events/HLT_Photon75"]	= DEFAULT;
    choose["Events/HLT_Photon75_R9Id90_HE10_IsoM"]	= DEFAULT;
    choose["Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3"]	= DEFAULT;
    choose["Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3"]	= DEFAULT;
    choose["Events/HLT_Photon90"]	= DEFAULT;
    choose["Events/HLT_Photon90_CaloIdL_PFHT700"]	= DEFAULT;
    choose["Events/HLT_Photon90_R9Id90_HE10_IsoM"]	= DEFAULT;
    choose["Events/HLT_Physics"]	= DEFAULT;
    choose["Events/HLT_Physics_part0"]	= DEFAULT;
    choose["Events/HLT_Physics_part1"]	= DEFAULT;
    choose["Events/HLT_Physics_part2"]	= DEFAULT;
    choose["Events/HLT_Physics_part3"]	= DEFAULT;
    choose["Events/HLT_Physics_part4"]	= DEFAULT;
    choose["Events/HLT_Physics_part5"]	= DEFAULT;
    choose["Events/HLT_Physics_part6"]	= DEFAULT;
    choose["Events/HLT_Physics_part7"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet103_88_75_15"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet105_88_76_15"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet111_90_80_15"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet98_83_71_15"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2"]	= DEFAULT;
    choose["Events/HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1"]	= DEFAULT;
    choose["Events/HLT_Random"]	= DEFAULT;
    choose["Events/HLT_Rsq0p35"]	= DEFAULT;
    choose["Events/HLT_Rsq0p40"]	= DEFAULT;
    choose["Events/HLT_RsqMR300_Rsq0p09_MR200"]	= DEFAULT;
    choose["Events/HLT_RsqMR300_Rsq0p09_MR200_4jet"]	= DEFAULT;
    choose["Events/HLT_RsqMR320_Rsq0p09_MR200"]	= DEFAULT;
    choose["Events/HLT_RsqMR320_Rsq0p09_MR200_4jet"]	= DEFAULT;
    choose["Events/HLT_SingleJet30_Mu12_SinglePFJet40"]	= DEFAULT;
    choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15"]	= DEFAULT;
    choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1"]	= DEFAULT;
    choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15"]	= DEFAULT;
    choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1"]	= DEFAULT;
    choose["Events/HLT_TkMu100"]	= DEFAULT;
    choose["Events/HLT_Trimuon5_3p5_2_Upsilon_Muon"]	= DEFAULT;
    choose["Events/HLT_TripleJet110_35_35_Mjj650_PFMET110"]	= DEFAULT;
    choose["Events/HLT_TripleJet110_35_35_Mjj650_PFMET120"]	= DEFAULT;
    choose["Events/HLT_TripleJet110_35_35_Mjj650_PFMET130"]	= DEFAULT;
    choose["Events/HLT_TripleMu_10_5_5_DZ"]	= DEFAULT;
    choose["Events/HLT_TripleMu_12_10_5"]	= DEFAULT;
    choose["Events/HLT_TripleMu_5_3_3_Mass3p8to60_DCA"]	= DEFAULT;
    choose["Events/HLT_TripleMu_5_3_3_Mass3p8to60_DZ"]	= DEFAULT;
    choose["Events/HLT_TriplePhoton_20_20_20_CaloIdLV2"]	= DEFAULT;
    choose["Events/HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL"]	= DEFAULT;
    choose["Events/HLT_TriplePhoton_30_30_10_CaloIdLV2"]	= DEFAULT;
    choose["Events/HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL"]	= DEFAULT;
    choose["Events/HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL"]	= DEFAULT;
    choose["Events/HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx"]	= DEFAULT;
    choose["Events/HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx"]	= DEFAULT;
    choose["Events/HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx"]	= DEFAULT;
    choose["Events/HLT_UncorrectedJetE30_NoBPTX"]	= DEFAULT;
    choose["Events/HLT_UncorrectedJetE30_NoBPTX3BX"]	= DEFAULT;
    choose["Events/HLT_UncorrectedJetE60_NoBPTX3BX"]	= DEFAULT;
    choose["Events/HLT_UncorrectedJetE70_NoBPTX3BX"]	= DEFAULT;
    choose["Events/HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg"]	= DEFAULT;
    choose["Events/HLT_ZeroBias"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_FirstBXAfterTrain"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_FirstCollisionAfterAbortGap"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_FirstCollisionInTrain"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_IsolatedBunches"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_LastCollisionInTrain"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part0"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part1"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part2"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part3"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part4"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part5"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part6"]	= DEFAULT;
    choose["Events/HLT_ZeroBias_part7"]	= DEFAULT;
    choose["Events/HLTriggerFinalPath"]	= DEFAULT;
    choose["Events/HLTriggerFirstPath"]	= DEFAULT;
    choose["Events/IsoTrack_dxy"]	= DEFAULT;
    choose["Events/IsoTrack_dz"]	= DEFAULT;
    choose["Events/IsoTrack_eta"]	= DEFAULT;
    choose["Events/IsoTrack_isHighPurityTrack"]	= DEFAULT;
    choose["Events/IsoTrack_isPFcand"]	= DEFAULT;
    choose["Events/IsoTrack_miniPFRelIso_all"]	= DEFAULT;
    choose["Events/IsoTrack_miniPFRelIso_chg"]	= DEFAULT;
    choose["Events/IsoTrack_pdgId"]	= DEFAULT;
    choose["Events/IsoTrack_pfRelIso03_all"]	= DEFAULT;
    choose["Events/IsoTrack_pfRelIso03_chg"]	= DEFAULT;
    choose["Events/IsoTrack_phi"]	= DEFAULT;
    choose["Events/IsoTrack_pt"]	= DEFAULT;
    choose["Events/Jet_area"]	= DEFAULT;
    choose["Events/Jet_bReg"]	= DEFAULT;
    choose["Events/Jet_btagCMVA"]	= DEFAULT;
    choose["Events/Jet_btagCSVV2"]	= DEFAULT;
    choose["Events/Jet_btagDeepB"]	= DEFAULT;
    choose["Events/Jet_btagDeepC"]	= DEFAULT;
    choose["Events/Jet_btagDeepFlavB"]	= DEFAULT;
    choose["Events/Jet_chEmEF"]	= DEFAULT;
    choose["Events/Jet_chHEF"]	= DEFAULT;
    choose["Events/Jet_cleanmask"]	= DEFAULT;
    choose["Events/Jet_electronIdx1"]	= DEFAULT;
    choose["Events/Jet_electronIdx2"]	= DEFAULT;
    choose["Events/Jet_eta"]	= DEFAULT;
    choose["Events/Jet_genJetIdx"]	= DEFAULT;
    choose["Events/Jet_hadronFlavour"]	= DEFAULT;
    choose["Events/Jet_jetId"]	= DEFAULT;
    choose["Events/Jet_mass"]	= DEFAULT;
    choose["Events/Jet_muonIdx1"]	= DEFAULT;
    choose["Events/Jet_muonIdx2"]	= DEFAULT;
    choose["Events/Jet_nConstituents"]	= DEFAULT;
    choose["Events/Jet_nElectrons"]	= DEFAULT;
    choose["Events/Jet_nMuons"]	= DEFAULT;
    choose["Events/Jet_neEmEF"]	= DEFAULT;
    choose["Events/Jet_neHEF"]	= DEFAULT;
    choose["Events/Jet_partonFlavour"]	= DEFAULT;
    choose["Events/Jet_phi"]	= DEFAULT;
    choose["Events/Jet_pt"]	= DEFAULT;
    choose["Events/Jet_puId"]	= DEFAULT;
    choose["Events/Jet_qgl"]	= DEFAULT;
    choose["Events/Jet_rawFactor"]	= DEFAULT;
    choose["Events/L1simulation_step"]	= DEFAULT;
    choose["Events/LHEPart_eta"]	= DEFAULT;
    choose["Events/LHEPart_mass"]	= DEFAULT;
    choose["Events/LHEPart_pdgId"]	= DEFAULT;
    choose["Events/LHEPart_phi"]	= DEFAULT;
    choose["Events/LHEPart_pt"]	= DEFAULT;
    choose["Events/LHEPdfWeight"]	= DEFAULT;
    choose["Events/LHEScaleWeight"]	= DEFAULT;
    choose["Events/LHEWeight_originalXWGTUP"]	= DEFAULT;
    choose["Events/LHE_HT"]	= DEFAULT;
    choose["Events/LHE_HTIncoming"]	= DEFAULT;
    choose["Events/LHE_Nb"]	= DEFAULT;
    choose["Events/LHE_Nc"]	= DEFAULT;
    choose["Events/LHE_Nglu"]	= DEFAULT;
    choose["Events/LHE_Njets"]	= DEFAULT;
    choose["Events/LHE_NpLO"]	= DEFAULT;
    choose["Events/LHE_NpNLO"]	= DEFAULT;
    choose["Events/LHE_Nuds"]	= DEFAULT;
    choose["Events/LHE_Vpt"]	= DEFAULT;
    choose["Events/MET_MetUnclustEnUpDeltaX"]	= DEFAULT;
    choose["Events/MET_MetUnclustEnUpDeltaY"]	= DEFAULT;
    choose["Events/MET_covXX"]	= DEFAULT;
    choose["Events/MET_covXY"]	= DEFAULT;
    choose["Events/MET_covYY"]	= DEFAULT;
    choose["Events/MET_fiducialGenPhi"]	= DEFAULT;
    choose["Events/MET_fiducialGenPt"]	= DEFAULT;
    choose["Events/MET_phi"]	= DEFAULT;
    choose["Events/MET_pt"]	= DEFAULT;
    choose["Events/MET_significance"]	= DEFAULT;
    choose["Events/MET_sumEt"]	= DEFAULT;
    choose["Events/Muon_charge"]	= DEFAULT;
    choose["Events/Muon_cleanmask"]	= DEFAULT;
    choose["Events/Muon_dxy"]	= DEFAULT;
    choose["Events/Muon_dxyErr"]	= DEFAULT;
    choose["Events/Muon_dz"]	= DEFAULT;
    choose["Events/Muon_dzErr"]	= DEFAULT;
    choose["Events/Muon_eta"]	= DEFAULT;
    choose["Events/Muon_genPartFlav"]	= DEFAULT;
    choose["Events/Muon_genPartIdx"]	= DEFAULT;
    choose["Events/Muon_highPtId"]	= DEFAULT;
    choose["Events/Muon_ip3d"]	= DEFAULT;
    choose["Events/Muon_isPFcand"]	= DEFAULT;
    choose["Events/Muon_jetIdx"]	= DEFAULT;
    choose["Events/Muon_mass"]	= DEFAULT;
    choose["Events/Muon_mediumId"]	= DEFAULT;
    choose["Events/Muon_miniPFRelIso_all"]	= DEFAULT;
    choose["Events/Muon_miniPFRelIso_chg"]	= DEFAULT;
    choose["Events/Muon_mvaTTH"]	= DEFAULT;
    choose["Events/Muon_nStations"]	= DEFAULT;
    choose["Events/Muon_nTrackerLayers"]	= DEFAULT;
    choose["Events/Muon_pdgId"]	= DEFAULT;
    choose["Events/Muon_pfRelIso03_all"]	= DEFAULT;
    choose["Events/Muon_pfRelIso03_chg"]	= DEFAULT;
    choose["Events/Muon_pfRelIso04_all"]	= DEFAULT;
    choose["Events/Muon_phi"]	= DEFAULT;
    choose["Events/Muon_pt"]	= DEFAULT;
    choose["Events/Muon_ptErr"]	= DEFAULT;
    choose["Events/Muon_segmentComp"]	= DEFAULT;
    choose["Events/Muon_sip3d"]	= DEFAULT;
    choose["Events/Muon_softId"]	= DEFAULT;
    choose["Events/Muon_tightCharge"]	= DEFAULT;
    choose["Events/Muon_tightId"]	= DEFAULT;
    choose["Events/OtherPV_z"]	= DEFAULT;
    choose["Events/PV_chi2"]	= DEFAULT;
    choose["Events/PV_ndof"]	= DEFAULT;
    choose["Events/PV_npvs"]	= DEFAULT;
    choose["Events/PV_npvsGood"]	= DEFAULT;
    choose["Events/PV_score"]	= DEFAULT;
    choose["Events/PV_x"]	= DEFAULT;
    choose["Events/PV_y"]	= DEFAULT;
    choose["Events/PV_z"]	= DEFAULT;
    choose["Events/Photon_charge"]	= DEFAULT;
    choose["Events/Photon_cleanmask"]	= DEFAULT;
    choose["Events/Photon_cutBasedBitmap"]	= DEFAULT;
    choose["Events/Photon_eCorr"]	= DEFAULT;
    choose["Events/Photon_electronIdx"]	= DEFAULT;
    choose["Events/Photon_electronVeto"]	= DEFAULT;
    choose["Events/Photon_energyErr"]	= DEFAULT;
    choose["Events/Photon_eta"]	= DEFAULT;
    choose["Events/Photon_genPartFlav"]	= DEFAULT;
    choose["Events/Photon_genPartIdx"]	= DEFAULT;
    choose["Events/Photon_hoe"]	= DEFAULT;
    choose["Events/Photon_isScEtaEB"]	= DEFAULT;
    choose["Events/Photon_isScEtaEE"]	= DEFAULT;
    choose["Events/Photon_jetIdx"]	= DEFAULT;
    choose["Events/Photon_mass"]	= DEFAULT;
    choose["Events/Photon_mvaID"]	= DEFAULT;
    choose["Events/Photon_mvaID_WP80"]	= DEFAULT;
    choose["Events/Photon_mvaID_WP90"]	= DEFAULT;
    choose["Events/Photon_pdgId"]	= DEFAULT;
    choose["Events/Photon_pfRelIso03_all"]	= DEFAULT;
    choose["Events/Photon_pfRelIso03_chg"]	= DEFAULT;
    choose["Events/Photon_phi"]	= DEFAULT;
    choose["Events/Photon_pixelSeed"]	= DEFAULT;
    choose["Events/Photon_pt"]	= DEFAULT;
    choose["Events/Photon_r9"]	= DEFAULT;
    choose["Events/Photon_sieie"]	= DEFAULT;
    choose["Events/Photon_vidNestedWPBitmap"]	= DEFAULT;
    choose["Events/Pileup_nPU"]	= DEFAULT;
    choose["Events/Pileup_nTrueInt"]	= DEFAULT;
    choose["Events/Pileup_sumEOOT"]	= DEFAULT;
    choose["Events/Pileup_sumLOOT"]	= DEFAULT;
    choose["Events/PuppiMET_phi"]	= DEFAULT;
    choose["Events/PuppiMET_pt"]	= DEFAULT;
    choose["Events/PuppiMET_sumEt"]	= DEFAULT;
    choose["Events/RawMET_phi"]	= DEFAULT;
    choose["Events/RawMET_pt"]	= DEFAULT;
    choose["Events/RawMET_sumEt"]	= DEFAULT;
    choose["Events/SV_chi2"]	= DEFAULT;
    choose["Events/SV_dlen"]	= DEFAULT;
    choose["Events/SV_dlenSig"]	= DEFAULT;
    choose["Events/SV_eta"]	= DEFAULT;
    choose["Events/SV_mass"]	= DEFAULT;
    choose["Events/SV_ndof"]	= DEFAULT;
    choose["Events/SV_pAngle"]	= DEFAULT;
    choose["Events/SV_phi"]	= DEFAULT;
    choose["Events/SV_pt"]	= DEFAULT;
    choose["Events/SV_x"]	= DEFAULT;
    choose["Events/SV_y"]	= DEFAULT;
    choose["Events/SV_z"]	= DEFAULT;
    choose["Events/SoftActivityJetHT"]	= DEFAULT;
    choose["Events/SoftActivityJetHT10"]	= DEFAULT;
    choose["Events/SoftActivityJetHT2"]	= DEFAULT;
    choose["Events/SoftActivityJetHT5"]	= DEFAULT;
    choose["Events/SoftActivityJetNjets10"]	= DEFAULT;
    choose["Events/SoftActivityJetNjets2"]	= DEFAULT;
    choose["Events/SoftActivityJetNjets5"]	= DEFAULT;
    choose["Events/SoftActivityJet_eta"]	= DEFAULT;
    choose["Events/SoftActivityJet_phi"]	= DEFAULT;
    choose["Events/SoftActivityJet_pt"]	= DEFAULT;
    choose["Events/SubGenJetAK8_eta"]	= DEFAULT;
    choose["Events/SubGenJetAK8_mass"]	= DEFAULT;
    choose["Events/SubGenJetAK8_phi"]	= DEFAULT;
    choose["Events/SubGenJetAK8_pt"]	= DEFAULT;
    choose["Events/SubJet_btagCMVA"]	= DEFAULT;
    choose["Events/SubJet_btagCSVV2"]	= DEFAULT;
    choose["Events/SubJet_btagDeepB"]	= DEFAULT;
    choose["Events/SubJet_eta"]	= DEFAULT;
    choose["Events/SubJet_mass"]	= DEFAULT;
    choose["Events/SubJet_n2b1"]	= DEFAULT;
    choose["Events/SubJet_n3b1"]	= DEFAULT;
    choose["Events/SubJet_phi"]	= DEFAULT;
    choose["Events/SubJet_pt"]	= DEFAULT;
    choose["Events/SubJet_tau1"]	= DEFAULT;
    choose["Events/SubJet_tau2"]	= DEFAULT;
    choose["Events/SubJet_tau3"]	= DEFAULT;
    choose["Events/SubJet_tau4"]	= DEFAULT;
    choose["Events/Tau_charge"]	= DEFAULT;
    choose["Events/Tau_chargedIso"]	= DEFAULT;
    choose["Events/Tau_cleanmask"]	= DEFAULT;
    choose["Events/Tau_decayMode"]	= DEFAULT;
    choose["Events/Tau_dxy"]	= DEFAULT;
    choose["Events/Tau_dz"]	= DEFAULT;
    choose["Events/Tau_eta"]	= DEFAULT;
    choose["Events/Tau_genPartFlav"]	= DEFAULT;
    choose["Events/Tau_genPartIdx"]	= DEFAULT;
    choose["Events/Tau_idAntiEle"]	= DEFAULT;
    choose["Events/Tau_idAntiMu"]	= DEFAULT;
    choose["Events/Tau_idDecayMode"]	= DEFAULT;
    choose["Events/Tau_idDecayModeNewDMs"]	= DEFAULT;
    choose["Events/Tau_idMVAnewDM2017v2"]	= DEFAULT;
    choose["Events/Tau_idMVAoldDM"]	= DEFAULT;
    choose["Events/Tau_idMVAoldDM2017v1"]	= DEFAULT;
    choose["Events/Tau_idMVAoldDM2017v2"]	= DEFAULT;
    choose["Events/Tau_idMVAoldDMdR032017v2"]	= DEFAULT;
    choose["Events/Tau_jetIdx"]	= DEFAULT;
    choose["Events/Tau_leadTkDeltaEta"]	= DEFAULT;
    choose["Events/Tau_leadTkDeltaPhi"]	= DEFAULT;
    choose["Events/Tau_leadTkPtOverTauPt"]	= DEFAULT;
    choose["Events/Tau_mass"]	= DEFAULT;
    choose["Events/Tau_neutralIso"]	= DEFAULT;
    choose["Events/Tau_phi"]	= DEFAULT;
    choose["Events/Tau_photonsOutsideSignalCone"]	= DEFAULT;
    choose["Events/Tau_pt"]	= DEFAULT;
    choose["Events/Tau_puCorr"]	= DEFAULT;
    choose["Events/Tau_rawAntiEle"]	= DEFAULT;
    choose["Events/Tau_rawAntiEleCat"]	= DEFAULT;
    choose["Events/Tau_rawIso"]	= DEFAULT;
    choose["Events/Tau_rawIsodR03"]	= DEFAULT;
    choose["Events/Tau_rawMVAnewDM2017v2"]	= DEFAULT;
    choose["Events/Tau_rawMVAoldDM"]	= DEFAULT;
    choose["Events/Tau_rawMVAoldDM2017v1"]	= DEFAULT;
    choose["Events/Tau_rawMVAoldDM2017v2"]	= DEFAULT;
    choose["Events/Tau_rawMVAoldDMdR032017v2"]	= DEFAULT;
    choose["Events/TkMET_phi"]	= DEFAULT;
    choose["Events/TkMET_pt"]	= DEFAULT;
    choose["Events/TkMET_sumEt"]	= DEFAULT;
    choose["Events/TrigObj_eta"]	= DEFAULT;
    choose["Events/TrigObj_filterBits"]	= DEFAULT;
    choose["Events/TrigObj_id"]	= DEFAULT;
    choose["Events/TrigObj_l1charge"]	= DEFAULT;
    choose["Events/TrigObj_l1iso"]	= DEFAULT;
    choose["Events/TrigObj_l1pt"]	= DEFAULT;
    choose["Events/TrigObj_l1pt_2"]	= DEFAULT;
    choose["Events/TrigObj_l2pt"]	= DEFAULT;
    choose["Events/TrigObj_phi"]	= DEFAULT;
    choose["Events/TrigObj_pt"]	= DEFAULT;
    choose["Events/event"]	= DEFAULT;
    choose["Events/fixedGridRhoFastjetAll"]	= DEFAULT;
    choose["Events/fixedGridRhoFastjetCentralCalo"]	= DEFAULT;
    choose["Events/fixedGridRhoFastjetCentralNeutral"]	= DEFAULT;
    choose["Events/genTtbarId"]	= DEFAULT;
    choose["Events/genWeight"]	= DEFAULT;
    choose["Events/luminosityBlock"]	= DEFAULT;
    choose["Events/run"]	= DEFAULT;

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
    if ( choose["Events/CaloMET_phi"] )
      input->select("Events/CaloMET_phi", 	CaloMET_phi);
    if ( choose["Events/CaloMET_pt"] )
      input->select("Events/CaloMET_pt", 	CaloMET_pt);
    if ( choose["Events/CaloMET_sumEt"] )
      input->select("Events/CaloMET_sumEt", 	CaloMET_sumEt);
    if ( choose["Events/Electron_charge"] )
      input->select("Events/Electron_charge", 	Electron_charge);
    if ( choose["Events/Electron_cleanmask"] )
      input->select("Events/Electron_cleanmask", 	Electron_cleanmask);
    if ( choose["Events/Electron_convVeto"] )
      input->select("Events/Electron_convVeto", 	Electron_convVeto);
    if ( choose["Events/Electron_cutBased"] )
      input->select("Events/Electron_cutBased", 	Electron_cutBased);
    if ( choose["Events/Electron_cutBased_HEEP"] )
      input->select("Events/Electron_cutBased_HEEP",
                     Electron_cutBased_HEEP);
    if ( choose["Events/Electron_deltaEtaSC"] )
      input->select("Events/Electron_deltaEtaSC", 	Electron_deltaEtaSC);
    if ( choose["Events/Electron_dr03EcalRecHitSumEt"] )
      input->select("Events/Electron_dr03EcalRecHitSumEt",
                     Electron_dr03EcalRecHitSumEt);
    if ( choose["Events/Electron_dr03HcalDepth1TowerSumEt"] )
      input->select("Events/Electron_dr03HcalDepth1TowerSumEt",
                     Electron_dr03HcalDepth1TowerSumEt);
    if ( choose["Events/Electron_dr03TkSumPt"] )
      input->select("Events/Electron_dr03TkSumPt", 	Electron_dr03TkSumPt);
    if ( choose["Events/Electron_dxy"] )
      input->select("Events/Electron_dxy", 	Electron_dxy);
    if ( choose["Events/Electron_dxyErr"] )
      input->select("Events/Electron_dxyErr", 	Electron_dxyErr);
    if ( choose["Events/Electron_dz"] )
      input->select("Events/Electron_dz", 	Electron_dz);
    if ( choose["Events/Electron_dzErr"] )
      input->select("Events/Electron_dzErr", 	Electron_dzErr);
    if ( choose["Events/Electron_eCorr"] )
      input->select("Events/Electron_eCorr", 	Electron_eCorr);
    if ( choose["Events/Electron_eInvMinusPInv"] )
      input->select("Events/Electron_eInvMinusPInv",
                     Electron_eInvMinusPInv);
    if ( choose["Events/Electron_energyErr"] )
      input->select("Events/Electron_energyErr", 	Electron_energyErr);
    if ( choose["Events/Electron_eta"] )
      input->select("Events/Electron_eta", 	Electron_eta);
    if ( choose["Events/Electron_genPartFlav"] )
      input->select("Events/Electron_genPartFlav", 	Electron_genPartFlav);
    if ( choose["Events/Electron_genPartIdx"] )
      input->select("Events/Electron_genPartIdx", 	Electron_genPartIdx);
    if ( choose["Events/Electron_hoe"] )
      input->select("Events/Electron_hoe", 	Electron_hoe);
    if ( choose["Events/Electron_ip3d"] )
      input->select("Events/Electron_ip3d", 	Electron_ip3d);
    if ( choose["Events/Electron_isPFcand"] )
      input->select("Events/Electron_isPFcand", 	Electron_isPFcand);
    if ( choose["Events/Electron_jetIdx"] )
      input->select("Events/Electron_jetIdx", 	Electron_jetIdx);
    if ( choose["Events/Electron_lostHits"] )
      input->select("Events/Electron_lostHits", 	Electron_lostHits);
    if ( choose["Events/Electron_mass"] )
      input->select("Events/Electron_mass", 	Electron_mass);
    if ( choose["Events/Electron_miniPFRelIso_all"] )
      input->select("Events/Electron_miniPFRelIso_all",
                     Electron_miniPFRelIso_all);
    if ( choose["Events/Electron_miniPFRelIso_chg"] )
      input->select("Events/Electron_miniPFRelIso_chg",
                     Electron_miniPFRelIso_chg);
    if ( choose["Events/Electron_mvaFall17Iso"] )
      input->select("Events/Electron_mvaFall17Iso", 	Electron_mvaFall17Iso);
    if ( choose["Events/Electron_mvaFall17Iso_WP80"] )
      input->select("Events/Electron_mvaFall17Iso_WP80",
                     Electron_mvaFall17Iso_WP80);
    if ( choose["Events/Electron_mvaFall17Iso_WP90"] )
      input->select("Events/Electron_mvaFall17Iso_WP90",
                     Electron_mvaFall17Iso_WP90);
    if ( choose["Events/Electron_mvaFall17Iso_WPL"] )
      input->select("Events/Electron_mvaFall17Iso_WPL",
                     Electron_mvaFall17Iso_WPL);
    if ( choose["Events/Electron_mvaFall17noIso"] )
      input->select("Events/Electron_mvaFall17noIso",
                     Electron_mvaFall17noIso);
    if ( choose["Events/Electron_mvaFall17noIso_WP80"] )
      input->select("Events/Electron_mvaFall17noIso_WP80",
                     Electron_mvaFall17noIso_WP80);
    if ( choose["Events/Electron_mvaFall17noIso_WP90"] )
      input->select("Events/Electron_mvaFall17noIso_WP90",
                     Electron_mvaFall17noIso_WP90);
    if ( choose["Events/Electron_mvaFall17noIso_WPL"] )
      input->select("Events/Electron_mvaFall17noIso_WPL",
                     Electron_mvaFall17noIso_WPL);
    if ( choose["Events/Electron_mvaTTH"] )
      input->select("Events/Electron_mvaTTH", 	Electron_mvaTTH);
    if ( choose["Events/Electron_pdgId"] )
      input->select("Events/Electron_pdgId", 	Electron_pdgId);
    if ( choose["Events/Electron_pfRelIso03_all"] )
      input->select("Events/Electron_pfRelIso03_all",
                     Electron_pfRelIso03_all);
    if ( choose["Events/Electron_pfRelIso03_chg"] )
      input->select("Events/Electron_pfRelIso03_chg",
                     Electron_pfRelIso03_chg);
    if ( choose["Events/Electron_phi"] )
      input->select("Events/Electron_phi", 	Electron_phi);
    if ( choose["Events/Electron_photonIdx"] )
      input->select("Events/Electron_photonIdx", 	Electron_photonIdx);
    if ( choose["Events/Electron_pt"] )
      input->select("Events/Electron_pt", 	Electron_pt);
    if ( choose["Events/Electron_r9"] )
      input->select("Events/Electron_r9", 	Electron_r9);
    if ( choose["Events/Electron_sieie"] )
      input->select("Events/Electron_sieie", 	Electron_sieie);
    if ( choose["Events/Electron_sip3d"] )
      input->select("Events/Electron_sip3d", 	Electron_sip3d);
    if ( choose["Events/Electron_tightCharge"] )
      input->select("Events/Electron_tightCharge", 	Electron_tightCharge);
    if ( choose["Events/Electron_vidNestedWPBitmap"] )
      input->select("Events/Electron_vidNestedWPBitmap",
                     Electron_vidNestedWPBitmap);
    if ( choose["Events/FatJet_area"] )
      input->select("Events/FatJet_area", 	FatJet_area);
    if ( choose["Events/FatJet_btagCMVA"] )
      input->select("Events/FatJet_btagCMVA", 	FatJet_btagCMVA);
    if ( choose["Events/FatJet_btagCSVV2"] )
      input->select("Events/FatJet_btagCSVV2", 	FatJet_btagCSVV2);
    if ( choose["Events/FatJet_btagDeepB"] )
      input->select("Events/FatJet_btagDeepB", 	FatJet_btagDeepB);
    if ( choose["Events/FatJet_btagHbb"] )
      input->select("Events/FatJet_btagHbb", 	FatJet_btagHbb);
    if ( choose["Events/FatJet_eta"] )
      input->select("Events/FatJet_eta", 	FatJet_eta);
    if ( choose["Events/FatJet_jetId"] )
      input->select("Events/FatJet_jetId", 	FatJet_jetId);
    if ( choose["Events/FatJet_mass"] )
      input->select("Events/FatJet_mass", 	FatJet_mass);
    if ( choose["Events/FatJet_msoftdrop"] )
      input->select("Events/FatJet_msoftdrop", 	FatJet_msoftdrop);
    if ( choose["Events/FatJet_n2b1"] )
      input->select("Events/FatJet_n2b1", 	FatJet_n2b1);
    if ( choose["Events/FatJet_n3b1"] )
      input->select("Events/FatJet_n3b1", 	FatJet_n3b1);
    if ( choose["Events/FatJet_phi"] )
      input->select("Events/FatJet_phi", 	FatJet_phi);
    if ( choose["Events/FatJet_pt"] )
      input->select("Events/FatJet_pt", 	FatJet_pt);
    if ( choose["Events/FatJet_subJetIdx1"] )
      input->select("Events/FatJet_subJetIdx1", 	FatJet_subJetIdx1);
    if ( choose["Events/FatJet_subJetIdx2"] )
      input->select("Events/FatJet_subJetIdx2", 	FatJet_subJetIdx2);
    if ( choose["Events/FatJet_tau1"] )
      input->select("Events/FatJet_tau1", 	FatJet_tau1);
    if ( choose["Events/FatJet_tau2"] )
      input->select("Events/FatJet_tau2", 	FatJet_tau2);
    if ( choose["Events/FatJet_tau3"] )
      input->select("Events/FatJet_tau3", 	FatJet_tau3);
    if ( choose["Events/FatJet_tau4"] )
      input->select("Events/FatJet_tau4", 	FatJet_tau4);
    if ( choose["Events/Flag_BadChargedCandidateFilter"] )
      input->select("Events/Flag_BadChargedCandidateFilter",
                     Flag_BadChargedCandidateFilter);
    if ( choose["Events/Flag_BadChargedCandidateSummer16Filter"] )
      input->select("Events/Flag_BadChargedCandidateSummer16Filter",
                     Flag_BadChargedCandidateSummer16Filter);
    if ( choose["Events/Flag_BadPFMuonFilter"] )
      input->select("Events/Flag_BadPFMuonFilter", 	Flag_BadPFMuonFilter);
    if ( choose["Events/Flag_BadPFMuonSummer16Filter"] )
      input->select("Events/Flag_BadPFMuonSummer16Filter",
                     Flag_BadPFMuonSummer16Filter);
    if ( choose["Events/Flag_CSCTightHalo2015Filter"] )
      input->select("Events/Flag_CSCTightHalo2015Filter",
                     Flag_CSCTightHalo2015Filter);
    if ( choose["Events/Flag_CSCTightHaloFilter"] )
      input->select("Events/Flag_CSCTightHaloFilter",
                     Flag_CSCTightHaloFilter);
    if ( choose["Events/Flag_CSCTightHaloTrkMuUnvetoFilter"] )
      input->select("Events/Flag_CSCTightHaloTrkMuUnvetoFilter",
                     Flag_CSCTightHaloTrkMuUnvetoFilter);
    if ( choose["Events/Flag_EcalDeadCellBoundaryEnergyFilter"] )
      input->select("Events/Flag_EcalDeadCellBoundaryEnergyFilter",
                     Flag_EcalDeadCellBoundaryEnergyFilter);
    if ( choose["Events/Flag_EcalDeadCellTriggerPrimitiveFilter"] )
      input->select("Events/Flag_EcalDeadCellTriggerPrimitiveFilter",
                     Flag_EcalDeadCellTriggerPrimitiveFilter);
    if ( choose["Events/Flag_HBHENoiseFilter"] )
      input->select("Events/Flag_HBHENoiseFilter", 	Flag_HBHENoiseFilter);
    if ( choose["Events/Flag_HBHENoiseIsoFilter"] )
      input->select("Events/Flag_HBHENoiseIsoFilter",
                     Flag_HBHENoiseIsoFilter);
    if ( choose["Events/Flag_HcalStripHaloFilter"] )
      input->select("Events/Flag_HcalStripHaloFilter",
                     Flag_HcalStripHaloFilter);
    if ( choose["Events/Flag_METFilters"] )
      input->select("Events/Flag_METFilters", 	Flag_METFilters);
    if ( choose["Events/Flag_chargedHadronTrackResolutionFilter"] )
      input->select("Events/Flag_chargedHadronTrackResolutionFilter",
                     Flag_chargedHadronTrackResolutionFilter);
    if ( choose["Events/Flag_ecalBadCalibFilter"] )
      input->select("Events/Flag_ecalBadCalibFilter",
                     Flag_ecalBadCalibFilter);
    if ( choose["Events/Flag_ecalLaserCorrFilter"] )
      input->select("Events/Flag_ecalLaserCorrFilter",
                     Flag_ecalLaserCorrFilter);
    if ( choose["Events/Flag_eeBadScFilter"] )
      input->select("Events/Flag_eeBadScFilter", 	Flag_eeBadScFilter);
    if ( choose["Events/Flag_globalSuperTightHalo2016Filter"] )
      input->select("Events/Flag_globalSuperTightHalo2016Filter",
                     Flag_globalSuperTightHalo2016Filter);
    if ( choose["Events/Flag_globalTightHalo2016Filter"] )
      input->select("Events/Flag_globalTightHalo2016Filter",
                     Flag_globalTightHalo2016Filter);
    if ( choose["Events/Flag_goodVertices"] )
      input->select("Events/Flag_goodVertices", 	Flag_goodVertices);
    if ( choose["Events/Flag_hcalLaserEventFilter"] )
      input->select("Events/Flag_hcalLaserEventFilter",
                     Flag_hcalLaserEventFilter);
    if ( choose["Events/Flag_muonBadTrackFilter"] )
      input->select("Events/Flag_muonBadTrackFilter",
                     Flag_muonBadTrackFilter);
    if ( choose["Events/Flag_trkPOGFilters"] )
      input->select("Events/Flag_trkPOGFilters", 	Flag_trkPOGFilters);
    if ( choose["Events/Flag_trkPOG_logErrorTooManyClusters"] )
      input->select("Events/Flag_trkPOG_logErrorTooManyClusters",
                     Flag_trkPOG_logErrorTooManyClusters);
    if ( choose["Events/Flag_trkPOG_manystripclus53X"] )
      input->select("Events/Flag_trkPOG_manystripclus53X",
                     Flag_trkPOG_manystripclus53X);
    if ( choose["Events/Flag_trkPOG_toomanystripclus53X"] )
      input->select("Events/Flag_trkPOG_toomanystripclus53X",
                     Flag_trkPOG_toomanystripclus53X);
    if ( choose["Events/GenDressedLepton_eta"] )
      input->select("Events/GenDressedLepton_eta", 	GenDressedLepton_eta);
    if ( choose["Events/GenDressedLepton_mass"] )
      input->select("Events/GenDressedLepton_mass", 	GenDressedLepton_mass);
    if ( choose["Events/GenDressedLepton_pdgId"] )
      input->select("Events/GenDressedLepton_pdgId",
                     GenDressedLepton_pdgId);
    if ( choose["Events/GenDressedLepton_phi"] )
      input->select("Events/GenDressedLepton_phi", 	GenDressedLepton_phi);
    if ( choose["Events/GenDressedLepton_pt"] )
      input->select("Events/GenDressedLepton_pt", 	GenDressedLepton_pt);
    if ( choose["Events/GenJetAK8_eta"] )
      input->select("Events/GenJetAK8_eta", 	GenJetAK8_eta);
    if ( choose["Events/GenJetAK8_hadronFlavour"] )
      input->select("Events/GenJetAK8_hadronFlavour",
                     GenJetAK8_hadronFlavour);
    if ( choose["Events/GenJetAK8_mass"] )
      input->select("Events/GenJetAK8_mass", 	GenJetAK8_mass);
    if ( choose["Events/GenJetAK8_partonFlavour"] )
      input->select("Events/GenJetAK8_partonFlavour",
                     GenJetAK8_partonFlavour);
    if ( choose["Events/GenJetAK8_phi"] )
      input->select("Events/GenJetAK8_phi", 	GenJetAK8_phi);
    if ( choose["Events/GenJetAK8_pt"] )
      input->select("Events/GenJetAK8_pt", 	GenJetAK8_pt);
    if ( choose["Events/GenJet_eta"] )
      input->select("Events/GenJet_eta", 	GenJet_eta);
    if ( choose["Events/GenJet_hadronFlavour"] )
      input->select("Events/GenJet_hadronFlavour", 	GenJet_hadronFlavour);
    if ( choose["Events/GenJet_mass"] )
      input->select("Events/GenJet_mass", 	GenJet_mass);
    if ( choose["Events/GenJet_partonFlavour"] )
      input->select("Events/GenJet_partonFlavour", 	GenJet_partonFlavour);
    if ( choose["Events/GenJet_phi"] )
      input->select("Events/GenJet_phi", 	GenJet_phi);
    if ( choose["Events/GenJet_pt"] )
      input->select("Events/GenJet_pt", 	GenJet_pt);
    if ( choose["Events/GenMET_phi"] )
      input->select("Events/GenMET_phi", 	GenMET_phi);
    if ( choose["Events/GenMET_pt"] )
      input->select("Events/GenMET_pt", 	GenMET_pt);
    if ( choose["Events/GenPart_eta"] )
      input->select("Events/GenPart_eta", 	GenPart_eta);
    if ( choose["Events/GenPart_genPartIdxMother"] )
      input->select("Events/GenPart_genPartIdxMother",
                     GenPart_genPartIdxMother);
    if ( choose["Events/GenPart_mass"] )
      input->select("Events/GenPart_mass", 	GenPart_mass);
    if ( choose["Events/GenPart_pdgId"] )
      input->select("Events/GenPart_pdgId", 	GenPart_pdgId);
    if ( choose["Events/GenPart_phi"] )
      input->select("Events/GenPart_phi", 	GenPart_phi);
    if ( choose["Events/GenPart_pt"] )
      input->select("Events/GenPart_pt", 	GenPart_pt);
    if ( choose["Events/GenPart_status"] )
      input->select("Events/GenPart_status", 	GenPart_status);
    if ( choose["Events/GenPart_statusFlags"] )
      input->select("Events/GenPart_statusFlags", 	GenPart_statusFlags);
    if ( choose["Events/GenVisTau_charge"] )
      input->select("Events/GenVisTau_charge", 	GenVisTau_charge);
    if ( choose["Events/GenVisTau_eta"] )
      input->select("Events/GenVisTau_eta", 	GenVisTau_eta);
    if ( choose["Events/GenVisTau_genPartIdxMother"] )
      input->select("Events/GenVisTau_genPartIdxMother",
                     GenVisTau_genPartIdxMother);
    if ( choose["Events/GenVisTau_mass"] )
      input->select("Events/GenVisTau_mass", 	GenVisTau_mass);
    if ( choose["Events/GenVisTau_phi"] )
      input->select("Events/GenVisTau_phi", 	GenVisTau_phi);
    if ( choose["Events/GenVisTau_pt"] )
      input->select("Events/GenVisTau_pt", 	GenVisTau_pt);
    if ( choose["Events/GenVisTau_status"] )
      input->select("Events/GenVisTau_status", 	GenVisTau_status);
    if ( choose["Events/Generator_binvar"] )
      input->select("Events/Generator_binvar", 	Generator_binvar);
    if ( choose["Events/Generator_id1"] )
      input->select("Events/Generator_id1", 	Generator_id1);
    if ( choose["Events/Generator_id2"] )
      input->select("Events/Generator_id2", 	Generator_id2);
    if ( choose["Events/Generator_scalePDF"] )
      input->select("Events/Generator_scalePDF", 	Generator_scalePDF);
    if ( choose["Events/Generator_weight"] )
      input->select("Events/Generator_weight", 	Generator_weight);
    if ( choose["Events/Generator_x1"] )
      input->select("Events/Generator_x1", 	Generator_x1);
    if ( choose["Events/Generator_x2"] )
      input->select("Events/Generator_x2", 	Generator_x2);
    if ( choose["Events/Generator_xpdf1"] )
      input->select("Events/Generator_xpdf1", 	Generator_xpdf1);
    if ( choose["Events/Generator_xpdf2"] )
      input->select("Events/Generator_xpdf2", 	Generator_xpdf2);
    if ( choose["Events/HLT_AK4CaloJet100"] )
      input->select("Events/HLT_AK4CaloJet100", 	HLT_AK4CaloJet100);
    if ( choose["Events/HLT_AK4CaloJet120"] )
      input->select("Events/HLT_AK4CaloJet120", 	HLT_AK4CaloJet120);
    if ( choose["Events/HLT_AK4CaloJet30"] )
      input->select("Events/HLT_AK4CaloJet30", 	HLT_AK4CaloJet30);
    if ( choose["Events/HLT_AK4CaloJet40"] )
      input->select("Events/HLT_AK4CaloJet40", 	HLT_AK4CaloJet40);
    if ( choose["Events/HLT_AK4CaloJet50"] )
      input->select("Events/HLT_AK4CaloJet50", 	HLT_AK4CaloJet50);
    if ( choose["Events/HLT_AK4CaloJet80"] )
      input->select("Events/HLT_AK4CaloJet80", 	HLT_AK4CaloJet80);
    if ( choose["Events/HLT_AK4PFJet100"] )
      input->select("Events/HLT_AK4PFJet100", 	HLT_AK4PFJet100);
    if ( choose["Events/HLT_AK4PFJet120"] )
      input->select("Events/HLT_AK4PFJet120", 	HLT_AK4PFJet120);
    if ( choose["Events/HLT_AK4PFJet30"] )
      input->select("Events/HLT_AK4PFJet30", 	HLT_AK4PFJet30);
    if ( choose["Events/HLT_AK4PFJet50"] )
      input->select("Events/HLT_AK4PFJet50", 	HLT_AK4PFJet50);
    if ( choose["Events/HLT_AK4PFJet80"] )
      input->select("Events/HLT_AK4PFJet80", 	HLT_AK4PFJet80);
    if ( choose["Events/HLT_AK8PFHT750_TrimMass50"] )
      input->select("Events/HLT_AK8PFHT750_TrimMass50",
                     HLT_AK8PFHT750_TrimMass50);
    if ( choose["Events/HLT_AK8PFHT800_TrimMass50"] )
      input->select("Events/HLT_AK8PFHT800_TrimMass50",
                     HLT_AK8PFHT800_TrimMass50);
    if ( choose["Events/HLT_AK8PFHT850_TrimMass50"] )
      input->select("Events/HLT_AK8PFHT850_TrimMass50",
                     HLT_AK8PFHT850_TrimMass50);
    if ( choose["Events/HLT_AK8PFHT900_TrimMass50"] )
      input->select("Events/HLT_AK8PFHT900_TrimMass50",
                     HLT_AK8PFHT900_TrimMass50);
    if ( choose["Events/HLT_AK8PFJet140"] )
      input->select("Events/HLT_AK8PFJet140", 	HLT_AK8PFJet140);
    if ( choose["Events/HLT_AK8PFJet200"] )
      input->select("Events/HLT_AK8PFJet200", 	HLT_AK8PFJet200);
    if ( choose["Events/HLT_AK8PFJet260"] )
      input->select("Events/HLT_AK8PFJet260", 	HLT_AK8PFJet260);
    if ( choose["Events/HLT_AK8PFJet320"] )
      input->select("Events/HLT_AK8PFJet320", 	HLT_AK8PFJet320);
    if ( choose["Events/HLT_AK8PFJet330_PFAK8BTagCSV_p1"] )
      input->select("Events/HLT_AK8PFJet330_PFAK8BTagCSV_p1",
                     HLT_AK8PFJet330_PFAK8BTagCSV_p1);
    if ( choose["Events/HLT_AK8PFJet330_PFAK8BTagCSV_p17"] )
      input->select("Events/HLT_AK8PFJet330_PFAK8BTagCSV_p17",
                     HLT_AK8PFJet330_PFAK8BTagCSV_p17);
    if ( choose["Events/HLT_AK8PFJet360_TrimMass30"] )
      input->select("Events/HLT_AK8PFJet360_TrimMass30",
                     HLT_AK8PFJet360_TrimMass30);
    if ( choose["Events/HLT_AK8PFJet380_TrimMass30"] )
      input->select("Events/HLT_AK8PFJet380_TrimMass30",
                     HLT_AK8PFJet380_TrimMass30);
    if ( choose["Events/HLT_AK8PFJet40"] )
      input->select("Events/HLT_AK8PFJet40", 	HLT_AK8PFJet40);
    if ( choose["Events/HLT_AK8PFJet400"] )
      input->select("Events/HLT_AK8PFJet400", 	HLT_AK8PFJet400);
    if ( choose["Events/HLT_AK8PFJet400_TrimMass30"] )
      input->select("Events/HLT_AK8PFJet400_TrimMass30",
                     HLT_AK8PFJet400_TrimMass30);
    if ( choose["Events/HLT_AK8PFJet420_TrimMass30"] )
      input->select("Events/HLT_AK8PFJet420_TrimMass30",
                     HLT_AK8PFJet420_TrimMass30);
    if ( choose["Events/HLT_AK8PFJet450"] )
      input->select("Events/HLT_AK8PFJet450", 	HLT_AK8PFJet450);
    if ( choose["Events/HLT_AK8PFJet500"] )
      input->select("Events/HLT_AK8PFJet500", 	HLT_AK8PFJet500);
    if ( choose["Events/HLT_AK8PFJet550"] )
      input->select("Events/HLT_AK8PFJet550", 	HLT_AK8PFJet550);
    if ( choose["Events/HLT_AK8PFJet60"] )
      input->select("Events/HLT_AK8PFJet60", 	HLT_AK8PFJet60);
    if ( choose["Events/HLT_AK8PFJet80"] )
      input->select("Events/HLT_AK8PFJet80", 	HLT_AK8PFJet80);
    if ( choose["Events/HLT_AK8PFJetFwd140"] )
      input->select("Events/HLT_AK8PFJetFwd140", 	HLT_AK8PFJetFwd140);
    if ( choose["Events/HLT_AK8PFJetFwd200"] )
      input->select("Events/HLT_AK8PFJetFwd200", 	HLT_AK8PFJetFwd200);
    if ( choose["Events/HLT_AK8PFJetFwd260"] )
      input->select("Events/HLT_AK8PFJetFwd260", 	HLT_AK8PFJetFwd260);
    if ( choose["Events/HLT_AK8PFJetFwd320"] )
      input->select("Events/HLT_AK8PFJetFwd320", 	HLT_AK8PFJetFwd320);
    if ( choose["Events/HLT_AK8PFJetFwd40"] )
      input->select("Events/HLT_AK8PFJetFwd40", 	HLT_AK8PFJetFwd40);
    if ( choose["Events/HLT_AK8PFJetFwd400"] )
      input->select("Events/HLT_AK8PFJetFwd400", 	HLT_AK8PFJetFwd400);
    if ( choose["Events/HLT_AK8PFJetFwd450"] )
      input->select("Events/HLT_AK8PFJetFwd450", 	HLT_AK8PFJetFwd450);
    if ( choose["Events/HLT_AK8PFJetFwd500"] )
      input->select("Events/HLT_AK8PFJetFwd500", 	HLT_AK8PFJetFwd500);
    if ( choose["Events/HLT_AK8PFJetFwd60"] )
      input->select("Events/HLT_AK8PFJetFwd60", 	HLT_AK8PFJetFwd60);
    if ( choose["Events/HLT_AK8PFJetFwd80"] )
      input->select("Events/HLT_AK8PFJetFwd80", 	HLT_AK8PFJetFwd80);
    if ( choose["Events/HLT_BTagMu_AK4DiJet110_Mu5"] )
      input->select("Events/HLT_BTagMu_AK4DiJet110_Mu5",
                     HLT_BTagMu_AK4DiJet110_Mu5);
    if ( choose["Events/HLT_BTagMu_AK4DiJet170_Mu5"] )
      input->select("Events/HLT_BTagMu_AK4DiJet170_Mu5",
                     HLT_BTagMu_AK4DiJet170_Mu5);
    if ( choose["Events/HLT_BTagMu_AK4DiJet20_Mu5"] )
      input->select("Events/HLT_BTagMu_AK4DiJet20_Mu5",
                     HLT_BTagMu_AK4DiJet20_Mu5);
    if ( choose["Events/HLT_BTagMu_AK4DiJet40_Mu5"] )
      input->select("Events/HLT_BTagMu_AK4DiJet40_Mu5",
                     HLT_BTagMu_AK4DiJet40_Mu5);
    if ( choose["Events/HLT_BTagMu_AK4DiJet70_Mu5"] )
      input->select("Events/HLT_BTagMu_AK4DiJet70_Mu5",
                     HLT_BTagMu_AK4DiJet70_Mu5);
    if ( choose["Events/HLT_BTagMu_AK4Jet300_Mu5"] )
      input->select("Events/HLT_BTagMu_AK4Jet300_Mu5",
                     HLT_BTagMu_AK4Jet300_Mu5);
    if ( choose["Events/HLT_BTagMu_AK8DiJet170_Mu5"] )
      input->select("Events/HLT_BTagMu_AK8DiJet170_Mu5",
                     HLT_BTagMu_AK8DiJet170_Mu5);
    if ( choose["Events/HLT_BTagMu_AK8Jet300_Mu5"] )
      input->select("Events/HLT_BTagMu_AK8Jet300_Mu5",
                     HLT_BTagMu_AK8Jet300_Mu5);
    if ( choose["Events/HLT_CaloJet500_NoJetID"] )
      input->select("Events/HLT_CaloJet500_NoJetID",
                     HLT_CaloJet500_NoJetID);
    if ( choose["Events/HLT_CaloJet550_NoJetID"] )
      input->select("Events/HLT_CaloJet550_NoJetID",
                     HLT_CaloJet550_NoJetID);
    if ( choose["Events/HLT_CaloMET100_HBHECleaned"] )
      input->select("Events/HLT_CaloMET100_HBHECleaned",
                     HLT_CaloMET100_HBHECleaned);
    if ( choose["Events/HLT_CaloMET100_NotCleaned"] )
      input->select("Events/HLT_CaloMET100_NotCleaned",
                     HLT_CaloMET100_NotCleaned);
    if ( choose["Events/HLT_CaloMET110_NotCleaned"] )
      input->select("Events/HLT_CaloMET110_NotCleaned",
                     HLT_CaloMET110_NotCleaned);
    if ( choose["Events/HLT_CaloMET250_HBHECleaned"] )
      input->select("Events/HLT_CaloMET250_HBHECleaned",
                     HLT_CaloMET250_HBHECleaned);
    if ( choose["Events/HLT_CaloMET250_NotCleaned"] )
      input->select("Events/HLT_CaloMET250_NotCleaned",
                     HLT_CaloMET250_NotCleaned);
    if ( choose["Events/HLT_CaloMET300_HBHECleaned"] )
      input->select("Events/HLT_CaloMET300_HBHECleaned",
                     HLT_CaloMET300_HBHECleaned);
    if ( choose["Events/HLT_CaloMET350_HBHECleaned"] )
      input->select("Events/HLT_CaloMET350_HBHECleaned",
                     HLT_CaloMET350_HBHECleaned);
    if ( choose["Events/HLT_CaloMET70_HBHECleaned"] )
      input->select("Events/HLT_CaloMET70_HBHECleaned",
                     HLT_CaloMET70_HBHECleaned);
    if ( choose["Events/HLT_CaloMET80_HBHECleaned"] )
      input->select("Events/HLT_CaloMET80_HBHECleaned",
                     HLT_CaloMET80_HBHECleaned);
    if ( choose["Events/HLT_CaloMET80_NotCleaned"] )
      input->select("Events/HLT_CaloMET80_NotCleaned",
                     HLT_CaloMET80_NotCleaned);
    if ( choose["Events/HLT_CaloMET90_HBHECleaned"] )
      input->select("Events/HLT_CaloMET90_HBHECleaned",
                     HLT_CaloMET90_HBHECleaned);
    if ( choose["Events/HLT_CaloMET90_NotCleaned"] )
      input->select("Events/HLT_CaloMET90_NotCleaned",
                     HLT_CaloMET90_NotCleaned);
    if ( choose["Events/HLT_CaloMHT90"] )
      input->select("Events/HLT_CaloMHT90", 	HLT_CaloMHT90);
    if ( choose["Events/HLT_DiEle27_WPTightCaloOnly_L1DoubleEG"] )
      input->select("Events/HLT_DiEle27_WPTightCaloOnly_L1DoubleEG",
                     HLT_DiEle27_WPTightCaloOnly_L1DoubleEG);
    if ( choose["Events/HLT_DiJet110_35_Mjj650_PFMET110"] )
      input->select("Events/HLT_DiJet110_35_Mjj650_PFMET110",
                     HLT_DiJet110_35_Mjj650_PFMET110);
    if ( choose["Events/HLT_DiJet110_35_Mjj650_PFMET120"] )
      input->select("Events/HLT_DiJet110_35_Mjj650_PFMET120",
                     HLT_DiJet110_35_Mjj650_PFMET120);
    if ( choose["Events/HLT_DiJet110_35_Mjj650_PFMET130"] )
      input->select("Events/HLT_DiJet110_35_Mjj650_PFMET130",
                     HLT_DiJet110_35_Mjj650_PFMET130);
    if ( choose["Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL"] )
      input->select("Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL",
                     HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
    if ( choose["Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ"] )
      input->select("Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ",
                     HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
    if ( choose["Events/HLT_DiPFJet15_FBEta3_NoCaloMatched"] )
      input->select("Events/HLT_DiPFJet15_FBEta3_NoCaloMatched",
                     HLT_DiPFJet15_FBEta3_NoCaloMatched);
    if ( choose["Events/HLT_DiPFJet15_NoCaloMatched"] )
      input->select("Events/HLT_DiPFJet15_NoCaloMatched",
                     HLT_DiPFJet15_NoCaloMatched);
    if ( choose["Events/HLT_DiPFJet25_FBEta3_NoCaloMatched"] )
      input->select("Events/HLT_DiPFJet25_FBEta3_NoCaloMatched",
                     HLT_DiPFJet25_FBEta3_NoCaloMatched);
    if ( choose["Events/HLT_DiPFJet25_NoCaloMatched"] )
      input->select("Events/HLT_DiPFJet25_NoCaloMatched",
                     HLT_DiPFJet25_NoCaloMatched);
    if ( choose["Events/HLT_DiPFJetAve100_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve100_HFJEC",
                     HLT_DiPFJetAve100_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve140"] )
      input->select("Events/HLT_DiPFJetAve140", 	HLT_DiPFJetAve140);
    if ( choose["Events/HLT_DiPFJetAve15_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve15_HFJEC",
                     HLT_DiPFJetAve15_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve160_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve160_HFJEC",
                     HLT_DiPFJetAve160_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve200"] )
      input->select("Events/HLT_DiPFJetAve200", 	HLT_DiPFJetAve200);
    if ( choose["Events/HLT_DiPFJetAve220_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve220_HFJEC",
                     HLT_DiPFJetAve220_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve25_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve25_HFJEC",
                     HLT_DiPFJetAve25_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve260"] )
      input->select("Events/HLT_DiPFJetAve260", 	HLT_DiPFJetAve260);
    if ( choose["Events/HLT_DiPFJetAve300_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve300_HFJEC",
                     HLT_DiPFJetAve300_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve320"] )
      input->select("Events/HLT_DiPFJetAve320", 	HLT_DiPFJetAve320);
    if ( choose["Events/HLT_DiPFJetAve35_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve35_HFJEC",
                     HLT_DiPFJetAve35_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve40"] )
      input->select("Events/HLT_DiPFJetAve40", 	HLT_DiPFJetAve40);
    if ( choose["Events/HLT_DiPFJetAve400"] )
      input->select("Events/HLT_DiPFJetAve400", 	HLT_DiPFJetAve400);
    if ( choose["Events/HLT_DiPFJetAve500"] )
      input->select("Events/HLT_DiPFJetAve500", 	HLT_DiPFJetAve500);
    if ( choose["Events/HLT_DiPFJetAve60"] )
      input->select("Events/HLT_DiPFJetAve60", 	HLT_DiPFJetAve60);
    if ( choose["Events/HLT_DiPFJetAve60_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve60_HFJEC",
                     HLT_DiPFJetAve60_HFJEC);
    if ( choose["Events/HLT_DiPFJetAve80"] )
      input->select("Events/HLT_DiPFJetAve80", 	HLT_DiPFJetAve80);
    if ( choose["Events/HLT_DiPFJetAve80_HFJEC"] )
      input->select("Events/HLT_DiPFJetAve80_HFJEC",
                     HLT_DiPFJetAve80_HFJEC);
    if ( choose["Events/HLT_DiSC30_18_EIso_AND_HE_Mass70"] )
      input->select("Events/HLT_DiSC30_18_EIso_AND_HE_Mass70",
                     HLT_DiSC30_18_EIso_AND_HE_Mass70);
    if ( choose["Events/HLT_Dimuon0_Jpsi"] )
      input->select("Events/HLT_Dimuon0_Jpsi", 	HLT_Dimuon0_Jpsi);
    if ( choose["Events/HLT_Dimuon0_Jpsi3p5_Muon2"] )
      input->select("Events/HLT_Dimuon0_Jpsi3p5_Muon2",
                     HLT_Dimuon0_Jpsi3p5_Muon2);
    if ( choose["Events/HLT_Dimuon0_Jpsi_L1_4R_0er1p5R"] )
      input->select("Events/HLT_Dimuon0_Jpsi_L1_4R_0er1p5R",
                     HLT_Dimuon0_Jpsi_L1_4R_0er1p5R);
    if ( choose["Events/HLT_Dimuon0_Jpsi_L1_NoOS"] )
      input->select("Events/HLT_Dimuon0_Jpsi_L1_NoOS",
                     HLT_Dimuon0_Jpsi_L1_NoOS);
    if ( choose["Events/HLT_Dimuon0_Jpsi_NoVertexing"] )
      input->select("Events/HLT_Dimuon0_Jpsi_NoVertexing",
                     HLT_Dimuon0_Jpsi_NoVertexing);
    if ( choose["Events/HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R"] )
      input->select("Events/HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R",
                     HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R);
    if ( choose["Events/HLT_Dimuon0_Jpsi_NoVertexing_NoOS"] )
      input->select("Events/HLT_Dimuon0_Jpsi_NoVertexing_NoOS",
                     HLT_Dimuon0_Jpsi_NoVertexing_NoOS);
    if ( choose["Events/HLT_Dimuon0_LowMass"] )
      input->select("Events/HLT_Dimuon0_LowMass", 	HLT_Dimuon0_LowMass);
    if ( choose["Events/HLT_Dimuon0_LowMass_L1_0er1p5"] )
      input->select("Events/HLT_Dimuon0_LowMass_L1_0er1p5",
                     HLT_Dimuon0_LowMass_L1_0er1p5);
    if ( choose["Events/HLT_Dimuon0_LowMass_L1_0er1p5R"] )
      input->select("Events/HLT_Dimuon0_LowMass_L1_0er1p5R",
                     HLT_Dimuon0_LowMass_L1_0er1p5R);
    if ( choose["Events/HLT_Dimuon0_LowMass_L1_4"] )
      input->select("Events/HLT_Dimuon0_LowMass_L1_4",
                     HLT_Dimuon0_LowMass_L1_4);
    if ( choose["Events/HLT_Dimuon0_LowMass_L1_4R"] )
      input->select("Events/HLT_Dimuon0_LowMass_L1_4R",
                     HLT_Dimuon0_LowMass_L1_4R);
    if ( choose["Events/HLT_Dimuon0_LowMass_L1_TM530"] )
      input->select("Events/HLT_Dimuon0_LowMass_L1_TM530",
                     HLT_Dimuon0_LowMass_L1_TM530);
    if ( choose["Events/HLT_Dimuon0_Upsilon_L1_4p5"] )
      input->select("Events/HLT_Dimuon0_Upsilon_L1_4p5",
                     HLT_Dimuon0_Upsilon_L1_4p5);
    if ( choose["Events/HLT_Dimuon0_Upsilon_L1_4p5NoOS"] )
      input->select("Events/HLT_Dimuon0_Upsilon_L1_4p5NoOS",
                     HLT_Dimuon0_Upsilon_L1_4p5NoOS);
    if ( choose["Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0"] )
      input->select("Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0",
                     HLT_Dimuon0_Upsilon_L1_4p5er2p0);
    if ( choose["Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0M"] )
      input->select("Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0M",
                     HLT_Dimuon0_Upsilon_L1_4p5er2p0M);
    if ( choose["Events/HLT_Dimuon0_Upsilon_L1_5"] )
      input->select("Events/HLT_Dimuon0_Upsilon_L1_5",
                     HLT_Dimuon0_Upsilon_L1_5);
    if ( choose["Events/HLT_Dimuon0_Upsilon_L1_5M"] )
      input->select("Events/HLT_Dimuon0_Upsilon_L1_5M",
                     HLT_Dimuon0_Upsilon_L1_5M);
    if ( choose["Events/HLT_Dimuon0_Upsilon_Muon_L1_TM0"] )
      input->select("Events/HLT_Dimuon0_Upsilon_Muon_L1_TM0",
                     HLT_Dimuon0_Upsilon_Muon_L1_TM0);
    if ( choose["Events/HLT_Dimuon0_Upsilon_Muon_NoL1Mass"] )
      input->select("Events/HLT_Dimuon0_Upsilon_Muon_NoL1Mass",
                     HLT_Dimuon0_Upsilon_Muon_NoL1Mass);
    if ( choose["Events/HLT_Dimuon0_Upsilon_NoVertexing"] )
      input->select("Events/HLT_Dimuon0_Upsilon_NoVertexing",
                     HLT_Dimuon0_Upsilon_NoVertexing);
    if ( choose["Events/HLT_Dimuon10_PsiPrime_Barrel_Seagulls"] )
      input->select("Events/HLT_Dimuon10_PsiPrime_Barrel_Seagulls",
                     HLT_Dimuon10_PsiPrime_Barrel_Seagulls);
    if ( choose["Events/HLT_Dimuon10_Upsilon_Barrel_Seagulls"] )
      input->select("Events/HLT_Dimuon10_Upsilon_Barrel_Seagulls",
                     HLT_Dimuon10_Upsilon_Barrel_Seagulls);
    if ( choose["Events/HLT_Dimuon12_Upsilon_eta1p5"] )
      input->select("Events/HLT_Dimuon12_Upsilon_eta1p5",
                     HLT_Dimuon12_Upsilon_eta1p5);
    if ( choose["Events/HLT_Dimuon14_Phi_Barrel_Seagulls"] )
      input->select("Events/HLT_Dimuon14_Phi_Barrel_Seagulls",
                     HLT_Dimuon14_Phi_Barrel_Seagulls);
    if ( choose["Events/HLT_Dimuon18_PsiPrime"] )
      input->select("Events/HLT_Dimuon18_PsiPrime", 	HLT_Dimuon18_PsiPrime);
    if ( choose["Events/HLT_Dimuon18_PsiPrime_noCorrL1"] )
      input->select("Events/HLT_Dimuon18_PsiPrime_noCorrL1",
                     HLT_Dimuon18_PsiPrime_noCorrL1);
    if ( choose["Events/HLT_Dimuon20_Jpsi_Barrel_Seagulls"] )
      input->select("Events/HLT_Dimuon20_Jpsi_Barrel_Seagulls",
                     HLT_Dimuon20_Jpsi_Barrel_Seagulls);
    if ( choose["Events/HLT_Dimuon24_Phi_noCorrL1"] )
      input->select("Events/HLT_Dimuon24_Phi_noCorrL1",
                     HLT_Dimuon24_Phi_noCorrL1);
    if ( choose["Events/HLT_Dimuon24_Upsilon_noCorrL1"] )
      input->select("Events/HLT_Dimuon24_Upsilon_noCorrL1",
                     HLT_Dimuon24_Upsilon_noCorrL1);
    if ( choose["Events/HLT_Dimuon25_Jpsi"] )
      input->select("Events/HLT_Dimuon25_Jpsi", 	HLT_Dimuon25_Jpsi);
    if ( choose["Events/HLT_Dimuon25_Jpsi_noCorrL1"] )
      input->select("Events/HLT_Dimuon25_Jpsi_noCorrL1",
                     HLT_Dimuon25_Jpsi_noCorrL1);
    if ( choose["Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55"] )
      input->select("Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55",
                     HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
    if ( choose["Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55"] )
      input->select("Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55",
                     HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
    if ( choose["Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55"] )
      input->select("Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55",
                     HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
    if ( choose["Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55"] )
      input->select("Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55",
                     HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
    if ( choose["Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55"] )
      input->select("Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55",
                     HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
    if ( choose["Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55"] )
      input->select("Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55",
                     HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
    if ( choose["Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90"] )
      input->select("Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90",
                     HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90);
    if ( choose["Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95"] )
      input->select("Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95",
                     HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95);
    if ( choose["Events/HLT_DoubleEle24_eta2p1_WPTight_Gsf"] )
      input->select("Events/HLT_DoubleEle24_eta2p1_WPTight_Gsf",
                     HLT_DoubleEle24_eta2p1_WPTight_Gsf);
    if ( choose["Events/HLT_DoubleEle25_CaloIdL_MW"] )
      input->select("Events/HLT_DoubleEle25_CaloIdL_MW",
                     HLT_DoubleEle25_CaloIdL_MW);
    if ( choose["Events/HLT_DoubleEle27_CaloIdL_MW"] )
      input->select("Events/HLT_DoubleEle27_CaloIdL_MW",
                     HLT_DoubleEle27_CaloIdL_MW);
    if ( choose["Events/HLT_DoubleEle33_CaloIdL_MW"] )
      input->select("Events/HLT_DoubleEle33_CaloIdL_MW",
                     HLT_DoubleEle33_CaloIdL_MW);
    if ( choose["Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350"] )
      input->select("Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350",
                     HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350);
    if ( choose["Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350"] )
      input->select("Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350",
                     HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350);
    if ( choose["Events/HLT_DoubleIsoMu20_eta2p1"] )
      input->select("Events/HLT_DoubleIsoMu20_eta2p1",
                     HLT_DoubleIsoMu20_eta2p1);
    if ( choose["Events/HLT_DoubleIsoMu24_eta2p1"] )
      input->select("Events/HLT_DoubleIsoMu24_eta2p1",
                     HLT_DoubleIsoMu24_eta2p1);
    if ( choose["Events/HLT_DoubleL2Mu50"] )
      input->select("Events/HLT_DoubleL2Mu50", 	HLT_DoubleL2Mu50);
    if ( choose["Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg",
                     HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg",
                     HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg",
                     HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg",
                     HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg",
                     HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg",
                     HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg",
                     HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg",
                     HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4"] )
      input->select("Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4",
                     HLT_DoubleMu20_7_Mass0to30_L1_DM4);
    if ( choose["Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4EG"] )
      input->select("Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4EG",
                     HLT_DoubleMu20_7_Mass0to30_L1_DM4EG);
    if ( choose["Events/HLT_DoubleMu20_7_Mass0to30_Photon23"] )
      input->select("Events/HLT_DoubleMu20_7_Mass0to30_Photon23",
                     HLT_DoubleMu20_7_Mass0to30_Photon23);
    if ( choose["Events/HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi"] )
      input->select("Events/HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi",
                     HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi);
    if ( choose["Events/HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi"] )
      input->select("Events/HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi",
                     HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi);
    if ( choose["Events/HLT_DoubleMu3_DCA_PFMET50_PFMHT60"] )
      input->select("Events/HLT_DoubleMu3_DCA_PFMET50_PFMHT60",
                     HLT_DoubleMu3_DCA_PFMET50_PFMHT60);
    if ( choose["Events/HLT_DoubleMu3_DZ_PFMET50_PFMHT60"] )
      input->select("Events/HLT_DoubleMu3_DZ_PFMET50_PFMHT60",
                     HLT_DoubleMu3_DZ_PFMET50_PFMHT60);
    if ( choose["Events/HLT_DoubleMu3_DZ_PFMET70_PFMHT70"] )
      input->select("Events/HLT_DoubleMu3_DZ_PFMET70_PFMHT70",
                     HLT_DoubleMu3_DZ_PFMET70_PFMHT70);
    if ( choose["Events/HLT_DoubleMu3_DZ_PFMET90_PFMHT90"] )
      input->select("Events/HLT_DoubleMu3_DZ_PFMET90_PFMHT90",
                     HLT_DoubleMu3_DZ_PFMET90_PFMHT90);
    if ( choose["Events/HLT_DoubleMu3_Trk_Tau3mu"] )
      input->select("Events/HLT_DoubleMu3_Trk_Tau3mu",
                     HLT_DoubleMu3_Trk_Tau3mu);
    if ( choose["Events/HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass"] )
      input->select("Events/HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass",
                     HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass);
    if ( choose["Events/HLT_DoubleMu43NoFiltersNoVtx"] )
      input->select("Events/HLT_DoubleMu43NoFiltersNoVtx",
                     HLT_DoubleMu43NoFiltersNoVtx);
    if ( choose["Events/HLT_DoubleMu48NoFiltersNoVtx"] )
      input->select("Events/HLT_DoubleMu48NoFiltersNoVtx",
                     HLT_DoubleMu48NoFiltersNoVtx);
    if ( choose["Events/HLT_DoubleMu4_3_Bs"] )
      input->select("Events/HLT_DoubleMu4_3_Bs", 	HLT_DoubleMu4_3_Bs);
    if ( choose["Events/HLT_DoubleMu4_3_Jpsi_Displaced"] )
      input->select("Events/HLT_DoubleMu4_3_Jpsi_Displaced",
                     HLT_DoubleMu4_3_Jpsi_Displaced);
    if ( choose["Events/HLT_DoubleMu4_JpsiTrkTrk_Displaced"] )
      input->select("Events/HLT_DoubleMu4_JpsiTrkTrk_Displaced",
                     HLT_DoubleMu4_JpsiTrkTrk_Displaced);
    if ( choose["Events/HLT_DoubleMu4_JpsiTrk_Displaced"] )
      input->select("Events/HLT_DoubleMu4_JpsiTrk_Displaced",
                     HLT_DoubleMu4_JpsiTrk_Displaced);
    if ( choose["Events/HLT_DoubleMu4_Jpsi_Displaced"] )
      input->select("Events/HLT_DoubleMu4_Jpsi_Displaced",
                     HLT_DoubleMu4_Jpsi_Displaced);
    if ( choose["Events/HLT_DoubleMu4_Jpsi_NoVertexing"] )
      input->select("Events/HLT_DoubleMu4_Jpsi_NoVertexing",
                     HLT_DoubleMu4_Jpsi_NoVertexing);
    if ( choose["Events/HLT_DoubleMu4_LowMassNonResonantTrk_Displaced"] )
      input->select("Events/HLT_DoubleMu4_LowMassNonResonantTrk_Displaced",
                     HLT_DoubleMu4_LowMassNonResonantTrk_Displaced);
    if ( choose["Events/HLT_DoubleMu4_Mass8_DZ_PFHT350"] )
      input->select("Events/HLT_DoubleMu4_Mass8_DZ_PFHT350",
                     HLT_DoubleMu4_Mass8_DZ_PFHT350);
    if ( choose["Events/HLT_DoubleMu4_PsiPrimeTrk_Displaced"] )
      input->select("Events/HLT_DoubleMu4_PsiPrimeTrk_Displaced",
                     HLT_DoubleMu4_PsiPrimeTrk_Displaced);
    if ( choose["Events/HLT_DoubleMu8_Mass8_PFHT350"] )
      input->select("Events/HLT_DoubleMu8_Mass8_PFHT350",
                     HLT_DoubleMu8_Mass8_PFHT350);
    if ( choose["Events/HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33"] )
      input->select("Events/HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33",
                     HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33);
    if ( choose["Events/HLT_DoublePFJets100_CaloBTagCSV_p33"] )
      input->select("Events/HLT_DoublePFJets100_CaloBTagCSV_p33",
                     HLT_DoublePFJets100_CaloBTagCSV_p33);
    if ( choose["Events/HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33"] )
      input->select("Events/HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33",
                     HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33);
    if ( choose["Events/HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33"] )
      input->select("Events/HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33",
                     HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33);
    if ( choose["Events/HLT_DoublePFJets200_CaloBTagCSV_p33"] )
      input->select("Events/HLT_DoublePFJets200_CaloBTagCSV_p33",
                     HLT_DoublePFJets200_CaloBTagCSV_p33);
    if ( choose["Events/HLT_DoublePFJets350_CaloBTagCSV_p33"] )
      input->select("Events/HLT_DoublePFJets350_CaloBTagCSV_p33",
                     HLT_DoublePFJets350_CaloBTagCSV_p33);
    if ( choose["Events/HLT_DoublePFJets40_CaloBTagCSV_p33"] )
      input->select("Events/HLT_DoublePFJets40_CaloBTagCSV_p33",
                     HLT_DoublePFJets40_CaloBTagCSV_p33);
    if ( choose["Events/HLT_DoublePhoton33_CaloIdL"] )
      input->select("Events/HLT_DoublePhoton33_CaloIdL",
                     HLT_DoublePhoton33_CaloIdL);
    if ( choose["Events/HLT_DoublePhoton70"] )
      input->select("Events/HLT_DoublePhoton70", 	HLT_DoublePhoton70);
    if ( choose["Events/HLT_DoublePhoton85"] )
      input->select("Events/HLT_DoublePhoton85", 	HLT_DoublePhoton85);
    if ( choose["Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg",
                     HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg",
                     HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg",
                     HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
    if ( choose["Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg",
                     HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_ECALHT800"] )
      input->select("Events/HLT_ECALHT800", 	HLT_ECALHT800);
    if ( choose["Events/HLT_EcalCalibration"] )
      input->select("Events/HLT_EcalCalibration", 	HLT_EcalCalibration);
    if ( choose["Events/HLT_Ele115_CaloIdVT_GsfTrkIdT"] )
      input->select("Events/HLT_Ele115_CaloIdVT_GsfTrkIdT",
                     HLT_Ele115_CaloIdVT_GsfTrkIdT);
    if ( choose["Events/HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30"] )
      input->select("Events/HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30",
                     HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
    if ( choose["Events/HLT_Ele135_CaloIdVT_GsfTrkIdT"] )
      input->select("Events/HLT_Ele135_CaloIdVT_GsfTrkIdT",
                     HLT_Ele135_CaloIdVT_GsfTrkIdT);
    if ( choose["Events/HLT_Ele145_CaloIdVT_GsfTrkIdT"] )
      input->select("Events/HLT_Ele145_CaloIdVT_GsfTrkIdT",
                     HLT_Ele145_CaloIdVT_GsfTrkIdT);
    if ( choose["Events/HLT_Ele15_IsoVVVL_PFHT450"] )
      input->select("Events/HLT_Ele15_IsoVVVL_PFHT450",
                     HLT_Ele15_IsoVVVL_PFHT450);
    if ( choose["Events/HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5"] )
      input->select("Events/HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5",
                     HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5);
    if ( choose["Events/HLT_Ele15_IsoVVVL_PFHT450_PFMET50"] )
      input->select("Events/HLT_Ele15_IsoVVVL_PFHT450_PFMET50",
                     HLT_Ele15_IsoVVVL_PFHT450_PFMET50);
    if ( choose["Events/HLT_Ele15_IsoVVVL_PFHT600"] )
      input->select("Events/HLT_Ele15_IsoVVVL_PFHT600",
                     HLT_Ele15_IsoVVVL_PFHT600);
    if ( choose["Events/HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL"] )
      input->select("Events/HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL",
                     HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
    if ( choose["Events/HLT_Ele17_CaloIdM_TrackIdM_PFJet30"] )
      input->select("Events/HLT_Ele17_CaloIdM_TrackIdM_PFJet30",
                     HLT_Ele17_CaloIdM_TrackIdM_PFJet30);
    if ( choose["Events/HLT_Ele200_CaloIdVT_GsfTrkIdT"] )
      input->select("Events/HLT_Ele200_CaloIdVT_GsfTrkIdT",
                     HLT_Ele200_CaloIdVT_GsfTrkIdT);
    if ( choose["Events/HLT_Ele20_WPLoose_Gsf"] )
      input->select("Events/HLT_Ele20_WPLoose_Gsf", 	HLT_Ele20_WPLoose_Gsf);
    if ( choose["Events/HLT_Ele20_WPTight_Gsf"] )
      input->select("Events/HLT_Ele20_WPTight_Gsf", 	HLT_Ele20_WPTight_Gsf);
    if ( choose["Events/HLT_Ele20_eta2p1_WPLoose_Gsf"] )
      input->select("Events/HLT_Ele20_eta2p1_WPLoose_Gsf",
                     HLT_Ele20_eta2p1_WPLoose_Gsf);
    if ( choose["Events/HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30"] )
      input->select("Events/HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30",
                     HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
    if ( choose["Events/HLT_Ele23_CaloIdM_TrackIdM_PFJet30"] )
      input->select("Events/HLT_Ele23_CaloIdM_TrackIdM_PFJet30",
                     HLT_Ele23_CaloIdM_TrackIdM_PFJet30);
    if ( choose["Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"] )
      input->select("Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL",
                     HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
    if ( choose["Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"] )
      input->select("Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ",
                     HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    if ( choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1"] )
      input->select("Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1",
                     HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1);
    if ( choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1"] )
      input->select("Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1",
                     HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1);
    if ( choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1"] )
      input->select("Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1",
                     HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1);
    if ( choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1"] )
      input->select("Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1",
                     HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1);
    if ( choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1"] )
      input->select("Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1",
                     HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1);
    if ( choose["Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1"] )
      input->select("Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1",
                     HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1);
    if ( choose["Events/HLT_Ele250_CaloIdVT_GsfTrkIdT"] )
      input->select("Events/HLT_Ele250_CaloIdVT_GsfTrkIdT",
                     HLT_Ele250_CaloIdVT_GsfTrkIdT);
    if ( choose["Events/HLT_Ele27_Ele37_CaloIdL_MW"] )
      input->select("Events/HLT_Ele27_Ele37_CaloIdL_MW",
                     HLT_Ele27_Ele37_CaloIdL_MW);
    if ( choose["Events/HLT_Ele27_WPTight_Gsf"] )
      input->select("Events/HLT_Ele27_WPTight_Gsf", 	HLT_Ele27_WPTight_Gsf);
    if ( choose["Events/HLT_Ele28_HighEta_SC20_Mass55"] )
      input->select("Events/HLT_Ele28_HighEta_SC20_Mass55",
                     HLT_Ele28_HighEta_SC20_Mass55);
    if ( choose["Events/HLT_Ele28_eta2p1_WPTight_Gsf_HT150"] )
      input->select("Events/HLT_Ele28_eta2p1_WPTight_Gsf_HT150",
                     HLT_Ele28_eta2p1_WPTight_Gsf_HT150);
    if ( choose["Events/HLT_Ele300_CaloIdVT_GsfTrkIdT"] )
      input->select("Events/HLT_Ele300_CaloIdVT_GsfTrkIdT",
                     HLT_Ele300_CaloIdVT_GsfTrkIdT);
    if ( choose["Events/HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned"] )
      input->select("Events/HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned",
                     HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned);
    if ( choose["Events/HLT_Ele32_WPTight_Gsf"] )
      input->select("Events/HLT_Ele32_WPTight_Gsf", 	HLT_Ele32_WPTight_Gsf);
    if ( choose["Events/HLT_Ele32_WPTight_Gsf_L1DoubleEG"] )
      input->select("Events/HLT_Ele32_WPTight_Gsf_L1DoubleEG",
                     HLT_Ele32_WPTight_Gsf_L1DoubleEG);
    if ( choose["Events/HLT_Ele35_WPTight_Gsf"] )
      input->select("Events/HLT_Ele35_WPTight_Gsf", 	HLT_Ele35_WPTight_Gsf);
    if ( choose["Events/HLT_Ele35_WPTight_Gsf_L1EGMT"] )
      input->select("Events/HLT_Ele35_WPTight_Gsf_L1EGMT",
                     HLT_Ele35_WPTight_Gsf_L1EGMT);
    if ( choose["Events/HLT_Ele38_WPTight_Gsf"] )
      input->select("Events/HLT_Ele38_WPTight_Gsf", 	HLT_Ele38_WPTight_Gsf);
    if ( choose["Events/HLT_Ele40_WPTight_Gsf"] )
      input->select("Events/HLT_Ele40_WPTight_Gsf", 	HLT_Ele40_WPTight_Gsf);
    if ( choose["Events/HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165"] )
      input->select("Events/HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165",
                     HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165);
    if ( choose["Events/HLT_Ele50_IsoVVVL_PFHT450"] )
      input->select("Events/HLT_Ele50_IsoVVVL_PFHT450",
                     HLT_Ele50_IsoVVVL_PFHT450);
    if ( choose["Events/HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30"] )
      input->select("Events/HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30",
                     HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30);
    if ( choose["Events/HLT_Ele8_CaloIdM_TrackIdM_PFJet30"] )
      input->select("Events/HLT_Ele8_CaloIdM_TrackIdM_PFJet30",
                     HLT_Ele8_CaloIdM_TrackIdM_PFJet30);
    if ( choose["Events/HLT_FullTrack_Multiplicity100"] )
      input->select("Events/HLT_FullTrack_Multiplicity100",
                     HLT_FullTrack_Multiplicity100);
    if ( choose["Events/HLT_FullTrack_Multiplicity130"] )
      input->select("Events/HLT_FullTrack_Multiplicity130",
                     HLT_FullTrack_Multiplicity130);
    if ( choose["Events/HLT_FullTrack_Multiplicity155"] )
      input->select("Events/HLT_FullTrack_Multiplicity155",
                     HLT_FullTrack_Multiplicity155);
    if ( choose["Events/HLT_FullTrack_Multiplicity85"] )
      input->select("Events/HLT_FullTrack_Multiplicity85",
                     HLT_FullTrack_Multiplicity85);
    if ( choose["Events/HLT_HISinglePhoton10_Eta3p1ForPPRef"] )
      input->select("Events/HLT_HISinglePhoton10_Eta3p1ForPPRef",
                     HLT_HISinglePhoton10_Eta3p1ForPPRef);
    if ( choose["Events/HLT_HISinglePhoton20_Eta3p1ForPPRef"] )
      input->select("Events/HLT_HISinglePhoton20_Eta3p1ForPPRef",
                     HLT_HISinglePhoton20_Eta3p1ForPPRef);
    if ( choose["Events/HLT_HISinglePhoton30_Eta3p1ForPPRef"] )
      input->select("Events/HLT_HISinglePhoton30_Eta3p1ForPPRef",
                     HLT_HISinglePhoton30_Eta3p1ForPPRef);
    if ( choose["Events/HLT_HISinglePhoton40_Eta3p1ForPPRef"] )
      input->select("Events/HLT_HISinglePhoton40_Eta3p1ForPPRef",
                     HLT_HISinglePhoton40_Eta3p1ForPPRef);
    if ( choose["Events/HLT_HISinglePhoton50_Eta3p1ForPPRef"] )
      input->select("Events/HLT_HISinglePhoton50_Eta3p1ForPPRef",
                     HLT_HISinglePhoton50_Eta3p1ForPPRef);
    if ( choose["Events/HLT_HISinglePhoton60_Eta3p1ForPPRef"] )
      input->select("Events/HLT_HISinglePhoton60_Eta3p1ForPPRef",
                     HLT_HISinglePhoton60_Eta3p1ForPPRef);
    if ( choose["Events/HLT_HT300_Beamspot"] )
      input->select("Events/HLT_HT300_Beamspot", 	HLT_HT300_Beamspot);
    if ( choose["Events/HLT_HT400_DisplacedDijet40_DisplacedTrack"] )
      input->select("Events/HLT_HT400_DisplacedDijet40_DisplacedTrack",
                     HLT_HT400_DisplacedDijet40_DisplacedTrack);
    if ( choose["Events/HLT_HT425"] )
      input->select("Events/HLT_HT425", 	HLT_HT425);
    if ( choose["Events/HLT_HT430_DisplacedDijet40_DisplacedTrack"] )
      input->select("Events/HLT_HT430_DisplacedDijet40_DisplacedTrack",
                     HLT_HT430_DisplacedDijet40_DisplacedTrack);
    if ( choose["Events/HLT_HT430_DisplacedDijet60_DisplacedTrack"] )
      input->select("Events/HLT_HT430_DisplacedDijet60_DisplacedTrack",
                     HLT_HT430_DisplacedDijet60_DisplacedTrack);
    if ( choose["Events/HLT_HT430_DisplacedDijet80_DisplacedTrack"] )
      input->select("Events/HLT_HT430_DisplacedDijet80_DisplacedTrack",
                     HLT_HT430_DisplacedDijet80_DisplacedTrack);
    if ( choose["Events/HLT_HT450_Beamspot"] )
      input->select("Events/HLT_HT450_Beamspot", 	HLT_HT450_Beamspot);
    if ( choose["Events/HLT_HT550_DisplacedDijet60_Inclusive"] )
      input->select("Events/HLT_HT550_DisplacedDijet60_Inclusive",
                     HLT_HT550_DisplacedDijet60_Inclusive);
    if ( choose["Events/HLT_HT550_DisplacedDijet80_Inclusive"] )
      input->select("Events/HLT_HT550_DisplacedDijet80_Inclusive",
                     HLT_HT550_DisplacedDijet80_Inclusive);
    if ( choose["Events/HLT_HT650_DisplacedDijet60_Inclusive"] )
      input->select("Events/HLT_HT650_DisplacedDijet60_Inclusive",
                     HLT_HT650_DisplacedDijet60_Inclusive);
    if ( choose["Events/HLT_HT650_DisplacedDijet80_Inclusive"] )
      input->select("Events/HLT_HT650_DisplacedDijet80_Inclusive",
                     HLT_HT650_DisplacedDijet80_Inclusive);
    if ( choose["Events/HLT_HT750_DisplacedDijet80_Inclusive"] )
      input->select("Events/HLT_HT750_DisplacedDijet80_Inclusive",
                     HLT_HT750_DisplacedDijet80_Inclusive);
    if ( choose["Events/HLT_HcalCalibration"] )
      input->select("Events/HLT_HcalCalibration", 	HLT_HcalCalibration);
    if ( choose["Events/HLT_HcalIsolatedbunch"] )
      input->select("Events/HLT_HcalIsolatedbunch", 	HLT_HcalIsolatedbunch);
    if ( choose["Events/HLT_HcalNZS"] )
      input->select("Events/HLT_HcalNZS", 	HLT_HcalNZS);
    if ( choose["Events/HLT_HcalPhiSym"] )
      input->select("Events/HLT_HcalPhiSym", 	HLT_HcalPhiSym);
    if ( choose["Events/HLT_IsoMu20"] )
      input->select("Events/HLT_IsoMu20", 	HLT_IsoMu20);
    if ( choose["Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1"] )
      input->select("Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1",
                     HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1);
    if ( choose["Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1"] )
      input->select("Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1",
                     HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1);
    if ( choose["Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1"] )
      input->select("Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1",
                     HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1);
    if ( choose["Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1"] )
      input->select("Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1",
                     HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1);
    if ( choose["Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1"] )
      input->select("Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1",
                     HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1);
    if ( choose["Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1"] )
      input->select("Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1",
                     HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1);
    if ( choose["Events/HLT_IsoMu24"] )
      input->select("Events/HLT_IsoMu24", 	HLT_IsoMu24);
    if ( choose["Events/HLT_IsoMu24_eta2p1"] )
      input->select("Events/HLT_IsoMu24_eta2p1", 	HLT_IsoMu24_eta2p1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1",
                     HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1",
                     HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1",
                     HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1",
                     HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr"] )
      input->select("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr",
                     HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
    if ( choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1",
                     HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1",
                     HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1"] )
      input->select("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1",
                     HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1);
    if ( choose["Events/HLT_IsoMu27"] )
      input->select("Events/HLT_IsoMu27", 	HLT_IsoMu27);
    if ( choose["Events/HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1"] )
      input->select("Events/HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1",
                     HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1);
    if ( choose["Events/HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1"] )
      input->select("Events/HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1",
                     HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1);
    if ( choose["Events/HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1"] )
      input->select("Events/HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1",
                     HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1);
    if ( choose["Events/HLT_IsoMu30"] )
      input->select("Events/HLT_IsoMu30", 	HLT_IsoMu30);
    if ( choose["Events/HLT_IsoTrackHB"] )
      input->select("Events/HLT_IsoTrackHB", 	HLT_IsoTrackHB);
    if ( choose["Events/HLT_IsoTrackHE"] )
      input->select("Events/HLT_IsoTrackHE", 	HLT_IsoTrackHE);
    if ( choose["Events/HLT_L1ETMHadSeeds"] )
      input->select("Events/HLT_L1ETMHadSeeds", 	HLT_L1ETMHadSeeds);
    if ( choose["Events/HLT_L1MinimumBiasHF0OR"] )
      input->select("Events/HLT_L1MinimumBiasHF0OR",
                     HLT_L1MinimumBiasHF0OR);
    if ( choose["Events/HLT_L1MinimumBiasHF_OR"] )
      input->select("Events/HLT_L1MinimumBiasHF_OR",
                     HLT_L1MinimumBiasHF_OR);
    if ( choose["Events/HLT_L1NotBptxOR"] )
      input->select("Events/HLT_L1NotBptxOR", 	HLT_L1NotBptxOR);
    if ( choose["Events/HLT_L1SingleMu18"] )
      input->select("Events/HLT_L1SingleMu18", 	HLT_L1SingleMu18);
    if ( choose["Events/HLT_L1SingleMu25"] )
      input->select("Events/HLT_L1SingleMu25", 	HLT_L1SingleMu25);
    if ( choose["Events/HLT_L1UnpairedBunchBptxMinus"] )
      input->select("Events/HLT_L1UnpairedBunchBptxMinus",
                     HLT_L1UnpairedBunchBptxMinus);
    if ( choose["Events/HLT_L1UnpairedBunchBptxPlus"] )
      input->select("Events/HLT_L1UnpairedBunchBptxPlus",
                     HLT_L1UnpairedBunchBptxPlus);
    if ( choose["Events/HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142"] )
      input->select("Events/HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142",
                     HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142);
    if ( choose["Events/HLT_L1_DoubleJet30_Mass_Min400_Mu10"] )
      input->select("Events/HLT_L1_DoubleJet30_Mass_Min400_Mu10",
                     HLT_L1_DoubleJet30_Mass_Min400_Mu10);
    if ( choose["Events/HLT_L2Mu10"] )
      input->select("Events/HLT_L2Mu10", 	HLT_L2Mu10);
    if ( choose["Events/HLT_L2Mu10_NoVertex_NoBPTX"] )
      input->select("Events/HLT_L2Mu10_NoVertex_NoBPTX",
                     HLT_L2Mu10_NoVertex_NoBPTX);
    if ( choose["Events/HLT_L2Mu10_NoVertex_NoBPTX3BX"] )
      input->select("Events/HLT_L2Mu10_NoVertex_NoBPTX3BX",
                     HLT_L2Mu10_NoVertex_NoBPTX3BX);
    if ( choose["Events/HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX"] )
      input->select("Events/HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX",
                     HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX);
    if ( choose["Events/HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX"] )
      input->select("Events/HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX",
                     HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX);
    if ( choose["Events/HLT_L2Mu50"] )
      input->select("Events/HLT_L2Mu50", 	HLT_L2Mu50);
    if ( choose["Events/HLT_MET105_IsoTrk50"] )
      input->select("Events/HLT_MET105_IsoTrk50", 	HLT_MET105_IsoTrk50);
    if ( choose["Events/HLT_MET120_IsoTrk50"] )
      input->select("Events/HLT_MET120_IsoTrk50", 	HLT_MET120_IsoTrk50);
    if ( choose["Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1"] )
      input->select("Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1",
                     HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1);
    if ( choose["Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr"] )
      input->select("Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr",
                     HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr);
    if ( choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr"] )
      input->select("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr",
                     HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
    if ( choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100"] )
      input->select("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100",
                     HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100);
    if ( choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110"] )
      input->select("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110",
                     HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110);
    if ( choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120"] )
      input->select("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120",
                     HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120);
    if ( choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130"] )
      input->select("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130",
                     HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130);
    if ( choose["Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90"] )
      input->select("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90",
                     HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90);
    if ( choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight"] )
      input->select("Events/HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight",
                     HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight);
    if ( choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight"] )
      input->select("Events/HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight",
                     HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
    if ( choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight"] )
      input->select("Events/HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight",
                     HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight);
    if ( choose["Events/HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight"] )
      input->select("Events/HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight",
                     HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight);
    if ( choose["Events/HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60"] )
      input->select("Events/HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60",
                     HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60);
    if ( choose["Events/HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33"] )
      input->select("Events/HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33",
                     HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33);
    if ( choose["Events/HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33"] )
      input->select("Events/HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33",
                     HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33);
    if ( choose["Events/HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33"] )
      input->select("Events/HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33",
                     HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33);
    if ( choose["Events/HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33"] )
      input->select("Events/HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33",
                     HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33);
    if ( choose["Events/HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33"] )
      input->select("Events/HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33",
                     HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33);
    if ( choose["Events/HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33"] )
      input->select("Events/HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33",
                     HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33);
    if ( choose["Events/HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33"] )
      input->select("Events/HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33",
                     HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33);
    if ( choose["Events/HLT_Mu12_DoublePhoton20"] )
      input->select("Events/HLT_Mu12_DoublePhoton20",
                     HLT_Mu12_DoublePhoton20);
    if ( choose["Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"] )
      input->select("Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL",
                     HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
    if ( choose["Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"] )
      input->select("Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ",
                     HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
    if ( choose["Events/HLT_Mu15_IsoVVVL_PFHT450"] )
      input->select("Events/HLT_Mu15_IsoVVVL_PFHT450",
                     HLT_Mu15_IsoVVVL_PFHT450);
    if ( choose["Events/HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5"] )
      input->select("Events/HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5",
                     HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5);
    if ( choose["Events/HLT_Mu15_IsoVVVL_PFHT450_PFMET50"] )
      input->select("Events/HLT_Mu15_IsoVVVL_PFHT450_PFMET50",
                     HLT_Mu15_IsoVVVL_PFHT450_PFMET50);
    if ( choose["Events/HLT_Mu15_IsoVVVL_PFHT600"] )
      input->select("Events/HLT_Mu15_IsoVVVL_PFHT600",
                     HLT_Mu15_IsoVVVL_PFHT600);
    if ( choose["Events/HLT_Mu17"] )
      input->select("Events/HLT_Mu17", 	HLT_Mu17);
    if ( choose["Events/HLT_Mu17_Photon30_IsoCaloId"] )
      input->select("Events/HLT_Mu17_Photon30_IsoCaloId",
                     HLT_Mu17_Photon30_IsoCaloId);
    if ( choose["Events/HLT_Mu17_TrkIsoVVL"] )
      input->select("Events/HLT_Mu17_TrkIsoVVL", 	HLT_Mu17_TrkIsoVVL);
    if ( choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"] )
      input->select("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL",
                     HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
    if ( choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"] )
      input->select("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ",
                     HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
    if ( choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8"] )
      input->select("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8",
                     HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
    if ( choose["Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8"] )
      input->select("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8",
                     HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
    if ( choose["Events/HLT_Mu18_Mu9"] )
      input->select("Events/HLT_Mu18_Mu9", 	HLT_Mu18_Mu9);
    if ( choose["Events/HLT_Mu18_Mu9_DZ"] )
      input->select("Events/HLT_Mu18_Mu9_DZ", 	HLT_Mu18_Mu9_DZ);
    if ( choose["Events/HLT_Mu18_Mu9_SameSign"] )
      input->select("Events/HLT_Mu18_Mu9_SameSign", 	HLT_Mu18_Mu9_SameSign);
    if ( choose["Events/HLT_Mu18_Mu9_SameSign_DZ"] )
      input->select("Events/HLT_Mu18_Mu9_SameSign_DZ",
                     HLT_Mu18_Mu9_SameSign_DZ);
    if ( choose["Events/HLT_Mu19"] )
      input->select("Events/HLT_Mu19", 	HLT_Mu19);
    if ( choose["Events/HLT_Mu19_TrkIsoVVL"] )
      input->select("Events/HLT_Mu19_TrkIsoVVL", 	HLT_Mu19_TrkIsoVVL);
    if ( choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL"] )
      input->select("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL",
                     HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL);
    if ( choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ"] )
      input->select("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ",
                     HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ);
    if ( choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8"] )
      input->select("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8",
                     HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
    if ( choose["Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8"] )
      input->select("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8",
                     HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
    if ( choose["Events/HLT_Mu20"] )
      input->select("Events/HLT_Mu20", 	HLT_Mu20);
    if ( choose["Events/HLT_Mu20_Mu10"] )
      input->select("Events/HLT_Mu20_Mu10", 	HLT_Mu20_Mu10);
    if ( choose["Events/HLT_Mu20_Mu10_DZ"] )
      input->select("Events/HLT_Mu20_Mu10_DZ", 	HLT_Mu20_Mu10_DZ);
    if ( choose["Events/HLT_Mu20_Mu10_SameSign"] )
      input->select("Events/HLT_Mu20_Mu10_SameSign",
                     HLT_Mu20_Mu10_SameSign);
    if ( choose["Events/HLT_Mu20_Mu10_SameSign_DZ"] )
      input->select("Events/HLT_Mu20_Mu10_SameSign_DZ",
                     HLT_Mu20_Mu10_SameSign_DZ);
    if ( choose["Events/HLT_Mu20_TkMu0_Phi"] )
      input->select("Events/HLT_Mu20_TkMu0_Phi", 	HLT_Mu20_TkMu0_Phi);
    if ( choose["Events/HLT_Mu23_Mu12"] )
      input->select("Events/HLT_Mu23_Mu12", 	HLT_Mu23_Mu12);
    if ( choose["Events/HLT_Mu23_Mu12_DZ"] )
      input->select("Events/HLT_Mu23_Mu12_DZ", 	HLT_Mu23_Mu12_DZ);
    if ( choose["Events/HLT_Mu23_Mu12_SameSign"] )
      input->select("Events/HLT_Mu23_Mu12_SameSign",
                     HLT_Mu23_Mu12_SameSign);
    if ( choose["Events/HLT_Mu23_Mu12_SameSign_DZ"] )
      input->select("Events/HLT_Mu23_Mu12_SameSign_DZ",
                     HLT_Mu23_Mu12_SameSign_DZ);
    if ( choose["Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"] )
      input->select("Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL",
                     HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
    if ( choose["Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"] )
      input->select("Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ",
                     HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    if ( choose["Events/HLT_Mu25_TkMu0_Onia"] )
      input->select("Events/HLT_Mu25_TkMu0_Onia", 	HLT_Mu25_TkMu0_Onia);
    if ( choose["Events/HLT_Mu25_TkMu0_Phi"] )
      input->select("Events/HLT_Mu25_TkMu0_Phi", 	HLT_Mu25_TkMu0_Phi);
    if ( choose["Events/HLT_Mu27"] )
      input->select("Events/HLT_Mu27", 	HLT_Mu27);
    if ( choose["Events/HLT_Mu27_Ele37_CaloIdL_MW"] )
      input->select("Events/HLT_Mu27_Ele37_CaloIdL_MW",
                     HLT_Mu27_Ele37_CaloIdL_MW);
    if ( choose["Events/HLT_Mu30_TkMu0_Onia"] )
      input->select("Events/HLT_Mu30_TkMu0_Onia", 	HLT_Mu30_TkMu0_Onia);
    if ( choose["Events/HLT_Mu37_Ele27_CaloIdL_MW"] )
      input->select("Events/HLT_Mu37_Ele27_CaloIdL_MW",
                     HLT_Mu37_Ele27_CaloIdL_MW);
    if ( choose["Events/HLT_Mu37_TkMu27"] )
      input->select("Events/HLT_Mu37_TkMu27", 	HLT_Mu37_TkMu27);
    if ( choose["Events/HLT_Mu3_PFJet40"] )
      input->select("Events/HLT_Mu3_PFJet40", 	HLT_Mu3_PFJet40);
    if ( choose["Events/HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL"] )
      input->select("Events/HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL",
                     HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL);
    if ( choose["Events/HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL"] )
      input->select("Events/HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL",
                     HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL);
    if ( choose["Events/HLT_Mu50"] )
      input->select("Events/HLT_Mu50", 	HLT_Mu50);
    if ( choose["Events/HLT_Mu50_IsoVVVL_PFHT450"] )
      input->select("Events/HLT_Mu50_IsoVVVL_PFHT450",
                     HLT_Mu50_IsoVVVL_PFHT450);
    if ( choose["Events/HLT_Mu55"] )
      input->select("Events/HLT_Mu55", 	HLT_Mu55);
    if ( choose["Events/HLT_Mu7p5_L2Mu2_Jpsi"] )
      input->select("Events/HLT_Mu7p5_L2Mu2_Jpsi", 	HLT_Mu7p5_L2Mu2_Jpsi);
    if ( choose["Events/HLT_Mu7p5_L2Mu2_Upsilon"] )
      input->select("Events/HLT_Mu7p5_L2Mu2_Upsilon",
                     HLT_Mu7p5_L2Mu2_Upsilon);
    if ( choose["Events/HLT_Mu7p5_Track2_Jpsi"] )
      input->select("Events/HLT_Mu7p5_Track2_Jpsi", 	HLT_Mu7p5_Track2_Jpsi);
    if ( choose["Events/HLT_Mu7p5_Track2_Upsilon"] )
      input->select("Events/HLT_Mu7p5_Track2_Upsilon",
                     HLT_Mu7p5_Track2_Upsilon);
    if ( choose["Events/HLT_Mu7p5_Track3p5_Jpsi"] )
      input->select("Events/HLT_Mu7p5_Track3p5_Jpsi",
                     HLT_Mu7p5_Track3p5_Jpsi);
    if ( choose["Events/HLT_Mu7p5_Track3p5_Upsilon"] )
      input->select("Events/HLT_Mu7p5_Track3p5_Upsilon",
                     HLT_Mu7p5_Track3p5_Upsilon);
    if ( choose["Events/HLT_Mu7p5_Track7_Jpsi"] )
      input->select("Events/HLT_Mu7p5_Track7_Jpsi", 	HLT_Mu7p5_Track7_Jpsi);
    if ( choose["Events/HLT_Mu7p5_Track7_Upsilon"] )
      input->select("Events/HLT_Mu7p5_Track7_Upsilon",
                     HLT_Mu7p5_Track7_Upsilon);
    if ( choose["Events/HLT_Mu8"] )
      input->select("Events/HLT_Mu8", 	HLT_Mu8);
    if ( choose["Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL"] )
      input->select("Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL",
                     HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
    if ( choose["Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ"] )
      input->select("Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ",
                     HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
    if ( choose["Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350"] )
      input->select("Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350",
                     HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350);
    if ( choose["Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ"] )
      input->select("Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ",
                     HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
    if ( choose["Events/HLT_Mu8_TrkIsoVVL"] )
      input->select("Events/HLT_Mu8_TrkIsoVVL", 	HLT_Mu8_TrkIsoVVL);
    if ( choose["Events/HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60"] )
      input->select("Events/HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60",
                     HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
    if ( choose["Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"] )
      input->select("Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL",
                     HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
    if ( choose["Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"] )
      input->select("Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ",
                     HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
    if ( choose["Events/HLT_OldMu100"] )
      input->select("Events/HLT_OldMu100", 	HLT_OldMu100);
    if ( choose["Events/HLT_PFHT1050"] )
      input->select("Events/HLT_PFHT1050", 	HLT_PFHT1050);
    if ( choose["Events/HLT_PFHT180"] )
      input->select("Events/HLT_PFHT180", 	HLT_PFHT180);
    if ( choose["Events/HLT_PFHT250"] )
      input->select("Events/HLT_PFHT250", 	HLT_PFHT250);
    if ( choose["Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40"] )
      input->select("Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40",
                     HLT_PFHT300PT30_QuadPFJet_75_60_45_40);
    if ( choose["Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0"] )
      input->select("Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0",
                     HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0);
    if ( choose["Events/HLT_PFHT350"] )
      input->select("Events/HLT_PFHT350", 	HLT_PFHT350);
    if ( choose["Events/HLT_PFHT350MinPFJet15"] )
      input->select("Events/HLT_PFHT350MinPFJet15", 	HLT_PFHT350MinPFJet15);
    if ( choose["Events/HLT_PFHT370"] )
      input->select("Events/HLT_PFHT370", 	HLT_PFHT370);
    if ( choose["Events/HLT_PFHT380_SixPFJet32"] )
      input->select("Events/HLT_PFHT380_SixPFJet32",
                     HLT_PFHT380_SixPFJet32);
    if ( choose["Events/HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2"] )
      input->select("Events/HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2",
                     HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2);
    if ( choose["Events/HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2"] )
      input->select("Events/HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2",
                     HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2);
    if ( choose["Events/HLT_PFHT430"] )
      input->select("Events/HLT_PFHT430", 	HLT_PFHT430);
    if ( choose["Events/HLT_PFHT430_SixPFJet40"] )
      input->select("Events/HLT_PFHT430_SixPFJet40",
                     HLT_PFHT430_SixPFJet40);
    if ( choose["Events/HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5"] )
      input->select("Events/HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5",
                     HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5);
    if ( choose["Events/HLT_PFHT500_PFMET100_PFMHT100_IDTight"] )
      input->select("Events/HLT_PFHT500_PFMET100_PFMHT100_IDTight",
                     HLT_PFHT500_PFMET100_PFMHT100_IDTight);
    if ( choose["Events/HLT_PFHT500_PFMET110_PFMHT110_IDTight"] )
      input->select("Events/HLT_PFHT500_PFMET110_PFMHT110_IDTight",
                     HLT_PFHT500_PFMET110_PFMHT110_IDTight);
    if ( choose["Events/HLT_PFHT510"] )
      input->select("Events/HLT_PFHT510", 	HLT_PFHT510);
    if ( choose["Events/HLT_PFHT590"] )
      input->select("Events/HLT_PFHT590", 	HLT_PFHT590);
    if ( choose["Events/HLT_PFHT680"] )
      input->select("Events/HLT_PFHT680", 	HLT_PFHT680);
    if ( choose["Events/HLT_PFHT700_PFMET85_PFMHT85_IDTight"] )
      input->select("Events/HLT_PFHT700_PFMET85_PFMHT85_IDTight",
                     HLT_PFHT700_PFMET85_PFMHT85_IDTight);
    if ( choose["Events/HLT_PFHT700_PFMET95_PFMHT95_IDTight"] )
      input->select("Events/HLT_PFHT700_PFMET95_PFMHT95_IDTight",
                     HLT_PFHT700_PFMET95_PFMHT95_IDTight);
    if ( choose["Events/HLT_PFHT780"] )
      input->select("Events/HLT_PFHT780", 	HLT_PFHT780);
    if ( choose["Events/HLT_PFHT800_PFMET75_PFMHT75_IDTight"] )
      input->select("Events/HLT_PFHT800_PFMET75_PFMHT75_IDTight",
                     HLT_PFHT800_PFMET75_PFMHT75_IDTight);
    if ( choose["Events/HLT_PFHT800_PFMET85_PFMHT85_IDTight"] )
      input->select("Events/HLT_PFHT800_PFMET85_PFMHT85_IDTight",
                     HLT_PFHT800_PFMET85_PFMHT85_IDTight);
    if ( choose["Events/HLT_PFHT890"] )
      input->select("Events/HLT_PFHT890", 	HLT_PFHT890);
    if ( choose["Events/HLT_PFJet140"] )
      input->select("Events/HLT_PFJet140", 	HLT_PFJet140);
    if ( choose["Events/HLT_PFJet200"] )
      input->select("Events/HLT_PFJet200", 	HLT_PFJet200);
    if ( choose["Events/HLT_PFJet260"] )
      input->select("Events/HLT_PFJet260", 	HLT_PFJet260);
    if ( choose["Events/HLT_PFJet320"] )
      input->select("Events/HLT_PFJet320", 	HLT_PFJet320);
    if ( choose["Events/HLT_PFJet40"] )
      input->select("Events/HLT_PFJet40", 	HLT_PFJet40);
    if ( choose["Events/HLT_PFJet400"] )
      input->select("Events/HLT_PFJet400", 	HLT_PFJet400);
    if ( choose["Events/HLT_PFJet450"] )
      input->select("Events/HLT_PFJet450", 	HLT_PFJet450);
    if ( choose["Events/HLT_PFJet500"] )
      input->select("Events/HLT_PFJet500", 	HLT_PFJet500);
    if ( choose["Events/HLT_PFJet550"] )
      input->select("Events/HLT_PFJet550", 	HLT_PFJet550);
    if ( choose["Events/HLT_PFJet60"] )
      input->select("Events/HLT_PFJet60", 	HLT_PFJet60);
    if ( choose["Events/HLT_PFJet80"] )
      input->select("Events/HLT_PFJet80", 	HLT_PFJet80);
    if ( choose["Events/HLT_PFJetFwd140"] )
      input->select("Events/HLT_PFJetFwd140", 	HLT_PFJetFwd140);
    if ( choose["Events/HLT_PFJetFwd200"] )
      input->select("Events/HLT_PFJetFwd200", 	HLT_PFJetFwd200);
    if ( choose["Events/HLT_PFJetFwd260"] )
      input->select("Events/HLT_PFJetFwd260", 	HLT_PFJetFwd260);
    if ( choose["Events/HLT_PFJetFwd320"] )
      input->select("Events/HLT_PFJetFwd320", 	HLT_PFJetFwd320);
    if ( choose["Events/HLT_PFJetFwd40"] )
      input->select("Events/HLT_PFJetFwd40", 	HLT_PFJetFwd40);
    if ( choose["Events/HLT_PFJetFwd400"] )
      input->select("Events/HLT_PFJetFwd400", 	HLT_PFJetFwd400);
    if ( choose["Events/HLT_PFJetFwd450"] )
      input->select("Events/HLT_PFJetFwd450", 	HLT_PFJetFwd450);
    if ( choose["Events/HLT_PFJetFwd500"] )
      input->select("Events/HLT_PFJetFwd500", 	HLT_PFJetFwd500);
    if ( choose["Events/HLT_PFJetFwd60"] )
      input->select("Events/HLT_PFJetFwd60", 	HLT_PFJetFwd60);
    if ( choose["Events/HLT_PFJetFwd80"] )
      input->select("Events/HLT_PFJetFwd80", 	HLT_PFJetFwd80);
    if ( choose["Events/HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1"] )
      input->select("Events/HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1",
                     HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1);
    if ( choose["Events/HLT_PFMET100_PFMHT100_IDTight_PFHT60"] )
      input->select("Events/HLT_PFMET100_PFMHT100_IDTight_PFHT60",
                     HLT_PFMET100_PFMHT100_IDTight_PFHT60);
    if ( choose["Events/HLT_PFMET110_PFMHT110_IDTight"] )
      input->select("Events/HLT_PFMET110_PFMHT110_IDTight",
                     HLT_PFMET110_PFMHT110_IDTight);
    if ( choose["Events/HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1"] )
      input->select("Events/HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1",
                     HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1);
    if ( choose["Events/HLT_PFMET120_PFMHT120_IDTight"] )
      input->select("Events/HLT_PFMET120_PFMHT120_IDTight",
                     HLT_PFMET120_PFMHT120_IDTight);
    if ( choose["Events/HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1"] )
      input->select("Events/HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1",
                     HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1);
    if ( choose["Events/HLT_PFMET120_PFMHT120_IDTight_PFHT60"] )
      input->select("Events/HLT_PFMET120_PFMHT120_IDTight_PFHT60",
                     HLT_PFMET120_PFMHT120_IDTight_PFHT60);
    if ( choose["Events/HLT_PFMET130_PFMHT130_IDTight"] )
      input->select("Events/HLT_PFMET130_PFMHT130_IDTight",
                     HLT_PFMET130_PFMHT130_IDTight);
    if ( choose["Events/HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1"] )
      input->select("Events/HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1",
                     HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1);
    if ( choose["Events/HLT_PFMET140_PFMHT140_IDTight"] )
      input->select("Events/HLT_PFMET140_PFMHT140_IDTight",
                     HLT_PFMET140_PFMHT140_IDTight);
    if ( choose["Events/HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1"] )
      input->select("Events/HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1",
                     HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1);
    if ( choose["Events/HLT_PFMET200_HBHECleaned"] )
      input->select("Events/HLT_PFMET200_HBHECleaned",
                     HLT_PFMET200_HBHECleaned);
    if ( choose["Events/HLT_PFMET200_HBHE_BeamHaloCleaned"] )
      input->select("Events/HLT_PFMET200_HBHE_BeamHaloCleaned",
                     HLT_PFMET200_HBHE_BeamHaloCleaned);
    if ( choose["Events/HLT_PFMET200_NotCleaned"] )
      input->select("Events/HLT_PFMET200_NotCleaned",
                     HLT_PFMET200_NotCleaned);
    if ( choose["Events/HLT_PFMET250_HBHECleaned"] )
      input->select("Events/HLT_PFMET250_HBHECleaned",
                     HLT_PFMET250_HBHECleaned);
    if ( choose["Events/HLT_PFMET300_HBHECleaned"] )
      input->select("Events/HLT_PFMET300_HBHECleaned",
                     HLT_PFMET300_HBHECleaned);
    if ( choose["Events/HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60"] )
      input->select("Events/HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60",
                     HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60);
    if ( choose["Events/HLT_PFMETNoMu110_PFMHTNoMu110_IDTight"] )
      input->select("Events/HLT_PFMETNoMu110_PFMHTNoMu110_IDTight",
                     HLT_PFMETNoMu110_PFMHTNoMu110_IDTight);
    if ( choose["Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight"] )
      input->select("Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight",
                     HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
    if ( choose["Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60"] )
      input->select("Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",
                     HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
    if ( choose["Events/HLT_PFMETNoMu130_PFMHTNoMu130_IDTight"] )
      input->select("Events/HLT_PFMETNoMu130_PFMHTNoMu130_IDTight",
                     HLT_PFMETNoMu130_PFMHTNoMu130_IDTight);
    if ( choose["Events/HLT_PFMETNoMu140_PFMHTNoMu140_IDTight"] )
      input->select("Events/HLT_PFMETNoMu140_PFMHTNoMu140_IDTight",
                     HLT_PFMETNoMu140_PFMHTNoMu140_IDTight);
    if ( choose["Events/HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60"] )
      input->select("Events/HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60",
                     HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60);
    if ( choose["Events/HLT_PFMETTypeOne110_PFMHT110_IDTight"] )
      input->select("Events/HLT_PFMETTypeOne110_PFMHT110_IDTight",
                     HLT_PFMETTypeOne110_PFMHT110_IDTight);
    if ( choose["Events/HLT_PFMETTypeOne120_PFMHT120_IDTight"] )
      input->select("Events/HLT_PFMETTypeOne120_PFMHT120_IDTight",
                     HLT_PFMETTypeOne120_PFMHT120_IDTight);
    if ( choose["Events/HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60"] )
      input->select("Events/HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60",
                     HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60);
    if ( choose["Events/HLT_PFMETTypeOne130_PFMHT130_IDTight"] )
      input->select("Events/HLT_PFMETTypeOne130_PFMHT130_IDTight",
                     HLT_PFMETTypeOne130_PFMHT130_IDTight);
    if ( choose["Events/HLT_PFMETTypeOne140_PFMHT140_IDTight"] )
      input->select("Events/HLT_PFMETTypeOne140_PFMHT140_IDTight",
                     HLT_PFMETTypeOne140_PFMHT140_IDTight);
    if ( choose["Events/HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned"] )
      input->select("Events/HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned",
                     HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned);
    if ( choose["Events/HLT_Photon120"] )
      input->select("Events/HLT_Photon120", 	HLT_Photon120);
    if ( choose["Events/HLT_Photon120_R9Id90_HE10_IsoM"] )
      input->select("Events/HLT_Photon120_R9Id90_HE10_IsoM",
                     HLT_Photon120_R9Id90_HE10_IsoM);
    if ( choose["Events/HLT_Photon150"] )
      input->select("Events/HLT_Photon150", 	HLT_Photon150);
    if ( choose["Events/HLT_Photon165_R9Id90_HE10_IsoM"] )
      input->select("Events/HLT_Photon165_R9Id90_HE10_IsoM",
                     HLT_Photon165_R9Id90_HE10_IsoM);
    if ( choose["Events/HLT_Photon175"] )
      input->select("Events/HLT_Photon175", 	HLT_Photon175);
    if ( choose["Events/HLT_Photon200"] )
      input->select("Events/HLT_Photon200", 	HLT_Photon200);
    if ( choose["Events/HLT_Photon20_HoverELoose"] )
      input->select("Events/HLT_Photon20_HoverELoose",
                     HLT_Photon20_HoverELoose);
    if ( choose["Events/HLT_Photon25"] )
      input->select("Events/HLT_Photon25", 	HLT_Photon25);
    if ( choose["Events/HLT_Photon300_NoHE"] )
      input->select("Events/HLT_Photon300_NoHE", 	HLT_Photon300_NoHE);
    if ( choose["Events/HLT_Photon30_HoverELoose"] )
      input->select("Events/HLT_Photon30_HoverELoose",
                     HLT_Photon30_HoverELoose);
    if ( choose["Events/HLT_Photon33"] )
      input->select("Events/HLT_Photon33", 	HLT_Photon33);
    if ( choose["Events/HLT_Photon40_HoverELoose"] )
      input->select("Events/HLT_Photon40_HoverELoose",
                     HLT_Photon40_HoverELoose);
    if ( choose["Events/HLT_Photon50"] )
      input->select("Events/HLT_Photon50", 	HLT_Photon50);
    if ( choose["Events/HLT_Photon50_HoverELoose"] )
      input->select("Events/HLT_Photon50_HoverELoose",
                     HLT_Photon50_HoverELoose);
    if ( choose["Events/HLT_Photon50_R9Id90_HE10_IsoM"] )
      input->select("Events/HLT_Photon50_R9Id90_HE10_IsoM",
                     HLT_Photon50_R9Id90_HE10_IsoM);
    if ( choose["Events/HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50"] )
      input->select("Events/HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50",
                     HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50);
    if ( choose["Events/HLT_Photon60_HoverELoose"] )
      input->select("Events/HLT_Photon60_HoverELoose",
                     HLT_Photon60_HoverELoose);
    if ( choose["Events/HLT_Photon60_R9Id90_CaloIdL_IsoL"] )
      input->select("Events/HLT_Photon60_R9Id90_CaloIdL_IsoL",
                     HLT_Photon60_R9Id90_CaloIdL_IsoL);
    if ( choose["Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL"] )
      input->select("Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL",
                     HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL);
    if ( choose["Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15"] )
      input->select("Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15",
                     HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15);
    if ( choose["Events/HLT_Photon75"] )
      input->select("Events/HLT_Photon75", 	HLT_Photon75);
    if ( choose["Events/HLT_Photon75_R9Id90_HE10_IsoM"] )
      input->select("Events/HLT_Photon75_R9Id90_HE10_IsoM",
                     HLT_Photon75_R9Id90_HE10_IsoM);
    if ( choose["Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3"] )
      input->select("Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3",
                     HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3);
    if ( choose["Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3"] )
      input->select("Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3",
                     HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3);
    if ( choose["Events/HLT_Photon90"] )
      input->select("Events/HLT_Photon90", 	HLT_Photon90);
    if ( choose["Events/HLT_Photon90_CaloIdL_PFHT700"] )
      input->select("Events/HLT_Photon90_CaloIdL_PFHT700",
                     HLT_Photon90_CaloIdL_PFHT700);
    if ( choose["Events/HLT_Photon90_R9Id90_HE10_IsoM"] )
      input->select("Events/HLT_Photon90_R9Id90_HE10_IsoM",
                     HLT_Photon90_R9Id90_HE10_IsoM);
    if ( choose["Events/HLT_Physics"] )
      input->select("Events/HLT_Physics", 	HLT_Physics);
    if ( choose["Events/HLT_Physics_part0"] )
      input->select("Events/HLT_Physics_part0", 	HLT_Physics_part0);
    if ( choose["Events/HLT_Physics_part1"] )
      input->select("Events/HLT_Physics_part1", 	HLT_Physics_part1);
    if ( choose["Events/HLT_Physics_part2"] )
      input->select("Events/HLT_Physics_part2", 	HLT_Physics_part2);
    if ( choose["Events/HLT_Physics_part3"] )
      input->select("Events/HLT_Physics_part3", 	HLT_Physics_part3);
    if ( choose["Events/HLT_Physics_part4"] )
      input->select("Events/HLT_Physics_part4", 	HLT_Physics_part4);
    if ( choose["Events/HLT_Physics_part5"] )
      input->select("Events/HLT_Physics_part5", 	HLT_Physics_part5);
    if ( choose["Events/HLT_Physics_part6"] )
      input->select("Events/HLT_Physics_part6", 	HLT_Physics_part6);
    if ( choose["Events/HLT_Physics_part7"] )
      input->select("Events/HLT_Physics_part7", 	HLT_Physics_part7);
    if ( choose["Events/HLT_QuadPFJet103_88_75_15"] )
      input->select("Events/HLT_QuadPFJet103_88_75_15",
                     HLT_QuadPFJet103_88_75_15);
    if ( choose["Events/HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2"] )
      input->select("Events/HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2",
                     HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2);
    if ( choose["Events/HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1"] )
      input->select("Events/HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1",
                     HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1);
    if ( choose["Events/HLT_QuadPFJet105_88_76_15"] )
      input->select("Events/HLT_QuadPFJet105_88_76_15",
                     HLT_QuadPFJet105_88_76_15);
    if ( choose["Events/HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2"] )
      input->select("Events/HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2",
                     HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2);
    if ( choose["Events/HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1"] )
      input->select("Events/HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1",
                     HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1);
    if ( choose["Events/HLT_QuadPFJet111_90_80_15"] )
      input->select("Events/HLT_QuadPFJet111_90_80_15",
                     HLT_QuadPFJet111_90_80_15);
    if ( choose["Events/HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2"] )
      input->select("Events/HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2",
                     HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2);
    if ( choose["Events/HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1"] )
      input->select("Events/HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1",
                     HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1);
    if ( choose["Events/HLT_QuadPFJet98_83_71_15"] )
      input->select("Events/HLT_QuadPFJet98_83_71_15",
                     HLT_QuadPFJet98_83_71_15);
    if ( choose["Events/HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2"] )
      input->select("Events/HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2",
                     HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2);
    if ( choose["Events/HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1"] )
      input->select("Events/HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1",
                     HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1);
    if ( choose["Events/HLT_Random"] )
      input->select("Events/HLT_Random", 	HLT_Random);
    if ( choose["Events/HLT_Rsq0p35"] )
      input->select("Events/HLT_Rsq0p35", 	HLT_Rsq0p35);
    if ( choose["Events/HLT_Rsq0p40"] )
      input->select("Events/HLT_Rsq0p40", 	HLT_Rsq0p40);
    if ( choose["Events/HLT_RsqMR300_Rsq0p09_MR200"] )
      input->select("Events/HLT_RsqMR300_Rsq0p09_MR200",
                     HLT_RsqMR300_Rsq0p09_MR200);
    if ( choose["Events/HLT_RsqMR300_Rsq0p09_MR200_4jet"] )
      input->select("Events/HLT_RsqMR300_Rsq0p09_MR200_4jet",
                     HLT_RsqMR300_Rsq0p09_MR200_4jet);
    if ( choose["Events/HLT_RsqMR320_Rsq0p09_MR200"] )
      input->select("Events/HLT_RsqMR320_Rsq0p09_MR200",
                     HLT_RsqMR320_Rsq0p09_MR200);
    if ( choose["Events/HLT_RsqMR320_Rsq0p09_MR200_4jet"] )
      input->select("Events/HLT_RsqMR320_Rsq0p09_MR200_4jet",
                     HLT_RsqMR320_Rsq0p09_MR200_4jet);
    if ( choose["Events/HLT_SingleJet30_Mu12_SinglePFJet40"] )
      input->select("Events/HLT_SingleJet30_Mu12_SinglePFJet40",
                     HLT_SingleJet30_Mu12_SinglePFJet40);
    if ( choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15"] )
      input->select("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15",
                     HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15);
    if ( choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1"] )
      input->select("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1",
                     HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1);
    if ( choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15"] )
      input->select("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15",
                     HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15);
    if ( choose["Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1"] )
      input->select("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1",
                     HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1);
    if ( choose["Events/HLT_TkMu100"] )
      input->select("Events/HLT_TkMu100", 	HLT_TkMu100);
    if ( choose["Events/HLT_Trimuon5_3p5_2_Upsilon_Muon"] )
      input->select("Events/HLT_Trimuon5_3p5_2_Upsilon_Muon",
                     HLT_Trimuon5_3p5_2_Upsilon_Muon);
    if ( choose["Events/HLT_TripleJet110_35_35_Mjj650_PFMET110"] )
      input->select("Events/HLT_TripleJet110_35_35_Mjj650_PFMET110",
                     HLT_TripleJet110_35_35_Mjj650_PFMET110);
    if ( choose["Events/HLT_TripleJet110_35_35_Mjj650_PFMET120"] )
      input->select("Events/HLT_TripleJet110_35_35_Mjj650_PFMET120",
                     HLT_TripleJet110_35_35_Mjj650_PFMET120);
    if ( choose["Events/HLT_TripleJet110_35_35_Mjj650_PFMET130"] )
      input->select("Events/HLT_TripleJet110_35_35_Mjj650_PFMET130",
                     HLT_TripleJet110_35_35_Mjj650_PFMET130);
    if ( choose["Events/HLT_TripleMu_10_5_5_DZ"] )
      input->select("Events/HLT_TripleMu_10_5_5_DZ",
                     HLT_TripleMu_10_5_5_DZ);
    if ( choose["Events/HLT_TripleMu_12_10_5"] )
      input->select("Events/HLT_TripleMu_12_10_5", 	HLT_TripleMu_12_10_5);
    if ( choose["Events/HLT_TripleMu_5_3_3_Mass3p8to60_DCA"] )
      input->select("Events/HLT_TripleMu_5_3_3_Mass3p8to60_DCA",
                     HLT_TripleMu_5_3_3_Mass3p8to60_DCA);
    if ( choose["Events/HLT_TripleMu_5_3_3_Mass3p8to60_DZ"] )
      input->select("Events/HLT_TripleMu_5_3_3_Mass3p8to60_DZ",
                     HLT_TripleMu_5_3_3_Mass3p8to60_DZ);
    if ( choose["Events/HLT_TriplePhoton_20_20_20_CaloIdLV2"] )
      input->select("Events/HLT_TriplePhoton_20_20_20_CaloIdLV2",
                     HLT_TriplePhoton_20_20_20_CaloIdLV2);
    if ( choose["Events/HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL"] )
      input->select("Events/HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL",
                     HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL);
    if ( choose["Events/HLT_TriplePhoton_30_30_10_CaloIdLV2"] )
      input->select("Events/HLT_TriplePhoton_30_30_10_CaloIdLV2",
                     HLT_TriplePhoton_30_30_10_CaloIdLV2);
    if ( choose["Events/HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL"] )
      input->select("Events/HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL",
                     HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL);
    if ( choose["Events/HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL"] )
      input->select("Events/HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL",
                     HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL);
    if ( choose["Events/HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx"] )
      input->select("Events/HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx",
                     HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx);
    if ( choose["Events/HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx"] )
      input->select("Events/HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx",
                     HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx);
    if ( choose["Events/HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx"] )
      input->select("Events/HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx",
                     HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx);
    if ( choose["Events/HLT_UncorrectedJetE30_NoBPTX"] )
      input->select("Events/HLT_UncorrectedJetE30_NoBPTX",
                     HLT_UncorrectedJetE30_NoBPTX);
    if ( choose["Events/HLT_UncorrectedJetE30_NoBPTX3BX"] )
      input->select("Events/HLT_UncorrectedJetE30_NoBPTX3BX",
                     HLT_UncorrectedJetE30_NoBPTX3BX);
    if ( choose["Events/HLT_UncorrectedJetE60_NoBPTX3BX"] )
      input->select("Events/HLT_UncorrectedJetE60_NoBPTX3BX",
                     HLT_UncorrectedJetE60_NoBPTX3BX);
    if ( choose["Events/HLT_UncorrectedJetE70_NoBPTX3BX"] )
      input->select("Events/HLT_UncorrectedJetE70_NoBPTX3BX",
                     HLT_UncorrectedJetE70_NoBPTX3BX);
    if ( choose["Events/HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg",
                     HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg",
                     HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg"] )
      input->select("Events/HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg",
                     HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg);
    if ( choose["Events/HLT_ZeroBias"] )
      input->select("Events/HLT_ZeroBias", 	HLT_ZeroBias);
    if ( choose["Events/HLT_ZeroBias_FirstBXAfterTrain"] )
      input->select("Events/HLT_ZeroBias_FirstBXAfterTrain",
                     HLT_ZeroBias_FirstBXAfterTrain);
    if ( choose["Events/HLT_ZeroBias_FirstCollisionAfterAbortGap"] )
      input->select("Events/HLT_ZeroBias_FirstCollisionAfterAbortGap",
                     HLT_ZeroBias_FirstCollisionAfterAbortGap);
    if ( choose["Events/HLT_ZeroBias_FirstCollisionInTrain"] )
      input->select("Events/HLT_ZeroBias_FirstCollisionInTrain",
                     HLT_ZeroBias_FirstCollisionInTrain);
    if ( choose["Events/HLT_ZeroBias_IsolatedBunches"] )
      input->select("Events/HLT_ZeroBias_IsolatedBunches",
                     HLT_ZeroBias_IsolatedBunches);
    if ( choose["Events/HLT_ZeroBias_LastCollisionInTrain"] )
      input->select("Events/HLT_ZeroBias_LastCollisionInTrain",
                     HLT_ZeroBias_LastCollisionInTrain);
    if ( choose["Events/HLT_ZeroBias_part0"] )
      input->select("Events/HLT_ZeroBias_part0", 	HLT_ZeroBias_part0);
    if ( choose["Events/HLT_ZeroBias_part1"] )
      input->select("Events/HLT_ZeroBias_part1", 	HLT_ZeroBias_part1);
    if ( choose["Events/HLT_ZeroBias_part2"] )
      input->select("Events/HLT_ZeroBias_part2", 	HLT_ZeroBias_part2);
    if ( choose["Events/HLT_ZeroBias_part3"] )
      input->select("Events/HLT_ZeroBias_part3", 	HLT_ZeroBias_part3);
    if ( choose["Events/HLT_ZeroBias_part4"] )
      input->select("Events/HLT_ZeroBias_part4", 	HLT_ZeroBias_part4);
    if ( choose["Events/HLT_ZeroBias_part5"] )
      input->select("Events/HLT_ZeroBias_part5", 	HLT_ZeroBias_part5);
    if ( choose["Events/HLT_ZeroBias_part6"] )
      input->select("Events/HLT_ZeroBias_part6", 	HLT_ZeroBias_part6);
    if ( choose["Events/HLT_ZeroBias_part7"] )
      input->select("Events/HLT_ZeroBias_part7", 	HLT_ZeroBias_part7);
    if ( choose["Events/HLTriggerFinalPath"] )
      input->select("Events/HLTriggerFinalPath", 	HLTriggerFinalPath);
    if ( choose["Events/HLTriggerFirstPath"] )
      input->select("Events/HLTriggerFirstPath", 	HLTriggerFirstPath);
    if ( choose["Events/IsoTrack_dxy"] )
      input->select("Events/IsoTrack_dxy", 	IsoTrack_dxy);
    if ( choose["Events/IsoTrack_dz"] )
      input->select("Events/IsoTrack_dz", 	IsoTrack_dz);
    if ( choose["Events/IsoTrack_eta"] )
      input->select("Events/IsoTrack_eta", 	IsoTrack_eta);
    if ( choose["Events/IsoTrack_isHighPurityTrack"] )
      input->select("Events/IsoTrack_isHighPurityTrack",
                     IsoTrack_isHighPurityTrack);
    if ( choose["Events/IsoTrack_isPFcand"] )
      input->select("Events/IsoTrack_isPFcand", 	IsoTrack_isPFcand);
    if ( choose["Events/IsoTrack_miniPFRelIso_all"] )
      input->select("Events/IsoTrack_miniPFRelIso_all",
                     IsoTrack_miniPFRelIso_all);
    if ( choose["Events/IsoTrack_miniPFRelIso_chg"] )
      input->select("Events/IsoTrack_miniPFRelIso_chg",
                     IsoTrack_miniPFRelIso_chg);
    if ( choose["Events/IsoTrack_pdgId"] )
      input->select("Events/IsoTrack_pdgId", 	IsoTrack_pdgId);
    if ( choose["Events/IsoTrack_pfRelIso03_all"] )
      input->select("Events/IsoTrack_pfRelIso03_all",
                     IsoTrack_pfRelIso03_all);
    if ( choose["Events/IsoTrack_pfRelIso03_chg"] )
      input->select("Events/IsoTrack_pfRelIso03_chg",
                     IsoTrack_pfRelIso03_chg);
    if ( choose["Events/IsoTrack_phi"] )
      input->select("Events/IsoTrack_phi", 	IsoTrack_phi);
    if ( choose["Events/IsoTrack_pt"] )
      input->select("Events/IsoTrack_pt", 	IsoTrack_pt);
    if ( choose["Events/Jet_area"] )
      input->select("Events/Jet_area", 	Jet_area);
    if ( choose["Events/Jet_bReg"] )
      input->select("Events/Jet_bReg", 	Jet_bReg);
    if ( choose["Events/Jet_btagCMVA"] )
      input->select("Events/Jet_btagCMVA", 	Jet_btagCMVA);
    if ( choose["Events/Jet_btagCSVV2"] )
      input->select("Events/Jet_btagCSVV2", 	Jet_btagCSVV2);
    if ( choose["Events/Jet_btagDeepB"] )
      input->select("Events/Jet_btagDeepB", 	Jet_btagDeepB);
    if ( choose["Events/Jet_btagDeepC"] )
      input->select("Events/Jet_btagDeepC", 	Jet_btagDeepC);
    if ( choose["Events/Jet_btagDeepFlavB"] )
      input->select("Events/Jet_btagDeepFlavB", 	Jet_btagDeepFlavB);
    if ( choose["Events/Jet_chEmEF"] )
      input->select("Events/Jet_chEmEF", 	Jet_chEmEF);
    if ( choose["Events/Jet_chHEF"] )
      input->select("Events/Jet_chHEF", 	Jet_chHEF);
    if ( choose["Events/Jet_cleanmask"] )
      input->select("Events/Jet_cleanmask", 	Jet_cleanmask);
    if ( choose["Events/Jet_electronIdx1"] )
      input->select("Events/Jet_electronIdx1", 	Jet_electronIdx1);
    if ( choose["Events/Jet_electronIdx2"] )
      input->select("Events/Jet_electronIdx2", 	Jet_electronIdx2);
    if ( choose["Events/Jet_eta"] )
      input->select("Events/Jet_eta", 	Jet_eta);
    if ( choose["Events/Jet_genJetIdx"] )
      input->select("Events/Jet_genJetIdx", 	Jet_genJetIdx);
    if ( choose["Events/Jet_hadronFlavour"] )
      input->select("Events/Jet_hadronFlavour", 	Jet_hadronFlavour);
    if ( choose["Events/Jet_jetId"] )
      input->select("Events/Jet_jetId", 	Jet_jetId);
    if ( choose["Events/Jet_mass"] )
      input->select("Events/Jet_mass", 	Jet_mass);
    if ( choose["Events/Jet_muonIdx1"] )
      input->select("Events/Jet_muonIdx1", 	Jet_muonIdx1);
    if ( choose["Events/Jet_muonIdx2"] )
      input->select("Events/Jet_muonIdx2", 	Jet_muonIdx2);
    if ( choose["Events/Jet_nConstituents"] )
      input->select("Events/Jet_nConstituents", 	Jet_nConstituents);
    if ( choose["Events/Jet_nElectrons"] )
      input->select("Events/Jet_nElectrons", 	Jet_nElectrons);
    if ( choose["Events/Jet_nMuons"] )
      input->select("Events/Jet_nMuons", 	Jet_nMuons);
    if ( choose["Events/Jet_neEmEF"] )
      input->select("Events/Jet_neEmEF", 	Jet_neEmEF);
    if ( choose["Events/Jet_neHEF"] )
      input->select("Events/Jet_neHEF", 	Jet_neHEF);
    if ( choose["Events/Jet_partonFlavour"] )
      input->select("Events/Jet_partonFlavour", 	Jet_partonFlavour);
    if ( choose["Events/Jet_phi"] )
      input->select("Events/Jet_phi", 	Jet_phi);
    if ( choose["Events/Jet_pt"] )
      input->select("Events/Jet_pt", 	Jet_pt);
    if ( choose["Events/Jet_puId"] )
      input->select("Events/Jet_puId", 	Jet_puId);
    if ( choose["Events/Jet_qgl"] )
      input->select("Events/Jet_qgl", 	Jet_qgl);
    if ( choose["Events/Jet_rawFactor"] )
      input->select("Events/Jet_rawFactor", 	Jet_rawFactor);
    if ( choose["Events/L1simulation_step"] )
      input->select("Events/L1simulation_step", 	L1simulation_step);
    if ( choose["Events/LHEPart_eta"] )
      input->select("Events/LHEPart_eta", 	LHEPart_eta);
    if ( choose["Events/LHEPart_mass"] )
      input->select("Events/LHEPart_mass", 	LHEPart_mass);
    if ( choose["Events/LHEPart_pdgId"] )
      input->select("Events/LHEPart_pdgId", 	LHEPart_pdgId);
    if ( choose["Events/LHEPart_phi"] )
      input->select("Events/LHEPart_phi", 	LHEPart_phi);
    if ( choose["Events/LHEPart_pt"] )
      input->select("Events/LHEPart_pt", 	LHEPart_pt);
    if ( choose["Events/LHEPdfWeight"] )
      input->select("Events/LHEPdfWeight", 	LHEPdfWeight);
    if ( choose["Events/LHEScaleWeight"] )
      input->select("Events/LHEScaleWeight", 	LHEScaleWeight);
    if ( choose["Events/LHEWeight_originalXWGTUP"] )
      input->select("Events/LHEWeight_originalXWGTUP",
                     LHEWeight_originalXWGTUP);
    if ( choose["Events/LHE_HT"] )
      input->select("Events/LHE_HT", 	LHE_HT);
    if ( choose["Events/LHE_HTIncoming"] )
      input->select("Events/LHE_HTIncoming", 	LHE_HTIncoming);
    if ( choose["Events/LHE_Nb"] )
      input->select("Events/LHE_Nb", 	LHE_Nb);
    if ( choose["Events/LHE_Nc"] )
      input->select("Events/LHE_Nc", 	LHE_Nc);
    if ( choose["Events/LHE_Nglu"] )
      input->select("Events/LHE_Nglu", 	LHE_Nglu);
    if ( choose["Events/LHE_Njets"] )
      input->select("Events/LHE_Njets", 	LHE_Njets);
    if ( choose["Events/LHE_NpLO"] )
      input->select("Events/LHE_NpLO", 	LHE_NpLO);
    if ( choose["Events/LHE_NpNLO"] )
      input->select("Events/LHE_NpNLO", 	LHE_NpNLO);
    if ( choose["Events/LHE_Nuds"] )
      input->select("Events/LHE_Nuds", 	LHE_Nuds);
    if ( choose["Events/LHE_Vpt"] )
      input->select("Events/LHE_Vpt", 	LHE_Vpt);
    if ( choose["Events/MET_MetUnclustEnUpDeltaX"] )
      input->select("Events/MET_MetUnclustEnUpDeltaX",
                     MET_MetUnclustEnUpDeltaX);
    if ( choose["Events/MET_MetUnclustEnUpDeltaY"] )
      input->select("Events/MET_MetUnclustEnUpDeltaY",
                     MET_MetUnclustEnUpDeltaY);
    if ( choose["Events/MET_covXX"] )
      input->select("Events/MET_covXX", 	MET_covXX);
    if ( choose["Events/MET_covXY"] )
      input->select("Events/MET_covXY", 	MET_covXY);
    if ( choose["Events/MET_covYY"] )
      input->select("Events/MET_covYY", 	MET_covYY);
    if ( choose["Events/MET_fiducialGenPhi"] )
      input->select("Events/MET_fiducialGenPhi", 	MET_fiducialGenPhi);
    if ( choose["Events/MET_fiducialGenPt"] )
      input->select("Events/MET_fiducialGenPt", 	MET_fiducialGenPt);
    if ( choose["Events/MET_phi"] )
      input->select("Events/MET_phi", 	MET_phi);
    if ( choose["Events/MET_pt"] )
      input->select("Events/MET_pt", 	MET_pt);
    if ( choose["Events/MET_significance"] )
      input->select("Events/MET_significance", 	MET_significance);
    if ( choose["Events/MET_sumEt"] )
      input->select("Events/MET_sumEt", 	MET_sumEt);
    if ( choose["Events/Muon_charge"] )
      input->select("Events/Muon_charge", 	Muon_charge);
    if ( choose["Events/Muon_cleanmask"] )
      input->select("Events/Muon_cleanmask", 	Muon_cleanmask);
    if ( choose["Events/Muon_dxy"] )
      input->select("Events/Muon_dxy", 	Muon_dxy);
    if ( choose["Events/Muon_dxyErr"] )
      input->select("Events/Muon_dxyErr", 	Muon_dxyErr);
    if ( choose["Events/Muon_dz"] )
      input->select("Events/Muon_dz", 	Muon_dz);
    if ( choose["Events/Muon_dzErr"] )
      input->select("Events/Muon_dzErr", 	Muon_dzErr);
    if ( choose["Events/Muon_eta"] )
      input->select("Events/Muon_eta", 	Muon_eta);
    if ( choose["Events/Muon_genPartFlav"] )
      input->select("Events/Muon_genPartFlav", 	Muon_genPartFlav);
    if ( choose["Events/Muon_genPartIdx"] )
      input->select("Events/Muon_genPartIdx", 	Muon_genPartIdx);
    if ( choose["Events/Muon_highPtId"] )
      input->select("Events/Muon_highPtId", 	Muon_highPtId);
    if ( choose["Events/Muon_ip3d"] )
      input->select("Events/Muon_ip3d", 	Muon_ip3d);
    if ( choose["Events/Muon_isPFcand"] )
      input->select("Events/Muon_isPFcand", 	Muon_isPFcand);
    if ( choose["Events/Muon_jetIdx"] )
      input->select("Events/Muon_jetIdx", 	Muon_jetIdx);
    if ( choose["Events/Muon_mass"] )
      input->select("Events/Muon_mass", 	Muon_mass);
    if ( choose["Events/Muon_mediumId"] )
      input->select("Events/Muon_mediumId", 	Muon_mediumId);
    if ( choose["Events/Muon_miniPFRelIso_all"] )
      input->select("Events/Muon_miniPFRelIso_all", 	Muon_miniPFRelIso_all);
    if ( choose["Events/Muon_miniPFRelIso_chg"] )
      input->select("Events/Muon_miniPFRelIso_chg", 	Muon_miniPFRelIso_chg);
    if ( choose["Events/Muon_mvaTTH"] )
      input->select("Events/Muon_mvaTTH", 	Muon_mvaTTH);
    if ( choose["Events/Muon_nStations"] )
      input->select("Events/Muon_nStations", 	Muon_nStations);
    if ( choose["Events/Muon_nTrackerLayers"] )
      input->select("Events/Muon_nTrackerLayers", 	Muon_nTrackerLayers);
    if ( choose["Events/Muon_pdgId"] )
      input->select("Events/Muon_pdgId", 	Muon_pdgId);
    if ( choose["Events/Muon_pfRelIso03_all"] )
      input->select("Events/Muon_pfRelIso03_all", 	Muon_pfRelIso03_all);
    if ( choose["Events/Muon_pfRelIso03_chg"] )
      input->select("Events/Muon_pfRelIso03_chg", 	Muon_pfRelIso03_chg);
    if ( choose["Events/Muon_pfRelIso04_all"] )
      input->select("Events/Muon_pfRelIso04_all", 	Muon_pfRelIso04_all);
    if ( choose["Events/Muon_phi"] )
      input->select("Events/Muon_phi", 	Muon_phi);
    if ( choose["Events/Muon_pt"] )
      input->select("Events/Muon_pt", 	Muon_pt);
    if ( choose["Events/Muon_ptErr"] )
      input->select("Events/Muon_ptErr", 	Muon_ptErr);
    if ( choose["Events/Muon_segmentComp"] )
      input->select("Events/Muon_segmentComp", 	Muon_segmentComp);
    if ( choose["Events/Muon_sip3d"] )
      input->select("Events/Muon_sip3d", 	Muon_sip3d);
    if ( choose["Events/Muon_softId"] )
      input->select("Events/Muon_softId", 	Muon_softId);
    if ( choose["Events/Muon_tightCharge"] )
      input->select("Events/Muon_tightCharge", 	Muon_tightCharge);
    if ( choose["Events/Muon_tightId"] )
      input->select("Events/Muon_tightId", 	Muon_tightId);
    if ( choose["Events/OtherPV_z"] )
      input->select("Events/OtherPV_z", 	OtherPV_z);
    if ( choose["Events/PV_chi2"] )
      input->select("Events/PV_chi2", 	PV_chi2);
    if ( choose["Events/PV_ndof"] )
      input->select("Events/PV_ndof", 	PV_ndof);
    if ( choose["Events/PV_npvs"] )
      input->select("Events/PV_npvs", 	PV_npvs);
    if ( choose["Events/PV_npvsGood"] )
      input->select("Events/PV_npvsGood", 	PV_npvsGood);
    if ( choose["Events/PV_score"] )
      input->select("Events/PV_score", 	PV_score);
    if ( choose["Events/PV_x"] )
      input->select("Events/PV_x", 	PV_x);
    if ( choose["Events/PV_y"] )
      input->select("Events/PV_y", 	PV_y);
    if ( choose["Events/PV_z"] )
      input->select("Events/PV_z", 	PV_z);
    if ( choose["Events/Photon_charge"] )
      input->select("Events/Photon_charge", 	Photon_charge);
    if ( choose["Events/Photon_cleanmask"] )
      input->select("Events/Photon_cleanmask", 	Photon_cleanmask);
    if ( choose["Events/Photon_cutBasedBitmap"] )
      input->select("Events/Photon_cutBasedBitmap", 	Photon_cutBasedBitmap);
    if ( choose["Events/Photon_eCorr"] )
      input->select("Events/Photon_eCorr", 	Photon_eCorr);
    if ( choose["Events/Photon_electronIdx"] )
      input->select("Events/Photon_electronIdx", 	Photon_electronIdx);
    if ( choose["Events/Photon_electronVeto"] )
      input->select("Events/Photon_electronVeto", 	Photon_electronVeto);
    if ( choose["Events/Photon_energyErr"] )
      input->select("Events/Photon_energyErr", 	Photon_energyErr);
    if ( choose["Events/Photon_eta"] )
      input->select("Events/Photon_eta", 	Photon_eta);
    if ( choose["Events/Photon_genPartFlav"] )
      input->select("Events/Photon_genPartFlav", 	Photon_genPartFlav);
    if ( choose["Events/Photon_genPartIdx"] )
      input->select("Events/Photon_genPartIdx", 	Photon_genPartIdx);
    if ( choose["Events/Photon_hoe"] )
      input->select("Events/Photon_hoe", 	Photon_hoe);
    if ( choose["Events/Photon_isScEtaEB"] )
      input->select("Events/Photon_isScEtaEB", 	Photon_isScEtaEB);
    if ( choose["Events/Photon_isScEtaEE"] )
      input->select("Events/Photon_isScEtaEE", 	Photon_isScEtaEE);
    if ( choose["Events/Photon_jetIdx"] )
      input->select("Events/Photon_jetIdx", 	Photon_jetIdx);
    if ( choose["Events/Photon_mass"] )
      input->select("Events/Photon_mass", 	Photon_mass);
    if ( choose["Events/Photon_mvaID"] )
      input->select("Events/Photon_mvaID", 	Photon_mvaID);
    if ( choose["Events/Photon_mvaID_WP80"] )
      input->select("Events/Photon_mvaID_WP80", 	Photon_mvaID_WP80);
    if ( choose["Events/Photon_mvaID_WP90"] )
      input->select("Events/Photon_mvaID_WP90", 	Photon_mvaID_WP90);
    if ( choose["Events/Photon_pdgId"] )
      input->select("Events/Photon_pdgId", 	Photon_pdgId);
    if ( choose["Events/Photon_pfRelIso03_all"] )
      input->select("Events/Photon_pfRelIso03_all", 	Photon_pfRelIso03_all);
    if ( choose["Events/Photon_pfRelIso03_chg"] )
      input->select("Events/Photon_pfRelIso03_chg", 	Photon_pfRelIso03_chg);
    if ( choose["Events/Photon_phi"] )
      input->select("Events/Photon_phi", 	Photon_phi);
    if ( choose["Events/Photon_pixelSeed"] )
      input->select("Events/Photon_pixelSeed", 	Photon_pixelSeed);
    if ( choose["Events/Photon_pt"] )
      input->select("Events/Photon_pt", 	Photon_pt);
    if ( choose["Events/Photon_r9"] )
      input->select("Events/Photon_r9", 	Photon_r9);
    if ( choose["Events/Photon_sieie"] )
      input->select("Events/Photon_sieie", 	Photon_sieie);
    if ( choose["Events/Photon_vidNestedWPBitmap"] )
      input->select("Events/Photon_vidNestedWPBitmap",
                     Photon_vidNestedWPBitmap);
    if ( choose["Events/Pileup_nPU"] )
      input->select("Events/Pileup_nPU", 	Pileup_nPU);
    if ( choose["Events/Pileup_nTrueInt"] )
      input->select("Events/Pileup_nTrueInt", 	Pileup_nTrueInt);
    if ( choose["Events/Pileup_sumEOOT"] )
      input->select("Events/Pileup_sumEOOT", 	Pileup_sumEOOT);
    if ( choose["Events/Pileup_sumLOOT"] )
      input->select("Events/Pileup_sumLOOT", 	Pileup_sumLOOT);
    if ( choose["Events/PuppiMET_phi"] )
      input->select("Events/PuppiMET_phi", 	PuppiMET_phi);
    if ( choose["Events/PuppiMET_pt"] )
      input->select("Events/PuppiMET_pt", 	PuppiMET_pt);
    if ( choose["Events/PuppiMET_sumEt"] )
      input->select("Events/PuppiMET_sumEt", 	PuppiMET_sumEt);
    if ( choose["Events/RawMET_phi"] )
      input->select("Events/RawMET_phi", 	RawMET_phi);
    if ( choose["Events/RawMET_pt"] )
      input->select("Events/RawMET_pt", 	RawMET_pt);
    if ( choose["Events/RawMET_sumEt"] )
      input->select("Events/RawMET_sumEt", 	RawMET_sumEt);
    if ( choose["Events/SV_chi2"] )
      input->select("Events/SV_chi2", 	SV_chi2);
    if ( choose["Events/SV_dlen"] )
      input->select("Events/SV_dlen", 	SV_dlen);
    if ( choose["Events/SV_dlenSig"] )
      input->select("Events/SV_dlenSig", 	SV_dlenSig);
    if ( choose["Events/SV_eta"] )
      input->select("Events/SV_eta", 	SV_eta);
    if ( choose["Events/SV_mass"] )
      input->select("Events/SV_mass", 	SV_mass);
    if ( choose["Events/SV_ndof"] )
      input->select("Events/SV_ndof", 	SV_ndof);
    if ( choose["Events/SV_pAngle"] )
      input->select("Events/SV_pAngle", 	SV_pAngle);
    if ( choose["Events/SV_phi"] )
      input->select("Events/SV_phi", 	SV_phi);
    if ( choose["Events/SV_pt"] )
      input->select("Events/SV_pt", 	SV_pt);
    if ( choose["Events/SV_x"] )
      input->select("Events/SV_x", 	SV_x);
    if ( choose["Events/SV_y"] )
      input->select("Events/SV_y", 	SV_y);
    if ( choose["Events/SV_z"] )
      input->select("Events/SV_z", 	SV_z);
    if ( choose["Events/SoftActivityJetHT"] )
      input->select("Events/SoftActivityJetHT", 	SoftActivityJetHT);
    if ( choose["Events/SoftActivityJetHT10"] )
      input->select("Events/SoftActivityJetHT10", 	SoftActivityJetHT10);
    if ( choose["Events/SoftActivityJetHT2"] )
      input->select("Events/SoftActivityJetHT2", 	SoftActivityJetHT2);
    if ( choose["Events/SoftActivityJetHT5"] )
      input->select("Events/SoftActivityJetHT5", 	SoftActivityJetHT5);
    if ( choose["Events/SoftActivityJetNjets10"] )
      input->select("Events/SoftActivityJetNjets10",
                     SoftActivityJetNjets10);
    if ( choose["Events/SoftActivityJetNjets2"] )
      input->select("Events/SoftActivityJetNjets2", 	SoftActivityJetNjets2);
    if ( choose["Events/SoftActivityJetNjets5"] )
      input->select("Events/SoftActivityJetNjets5", 	SoftActivityJetNjets5);
    if ( choose["Events/SoftActivityJet_eta"] )
      input->select("Events/SoftActivityJet_eta", 	SoftActivityJet_eta);
    if ( choose["Events/SoftActivityJet_phi"] )
      input->select("Events/SoftActivityJet_phi", 	SoftActivityJet_phi);
    if ( choose["Events/SoftActivityJet_pt"] )
      input->select("Events/SoftActivityJet_pt", 	SoftActivityJet_pt);
    if ( choose["Events/SubGenJetAK8_eta"] )
      input->select("Events/SubGenJetAK8_eta", 	SubGenJetAK8_eta);
    if ( choose["Events/SubGenJetAK8_mass"] )
      input->select("Events/SubGenJetAK8_mass", 	SubGenJetAK8_mass);
    if ( choose["Events/SubGenJetAK8_phi"] )
      input->select("Events/SubGenJetAK8_phi", 	SubGenJetAK8_phi);
    if ( choose["Events/SubGenJetAK8_pt"] )
      input->select("Events/SubGenJetAK8_pt", 	SubGenJetAK8_pt);
    if ( choose["Events/SubJet_btagCMVA"] )
      input->select("Events/SubJet_btagCMVA", 	SubJet_btagCMVA);
    if ( choose["Events/SubJet_btagCSVV2"] )
      input->select("Events/SubJet_btagCSVV2", 	SubJet_btagCSVV2);
    if ( choose["Events/SubJet_btagDeepB"] )
      input->select("Events/SubJet_btagDeepB", 	SubJet_btagDeepB);
    if ( choose["Events/SubJet_eta"] )
      input->select("Events/SubJet_eta", 	SubJet_eta);
    if ( choose["Events/SubJet_mass"] )
      input->select("Events/SubJet_mass", 	SubJet_mass);
    if ( choose["Events/SubJet_n2b1"] )
      input->select("Events/SubJet_n2b1", 	SubJet_n2b1);
    if ( choose["Events/SubJet_n3b1"] )
      input->select("Events/SubJet_n3b1", 	SubJet_n3b1);
    if ( choose["Events/SubJet_phi"] )
      input->select("Events/SubJet_phi", 	SubJet_phi);
    if ( choose["Events/SubJet_pt"] )
      input->select("Events/SubJet_pt", 	SubJet_pt);
    if ( choose["Events/SubJet_tau1"] )
      input->select("Events/SubJet_tau1", 	SubJet_tau1);
    if ( choose["Events/SubJet_tau2"] )
      input->select("Events/SubJet_tau2", 	SubJet_tau2);
    if ( choose["Events/SubJet_tau3"] )
      input->select("Events/SubJet_tau3", 	SubJet_tau3);
    if ( choose["Events/SubJet_tau4"] )
      input->select("Events/SubJet_tau4", 	SubJet_tau4);
    if ( choose["Events/Tau_charge"] )
      input->select("Events/Tau_charge", 	Tau_charge);
    if ( choose["Events/Tau_chargedIso"] )
      input->select("Events/Tau_chargedIso", 	Tau_chargedIso);
    if ( choose["Events/Tau_cleanmask"] )
      input->select("Events/Tau_cleanmask", 	Tau_cleanmask);
    if ( choose["Events/Tau_decayMode"] )
      input->select("Events/Tau_decayMode", 	Tau_decayMode);
    if ( choose["Events/Tau_dxy"] )
      input->select("Events/Tau_dxy", 	Tau_dxy);
    if ( choose["Events/Tau_dz"] )
      input->select("Events/Tau_dz", 	Tau_dz);
    if ( choose["Events/Tau_eta"] )
      input->select("Events/Tau_eta", 	Tau_eta);
    if ( choose["Events/Tau_genPartFlav"] )
      input->select("Events/Tau_genPartFlav", 	Tau_genPartFlav);
    if ( choose["Events/Tau_genPartIdx"] )
      input->select("Events/Tau_genPartIdx", 	Tau_genPartIdx);
    if ( choose["Events/Tau_idAntiEle"] )
      input->select("Events/Tau_idAntiEle", 	Tau_idAntiEle);
    if ( choose["Events/Tau_idAntiMu"] )
      input->select("Events/Tau_idAntiMu", 	Tau_idAntiMu);
    if ( choose["Events/Tau_idDecayMode"] )
      input->select("Events/Tau_idDecayMode", 	Tau_idDecayMode);
    if ( choose["Events/Tau_idDecayModeNewDMs"] )
      input->select("Events/Tau_idDecayModeNewDMs", 	Tau_idDecayModeNewDMs);
    if ( choose["Events/Tau_idMVAnewDM2017v2"] )
      input->select("Events/Tau_idMVAnewDM2017v2", 	Tau_idMVAnewDM2017v2);
    if ( choose["Events/Tau_idMVAoldDM"] )
      input->select("Events/Tau_idMVAoldDM", 	Tau_idMVAoldDM);
    if ( choose["Events/Tau_idMVAoldDM2017v1"] )
      input->select("Events/Tau_idMVAoldDM2017v1", 	Tau_idMVAoldDM2017v1);
    if ( choose["Events/Tau_idMVAoldDM2017v2"] )
      input->select("Events/Tau_idMVAoldDM2017v2", 	Tau_idMVAoldDM2017v2);
    if ( choose["Events/Tau_idMVAoldDMdR032017v2"] )
      input->select("Events/Tau_idMVAoldDMdR032017v2",
                     Tau_idMVAoldDMdR032017v2);
    if ( choose["Events/Tau_jetIdx"] )
      input->select("Events/Tau_jetIdx", 	Tau_jetIdx);
    if ( choose["Events/Tau_leadTkDeltaEta"] )
      input->select("Events/Tau_leadTkDeltaEta", 	Tau_leadTkDeltaEta);
    if ( choose["Events/Tau_leadTkDeltaPhi"] )
      input->select("Events/Tau_leadTkDeltaPhi", 	Tau_leadTkDeltaPhi);
    if ( choose["Events/Tau_leadTkPtOverTauPt"] )
      input->select("Events/Tau_leadTkPtOverTauPt", 	Tau_leadTkPtOverTauPt);
    if ( choose["Events/Tau_mass"] )
      input->select("Events/Tau_mass", 	Tau_mass);
    if ( choose["Events/Tau_neutralIso"] )
      input->select("Events/Tau_neutralIso", 	Tau_neutralIso);
    if ( choose["Events/Tau_phi"] )
      input->select("Events/Tau_phi", 	Tau_phi);
    if ( choose["Events/Tau_photonsOutsideSignalCone"] )
      input->select("Events/Tau_photonsOutsideSignalCone",
                     Tau_photonsOutsideSignalCone);
    if ( choose["Events/Tau_pt"] )
      input->select("Events/Tau_pt", 	Tau_pt);
    if ( choose["Events/Tau_puCorr"] )
      input->select("Events/Tau_puCorr", 	Tau_puCorr);
    if ( choose["Events/Tau_rawAntiEle"] )
      input->select("Events/Tau_rawAntiEle", 	Tau_rawAntiEle);
    if ( choose["Events/Tau_rawAntiEleCat"] )
      input->select("Events/Tau_rawAntiEleCat", 	Tau_rawAntiEleCat);
    if ( choose["Events/Tau_rawIso"] )
      input->select("Events/Tau_rawIso", 	Tau_rawIso);
    if ( choose["Events/Tau_rawIsodR03"] )
      input->select("Events/Tau_rawIsodR03", 	Tau_rawIsodR03);
    if ( choose["Events/Tau_rawMVAnewDM2017v2"] )
      input->select("Events/Tau_rawMVAnewDM2017v2", 	Tau_rawMVAnewDM2017v2);
    if ( choose["Events/Tau_rawMVAoldDM"] )
      input->select("Events/Tau_rawMVAoldDM", 	Tau_rawMVAoldDM);
    if ( choose["Events/Tau_rawMVAoldDM2017v1"] )
      input->select("Events/Tau_rawMVAoldDM2017v1", 	Tau_rawMVAoldDM2017v1);
    if ( choose["Events/Tau_rawMVAoldDM2017v2"] )
      input->select("Events/Tau_rawMVAoldDM2017v2", 	Tau_rawMVAoldDM2017v2);
    if ( choose["Events/Tau_rawMVAoldDMdR032017v2"] )
      input->select("Events/Tau_rawMVAoldDMdR032017v2",
                     Tau_rawMVAoldDMdR032017v2);
    if ( choose["Events/TkMET_phi"] )
      input->select("Events/TkMET_phi", 	TkMET_phi);
    if ( choose["Events/TkMET_pt"] )
      input->select("Events/TkMET_pt", 	TkMET_pt);
    if ( choose["Events/TkMET_sumEt"] )
      input->select("Events/TkMET_sumEt", 	TkMET_sumEt);
    if ( choose["Events/TrigObj_eta"] )
      input->select("Events/TrigObj_eta", 	TrigObj_eta);
    if ( choose["Events/TrigObj_filterBits"] )
      input->select("Events/TrigObj_filterBits", 	TrigObj_filterBits);
    if ( choose["Events/TrigObj_id"] )
      input->select("Events/TrigObj_id", 	TrigObj_id);
    if ( choose["Events/TrigObj_l1charge"] )
      input->select("Events/TrigObj_l1charge", 	TrigObj_l1charge);
    if ( choose["Events/TrigObj_l1iso"] )
      input->select("Events/TrigObj_l1iso", 	TrigObj_l1iso);
    if ( choose["Events/TrigObj_l1pt"] )
      input->select("Events/TrigObj_l1pt", 	TrigObj_l1pt);
    if ( choose["Events/TrigObj_l1pt_2"] )
      input->select("Events/TrigObj_l1pt_2", 	TrigObj_l1pt_2);
    if ( choose["Events/TrigObj_l2pt"] )
      input->select("Events/TrigObj_l2pt", 	TrigObj_l2pt);
    if ( choose["Events/TrigObj_phi"] )
      input->select("Events/TrigObj_phi", 	TrigObj_phi);
    if ( choose["Events/TrigObj_pt"] )
      input->select("Events/TrigObj_pt", 	TrigObj_pt);
    if ( choose["Events/event"] )
      input->select("Events/event", 	event);
    if ( choose["Events/fixedGridRhoFastjetAll"] )
      input->select("Events/fixedGridRhoFastjetAll",
                     fixedGridRhoFastjetAll);
    if ( choose["Events/fixedGridRhoFastjetCentralCalo"] )
      input->select("Events/fixedGridRhoFastjetCentralCalo",
                     fixedGridRhoFastjetCentralCalo);
    if ( choose["Events/fixedGridRhoFastjetCentralNeutral"] )
      input->select("Events/fixedGridRhoFastjetCentralNeutral",
                     fixedGridRhoFastjetCentralNeutral);
    if ( choose["Events/genTtbarId"] )
      input->select("Events/genTtbarId", 	genTtbarId);
    if ( choose["Events/genWeight"] )
      input->select("Events/genWeight", 	genWeight);
    if ( choose["Events/luminosityBlock"] )
      input->select("Events/luminosityBlock", 	luminosityBlock);
    if ( choose["Events/run"] )
      input->select("Events/run", 	run);

  }

  // A write-only buffer
  eventBuffer(otreestream& stream)
  : input(0),
    output(&stream)
  {
    initBuffers();

    output->add("nTau", 	nTau);
    output->add("nPhoton", 	nPhoton);
    output->add("nSubGenJetAK8", 	nSubGenJetAK8);
    output->add("nMuon", 	nMuon);
    output->add("nElectron", 	nElectron);
    output->add("nGenJet", 	nGenJet);
    output->add("nLHEScaleWeight", 	nLHEScaleWeight);
    output->add("nLHEPdfWeight", 	nLHEPdfWeight);
    output->add("nFatJet", 	nFatJet);
    output->add("nLHEPart", 	nLHEPart);
    output->add("nGenVisTau", 	nGenVisTau);
    output->add("nTrigObj", 	nTrigObj);
    output->add("nSoftActivityJet", 	nSoftActivityJet);
    output->add("nOtherPV", 	nOtherPV);
    output->add("nGenPart", 	nGenPart);
    output->add("nGenJetAK8", 	nGenJetAK8);
    output->add("nSubJet", 	nSubJet);
    output->add("nIsoTrack", 	nIsoTrack);
    output->add("nGenDressedLepton", 	nGenDressedLepton);
    output->add("nSV", 	nSV);
    output->add("nJet", 	nJet);
  
    output->add("Events/CaloMET_phi", 	CaloMET_phi);
    output->add("Events/CaloMET_pt", 	CaloMET_pt);
    output->add("Events/CaloMET_sumEt", 	CaloMET_sumEt);
    output->add("Events/Electron_charge[nElectron]", 	Electron_charge);
    output->add("Events/Electron_cleanmask[nElectron]",
                 Electron_cleanmask);
    output->add("Events/Electron_convVeto[nElectron]", 	Electron_convVeto);
    output->add("Events/Electron_cutBased[nElectron]", 	Electron_cutBased);
    output->add("Events/Electron_cutBased_HEEP[nElectron]",
                 Electron_cutBased_HEEP);
    output->add("Events/Electron_deltaEtaSC[nElectron]",
                 Electron_deltaEtaSC);
    output->add("Events/Electron_dr03EcalRecHitSumEt[nElectron]",
                 Electron_dr03EcalRecHitSumEt);
    output->add("Events/Electron_dr03HcalDepth1TowerSumEt[nElectron]",
                 Electron_dr03HcalDepth1TowerSumEt);
    output->add("Events/Electron_dr03TkSumPt[nElectron]",
                 Electron_dr03TkSumPt);
    output->add("Events/Electron_dxy[nElectron]", 	Electron_dxy);
    output->add("Events/Electron_dxyErr[nElectron]", 	Electron_dxyErr);
    output->add("Events/Electron_dz[nElectron]", 	Electron_dz);
    output->add("Events/Electron_dzErr[nElectron]", 	Electron_dzErr);
    output->add("Events/Electron_eCorr[nElectron]", 	Electron_eCorr);
    output->add("Events/Electron_eInvMinusPInv[nElectron]",
                 Electron_eInvMinusPInv);
    output->add("Events/Electron_energyErr[nElectron]",
                 Electron_energyErr);
    output->add("Events/Electron_eta[nElectron]", 	Electron_eta);
    output->add("Events/Electron_genPartFlav[nElectron]",
                 Electron_genPartFlav);
    output->add("Events/Electron_genPartIdx[nElectron]",
                 Electron_genPartIdx);
    output->add("Events/Electron_hoe[nElectron]", 	Electron_hoe);
    output->add("Events/Electron_ip3d[nElectron]", 	Electron_ip3d);
    output->add("Events/Electron_isPFcand[nElectron]", 	Electron_isPFcand);
    output->add("Events/Electron_jetIdx[nElectron]", 	Electron_jetIdx);
    output->add("Events/Electron_lostHits[nElectron]", 	Electron_lostHits);
    output->add("Events/Electron_mass[nElectron]", 	Electron_mass);
    output->add("Events/Electron_miniPFRelIso_all[nElectron]",
                 Electron_miniPFRelIso_all);
    output->add("Events/Electron_miniPFRelIso_chg[nElectron]",
                 Electron_miniPFRelIso_chg);
    output->add("Events/Electron_mvaFall17Iso[nElectron]",
                 Electron_mvaFall17Iso);
    output->add("Events/Electron_mvaFall17Iso_WP80[nElectron]",
                 Electron_mvaFall17Iso_WP80);
    output->add("Events/Electron_mvaFall17Iso_WP90[nElectron]",
                 Electron_mvaFall17Iso_WP90);
    output->add("Events/Electron_mvaFall17Iso_WPL[nElectron]",
                 Electron_mvaFall17Iso_WPL);
    output->add("Events/Electron_mvaFall17noIso[nElectron]",
                 Electron_mvaFall17noIso);
    output->add("Events/Electron_mvaFall17noIso_WP80[nElectron]",
                 Electron_mvaFall17noIso_WP80);
    output->add("Events/Electron_mvaFall17noIso_WP90[nElectron]",
                 Electron_mvaFall17noIso_WP90);
    output->add("Events/Electron_mvaFall17noIso_WPL[nElectron]",
                 Electron_mvaFall17noIso_WPL);
    output->add("Events/Electron_mvaTTH[nElectron]", 	Electron_mvaTTH);
    output->add("Events/Electron_pdgId[nElectron]", 	Electron_pdgId);
    output->add("Events/Electron_pfRelIso03_all[nElectron]",
                 Electron_pfRelIso03_all);
    output->add("Events/Electron_pfRelIso03_chg[nElectron]",
                 Electron_pfRelIso03_chg);
    output->add("Events/Electron_phi[nElectron]", 	Electron_phi);
    output->add("Events/Electron_photonIdx[nElectron]",
                 Electron_photonIdx);
    output->add("Events/Electron_pt[nElectron]", 	Electron_pt);
    output->add("Events/Electron_r9[nElectron]", 	Electron_r9);
    output->add("Events/Electron_sieie[nElectron]", 	Electron_sieie);
    output->add("Events/Electron_sip3d[nElectron]", 	Electron_sip3d);
    output->add("Events/Electron_tightCharge[nElectron]",
                 Electron_tightCharge);
    output->add("Events/Electron_vidNestedWPBitmap[nElectron]",
                 Electron_vidNestedWPBitmap);
    output->add("Events/FatJet_area[nFatJet]", 	FatJet_area);
    output->add("Events/FatJet_btagCMVA[nFatJet]", 	FatJet_btagCMVA);
    output->add("Events/FatJet_btagCSVV2[nFatJet]", 	FatJet_btagCSVV2);
    output->add("Events/FatJet_btagDeepB[nFatJet]", 	FatJet_btagDeepB);
    output->add("Events/FatJet_btagHbb[nFatJet]", 	FatJet_btagHbb);
    output->add("Events/FatJet_eta[nFatJet]", 	FatJet_eta);
    output->add("Events/FatJet_jetId[nFatJet]", 	FatJet_jetId);
    output->add("Events/FatJet_mass[nFatJet]", 	FatJet_mass);
    output->add("Events/FatJet_msoftdrop[nFatJet]", 	FatJet_msoftdrop);
    output->add("Events/FatJet_n2b1[nFatJet]", 	FatJet_n2b1);
    output->add("Events/FatJet_n3b1[nFatJet]", 	FatJet_n3b1);
    output->add("Events/FatJet_phi[nFatJet]", 	FatJet_phi);
    output->add("Events/FatJet_pt[nFatJet]", 	FatJet_pt);
    output->add("Events/FatJet_subJetIdx1[nFatJet]", 	FatJet_subJetIdx1);
    output->add("Events/FatJet_subJetIdx2[nFatJet]", 	FatJet_subJetIdx2);
    output->add("Events/FatJet_tau1[nFatJet]", 	FatJet_tau1);
    output->add("Events/FatJet_tau2[nFatJet]", 	FatJet_tau2);
    output->add("Events/FatJet_tau3[nFatJet]", 	FatJet_tau3);
    output->add("Events/FatJet_tau4[nFatJet]", 	FatJet_tau4);
    output->add("Events/Flag_BadChargedCandidateFilter",
                 Flag_BadChargedCandidateFilter);
    output->add("Events/Flag_BadChargedCandidateSummer16Filter",
                 Flag_BadChargedCandidateSummer16Filter);
    output->add("Events/Flag_BadPFMuonFilter", 	Flag_BadPFMuonFilter);
    output->add("Events/Flag_BadPFMuonSummer16Filter",
                 Flag_BadPFMuonSummer16Filter);
    output->add("Events/Flag_CSCTightHalo2015Filter",
                 Flag_CSCTightHalo2015Filter);
    output->add("Events/Flag_CSCTightHaloFilter", 	Flag_CSCTightHaloFilter);
    output->add("Events/Flag_CSCTightHaloTrkMuUnvetoFilter",
                 Flag_CSCTightHaloTrkMuUnvetoFilter);
    output->add("Events/Flag_EcalDeadCellBoundaryEnergyFilter",
                 Flag_EcalDeadCellBoundaryEnergyFilter);
    output->add("Events/Flag_EcalDeadCellTriggerPrimitiveFilter",
                 Flag_EcalDeadCellTriggerPrimitiveFilter);
    output->add("Events/Flag_HBHENoiseFilter", 	Flag_HBHENoiseFilter);
    output->add("Events/Flag_HBHENoiseIsoFilter", 	Flag_HBHENoiseIsoFilter);
    output->add("Events/Flag_HcalStripHaloFilter",
                 Flag_HcalStripHaloFilter);
    output->add("Events/Flag_METFilters", 	Flag_METFilters);
    output->add("Events/Flag_chargedHadronTrackResolutionFilter",
                 Flag_chargedHadronTrackResolutionFilter);
    output->add("Events/Flag_ecalBadCalibFilter", 	Flag_ecalBadCalibFilter);
    output->add("Events/Flag_ecalLaserCorrFilter",
                 Flag_ecalLaserCorrFilter);
    output->add("Events/Flag_eeBadScFilter", 	Flag_eeBadScFilter);
    output->add("Events/Flag_globalSuperTightHalo2016Filter",
                 Flag_globalSuperTightHalo2016Filter);
    output->add("Events/Flag_globalTightHalo2016Filter",
                 Flag_globalTightHalo2016Filter);
    output->add("Events/Flag_goodVertices", 	Flag_goodVertices);
    output->add("Events/Flag_hcalLaserEventFilter",
                 Flag_hcalLaserEventFilter);
    output->add("Events/Flag_muonBadTrackFilter", 	Flag_muonBadTrackFilter);
    output->add("Events/Flag_trkPOGFilters", 	Flag_trkPOGFilters);
    output->add("Events/Flag_trkPOG_logErrorTooManyClusters",
                 Flag_trkPOG_logErrorTooManyClusters);
    output->add("Events/Flag_trkPOG_manystripclus53X",
                 Flag_trkPOG_manystripclus53X);
    output->add("Events/Flag_trkPOG_toomanystripclus53X",
                 Flag_trkPOG_toomanystripclus53X);
    output->add("Events/GenDressedLepton_eta[nGenDressedLepton]",
                 GenDressedLepton_eta);
    output->add("Events/GenDressedLepton_mass[nGenDressedLepton]",
                 GenDressedLepton_mass);
    output->add("Events/GenDressedLepton_pdgId[nGenDressedLepton]",
                 GenDressedLepton_pdgId);
    output->add("Events/GenDressedLepton_phi[nGenDressedLepton]",
                 GenDressedLepton_phi);
    output->add("Events/GenDressedLepton_pt[nGenDressedLepton]",
                 GenDressedLepton_pt);
    output->add("Events/GenJetAK8_eta[nGenJetAK8]", 	GenJetAK8_eta);
    output->add("Events/GenJetAK8_hadronFlavour[nGenJetAK8]",
                 GenJetAK8_hadronFlavour);
    output->add("Events/GenJetAK8_mass[nGenJetAK8]", 	GenJetAK8_mass);
    output->add("Events/GenJetAK8_partonFlavour[nGenJetAK8]",
                 GenJetAK8_partonFlavour);
    output->add("Events/GenJetAK8_phi[nGenJetAK8]", 	GenJetAK8_phi);
    output->add("Events/GenJetAK8_pt[nGenJetAK8]", 	GenJetAK8_pt);
    output->add("Events/GenJet_eta[nGenJet]", 	GenJet_eta);
    output->add("Events/GenJet_hadronFlavour[nGenJet]",
                 GenJet_hadronFlavour);
    output->add("Events/GenJet_mass[nGenJet]", 	GenJet_mass);
    output->add("Events/GenJet_partonFlavour[nGenJet]",
                 GenJet_partonFlavour);
    output->add("Events/GenJet_phi[nGenJet]", 	GenJet_phi);
    output->add("Events/GenJet_pt[nGenJet]", 	GenJet_pt);
    output->add("Events/GenMET_phi", 	GenMET_phi);
    output->add("Events/GenMET_pt", 	GenMET_pt);
    output->add("Events/GenPart_eta[nGenPart]", 	GenPart_eta);
    output->add("Events/GenPart_genPartIdxMother[nGenPart]",
                 GenPart_genPartIdxMother);
    output->add("Events/GenPart_mass[nGenPart]", 	GenPart_mass);
    output->add("Events/GenPart_pdgId[nGenPart]", 	GenPart_pdgId);
    output->add("Events/GenPart_phi[nGenPart]", 	GenPart_phi);
    output->add("Events/GenPart_pt[nGenPart]", 	GenPart_pt);
    output->add("Events/GenPart_status[nGenPart]", 	GenPart_status);
    output->add("Events/GenPart_statusFlags[nGenPart]",
                 GenPart_statusFlags);
    output->add("Events/GenVisTau_charge[nGenVisTau]", 	GenVisTau_charge);
    output->add("Events/GenVisTau_eta[nGenVisTau]", 	GenVisTau_eta);
    output->add("Events/GenVisTau_genPartIdxMother[nGenVisTau]",
                 GenVisTau_genPartIdxMother);
    output->add("Events/GenVisTau_mass[nGenVisTau]", 	GenVisTau_mass);
    output->add("Events/GenVisTau_phi[nGenVisTau]", 	GenVisTau_phi);
    output->add("Events/GenVisTau_pt[nGenVisTau]", 	GenVisTau_pt);
    output->add("Events/GenVisTau_status[nGenVisTau]", 	GenVisTau_status);
    output->add("Events/Generator_binvar", 	Generator_binvar);
    output->add("Events/Generator_id1", 	Generator_id1);
    output->add("Events/Generator_id2", 	Generator_id2);
    output->add("Events/Generator_scalePDF", 	Generator_scalePDF);
    output->add("Events/Generator_weight", 	Generator_weight);
    output->add("Events/Generator_x1", 	Generator_x1);
    output->add("Events/Generator_x2", 	Generator_x2);
    output->add("Events/Generator_xpdf1", 	Generator_xpdf1);
    output->add("Events/Generator_xpdf2", 	Generator_xpdf2);
    output->add("Events/HLT_AK4CaloJet100", 	HLT_AK4CaloJet100);
    output->add("Events/HLT_AK4CaloJet120", 	HLT_AK4CaloJet120);
    output->add("Events/HLT_AK4CaloJet30", 	HLT_AK4CaloJet30);
    output->add("Events/HLT_AK4CaloJet40", 	HLT_AK4CaloJet40);
    output->add("Events/HLT_AK4CaloJet50", 	HLT_AK4CaloJet50);
    output->add("Events/HLT_AK4CaloJet80", 	HLT_AK4CaloJet80);
    output->add("Events/HLT_AK4PFJet100", 	HLT_AK4PFJet100);
    output->add("Events/HLT_AK4PFJet120", 	HLT_AK4PFJet120);
    output->add("Events/HLT_AK4PFJet30", 	HLT_AK4PFJet30);
    output->add("Events/HLT_AK4PFJet50", 	HLT_AK4PFJet50);
    output->add("Events/HLT_AK4PFJet80", 	HLT_AK4PFJet80);
    output->add("Events/HLT_AK8PFHT750_TrimMass50",
                 HLT_AK8PFHT750_TrimMass50);
    output->add("Events/HLT_AK8PFHT800_TrimMass50",
                 HLT_AK8PFHT800_TrimMass50);
    output->add("Events/HLT_AK8PFHT850_TrimMass50",
                 HLT_AK8PFHT850_TrimMass50);
    output->add("Events/HLT_AK8PFHT900_TrimMass50",
                 HLT_AK8PFHT900_TrimMass50);
    output->add("Events/HLT_AK8PFJet140", 	HLT_AK8PFJet140);
    output->add("Events/HLT_AK8PFJet200", 	HLT_AK8PFJet200);
    output->add("Events/HLT_AK8PFJet260", 	HLT_AK8PFJet260);
    output->add("Events/HLT_AK8PFJet320", 	HLT_AK8PFJet320);
    output->add("Events/HLT_AK8PFJet330_PFAK8BTagCSV_p1",
                 HLT_AK8PFJet330_PFAK8BTagCSV_p1);
    output->add("Events/HLT_AK8PFJet330_PFAK8BTagCSV_p17",
                 HLT_AK8PFJet330_PFAK8BTagCSV_p17);
    output->add("Events/HLT_AK8PFJet360_TrimMass30",
                 HLT_AK8PFJet360_TrimMass30);
    output->add("Events/HLT_AK8PFJet380_TrimMass30",
                 HLT_AK8PFJet380_TrimMass30);
    output->add("Events/HLT_AK8PFJet40", 	HLT_AK8PFJet40);
    output->add("Events/HLT_AK8PFJet400", 	HLT_AK8PFJet400);
    output->add("Events/HLT_AK8PFJet400_TrimMass30",
                 HLT_AK8PFJet400_TrimMass30);
    output->add("Events/HLT_AK8PFJet420_TrimMass30",
                 HLT_AK8PFJet420_TrimMass30);
    output->add("Events/HLT_AK8PFJet450", 	HLT_AK8PFJet450);
    output->add("Events/HLT_AK8PFJet500", 	HLT_AK8PFJet500);
    output->add("Events/HLT_AK8PFJet550", 	HLT_AK8PFJet550);
    output->add("Events/HLT_AK8PFJet60", 	HLT_AK8PFJet60);
    output->add("Events/HLT_AK8PFJet80", 	HLT_AK8PFJet80);
    output->add("Events/HLT_AK8PFJetFwd140", 	HLT_AK8PFJetFwd140);
    output->add("Events/HLT_AK8PFJetFwd200", 	HLT_AK8PFJetFwd200);
    output->add("Events/HLT_AK8PFJetFwd260", 	HLT_AK8PFJetFwd260);
    output->add("Events/HLT_AK8PFJetFwd320", 	HLT_AK8PFJetFwd320);
    output->add("Events/HLT_AK8PFJetFwd40", 	HLT_AK8PFJetFwd40);
    output->add("Events/HLT_AK8PFJetFwd400", 	HLT_AK8PFJetFwd400);
    output->add("Events/HLT_AK8PFJetFwd450", 	HLT_AK8PFJetFwd450);
    output->add("Events/HLT_AK8PFJetFwd500", 	HLT_AK8PFJetFwd500);
    output->add("Events/HLT_AK8PFJetFwd60", 	HLT_AK8PFJetFwd60);
    output->add("Events/HLT_AK8PFJetFwd80", 	HLT_AK8PFJetFwd80);
    output->add("Events/HLT_BTagMu_AK4DiJet110_Mu5",
                 HLT_BTagMu_AK4DiJet110_Mu5);
    output->add("Events/HLT_BTagMu_AK4DiJet170_Mu5",
                 HLT_BTagMu_AK4DiJet170_Mu5);
    output->add("Events/HLT_BTagMu_AK4DiJet20_Mu5",
                 HLT_BTagMu_AK4DiJet20_Mu5);
    output->add("Events/HLT_BTagMu_AK4DiJet40_Mu5",
                 HLT_BTagMu_AK4DiJet40_Mu5);
    output->add("Events/HLT_BTagMu_AK4DiJet70_Mu5",
                 HLT_BTagMu_AK4DiJet70_Mu5);
    output->add("Events/HLT_BTagMu_AK4Jet300_Mu5",
                 HLT_BTagMu_AK4Jet300_Mu5);
    output->add("Events/HLT_BTagMu_AK8DiJet170_Mu5",
                 HLT_BTagMu_AK8DiJet170_Mu5);
    output->add("Events/HLT_BTagMu_AK8Jet300_Mu5",
                 HLT_BTagMu_AK8Jet300_Mu5);
    output->add("Events/HLT_CaloJet500_NoJetID", 	HLT_CaloJet500_NoJetID);
    output->add("Events/HLT_CaloJet550_NoJetID", 	HLT_CaloJet550_NoJetID);
    output->add("Events/HLT_CaloMET100_HBHECleaned",
                 HLT_CaloMET100_HBHECleaned);
    output->add("Events/HLT_CaloMET100_NotCleaned",
                 HLT_CaloMET100_NotCleaned);
    output->add("Events/HLT_CaloMET110_NotCleaned",
                 HLT_CaloMET110_NotCleaned);
    output->add("Events/HLT_CaloMET250_HBHECleaned",
                 HLT_CaloMET250_HBHECleaned);
    output->add("Events/HLT_CaloMET250_NotCleaned",
                 HLT_CaloMET250_NotCleaned);
    output->add("Events/HLT_CaloMET300_HBHECleaned",
                 HLT_CaloMET300_HBHECleaned);
    output->add("Events/HLT_CaloMET350_HBHECleaned",
                 HLT_CaloMET350_HBHECleaned);
    output->add("Events/HLT_CaloMET70_HBHECleaned",
                 HLT_CaloMET70_HBHECleaned);
    output->add("Events/HLT_CaloMET80_HBHECleaned",
                 HLT_CaloMET80_HBHECleaned);
    output->add("Events/HLT_CaloMET80_NotCleaned",
                 HLT_CaloMET80_NotCleaned);
    output->add("Events/HLT_CaloMET90_HBHECleaned",
                 HLT_CaloMET90_HBHECleaned);
    output->add("Events/HLT_CaloMET90_NotCleaned",
                 HLT_CaloMET90_NotCleaned);
    output->add("Events/HLT_CaloMHT90", 	HLT_CaloMHT90);
    output->add("Events/HLT_DiEle27_WPTightCaloOnly_L1DoubleEG",
                 HLT_DiEle27_WPTightCaloOnly_L1DoubleEG);
    output->add("Events/HLT_DiJet110_35_Mjj650_PFMET110",
                 HLT_DiJet110_35_Mjj650_PFMET110);
    output->add("Events/HLT_DiJet110_35_Mjj650_PFMET120",
                 HLT_DiJet110_35_Mjj650_PFMET120);
    output->add("Events/HLT_DiJet110_35_Mjj650_PFMET130",
                 HLT_DiJet110_35_Mjj650_PFMET130);
    output->add("Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL",
                 HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
    output->add("Events/HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ",
                 HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
    output->add("Events/HLT_DiPFJet15_FBEta3_NoCaloMatched",
                 HLT_DiPFJet15_FBEta3_NoCaloMatched);
    output->add("Events/HLT_DiPFJet15_NoCaloMatched",
                 HLT_DiPFJet15_NoCaloMatched);
    output->add("Events/HLT_DiPFJet25_FBEta3_NoCaloMatched",
                 HLT_DiPFJet25_FBEta3_NoCaloMatched);
    output->add("Events/HLT_DiPFJet25_NoCaloMatched",
                 HLT_DiPFJet25_NoCaloMatched);
    output->add("Events/HLT_DiPFJetAve100_HFJEC", 	HLT_DiPFJetAve100_HFJEC);
    output->add("Events/HLT_DiPFJetAve140", 	HLT_DiPFJetAve140);
    output->add("Events/HLT_DiPFJetAve15_HFJEC", 	HLT_DiPFJetAve15_HFJEC);
    output->add("Events/HLT_DiPFJetAve160_HFJEC", 	HLT_DiPFJetAve160_HFJEC);
    output->add("Events/HLT_DiPFJetAve200", 	HLT_DiPFJetAve200);
    output->add("Events/HLT_DiPFJetAve220_HFJEC", 	HLT_DiPFJetAve220_HFJEC);
    output->add("Events/HLT_DiPFJetAve25_HFJEC", 	HLT_DiPFJetAve25_HFJEC);
    output->add("Events/HLT_DiPFJetAve260", 	HLT_DiPFJetAve260);
    output->add("Events/HLT_DiPFJetAve300_HFJEC", 	HLT_DiPFJetAve300_HFJEC);
    output->add("Events/HLT_DiPFJetAve320", 	HLT_DiPFJetAve320);
    output->add("Events/HLT_DiPFJetAve35_HFJEC", 	HLT_DiPFJetAve35_HFJEC);
    output->add("Events/HLT_DiPFJetAve40", 	HLT_DiPFJetAve40);
    output->add("Events/HLT_DiPFJetAve400", 	HLT_DiPFJetAve400);
    output->add("Events/HLT_DiPFJetAve500", 	HLT_DiPFJetAve500);
    output->add("Events/HLT_DiPFJetAve60", 	HLT_DiPFJetAve60);
    output->add("Events/HLT_DiPFJetAve60_HFJEC", 	HLT_DiPFJetAve60_HFJEC);
    output->add("Events/HLT_DiPFJetAve80", 	HLT_DiPFJetAve80);
    output->add("Events/HLT_DiPFJetAve80_HFJEC", 	HLT_DiPFJetAve80_HFJEC);
    output->add("Events/HLT_DiSC30_18_EIso_AND_HE_Mass70",
                 HLT_DiSC30_18_EIso_AND_HE_Mass70);
    output->add("Events/HLT_Dimuon0_Jpsi", 	HLT_Dimuon0_Jpsi);
    output->add("Events/HLT_Dimuon0_Jpsi3p5_Muon2",
                 HLT_Dimuon0_Jpsi3p5_Muon2);
    output->add("Events/HLT_Dimuon0_Jpsi_L1_4R_0er1p5R",
                 HLT_Dimuon0_Jpsi_L1_4R_0er1p5R);
    output->add("Events/HLT_Dimuon0_Jpsi_L1_NoOS",
                 HLT_Dimuon0_Jpsi_L1_NoOS);
    output->add("Events/HLT_Dimuon0_Jpsi_NoVertexing",
                 HLT_Dimuon0_Jpsi_NoVertexing);
    output->add("Events/HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R",
                 HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R);
    output->add("Events/HLT_Dimuon0_Jpsi_NoVertexing_NoOS",
                 HLT_Dimuon0_Jpsi_NoVertexing_NoOS);
    output->add("Events/HLT_Dimuon0_LowMass", 	HLT_Dimuon0_LowMass);
    output->add("Events/HLT_Dimuon0_LowMass_L1_0er1p5",
                 HLT_Dimuon0_LowMass_L1_0er1p5);
    output->add("Events/HLT_Dimuon0_LowMass_L1_0er1p5R",
                 HLT_Dimuon0_LowMass_L1_0er1p5R);
    output->add("Events/HLT_Dimuon0_LowMass_L1_4",
                 HLT_Dimuon0_LowMass_L1_4);
    output->add("Events/HLT_Dimuon0_LowMass_L1_4R",
                 HLT_Dimuon0_LowMass_L1_4R);
    output->add("Events/HLT_Dimuon0_LowMass_L1_TM530",
                 HLT_Dimuon0_LowMass_L1_TM530);
    output->add("Events/HLT_Dimuon0_Upsilon_L1_4p5",
                 HLT_Dimuon0_Upsilon_L1_4p5);
    output->add("Events/HLT_Dimuon0_Upsilon_L1_4p5NoOS",
                 HLT_Dimuon0_Upsilon_L1_4p5NoOS);
    output->add("Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0",
                 HLT_Dimuon0_Upsilon_L1_4p5er2p0);
    output->add("Events/HLT_Dimuon0_Upsilon_L1_4p5er2p0M",
                 HLT_Dimuon0_Upsilon_L1_4p5er2p0M);
    output->add("Events/HLT_Dimuon0_Upsilon_L1_5",
                 HLT_Dimuon0_Upsilon_L1_5);
    output->add("Events/HLT_Dimuon0_Upsilon_L1_5M",
                 HLT_Dimuon0_Upsilon_L1_5M);
    output->add("Events/HLT_Dimuon0_Upsilon_Muon_L1_TM0",
                 HLT_Dimuon0_Upsilon_Muon_L1_TM0);
    output->add("Events/HLT_Dimuon0_Upsilon_Muon_NoL1Mass",
                 HLT_Dimuon0_Upsilon_Muon_NoL1Mass);
    output->add("Events/HLT_Dimuon0_Upsilon_NoVertexing",
                 HLT_Dimuon0_Upsilon_NoVertexing);
    output->add("Events/HLT_Dimuon10_PsiPrime_Barrel_Seagulls",
                 HLT_Dimuon10_PsiPrime_Barrel_Seagulls);
    output->add("Events/HLT_Dimuon10_Upsilon_Barrel_Seagulls",
                 HLT_Dimuon10_Upsilon_Barrel_Seagulls);
    output->add("Events/HLT_Dimuon12_Upsilon_eta1p5",
                 HLT_Dimuon12_Upsilon_eta1p5);
    output->add("Events/HLT_Dimuon14_Phi_Barrel_Seagulls",
                 HLT_Dimuon14_Phi_Barrel_Seagulls);
    output->add("Events/HLT_Dimuon18_PsiPrime", 	HLT_Dimuon18_PsiPrime);
    output->add("Events/HLT_Dimuon18_PsiPrime_noCorrL1",
                 HLT_Dimuon18_PsiPrime_noCorrL1);
    output->add("Events/HLT_Dimuon20_Jpsi_Barrel_Seagulls",
                 HLT_Dimuon20_Jpsi_Barrel_Seagulls);
    output->add("Events/HLT_Dimuon24_Phi_noCorrL1",
                 HLT_Dimuon24_Phi_noCorrL1);
    output->add("Events/HLT_Dimuon24_Upsilon_noCorrL1",
                 HLT_Dimuon24_Upsilon_noCorrL1);
    output->add("Events/HLT_Dimuon25_Jpsi", 	HLT_Dimuon25_Jpsi);
    output->add("Events/HLT_Dimuon25_Jpsi_noCorrL1",
                 HLT_Dimuon25_Jpsi_noCorrL1);
    output->add("Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55",
                 HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
    output->add("Events/HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55",
                 HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
    output->add("Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55",
                 HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
    output->add("Events/HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55",
                 HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
    output->add("Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55",
                 HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
    output->add("Events/HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55",
                 HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
    output->add("Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90",
                 HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90);
    output->add("Events/HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95",
                 HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95);
    output->add("Events/HLT_DoubleEle24_eta2p1_WPTight_Gsf",
                 HLT_DoubleEle24_eta2p1_WPTight_Gsf);
    output->add("Events/HLT_DoubleEle25_CaloIdL_MW",
                 HLT_DoubleEle25_CaloIdL_MW);
    output->add("Events/HLT_DoubleEle27_CaloIdL_MW",
                 HLT_DoubleEle27_CaloIdL_MW);
    output->add("Events/HLT_DoubleEle33_CaloIdL_MW",
                 HLT_DoubleEle33_CaloIdL_MW);
    output->add("Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350",
                 HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350);
    output->add("Events/HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350",
                 HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350);
    output->add("Events/HLT_DoubleIsoMu20_eta2p1",
                 HLT_DoubleIsoMu20_eta2p1);
    output->add("Events/HLT_DoubleIsoMu24_eta2p1",
                 HLT_DoubleIsoMu24_eta2p1);
    output->add("Events/HLT_DoubleL2Mu50", 	HLT_DoubleL2Mu50);
    output->add("Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg",
                 HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
    output->add("Events/HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg",
                 HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg);
    output->add("Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg",
                 HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
    output->add("Events/HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg",
                 HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg);
    output->add("Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg",
                 HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
    output->add("Events/HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg",
                 HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg);
    output->add("Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg",
                 HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
    output->add("Events/HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg",
                 HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg);
    output->add("Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4",
                 HLT_DoubleMu20_7_Mass0to30_L1_DM4);
    output->add("Events/HLT_DoubleMu20_7_Mass0to30_L1_DM4EG",
                 HLT_DoubleMu20_7_Mass0to30_L1_DM4EG);
    output->add("Events/HLT_DoubleMu20_7_Mass0to30_Photon23",
                 HLT_DoubleMu20_7_Mass0to30_Photon23);
    output->add("Events/HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi",
                 HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi);
    output->add("Events/HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi",
                 HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi);
    output->add("Events/HLT_DoubleMu3_DCA_PFMET50_PFMHT60",
                 HLT_DoubleMu3_DCA_PFMET50_PFMHT60);
    output->add("Events/HLT_DoubleMu3_DZ_PFMET50_PFMHT60",
                 HLT_DoubleMu3_DZ_PFMET50_PFMHT60);
    output->add("Events/HLT_DoubleMu3_DZ_PFMET70_PFMHT70",
                 HLT_DoubleMu3_DZ_PFMET70_PFMHT70);
    output->add("Events/HLT_DoubleMu3_DZ_PFMET90_PFMHT90",
                 HLT_DoubleMu3_DZ_PFMET90_PFMHT90);
    output->add("Events/HLT_DoubleMu3_Trk_Tau3mu",
                 HLT_DoubleMu3_Trk_Tau3mu);
    output->add("Events/HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass",
                 HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass);
    output->add("Events/HLT_DoubleMu43NoFiltersNoVtx",
                 HLT_DoubleMu43NoFiltersNoVtx);
    output->add("Events/HLT_DoubleMu48NoFiltersNoVtx",
                 HLT_DoubleMu48NoFiltersNoVtx);
    output->add("Events/HLT_DoubleMu4_3_Bs", 	HLT_DoubleMu4_3_Bs);
    output->add("Events/HLT_DoubleMu4_3_Jpsi_Displaced",
                 HLT_DoubleMu4_3_Jpsi_Displaced);
    output->add("Events/HLT_DoubleMu4_JpsiTrkTrk_Displaced",
                 HLT_DoubleMu4_JpsiTrkTrk_Displaced);
    output->add("Events/HLT_DoubleMu4_JpsiTrk_Displaced",
                 HLT_DoubleMu4_JpsiTrk_Displaced);
    output->add("Events/HLT_DoubleMu4_Jpsi_Displaced",
                 HLT_DoubleMu4_Jpsi_Displaced);
    output->add("Events/HLT_DoubleMu4_Jpsi_NoVertexing",
                 HLT_DoubleMu4_Jpsi_NoVertexing);
    output->add("Events/HLT_DoubleMu4_LowMassNonResonantTrk_Displaced",
                 HLT_DoubleMu4_LowMassNonResonantTrk_Displaced);
    output->add("Events/HLT_DoubleMu4_Mass8_DZ_PFHT350",
                 HLT_DoubleMu4_Mass8_DZ_PFHT350);
    output->add("Events/HLT_DoubleMu4_PsiPrimeTrk_Displaced",
                 HLT_DoubleMu4_PsiPrimeTrk_Displaced);
    output->add("Events/HLT_DoubleMu8_Mass8_PFHT350",
                 HLT_DoubleMu8_Mass8_PFHT350);
    output->add("Events/HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33",
                 HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33);
    output->add("Events/HLT_DoublePFJets100_CaloBTagCSV_p33",
                 HLT_DoublePFJets100_CaloBTagCSV_p33);
    output->add("Events/HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33",
                 HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33);
    output->add("Events/HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33",
                 HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33);
    output->add("Events/HLT_DoublePFJets200_CaloBTagCSV_p33",
                 HLT_DoublePFJets200_CaloBTagCSV_p33);
    output->add("Events/HLT_DoublePFJets350_CaloBTagCSV_p33",
                 HLT_DoublePFJets350_CaloBTagCSV_p33);
    output->add("Events/HLT_DoublePFJets40_CaloBTagCSV_p33",
                 HLT_DoublePFJets40_CaloBTagCSV_p33);
    output->add("Events/HLT_DoublePhoton33_CaloIdL",
                 HLT_DoublePhoton33_CaloIdL);
    output->add("Events/HLT_DoublePhoton70", 	HLT_DoublePhoton70);
    output->add("Events/HLT_DoublePhoton85", 	HLT_DoublePhoton85);
    output->add("Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg",
                 HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
    output->add("Events/HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg",
                 HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg);
    output->add("Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg",
                 HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
    output->add("Events/HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg",
                 HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg);
    output->add("Events/HLT_ECALHT800", 	HLT_ECALHT800);
    output->add("Events/HLT_EcalCalibration", 	HLT_EcalCalibration);
    output->add("Events/HLT_Ele115_CaloIdVT_GsfTrkIdT",
                 HLT_Ele115_CaloIdVT_GsfTrkIdT);
    output->add("Events/HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30",
                 HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
    output->add("Events/HLT_Ele135_CaloIdVT_GsfTrkIdT",
                 HLT_Ele135_CaloIdVT_GsfTrkIdT);
    output->add("Events/HLT_Ele145_CaloIdVT_GsfTrkIdT",
                 HLT_Ele145_CaloIdVT_GsfTrkIdT);
    output->add("Events/HLT_Ele15_IsoVVVL_PFHT450",
                 HLT_Ele15_IsoVVVL_PFHT450);
    output->add("Events/HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5",
                 HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5);
    output->add("Events/HLT_Ele15_IsoVVVL_PFHT450_PFMET50",
                 HLT_Ele15_IsoVVVL_PFHT450_PFMET50);
    output->add("Events/HLT_Ele15_IsoVVVL_PFHT600",
                 HLT_Ele15_IsoVVVL_PFHT600);
    output->add("Events/HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL",
                 HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
    output->add("Events/HLT_Ele17_CaloIdM_TrackIdM_PFJet30",
                 HLT_Ele17_CaloIdM_TrackIdM_PFJet30);
    output->add("Events/HLT_Ele200_CaloIdVT_GsfTrkIdT",
                 HLT_Ele200_CaloIdVT_GsfTrkIdT);
    output->add("Events/HLT_Ele20_WPLoose_Gsf", 	HLT_Ele20_WPLoose_Gsf);
    output->add("Events/HLT_Ele20_WPTight_Gsf", 	HLT_Ele20_WPTight_Gsf);
    output->add("Events/HLT_Ele20_eta2p1_WPLoose_Gsf",
                 HLT_Ele20_eta2p1_WPLoose_Gsf);
    output->add("Events/HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30",
                 HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
    output->add("Events/HLT_Ele23_CaloIdM_TrackIdM_PFJet30",
                 HLT_Ele23_CaloIdM_TrackIdM_PFJet30);
    output->add("Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL",
                 HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
    output->add("Events/HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ",
                 HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    output->add("Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1",
                 HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1);
    output->add("Events/HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1",
                 HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1);
    output->add("Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1",
                 HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1);
    output->add("Events/HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1",
                 HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1);
    output->add("Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1",
                 HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1);
    output->add("Events/HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1",
                 HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1);
    output->add("Events/HLT_Ele250_CaloIdVT_GsfTrkIdT",
                 HLT_Ele250_CaloIdVT_GsfTrkIdT);
    output->add("Events/HLT_Ele27_Ele37_CaloIdL_MW",
                 HLT_Ele27_Ele37_CaloIdL_MW);
    output->add("Events/HLT_Ele27_WPTight_Gsf", 	HLT_Ele27_WPTight_Gsf);
    output->add("Events/HLT_Ele28_HighEta_SC20_Mass55",
                 HLT_Ele28_HighEta_SC20_Mass55);
    output->add("Events/HLT_Ele28_eta2p1_WPTight_Gsf_HT150",
                 HLT_Ele28_eta2p1_WPTight_Gsf_HT150);
    output->add("Events/HLT_Ele300_CaloIdVT_GsfTrkIdT",
                 HLT_Ele300_CaloIdVT_GsfTrkIdT);
    output->add("Events/HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned",
                 HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned);
    output->add("Events/HLT_Ele32_WPTight_Gsf", 	HLT_Ele32_WPTight_Gsf);
    output->add("Events/HLT_Ele32_WPTight_Gsf_L1DoubleEG",
                 HLT_Ele32_WPTight_Gsf_L1DoubleEG);
    output->add("Events/HLT_Ele35_WPTight_Gsf", 	HLT_Ele35_WPTight_Gsf);
    output->add("Events/HLT_Ele35_WPTight_Gsf_L1EGMT",
                 HLT_Ele35_WPTight_Gsf_L1EGMT);
    output->add("Events/HLT_Ele38_WPTight_Gsf", 	HLT_Ele38_WPTight_Gsf);
    output->add("Events/HLT_Ele40_WPTight_Gsf", 	HLT_Ele40_WPTight_Gsf);
    output->add("Events/HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165",
                 HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165);
    output->add("Events/HLT_Ele50_IsoVVVL_PFHT450",
                 HLT_Ele50_IsoVVVL_PFHT450);
    output->add("Events/HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30",
                 HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30);
    output->add("Events/HLT_Ele8_CaloIdM_TrackIdM_PFJet30",
                 HLT_Ele8_CaloIdM_TrackIdM_PFJet30);
    output->add("Events/HLT_FullTrack_Multiplicity100",
                 HLT_FullTrack_Multiplicity100);
    output->add("Events/HLT_FullTrack_Multiplicity130",
                 HLT_FullTrack_Multiplicity130);
    output->add("Events/HLT_FullTrack_Multiplicity155",
                 HLT_FullTrack_Multiplicity155);
    output->add("Events/HLT_FullTrack_Multiplicity85",
                 HLT_FullTrack_Multiplicity85);
    output->add("Events/HLT_HISinglePhoton10_Eta3p1ForPPRef",
                 HLT_HISinglePhoton10_Eta3p1ForPPRef);
    output->add("Events/HLT_HISinglePhoton20_Eta3p1ForPPRef",
                 HLT_HISinglePhoton20_Eta3p1ForPPRef);
    output->add("Events/HLT_HISinglePhoton30_Eta3p1ForPPRef",
                 HLT_HISinglePhoton30_Eta3p1ForPPRef);
    output->add("Events/HLT_HISinglePhoton40_Eta3p1ForPPRef",
                 HLT_HISinglePhoton40_Eta3p1ForPPRef);
    output->add("Events/HLT_HISinglePhoton50_Eta3p1ForPPRef",
                 HLT_HISinglePhoton50_Eta3p1ForPPRef);
    output->add("Events/HLT_HISinglePhoton60_Eta3p1ForPPRef",
                 HLT_HISinglePhoton60_Eta3p1ForPPRef);
    output->add("Events/HLT_HT300_Beamspot", 	HLT_HT300_Beamspot);
    output->add("Events/HLT_HT400_DisplacedDijet40_DisplacedTrack",
                 HLT_HT400_DisplacedDijet40_DisplacedTrack);
    output->add("Events/HLT_HT425", 	HLT_HT425);
    output->add("Events/HLT_HT430_DisplacedDijet40_DisplacedTrack",
                 HLT_HT430_DisplacedDijet40_DisplacedTrack);
    output->add("Events/HLT_HT430_DisplacedDijet60_DisplacedTrack",
                 HLT_HT430_DisplacedDijet60_DisplacedTrack);
    output->add("Events/HLT_HT430_DisplacedDijet80_DisplacedTrack",
                 HLT_HT430_DisplacedDijet80_DisplacedTrack);
    output->add("Events/HLT_HT450_Beamspot", 	HLT_HT450_Beamspot);
    output->add("Events/HLT_HT550_DisplacedDijet60_Inclusive",
                 HLT_HT550_DisplacedDijet60_Inclusive);
    output->add("Events/HLT_HT550_DisplacedDijet80_Inclusive",
                 HLT_HT550_DisplacedDijet80_Inclusive);
    output->add("Events/HLT_HT650_DisplacedDijet60_Inclusive",
                 HLT_HT650_DisplacedDijet60_Inclusive);
    output->add("Events/HLT_HT650_DisplacedDijet80_Inclusive",
                 HLT_HT650_DisplacedDijet80_Inclusive);
    output->add("Events/HLT_HT750_DisplacedDijet80_Inclusive",
                 HLT_HT750_DisplacedDijet80_Inclusive);
    output->add("Events/HLT_HcalCalibration", 	HLT_HcalCalibration);
    output->add("Events/HLT_HcalIsolatedbunch", 	HLT_HcalIsolatedbunch);
    output->add("Events/HLT_HcalNZS", 	HLT_HcalNZS);
    output->add("Events/HLT_HcalPhiSym", 	HLT_HcalPhiSym);
    output->add("Events/HLT_IsoMu20", 	HLT_IsoMu20);
    output->add("Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1",
                 HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1);
    output->add("Events/HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1",
                 HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1);
    output->add("Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1",
                 HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1);
    output->add("Events/HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1",
                 HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1);
    output->add("Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1",
                 HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1);
    output->add("Events/HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1",
                 HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1);
    output->add("Events/HLT_IsoMu24", 	HLT_IsoMu24);
    output->add("Events/HLT_IsoMu24_eta2p1", 	HLT_IsoMu24_eta2p1);
    output->add("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1",
                 HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1);
    output->add("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1",
                 HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1);
    output->add("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1",
                 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1);
    output->add("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1",
                 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1);
    output->add("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr",
                 HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
    output->add("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1",
                 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1);
    output->add("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1",
                 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1);
    output->add("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1",
                 HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1);
    output->add("Events/HLT_IsoMu27", 	HLT_IsoMu27);
    output->add("Events/HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1",
                 HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1);
    output->add("Events/HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1",
                 HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1);
    output->add("Events/HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1",
                 HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1);
    output->add("Events/HLT_IsoMu30", 	HLT_IsoMu30);
    output->add("Events/HLT_IsoTrackHB", 	HLT_IsoTrackHB);
    output->add("Events/HLT_IsoTrackHE", 	HLT_IsoTrackHE);
    output->add("Events/HLT_L1ETMHadSeeds", 	HLT_L1ETMHadSeeds);
    output->add("Events/HLT_L1MinimumBiasHF0OR", 	HLT_L1MinimumBiasHF0OR);
    output->add("Events/HLT_L1MinimumBiasHF_OR", 	HLT_L1MinimumBiasHF_OR);
    output->add("Events/HLT_L1NotBptxOR", 	HLT_L1NotBptxOR);
    output->add("Events/HLT_L1SingleMu18", 	HLT_L1SingleMu18);
    output->add("Events/HLT_L1SingleMu25", 	HLT_L1SingleMu25);
    output->add("Events/HLT_L1UnpairedBunchBptxMinus",
                 HLT_L1UnpairedBunchBptxMinus);
    output->add("Events/HLT_L1UnpairedBunchBptxPlus",
                 HLT_L1UnpairedBunchBptxPlus);
    output->add("Events/HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142",
                 HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142);
    output->add("Events/HLT_L1_DoubleJet30_Mass_Min400_Mu10",
                 HLT_L1_DoubleJet30_Mass_Min400_Mu10);
    output->add("Events/HLT_L2Mu10", 	HLT_L2Mu10);
    output->add("Events/HLT_L2Mu10_NoVertex_NoBPTX",
                 HLT_L2Mu10_NoVertex_NoBPTX);
    output->add("Events/HLT_L2Mu10_NoVertex_NoBPTX3BX",
                 HLT_L2Mu10_NoVertex_NoBPTX3BX);
    output->add("Events/HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX",
                 HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX);
    output->add("Events/HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX",
                 HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX);
    output->add("Events/HLT_L2Mu50", 	HLT_L2Mu50);
    output->add("Events/HLT_MET105_IsoTrk50", 	HLT_MET105_IsoTrk50);
    output->add("Events/HLT_MET120_IsoTrk50", 	HLT_MET120_IsoTrk50);
    output->add("Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1",
                 HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1);
    output->add("Events/HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr",
                 HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr);
    output->add("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr",
                 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
    output->add("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100",
                 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100);
    output->add("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110",
                 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110);
    output->add("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120",
                 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120);
    output->add("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130",
                 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130);
    output->add("Events/HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90",
                 HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90);
    output->add("Events/HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight",
                 HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight);
    output->add("Events/HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight",
                 HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
    output->add("Events/HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight",
                 HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight);
    output->add("Events/HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight",
                 HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight);
    output->add("Events/HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60",
                 HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60);
    output->add("Events/HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33",
                 HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33);
    output->add("Events/HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33",
                 HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33);
    output->add("Events/HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33",
                 HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33);
    output->add("Events/HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33",
                 HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33);
    output->add("Events/HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33",
                 HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33);
    output->add("Events/HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33",
                 HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33);
    output->add("Events/HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33",
                 HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33);
    output->add("Events/HLT_Mu12_DoublePhoton20", 	HLT_Mu12_DoublePhoton20);
    output->add("Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL",
                 HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
    output->add("Events/HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ",
                 HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
    output->add("Events/HLT_Mu15_IsoVVVL_PFHT450",
                 HLT_Mu15_IsoVVVL_PFHT450);
    output->add("Events/HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5",
                 HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5);
    output->add("Events/HLT_Mu15_IsoVVVL_PFHT450_PFMET50",
                 HLT_Mu15_IsoVVVL_PFHT450_PFMET50);
    output->add("Events/HLT_Mu15_IsoVVVL_PFHT600",
                 HLT_Mu15_IsoVVVL_PFHT600);
    output->add("Events/HLT_Mu17", 	HLT_Mu17);
    output->add("Events/HLT_Mu17_Photon30_IsoCaloId",
                 HLT_Mu17_Photon30_IsoCaloId);
    output->add("Events/HLT_Mu17_TrkIsoVVL", 	HLT_Mu17_TrkIsoVVL);
    output->add("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL",
                 HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
    output->add("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ",
                 HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
    output->add("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8",
                 HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
    output->add("Events/HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8",
                 HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
    output->add("Events/HLT_Mu18_Mu9", 	HLT_Mu18_Mu9);
    output->add("Events/HLT_Mu18_Mu9_DZ", 	HLT_Mu18_Mu9_DZ);
    output->add("Events/HLT_Mu18_Mu9_SameSign", 	HLT_Mu18_Mu9_SameSign);
    output->add("Events/HLT_Mu18_Mu9_SameSign_DZ",
                 HLT_Mu18_Mu9_SameSign_DZ);
    output->add("Events/HLT_Mu19", 	HLT_Mu19);
    output->add("Events/HLT_Mu19_TrkIsoVVL", 	HLT_Mu19_TrkIsoVVL);
    output->add("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL",
                 HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL);
    output->add("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ",
                 HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ);
    output->add("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8",
                 HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
    output->add("Events/HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8",
                 HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
    output->add("Events/HLT_Mu20", 	HLT_Mu20);
    output->add("Events/HLT_Mu20_Mu10", 	HLT_Mu20_Mu10);
    output->add("Events/HLT_Mu20_Mu10_DZ", 	HLT_Mu20_Mu10_DZ);
    output->add("Events/HLT_Mu20_Mu10_SameSign", 	HLT_Mu20_Mu10_SameSign);
    output->add("Events/HLT_Mu20_Mu10_SameSign_DZ",
                 HLT_Mu20_Mu10_SameSign_DZ);
    output->add("Events/HLT_Mu20_TkMu0_Phi", 	HLT_Mu20_TkMu0_Phi);
    output->add("Events/HLT_Mu23_Mu12", 	HLT_Mu23_Mu12);
    output->add("Events/HLT_Mu23_Mu12_DZ", 	HLT_Mu23_Mu12_DZ);
    output->add("Events/HLT_Mu23_Mu12_SameSign", 	HLT_Mu23_Mu12_SameSign);
    output->add("Events/HLT_Mu23_Mu12_SameSign_DZ",
                 HLT_Mu23_Mu12_SameSign_DZ);
    output->add("Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL",
                 HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
    output->add("Events/HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ",
                 HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    output->add("Events/HLT_Mu25_TkMu0_Onia", 	HLT_Mu25_TkMu0_Onia);
    output->add("Events/HLT_Mu25_TkMu0_Phi", 	HLT_Mu25_TkMu0_Phi);
    output->add("Events/HLT_Mu27", 	HLT_Mu27);
    output->add("Events/HLT_Mu27_Ele37_CaloIdL_MW",
                 HLT_Mu27_Ele37_CaloIdL_MW);
    output->add("Events/HLT_Mu30_TkMu0_Onia", 	HLT_Mu30_TkMu0_Onia);
    output->add("Events/HLT_Mu37_Ele27_CaloIdL_MW",
                 HLT_Mu37_Ele27_CaloIdL_MW);
    output->add("Events/HLT_Mu37_TkMu27", 	HLT_Mu37_TkMu27);
    output->add("Events/HLT_Mu3_PFJet40", 	HLT_Mu3_PFJet40);
    output->add("Events/HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL",
                 HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL);
    output->add("Events/HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL",
                 HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL);
    output->add("Events/HLT_Mu50", 	HLT_Mu50);
    output->add("Events/HLT_Mu50_IsoVVVL_PFHT450",
                 HLT_Mu50_IsoVVVL_PFHT450);
    output->add("Events/HLT_Mu55", 	HLT_Mu55);
    output->add("Events/HLT_Mu7p5_L2Mu2_Jpsi", 	HLT_Mu7p5_L2Mu2_Jpsi);
    output->add("Events/HLT_Mu7p5_L2Mu2_Upsilon", 	HLT_Mu7p5_L2Mu2_Upsilon);
    output->add("Events/HLT_Mu7p5_Track2_Jpsi", 	HLT_Mu7p5_Track2_Jpsi);
    output->add("Events/HLT_Mu7p5_Track2_Upsilon",
                 HLT_Mu7p5_Track2_Upsilon);
    output->add("Events/HLT_Mu7p5_Track3p5_Jpsi", 	HLT_Mu7p5_Track3p5_Jpsi);
    output->add("Events/HLT_Mu7p5_Track3p5_Upsilon",
                 HLT_Mu7p5_Track3p5_Upsilon);
    output->add("Events/HLT_Mu7p5_Track7_Jpsi", 	HLT_Mu7p5_Track7_Jpsi);
    output->add("Events/HLT_Mu7p5_Track7_Upsilon",
                 HLT_Mu7p5_Track7_Upsilon);
    output->add("Events/HLT_Mu8", 	HLT_Mu8);
    output->add("Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL",
                 HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
    output->add("Events/HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ",
                 HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
    output->add("Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350",
                 HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350);
    output->add("Events/HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ",
                 HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
    output->add("Events/HLT_Mu8_TrkIsoVVL", 	HLT_Mu8_TrkIsoVVL);
    output->add("Events/HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60",
                 HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
    output->add("Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL",
                 HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
    output->add("Events/HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ",
                 HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
    output->add("Events/HLT_OldMu100", 	HLT_OldMu100);
    output->add("Events/HLT_PFHT1050", 	HLT_PFHT1050);
    output->add("Events/HLT_PFHT180", 	HLT_PFHT180);
    output->add("Events/HLT_PFHT250", 	HLT_PFHT250);
    output->add("Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40",
                 HLT_PFHT300PT30_QuadPFJet_75_60_45_40);
    output->add("Events/HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0",
                 HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0);
    output->add("Events/HLT_PFHT350", 	HLT_PFHT350);
    output->add("Events/HLT_PFHT350MinPFJet15", 	HLT_PFHT350MinPFJet15);
    output->add("Events/HLT_PFHT370", 	HLT_PFHT370);
    output->add("Events/HLT_PFHT380_SixPFJet32", 	HLT_PFHT380_SixPFJet32);
    output->add("Events/HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2",
                 HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2);
    output->add("Events/HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2",
                 HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2);
    output->add("Events/HLT_PFHT430", 	HLT_PFHT430);
    output->add("Events/HLT_PFHT430_SixPFJet40", 	HLT_PFHT430_SixPFJet40);
    output->add("Events/HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5",
                 HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5);
    output->add("Events/HLT_PFHT500_PFMET100_PFMHT100_IDTight",
                 HLT_PFHT500_PFMET100_PFMHT100_IDTight);
    output->add("Events/HLT_PFHT500_PFMET110_PFMHT110_IDTight",
                 HLT_PFHT500_PFMET110_PFMHT110_IDTight);
    output->add("Events/HLT_PFHT510", 	HLT_PFHT510);
    output->add("Events/HLT_PFHT590", 	HLT_PFHT590);
    output->add("Events/HLT_PFHT680", 	HLT_PFHT680);
    output->add("Events/HLT_PFHT700_PFMET85_PFMHT85_IDTight",
                 HLT_PFHT700_PFMET85_PFMHT85_IDTight);
    output->add("Events/HLT_PFHT700_PFMET95_PFMHT95_IDTight",
                 HLT_PFHT700_PFMET95_PFMHT95_IDTight);
    output->add("Events/HLT_PFHT780", 	HLT_PFHT780);
    output->add("Events/HLT_PFHT800_PFMET75_PFMHT75_IDTight",
                 HLT_PFHT800_PFMET75_PFMHT75_IDTight);
    output->add("Events/HLT_PFHT800_PFMET85_PFMHT85_IDTight",
                 HLT_PFHT800_PFMET85_PFMHT85_IDTight);
    output->add("Events/HLT_PFHT890", 	HLT_PFHT890);
    output->add("Events/HLT_PFJet140", 	HLT_PFJet140);
    output->add("Events/HLT_PFJet200", 	HLT_PFJet200);
    output->add("Events/HLT_PFJet260", 	HLT_PFJet260);
    output->add("Events/HLT_PFJet320", 	HLT_PFJet320);
    output->add("Events/HLT_PFJet40", 	HLT_PFJet40);
    output->add("Events/HLT_PFJet400", 	HLT_PFJet400);
    output->add("Events/HLT_PFJet450", 	HLT_PFJet450);
    output->add("Events/HLT_PFJet500", 	HLT_PFJet500);
    output->add("Events/HLT_PFJet550", 	HLT_PFJet550);
    output->add("Events/HLT_PFJet60", 	HLT_PFJet60);
    output->add("Events/HLT_PFJet80", 	HLT_PFJet80);
    output->add("Events/HLT_PFJetFwd140", 	HLT_PFJetFwd140);
    output->add("Events/HLT_PFJetFwd200", 	HLT_PFJetFwd200);
    output->add("Events/HLT_PFJetFwd260", 	HLT_PFJetFwd260);
    output->add("Events/HLT_PFJetFwd320", 	HLT_PFJetFwd320);
    output->add("Events/HLT_PFJetFwd40", 	HLT_PFJetFwd40);
    output->add("Events/HLT_PFJetFwd400", 	HLT_PFJetFwd400);
    output->add("Events/HLT_PFJetFwd450", 	HLT_PFJetFwd450);
    output->add("Events/HLT_PFJetFwd500", 	HLT_PFJetFwd500);
    output->add("Events/HLT_PFJetFwd60", 	HLT_PFJetFwd60);
    output->add("Events/HLT_PFJetFwd80", 	HLT_PFJetFwd80);
    output->add("Events/HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1",
                 HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1);
    output->add("Events/HLT_PFMET100_PFMHT100_IDTight_PFHT60",
                 HLT_PFMET100_PFMHT100_IDTight_PFHT60);
    output->add("Events/HLT_PFMET110_PFMHT110_IDTight",
                 HLT_PFMET110_PFMHT110_IDTight);
    output->add("Events/HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1",
                 HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1);
    output->add("Events/HLT_PFMET120_PFMHT120_IDTight",
                 HLT_PFMET120_PFMHT120_IDTight);
    output->add("Events/HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1",
                 HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1);
    output->add("Events/HLT_PFMET120_PFMHT120_IDTight_PFHT60",
                 HLT_PFMET120_PFMHT120_IDTight_PFHT60);
    output->add("Events/HLT_PFMET130_PFMHT130_IDTight",
                 HLT_PFMET130_PFMHT130_IDTight);
    output->add("Events/HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1",
                 HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1);
    output->add("Events/HLT_PFMET140_PFMHT140_IDTight",
                 HLT_PFMET140_PFMHT140_IDTight);
    output->add("Events/HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1",
                 HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1);
    output->add("Events/HLT_PFMET200_HBHECleaned",
                 HLT_PFMET200_HBHECleaned);
    output->add("Events/HLT_PFMET200_HBHE_BeamHaloCleaned",
                 HLT_PFMET200_HBHE_BeamHaloCleaned);
    output->add("Events/HLT_PFMET200_NotCleaned", 	HLT_PFMET200_NotCleaned);
    output->add("Events/HLT_PFMET250_HBHECleaned",
                 HLT_PFMET250_HBHECleaned);
    output->add("Events/HLT_PFMET300_HBHECleaned",
                 HLT_PFMET300_HBHECleaned);
    output->add("Events/HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60",
                 HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60);
    output->add("Events/HLT_PFMETNoMu110_PFMHTNoMu110_IDTight",
                 HLT_PFMETNoMu110_PFMHTNoMu110_IDTight);
    output->add("Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight",
                 HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
    output->add("Events/HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",
                 HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
    output->add("Events/HLT_PFMETNoMu130_PFMHTNoMu130_IDTight",
                 HLT_PFMETNoMu130_PFMHTNoMu130_IDTight);
    output->add("Events/HLT_PFMETNoMu140_PFMHTNoMu140_IDTight",
                 HLT_PFMETNoMu140_PFMHTNoMu140_IDTight);
    output->add("Events/HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60",
                 HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60);
    output->add("Events/HLT_PFMETTypeOne110_PFMHT110_IDTight",
                 HLT_PFMETTypeOne110_PFMHT110_IDTight);
    output->add("Events/HLT_PFMETTypeOne120_PFMHT120_IDTight",
                 HLT_PFMETTypeOne120_PFMHT120_IDTight);
    output->add("Events/HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60",
                 HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60);
    output->add("Events/HLT_PFMETTypeOne130_PFMHT130_IDTight",
                 HLT_PFMETTypeOne130_PFMHT130_IDTight);
    output->add("Events/HLT_PFMETTypeOne140_PFMHT140_IDTight",
                 HLT_PFMETTypeOne140_PFMHT140_IDTight);
    output->add("Events/HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned",
                 HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned);
    output->add("Events/HLT_Photon120", 	HLT_Photon120);
    output->add("Events/HLT_Photon120_R9Id90_HE10_IsoM",
                 HLT_Photon120_R9Id90_HE10_IsoM);
    output->add("Events/HLT_Photon150", 	HLT_Photon150);
    output->add("Events/HLT_Photon165_R9Id90_HE10_IsoM",
                 HLT_Photon165_R9Id90_HE10_IsoM);
    output->add("Events/HLT_Photon175", 	HLT_Photon175);
    output->add("Events/HLT_Photon200", 	HLT_Photon200);
    output->add("Events/HLT_Photon20_HoverELoose",
                 HLT_Photon20_HoverELoose);
    output->add("Events/HLT_Photon25", 	HLT_Photon25);
    output->add("Events/HLT_Photon300_NoHE", 	HLT_Photon300_NoHE);
    output->add("Events/HLT_Photon30_HoverELoose",
                 HLT_Photon30_HoverELoose);
    output->add("Events/HLT_Photon33", 	HLT_Photon33);
    output->add("Events/HLT_Photon40_HoverELoose",
                 HLT_Photon40_HoverELoose);
    output->add("Events/HLT_Photon50", 	HLT_Photon50);
    output->add("Events/HLT_Photon50_HoverELoose",
                 HLT_Photon50_HoverELoose);
    output->add("Events/HLT_Photon50_R9Id90_HE10_IsoM",
                 HLT_Photon50_R9Id90_HE10_IsoM);
    output->add("Events/HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50",
                 HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50);
    output->add("Events/HLT_Photon60_HoverELoose",
                 HLT_Photon60_HoverELoose);
    output->add("Events/HLT_Photon60_R9Id90_CaloIdL_IsoL",
                 HLT_Photon60_R9Id90_CaloIdL_IsoL);
    output->add("Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL",
                 HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL);
    output->add("Events/HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15",
                 HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15);
    output->add("Events/HLT_Photon75", 	HLT_Photon75);
    output->add("Events/HLT_Photon75_R9Id90_HE10_IsoM",
                 HLT_Photon75_R9Id90_HE10_IsoM);
    output->add("Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3",
                 HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3);
    output->add("Events/HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3",
                 HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3);
    output->add("Events/HLT_Photon90", 	HLT_Photon90);
    output->add("Events/HLT_Photon90_CaloIdL_PFHT700",
                 HLT_Photon90_CaloIdL_PFHT700);
    output->add("Events/HLT_Photon90_R9Id90_HE10_IsoM",
                 HLT_Photon90_R9Id90_HE10_IsoM);
    output->add("Events/HLT_Physics", 	HLT_Physics);
    output->add("Events/HLT_Physics_part0", 	HLT_Physics_part0);
    output->add("Events/HLT_Physics_part1", 	HLT_Physics_part1);
    output->add("Events/HLT_Physics_part2", 	HLT_Physics_part2);
    output->add("Events/HLT_Physics_part3", 	HLT_Physics_part3);
    output->add("Events/HLT_Physics_part4", 	HLT_Physics_part4);
    output->add("Events/HLT_Physics_part5", 	HLT_Physics_part5);
    output->add("Events/HLT_Physics_part6", 	HLT_Physics_part6);
    output->add("Events/HLT_Physics_part7", 	HLT_Physics_part7);
    output->add("Events/HLT_QuadPFJet103_88_75_15",
                 HLT_QuadPFJet103_88_75_15);
    output->add("Events/HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2",
                 HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2);
    output->add("Events/HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1",
                 HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1);
    output->add("Events/HLT_QuadPFJet105_88_76_15",
                 HLT_QuadPFJet105_88_76_15);
    output->add("Events/HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2",
                 HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2);
    output->add("Events/HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1",
                 HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1);
    output->add("Events/HLT_QuadPFJet111_90_80_15",
                 HLT_QuadPFJet111_90_80_15);
    output->add("Events/HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2",
                 HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2);
    output->add("Events/HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1",
                 HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1);
    output->add("Events/HLT_QuadPFJet98_83_71_15",
                 HLT_QuadPFJet98_83_71_15);
    output->add("Events/HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2",
                 HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2);
    output->add("Events/HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1",
                 HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1);
    output->add("Events/HLT_Random", 	HLT_Random);
    output->add("Events/HLT_Rsq0p35", 	HLT_Rsq0p35);
    output->add("Events/HLT_Rsq0p40", 	HLT_Rsq0p40);
    output->add("Events/HLT_RsqMR300_Rsq0p09_MR200",
                 HLT_RsqMR300_Rsq0p09_MR200);
    output->add("Events/HLT_RsqMR300_Rsq0p09_MR200_4jet",
                 HLT_RsqMR300_Rsq0p09_MR200_4jet);
    output->add("Events/HLT_RsqMR320_Rsq0p09_MR200",
                 HLT_RsqMR320_Rsq0p09_MR200);
    output->add("Events/HLT_RsqMR320_Rsq0p09_MR200_4jet",
                 HLT_RsqMR320_Rsq0p09_MR200_4jet);
    output->add("Events/HLT_SingleJet30_Mu12_SinglePFJet40",
                 HLT_SingleJet30_Mu12_SinglePFJet40);
    output->add("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15",
                 HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15);
    output->add("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1",
                 HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1);
    output->add("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15",
                 HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15);
    output->add("Events/HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1",
                 HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1);
    output->add("Events/HLT_TkMu100", 	HLT_TkMu100);
    output->add("Events/HLT_Trimuon5_3p5_2_Upsilon_Muon",
                 HLT_Trimuon5_3p5_2_Upsilon_Muon);
    output->add("Events/HLT_TripleJet110_35_35_Mjj650_PFMET110",
                 HLT_TripleJet110_35_35_Mjj650_PFMET110);
    output->add("Events/HLT_TripleJet110_35_35_Mjj650_PFMET120",
                 HLT_TripleJet110_35_35_Mjj650_PFMET120);
    output->add("Events/HLT_TripleJet110_35_35_Mjj650_PFMET130",
                 HLT_TripleJet110_35_35_Mjj650_PFMET130);
    output->add("Events/HLT_TripleMu_10_5_5_DZ", 	HLT_TripleMu_10_5_5_DZ);
    output->add("Events/HLT_TripleMu_12_10_5", 	HLT_TripleMu_12_10_5);
    output->add("Events/HLT_TripleMu_5_3_3_Mass3p8to60_DCA",
                 HLT_TripleMu_5_3_3_Mass3p8to60_DCA);
    output->add("Events/HLT_TripleMu_5_3_3_Mass3p8to60_DZ",
                 HLT_TripleMu_5_3_3_Mass3p8to60_DZ);
    output->add("Events/HLT_TriplePhoton_20_20_20_CaloIdLV2",
                 HLT_TriplePhoton_20_20_20_CaloIdLV2);
    output->add("Events/HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL",
                 HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL);
    output->add("Events/HLT_TriplePhoton_30_30_10_CaloIdLV2",
                 HLT_TriplePhoton_30_30_10_CaloIdLV2);
    output->add("Events/HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL",
                 HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL);
    output->add("Events/HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL",
                 HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL);
    output->add("Events/HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx",
                 HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx);
    output->add("Events/HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx",
                 HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx);
    output->add("Events/HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx",
                 HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx);
    output->add("Events/HLT_UncorrectedJetE30_NoBPTX",
                 HLT_UncorrectedJetE30_NoBPTX);
    output->add("Events/HLT_UncorrectedJetE30_NoBPTX3BX",
                 HLT_UncorrectedJetE30_NoBPTX3BX);
    output->add("Events/HLT_UncorrectedJetE60_NoBPTX3BX",
                 HLT_UncorrectedJetE60_NoBPTX3BX);
    output->add("Events/HLT_UncorrectedJetE70_NoBPTX3BX",
                 HLT_UncorrectedJetE70_NoBPTX3BX);
    output->add("Events/HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg",
                 HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg);
    output->add("Events/HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg",
                 HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg);
    output->add("Events/HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg",
                 HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg);
    output->add("Events/HLT_ZeroBias", 	HLT_ZeroBias);
    output->add("Events/HLT_ZeroBias_FirstBXAfterTrain",
                 HLT_ZeroBias_FirstBXAfterTrain);
    output->add("Events/HLT_ZeroBias_FirstCollisionAfterAbortGap",
                 HLT_ZeroBias_FirstCollisionAfterAbortGap);
    output->add("Events/HLT_ZeroBias_FirstCollisionInTrain",
                 HLT_ZeroBias_FirstCollisionInTrain);
    output->add("Events/HLT_ZeroBias_IsolatedBunches",
                 HLT_ZeroBias_IsolatedBunches);
    output->add("Events/HLT_ZeroBias_LastCollisionInTrain",
                 HLT_ZeroBias_LastCollisionInTrain);
    output->add("Events/HLT_ZeroBias_part0", 	HLT_ZeroBias_part0);
    output->add("Events/HLT_ZeroBias_part1", 	HLT_ZeroBias_part1);
    output->add("Events/HLT_ZeroBias_part2", 	HLT_ZeroBias_part2);
    output->add("Events/HLT_ZeroBias_part3", 	HLT_ZeroBias_part3);
    output->add("Events/HLT_ZeroBias_part4", 	HLT_ZeroBias_part4);
    output->add("Events/HLT_ZeroBias_part5", 	HLT_ZeroBias_part5);
    output->add("Events/HLT_ZeroBias_part6", 	HLT_ZeroBias_part6);
    output->add("Events/HLT_ZeroBias_part7", 	HLT_ZeroBias_part7);
    output->add("Events/HLTriggerFinalPath", 	HLTriggerFinalPath);
    output->add("Events/HLTriggerFirstPath", 	HLTriggerFirstPath);
    output->add("Events/IsoTrack_dxy[nIsoTrack]", 	IsoTrack_dxy);
    output->add("Events/IsoTrack_dz[nIsoTrack]", 	IsoTrack_dz);
    output->add("Events/IsoTrack_eta[nIsoTrack]", 	IsoTrack_eta);
    output->add("Events/IsoTrack_isHighPurityTrack[nIsoTrack]",
                 IsoTrack_isHighPurityTrack);
    output->add("Events/IsoTrack_isPFcand[nIsoTrack]", 	IsoTrack_isPFcand);
    output->add("Events/IsoTrack_miniPFRelIso_all[nIsoTrack]",
                 IsoTrack_miniPFRelIso_all);
    output->add("Events/IsoTrack_miniPFRelIso_chg[nIsoTrack]",
                 IsoTrack_miniPFRelIso_chg);
    output->add("Events/IsoTrack_pdgId[nIsoTrack]", 	IsoTrack_pdgId);
    output->add("Events/IsoTrack_pfRelIso03_all[nIsoTrack]",
                 IsoTrack_pfRelIso03_all);
    output->add("Events/IsoTrack_pfRelIso03_chg[nIsoTrack]",
                 IsoTrack_pfRelIso03_chg);
    output->add("Events/IsoTrack_phi[nIsoTrack]", 	IsoTrack_phi);
    output->add("Events/IsoTrack_pt[nIsoTrack]", 	IsoTrack_pt);
    output->add("Events/Jet_area[nJet]", 	Jet_area);
    output->add("Events/Jet_bReg[nJet]", 	Jet_bReg);
    output->add("Events/Jet_btagCMVA[nJet]", 	Jet_btagCMVA);
    output->add("Events/Jet_btagCSVV2[nJet]", 	Jet_btagCSVV2);
    output->add("Events/Jet_btagDeepB[nJet]", 	Jet_btagDeepB);
    output->add("Events/Jet_btagDeepC[nJet]", 	Jet_btagDeepC);
    output->add("Events/Jet_btagDeepFlavB[nJet]", 	Jet_btagDeepFlavB);
    output->add("Events/Jet_chEmEF[nJet]", 	Jet_chEmEF);
    output->add("Events/Jet_chHEF[nJet]", 	Jet_chHEF);
    output->add("Events/Jet_cleanmask[nJet]", 	Jet_cleanmask);
    output->add("Events/Jet_electronIdx1[nJet]", 	Jet_electronIdx1);
    output->add("Events/Jet_electronIdx2[nJet]", 	Jet_electronIdx2);
    output->add("Events/Jet_eta[nJet]", 	Jet_eta);
    output->add("Events/Jet_genJetIdx[nJet]", 	Jet_genJetIdx);
    output->add("Events/Jet_hadronFlavour[nJet]", 	Jet_hadronFlavour);
    output->add("Events/Jet_jetId[nJet]", 	Jet_jetId);
    output->add("Events/Jet_mass[nJet]", 	Jet_mass);
    output->add("Events/Jet_muonIdx1[nJet]", 	Jet_muonIdx1);
    output->add("Events/Jet_muonIdx2[nJet]", 	Jet_muonIdx2);
    output->add("Events/Jet_nConstituents[nJet]", 	Jet_nConstituents);
    output->add("Events/Jet_nElectrons[nJet]", 	Jet_nElectrons);
    output->add("Events/Jet_nMuons[nJet]", 	Jet_nMuons);
    output->add("Events/Jet_neEmEF[nJet]", 	Jet_neEmEF);
    output->add("Events/Jet_neHEF[nJet]", 	Jet_neHEF);
    output->add("Events/Jet_partonFlavour[nJet]", 	Jet_partonFlavour);
    output->add("Events/Jet_phi[nJet]", 	Jet_phi);
    output->add("Events/Jet_pt[nJet]", 	Jet_pt);
    output->add("Events/Jet_puId[nJet]", 	Jet_puId);
    output->add("Events/Jet_qgl[nJet]", 	Jet_qgl);
    output->add("Events/Jet_rawFactor[nJet]", 	Jet_rawFactor);
    output->add("Events/L1simulation_step", 	L1simulation_step);
    output->add("Events/LHEPart_eta[nLHEPart]", 	LHEPart_eta);
    output->add("Events/LHEPart_mass[nLHEPart]", 	LHEPart_mass);
    output->add("Events/LHEPart_pdgId[nLHEPart]", 	LHEPart_pdgId);
    output->add("Events/LHEPart_phi[nLHEPart]", 	LHEPart_phi);
    output->add("Events/LHEPart_pt[nLHEPart]", 	LHEPart_pt);
    output->add("Events/LHEPdfWeight[nLHEPdfWeight]", 	LHEPdfWeight);
    output->add("Events/LHEScaleWeight[nLHEScaleWeight]", 	LHEScaleWeight);
    output->add("Events/LHEWeight_originalXWGTUP",
                 LHEWeight_originalXWGTUP);
    output->add("Events/LHE_HT", 	LHE_HT);
    output->add("Events/LHE_HTIncoming", 	LHE_HTIncoming);
    output->add("Events/LHE_Nb", 	LHE_Nb);
    output->add("Events/LHE_Nc", 	LHE_Nc);
    output->add("Events/LHE_Nglu", 	LHE_Nglu);
    output->add("Events/LHE_Njets", 	LHE_Njets);
    output->add("Events/LHE_NpLO", 	LHE_NpLO);
    output->add("Events/LHE_NpNLO", 	LHE_NpNLO);
    output->add("Events/LHE_Nuds", 	LHE_Nuds);
    output->add("Events/LHE_Vpt", 	LHE_Vpt);
    output->add("Events/MET_MetUnclustEnUpDeltaX",
                 MET_MetUnclustEnUpDeltaX);
    output->add("Events/MET_MetUnclustEnUpDeltaY",
                 MET_MetUnclustEnUpDeltaY);
    output->add("Events/MET_covXX", 	MET_covXX);
    output->add("Events/MET_covXY", 	MET_covXY);
    output->add("Events/MET_covYY", 	MET_covYY);
    output->add("Events/MET_fiducialGenPhi", 	MET_fiducialGenPhi);
    output->add("Events/MET_fiducialGenPt", 	MET_fiducialGenPt);
    output->add("Events/MET_phi", 	MET_phi);
    output->add("Events/MET_pt", 	MET_pt);
    output->add("Events/MET_significance", 	MET_significance);
    output->add("Events/MET_sumEt", 	MET_sumEt);
    output->add("Events/Muon_charge[nMuon]", 	Muon_charge);
    output->add("Events/Muon_cleanmask[nMuon]", 	Muon_cleanmask);
    output->add("Events/Muon_dxy[nMuon]", 	Muon_dxy);
    output->add("Events/Muon_dxyErr[nMuon]", 	Muon_dxyErr);
    output->add("Events/Muon_dz[nMuon]", 	Muon_dz);
    output->add("Events/Muon_dzErr[nMuon]", 	Muon_dzErr);
    output->add("Events/Muon_eta[nMuon]", 	Muon_eta);
    output->add("Events/Muon_genPartFlav[nMuon]", 	Muon_genPartFlav);
    output->add("Events/Muon_genPartIdx[nMuon]", 	Muon_genPartIdx);
    output->add("Events/Muon_highPtId[nMuon]", 	Muon_highPtId);
    output->add("Events/Muon_ip3d[nMuon]", 	Muon_ip3d);
    output->add("Events/Muon_isPFcand[nMuon]", 	Muon_isPFcand);
    output->add("Events/Muon_jetIdx[nMuon]", 	Muon_jetIdx);
    output->add("Events/Muon_mass[nMuon]", 	Muon_mass);
    output->add("Events/Muon_mediumId[nMuon]", 	Muon_mediumId);
    output->add("Events/Muon_miniPFRelIso_all[nMuon]",
                 Muon_miniPFRelIso_all);
    output->add("Events/Muon_miniPFRelIso_chg[nMuon]",
                 Muon_miniPFRelIso_chg);
    output->add("Events/Muon_mvaTTH[nMuon]", 	Muon_mvaTTH);
    output->add("Events/Muon_nStations[nMuon]", 	Muon_nStations);
    output->add("Events/Muon_nTrackerLayers[nMuon]", 	Muon_nTrackerLayers);
    output->add("Events/Muon_pdgId[nMuon]", 	Muon_pdgId);
    output->add("Events/Muon_pfRelIso03_all[nMuon]", 	Muon_pfRelIso03_all);
    output->add("Events/Muon_pfRelIso03_chg[nMuon]", 	Muon_pfRelIso03_chg);
    output->add("Events/Muon_pfRelIso04_all[nMuon]", 	Muon_pfRelIso04_all);
    output->add("Events/Muon_phi[nMuon]", 	Muon_phi);
    output->add("Events/Muon_pt[nMuon]", 	Muon_pt);
    output->add("Events/Muon_ptErr[nMuon]", 	Muon_ptErr);
    output->add("Events/Muon_segmentComp[nMuon]", 	Muon_segmentComp);
    output->add("Events/Muon_sip3d[nMuon]", 	Muon_sip3d);
    output->add("Events/Muon_softId[nMuon]", 	Muon_softId);
    output->add("Events/Muon_tightCharge[nMuon]", 	Muon_tightCharge);
    output->add("Events/Muon_tightId[nMuon]", 	Muon_tightId);
    output->add("Events/OtherPV_z[nOtherPV]", 	OtherPV_z);
    output->add("Events/PV_chi2", 	PV_chi2);
    output->add("Events/PV_ndof", 	PV_ndof);
    output->add("Events/PV_npvs", 	PV_npvs);
    output->add("Events/PV_npvsGood", 	PV_npvsGood);
    output->add("Events/PV_score", 	PV_score);
    output->add("Events/PV_x", 	PV_x);
    output->add("Events/PV_y", 	PV_y);
    output->add("Events/PV_z", 	PV_z);
    output->add("Events/Photon_charge[nPhoton]", 	Photon_charge);
    output->add("Events/Photon_cleanmask[nPhoton]", 	Photon_cleanmask);
    output->add("Events/Photon_cutBasedBitmap[nPhoton]",
                 Photon_cutBasedBitmap);
    output->add("Events/Photon_eCorr[nPhoton]", 	Photon_eCorr);
    output->add("Events/Photon_electronIdx[nPhoton]", 	Photon_electronIdx);
    output->add("Events/Photon_electronVeto[nPhoton]",
                 Photon_electronVeto);
    output->add("Events/Photon_energyErr[nPhoton]", 	Photon_energyErr);
    output->add("Events/Photon_eta[nPhoton]", 	Photon_eta);
    output->add("Events/Photon_genPartFlav[nPhoton]", 	Photon_genPartFlav);
    output->add("Events/Photon_genPartIdx[nPhoton]", 	Photon_genPartIdx);
    output->add("Events/Photon_hoe[nPhoton]", 	Photon_hoe);
    output->add("Events/Photon_isScEtaEB[nPhoton]", 	Photon_isScEtaEB);
    output->add("Events/Photon_isScEtaEE[nPhoton]", 	Photon_isScEtaEE);
    output->add("Events/Photon_jetIdx[nPhoton]", 	Photon_jetIdx);
    output->add("Events/Photon_mass[nPhoton]", 	Photon_mass);
    output->add("Events/Photon_mvaID[nPhoton]", 	Photon_mvaID);
    output->add("Events/Photon_mvaID_WP80[nPhoton]", 	Photon_mvaID_WP80);
    output->add("Events/Photon_mvaID_WP90[nPhoton]", 	Photon_mvaID_WP90);
    output->add("Events/Photon_pdgId[nPhoton]", 	Photon_pdgId);
    output->add("Events/Photon_pfRelIso03_all[nPhoton]",
                 Photon_pfRelIso03_all);
    output->add("Events/Photon_pfRelIso03_chg[nPhoton]",
                 Photon_pfRelIso03_chg);
    output->add("Events/Photon_phi[nPhoton]", 	Photon_phi);
    output->add("Events/Photon_pixelSeed[nPhoton]", 	Photon_pixelSeed);
    output->add("Events/Photon_pt[nPhoton]", 	Photon_pt);
    output->add("Events/Photon_r9[nPhoton]", 	Photon_r9);
    output->add("Events/Photon_sieie[nPhoton]", 	Photon_sieie);
    output->add("Events/Photon_vidNestedWPBitmap[nPhoton]",
                 Photon_vidNestedWPBitmap);
    output->add("Events/Pileup_nPU", 	Pileup_nPU);
    output->add("Events/Pileup_nTrueInt", 	Pileup_nTrueInt);
    output->add("Events/Pileup_sumEOOT", 	Pileup_sumEOOT);
    output->add("Events/Pileup_sumLOOT", 	Pileup_sumLOOT);
    output->add("Events/PuppiMET_phi", 	PuppiMET_phi);
    output->add("Events/PuppiMET_pt", 	PuppiMET_pt);
    output->add("Events/PuppiMET_sumEt", 	PuppiMET_sumEt);
    output->add("Events/RawMET_phi", 	RawMET_phi);
    output->add("Events/RawMET_pt", 	RawMET_pt);
    output->add("Events/RawMET_sumEt", 	RawMET_sumEt);
    output->add("Events/SV_chi2[nSV]", 	SV_chi2);
    output->add("Events/SV_dlen[nSV]", 	SV_dlen);
    output->add("Events/SV_dlenSig[nSV]", 	SV_dlenSig);
    output->add("Events/SV_eta[nSV]", 	SV_eta);
    output->add("Events/SV_mass[nSV]", 	SV_mass);
    output->add("Events/SV_ndof[nSV]", 	SV_ndof);
    output->add("Events/SV_pAngle[nSV]", 	SV_pAngle);
    output->add("Events/SV_phi[nSV]", 	SV_phi);
    output->add("Events/SV_pt[nSV]", 	SV_pt);
    output->add("Events/SV_x[nSV]", 	SV_x);
    output->add("Events/SV_y[nSV]", 	SV_y);
    output->add("Events/SV_z[nSV]", 	SV_z);
    output->add("Events/SoftActivityJetHT", 	SoftActivityJetHT);
    output->add("Events/SoftActivityJetHT10", 	SoftActivityJetHT10);
    output->add("Events/SoftActivityJetHT2", 	SoftActivityJetHT2);
    output->add("Events/SoftActivityJetHT5", 	SoftActivityJetHT5);
    output->add("Events/SoftActivityJetNjets10", 	SoftActivityJetNjets10);
    output->add("Events/SoftActivityJetNjets2", 	SoftActivityJetNjets2);
    output->add("Events/SoftActivityJetNjets5", 	SoftActivityJetNjets5);
    output->add("Events/SoftActivityJet_eta[nSoftActivityJet]",
                 SoftActivityJet_eta);
    output->add("Events/SoftActivityJet_phi[nSoftActivityJet]",
                 SoftActivityJet_phi);
    output->add("Events/SoftActivityJet_pt[nSoftActivityJet]",
                 SoftActivityJet_pt);
    output->add("Events/SubGenJetAK8_eta[nSubGenJetAK8]",
                 SubGenJetAK8_eta);
    output->add("Events/SubGenJetAK8_mass[nSubGenJetAK8]",
                 SubGenJetAK8_mass);
    output->add("Events/SubGenJetAK8_phi[nSubGenJetAK8]",
                 SubGenJetAK8_phi);
    output->add("Events/SubGenJetAK8_pt[nSubGenJetAK8]", 	SubGenJetAK8_pt);
    output->add("Events/SubJet_btagCMVA[nSubJet]", 	SubJet_btagCMVA);
    output->add("Events/SubJet_btagCSVV2[nSubJet]", 	SubJet_btagCSVV2);
    output->add("Events/SubJet_btagDeepB[nSubJet]", 	SubJet_btagDeepB);
    output->add("Events/SubJet_eta[nSubJet]", 	SubJet_eta);
    output->add("Events/SubJet_mass[nSubJet]", 	SubJet_mass);
    output->add("Events/SubJet_n2b1[nSubJet]", 	SubJet_n2b1);
    output->add("Events/SubJet_n3b1[nSubJet]", 	SubJet_n3b1);
    output->add("Events/SubJet_phi[nSubJet]", 	SubJet_phi);
    output->add("Events/SubJet_pt[nSubJet]", 	SubJet_pt);
    output->add("Events/SubJet_tau1[nSubJet]", 	SubJet_tau1);
    output->add("Events/SubJet_tau2[nSubJet]", 	SubJet_tau2);
    output->add("Events/SubJet_tau3[nSubJet]", 	SubJet_tau3);
    output->add("Events/SubJet_tau4[nSubJet]", 	SubJet_tau4);
    output->add("Events/Tau_charge[nTau]", 	Tau_charge);
    output->add("Events/Tau_chargedIso[nTau]", 	Tau_chargedIso);
    output->add("Events/Tau_cleanmask[nTau]", 	Tau_cleanmask);
    output->add("Events/Tau_decayMode[nTau]", 	Tau_decayMode);
    output->add("Events/Tau_dxy[nTau]", 	Tau_dxy);
    output->add("Events/Tau_dz[nTau]", 	Tau_dz);
    output->add("Events/Tau_eta[nTau]", 	Tau_eta);
    output->add("Events/Tau_genPartFlav[nTau]", 	Tau_genPartFlav);
    output->add("Events/Tau_genPartIdx[nTau]", 	Tau_genPartIdx);
    output->add("Events/Tau_idAntiEle[nTau]", 	Tau_idAntiEle);
    output->add("Events/Tau_idAntiMu[nTau]", 	Tau_idAntiMu);
    output->add("Events/Tau_idDecayMode[nTau]", 	Tau_idDecayMode);
    output->add("Events/Tau_idDecayModeNewDMs[nTau]",
                 Tau_idDecayModeNewDMs);
    output->add("Events/Tau_idMVAnewDM2017v2[nTau]", 	Tau_idMVAnewDM2017v2);
    output->add("Events/Tau_idMVAoldDM[nTau]", 	Tau_idMVAoldDM);
    output->add("Events/Tau_idMVAoldDM2017v1[nTau]", 	Tau_idMVAoldDM2017v1);
    output->add("Events/Tau_idMVAoldDM2017v2[nTau]", 	Tau_idMVAoldDM2017v2);
    output->add("Events/Tau_idMVAoldDMdR032017v2[nTau]",
                 Tau_idMVAoldDMdR032017v2);
    output->add("Events/Tau_jetIdx[nTau]", 	Tau_jetIdx);
    output->add("Events/Tau_leadTkDeltaEta[nTau]", 	Tau_leadTkDeltaEta);
    output->add("Events/Tau_leadTkDeltaPhi[nTau]", 	Tau_leadTkDeltaPhi);
    output->add("Events/Tau_leadTkPtOverTauPt[nTau]",
                 Tau_leadTkPtOverTauPt);
    output->add("Events/Tau_mass[nTau]", 	Tau_mass);
    output->add("Events/Tau_neutralIso[nTau]", 	Tau_neutralIso);
    output->add("Events/Tau_phi[nTau]", 	Tau_phi);
    output->add("Events/Tau_photonsOutsideSignalCone[nTau]",
                 Tau_photonsOutsideSignalCone);
    output->add("Events/Tau_pt[nTau]", 	Tau_pt);
    output->add("Events/Tau_puCorr[nTau]", 	Tau_puCorr);
    output->add("Events/Tau_rawAntiEle[nTau]", 	Tau_rawAntiEle);
    output->add("Events/Tau_rawAntiEleCat[nTau]", 	Tau_rawAntiEleCat);
    output->add("Events/Tau_rawIso[nTau]", 	Tau_rawIso);
    output->add("Events/Tau_rawIsodR03[nTau]", 	Tau_rawIsodR03);
    output->add("Events/Tau_rawMVAnewDM2017v2[nTau]",
                 Tau_rawMVAnewDM2017v2);
    output->add("Events/Tau_rawMVAoldDM[nTau]", 	Tau_rawMVAoldDM);
    output->add("Events/Tau_rawMVAoldDM2017v1[nTau]",
                 Tau_rawMVAoldDM2017v1);
    output->add("Events/Tau_rawMVAoldDM2017v2[nTau]",
                 Tau_rawMVAoldDM2017v2);
    output->add("Events/Tau_rawMVAoldDMdR032017v2[nTau]",
                 Tau_rawMVAoldDMdR032017v2);
    output->add("Events/TkMET_phi", 	TkMET_phi);
    output->add("Events/TkMET_pt", 	TkMET_pt);
    output->add("Events/TkMET_sumEt", 	TkMET_sumEt);
    output->add("Events/TrigObj_eta[nTrigObj]", 	TrigObj_eta);
    output->add("Events/TrigObj_filterBits[nTrigObj]", 	TrigObj_filterBits);
    output->add("Events/TrigObj_id[nTrigObj]", 	TrigObj_id);
    output->add("Events/TrigObj_l1charge[nTrigObj]", 	TrigObj_l1charge);
    output->add("Events/TrigObj_l1iso[nTrigObj]", 	TrigObj_l1iso);
    output->add("Events/TrigObj_l1pt[nTrigObj]", 	TrigObj_l1pt);
    output->add("Events/TrigObj_l1pt_2[nTrigObj]", 	TrigObj_l1pt_2);
    output->add("Events/TrigObj_l2pt[nTrigObj]", 	TrigObj_l2pt);
    output->add("Events/TrigObj_phi[nTrigObj]", 	TrigObj_phi);
    output->add("Events/TrigObj_pt[nTrigObj]", 	TrigObj_pt);
    output->add("Events/event", 	event);
    output->add("Events/fixedGridRhoFastjetAll", 	fixedGridRhoFastjetAll);
    output->add("Events/fixedGridRhoFastjetCentralCalo",
                 fixedGridRhoFastjetCentralCalo);
    output->add("Events/fixedGridRhoFastjetCentralNeutral",
                 fixedGridRhoFastjetCentralNeutral);
    output->add("Events/genTtbarId", 	genTtbarId);
    output->add("Events/genWeight", 	genWeight);
    output->add("Events/luminosityBlock", 	luminosityBlock);
    output->add("Events/run", 	run);

  }

  void initBuffers()
  {
    Electron_charge	= std::vector<int>(25,0);
    Electron_cleanmask	= std::vector<int>(25,0);
    Electron_convVeto	= std::vector<bool>(25,0);
    Electron_cutBased	= std::vector<int>(25,0);
    Electron_cutBased_HEEP	= std::vector<bool>(25,0);
    Electron_deltaEtaSC	= std::vector<float>(25,0);
    Electron_dr03EcalRecHitSumEt	= std::vector<float>(25,0);
    Electron_dr03HcalDepth1TowerSumEt	= std::vector<float>(25,0);
    Electron_dr03TkSumPt	= std::vector<float>(25,0);
    Electron_dxy	= std::vector<float>(25,0);
    Electron_dxyErr	= std::vector<float>(25,0);
    Electron_dz	= std::vector<float>(25,0);
    Electron_dzErr	= std::vector<float>(25,0);
    Electron_eCorr	= std::vector<float>(25,0);
    Electron_eInvMinusPInv	= std::vector<float>(25,0);
    Electron_energyErr	= std::vector<float>(25,0);
    Electron_eta	= std::vector<float>(25,0);
    Electron_genPartFlav	= std::vector<int>(25,0);
    Electron_genPartIdx	= std::vector<int>(25,0);
    Electron_hoe	= std::vector<float>(25,0);
    Electron_ip3d	= std::vector<float>(25,0);
    Electron_isPFcand	= std::vector<bool>(25,0);
    Electron_jetIdx	= std::vector<int>(25,0);
    Electron_lostHits	= std::vector<int>(25,0);
    Electron_mass	= std::vector<float>(25,0);
    Electron_miniPFRelIso_all	= std::vector<float>(25,0);
    Electron_miniPFRelIso_chg	= std::vector<float>(25,0);
    Electron_mvaFall17Iso	= std::vector<float>(25,0);
    Electron_mvaFall17Iso_WP80	= std::vector<bool>(25,0);
    Electron_mvaFall17Iso_WP90	= std::vector<bool>(25,0);
    Electron_mvaFall17Iso_WPL	= std::vector<bool>(25,0);
    Electron_mvaFall17noIso	= std::vector<float>(25,0);
    Electron_mvaFall17noIso_WP80	= std::vector<bool>(25,0);
    Electron_mvaFall17noIso_WP90	= std::vector<bool>(25,0);
    Electron_mvaFall17noIso_WPL	= std::vector<bool>(25,0);
    Electron_mvaTTH	= std::vector<float>(25,0);
    Electron_pdgId	= std::vector<int>(25,0);
    Electron_pfRelIso03_all	= std::vector<float>(25,0);
    Electron_pfRelIso03_chg	= std::vector<float>(25,0);
    Electron_phi	= std::vector<float>(25,0);
    Electron_photonIdx	= std::vector<int>(25,0);
    Electron_pt	= std::vector<float>(25,0);
    Electron_r9	= std::vector<float>(25,0);
    Electron_sieie	= std::vector<float>(25,0);
    Electron_sip3d	= std::vector<float>(25,0);
    Electron_tightCharge	= std::vector<int>(25,0);
    Electron_vidNestedWPBitmap	= std::vector<int>(25,0);
    FatJet_area	= std::vector<float>(20,0);
    FatJet_btagCMVA	= std::vector<float>(20,0);
    FatJet_btagCSVV2	= std::vector<float>(20,0);
    FatJet_btagDeepB	= std::vector<float>(20,0);
    FatJet_btagHbb	= std::vector<float>(20,0);
    FatJet_eta	= std::vector<float>(20,0);
    FatJet_jetId	= std::vector<int>(20,0);
    FatJet_mass	= std::vector<float>(20,0);
    FatJet_msoftdrop	= std::vector<float>(20,0);
    FatJet_n2b1	= std::vector<float>(20,0);
    FatJet_n3b1	= std::vector<float>(20,0);
    FatJet_phi	= std::vector<float>(20,0);
    FatJet_pt	= std::vector<float>(20,0);
    FatJet_subJetIdx1	= std::vector<int>(20,0);
    FatJet_subJetIdx2	= std::vector<int>(20,0);
    FatJet_tau1	= std::vector<float>(20,0);
    FatJet_tau2	= std::vector<float>(20,0);
    FatJet_tau3	= std::vector<float>(20,0);
    FatJet_tau4	= std::vector<float>(20,0);
    GenDressedLepton_eta	= std::vector<float>(15,0);
    GenDressedLepton_mass	= std::vector<float>(15,0);
    GenDressedLepton_pdgId	= std::vector<int>(15,0);
    GenDressedLepton_phi	= std::vector<float>(15,0);
    GenDressedLepton_pt	= std::vector<float>(15,0);
    GenJetAK8_eta	= std::vector<float>(20,0);
    GenJetAK8_hadronFlavour	= std::vector<int>(20,0);
    GenJetAK8_mass	= std::vector<float>(20,0);
    GenJetAK8_partonFlavour	= std::vector<int>(20,0);
    GenJetAK8_phi	= std::vector<float>(20,0);
    GenJetAK8_pt	= std::vector<float>(20,0);
    GenJet_eta	= std::vector<float>(50,0);
    GenJet_hadronFlavour	= std::vector<int>(50,0);
    GenJet_mass	= std::vector<float>(50,0);
    GenJet_partonFlavour	= std::vector<int>(50,0);
    GenJet_phi	= std::vector<float>(50,0);
    GenJet_pt	= std::vector<float>(50,0);
    GenPart_eta	= std::vector<float>(200,0);
    GenPart_genPartIdxMother	= std::vector<int>(200,0);
    GenPart_mass	= std::vector<float>(200,0);
    GenPart_pdgId	= std::vector<int>(200,0);
    GenPart_phi	= std::vector<float>(200,0);
    GenPart_pt	= std::vector<float>(200,0);
    GenPart_status	= std::vector<int>(200,0);
    GenPart_statusFlags	= std::vector<int>(200,0);
    GenVisTau_charge	= std::vector<int>(15,0);
    GenVisTau_eta	= std::vector<float>(15,0);
    GenVisTau_genPartIdxMother	= std::vector<int>(15,0);
    GenVisTau_mass	= std::vector<float>(15,0);
    GenVisTau_phi	= std::vector<float>(15,0);
    GenVisTau_pt	= std::vector<float>(15,0);
    GenVisTau_status	= std::vector<int>(15,0);
    IsoTrack_dxy	= std::vector<float>(20,0);
    IsoTrack_dz	= std::vector<float>(20,0);
    IsoTrack_eta	= std::vector<float>(20,0);
    IsoTrack_isHighPurityTrack	= std::vector<bool>(20,0);
    IsoTrack_isPFcand	= std::vector<bool>(20,0);
    IsoTrack_miniPFRelIso_all	= std::vector<float>(20,0);
    IsoTrack_miniPFRelIso_chg	= std::vector<float>(20,0);
    IsoTrack_pdgId	= std::vector<int>(20,0);
    IsoTrack_pfRelIso03_all	= std::vector<float>(20,0);
    IsoTrack_pfRelIso03_chg	= std::vector<float>(20,0);
    IsoTrack_phi	= std::vector<float>(20,0);
    IsoTrack_pt	= std::vector<float>(20,0);
    Jet_area	= std::vector<float>(55,0);
    Jet_bReg	= std::vector<float>(55,0);
    Jet_btagCMVA	= std::vector<float>(55,0);
    Jet_btagCSVV2	= std::vector<float>(55,0);
    Jet_btagDeepB	= std::vector<float>(55,0);
    Jet_btagDeepC	= std::vector<float>(55,0);
    Jet_btagDeepFlavB	= std::vector<float>(55,0);
    Jet_chEmEF	= std::vector<float>(55,0);
    Jet_chHEF	= std::vector<float>(55,0);
    Jet_cleanmask	= std::vector<int>(55,0);
    Jet_electronIdx1	= std::vector<int>(55,0);
    Jet_electronIdx2	= std::vector<int>(55,0);
    Jet_eta	= std::vector<float>(55,0);
    Jet_genJetIdx	= std::vector<int>(55,0);
    Jet_hadronFlavour	= std::vector<int>(55,0);
    Jet_jetId	= std::vector<int>(55,0);
    Jet_mass	= std::vector<float>(55,0);
    Jet_muonIdx1	= std::vector<int>(55,0);
    Jet_muonIdx2	= std::vector<int>(55,0);
    Jet_nConstituents	= std::vector<int>(55,0);
    Jet_nElectrons	= std::vector<int>(55,0);
    Jet_nMuons	= std::vector<int>(55,0);
    Jet_neEmEF	= std::vector<float>(55,0);
    Jet_neHEF	= std::vector<float>(55,0);
    Jet_partonFlavour	= std::vector<int>(55,0);
    Jet_phi	= std::vector<float>(55,0);
    Jet_pt	= std::vector<float>(55,0);
    Jet_puId	= std::vector<int>(55,0);
    Jet_qgl	= std::vector<float>(55,0);
    Jet_rawFactor	= std::vector<float>(55,0);
    LHEPart_eta	= std::vector<float>(25,0);
    LHEPart_mass	= std::vector<float>(25,0);
    LHEPart_pdgId	= std::vector<int>(25,0);
    LHEPart_phi	= std::vector<float>(25,0);
    LHEPart_pt	= std::vector<float>(25,0);
    LHEPdfWeight	= std::vector<float>(100,0);
    LHEScaleWeight	= std::vector<float>(100,0);
    Muon_charge	= std::vector<int>(20,0);
    Muon_cleanmask	= std::vector<int>(20,0);
    Muon_dxy	= std::vector<float>(20,0);
    Muon_dxyErr	= std::vector<float>(20,0);
    Muon_dz	= std::vector<float>(20,0);
    Muon_dzErr	= std::vector<float>(20,0);
    Muon_eta	= std::vector<float>(20,0);
    Muon_genPartFlav	= std::vector<int>(20,0);
    Muon_genPartIdx	= std::vector<int>(20,0);
    Muon_highPtId	= std::vector<int>(20,0);
    Muon_ip3d	= std::vector<float>(20,0);
    Muon_isPFcand	= std::vector<bool>(20,0);
    Muon_jetIdx	= std::vector<int>(20,0);
    Muon_mass	= std::vector<float>(20,0);
    Muon_mediumId	= std::vector<bool>(20,0);
    Muon_miniPFRelIso_all	= std::vector<float>(20,0);
    Muon_miniPFRelIso_chg	= std::vector<float>(20,0);
    Muon_mvaTTH	= std::vector<float>(20,0);
    Muon_nStations	= std::vector<int>(20,0);
    Muon_nTrackerLayers	= std::vector<int>(20,0);
    Muon_pdgId	= std::vector<int>(20,0);
    Muon_pfRelIso03_all	= std::vector<float>(20,0);
    Muon_pfRelIso03_chg	= std::vector<float>(20,0);
    Muon_pfRelIso04_all	= std::vector<float>(20,0);
    Muon_phi	= std::vector<float>(20,0);
    Muon_pt	= std::vector<float>(20,0);
    Muon_ptErr	= std::vector<float>(20,0);
    Muon_segmentComp	= std::vector<float>(20,0);
    Muon_sip3d	= std::vector<float>(20,0);
    Muon_softId	= std::vector<bool>(20,0);
    Muon_tightCharge	= std::vector<int>(20,0);
    Muon_tightId	= std::vector<bool>(20,0);
    OtherPV_z	= std::vector<float>(15,0);
    Photon_charge	= std::vector<int>(25,0);
    Photon_cleanmask	= std::vector<int>(25,0);
    Photon_cutBasedBitmap	= std::vector<int>(25,0);
    Photon_eCorr	= std::vector<float>(25,0);
    Photon_electronIdx	= std::vector<int>(25,0);
    Photon_electronVeto	= std::vector<bool>(25,0);
    Photon_energyErr	= std::vector<float>(25,0);
    Photon_eta	= std::vector<float>(25,0);
    Photon_genPartFlav	= std::vector<int>(25,0);
    Photon_genPartIdx	= std::vector<int>(25,0);
    Photon_hoe	= std::vector<float>(25,0);
    Photon_isScEtaEB	= std::vector<bool>(25,0);
    Photon_isScEtaEE	= std::vector<bool>(25,0);
    Photon_jetIdx	= std::vector<int>(25,0);
    Photon_mass	= std::vector<float>(25,0);
    Photon_mvaID	= std::vector<float>(25,0);
    Photon_mvaID_WP80	= std::vector<bool>(25,0);
    Photon_mvaID_WP90	= std::vector<bool>(25,0);
    Photon_pdgId	= std::vector<int>(25,0);
    Photon_pfRelIso03_all	= std::vector<float>(25,0);
    Photon_pfRelIso03_chg	= std::vector<float>(25,0);
    Photon_phi	= std::vector<float>(25,0);
    Photon_pixelSeed	= std::vector<bool>(25,0);
    Photon_pt	= std::vector<float>(25,0);
    Photon_r9	= std::vector<float>(25,0);
    Photon_sieie	= std::vector<float>(25,0);
    Photon_vidNestedWPBitmap	= std::vector<int>(25,0);
    SV_chi2	= std::vector<float>(35,0);
    SV_dlen	= std::vector<float>(35,0);
    SV_dlenSig	= std::vector<float>(35,0);
    SV_eta	= std::vector<float>(35,0);
    SV_mass	= std::vector<float>(35,0);
    SV_ndof	= std::vector<float>(35,0);
    SV_pAngle	= std::vector<float>(35,0);
    SV_phi	= std::vector<float>(35,0);
    SV_pt	= std::vector<float>(35,0);
    SV_x	= std::vector<float>(35,0);
    SV_y	= std::vector<float>(35,0);
    SV_z	= std::vector<float>(35,0);
    SoftActivityJet_eta	= std::vector<float>(20,0);
    SoftActivityJet_phi	= std::vector<float>(20,0);
    SoftActivityJet_pt	= std::vector<float>(20,0);
    SubGenJetAK8_eta	= std::vector<float>(30,0);
    SubGenJetAK8_mass	= std::vector<float>(30,0);
    SubGenJetAK8_phi	= std::vector<float>(30,0);
    SubGenJetAK8_pt	= std::vector<float>(30,0);
    SubJet_btagCMVA	= std::vector<float>(30,0);
    SubJet_btagCSVV2	= std::vector<float>(30,0);
    SubJet_btagDeepB	= std::vector<float>(30,0);
    SubJet_eta	= std::vector<float>(30,0);
    SubJet_mass	= std::vector<float>(30,0);
    SubJet_n2b1	= std::vector<float>(30,0);
    SubJet_n3b1	= std::vector<float>(30,0);
    SubJet_phi	= std::vector<float>(30,0);
    SubJet_pt	= std::vector<float>(30,0);
    SubJet_tau1	= std::vector<float>(30,0);
    SubJet_tau2	= std::vector<float>(30,0);
    SubJet_tau3	= std::vector<float>(30,0);
    SubJet_tau4	= std::vector<float>(30,0);
    Tau_charge	= std::vector<int>(20,0);
    Tau_chargedIso	= std::vector<float>(20,0);
    Tau_cleanmask	= std::vector<int>(20,0);
    Tau_decayMode	= std::vector<int>(20,0);
    Tau_dxy	= std::vector<float>(20,0);
    Tau_dz	= std::vector<float>(20,0);
    Tau_eta	= std::vector<float>(20,0);
    Tau_genPartFlav	= std::vector<int>(20,0);
    Tau_genPartIdx	= std::vector<int>(20,0);
    Tau_idAntiEle	= std::vector<int>(20,0);
    Tau_idAntiMu	= std::vector<int>(20,0);
    Tau_idDecayMode	= std::vector<bool>(20,0);
    Tau_idDecayModeNewDMs	= std::vector<bool>(20,0);
    Tau_idMVAnewDM2017v2	= std::vector<int>(20,0);
    Tau_idMVAoldDM	= std::vector<int>(20,0);
    Tau_idMVAoldDM2017v1	= std::vector<int>(20,0);
    Tau_idMVAoldDM2017v2	= std::vector<int>(20,0);
    Tau_idMVAoldDMdR032017v2	= std::vector<int>(20,0);
    Tau_jetIdx	= std::vector<int>(20,0);
    Tau_leadTkDeltaEta	= std::vector<float>(20,0);
    Tau_leadTkDeltaPhi	= std::vector<float>(20,0);
    Tau_leadTkPtOverTauPt	= std::vector<float>(20,0);
    Tau_mass	= std::vector<float>(20,0);
    Tau_neutralIso	= std::vector<float>(20,0);
    Tau_phi	= std::vector<float>(20,0);
    Tau_photonsOutsideSignalCone	= std::vector<float>(20,0);
    Tau_pt	= std::vector<float>(20,0);
    Tau_puCorr	= std::vector<float>(20,0);
    Tau_rawAntiEle	= std::vector<float>(20,0);
    Tau_rawAntiEleCat	= std::vector<int>(20,0);
    Tau_rawIso	= std::vector<float>(20,0);
    Tau_rawIsodR03	= std::vector<float>(20,0);
    Tau_rawMVAnewDM2017v2	= std::vector<float>(20,0);
    Tau_rawMVAoldDM	= std::vector<float>(20,0);
    Tau_rawMVAoldDM2017v1	= std::vector<float>(20,0);
    Tau_rawMVAoldDM2017v2	= std::vector<float>(20,0);
    Tau_rawMVAoldDMdR032017v2	= std::vector<float>(20,0);
    TrigObj_eta	= std::vector<float>(65,0);
    TrigObj_filterBits	= std::vector<int>(65,0);
    TrigObj_id	= std::vector<int>(65,0);
    TrigObj_l1charge	= std::vector<int>(65,0);
    TrigObj_l1iso	= std::vector<int>(65,0);
    TrigObj_l1pt	= std::vector<float>(65,0);
    TrigObj_l1pt_2	= std::vector<float>(65,0);
    TrigObj_l2pt	= std::vector<float>(65,0);
    TrigObj_phi	= std::vector<float>(65,0);
    TrigObj_pt	= std::vector<float>(65,0);
    Electron	= std::vector<eventBuffer::Electron_s>(25);
    FatJet	= std::vector<eventBuffer::FatJet_s>(20);
    GenDressedLepton	= std::vector<eventBuffer::GenDressedLepton_s>(15);
    GenJet	= std::vector<eventBuffer::GenJet_s>(50);
    GenJetAK8	= std::vector<eventBuffer::GenJetAK8_s>(20);
    GenPart	= std::vector<eventBuffer::GenPart_s>(200);
    GenVisTau	= std::vector<eventBuffer::GenVisTau_s>(15);
    IsoTrack	= std::vector<eventBuffer::IsoTrack_s>(20);
    Jet	= std::vector<eventBuffer::Jet_s>(55);
    LHEPart	= std::vector<eventBuffer::LHEPart_s>(25);
    Muon	= std::vector<eventBuffer::Muon_s>(20);
    Photon	= std::vector<eventBuffer::Photon_s>(25);
    SV	= std::vector<eventBuffer::SV_s>(35);
    SoftActivityJet	= std::vector<eventBuffer::SoftActivityJet_s>(20);
    SubGenJetAK8	= std::vector<eventBuffer::SubGenJetAK8_s>(30);
    SubJet	= std::vector<eventBuffer::SubJet_s>(30);
    Tau	= std::vector<eventBuffer::Tau_s>(20);
    TrigObj	= std::vector<eventBuffer::TrigObj_s>(65);

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
