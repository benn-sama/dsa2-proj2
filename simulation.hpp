// #ifndef SIMULATION_HPP
// #define SIMULATION_HPP

// #include "analytical-model.hpp"
// #include "FIFO.hpp"
// #include "pq.hpp"
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>

// class Simulation {
//   private:
//     double lambda            = 0.00;   // avg. number of arrivals
//     double mu                = 0.00;  // avg. number we can serve per unit of time
//     int M                    = 0;      // number of service channels
//     int simulationEvents     = 0;      // number of events to simulate
//     int currentSimEvents     = 0;      // counts the current number of events
//     int serverAvailableCount = M;      // tracks the amount of channels available at that time
//     int customerWaitingCount = 0;      // number of customers waiting in line
//     double totalWaitTime = 0.00;       // total wait time of customers waiting
//     std::vector<bool> channels;        // number of available channels
//     FIFO fifo;                         // initialize fifo 
//     PQ minHeap;                        // initialize pq min heap
//     AnalyticalModel* analyticalModel;  // initialize analytical model for statistics
//     Customer* customer;
//   public:
//     Simulation(std::string file); // default constructor
//     void processNextEvent();
//     void runSimulation();
//     void processStatistics();
// };

// #endif