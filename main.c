#include <stdio.h>
#include <ctype.h>
#include "my_string.h"
#include "generic_vector.h"
#include "my_tree.h"

void clear_keyboard_buffer(void);
int return_guess_count(void);
int return_length_count(void);
Boolean return_remaining_count(void);
char enter_guess(void);
Boolean play_again(void);

int main(int argc, char* argv[])
{
  int VECTOR_SIZE = 30;
  GENERIC_VECTOR hMy_vector[VECTOR_SIZE];
  MY_STRING hMy_string = NULL;
  FILE* fp;
  Boolean again = TRUE;
  
  GENERIC_VECTOR hVector_focus = NULL;
  
  //initialize string

  hMy_string = my_string_init_default();
  fp = fopen("dictionary.txt","r");  
  
  //initialize vectors
  for (int i = 0; i < VECTOR_SIZE; i++)
    {
      hMy_vector[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    }

  //initalize partitioned dictionary
  while (my_string_extraction(hMy_string, fp))
    {
      int i;
      i = my_string_get_size(hMy_string);
      generic_vector_push_back(hMy_vector[i], hMy_string);
    }

  //EVIL HANGMAN GAME
  //===============================================================//
  while(again == TRUE){
  MY_STRING hGuesses_made = my_string_init_default(); // string of characters used
  MY_STRING hKey = my_string_init_default(); // string of key
  MY_STRING hNew_key = my_string_init_default(); // string of new key

  int GUESSES_REMAINING;
  int WORD_LENGTH;
  char guess_c;
  Boolean already_guessed = FALSE;
  int POSSIBILITIES_REMAINING;
  Boolean SOLVED = FALSE;
  Boolean SHOW_REMAINING_COUNT = FALSE;

  
  //INPUT FOR WORD LENGTH
  WORD_LENGTH = return_length_count();
  //INPUT FOR AMOUNT OF GUESSES
  GUESSES_REMAINING = return_guess_count();
  //INPUT FOR WORDS REMAINING
  SHOW_REMAINING_COUNT = return_remaining_count();

  //Game initialization
  hVector_focus = generic_vector_init_default(my_string_assignment, my_string_destroy);
  printf("Word length: %d\n", WORD_LENGTH);
  printf("guesses: %d\n", GUESSES_REMAINING);
  if (SHOW_REMAINING_COUNT == TRUE)
    printf("showing remainder count.\n\n");
  else
    printf("not showing remainder count.\n\n");

  //Key initialization
  for (int i = 0; i <WORD_LENGTH; i++)
    {
      my_string_push_back(hKey, '-');
      my_string_push_back(hNew_key, '-');
    }
  char final_guess[WORD_LENGTH];

  //MAKE COPY OF VECTOR INTO VECTOR FOCUS
  for (int i = 0; i < generic_vector_get_size(hMy_vector[WORD_LENGTH]); i++)
    {
      generic_vector_push_back(hVector_focus, generic_vector_at(hMy_vector[WORD_LENGTH], i));
    }

  printf("SIZE OF VECTOR FOCUS: %d\n", generic_vector_get_size(hVector_focus));
  POSSIBILITIES_REMAINING = generic_vector_get_size(hVector_focus);

  //Continue game as long as there are guesses or if the game isn't resolved
  while (GUESSES_REMAINING > 0 && SOLVED == FALSE)
    {
      printf("You have %d guesses remaining.\n", GUESSES_REMAINING);
      printf("USED GUESSES: %s\n", (char*) my_string_c_str(hGuesses_made));
      if (SHOW_REMAINING_COUNT == TRUE) //remaining number of words in list
	printf("NUMBER OF POSSIBILITIES: %d\n", POSSIBILITIES_REMAINING);
      
      //OBTAIN GUESS
      guess_c = enter_guess();
      
      //check if already guessed  
      for (int i = 0; i < my_string_get_size(hGuesses_made); i++)
	{
	  if (guess_c == *my_string_at(hGuesses_made,i))
	    {
	      already_guessed = TRUE;
	      break;
	    }
	}
      while (already_guessed)
	{
	  already_guessed = FALSE;
	  printf("You already guessed %c.\n\n", guess_c);

	  printf("You have %d guesses remaining.\n", GUESSES_REMAINING);
	  printf("USED GUESSES: %s\n", (char*) my_string_c_str(hGuesses_made));
	  if (SHOW_REMAINING_COUNT == TRUE) //remaining number of words in list
	    printf("NUMBER OF POSSIBILITIES: %d\n", POSSIBILITIES_REMAINING);

	  guess_c = enter_guess();
	  for (int i = 0; i < my_string_get_size(hGuesses_made); i++)
	    {
	      if (guess_c == *my_string_at(hGuesses_made,i))
		{
		  already_guessed = TRUE;
		  break;
		}
	    }	  
	}
      printf("\n");
      my_string_push_back(hGuesses_made, guess_c);
      my_string_push_back(hGuesses_made, ' ');

      Node* root = NULL;
      //insert nodes into bin
      for (int i = 0; i < generic_vector_get_size(hVector_focus); i++)
	{
	  get_word_key_value(hKey, hNew_key, generic_vector_at(hVector_focus, i), guess_c);	  
	  root = insert_node(root, hNew_key, generic_vector_at(hVector_focus, i));

	}
      if (SHOW_REMAINING_COUNT == TRUE)
	preOrder(root);

      Node* largest_root = return_largest_node(root);
      
      printf("YOUR WORD: %s\n", my_string_c_str(largest_root->key));

      //replace init values
      
      for(int i = 0; i < WORD_LENGTH; i++)
	{
	  my_string_pop_back(hKey);
	}
      my_string_concat(hKey, largest_root->key);

      //empty vector focus & fill it with new strings
      int Popback = generic_vector_get_size(hVector_focus);
      for(int i = 0; i < Popback; i++)
	{
	  generic_vector_pop_back(hVector_focus);
	}

      POSSIBILITIES_REMAINING = generic_vector_get_size(largest_root->words);

      for(int i = 0; i < POSSIBILITIES_REMAINING; i++)
	{
	  generic_vector_push_back(hVector_focus, generic_vector_at(largest_root->words,i));
	}
      
      //check if solved
      for(int i = 0; i <WORD_LENGTH; i++)
	{
	  if (*my_string_at(hKey, i)== '-')
	    break;
	  if (i == WORD_LENGTH-1)
	    SOLVED = TRUE;
	}
      
      if (SOLVED == TRUE)
	{
	  tree_destroy(&root);
	  printf("\nYou got the word %s!\n", my_string_c_str(hKey));
	  GUESSES_REMAINING = 0;
	}
      
      tree_destroy(&root);
      GUESSES_REMAINING--;
    }
  
  if (SOLVED == FALSE)
    {
      printf("Guess what the word is.\n");
      printf("%s\n", my_string_c_str(hKey));
      scanf("%s", final_guess);
      clear_keyboard_buffer();
      
      for (int i = 0; i < WORD_LENGTH; i++)
	{
	  if (final_guess[i] != *my_string_at(generic_vector_at(hVector_focus, 0),i))
	    {
	      break;
	    }
	  else if (i == WORD_LENGTH-1 && generic_vector_get_size(hVector_focus) == 1)
	    printf("\nYou got it!\n");
	  else
	    {
	      printf("\nWRONG\n");
	      break;
	    }
	}
    }

  again = play_again();
  
  generic_vector_destroy(&hVector_focus);
  my_string_destroy(&hKey);
  my_string_destroy(&hNew_key);
  my_string_destroy(&hGuesses_made);	 

  }
  
  //destroy vectors
  for (int i = 0; i < VECTOR_SIZE; i++)
    {
      //    printf("WORD SIZE OF %d: \t%d\n",i,generic_vector_get_size(hMy_vector[i]));
      generic_vector_destroy(&hMy_vector[i]);
    }
  
  my_string_destroy(&hMy_string);
  fclose(fp);

  return 0;
}

char enter_guess(void)
{
  char c;
  int noc;
  printf("Enter guess: ");

  noc = scanf("%c", &c);
  clear_keyboard_buffer();

  while (noc != 1 || !isalpha(c))
    {
      printf("\nPlease enter a valid guess.\n");
      printf("Enter guess: ");
      noc = scanf("%c",&c);
      clear_keyboard_buffer();
      
    }
  return tolower(c);
}

Boolean play_again(void)
{
  char yes_or_no;
  printf("Play again? (y\\n): ");

  int noc = scanf("%c", &yes_or_no);
  clear_keyboard_buffer();
  while(noc != 1 || (yes_or_no != 'y' && yes_or_no != 'n' && yes_or_no != 'Y' && yes_or_no != 'N'))
    {
      printf("\nPlease enter a valid response.\n");
      printf("Play again? (y\\n): ");
      noc = scanf("%c", &yes_or_no);
      clear_keyboard_buffer();
    }
  if (yes_or_no == 'Y' || yes_or_no == 'y')
    return TRUE;
  return FALSE;
}


Boolean return_remaining_count(void)
{
  char yes_or_no;
  printf("Words remaining in list count? (y\\n): ");

  int noc = scanf("%c", &yes_or_no);
  clear_keyboard_buffer();
  while(noc != 1 || (yes_or_no != 'y' && yes_or_no != 'n' && yes_or_no != 'Y' && yes_or_no != 'N'))
    {
      printf("\nPlease enter a valid response.\n");
      printf("Words remaining in the list count? (y\\n): ");
      noc = scanf("%c", &yes_or_no);
      clear_keyboard_buffer();
    }
  if (yes_or_no == 'Y' || yes_or_no == 'y')
    return TRUE;
  return FALSE;
}


int return_length_count(void)
{
  int WORD_LENGTH;
  printf("How long should the words be: ");
  int noc = scanf("%d", &WORD_LENGTH);

  clear_keyboard_buffer();
  while(noc != 1 || WORD_LENGTH < 2 || WORD_LENGTH == 23 || WORD_LENGTH == 25 || WORD_LENGTH == 26 || WORD_LENGTH == 27)
    {
      printf("\nPlease enter a valid word length.\n");
      printf("How long should the words be: ");
      noc = scanf("%d", &WORD_LENGTH);
      clear_keyboard_buffer();
    }
  return WORD_LENGTH;
}

int return_guess_count(void)
{
 int x = 0;
 printf("How many guesses do you want: ");
 int noc = scanf("%d", &x);
 
 clear_keyboard_buffer();
 while(noc !=1 || x < 1)
   {
     printf("\nPlease enter a valid guess length.\n");
     printf("How many guesses do you have: ");
     noc = scanf("%d", &x);
     clear_keyboard_buffer();
   }
 return x;
}
void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n') 
	{
		scanf("%c", &c);
	}
}
