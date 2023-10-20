#include <iostream>
#include <cmath>
#include <complex.h>

int main() {
  float a;
  float b;
  float c;
  std::cout << "Solving a*x*x + b*x + c = 0:" << std::endl;
  std::cout << "Enter a: "; // Type a number and press enter
  std::cin >> a; // Get user input from the keyboard
  std::cout << "Enter b: ";
  std::cin >> b;
  std::cout << "Enter c: ";
  std::cin >> c;
  float disc;
  disc = (b*b) - (4*a*c);
  if (disc > 0){
    float x1 = (-b + sqrt(disc)) / (2*a);
    float x2 = (-b - sqrt(disc)) / (2*a);
    std::cout << "Solutions are " << x1 << " and " << x2 << "." << std::endl;
  }
  else {
    if (disc == 0){
      float x = (-b) / (2*a);
      std::cout << "Solution is " << x << " (multiplicity 2)." << std::endl;
    }
    else{
      std::cout << "There are no real solutions.";
      float re = (-b) / (2*a);
      float im = (sqrt( - disc)) / (2*a);
      std::cout << "Complex solutions are " << re << " + " << im << "i" << " and " << re << " - " << im << "i." << std::endl;
    }
  }
  return 0;
}