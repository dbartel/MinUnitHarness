#ifndef MINUNIT_HARNESS_H
#define MINUNIT_HARNESS_H
#include <stdlib.h>

// munit assert, borrowed from http://www.jera.com/techinfo/jtns/jtn002.html
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)


struct TEST_LIST {
  char* (*test)();
  char* name;
  struct TEST_LIST* next;
};

typedef struct TEST_LIST MU_TEST;
MU_TEST* TEST_LIST;


/**
 * TODO Rename this function
 * Runs the test harness
 * @return 1 if some tests fail, 0 if tests pass
*/
int MU_RUN_HARNESS();


/**
 * Run a test
 * @return If test fails, the failure message, if test passes, NULL
*/
char* run_test(char* (*test)());


/**
  * Add a test
  * @param name The name of the test
  * @param test The test method
  * @param setup A setup method specific to that test
  * @param teardown A teardown method specific to that test
  */
void mu_add_test(char* name, char* (*test)(), int* (*setup)(), int* (*teardown)());



#endif
