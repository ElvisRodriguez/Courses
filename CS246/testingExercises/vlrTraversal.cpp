//Name: Elvis Rodriguez
//Question 4: Write a recursive program to implement the VLR traversal
//            Of a binary tree

#include <iostream>
using namespace std;

typedef struct node {
  int data;
  node *left;
  node *right;
} Tree;

Tree *newNode(int data) {
  Tree *n = new Tree;
  if (n != NULL) {
    n->data = data;
    n->left = NULL;
    n->right = NULL;
  }
  return n;
}

void vlrTraversal(Tree *node) {
  if (node == NULL) {
    return;
  }
  cout << node->data;
  vlrTraversal(node->left);
  vlrTraversal(node->right);
}

int main() {
  Tree *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  vlrTraversal(root);
  delete root->left->right;
  delete root->left->left;
  delete root->right;
  delete root->left;
  delete root;
  return 0;
}
