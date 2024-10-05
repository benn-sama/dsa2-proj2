#include "customer.hpp"

Customer::Customer(float arrivalTime, float startOfTime, float departureTime) {
    this->arrivalTime = arrivalTime;
    this->startOfTime = startOfTime;
    this->departureTime = departureTime;
    this->nextCustomer = nullptr; // Initialize nextCustomer to nullptr
}

void Customer::addNextCustomer(Customer* nextCustomer) {
    this->nextCustomer = nextCustomer;
}

Customer* Customer::getNextCustomer() {
    return this->nextCustomer;
}

Customer::~Customer() {
  delete this->nextCustomer;
}