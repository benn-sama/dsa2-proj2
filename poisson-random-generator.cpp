#include "poisson-random-generator.hpp"

Poisson::Poisson() {
}

double Poisson::randomArrivalTime(double lambda) { // generates arrival time for customers
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  std::random_device rd;
  generator.seed(rd());

  double randomNumber = distribution(generator);
  double arrivalTime = - (1 / lambda) * std::log(1 - randomNumber);

  // rounds to the nearest thousandth 
  std::string roundNearestThousandth = std::to_string(arrivalTime);
  roundNearestThousandth.erase(4, roundNearestThousandth.length());
  arrivalTime = std::stod(roundNearestThousandth);

  return arrivalTime;
}

double Poisson::randomServiceTime(double mu) {
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  std::random_device rd;
  generator.seed(rd());

  double randomNumber = distribution(generator);
  double arrivalTime = - (1 / mu) * std::log(1 - randomNumber);

  // rounds to the nearest thousandth 
  std::string roundNearestThousandth = std::to_string(arrivalTime);
  roundNearestThousandth.erase(4, roundNearestThousandth.length());
  arrivalTime = std::stod(roundNearestThousandth);

  return arrivalTime;
}