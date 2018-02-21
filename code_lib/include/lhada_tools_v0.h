/**
 * Common Lhada library.
 *
 * Analysis description in Lhada17 can use the tool functions defined in this file
 *
 */

/** Definition of the Lhada types
 */
class FourMomentum {
public:
  /**
   * Mass
   * Lhada name: mass
   */
  double mass() const;

  /**
   * Energy
   * Lhada name: e
   */
  double e() const;

  /**
   * Momentum x-component
   * Lhada name: px
   */
  double px() const;

  /**
   * Momentum y-component
   * Lhada name: py
   */
  double py() const;

  /**
   *momentum z-component
   * Lhada name: pz
   */
  double pz() const;

  /**
   *absolute transverse momentum
   * Lhada name: pt
   */
  double pt() const;

  /**
   *pseudorapidity
   * Lhada name: eta
   */
  double eta() const;

  /**
   *rapidity
   * Lhada name: rapidity
   */
  double rapidity() const;

  /**
   *charge
   * Lhada name: charge
   */
  double charge() const;

  /**
   * Spin
   * Lhada name: spin
   */
  double spin() const;

  /**
   *PDG particle id
   * Lhada name: pdgid
   */
  double pdgid() const;

  /**
   * Momentum phi coordinate
   * Lhada name: phi
   */
  double phi() const;

  /**
   *Particle production vertex x-coordinate
   * Lhada name: x
   */
  double x() const;

  /**
   * Particle production vertex y-coordinate
   * Lhada name: y
   */
  double y() const;

  /**
   * Particle production vertex z-coordinate
   * Lhada name: y    z
   */
  double z() const;
}
