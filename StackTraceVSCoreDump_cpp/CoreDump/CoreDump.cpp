#include <iostream>

void funcC() {
  int *ptr = nullptr;
  *ptr = 42;
}

void funcB() { funcC(); }

void funcA() { funcB(); }

int main() {
  funcA();

  return 0;
}
