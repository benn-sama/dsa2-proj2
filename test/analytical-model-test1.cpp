#include "analytical-model.hpp"

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

  try { // checks if L correctly outputs 0.5
    if (model.computeL() != 0.75) {
      throw std::runtime_error("Expected: 0.75\nActual: " + std::to_string(model.computeL()) + "\n");
    }
    std::cout << "----------Lq PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------Lq FAILED----------\n\n" << e.what() << std::endl;
  }

  try { // checks if W correctly outputs 0.375
    if (model.computeW() != 0.375) {
      throw std::runtime_error("Expected: 0.375\nActual: " + std::to_string(model.computeW()) + "\n");
    }
    std::cout << "----------W PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------W FAILED----------\n\n" << e.what() << std::endl;
  }

  try { // checks if Lq correctly outputs 0.083
    if (model.computeLq() != 0.083) {
      throw std::runtime_error("Expected: 0.083\nActual: " + std::to_string(model.computeLq()) + "\n");
    }
    std::cout << "----------Lq PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------Lq FAILED----------\n\n" << e.what() << std::endl;
  }

  try { // checks if Wq correctly outputs 0.0415
    if (model.computeWq() != 0.0415) {
      throw std::runtime_error("Expected: 0.0417\nActual: " + std::to_string(model.computeWq()) + "\n");
    }
    std::cout << "----------Wq PASSED----------\n\n" << std::endl;
  }
  catch (const std::runtime_error& e) {
    std::cout << "----------Wq FAILED----------\n\n" << e.what() << std::endl;
  }

}

int main() {
  analytical_model_test1();
  
  return 0;

}