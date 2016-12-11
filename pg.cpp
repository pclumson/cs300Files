//PRINCE CLUMSON-EKLU
//*********************

#include <iostream>
#include <queue>
using namespace std;

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

// Free the node
void Tree::freeNode(Node* leaf)
{
    if ( leaf != NULL )
    {
       freeNode(leaf->Left());
       freeNode(leaf->Right());
       delete leaf;
    }
}

// Add a node
void Tree::addNode(int key) {
     // No elements. Add the root
     if ( root == NULL ) {
        cout << "add root node ... " << key << endl;
        Node* n = new Node();
        n->setKey(key);
    root = n;
     }
     else {
    cout << "add other node ... " << key << endl;
    addNode(key, root);
     }
}

// Add a node (private)
void Tree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() ) {
       if ( leaf->Left() != NULL )
      addNode(key, leaf->Left());
       else {
      Node* n = new Node();
      n->setKey(key);
      leaf->setLeft(n);
       }
    }
    else {
       if ( leaf->Right() != NULL )
      addNode(key, leaf->Right());
       else {
      Node* n = new Node();
      n->setKey(key);
      leaf->setRight(n);
       }
    }
}

// Print the tree level-order assisted by queue
void Tree::levelOrder(Node* n) {
   // Create a queue
   queue<Node*> q;

   // Push the root
   q.push(n);

   while ( ! q.empty() )
   {
       // Dequeue a node from front
       Node* v = q.front();
       cout << v->Key() << " ";

       // Enqueue the left children
       if ( v->Left() != NULL )
            q.push(v->Left());

       // Enqueue the right children
       if ( v->Right() != NULL )
            q.push(v->Right());

       // Pop the visited node
       q.pop();
   }
}

void Tree::Preorder(Node* node)
{
    if ( node )
    {
        cout << node->Key() << " ";
        Preorder(node->Left());
        Preorder(node->Right());
    }
}

void Tree:: Inorder(Node* Root)
{
    if(Root != NULL)
    {
        Inorder(Root->Left());
        cout << Root->Key() << endl;
        Inorder(Root->Right());

    }
}

void Tree:: Postorder(Node* Root)
{
    if(Root != NULL)
    {

        Postorder(Root->Left());
        Postorder(Root->Right());
        cout << Root->Key() << endl;

    }
}



// Test main program
int main() 
{
    //Tree tree;
	//Node * temp;
    
     
   Tree* tree = new Tree();
    tree->addNode(11);
    tree->addNode(8);
    tree->addNode(6);
    tree->addNode(4);
    tree->addNode(7);
    tree->addNode(10);
    tree->addNode(19);
    tree->addNode(43);
    tree->addNode(31);
    tree->addNode(29);
    tree->addNode(37);
    tree->addNode(49);
    
    
    
      BinarySearchTree b;
    int ch,tmp,tmp1;
    while(1)
    {
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. Insertion/Creation "<<endl;
       cout<<" 2. In-Order Traversal "<<endl;
       cout<<" 3. Pre-Order Traversal "<<endl;
       cout<<" 4. Post-Order Traversal "<<endl;
       cout<<" 5. Removal "<<endl;
       cout<<" 6. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" Enter Number to be inserted : ";
                    cin>>tmp;
                    b.insert(tmp);
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_inorder();
                    break;
           case 3 : cout<<endl;
                    cout<<" Pre-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_preorder();
                    break;
           case 4 : cout<<endl;
                    cout<<" Post-Order Traversal "<<endl;
                    cout<<" --------------------"<<endl;
                    b.print_postorder();
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    cin>>tmp1;
                    b.remove(tmp1);
                    break;
           case 6 : 
                    return 0;
                    
       }
    }
    
    
/*
   
   cout << "Level order traversal" << endl;
   tree->levelOrder(tree->Root());
   cout << endl;


   cout << "Pre order traversal" << endl;
   tree->Preorder(tree->Root());
    cout << endl;


   cout << "In order traversal" << endl;
    tree->Inorder(tree->Root());
    cout << endl;

   cout << "Post order traversal" << endl;
    tree->Postorder(tree->Root());
    cout << endl;
*/
  / delete tree;
  / return 0;
   
   
}

