#include <iostream>
#include "simulation.hpp"

int main() {
  Simulation simulation("test1.txt");
  std::cout << "simulation 1 results: " << std::endl;
  simulation.runSimulation();
  std::cout << std::endl;

  Simulation simulation2("test2.txt");
  std::cout << "simulation 2 results: " << std::endl;
  simulation2.runSimulation();

  return 0;
}