/**
 * @file pq.hpp
 * @brief Priority Queue (PQ) class definition.
 * 
 * This file contains the definition of the PQ class, which implements a 
 * priority queue using a min-heap. The priority queue is designed to manage 
 * Customer objects, providing efficient insertion and removal operations.
 * 
 * The min-heap is implemented using a fixed-size array with a maximum capacity 
 * of 200 elements.
 * 
 * @class PQ
 * @brief A priority queue implemented using a min-heap.
 */
#ifndef PQ_HPP
#define PQ_HPP

#include "customer.hpp"
#include <vector>


class PQ {
  private:
    Customer* minHeap[200];         // max size of heap is 200
    int size = 0;                   // keeps track of the size of the heap
  public:
  PQ();                             // default constructor
  void buildHeap();                 // builds a min heap
  void insert(Customer* customer);  // inserts a new node from pq
  void serve();                     // removes the root node
  void percolateDown(int index);    // maintains the min heap condition
};

#endif