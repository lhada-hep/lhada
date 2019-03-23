#ifndef DELPHESADAPTER_H
#define DELPHESADAPTER_H

#include <vector>
#include <string>
#include "tnm.h"
#include "TEParticle.h"

struct DelphesAdapter
{
  DelphesAdapter();
  ~DelphesAdapter();
  void operator()(eventBuffer& ev, std::string a, std::vector<TEParticle>& p);
  void operator()(eventBuffer& ev, std::string a, TEParticle& p);
};

#endif

