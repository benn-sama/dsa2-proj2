/**
 * @file simulation.hpp
 * @brief Defines the Simulation class for simulating a queuing system.
 *
 * This file contains the declaration of the Simulation class, which is used to 
 * simulate a queuing system with multiple service channels. The class includes 
 * methods for processing events, running the simulation, and calculating statistics.
 * It utilizes various components such as FIFO queues, priority queues, and 
 * Poisson random generators to model the arrival and service processes.
 * 
 */
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "analytical-model.hpp"
#include "FIFO.hpp"
#include "pq.hpp"
#include "poisson-random-generator.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Simulation {
  private:
    double lambda            = 0.00;   // avg. number of arrivals
    double mu                = 0.00;   // avg. number we can serve per unit of time
    int M                    = 0.00;      // number of service channels
    double simulationEvents     = 0;      // number of events to simulate
    double currentSimEvents     = 0.00;      // counts the current number of events
    int serverAvailableCount = M;      // tracks the amount of channels available at that time
    double customerWaitedCount = 0.00;       // number of customers waiting in line
    double totalWaitTime = 0.00;       // total wait time of customers waiting
    double serviceTime = 0.00;         // total service time of customers
    double totalSimulationTime = 0.00; // total time of the simulation
    double totalArrivals = 0.00;             // total number of arrivals
    double totalServed = 0.00;               // total number of customers served
    std::vector<bool> channels;        // number of available channels
    FIFO fifo;                         // initialize fifo 
    PQ minHeap;                        // initialize pq min heap
    AnalyticalModel* analyticalModel;  // initialize analytical model for statistics
    Poisson poisson;                   // random arrival time
    double idleTime = 0.00;            // idle time of the system
  public:
    Simulation(std::string file);      // default constructor
    void processNextEvent();
    void runSimulation();
    void processStatistics(Customer* currentCustomer);
    void placeFirstArrivalsInPQ();
    bool moreArrivals();
    void addArrivalsToPQ();
    void showSimulationResults();
};

#endif