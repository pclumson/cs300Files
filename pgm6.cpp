//PRINCE CLUMSON
//Program 6
//MyWsu ID: H888A642

#include <iostream>
#include <cstdlib>
#include "pgm006.h"

using namespace std;


int main()
{
	int choice, num;
	BST bst;
	Node * temp;
	
	 Tree* bst = new Tree();
    bst->addNode(11);
    bst->addNode(8);
    bst->addNode(6);
    bst->addNode(4);
    bst->addNode(7);
    bst->addNode(10);
    bst->addNode(19);
    bst->addNode(43);
    bst->addNode(31);
    bst->addNode(29);
    bst->addNode(37);
    bst->addNode(49);
    
	
	do{
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
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				temp = new Node;
				cout<<"Enter element to be inserted"<<endl;
				cin>>temp->number;
				bst.insert(bst.root, temp);
				break;
			case 2:
				if (bst.root == NULL)
				{
					cout<<"Empty, nothing to delete"<<endl;
					break;
				}
				cout<<"Enter the number to be deleted: "<<endl;
				cin>>num;
				bst.deleteNode(bst.root, num);
				break;
			case 3:
				//search function
			case 4:
				cout<<"Preorder traversal order: "<<endl;
				bst.preorder(bst.root);
				cout<<endl;
				break;
			case 5:
				cout<<"Inorder traversal order: "<<endl;
				bst.inorder(bst.root);
				cout<<endl;
				break;
			case 6:
				cout<<"Postorder Traversal order: "<<endl;
				bst.postorder(bst.root);
				cout<<endl;
				break;
			case 7: 
				cout<<"Level-order Traversal order: "<<endl;
				bst.breadthfirst(bst.root);
				cout<<endl;
				break;
			case 8:
				//exit program
				break;
			default:
				cout<<"Please enter a valid choice..."<<endl;
				break;
		}
	
	}while(choice != 8);//add while loop here
}//end of main loop


void BST::insert(Node * tree, Node * newNode){
	if(root == NULL)
	{
		root = new Node;
		root->number = newNode->number;
		root->left = NULL;
		root->right = NULL;
		cout<<"Root node Added"<<endl;
		return;
	}
	if(tree->number == newNode-> number)
	{
		cout<<"Element already exists in BST.."<<endl;
		return;
	}
	if(tree->number > newNode->number)
	{
		if(tree->left != NULL)
		{
			insert(tree->left, newNode);
		}
		else
		{
			tree->left = newNode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout<<"Node Added on Left Side.."<<endl;
			return;
		}
	}
	else
	{
		if(tree->right != NULL)
		{
			insert(tree->right,newNode);
		}
		else
		{
			tree->right = newNode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout<<"Node Added on Right Side.."<<endl;
			return;
		}
	}
}


Node * BST::deleteNode(Node * root, int data)
{
     if(root == NULL)
     {
             return root;
     }
     if(root->number < data)
             root->right = delete(root->right, data);
     else if(root->number > data)
             root->left = delete(root->left,data);
     else{
          if(root->left == NULL && root->right == NULL)
          {delete root; root = NULL;}
          else if(root->left == NULL){
               Node * temp = root;
               root = root->right;
               delete temp;
          }
          else if(root->right == NULL){
               Node * temp = root;
               root = root->left;
               delete temp;
          }
          else{
               Node * temp = FindMin(root->right);//implement min function
               root->data = temp->data;
               root->right = delete(root->right; temp->data);
               }
          }
     return root;
}

void BST::preorder(Node * passed)
{
	if(root == NULL)
	{
		cout<<"Tree is Empty.."<<endl;
		return;
	}
	if(passed != NULL)
	{
		cout<<passed->number<<" ";
		preorder(passed->left);
		preorder(passed->right);
	}
}

void BST::inorder(Node * passed)
{
	if(root == NULL)
	{
		cout<<"Tree is Empty.."<<endl;
		return;
	}
	if(passed != NULL)
	{
		inorder(passed->left);
		cout<<passed->number<<" ";
		inorder(passed->right);
	}
}

void BST::postorder(Node * passed)
{
	if(root == NULL)
	{
		cout<<"Tree is Empty.."<<endl;
		return;
	}
	if(passed != NULL)
	{
		postorder(passed->left);
		postorder(passed->right);
		cout<<passed->number<<" ";
	}
}
