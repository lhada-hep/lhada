/**
 * Common Lhada library.
 *
 * Declaration of the FourMometum class
 *
 */


#ifndef FourMomentum_h
#define FourMomentum_h

/** Definition of the Lhada types
 */
class FourMomentum {
public:
  /**
   * Copy constructor
   */
  FourMomentum(const FourMomentum&);

  /**
   * Constructor
   * @param e energy
   * @param px x-component of the mometum
   * @param py y-component of the mometum
   * @param pz z-component of the mometum
   */
  FourMomentum(double e, double px, double py, double pz);

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
   * absolute mometum
   */
  double p() const;
  
  /**
   *pseudorapidity
   * Lhada name: eta
   */
  double eta() const;


  /**
   * pseudorapidity absolute value

   * Lhada name: abseta
   */
  double abseta() const;
  
  /**
   *rapidity
   * Lhada name: rapidity
   */
  double rapidity() const;

  /*
   * Methods
   */
  
  /**
   * Scale momentum absolute value keeping 
   * the direction constant.
   */
  void scale(double factor);

  /**
   * Smear momentum absolute value keeping 
   * the direction constant according to a
   * Gaussian law.
   */
  void smear(double sigma);
};

#endif //FourMomentum_h
