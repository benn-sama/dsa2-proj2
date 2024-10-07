/**
 * @file customer.hpp
 * @brief Defines the Customer class for creating customer data to put in a queue system.
 *
 * This header file contains the definition of the Customer class, which is used to 
 * represent a customer in a queue system. The class includes attributes for arrival 
 * time, start of service time, and departure time, as well as methods to access these 
 * attributes and manage the linked list of customers.
 *
 */
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP


class Customer {
  private:
  public:
    Customer* nextCustomer; // the customer after
    Customer(float arrivalTime, float startOfTime, float departureTime); // default constructor
    Customer* getNextCustomer();                  // returns next customer
    float arrivalTime   = 0.00;
    float startOfTime   = 0.00;
    float departureTime = 0.00;
};


#endif