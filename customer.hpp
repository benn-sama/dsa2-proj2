#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

class Customer {
  private:
    float arrivalTime   = 0.00;
    float startOfTime   = 0.00;
    float departureTime = 0.00;
  public:
    Customer* nextCustomer; // the customer after
    Customer(float arrivalTime, float startOfTime, float departureTime); // default constructor
    Customer* getNextCustomer();                  // returns next customer
    float getArrivalTime();                      // returns arrival time
    float getStartOfTime();                       // returns start of time
    float getDepartureTime();                     // return departure time
    ~Customer();                                  // destructor method
};


#endif