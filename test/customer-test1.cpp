#include <iostream>
#include "customer.hpp"

void testCustomer() {
  // create a customer with specific times
  Customer customer1(1.0, 2.0, 3.0);
  
  // create another customer
  Customer customer2(4.0, 5.0, 6.0);

  // create another customer who is first in line
  Customer customer3(1.5, 7.0, 10.0);
  
  // cink the second customer to the first
  customer1.addNextCustomer(&customer2);
  
  // check if the next customer is correctly assigned
  try {
    if (customer1.getNextCustomer() != &customer2) {
      throw std::runtime_error("Next Customer was not assigned!" "\n");
    } 
    std::cout << "----------NEXT CUSTOMER ASSIGNED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
      std::cout << "----------NEXT CUSTOMER HAS NOT BEEN ASSIGNED----------\n\n" << e.what() << std::endl;
  }
}

int main() {
  testCustomer();
  return 0;
}