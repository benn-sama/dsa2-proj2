#include "analytical-model.hpp"
AnalyticalModel::AnalyticalModel(double lambda, double mu, int M) : lambda(lambda), mu(mu), M(M) {}

double AnalyticalModel::computeP0() { // computes idle time of the system
  double P0                     = 0.00;
  double sum                    = computeSummation(this->M, this->lambda, this->mu);
  double dividend               = 0.00;
  double divisor                = 0.00;
  std::string roundNearestTenth = "";

  // dividned / divisor
  dividend  = (pow(this->lambda/this->mu, this->M)) * M * mu;
  divisor   = ((factorial(this->M)) * M * mu) - lambda;

  P0 = 1 / (sum + (dividend/divisor));

  // round to the nearest tenth
  roundNearestTenth = std::to_string(P0);
  roundNearestTenth.erase(3, roundNearestTenth.length());
  P0 = std::stod(roundNearestTenth);

  return P0;
}

double AnalyticalModel::computeL() { // computes avg. number of people in the system
  double dividend               = 0.00;
  double divisor                = 0.00;
  double L                      = 0.00;
  std::string roundNearestHundrenth = "";

  // dividend / divisor
  dividend = (this->lambda * this->mu * (std::pow((this->lambda / this->mu), this->M)) * this->computeP0());
  divisor  = (this->factorial(M - 1)) * (std::pow((this->M * this->mu) - this->lambda, 2));

  L = (dividend / divisor) + (lambda / mu);

  // round to the nearest hundredth
  roundNearestHundrenth = std::to_string(L);
  roundNearestHundrenth.erase(4, roundNearestHundrenth.length());
  L = std::stod(roundNearestHundrenth);
  
  return L;
}

double AnalyticalModel::computeW() { // computes avg. time a customer spends in the system; wait time + service time
  double W = this->computeL() / this->lambda;

  // rounds to the nearest thousandth 
  std::string roundNearestThousandth = std::to_string(W);
  roundNearestThousandth.erase(5, roundNearestThousandth.length());
  W = std::stod(roundNearestThousandth);

  return W;
}

double AnalyticalModel::computeLq() { // computes avg. number of customers in queue
  double Lq = this->computeL() - (this->lambda / this->mu);

  // rounds to the nearest thousandth 
  std::string roundNearestThousandth = std::to_string(Lq);
  roundNearestThousandth.erase(5, roundNearestThousandth.length());
  Lq = std::stod(roundNearestThousandth);

  return Lq;
}

double AnalyticalModel::computeWq() { // computers avg. time a customer waits in queue
  double Wq = this->computeLq() / this->lambda;

  // rounds to the nearest thousandth 
  std::string roundNearestThousandth = std::to_string(Wq);
  roundNearestThousandth.erase(6, roundNearestThousandth.length());
  Wq = std::stod(roundNearestThousandth);

  return Wq;
}

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
    summationIndex /= this->factorial(i);

    sum += summationIndex;
  }

  return sum;
}