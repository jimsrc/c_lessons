#include "traceback.hpp"
#include <iostream>
#include <stdio.h>

void foo(const int i) {
  if (i == 1) {
    fopen("/?", "r");
    throw traceback::RuntimeError("An error message");
  }
  foo(i + 1);
}

int main(int argc, char* argv[]) {
  try {
    foo(0);
  } catch (traceback::ErrorInfo &e) {
    std::cout << e.diagnostic() << std::endl;
  }
  return 0;
}

