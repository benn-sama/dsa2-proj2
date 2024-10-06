#include "poisson-random-generator.hpp"
#include <iostream>

void testArrivalTime() {
  Poisson poisson;

  std::cout << poisson.randomArrivalTime(2);
}

int main () {
  testArrivalTime();
  return 0;
}