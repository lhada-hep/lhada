#ifndef TEPARTICLE_H
#define TEPARTICLE_H
// ---------------------------------------------------------------------------
// File: TEParticle.h
// Description: Prototype of a generic LHADA particle class.
// created: Les Houches 2015 HBP
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <map>
#include "TROOT.h"
#include "TLorentzVector.h"
// ---------------------------------------------------------------------------
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

  //ClassDef(TEParticle,0)
};
std::ostream& operator<<(std::ostream& os, const TEParticle& o);

#endif
