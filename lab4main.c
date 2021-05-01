#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{

  MY_STRING hMy_string = NULL;
  MY_STRING hMy_result = NULL;
  MY_STRING hMy_empty = NULL;

  hMy_empty = my_string_init_default();
  hMy_string = my_string_init_default();
  hMy_result = my_string_init_c_string("more ");
  
  //pushback tests
  printf("\nmy_string_push_back tests\n");
  printf("My string is %d in size and %d in capacity\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));
  my_string_push_back(hMy_string, 'c');
  printf("My string is %d in size and %d in capacity\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));
  my_string_push_back(hMy_string, 'd');
  printf("My string is %d in size and %d in capacity\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));
  my_string_push_back(hMy_string, 's');
  printf("My string is %d in size and %d in capacity\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));
  
  //my_string_at tests
  printf("\nmy_string_at tests\n");
  printf("My string's character at index 0 is '%c'.\n", *my_string_at(hMy_string, 0));
  printf("My string's character at index 1 is '%c'.\n", *my_string_at(hMy_string, 1));
  printf("My string's character at index 2 is '%c'.\n", *my_string_at(hMy_string, 2));

  //popback test
  printf("\nmy_string_pop_back tests\n");
  my_string_pop_back(hMy_string);
  printf("My string's character at index 2 is '%c'.\n", *my_string_at(hMy_string, 2));
  printf("My string is %d in size and %d in capacity\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));

  
  //my_string_c_str test
  printf("\nmy_string_c_str tests\n");
  
  char* test = my_string_c_str(hMy_string);
  
  for (int i = 0; i < my_string_get_size(hMy_string); i++)
    {
      printf("%c", test[i]);
    }  
  printf("\n");
  printf("My string is %d in size and %d in capacity\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));

  //my_string_concat tests
  printf("\nmy_string_concat tests\n");
  printf("My_result is %d in size and %d in capacity\n", my_string_get_size(hMy_result), my_string_get_capacity(hMy_result));
  printf("My_string is %d in size and %d in capacity\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));
  my_string_concat(hMy_result, hMy_string);  
  printf("My_result is %d in size and %d in capacity\n", my_string_get_size(hMy_result), my_string_get_capacity(hMy_result));
  my_string_insertion(hMy_result, stdout);
  printf("\n");
  
  //my_empty tests
  printf("\nmy_empty tests\n");
  if (my_string_empty(hMy_empty))
      printf("hMy_empty is empty\n");

  if (my_string_empty(hMy_result))
      printf("hMy_empty is empty\n");
    
  my_string_destroy(&hMy_string);
  my_string_destroy(&hMy_result);
  my_string_destroy(&hMy_empty);
  return 0;
}
