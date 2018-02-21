/**
 * Common Lhada library.
 *
 * Analysis description in Lhada17 can use the tool functions defined in this file
 *
 */

#ifndef Lhada_Tools_h
#define Lhada_Tools_h

/**
 * Computes the azimuthal angle separation between two momenta mapped to
 * the [0, pi] range.
 * @arg p1 first momentum. Only transvers components (px,py) are used
 * @arg p2 first momentum. Only transvers components (px,py) are used
 * @return azimuthal angle separation
 */
double deltaPhi(const FourMomentum& p1, const FourMomentum& p2);

/**
 * Computes the distance between two momenta in the (\phi, \eta) plane,
 * deltaR = sqrt(\delta \phi ^ 2 + \delta \eta ^2)
 *
 */
double deltaR(const FourMomentum& p1, const FourMomentum& p2);


/**
 * Computes the distance between two momenta in the (\phi, y) plane,
 * deltaR = sqrt(\delta \phi ^ 2 + \delta \y ^2)
 *
 */
double deltaRy(const FourMomentum& p1, const FourMomentum& p2);


/**
 * Computes asymmetric m_{T2}**2 using the bisection method.
 * Ref.: Cheng, Han arXiv:0810.5178, Lester, Nachman arXiv:1411.4312,
 *       Barr, Gripalos,cLester arXiv:0908.3779
 *
 * If invisssibleMass2 is set to -1 , symm mT2**2 will be calculated.
 *
 * @arg a sum of momenta of visible particles for the fisrt decay chain
 * @arg a sum of momenta of visible particles for the second decay chain
 * @arg ptmiss missing momentum
 * @arg invisibleMass_a invisible mass for the first decay chain
 * @arg invisibleMass_b invisible mass for the second decay chain.
 */
double mT2Sq(const FourMomentum& a, const FourMomentum& b,
	     const FourMomentum& ptmiss, double invisiblesMass_a,
	     double invisiblesMass_b);
/**
 * Computes asymmetric m_{T2} using the bisection method.
 *
 * @see mt2Sq()
 */
double mT2(const FourMomentum& a, const FourMomentum& b,
	     const FourMomentum& ptmiss, double invisiblesMass_a,
	     double invisiblesMass_b);
/**
 * Apply efficiency and Gaussian smearing on a particle collection.
 *
 * @arg in particle collection to transform
 * @arg res resolution function returning the standard deviation of the smearing
 *      to apply
 * @arg eff efficiency function returning the efficiency to use
 */
std::vector<LhadaParticle> apply_res_and_eff(const std::vector<LhadaParticle>& in,
					     double (*res)(const LhadaParticle&),
					     double (*eff)(const LhadaParticle&));


#endif //Lhada_Tools_h not defined
