#include <stdio.h>
#include <alpha_test.h>

int main() {
  TEST_SUITE("Application test suite") {
    ASSERT(1 == 1);
  }

  print_report();
  return 0;
}