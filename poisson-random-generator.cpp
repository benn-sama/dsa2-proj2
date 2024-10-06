#include "poisson-random-generator.hpp"

Poisson::Poisson() {}

double Poisson::randomArrivalTime(double lambda) { // generates arrival time for customers
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  double randomNumber = distribution(generator);
  double arrivalTime = - (1 / lambda) * std::log(1 - randomNumber);

  return arrivalTime;
}