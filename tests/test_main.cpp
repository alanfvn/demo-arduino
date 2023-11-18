#include <stdio.h>
#include "planck_unit.h"
#include "../my_functions.h"

void check_ultrasonic_calc(planck_unit_test_t *tc){
  // 500 micro segundos aproximadamente equivalen a 8 cm.
  const long distance8cm = 500;
  int calcDistance = getUltraSonicDistance(distance8cm);
  PLANCK_UNIT_ASSERT_TRUE(tc, calcDistance==8);
}

void check_ultrasonic_string_overflow(planck_unit_test_t *tc){
  //esta funcion debe retornar menos de 30 caracteres
  const int largeInt = 2147483647;
  char *data = getUltraSonicString(largeInt);
  int len = strlen(data);
  free(data);
  PLANCK_UNIT_ASSERT_TRUE(tc, len<=30);
}

void check_wifi_info_string_overflow(planck_unit_test_t *tc){
  //esta funcion debe retornar menos de 84 caracteres
  char *strTest = "************";
  char *data =  getNetworkInfo(strTest, strTest);
  int len = strlen(data);
  free(data);
  PLANCK_UNIT_ASSERT_TRUE(tc, len<=84);
}

int main(void) {

  planck_unit_suite_t *suite;
  suite = planck_unit_new_suite();

  //Test Suite
  PLANCK_UNIT_ADD_TO_SUITE(suite, check_ultrasonic_calc);
  PLANCK_UNIT_ADD_TO_SUITE(suite, check_ultrasonic_string_overflow);
  PLANCK_UNIT_ADD_TO_SUITE(suite, check_wifi_info_string_overflow);

  //Exceute Suite
  planck_unit_run_suite(suite);
  planck_unit_destroy_suite(suite);
  return 0;
}
