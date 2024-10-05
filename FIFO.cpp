#include "FIFO.hpp"

FIFO::FIFO() {
  this->head = this->tail = nullptr; // assigns head and tail to nullptr
}

bool FIFO::isEmpty() { // checks if FIFO is empty
  if (head == nullptr) {
    return true;
  }
  return false;
}

void FIFO::insert(float arrivalTime, float startOfTime, float departureTime) { // inserts new node at the end
  // creates a new customer
  Customer* newCustomer = new Customer(arrivalTime, startOfTime, departureTime);

  // checks if FIFO is empty, if so, assigns first customer to the head and tail
  if (this->isEmpty()) {
    this->head = this->tail = nullptr;
    return;
  }

  // assigns the new node's next customer to the tail, effectively inserting a new customer
  this->tail->nextCustomer = newCustomer;
  this->tail = newCustomer;
}

void FIFO::serve() {  // dequeues head of the node
  // checks if queue is empty
  if (this->head == nullptr) {
    return;
  }

  // assigns the head to a temp  node, and assigns the head to null;
  Customer* tempCustomer = head;
  this->head = this->head->nextCustomer;

  // checks if the there is a node in the FIFO
  if (this->head == nullptr) {
    this->tail = nullptr;
  }

  delete tempCustomer;
}