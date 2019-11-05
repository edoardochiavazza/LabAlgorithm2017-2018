#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "modules/edit_distance/edit_distance.h"
#include "modules/edit_distance_dyn/edit_distance_dyn.h"

char *string1, *string2;

/**
 * Initialize String 1 and 2
 *
 */
void setUp() {
  string1 = "cavallo";
  string2 = "vassallo";
} //setUp

/**
 * Do Edit_Distance test
 *
 */
void test_edit_distance(){
  TEST_ASSERT_EQUAL(3, edit_distance(string1, string2));
} //test_edit_distance

/**
 * Do Edit_Distance_Dyn test
 *
 */
void test_edit_distance_dyn(){
  TEST_ASSERT_EQUAL(3, edit_distance_dyn(string1, string2));
} //test_edit_distance_dyn

/**
 * Execute test program
 *
 * @param argc
 * @param argv
 */
int main(int argc, char const *argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_edit_distance);
  RUN_TEST(test_edit_distance_dyn);
  return UNITY_END();
} //main
