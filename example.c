#include "example.h"
#include "minunit_harness.h"
#include <stdio.h>

int main() {
  add_example_tests();
  MU_RUN_HARNESS();
}
