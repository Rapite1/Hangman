#include <stdio.h>
#include "status.h"
#include "generic.h"
#include "my_string.h"
#include "generic_vector.h"
#include "my_tree.h"

Node* new_node(MY_STRING key)
{
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == NULL)
    {
      printf("Failed to allocate space for node.\n");
      return NULL;
    }

  node->key = my_string_init_c_string(my_string_c_str(key));

  if (node->key == NULL)
    {
      free(node);
      return NULL;
    }

  node->words = generic_vector_init_default(my_string_assignment, my_string_destroy);

  if (node->words == NULL)
    {
      free(node->key);
      free(node);
      return NULL;
    }
  
  node->left = NULL;
  node->right = NULL;
  node->depth = 1;
  
  return node;
}

Node* insert_node(Node* node, MY_STRING key, MY_STRING word)
{
    if (node == NULL){
        Node* newNode = new_node(key);
        generic_vector_push_back(newNode->words, word);
        return newNode;
    }
    
    if(my_string_compare(key, node->key) == 0){
        generic_vector_push_back(node->words, word);
        return node;
    }
    
    if (my_string_compare(key, node->key) < 0)
        node->left  = insert_node(node->left, key, word);
    
    else if (my_string_compare(key, node->key) > 0)
        node->right = insert_node(node->right, key, word);
    
  //re-evaluate depth of node
  node->depth = 1 + max(get_depth(node->left), get_depth(node->right));  

  int BALANCE_FACTOR = get_balance(node);

  if (BALANCE_FACTOR > 1 && key < node->left->key)
    return right_rotate(node);
  
  
  if (BALANCE_FACTOR < -1 && key > node->right->key)
    return left_rotate(node);
  
  // Left Right zig zag
  if (BALANCE_FACTOR > 1 && key > node->left->key)
    {
      node->left =  left_rotate(node->left);
      return right_rotate(node);
    }
  
  // Right left zig zag
  if (BALANCE_FACTOR < -1 && key < node->right->key)
    {
      node->right = right_rotate(node->right);
      return left_rotate(node);
    }
  return node;
}

Node* right_rotate(Node* root)
{
  Node* temp = root->right;
  if (temp != NULL)
    {
      if (temp->right != NULL && temp->left ==NULL) // if it is already properly oriented
	{
	  temp->left = root;
	  root->right = NULL;
	  root = temp; // temp is our new root
	  
	  root->depth = max(get_depth(root->left), get_depth(root->right))+1;
	  root->left->depth = max(get_depth(root->left->left), get_depth(root->left->right))+1;
	  return root;
	}
      if (temp->right == NULL && temp->left != NULL) // if it is not oriented properly
	{
	  temp->right = temp->left;
	  temp->left = NULL;

	  temp->left = root;
	  root->right = NULL;

	  root = temp; // temp is our new root
	  
	  root->depth = max(get_depth(root->left), get_depth(root->right))+1;
	  root->left->depth = max(get_depth(root->left->left), get_depth(root->left->right))+1;
	  return root;
	}      
    }
  return root;
}


Node* left_rotate(Node* root)
{
  Node* temp = root->left;
  if (temp != NULL)
    {
      if (temp->left != NULL && temp->right ==NULL) // if it is already properly oriented
	{
	  temp->right = root;
	  root->left = NULL;
	  root = temp; // temp is our new root
	  
	  root->depth = max(get_depth(root->left),get_depth(root->right))+1;
	  root->right->depth = max(get_depth(root->right->left), get_depth(root->right->right))+1;
	  return root;
	}
      if (temp->left == NULL && temp->right != NULL) // if it is not oriented properly
	{
	  temp->left = temp->right;
	  temp->right = NULL;

	  temp->right = root;
	  root->left = NULL;

	  root = temp; // temp is our new root
	  
	  root->depth = max(get_depth(root->left), get_depth(root->right))+1;
	  root->right->depth = max(get_depth(root->right->left), get_depth(root->right->right))+1;
	  return root;
	}      
    }
  return root;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

Node* return_largest_node(Node* root)
{
  if (root == NULL || (root->left == NULL && root->right == NULL) )
    return root;

  int S, L, R;

  S = generic_vector_get_size(root->words);
  
  Node* largest_left = return_largest_node(root->left);

  if (largest_left != NULL)
    {
      L = generic_vector_get_size(largest_left->words);
    }
    
  Node* largest_right = return_largest_node(root->right);

  if (largest_right != NULL)
    {
      R = generic_vector_get_size(largest_right->words);
    }
  
  if (largest_left == NULL)
    {
      if (S > R)
	return root;
      else
	return largest_right;
    }

  if (largest_right == NULL)
    {
      if (S > L)
	return root;
      else
	return largest_left;
    }

  if (L > R && L > S)
    return largest_left;
  else if(S > R && S > L)
    return root;
  else
    return largest_right;
  
}


int get_balance(Node* root)
{
  if (root == NULL)
    {
      return 0;
    }
  
  return get_depth(root->left)-get_depth(root->right);
}

int get_depth(Node* root)
{
  if (root == NULL)
    {
      return 0;
    }
  
  return root->depth;
}

void preOrder(Node *root){
    if(root != NULL)
    {
        printf("%s %d\n", my_string_c_str(root->key), generic_vector_get_size(root->words));
        preOrder(root->left);
        preOrder(root->right);
    }
}

void tree_destroy(Node** pRoot)
{ 
  if(*pRoot != NULL){
    tree_destroy(&(*pRoot)->left);
    tree_destroy(&(*pRoot)->right);

    generic_vector_destroy(&(*pRoot)->words);
    
    my_string_destroy(&(*pRoot)->key);
    
    
    free(*pRoot);
    *pRoot = NULL;
  }
}
