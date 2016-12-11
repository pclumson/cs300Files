// implementation for the stack
// PRINCE CLUMSON-EKLU  H888A642
//LAST MODIFIED : 10/15/2016
 
 
#include <iostream>
#include "stack.h"


using namespace std;
 
void Stack::push(Node * newNode)
{
	ll.addFirst(newNode);
	top = ll.getHead();
}

bool Stack::isEmpty()
{
	if(top == NULL)
		return true;
	else 
		return false;
}

Node * Stack::peek()
{
	// make a copy, erase next link and return 
	// copy is made by calling copy construtor
	Node * copy = new Node(*top);	// ?? asks for reference but pointer is given
	
	return copy;
}

Node * Stack::pop()
{
	if (isEmpty())
		return NULL;
	else
	{
		Node * copy = new Node(*top);
		ll.deleteFirst();
		top = ll.getHead();
		return copy;
	}
}

int main()
{
	Stack stack;
	
	
	
	   // ask user to input index 
	cout<< "Enter an integer or decimal number: ";
	
	int number;
	int reminder;
	cin >> number;
	cout<< "*********************************************"<<endl;
	cout<< "HERE IS THE BINARY CONVERTION OF YOUR DECIMAL :"<<endl;
	if( number == 0)
	{
	   cout<< " The Binary representation of 0 is equal to 0"<< endl;
	}
	else
	{
	  while(number > 0)
	  {
	    reminder = number % 2;
	    number /= 2 ;
	   Node * tempNode = new Node(reminder); //reminder -> newNode ;
	    stack.push(tempNode) ;// this will push total into the stack
	    
	    
	  }
	  
	   while(!stack.isEmpty())
	   {
	     
	    cout<<stack.pop()->getNumber()<<endl;
	    
	    }
	  cout<< "************************************************"<<endl;
	  
	}
	
	
	return 0;
}