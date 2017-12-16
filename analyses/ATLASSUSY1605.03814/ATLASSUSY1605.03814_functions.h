double Meff(std:vector<TLorentzVector> jets, TLorentzVector MET) {
  double meff = MET.pt();
  for (int i=0; i<jets.size(); i++) {
    meff += jets[i].pt();
  }
  return meff;
}

double dphijNjle3METmin(std:vector<TLorentzVector> jets, TLorentzVector MET) {
  if (jets.size() < 2)
    return 0;
  int njets = 3;
  if (jets.size() == 3) njets = 2;
  double dphimin = 999;
  for (int i=0; i<njets; i++) {
    double dphi = MET.DeltaPhi(jet[i]);
    if (dphi < dphimin) dphimin = dphi;
  }
  return dphimin;
}

double dphijNjgt3METmin(std:vector<TLorentzVector> jets, TLorentzVector MET) {
  double dphimin = 999;
  if (jets.size() <= 3) 
    return 0;
  for (int i=0; i<jets.size(); i++) {
    double dphi = MET.DeltaPhi(jet[i]);
    if (dphi < dphimin) dphimin = dphi;
  }
  return dphimin;
}

double METovermeffNJ(std:vector<TLorentzVector> jets, int njets TLorentzVector MET) {
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

double METoversqrtHT(std:vector<TLorentzVector> jets, TLorentzVector MET) {
  double HT = 0;
  for (int i=0; i<jets.size(); i++) {
    HT += jet[i].pt();
  }
  return MET.pt() / sqrt(HT);
}

double aplanarity(std::vector<TLorentzVector> jets) {
  // to be filled in
  return 0;
}


