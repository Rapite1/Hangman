#include <stdio.h>
#include "my_string.h"

int main (int argc, char* argv[])
{
  int SIZE = 100;
  MY_STRING arr[SIZE];

  arr[0] = my_string_init_c_string("COPY ME!");

  for (int i = 1; i < SIZE; i++)
    {
      arr[i] = NULL;
    }

  for (int i = 1; i < SIZE; i++)
    {
      my_string_assignment(&arr[i], arr[0]);
    }

  for(int i = 0; i < SIZE; i++)
    {
      printf("%d: ",i);
      my_string_insertion(arr[i],stdout);
      printf("\n");
      my_string_destroy(&arr[i]);
    }
  
  return 0;
}
