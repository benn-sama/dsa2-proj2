#include "pq.hpp"
PQ::PQ() {}

void PQ::buildHeap() {  // builds a min heap
  for (int i = this->size / 2 - 1; i > 0; --i) {
    this->percolateDown(i);
  }
}

void PQ::insert(Customer* customer) { // inserts new customer
  ++this->size;
  int i = size;

  // if new customer arrival time is less than another customer, moves it up the heap
  while((i > 1) && (customer->getArrivalTime() < minHeap[i / 2]->getArrivalTime())) {
    minHeap[i] = minHeap[i / 2];
    i /= 2;
  }
  minHeap[i] = customer;
}

void PQ::serve() {  // removes the root/first node/customer
  if (this->size == 0) {
    return;
  }

  // removes the first customer from the line
  Customer* minCustomer = minHeap[0];
  minHeap[0] = minHeap[size - 1];
  --size;
  this->percolateDown(0);

  delete minCustomer;
}

void PQ::percolateDown(int index) { // maintains min heap condition
  int child;
  Customer* temp = minHeap[index];

  // maintains min heap conditions by comparison
  while (index * 2 <= size) {
    child = index * 2;
    
    // compares current node's left and right, if true increment child 
    if ((child != size) && (minHeap[child + 1] < minHeap[child])) {
      ++child;
    }

    // if the smaller child has a smaller arrival time than temp, move child up to the current node's index
    if (minHeap[child]->getArrivalTime() < temp->getArrivalTime()) {
      minHeap[index] = minHeap[child];
    }
    else {
      break;
    }
    index = child;
  }
  minHeap[index] = temp;
}

int PQ::getSize() {
  return this->size;
}