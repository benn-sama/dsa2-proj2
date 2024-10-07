/**
 * @file FIFO.hpp
 * @brief Header file for the FIFO (First-In-First-Out) queue class.
 * 
 * This class implements a FIFO queue to manage Customer objects. It provides
 * methods to check if the queue is empty, insert new customers, and serve (remove)
 * customers from the queue.
 * 
 * @class FIFO
 * @brief A class to represent a FIFO queue for Customer objects.
 * 
 * The FIFO class maintains a queue of Customer objects, allowing for insertion
 * of new customers and serving (removal) of customers in a first-in-first-out order.
 * It also provides a method to check if the queue is empty.
 * 
 */
#ifndef FIFO_HPP
#define FIFO_HPP

#include "customer.hpp"


class FIFO {
  private:
    Customer *head; // the first customer in line
    Customer *tail; // last customer in line
  public:
    FIFO();         // default constructor
    bool isEmpty(); // checks if FIFO is empty
    void insert(Customer* customer);  // inserts new customer in the FIFO
    Customer* serve();   // removes customer from the FIFO
    ~FIFO();        // destructor method
};

#endif