#include "simulation.hpp"

Simulation::Simulation(std::string file) { // constructor for extracting files 
  std::ifstream inputFile(file);
  std::string line;

  while (!inputFile.is_open()) {
    std::cout << "File: " << file << " failed to open." << std::endl;
    exit(1);
  }

  while (std::getline(inputFile, line)) { // extracts the data from files and assigns values to the properties of simulaton
    std::istringstream iss(line);

    iss >> this->lambda;
    iss >> this->mu;
    iss >> this->M;
    iss >> this-> simulationEvents;
  }

  for (int i = 0; i < M; ++i) {
    channels.push_back(false);
  }

  inputFile.close();
}

void Simulation::processNextEvent() {

}

void Simulation::runSimulation() {

}

void Simulation::processStatistics() {
  this->analyticalModel = new AnalyticalModel(this->lambda, this->mu, this->M);
  double waitTime = analyticalModel->computeWq();

  if (waitTime > 0) {
    ++this->customerWaitingCount;
    this->totalWaitTime += waitTime;
  }
}