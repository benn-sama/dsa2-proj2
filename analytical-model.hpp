/**
 * @class AnalyticalModel
 * @brief A class to model and analyze queueing systems using analytical methods.
 *
 * This class provides methods to compute various performance metrics of a queueing system,
 * such as the average number of customers in the system, the average time a customer spends
 * in the system, the average number of customers in the queue, and the average time a customer
 * waits in the queue. It also includes methods to compute the idle time of the system, the
 * proportion of the system's resources used by the arrival of traffic, and factorial numbers.
 *
 * @param lambda The average number of arrivals per unit of time.
 * @param mu The average number of customers that can be served per unit of time.
 * @param M The number of service channels.
 */
#ifndef ANALYTICAL_MODEL_HPP
#define ANALYTICAL_MODEL_HPP
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>

class AnalyticalModel {
  private:
    double lambda = 0.00;    // avg. number of arrivals
    double mu     = 0.00;     // avg. number we can serve per unit of time
    int M         = 0;        // number of service channels

  public:
    AnalyticalModel(double lambda, double mu, int M); // constructor
    double computeP0();                // computes the idle time
    double computeL();                 // avg. number of people in the system
    double computeW();                 // avg. time a customer spends in the system; wait time + service time
    double computeLq();                // avg. number of customers in queue
    double computeWq();                // avg. time a customer waits in queue
    static long long factorial(int n); // computes factorial numbers
    double computeSummation(int M, double lambda, double mu); // computes summation
};

#endif