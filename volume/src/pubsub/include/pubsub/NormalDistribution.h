#include <random>
#include <fstream>

class NormalDistribution {
public:
  NormalDistribution(float mean, float standardDeviation);
  double generateRamdomNum();
private:
  float mean;
  float standardDeviation;
};
