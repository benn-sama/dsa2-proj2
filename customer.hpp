#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

class Customer {
  private:
    float arrivalTime   = 0.00;
    float startOfTime   = 0.00;
    float departureTime = 0.00;
    Customer* nextCustomer; // the customer after
  public:
    Customer(float arrivalTime, float startOfTime, float departureTime); // default constructor
    void addNextCustomer(Customer *nextCustomer); // assigns the customer after the current one
    Customer* getNextCustomer();
    ~Customer();                                  // destructor method
};


#endif