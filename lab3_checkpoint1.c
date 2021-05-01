#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{

  MY_STRING hMy_string = NULL;
  FILE* fp;

  hMy_string = my_string_init_default();
  fp = fopen("simple.txt","r");

  while(my_string_extraction(hMy_string,fp))
    {
      my_string_insertion(hMy_string,stdout);
      printf("\n");
      if(fgetc(fp)==' ')
	{
	  printf("Found a space after the string\n");
	}
    }
  my_string_destroy(&hMy_string);
  fclose(fp);
  
  return 0;
  /*
  MY_STRING hApple = NULL;
  MY_STRING hApp = NULL;
  MY_STRING hSale = NULL;
  MY_STRING hGone = NULL;
    
  hApp = my_string_init_c_string("app");
  hApple = my_string_init_c_string("apple");
  hSale = my_string_init_c_string("sale");
  hGone = my_string_init_c_string("gone");

  printf("size of hApp ('app') is: %d\n", my_string_get_size(hApp));
  printf("capacity of hApp ('app') is: %d\n", my_string_get_capacity(hApp));
  
  
  //test for app and apple
  printf("comparing 'app' and 'apple' returns %d\n", my_string_compare(hApp, hApple)); 
  //test for gone and sale
  printf("comparing 'gone' and 'sale' returns %d\n", my_string_compare(hGone, hSale));
  //again in reverse order
  printf("comparing 'sale' and 'gone' returns %d\n", my_string_compare(hSale, hGone));
  //test gone and gone
  printf("comparing 'gone' and 'gone' returns %d\n", my_string_compare(hGone, hGone));

  my_string_destroy(&hApple);
  my_string_destroy(&hApp);
  my_string_destroy(&hSale);
  my_string_destroy(&hGone);
  return 0;
  */
}
