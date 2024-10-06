#include "FIFO.hpp"
#include "customer.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

void testFIFO() {
  FIFO fifo;
  Customer* customer1 = new Customer(1.0, 2.0, 3.0);
  Customer* customer2 = new Customer(4.0, 5.0, 6.0);

  try { // tests if fifo is initially empty
    if (!fifo.isEmpty()) {
      throw std::runtime_error("FIFO has not been initialized and/or not null!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------FIFO INITIALIZE FAILED----------\n\n" << e.what() << std::endl;
  }

  fifo.insert(customer1);
  try  { // test if insert method work
    if (fifo.isEmpty()) {
      throw std::runtime_error("FIFO queue should not be empty after using insert method!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------FIFO INSERT METHOD FAILED----------\n\n" << e.what() << std::endl;
  }

  // insert another customer into the FIFO queue
  fifo.insert(customer2);

  // serves(remove) another customer into the FIFO queue
  fifo.serve();
  try { // tests insert another customer into the FIFO queue and queue
    if (fifo.isEmpty()) {
      throw std::runtime_error("FIFO queue should only have one node!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------FIFO IS NULL FAILED----------\n\n" << e.what() << std::endl;
  }

  // serves(remove) another customer into the FIFO
  fifo.serve();
  try { // test serve again to see if the fifo queue is empty
    if (!fifo.isEmpty()) {
      throw std::runtime_error("FIFO should be empty after two queues!");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------FIFO IS NOT NULL FAILED----------\n\n" << e.what() << std::endl;
  }

  std::cout << "----------FIFO FUNCTIONALITY CORRECTLY IMPLEMENTED----------\n\n" << std::endl;
}

int main() {
  testFIFO();
  return 0;
}