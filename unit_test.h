#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
//Prewritten

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status test1_alee_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test2_alee_init_c_string_returns_nonNULL(char* buffer, int length);
Status test3_alee_get_c_string_size(char* buffer, int length);
Status test4_alee_get_c_string_capacity(char* buffer, int length);

Status test5_alee_string_compare_left_larger(char* buffer, int length);
Status test6_alee_string_compare_left_smaller(char* buffer, int length);

Status test7_alee_string_extraction_returns_nonNULL(char* buffer, int length);
Status test8_alee_string_insertion(char* buffer, int length);

Status test9_alee_pushback_size_accuracy(char* buffer, int length);
Status test10_alee_pushback_capacity_same(char* buffer, int length);
Status test11_alee_pushback_capacity_cahnges(char* buffer, int length);

Status test12_alee_popback_if_empty(char* buffer, int length);
Status test13_alee_popback_if_notempty(char* buffer, int length);

Status test14_alee_is_empty(char* buffer, int length);
Status test15_alee_is_not_empty(char* buffer, int length);

Status test16_alee_concat_two_strings(char* buffer, int length);
Status test17_alee_concat_two_strings_reversed(char* buffer, int length);
Status test18_alee_get_size_after_concat(char* buffer, int length);
Status test19_alee_get_capacity_after_concat(char* buffer, int length);
Status test20_alee_get_size_after_popback(char*buffer, int length);
Status test21_alee_get_capacity_after_popback(char*buffer, int length);
Status test22_alee_my_string_at_accuracy(char* buffer, int length);
Status test23_alee_my_string_c_str_after_concat(char* buffer, int length);


#endif
