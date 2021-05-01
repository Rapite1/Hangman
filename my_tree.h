#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "generic.h"
#include "my_string.h"
#include "generic_vector.h"

struct node
{
  int depth;
  struct node* left;
  struct node* right;

  MY_STRING key;
  GENERIC_VECTOR words;
};
typedef struct node Node;

Node* new_node(MY_STRING key);

Node* insert_node(Node* node, MY_STRING key, MY_STRING word);

GENERIC_VECTOR get_key_word(Node* node, MY_STRING key);

Node* left_rotate(Node *root);
Node* right_rotate(Node *root);

void preOrder(Node *root);

int max(int a, int b);

int get_depth(Node* root);

int get_balance(Node* root);

void tree_destroy(Node** pRoot);

Node* return_largest_node(Node* root);
