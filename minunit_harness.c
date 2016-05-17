#include "minunit_harness.h"
#include <stdio.h>

int MU_RUN_HARNESS() {
  if (TEST_LIST == NULL) {
    printf("No tests have been added!\n");
    return 0;
  }
  
  int total_tests = 0;
  int tests_passed = 0;
  int tests_failed = 0;

  
  MU_TEST* harness = TEST_LIST;
  while (harness != NULL) {


    // Run setup method if necessary
    if (harness->setup != NULL) {
      harness->setup();
    }

    // Run the test
    printf("Test: %s -> ", harness->name);
    char* result = harness->test();
    if (result == NULL) {
      printf("passed\n");
      tests_passed++;
    } else {
      printf("failed: %s\n", result);
      tests_failed++;
    }

    // Run teardown method if necessary
    if (harness->teardown != NULL) {
      harness->teardown();
    }
    
    total_tests++;
    harness = harness->next;
  }

  printf("\n%d tests run\nFailed: %d\nPassed: %d\n\n",
	 total_tests,
	 tests_failed,
	 tests_passed);

  return tests_failed == 0;
}

void mu_add_test(char* name, char* (*test)(), int* (*setup)(), int* (*teardown)()) {
  if (TEST_LIST == NULL) {
    TEST_LIST = malloc(sizeof(MU_TEST));
    TEST_LIST->test = test;
    TEST_LIST->name = name;
    TEST_LIST->next = NULL;

    if (setup != NULL) TEST_LIST->setup = setup;
    if (teardown != NULL) TEST_LIST->teardown = teardown;
    
  } else {
    MU_TEST* tmp = TEST_LIST;
    while (tmp->next) tmp = tmp->next;
    
    tmp->next = malloc(sizeof(MU_TEST));
    tmp->next->test = test;
    tmp->next->name = name;
    tmp->next->next = NULL;
    tmp->next->setup = setup;
    tmp->next->teardown = teardown;    
  }
}



