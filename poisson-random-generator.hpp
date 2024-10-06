#ifndef POISSON_RANDOM_GENERATOR_HPP
#define POISSON_RANDOM_GENERATOR_HPP
#include <random>
#include <cmath>

// double lambda = 0.00;    // avg. number of arrivals
// double mu     = 0.00;     // avg. number we can serve per unit of time
// int M         = 0;        // number of service channels


class Poisson {
  public:
    Poisson();
    double randomArrivalTime(double lambda);
};

#endif