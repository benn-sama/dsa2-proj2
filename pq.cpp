#include "pq.hpp"
#include <stdexcept>
#include <vector>

PQ::PQ() : size(0) {
  minHeap.push_back(nullptr); // Placeholder for 1-based indexing
}

void PQ::buildHeap() {  // builds a min heap
  for (int i = this->size / 2; i > 0; --i) {
    this->percolateDown(i);
  }
}

void PQ::insert(Customer* customer) { // inserts new customer
  ++this->size;

  if (this->size >= (int)minHeap.size()) {
    minHeap.push_back(customer);
  } else {
    minHeap[this->size] = customer;
  }

  int i = size;

  if (this->size == 200) {
      this->emptyHeap();
  }

  // if new customer arrival time is less than another customer, moves it up the heap
  while ((i > 1) && (customer->arrivalTime < minHeap[i / 2]->arrivalTime)) {
    minHeap[i] = minHeap[i / 2];
    i /= 2;
  }
  minHeap[i] = customer;
}

Customer* PQ::serve() {  // removes the root/first node/customer
  if (this->size == 0) {
    return nullptr;
  }

  // removes the first customer from the line
  Customer* minCustomer = minHeap[1];
  minHeap[1] = minHeap[size];
  --size;
  this->percolateDown(1);

  return minCustomer;
}

void PQ::percolateDown(int index) { // maintains min heap condition
  int child;
  Customer* temp = minHeap[index];

  // maintains min heap conditions by comparison
  while (index * 2 <= size) {
    child = index * 2;

    // compares current node's left and right, if true increment child 
    if ((child != size) && (minHeap[child + 1]->arrivalTime < minHeap[child]->arrivalTime)) {
      ++child;
    }

    // if the smaller child has a smaller arrival time than temp, move child up to the current node's index
    if (minHeap[child]->arrivalTime < temp->arrivalTime) {
      minHeap[index] = minHeap[child];
    } else {
      break;
    }
    index = child;
  }
  minHeap[index] = temp;
}

int PQ::getSize() {
  return this->size;
}

void PQ::emptyHeap() {
  while (this->size > 0) {
    Customer* temp = this->serve();
    if (temp != nullptr) {
      delete temp;
    }
  }
}

bool PQ::isEmpty() {
  return this->size == 0;
}