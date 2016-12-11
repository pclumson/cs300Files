//PRINCE CLUMSON-EKLU
//**********************
//header file for binary tree program

#ifndef MY_TREE_H
#define MY_TREE_H

class Node
{
      public:
              int number;
              Node * left;
              Node * right;
              Node(){number = 0; left = NULL; right = NULL;}
};

class BST
{
      public:
              Node * root;
              BST(){root = NULL;}
              void insert(Node *, Node *);
              Node * deleteNode(Node *, int);
              void search(int, Node *);
              void preorder(Node *);
              void inorder(Node *);
              void postorder(Node *);
              void breadthfirst(Node *);
};

#endif
