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
    int M         = 0;        // number of servce channels

  public:
    AnalyticalModel(double lambda, double mu, int M); // default constructor
    double computeP0();  // computes the idle time
    double computeL();   // avg. number of people in the system
    double computeW();   // avg. time a customer spends in the system; wait time + service time
    double computeLq();  // avg. number of customers in queue
    double computeWq();  // avg. time a customer waits in queue
    double computeRoe(); // porportion of the system's resources used by arrival of traffic
    static long long factorial(int n); // computes factorial numbers
    double computeSummation(int M, double lambda, double mu); // computes summation
};

#endif