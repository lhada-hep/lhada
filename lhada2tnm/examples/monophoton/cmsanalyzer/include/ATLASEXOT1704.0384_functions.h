#ifndef ATLASEXO1704_0384_functions_H
#define ATLASEXO1704_0384_functions_H
#include <cmath>
#include "TLorentzVector.h"

double METoverSqrtSumET(TLorentzVector& MET, double scalarHT) {
  return MET.Pt() / sqrt(scalarHT);
}

#endif


