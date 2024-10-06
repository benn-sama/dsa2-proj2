/**
 * @file customer.hpp
 * @brief Defines the Customer class for creating customer data to put in a queue system.
 *
 * This header file contains the definition of the Customer class, which is used to 
 * represent a customer in a queue system. The class includes attributes for arrival 
 * time, start of service time, and departure time, as well as methods to access these 
 * attributes and manage the linked list of customers.
 *
 * Attributes:
 * - float arrivalTime: The time at which the customer arrives.
 * - float startOfTime: The time at which the customer starts being served.
 * - float departureTime: The time at which the customer departs.
 * - Customer* nextCustomer: Pointer to the next customer in the queue.
 */
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP


class Customer {
  private:
    float arrivalTime   = 0.00;
    float startOfTime   = 0.00;
    float departureTime = 0.00;
  public:
    Customer* nextCustomer; // the customer after
    Customer(float arrivalTime, float startOfTime, float departureTime); // default constructor
    Customer* getNextCustomer();                  // returns next customer
    float getArrivalTime();                      // returns arrival time
    float getStartOfTime();                       // returns start of time
    float getDepartureTime();                     // return departure time
};


#endif