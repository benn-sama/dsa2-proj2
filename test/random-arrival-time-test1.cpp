#include "poisson-random-generator.hpp"
#include <iostream>

void testArrivalTime() {
  Poisson poisson;

  std::cout << "Random Arrivale Time: " << poisson.randomArrivalTime(2) << std::endl;
  std::cout << "Random Service Time: " << poisson.randomServiceTime(2) << std::endl;

}

int main () {
  testArrivalTime();
  return 0;
}