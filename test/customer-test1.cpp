#include <iostream>
#include "customer.hpp"

void testCustomer() {
  // create a customer with specific times
  Customer customer1(1.0, 2.0, 3.0);
  
  // create another customer
  Customer customer2(4.0, 5.0, 6.0);

  // create another customer who is first in line
  Customer customer3(1.5, 7.0, 10.0);


  
  // check if the customer node is created and correctly assigned
  try {
    if (customer1.getNextCustomer() != nullptr) { // tests if customer 1 next customer is correctly assigned to null
      throw std::runtime_error("Customer's next customer is not null!\n");
    } 

    if (customer1.getArrivalTime() != 1.0) {      // tests if customer 1 arrival time is correct
      throw std::runtime_error("Customer 1's arrival time is incorrect!");
    }

    if (customer2.getArrivalTime() != 4.0) {      // tests if customer 2 arrival time is correct
      throw std::runtime_error("Customer 2's arrival time is incorrect!");
    }

    if (customer1.getStartOfTime() != 2.0) {      // tests if customer 1 start of time is correct
      throw std::runtime_error("Customer 1's start of time is incorrect!");
    }

    if (customer2.getStartOfTime() != 5.0) {      // tests if customer 2 start of time is correct
      throw std::runtime_error("Customer 2's start of time is incorrect!");
    }

    if (customer1.getDepartureTime() != 3.0) {    // tests if customer 1 departure time is correct
      throw std::runtime_error("Customer 1's departure time is incorrect!");
    }

    if (customer2.getDepartureTime() != 6.0) {    // tests if customer 2 departure time is correct
      throw std::runtime_error("Customer 2's departure time is incorrect!");
    }
    
    std::cout << "----------CUSTOMER HAS BEEN CREATED CORRECTLY----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
      std::cout << "----------CUSTOMER HAS BEEN CREATED CORRECTLY----------\n\n" << e.what() << std::endl;
  }
}

int main() {
  testCustomer();
  return 0;
}