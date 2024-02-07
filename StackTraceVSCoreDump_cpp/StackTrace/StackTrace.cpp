#include <iostream>

void funcC() { throw std::runtime_error("Fehler in funcC"); }

void funcB() { funcC(); }

void funcA() { funcB(); }

int main() {
  try {
    funcA();
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
