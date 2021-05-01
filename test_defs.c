#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_default();
  if(hString == NULL)
    {
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_get_size(hString) != 0)
    {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	      "Did not receive 0 from get_size after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "\ttest_get_size_on_init_default_returns_0\n"
	      , length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test1_alee_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString= my_string_init_default();

  if(my_string_get_capacity(hString) != 7)
    {
      status = FAILURE;
      strncpy(buffer, "test1_alee_get_capacity_on_init_default_returns_7\n"
	      "Did not receive 7 from get_capacity after init default\n", length);
      my_string_destroy(&hString);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "\ttest1_alee_get_capacity_on_init_default_returns_7\n",length);
    }
  my_string_destroy(&hString);
  return status;
}
  
Status test2_alee_init_c_string_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("bepis");

  if(hString == NULL)
    {
      strncpy(buffer, "test2_alee_init_c_string_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      status = FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_c_returns_nonNULL\n", length);
      status = SUCCESS;
    }
  
  return status;
}
  
Status test3_alee_get_c_string_size(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("bepis");
  if (hString ==NULL)
    {
      strncpy(buffer, "test3_alee_get_c_string_size\n"
	      "hString is NULL\n", length);
      return FAILURE;
    }
  if(my_string_get_size(hString) != 5)
    {
      strncpy(buffer, "test3_alee_get_c_string_size\n"
	      "\tget_c_string_size returns incorrect size", length);
      status = FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\tget_c_string_capacity returns correct size\n", length);
      status = SUCCESS;
    }
  
  return status;
  
}

Status test4_alee_get_c_string_capacity(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("bepis");

  if (hString ==NULL)
    {
      strncpy(buffer, "test4_alee_get_c_string_capacity\n"
	      "\thString is NULL\n", length);
      return FAILURE;
    }
  
  if(my_string_get_capacity(hString) != 6)
    {
      strncpy(buffer, "test4_alee_get_c_string_capacity\n"
	      "\tget_c_string_size returns incorrect capacity", length);
      status = FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\tget_c_string_capacity returns correct capacity\n", length);
      status = SUCCESS;
    }
    
  return status;
}
  

Status test5_alee_string_compare_left_larger(char* buffer, int length)
{
  MY_STRING hStringL = NULL;
  MY_STRING hStringR = NULL;
  Status status;

  hStringL = my_string_init_c_string("orly");
  hStringR = my_string_init_c_string("bepis");

  if (hStringL ==NULL || hStringR == NULL)
    {
      strncpy(buffer, "test4_alee_string_compare_left_larger\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }
  if(my_string_compare(hStringL,hStringR) > 0)
    {
      my_string_destroy(&hStringL);
      my_string_destroy(&hStringR);
      
      strncpy(buffer, "hStringL is larger than hStringR\n", length);
      status = SUCCESS;
    }
  else
    {
      my_string_destroy(&hStringL);
      my_string_destroy(&hStringR);
      strncpy(buffer, "test5_alee_string_compare_left_larger\n"
	      "\tmy_string_compare returns incorrect result\n", length);
      status = FAILURE;      
    }
  
  return status;
}

  
Status test6_alee_string_compare_left_smaller(char* buffer, int length)
{
  MY_STRING hStringL = NULL;
  MY_STRING hStringR = NULL;
  Status status;

  hStringL = my_string_init_c_string("bepis");
  hStringR = my_string_init_c_string("orly");

  if (hStringL ==NULL || hStringR == NULL)
    {
      strncpy(buffer, "test6_alee_string_compare_left_larger\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }
  if(my_string_compare(hStringL,hStringR) < 0)
    {
      my_string_destroy(&hStringL);
      my_string_destroy(&hStringR);
      
      strncpy(buffer, "hStringL is smaller than hStringR\n", length);
      status = SUCCESS;
    }
  else
    {
      my_string_destroy(&hStringL);
      my_string_destroy(&hStringR);
      strncpy(buffer, "test6_alee_string_compare_left_smaller\n"
	      "\tmy_string_compare returns incorrect result\n", length);
      status = FAILURE;      
    }
  
  return status;
}


Status test7_alee_string_extraction_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  FILE *fp;

  hString = my_string_init_default();
  
  fp = fopen("simple.txt", "r");

  
  if(my_string_extraction(hString,fp))
    {
      my_string_destroy(&hString);
      fclose(fp);
      strncpy(buffer, "Successfully extracted string\n", length);
      return SUCCESS;
    }

  my_string_destroy(&hString);
  fclose(fp);

  strncpy(buffer, "test7_alee_string_extraction_returns_nonNULL\n"
	  "\tmy_string_extraction returns failure\n", length);
  status = FAILURE;
  return status;
}

Status test8_alee_string_insertion(char* buffer, int length)
{
  MY_STRING hString = NULL;
  FILE *fp;
  FILE *insertion;
  
  hString = my_string_init_default();
  fp = fopen("simple.txt", "r");
  insertion = fopen("insertion_text.txt", "w+");

  if (insertion ==NULL)
    {
      strncpy(buffer, "test8_alee_string_insertion\n"
	      "\tfailed to create insertion_text.txt file",length);
      fclose(fp);
      my_string_destroy(&hString);
      return FAILURE;
    }
  
  if(my_string_extraction(hString,fp))
    {
      my_string_insertion(hString,insertion);
      fclose(fp);
      fclose(insertion);
      my_string_destroy(&hString);
      strncpy(buffer, "Successfully inserted string\n", length);

      return SUCCESS;
    }
  else
    {    
      strncpy(buffer, "test8_alee_string_insertion\n"
	      "\tstring_extraction failed\n", length);
      fclose(fp);
      my_string_destroy(&hString);
      fclose(insertion);
      return FAILURE;
    }
}

Status test9_alee_pushback_size_accuracy(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  
  if (hString == NULL)
    {
      strncpy(buffer, "test9_alee_pushback_size_accuracy\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }
  else
    {
      my_string_push_back(hString, 'b');
      if(my_string_get_size(hString) == 1)
	{
	  strncpy(buffer, "test9_alee_pushback_size is accurate\n", length);
	  my_string_destroy(&hString);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test9_alee_pushback_size_accuracy\n"
		  "\tunexpected string size\n", length);
	  my_string_destroy(&hString);
	  return FAILURE;
	}
    }
}


Status test10_alee_pushback_capacity_same(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  
  if (hString == NULL)
    {
      strncpy(buffer, "test10_alee_pushback_capacity_same\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }
  else
    {
      my_string_push_back(hString, 'b');
      if(my_string_get_capacity(hString) == 7)
	{
	  strncpy(buffer, "test10_alee_pushback_capacity is accurate\n", length);
	  my_string_destroy(&hString);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test10_alee_pushback_capacity_accuracy\n"
		  "\tunexpected string capacity\n", length);
	  my_string_destroy(&hString);
	  return FAILURE;
	}
    }
}


Status test11_alee_pushback_capacity_cahnges(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  
  if (hString == NULL)
    {
      strncpy(buffer, "test11_alee_pushback_capacity_cahnges\n"
	      "string returned NULL\n", length);
      return FAILURE;
    }
  else
    {
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      my_string_push_back(hString, 'b');
      
      if(my_string_get_capacity(hString) == 14)
	{
	  strncpy(buffer, "test11_alee_pushback_capacity is accurate\n", length);
	  my_string_destroy(&hString);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test11_alee_pushback_capacity_accuracy\n"
		  "\tunexpected string capacity\n", length);
	  my_string_destroy(&hString);
	  return FAILURE;
	}
    }

}

  
Status test12_alee_popback_if_empty(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("why hello there");
  
  if (hString == NULL)
    {
      strncpy(buffer, "test12_alee_popback_if_empty\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }
  
  while (my_string_empty(hString) == FALSE)
    {
      my_string_pop_back(hString);
    }

  if (my_string_empty(hString)== TRUE && my_string_get_size(hString) == 0)
    {
      strncpy(buffer, "successfully popbacked until empty\n", length);
      my_string_destroy(&hString);
      return SUCCESS;
    }
  else
    {
      strncpy(buffer, "test12_alee_popback_if_empty\n"
	      "\tfailure to empty string.\n",length);
      my_string_destroy(&hString);
      return FAILURE;
    }
}
  
Status test13_alee_popback_if_notempty(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  
  if (hString == NULL)
    {
      strncpy(buffer, "test13_alee_popback_if_notempty\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  if (my_string_pop_back(hString) == FAILURE)
    {
      strncpy(buffer, "string is already empty\n", length);
      my_string_destroy(&hString);
      return SUCCESS;
    }
  else
    {
      strncpy(buffer, "test12_alee_popback_if_empty\n"
	      "\tattempted to popback empty string.\n",length);
      my_string_destroy(&hString);
      return FAILURE;
    }
}

Status test14_alee_is_empty(char* buffer, int length)
{
  MY_STRING hString = NULL;
  
  hString = my_string_init_default();
  
  if (hString == NULL)
    {
      strncpy(buffer, "test15_alee_pushback_capacity_cahnges\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  if(my_string_empty(hString) == TRUE)
    {
      strncpy(buffer, "string is empty\n", length);
      my_string_destroy(&hString);
      return SUCCESS;
    }
  else
    {
      strncpy(buffer, "test14_alee_is_empty\n"
	      "\tstring reported not empty\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }
}


Status test15_alee_is_not_empty(char* buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_c_string("bepis");

  if (hString == NULL)
    {
      strncpy(buffer, "test15_alee_is_not_empty\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }
  if(my_string_empty(hString) == FALSE)
    {
      strncpy(buffer, "Successfully reports nonempty string\n", length);
      my_string_destroy(&hString);
      return SUCCESS;
    }
  else
    {
      strncpy(buffer, "test15_alee_is_not_empty\n"
	      "\tstring returned NULL\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }
}

Status test16_alee_concat_two_strings(char* buffer, int length)
{
  MY_STRING hString = NULL;
  MY_STRING hAppend = NULL;

  hString = my_string_init_c_string("omae wa moe");

  if (hString == NULL)
    {
      strncpy(buffer, "test16_alee_concat_two_strings\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  hAppend = my_string_init_c_string(" shinderu");

  if (hAppend == NULL)
    {
      strncpy(buffer, "test16_alee_concat_two_string\n"
	      "\tstring returned NULL\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }

  if (my_string_concat(hString, hAppend) == SUCCESS)
    {
      strncpy(buffer, "Successfully concat two strings.\n", length);
      my_string_destroy(&hString);
      my_string_destroy(&hAppend);
      return SUCCESS;
    }
  else
    {
      strncpy(buffer, "test16_alee_concat_two_string\n"
	      "\tFailed to concat two strings\n", length);
      my_string_destroy(&hString);
      my_string_destroy(&hAppend);
      return FAILURE;
    }
}
  
Status test17_alee_concat_two_strings_reversed(char* buffer, int length)
{
  MY_STRING hString = NULL;
  MY_STRING hAppend = NULL;

  hString = my_string_init_c_string("omae wa moe");

  if (hString == NULL)
    {
      strncpy(buffer, "test17_alee_concat_two_strings_reversed\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  hAppend = my_string_init_c_string(" shinderu");

  if (hAppend == NULL)
    {
      strncpy(buffer, "test17_alee_concat_two_string_reversed\n"
	      "\tstring returned NULL\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }

  if (my_string_concat(hAppend, hString) == SUCCESS)
    {
      strncpy(buffer, "Successfully concat two strings in reverse.\n", length);
      my_string_destroy(&hString);
      my_string_destroy(&hAppend);
      return SUCCESS;
    }
  else
    {
      strncpy(buffer, "test17_alee_concat_two_string_reversed\n"
	      "\tFailed to concat two strings in reverse\n", length);
      my_string_destroy(&hString);
      my_string_destroy(&hAppend);
      return FAILURE;
    }
}
  
Status test18_alee_get_size_after_concat(char* buffer, int length)
{
  MY_STRING hString = NULL;
  MY_STRING hAppend = NULL;

  hString = my_string_init_c_string("omae wa moe");

  if (hString == NULL)
    {
      strncpy(buffer, "test18_alee_concat_two_strings\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  hAppend = my_string_init_c_string(" shinderu");

  if (hAppend == NULL)
    {
      strncpy(buffer, "test18_alee_concat_two_string\n"
	      "\tstring returned NULL\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }

  int size = my_string_get_size(hString) + my_string_get_size(hAppend);
  if (my_string_concat(hString, hAppend) == SUCCESS)
    {
      if (my_string_get_size(hString) == size)
	{
	  strncpy(buffer, "hString is of proper size\n", length);
	  my_string_destroy(&hString);
	  my_string_destroy(&hAppend);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test18_alee_get_size_after_concat\n"
		  "\tUnexpected size\n", length);
	  my_string_destroy(&hString);
	  my_string_destroy(&hAppend);
	  return FAILURE;
	}
    }
  else
    {
      strncpy(buffer, "test16_alee_concat_two_string\n"
	      "\tFailed to concat two strings\n", length);
      my_string_destroy(&hString);
      my_string_destroy(&hAppend);
      return FAILURE;
    }  
}
  
Status test19_alee_get_capacity_after_concat(char* buffer, int length)
{
  MY_STRING hString = NULL;
  MY_STRING hAppend = NULL;

  hString = my_string_init_c_string("omae wa moe");

  if (hString == NULL)
    {
      strncpy(buffer, "test19_alee_get_capacity_after_concat\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  hAppend = my_string_init_c_string(" shinderu");

  if (hAppend == NULL)
    {
      strncpy(buffer, "test19_alee_get_capacity_after_concat\n"
	      "\tstring returned NULL\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }

  int min_capacity = my_string_get_capacity(hString) + my_string_get_capacity(hAppend);

  if (my_string_concat(hString, hAppend) == SUCCESS)
    {
      if (my_string_get_capacity(hString) >= min_capacity)
	{
	  strncpy(buffer, "hString is of proper capacity\n", length);
	  my_string_destroy(&hString);
	  my_string_destroy(&hAppend);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test19_alee_get_capacity_after_concat\n"
		  "\tUnexpected size\n", length);
	  my_string_destroy(&hString);
	  my_string_destroy(&hAppend);
	  return FAILURE;
	}
    }
  else
    {
      strncpy(buffer, "test19_alee_get_capacity_after_concat\n"
	      "\tFailed to concat two strings\n", length);
      my_string_destroy(&hString);
      my_string_destroy(&hAppend);
      return FAILURE;
    }

}
  
Status test20_alee_get_size_after_popback(char*buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_c_string("okay then");
  int string_size = my_string_get_size(hString);
  
  if (hString == NULL)
    {
      strncpy(buffer, "test20_alee_get_size_after_popback\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  if (my_string_pop_back(hString) == SUCCESS)
    {
      if (my_string_get_size(hString) == string_size-1)
	{
	  strncpy(buffer, "Successfully described size after popback.\n", length);
	  my_string_destroy(&hString);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test20_alee_get_size_after_popback\n"
		  "\tImproper string size after popback.\n", length);
	  my_string_destroy(&hString);
	  return FAILURE;
	}
    }
  else
    {
      strncpy(buffer, "test20_alee_get_size_after_popback\n"
	      "t\failed to popback\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }
}
  
Status test21_alee_get_capacity_after_popback(char*buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_c_string("okay then");
  int string_capacity = my_string_get_capacity(hString);
  
  if (hString == NULL)
    {
      strncpy(buffer, "test21_alee_get_capacity_after_popback\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  if (my_string_pop_back(hString) == SUCCESS)
    {
      if (my_string_get_capacity(hString) == string_capacity)
	{
	  strncpy(buffer, "Successfully described unchanged capacity after popback.\n", length);
	  my_string_destroy(&hString);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test21_alee_get_capacity_after_popback\n"
		  "\tImproper string capacity after popback.\n", length);
	  my_string_destroy(&hString);
	  return FAILURE;
	}
    }
  else
    {
      strncpy(buffer, "test21_alee_get_capacity_after_popback\n"
	      "t\failed to popback\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }

}
  
Status test22_alee_my_string_at_accuracy(char* buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_c_string("cds");

  if (hString == NULL)
    {
      strncpy(buffer, "test22_alee_my_string_at_accuracy\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  if (*my_string_at(hString, 0) == 'c')
    {
      strncpy(buffer, "Successfully identified character in string.\n", length);
      my_string_destroy(&hString);
      return SUCCESS;
    }
  else
    {
      strncpy(buffer, "test22_alee_my_string_at_accuracy\n"
	      "\tfailed to identify proper character address.\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }
}
  
Status test23_alee_my_string_c_str_after_concat(char* buffer, int length)
{
  MY_STRING hString = NULL;
  MY_STRING hAppend = NULL;
  char* str;
  hString = my_string_init_c_string("omae wa moe");

  if (hString == NULL)
    {
      strncpy(buffer, "test23_alee_concat_two_strings\n"
	      "\tstring returned NULL\n", length);
      return FAILURE;
    }

  hAppend = my_string_init_c_string(" shinderu");

  if (hAppend == NULL)
    {
      strncpy(buffer, "test16_alee_concat_two_string\n"
	      "\tstring returned NULL\n", length);
      my_string_destroy(&hString);
      return FAILURE;
    }

  if (my_string_concat(hString, hAppend) == SUCCESS)
    {
      if ((str=my_string_c_str(hString)))
	{
	  strncpy(buffer, "my_str_c function was successful\n", length);
	  my_string_destroy(&hString);
	  my_string_destroy(&hAppend);
	  return SUCCESS;
	}
      else
	{
	  strncpy(buffer, "test23_alee_my_string_c_str_after_concat\n"
		  "\tmy_string_c_str failed.\n", length);
	  my_string_destroy(&hString);
	  my_string_destroy(&hAppend);
	  return FAILURE;
	}
    }
  else
    {
      strncpy(buffer, "test23_alee_my_string_c_str_after_concat\n"
	      "\tFailed to concat two strings\n", length);
      my_string_destroy(&hString);
      my_string_destroy(&hAppend);
      return FAILURE;
    }

}
