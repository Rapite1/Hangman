#include <stdio.h>
#include <ctype.h>
#include "my_string.h"
#include "generic_vector.h"

int main(int argc, char* argv[])
{
  MY_STRING hWord_the = my_string_init_c_string("the");
  MY_STRING hWord_truck = my_string_init_c_string("truck");
  MY_STRING hWord_happy = my_string_init_c_string("happy");
  MY_STRING hWord_awesome = my_string_init_c_string("awesome");

  //initialize old keys
  MY_STRING hKey_the = my_string_init_c_string("---");
  MY_STRING hKey_truck = my_string_init_c_string("-----");
  MY_STRING hKey_happy = my_string_init_c_string("--ppy");
  MY_STRING hKey_awesome = my_string_init_c_string("--e---e");
  
  MY_STRING hNew_key1 = my_string_init_c_string("---");
  MY_STRING hNew_key2 = my_string_init_c_string("-----");
  MY_STRING hNew_key3 = my_string_init_c_string("-----");
  MY_STRING hNew_key4 = my_string_init_c_string("-------");

  get_word_key_value(hKey_the, hNew_key1, hWord_the, 't');

  printf("NEW KEY IS: %s\n", my_string_c_str(hNew_key1));

  get_word_key_value(hKey_truck, hNew_key2, hWord_truck, 'r');

  printf("NEW KEY IS: %s\n", my_string_c_str(hNew_key2));

  get_word_key_value(hKey_happy, hNew_key3, hWord_happy, 'h');
  printf("NEW KEY IS: %s\n", my_string_c_str(hNew_key3));

  get_word_key_value(hKey_awesome, hNew_key4, hWord_awesome, 'z');
  printf("NEW KEY IS: %s\n", my_string_c_str(hNew_key4));

  my_string_destroy(&hWord_the);
  my_string_destroy(&hWord_truck);
  my_string_destroy(&hWord_happy);
  my_string_destroy(&hWord_awesome);
  my_string_destroy(&hKey_the);
  my_string_destroy(&hKey_truck);
  my_string_destroy(&hKey_happy);
  my_string_destroy(&hKey_awesome);
  my_string_destroy(&hNew_key1);
  my_string_destroy(&hNew_key2);
  my_string_destroy(&hNew_key3);
  my_string_destroy(&hNew_key4);

  return 0;
}
