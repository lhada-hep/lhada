/**
 * Common Lhada library.
 *
 * Declaration of the LHADJet class
 *
 */


#ifndef LhadaJet_h
#define LhadaJet_h

#include "FourMomentum.h"

class LhadaJet: public FourMomentum {
  /**
   * Copy constructor
   */
  LhadaJet(const LhadaJet&);

  /**
   * Constructor
   * @param pdgid jet identifier using PDG convention
   * @param e energy
   * @param px x-component of the mometum
   * @param py y-component of the mometum
   * @param pz z-component of the mometum
   */
  LhadaJet(int pdgid, double e, double px, double py, double pz);


  /**
   * Constructor
   * @param pdgid jet identifier using PDG convention
   * @param e energy
   * @param px x-component of the mometum
   * @param py y-component of the mometum
   * @param pz z-component of the mometum
   * @param x x-component of the jet production vertex
   * @param y y-component of the jet production vertex
   * @param z z-component of the jet production vertex
   */
  LhadaJet(int pdgid, double e, double px, double py, double pz,
		double x, double y, double z);


  /**
   *charge
   * Lhada name: charge
   */
  double charge() const;

  /**
   * Momentum phi coordinate
   * Lhada name: phi
   */
  double phi() const;

  /**
   *Jet production vertex x-coordinate
   * Lhada name: x
   */
  double x() const;

  /**
   * Jet production vertex y-coordinate
   * Lhada name: y
   */
  double y() const;

  /**
   * Jet production vertex z-coordinate
   * Lhada name: y    z
   */
  double z() const;
};


#endif //LhadaJet_h not defined
