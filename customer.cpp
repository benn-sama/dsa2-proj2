#include "customer.hpp"

Customer::Customer(float arrivalTime, float startOfTime, float departureTime) {
    this->arrivalTime = arrivalTime;
    this->startOfTime = startOfTime;
    this->departureTime = departureTime;
    this->nextCustomer = nullptr; // Initialize nextCustomer to nullptr
}