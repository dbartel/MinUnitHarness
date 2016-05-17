#include <stdio.h>
#include "minunit_harness.h"


char* test_pass() {
  mu_assert("One is one", 1 == 1);
}

char* test_fail() {
  mu_assert("One is not one", 1 != 1);
}

int* setup() {
  printf("Setup method\n");
  return NULL;
}

int* teardown() {
  printf("Teardown method\n");
  return NULL;
}


// Add tests to test harness
// Could also function as an ad-hoc "before all" method to set up data
void add_example_tests() {
  mu_add_test("Passing Test", test_pass, setup, teardown);
  mu_add_test("Failing Test", test_fail, NULL, NULL);
}

