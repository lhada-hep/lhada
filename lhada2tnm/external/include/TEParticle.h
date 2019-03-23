#ifndef TEPARTICLE_H
#define TEPARTICLE_H
// ---------------------------------------------------------------------------
// File: TEParticle.h
// Description: Prototype of a generic ADL particle class.
// created: Les Houches 2015 HBP
// updated: 21-Mar-2019 HBP add cutvalue template class
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "TROOT.h"
#include "TLorentzVector.h"
// ---------------------------------------------------------------------------
template <class T>
class cutvector : public std::vector<T>
{
 public:
  cutvector<T>() : std::vector<T>() {}
  cutvector<T>(size_t n) : std::vector<T>(n, 0) {}
  ~cutvector<T>() {}

  bool operator<(T x)
  {
    bool value=true;
    for(size_t c=0; c < this->size(); c++)
      value = value && ((*this)[c] < x);
    return value;
  }

  bool operator>(T x)
  {
    bool value=true;
    for(size_t c=0; c < this->size(); c++)
      value = value && ((*this)[c] > x);
    return value;
  }
};
 
struct TEParticle : public TLorentzVector
{
  TEParticle();
  TEParticle(int PID_,
	     double PT, double Eta, double Phi, double Mass=0);
  TEParticle(const TEParticle& p);
  ~TEParticle();

  static std::string name(int pdgid);
  
  bool        operator<(const TEParticle& p) const;
  TEParticle& operator=(const TEParticle& p);
  TEParticle  operator+(const TEParticle& o) const;
  TEParticle  operator-(const TEParticle& o) const;
  TEParticle  operator*(double a) const;
  inline      operator float() {return Pt(); }
  inline      operator double() {return Pt(); }
  
  double      operator()(std::string varname);

  void        operator()(std::string varname, double x);
  
  int  UID;   // event unique identifier
  int  PID;   // PDG ID
  int  ID;
  int  Status;  
  int  Mother;
  bool Skip;
  double Order;
  std::string Name;
  std::vector<int> Daughters;
  std::map<std::string, double> Value;
  
  static int s_UID;

  ClassDef(TEParticle,0)
};
std::ostream& operator<<(std::ostream& os, const TEParticle& o);

#endif
