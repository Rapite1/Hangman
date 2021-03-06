#include <stdio.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
  Status (*tests[])(char*, int) =
    {
      test_init_default_returns_nonNULL,
      test_get_size_on_init_default_returns_0,

      test1_alee_get_capacity_on_init_default_returns_7,
      
      test2_alee_init_c_string_returns_nonNULL,
      test3_alee_get_c_string_size,
      test4_alee_get_c_string_capacity,
      
      test5_alee_string_compare_left_larger,
      test6_alee_string_compare_left_smaller,
      
      test7_alee_string_extraction_returns_nonNULL,
      test8_alee_string_insertion,
      
      test9_alee_pushback_size_accuracy,
      test10_alee_pushback_capacity_same,
      test11_alee_pushback_capacity_cahnges,
      
      test12_alee_popback_if_empty,
      test13_alee_popback_if_notempty,
      
      test14_alee_is_empty,
      test15_alee_is_not_empty,
      
      test16_alee_concat_two_strings,
      test17_alee_concat_two_strings_reversed,
      test18_alee_get_size_after_concat,
      test19_alee_get_capacity_after_concat,
      test20_alee_get_size_after_popback,
      test21_alee_get_capacity_after_popback,
      test22_alee_my_string_at_accuracy,
      test23_alee_my_string_c_str_after_concat

    };
  int number_of_functions = sizeof(tests) / sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;
  for(i=0; i<number_of_functions; i++)
    {
      if(tests[i](buffer, 500) == FAILURE)
	{
	  printf("FAILED: Test %d failed miserably\n", i);
	  printf("\t%s\n", buffer);
	  failure_count++;
	}
      else
	{
	  // printf("PASS: Test %d passed\n", i);
	  // printf("\t%s\n", buffer);
	  success_count++;
	}
    }
  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count,
	 number_of_functions, failure_count, number_of_functions);
  return 0;
}
