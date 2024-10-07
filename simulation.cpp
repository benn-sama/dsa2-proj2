#include "simulation.hpp"
#include <iostream>

Simulation::Simulation(std::string file) { // constructor to initialize the simulation from a file
    std::ifstream infile(file);
    if (infile.is_open()) {
        infile >> this->lambda;
        infile >> this->mu;
        infile >> this->M;
        infile >> this->simulationEvents;
        this->serverAvailableCount = this->M;
        this->channels.resize(this->M, true);
        infile.close();
    } 
    else {
        std::cerr << "Error: Unable to open file " << file << std::endl;
        exit(EXIT_FAILURE);
    }
    this->analyticalModel = new AnalyticalModel(this->lambda + 0.00, this->mu + 0.00, this->M);
}

void Simulation::placeFirstArrivalsInPQ() { // method to place the first arrivals in the priority queue
    for (int i = 0; i < this->simulationEvents; ++i) {
        double arrivalTime = this->poisson.randomArrivalTime(this->lambda);
        Customer* customer = new Customer(arrivalTime, 0.00, 0.00);
        totalWaitTime += arrivalTime;
        if (customer == nullptr) {
            std::cerr << "Error: Memory allocation for Customer failed" << std::endl;
            exit(EXIT_FAILURE);
        }
        this->minHeap.insert(customer);
    }
}

void Simulation::processNextEvent() { // method to process the next event
    if (this->minHeap.isEmpty()) {
        return; // no events to process
    }

    // get the next event from the priority queue
    Customer* currentCustomer = this->minHeap.serve();
    if (currentCustomer == nullptr) {
        std::cerr << "Error: Served a null customer from minHeap" << std::endl;
        return;
    }

    if (currentCustomer->arrivalTime > this->currentSimEvents) {
        this->currentSimEvents = currentCustomer->arrivalTime;
    }

    // check if the event is an arrival or departure
    if (currentCustomer->startOfTime == 0.00) { // arrival event
        if (this->serverAvailableCount > 0) {
            // s server is available, start servicing the customer
            --this->serverAvailableCount;
            currentCustomer->startOfTime = this->currentSimEvents;
            double interval = this->poisson.randomServiceTime(this->mu);
            currentCustomer->departureTime = currentCustomer->startOfTime + interval;

            // schedule a departure event
            Customer* departureCustomer = new Customer(currentCustomer->arrivalTime, currentCustomer->startOfTime, currentCustomer->departureTime);
            this->minHeap.insert(departureCustomer);
        } else {
            // no server available, place the customer in the FIFO queue
            this->fifo.insert(currentCustomer);
        }
    } 
    else { // departure event
        ++this->serverAvailableCount;

        // process statistics for the departing customer
        this->processStatistics(currentCustomer);

        if (!this->fifo.isEmpty()) {
            // serve the next customer in the FIFO queue
            Customer* nextCustomer = this->fifo.serve();
            ++this->totalServed;
            if (nextCustomer == nullptr) {
                std::cerr << "Error: Served a null customer from FIFO" << std::endl;
                return;
            }
            nextCustomer->startOfTime = this->currentSimEvents;
            double interval = this->poisson.randomServiceTime(this->mu);
            nextCustomer->departureTime = this->currentSimEvents + interval;

            // schedule a new departure event
            this->minHeap.insert(nextCustomer);

            --this->serverAvailableCount;
        }
    }

    delete currentCustomer; // clean up the processed customer
}

void Simulation::processStatistics(Customer* currentCustomer) { // method to process statistics for a customer
    if (currentCustomer == nullptr) {
        std::cerr << "Error: Null customer passed to processStatistics" << std::endl;
        return;
    }

    double currentWaitTime = currentCustomer->startOfTime - currentCustomer->arrivalTime;

    if (currentWaitTime > 0) {
        ++this->customerWaitedCount;
        this->totalWaitTime += currentWaitTime;
    }

    double currentServiceTime = currentCustomer->departureTime - currentCustomer->startOfTime;
    this->serviceTime += currentServiceTime;

    if (this->serverAvailableCount == this->M) {
        this->idleTime += currentServiceTime;
    }
}


bool Simulation::moreArrivals() { // method to check if there are more arrivals
    return this->currentSimEvents < this->simulationEvents;
}


void Simulation::addArrivalsToPQ() { // method to add new arrivals to the priority queue
    double arrivalTime = this->poisson.randomArrivalTime(this->lambda);
    Customer* customer = new Customer(arrivalTime, 0.00, 0.00);
    this->minHeap.insert(customer);
    ++this->totalArrivals;
}

void Simulation::showSimulationResults() { // method to show the simulation results
    this->totalArrivals += this->simulationEvents;
    this->totalServed = this->totalArrivals - this->customerWaitedCount;
    this->totalSimulationTime = this->totalWaitTime + this->serviceTime;
    double simLambda = static_cast<double>(this->totalArrivals) / this->totalSimulationTime;
    double simMu = static_cast<double>(this->totalServed) / this->totalSimulationTime;

    AnalyticalModel analyticalModelSim(simLambda, simMu, this->M);

    std::cout << "Analytical Model:" << std::endl;
    std::cout << "P0: " << this->analyticalModel->computeP0() << std::endl;
    std::cout << "L: " << this->analyticalModel->computeL() << std::endl;
    std::cout << "W: " << this->analyticalModel->computeW() << std::endl;
    std::cout << "Wq: " << this->analyticalModel->computeWq() << std::endl << std::endl;

    std::cout << "Simulation Results:" << std::endl;
    std::cout << "P0: " << analyticalModelSim.computeP0() << std::endl;
    std::cout << "L: " << analyticalModelSim.computeL() << std::endl;
    std::cout << "W: " << analyticalModelSim.computeW() << std::endl;
    std::cout << "Wq: " << analyticalModelSim.computeWq() << std::endl;
}


void Simulation::runSimulation() { // method to run the simulation
    // initialize the simulation
    this->placeFirstArrivalsInPQ();
    this->serverAvailableCount = this->M;

    // process events
    while (!this->minHeap.isEmpty()) {
        this->processNextEvent();

        // check if more arrivals need to be added to the priority queue
        if (this->moreArrivals() && this->minHeap.getSize() <= this->M + 1) {
            this->addArrivalsToPQ();
        }
    }

    // Calculate total simulation time
    this->totalSimulationTime = this->currentSimEvents;

    // Show simulation results
    this->showSimulationResults();
}