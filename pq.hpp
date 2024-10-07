/**
 * @file pq.hpp
 * @brief Priority Queue (PQ) class definition.
 * 
 * This file contains the definition of the PQ class, which implements a 
 * priority queue using a min-heap. The priority queue is designed to manage 
 * Customer objects, providing efficient insertion and removal operations.
 * 
 * The min-heap is implemented using a dynamic array (std::vector).
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
    std::vector<Customer*> minHeap; // min-heap implemented using a dynamic array
    int size;                       // keeps track of the size of the heap
  public:
    PQ();                           // default constructor
    void buildHeap();               // builds a min heap
    void insert(Customer* customer);// inserts a new node from pq
    Customer* serve();              // removes the root node
    void percolateDown(int index);  // maintains the min heap condition
    int getSize();                  // returns the size of the heap
    void emptyHeap();               // empties the heap
    bool isEmpty();                 // checks if the heap is empty
};

#endif