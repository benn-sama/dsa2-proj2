#include "analytical-model.hpp"

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

void analytical_model_test1() {
  AnalyticalModel model(2.0, 3.0, 2);
  double summation = std::round(model.computeSummation(2, 2.0, 3.0) * 10) / 10;


  try { // checks if factorials is correctly calculated
    if (model.factorial(0) != 1) {
      throw std::runtime_error("Expected: 1\nActual: " + std::to_string(model.factorial(0)) + "\n");
    }

    if (model.factorial(1) != 1) {
      throw std::runtime_error("Expected: 1\nActual: " + std::to_string(model.factorial(1)) + "\n");
    }

    if (model.factorial(5) != 120) {
      throw std::runtime_error("Expected: 1\nActual: " + std::to_string(model.factorial(1)) + "\n");
    }
    
    std::cout << "----------FACTORIALS PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------FACTORIALS FAILED----------\n\n" << e.what() << std::endl;
  }

  try { // checks if summation is correctly calculated
    if (summation != 1.7) {
      throw std::runtime_error("Expected: 1.67\nActual: " + std::to_string(summation) + "\n");
    }

    std::cout << "----------SUMMATION PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------SUMMATION FAILED----------\n\n" << e.what() << std::endl;
  }

  try { // checks if P0 correctly outputs 0.5
    if (model.computeP0() != 0.5) {
      throw std::runtime_error("Expected: 0.5\nActual: " + std::to_string(model.computeP0()) + "\n");
    }
    std::cout << "----------P0 PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------P0 FAILED----------\n\n" << e.what() << std::endl;
  }

  try { // checks if P0 correctly outputs 0.5
    if (model.computeLq() != 0.75) {
      throw std::runtime_error("Expected: 0.75\nActual: " + std::to_string(model.computeLq()) + "\n");
    }
    std::cout << "----------P0 PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------P0 FAILED----------\n\n" << e.what() << std::endl;
  }
}

int main() {
  analytical_model_test1();

}