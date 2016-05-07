#include "minunit_harness.h"


char* test_pass() {
  mu_assert("One is one", 1 == 1);
}

char* test_fail() {
  mu_assert("One is not one", 1 != 1);
}

// Add tests to test harness
// Could also function as an ad-hoc "before all" method to set up data
void add_example_tests() {
  mu_add_test("Passing Test", test_pass);
  mu_add_test("Failing Test", test_fail);
}
