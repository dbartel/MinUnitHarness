#include "minunit_harness.h"
#include <stdio.h>

int run_harness() {
  if (ALL_TESTS == NULL) {
    printf("No tests specified!\n");
    return 1;
  }
  MU_HARNESS* harness = ALL_TESTS;
  
  int tests_failed = 0;
  while (ALL_TESTS != NULL) {
    // Run the tests
    char** result = harness->run_tests();
    int i = 0;
    int len = sizeof(result) / sizeof(result[0]);
    for (; i < len; i++) {
      if (result[i]) {
	printf("TEST FAILED: %s\n\n", result[i]);
	tests_failed++;
      } 
    }
    
    // Get the next harness
    harness = harness->next_harness;
  }
  
  // Print report
  printf("Total Tests: %d\n  Passed: %d\n  Failed: %d",
	 tests_run,
	 tests_run - tests_run,
	 tests_failed);
  
  return tests_failed == 0;
}

