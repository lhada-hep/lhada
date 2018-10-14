#ifndef CMSNANOAODADAPTER_H
#define CMSNANOAODADAPTER_H

#include <vector>
#include <string>
#include "tnm.h"
#include "TEParticle.h"

struct CMSNanoAODAdapter
{
  CMSNanoAODAdapter();
  ~CMSNanoAODAdapter();
  void operator()(eventBuffer& ev, std::string a, std::vector<TEParticle>& p);
  void operator()(eventBuffer& ev, std::string a, TEParticle& p);
};

#endif

