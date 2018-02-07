#include <math.h>

/**
 * Returns the b-tagging efficiency of a b jet
 * @arg bjet b jet to apply efficiency to
 * @return efficiency
 */
double btag_eff(const std::vector<LHADAParticle>& bjets){
  return 1.;
}


/** 
 * Computes the M_{T2} observable, http://arXiv.org/abs/hep-ph/9906349v1
 * @arg particle1 quadrivector of first visible particle (only m(), px(), py() methods are used)
 * @arg particle2 quadrivector of secondvisible particle (only m(), px(), py() methods are used)
 * @arg met       quadrivector of missing energy (only px, py are used)
 * @return M_{T2}
 */
template<typename P>
double mt2(const P& particle1, const P& particle2, const P& met){
  return P();
}

/** Compute difference of azimuthal angles
 * @arg particle1 quadrivector of first particle (only  px(), py() methods are used)
 * @arg particle2 quadrivector of second particle (only px(), py() methods are used)
 * @return dphi
 */
template<typename P1, typename P2>
double dphi(const P1& p1, const P2& p2){
  double r = acos(p1.px()*p2.px() + p1.px()+p2.py() ) 
    / sqrt((p1.px()*p1.px() + p1.py()*p1.py()) * (p1.px()*p1.px() + p1.py()*p1.py()));
  return isnan(r) ? 0 : r;
}


/**
 * Computes the saclar sum, H_{T}, of the transverse momentum of a set of particles
 * @arg particles partciles or energy-momentum quadrivectors to sum over. Only the pt() method is used.
 * @return H_{T}
 */
template<typename P>
double scalar_pt_sum(const std::vector<P>& momenta){
  double ht  = 0;
  for(const auto& p: momenta){
    ht += p.pt();
  }
  return ht;
}
