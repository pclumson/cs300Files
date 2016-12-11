//PRINCE CLUMSON-EKLU
//MY ID H888A642
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

// Node class
class Node {
    int key;
    Node* left;
    Node* right;
public:
    Node() { key=-1; left=NULL; right=NULL; };
    void setKey(int aKey) { key = aKey; };
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    int Key() { return key; };
    Node* Left() { return left; };
    Node* Right() { return right; };
};

// Tree class
class Tree {
     Node* root;
public:
     Tree();
     ~Tree();
     Node* Root() { return root; };
     void addNode(int key);
     void levelOrder(Node* n);
     void Inorder(Node* );
    void Postorder(Node* );
    void Preorder(Node* node);
private:
     void addNode(int key, Node* leaf);
     void freeNode(Node* leaf);
};

// Constructor
Tree::Tree() {
     root = NULL;
}

// Destructor
Tree::~Tree() {
     freeNode(root);
}






#endif
