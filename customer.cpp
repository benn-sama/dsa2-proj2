#include "customer.hpp"

Customer::Customer(float arrivalTime, float startOfTime, float departureTime) {
    this->arrivalTime = arrivalTime;
    this->startOfTime = startOfTime;
    this->departureTime = departureTime;
    this->nextCustomer = nullptr; // Initialize nextCustomer to nullptr
}

float Customer::getArrivalTime() {
    return this->arrivalTime;
}

float Customer::getStartOfTime() {
    return this->startOfTime;
}

float Customer::getDepartureTime() {
    return this->departureTime;
}

Customer* Customer::getNextCustomer() {
    return this->nextCustomer;
}