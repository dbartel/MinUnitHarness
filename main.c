#include "minunit_harness.h"
#include <stdio.h>

int tests_run = 0;
extern MU_HARNESS* ALL_TESTS;

int main() {
  if (ALL_TESTS != NULL) {
    run_harness(ALL_TESTS);
  } else {
    printf("No tests were run!\n");
    return 1;
  }

}
