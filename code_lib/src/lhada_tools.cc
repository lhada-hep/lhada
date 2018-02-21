std::vector<LhadaParticle> apply_res_and_eff(const std::vector<LhadaParticle>& in,
					     double (*res)(const LhadaParticle&),
					     double (*eff)(const LhadaParticle&)){
  std::vector<LhadaParticle> out;
  for(auto p: in){
    if(lhadaRandom.uniform(1.) < eff(p)){
      out.push_bach(p.smear(res(p)));
    }
  }
  return out
};

