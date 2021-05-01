#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <ctype.h>

struct my_string
{
  int size;
  int capacity;
  char* data;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
  My_string* pString;

  pString = (My_string*)malloc(sizeof(My_string));
  if (pString != NULL)
    {
      pString->size = 0;
      pString->capacity = 7;
      pString->data = (char*) malloc(sizeof(char)*pString->capacity);

      if (pString->data == NULL)
	{
	  free(pString);
	  printf("Failed to allocate space for myString data\n");
	  return NULL;
	}
    }
  return (MY_STRING)pString;
}

MY_STRING my_string_init_c_string(const char* c_string){
    My_string* pString = (My_string*) malloc(sizeof(My_string));
    int i;
    int string_size = 0;
    
    if(pString !=  NULL)
      {
        while(c_string[string_size] != '\0')
	  {
	    string_size++;
	  }
	
        pString->size = string_size;
        pString->capacity = string_size + 1;
        
        pString->data = (char*) malloc(sizeof(char) * (string_size+2));
        
        if(pString->data == NULL){
            free(pString);
	    printf("Failed to allocate space for pString data\n");
	    return NULL;
        }
	
	for(i = 0; i <= string_size; i++)
	  {
	    pString->data[i] = c_string[i];
	  }
      }
    
    return (MY_STRING)pString;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string* pString = (My_string*) hMy_string;
  return pString->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  My_string* pString = (My_string*) hMy_string;
  return pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  My_string* pLeft = (My_string*)hLeft_string;
  My_string* pRight = (My_string*)hRight_string;

  char* stringL = my_string_c_str(hLeft_string);
  char* stringR = my_string_c_str(hRight_string);
  int i = 0;
  
  while ( i < pLeft->size && i < pRight->size)
    {
      if (stringL[i] < stringR[i])
	return -1;
      if (stringL[i] > stringR[i])
	return 1;
      
      i++;
    }

  if (stringL[i] == stringR[i])
    return 0;
  else if (stringL[i] < stringR[i])
    return -1;
  else
    return 1;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
  My_string* pString = (My_string*)hMy_string;
  char* temp;
  char c = '\0';
  int i;
  if(pString ==NULL || fp ==NULL)
    return FAILURE;
  
  int noc1 = fscanf(fp, "%c", &c);

  if (noc1)
    pString->size = 0;
  
  while(noc1)
    { 
      //allocation of space if full
      if(pString->capacity <= pString->size)
	{
	  temp = (char*)malloc(sizeof(char)*pString->capacity*2);
	  if (temp == NULL)
	    {
	      printf("Failed to allocate space for temp.\n");
	      return FAILURE;
	    }
	  for (i=0; i< pString->size; i++)
	    {
	      temp[i] = pString->data[i];
	    }
	  free(pString->data);
	  pString->data = temp;
	  pString->capacity *= 2;
	}

      //string extraction
      if (c == '\n' || c == EOF || c == '\0')
	{
	  break;
	}
      if (c == ' ')
	{
	  ungetc(c,fp);
	  c = '\0';
	  break;
	}
      
      pString->data[pString->size] = c;
      pString->size++;
      
      noc1 = fscanf(fp, "%c",&c); 
    }
  
  if(noc1 != 1 && c == '\0')
    return FAILURE;
  
  return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  My_string* pString = (My_string*)hMy_string;
  int i = 0;

  if (pString == NULL)
    {
      return FAILURE;
    }
  
  //printf("The size of pString is %d\n", my_string_get_size(hMy_string));
  //printf("The size of pString is %d\n", my_string_get_capacity(hMy_string));
  
  char* c = (char*)pString->data;
  for (i = 0; i < pString->size; i++)
    {
      fprintf(fp, "%c", c[i]);
    }
  //  printf("The size of pString is %d\n", my_string_get_size(hMy_string));
  //  printf("The size of pString is %d\n", my_string_get_capacity(hMy_string));
  
  return FAILURE;
}

Status my_string_push_back(MY_STRING hMy_string, char item) //Done
{
  My_string* pString = (My_string*) hMy_string;
  char* temp;
  int i;

  //allocation of space if data is full
  if (pString->capacity <= pString->size)
    {
      temp = (char*)malloc(sizeof(char)*pString->capacity*2);
      if (temp == NULL)
	{
	  printf("Failed to allocate space for temp.\n");
	  return FAILURE;
	}
      for (i = 0; i < pString->size; i++)
	{
	  temp[i] = pString->data[i];
	}
      free(pString->data);
      pString->data = temp;
      pString->capacity *= 2;
    }

  pString->data[pString->size] = item;
  pString->size++;
  
  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string) //Done
{
  My_string* pString = (My_string*) hMy_string;

  if (pString->size == 0)
    {
      return FAILURE;
    }

  pString->data[--pString->size] = '\0';
  
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index) //Done
{
  My_string* pString = (My_string*) hMy_string;
  
  if ( index < 0 || index > pString->size)
    {
      return NULL;
    }
  
  return &(pString->data[index]);
}

char* my_string_c_str(MY_STRING hMy_string) //Done
{

  My_string* pString = (My_string*) hMy_string;

  char* temp;
  int i;
  
  if (pString->capacity <= pString->size)
    {
      temp = (char*)malloc(sizeof(char)*pString->capacity*2);
      if (temp == NULL)
	{
	  printf("Failed to allocate space for temp.\n");
	  return FAILURE;
	}
      for (i = 0; i < pString->size; i++)
	{
	  temp[i] = pString->data[i];
	}
      free(pString->data);
      pString->data = temp;
      pString->capacity *= 2;
    }
  
  pString->data[pString->size] = '\0';

  
  
  char* c_str = pString->data;
  
  return c_str;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string* pResult = (My_string*) hResult;
  My_string* pAppend = (My_string*) hAppend;

  char* temp;
  
  while (pResult->capacity <= pResult->size + pAppend->size)
    {
      temp = (char*)malloc(sizeof(char)*pResult->capacity*2);
      if (temp == NULL)
	{
	  printf("Failed to allocate space for temp.\n");
	  return FAILURE;
	}
      for (int i = 0; i < pResult->size; i++)
	{
	  temp[i] = pResult->data[i];
	}
      free(pResult->data);
      pResult->data = temp;
      pResult->capacity *= 2;
    }

  for (int j = 0; j < pAppend->size; j++)
    {
      pResult->data[pResult->size++] = pAppend->data[j];
    }
  pResult->data[pResult->size]= '\0';
      
  return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  My_string* pString = (My_string*) hMy_string;

  if (pString->size <= 0)
    return TRUE;
  
  return FALSE;
}

Status my_string_assignment(ITEM* pLeft, ITEM Right)
{
  My_string* pString = (My_string*)*pLeft;
  My_string* pRight = (My_string*)Right;
  Status status;
  
  if (pString == NULL)
    {
      pString = my_string_init_default();
      status = my_string_concat(pString,pRight);
      *pLeft = pString;
    }
  else
    {
      status = my_string_concat(pString,pRight);
      *pLeft = pString;
    }
  return status;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{  
  My_string* pWord = (My_string*)word;
  My_string* newKey = (My_string*) new_key;
  My_string* current_word = (My_string*) current_word_family;

  int SIZE = current_word->size;
  
  char* CURRENT_KEY = current_word->data;
  char NEW_KEY[SIZE];

  for (int i = 0; i < SIZE; i++)
    {
      if (guess == pWord->data[i])
	{
	  NEW_KEY[i] = guess;
	}
      else
	NEW_KEY[i] = CURRENT_KEY[i];
    }
  
  //reallocate space
  if(newKey->capacity <= SIZE + 1){
    char* temp = (char *) malloc(sizeof(char)*pWord->capacity*2);
    
    if(temp == NULL)
      return FAILURE;
        
    free(newKey->data);
    newKey->data = temp;
    newKey->capacity *= 2;
  }


  for (int i = 0; i < SIZE; i++)
    {
      newKey->data[i] = NEW_KEY[i];
    }
  
  return SUCCESS;
}

void my_string_destroy(MY_STRING* phString)
{
  My_string* pString = (My_string*)*phString;
  free(pString->data);
  free(pString);
  *phString=NULL;
}
