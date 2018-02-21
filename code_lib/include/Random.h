#ifndef Random_h
#define Random_h
class Random{
public:
  double uniform(double x);
  double gauss(double mean, double sigma);
  double poisson(int mean);
  double breitWigner(double mean, double gamma);
  double exp(double tau);
  double landau(double mean, double sigma);
  double binomial(int ntot, double prob);
};

extern Random lhadaRand;

#endif

 
