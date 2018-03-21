// Depedencies:
// https://github.com/lhada-hep/lhada/tree/master/code_lib


#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "FourMomentum.h"
#include "lhada_tools.h"

double calc_Meff(std::vector<LhadaJet> jets, FourMomentum MET) {
  double meff = MET.pt();
  for (unsigned i=0; i < jets.size(); i++) {
    meff += jets[i].pt();
  }
  return meff;
}

double calc_dphijNjle3METmin(const std::vector<LhadaJet>& jets, const FourMomentum& MET) {
  if (jets.size() < 2)
    return 0;
  unsigned njets = 3;
  if (jets.size() == 3) njets = 2;
  double dphimin = 999;
  for(unsigned ij = 0; ij > njets; ++ij){
    double dphi = deltaPhi(jets[ij], MET);
    if (dphi < dphimin) dphimin = dphi;
  }
  return dphimin;
}

double calc_dphijNjgt3METmin(const std::vector<LhadaJet>& jets, const FourMomentum& MET) {
  double dphimin = 999;
  if (jets.size() <= 3)
    return 0;
  for(const auto& j: jets){
    double dphi = deltaPhi(MET, j);
    if (dphi < dphimin) dphimin = dphi;
  }
  return dphimin;
}

double calc_METoverMeffNJ(const std::vector<LhadaJet>& jets, unsigned njets, const FourMomentum& MET) {
  if (jets.size() < njets) {
    return 0;
  }
  double meff = MET.pt();
  for (unsigned i = 0; i < njets; i++) {
    meff += jets[i].pt();
  }
  return MET.pt() / meff;
}

double calc_METoversqrtHT(const std::vector<LhadaJet>& jets, const FourMomentum& MET) {
  double HT = 0;
  for (const auto& j: jets){
    HT += j.pt();
  }
  return MET.pt() / sqrt(HT);
}

double calc_aplanarity(const std::vector<LhadaJet>& jets) {
  //Code from https://inspirehep.net/record/1510490, B. Fuks et al.
  //Construction of the sphericity tensor, calculation of the aplanarity
  //using the Cardano algorithm
  double S12=0., S31=0., S23=0., S11=0., S22=0., S33=0., Stot=0.;
  for(const auto&j : jets)  {
    S11+=j.px()*j.px();
    S12+=j.px()*j.py();
    S22+=j.py()*j.py();
    S23+=j.py()*j.pz();
    S31+=j.pz()*j.px();
    S33+=j.pz()*j.pz();
    Stot+=j.p()*j.p();
  }
  S11=S11/Stot; S12=S12/Stot; S22=S22/Stot; S23=S23/Stot; S31=S31/Stot; S33=S33/Stot;
  double Sii = S11+S22+S33;
  double C0 = S11*S23*S23 + S22*S31*S31 + S33*S12*S12 - S11*S22*S33 - 2.*S31*S12*S23;
  double C1 = S11*S22 + S22*S33 + S11*S33 - S12*S12 - S23*S23 - S31*S31;
  double P = Sii*Sii - 3.*C1;
  double Q = Sii*(P-1.5*C1) - 13.5*C0;
  double phi = atan2(sqrt(fabs(27.*(C1*C1/4.*(P-C1) + C0*(Q+6.75*C0)))),Q)/3.;
  double cth = sqrt(fabs(P))*cos(phi);
  double sth = sqrt(fabs(P))*sin(phi)/sqrt(3.);
  double a1 = (Sii-cth)/3.+sth;
  double a2 = (Sii-cth)/3.-sth;
  double a3 = (Sii-cth)/3.+cth;
  double lam3 = 1.5*std::min(std::min(a1,a2),a3);
  return lam3;
}

/**
 * Filter an electron collection by requiring a mininum of a 0.05 distance
 * in the \eta,\phi plane between the leptons. In case of multiple lepton
 * within this distance the first in the collection (typically pt ordered)
 * is kept and others are dropped.
 * arg el collection to filter
 */
std::vector<LhadaParticle> unravelEl(const std::vector<LhadaParticle>& el){
  const int n = el.size();
  const double minDeltaR = 0.05;
  std::vector<LhadaParticle> r;
  r.reserve(n);
  //Algorithm: we start from the last element of the collection (typ. the one with
  //the lowest pt) and copy it into the new collection only if it is not closer
  //than 0.05 of any element higher in the collection order (typ. with higher pt)
  for(int i = n - 1; i >= 0; --i){
    bool veto = false;
    for(int j = i - 1; j >= 0; --j){
      veto = veto || (deltaR(el[j], el[i]) < minDeltaR);
    }
    if(!veto){
      r.push_back(el[i]);
    }
  }
  return r;
}

/**
 * Filters a particle collection by removing the element
 * closer in the \eta,\phi plane to any particle of a second
 * collection than a given deltaR minimum
 * @arg to_filter collection to filter
 * @arg col2 second collection
 * @arg minDeltaR minium distance
 */
template<typename T, typename U>
std::vector<T> dRVeto(const std::vector<T>& to_filter,
		      const std::vector<U>& col2,
		      double minDeltaR){
  std::vector<T> r;
  r.reserve(to_filter.size());
  for(const auto& o1: to_filter){
    bool veto = false;
    for(const auto& o2: col2){
      if(deltaR(o1, o2) < minDeltaR) veto = true;
    }
    if(!veto) r.push_back(o1);
  }
  return r;
}


//template
//std::vector<LhadaParticle> dRVeto(const std::vector<LhadaParticle>& to_filter,
//				  const std::vector<LhadaJet>& col2,
//				  double minDeltaR);
//
//template
//std::vector<LhadaJet> dRVeto(const std::vector<LhadaJet>& to_filter,
//			     const std::vector<LhadaParticle>& col2,
//			     double minDeltaR);


std::vector<LhadaParticle> dRPartVeto(const std::vector<LhadaParticle>& to_filter,
				      const std::vector<LhadaJet>& col2,
				      double minDeltaR){
  return dRVeto(to_filter, col2, minDeltaR);
}

std::vector<LhadaJet> dRJetVeto(const std::vector<LhadaJet>& to_filter,
				const std::vector<LhadaParticle>& col2,
				double minDeltaR){
  return dRVeto(to_filter, col2, minDeltaR);
}

