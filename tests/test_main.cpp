#include <stdio.h>
#include "planck_unit.h"
#include "../my_functions.h"

int add_stuff1( int a, int b) {
  return a + b;
}

void test_addstuff1_2( planck_unit_test_t *tc) {
  int a	= 10;
  int b	= 3;

  PLANCK_UNIT_ASSERT_TRUE(tc, a + b == add_stuff1(a, b));
}

void check_strings( planck_unit_test_t *tc) {
  char *a	= "apple";
  char *b	= "apple";

  PLANCK_UNIT_ASSERT_STR_ARE_EQUAL(tc, a, b);
}

void check_nothing(planck_unit_test_t *tc){
  int test = getUltraSonicDistance(50);
  PLANCK_UNIT_ASSERT_TRUE(tc, 1==1);
}


int main(void) {
  planck_unit_suite_t *suite;

  suite = planck_unit_new_suite();

  //TESTS
  PLANCK_UNIT_ADD_TO_SUITE(suite, test_addstuff1_2);
  PLANCK_UNIT_ADD_TO_SUITE(suite, check_strings);
  PLANCK_UNIT_ADD_TO_SUITE(suite, check_nothing);

  //EXECUTE
  planck_unit_run_suite(suite);
  planck_unit_destroy_suite(suite);
  return 0;
}

