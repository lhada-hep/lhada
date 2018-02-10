#ifndef DELPHESADAPTER_H
#define DELPHESADAPTER_H

#include <vector>
#include <string>
#include "tnm.h"
#include "LHParticle.h"

struct DelphesAdapter
{
  DelphesAdapter();
  ~DelphesAdapter();
  void operator()(eventBuffer& ev, std::string a, std::vector<LHParticle>& p);
  void operator()(eventBuffer& ev, std::string a, LHParticle& p);
};

#endif

