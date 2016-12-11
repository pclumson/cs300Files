#include <iostream>
#include <queue>
//#include <cstdlib>
#include "pg6.h"

using namespace std;

 
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


int printMenuGetUserChoice()
{
	int choice = 0;
	cout<<"********************"<<endl;
	cout<<"  ****************"<<endl;
	cout<<"    *************"<<endl;
	cout<<"      *********"<<endl;
	
	cout<<"BST Operations"<<endl;
		cout<<"--------------"<<endl;
		cout<<"1. Insert Element"<<endl;
		cout<<"2. Delete Element"<<endl;
		cout<<"3. Search for Element"<<endl;
		cout<<"4. Pre-Order Traverse"<<endl;
		cout<<"5. In-Order Traverse"<<endl;
		cout<<"6. Post-Order Traverse"<<endl;
		cout<<"7. Breadth-First Traverse"<<endl;
		cout<<"8. Exit Program"<<endl;
		cout<<"Please enter your choice: "<<endl;
		
	
	if(cin >> choice)	// make sure cin succeed, i.e. user input a integer.
	{
		if (choice > 0 && choice < 9)
		{
			cin.ignore();	// dump newline character
			return choice;
		}
		else		// choice beyond range 
		{
			cin.ignore();	// dump newline character
			return 0;
		}
	}
	else		// cin fails, indicating user input non-integer
	{
		cin.clear();		// bring cin back from failed status
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// dump everything from input.
		return 0;
	}
}

// Test main program
int main() 
{
   
    
   
   
   
   
   
      int choice, num;
	//Tree tree;
	Node * temp;
	
	 Tree* Tree = new Tree();
    tree.addNode(11);
    tree.addNode(8);
    tree.addNode(6);
    tree.addNode(4);
    tree.addNode(7);
    tree.addNode(10);
    tree.addNode(19);
    tree.addNode(43);
    tree.addNode(31);
    tree.addNode(29);
    tree.addNode(37);
    tree.addNode(49);
    
	
	
	int choice = printMenuGetUserChoice();
	while (choice != 8)	// if choice == 8, then save file and exit program.
	
	{
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				temp = new Node;
				cout<<"Enter element to be inserted"<<endl;
				cin>>temp->num;
				tree.insert(tree.root, temp);
				break;
			case 2:
				if (tree.root == NULL)
				{
					cout<<"Empty, nothing to delete"<<endl;
					break;
				}
				cout<<"Enter the number to be deleted: "<<endl;
				cin>>num;
				tree.deleteNode(tree.root, num);
				break;
			case 3:
				//search function
			case 4:
				cout << "Pre order traversal" << endl;
   tree->Preorder(tree->Root());
    cout << endl;
				break;
			case 5:
				cout << "In order traversal" << endl;
    tree->Inorder(tree->Root());
    cout << endl;

				break;
			case 6:
				cout << "Post order traversal" << endl;
    tree->Postorder(tree->Root());
    cout << endl;
				break;
			case 7: 
				cout << "Level order traversal" << endl;
   tree->levelOrder(tree->Root());
   cout << endl;
				break;
			case 8:
				//exit program
				break;
			default:
				cout<<"Please enter a valid choice..."<<endl;
				break;
		}
		
	choice = printMenuGetUserChoice();
	
	
	}

   
 

   


   


   
   

   delete tree;
   return 0;
}



