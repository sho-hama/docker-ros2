#include "NormalDistribution.h"

NormalDistribution::NormalDistribution(float mean, float standardDeviation){
  this->mean = mean;
  this->standardDeviation = standardDeviation;
}

double NormalDistribution::generateRamdomNum(){
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::normal_distribution<> dist(this->mean, this->standardDeviation);
  return dist(engine);
}
