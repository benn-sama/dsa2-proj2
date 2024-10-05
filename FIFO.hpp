#ifndef FIFO_HPP
#define FIFO_HPP

#include "customer.hpp"


class FIFO {
  private:
    Customer *head;
    Customer *tail;
  public:
    FIFO();         // default constructor
    bool isEmpty(); // checks if FIFO is empty
    void insert(float arrivalTime, float startOfTime, float departureTime);  // inserts new customer in the FIFO
    void serve();   // removes customer from the FIFO

};

#endif