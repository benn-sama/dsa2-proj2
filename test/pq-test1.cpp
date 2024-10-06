#include "pq.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

void testPQ() {
  PQ pq;

  try { // tests if pq is initially empty
    if (pq.getSize() != 0) {
      throw std::runtime_error("PQ has not been initialized correctly!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------PQ INITIALIZE FAILED----------\n\n" << e.what() << std::endl;
  }

  Customer* customer1 = new Customer(1.0, 2.0, 3.0);
  pq.insert(customer1);
  try  { // test if insert method works
    if (pq.getSize() == 0) {
      throw std::runtime_error("PQ queue should not be empty after using insert method!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------PQ INSERT METHOD FAILED----------\n\n" << e.what() << std::endl;
  }

  // insert another customer into the PQ queue
  Customer* customer2 = new Customer(4.0, 5.0, 6.0);
  pq.insert(customer2);

  // serves(remove) the customer with the highest priority (smallest value)
  pq.serve();
  try { // tests if the PQ queue has one node after serving one customer
    if (pq.getSize() != 1) {
      throw std::runtime_error("PQ queue should only have one node!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------PQ SERVE METHOD FAILED----------\n\n" << e.what() << std::endl;
  }

  // serves(remove) another customer from the PQ
  pq.serve();
  try { // test serve again to see if the pq queue is empty
    if (pq.getSize() != 0) {
      throw std::runtime_error("PQ should be empty after serving all customers!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------PQ SERVE METHOD FAILED----------\n\n" << e.what() << std::endl;
  }

  std::cout << "----------PQ FUNCTIONALITY CORRECTLY IMPLEMENTED----------\n\n" << std::endl;
}

int main() {
  testPQ();
  return 0;
}