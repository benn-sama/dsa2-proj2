#include "analytical-model.hpp"

long long AnalyticalModel::factorial(int n) { // computes factorial numbers
  if (n == 0) {
    return 1;
  } 
  else {
    return n * factorial(n - 1);
  }
}

double AnalyticalModel::computeSummation(int M, double lambda, double mu) { // computes summation
  int bound             = M - 1;
  double sum            = 0;
  double summationIndex = 0;

  for (int i = 0; i <= bound; ++i) { 
    summationIndex  = pow(lambda/mu, i);
    summationIndex /= factorial(i);

    sum += summationIndex;
  }

  return sum;
}

AnalyticalModel::AnalyticalModel(double lambda, double mu, int M) : lambda(lambda), mu(mu), M(M) {}

double AnalyticalModel::computeP0() { // computes idle time of the system
  double P0       = 0.00;
  double sum      = computeSummation(this->M, this->lambda, this->mu);
  double dividend = 0.00;
  double divisor  = 0.00;
  std::string roundNearestTenth = "";

  dividend  = (pow(this->lambda/this->mu, this->M)) * M * mu;

  divisor   = ((factorial(this->M)) * M * mu) - lambda;

  P0 = 1 / (sum + (dividend/divisor));

  roundNearestTenth = std::to_string(P0);
  roundNearestTenth.erase(3, roundNearestTenth.length());
  P0 = std::stod(roundNearestTenth);

  return P0;
}

double AnalyticalModel::computeL() { // computes avg. number of people in the system
  double dividend = 0.00;
  double divisor  = 0.00;

  dividend = (lambda * mu * (std::pow(lambda/mu, M)));
  return 0.00;
}

double AnalyticalModel::computeW() { // computes avg. time a customer spends in the system; wait time + service time
  return 0.00;
}

double AnalyticalModel::computeLq() { // computes avg. number of customers in queue
  return 0.00;
}

double AnalyticalModel::computeWq() { // computers avg. time a customer waits in queue
  return 0.00;
}

double AnalyticalModel::computeRoe() { // computes porportion of the system's resources used by arrival of traffic
  return 0.00;
}