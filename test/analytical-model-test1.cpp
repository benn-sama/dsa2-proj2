#include "analytical-model.hpp"

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

void analytical_model_test1() {
  AnalyticalModel model(2.0, 3.0, 2);
  double summation = std::round(model.computeSummation(2, 2.0, 3.0) * 1000) / 1000;


  try { // checks if factorials is correctly calculated
    if (!(model.factorial(0) != 1)) {
      throw std::runtime_error("Expected: 1\nActual: " + std::to_string(summation) + "\n");
    }

    if (!(model.factorial(1) != 1)) {
      throw std::runtime_error("Expected: 1\nActual: " + std::to_string(summation) + "\n");
    }
    
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------FAILED----------\n\n" << e.what() << std::endl;
  }

  try { // checks if summation is correctly calculated
    if (!(summation == 1.667)) {
      throw std::runtime_error("Expected: 1.67\nActual: " + std::to_string(summation) + "\n");
    }
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------FAILED----------\n\n" << e.what() << std::endl;
  }

  std::cout << model.computeP0() << std::endl << std::endl;
}

int main() {
  analytical_model_test1();

}