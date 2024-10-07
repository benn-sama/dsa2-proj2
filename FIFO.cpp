#include "FIFO.hpp"

FIFO::FIFO() { // assigns head and tail to nullptr
  this->head = nullptr;
  this->tail = nullptr;
}

bool FIFO::isEmpty() { // checks if FIFO is empty
  if (head == nullptr) {
    return true;
  }
  return false;
}

void FIFO::insert(Customer* newCustomer) { // inserts new node at the end

  // checks if FIFO is empty, if so, assigns first customer to the head and tail
  if (this->isEmpty()) {
    this->head = newCustomer;
    this->tail = newCustomer;
    return;
  }

  // assigns the new node's next customer to the tail, effectively inserting a new customer
  this->tail->nextCustomer = newCustomer;
  this->tail = newCustomer;
}

Customer* FIFO::serve() {  // dequeues head of the node
  // checks if queue is empty
  if (this->head == nullptr) {
    return nullptr;
  }

  // assigns the head to a temp  node, and assigns the head to null;
  Customer* tempCustomer = head;
  this->head = this->head->nextCustomer;

  // checks if the there is a node in the FIFO
  if (this->head == nullptr) {
    this->tail = nullptr;
  }

  return tempCustomer;
}

FIFO::~FIFO() { // deallocates memory
  while (this->head != nullptr) {
    this->serve();
  }
}