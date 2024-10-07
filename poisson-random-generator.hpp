/**
 * @file poisson-random-generator.hpp
 * @brief Header file for the Poisson class, which provides methods to generate random arrival and service times based on Poisson distribution.
 *
 * This file contains the declaration of the Poisson class, which includes methods to generate random arrival times and service times using the Poisson distribution. 
 * The class utilizes the <random> and <cmath> libraries to achieve this functionality.
 *
 */
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
    double randomServiceTime(double mu);
};

#endif