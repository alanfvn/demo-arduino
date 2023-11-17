#include <stdio.h>
#include "planck_unit.h"

int add_stuff1( int a, int b) {
	return a + b;
}

int add_stuff2( int a, int b) { 
  return 2 + a + b; 
}

void test_addstuff1_2( planck_unit_test_t *tc) {
	int a	= 10;
	int b	= 3;

	PLANCK_UNIT_ASSERT_TRUE(tc, a + b == add_stuff2(a, b));
}

void test_stringequals_failure( planck_unit_test_t *tc) {
	char	*a	= "apple";
	char	*b	= "orange";

	PLANCK_UNIT_ASSERT_STR_ARE_EQUAL(tc, a, b);
}


int main( void) {
	planck_unit_suite_t *suite;

	suite = planck_unit_new_suite();
	planck_unit_init_suite(suite,  planck_unit_print_funcs_concise);

  //TESTS
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_addstuff1_2);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_stringequals_failure);

  //EXECUTE
	planck_unit_run_suite(suite);
	planck_unit_destroy_suite(suite);
	return 0;
}

