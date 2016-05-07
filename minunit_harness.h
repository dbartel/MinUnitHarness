#ifndef MINUNIT_HARNESS_H
#define MINUNIT_HARNESS_H
#include <stdlib.h>

// The original munit code, borrowed from http://www.jera.com/techinfo/jtns/jtn002.html
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++;	\
                                if (message) return message; } while (0)

/**
 * A test harness is a linked list containing the following items:
 * 1. A function pointer pointing to a function which runs all the tests
 * 2. A string containing the name of the harness
 * The run_tests function should return a list of strings containing the results of a minunit test
 */
struct TEST_HARNESS {
  char** (*run_tests)();
  struct TEST_HARNESS* next_harness;
  char* name;

};

typedef struct TEST_HARNESS MU_HARNESS;


extern int tests_run;
MU_HARNESS* ALL_TESTS;

/**
 * TODO Rename this function
 * Runs the test harness
 * @return 1 if some tests fail, 0 if tests pass
*/
int run_harness();



#endif
