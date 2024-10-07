#include <iostream>
#include "customer.hpp"

void testCustomer() {
    // create a customer with specific times
    Customer customer1(1.0, 2.0, 3.0);
  
    // create another customer
    Customer customer2(4.0, 5.0, 6.0);

    // create another customer who is first in line
    Customer customer3(1.5, 7.0, 10.0);

    // Set the next customer for customer1
    customer1.nextCustomer = &customer2;

    // check if the customer node is created and correctly assigned
    try {
        if (customer1.nextCustomer != &customer2) { // tests if customer 1 next customer is correctly assigned
            throw std::runtime_error("Customer's next customer is not correctly assigned!\n");
        } 

        if (customer1.arrivalTime != 1.0) {      // tests if customer 1 arrival time is correct
            throw std::runtime_error("Customer 1's arrival time is incorrect!");
        }

        if (customer2.arrivalTime != 4.0) {      // tests if customer 2 arrival time is correct
            throw std::runtime_error("Customer 2's arrival time is incorrect!");
        }

        if (customer1.startOfTime != 2.0) {      // tests if customer 1 start of time is correct
            throw std::runtime_error("Customer 1's start of time is incorrect!");
        }

        if (customer2.startOfTime != 5.0) {      // tests if customer 2 start of time is correct
            throw std::runtime_error("Customer 2's start of time is incorrect!");
        }

        if (customer1.departureTime != 3.0) {    // tests if customer 1 departure time is correct
            throw std::runtime_error("Customer 1's departure time is incorrect!");
        }

        if (customer2.departureTime != 6.0) {    // tests if customer 2 departure time is correct
            throw std::runtime_error("Customer 2's departure time is incorrect!");
        }
    
        std::cout << "----------CUSTOMER HAS BEEN CREATED CORRECTLY----------\n\n" << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    testCustomer();
    return 0;
}