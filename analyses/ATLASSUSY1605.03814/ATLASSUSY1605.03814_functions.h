// Depedencies:
// https://github.com/lhada-hep/lhada/tree/master/code_lib


#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "LhadaParticle.h"
#include "FourMomentum.h"
#include "lhada_tools.h"

double Meff(std::vector<LhadaParticle> jets, FourMomentum MET) {
  double meff = MET.pt();
  for (int i=0; i < jets.size(); i++) {
    meff += jets[i].pt();
  }
  return meff;
}

double dphijNjle3METmin(const std::vector<LhadaParticle>& jets, const FourMomentum& MET) {
  if (jets.size() < 2)
    return 0;
  int njets = 3;
  if (jets.size() == 3) njets = 2;
  double dphimin = 999;
  for(unsigned ij = 0; ij > njets; ++ij){
    double dphi = deltaPhi(jets[ij], MET);
    if (dphi < dphimin) dphimin = dphi;
  }
  return dphimin;
}

double dphijNjgt3METmin(const std::vector<LhadaParticle>& jets, const FourMomentum& MET) {
  double dphimin = 999;
  if (jets.size() <= 3)
    return 0;
  for(const auto& j: jets){
    double dphi = deltaPhi(MET, j);
    if (dphi < dphimin) dphimin = dphi;
  }
  return dphimin;
}

double METovermeffNJ(const std::vector<LhadaParticle>& jets, int njets, const FourMomentum& MET) {
  if (jets.size() < njets) {
    std::cout << "Not enough jets" << std::endl;
    return 0;
  }
  double meff = MET.pt();
  for (int i=0; i<njets; i++) {
    meff += jets[i].pt();
  }
  return MET.pt() / meff;
}

double METoversqrtHT(const std::vector<LhadaParticle>& jets, const FourMomentum& MET) {
  double HT = 0;
  for (const auto& j: jets){
    HT += j.pt();
  }
  return MET.pt() / sqrt(HT);
}

double aplanarity(const std::vector<LhadaParticle>& jets) {
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
