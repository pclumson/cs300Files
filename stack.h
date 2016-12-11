// this is the header file of stack data structure.

#ifndef MY_STACK_H
#define MY_STACK_H

class Node 
{
private:
	int number;
	Node * next;

public:
	Node(){number = 0; next = NULL;}
	
	Node(int initialNumber, Node * initialNext = NULL)
	{
		number = initialNumber;
		next = initialNext;
	}
	
	// copy constructor
	Node(Node & copyFromNode) 
	{
		this->number	=	copyFromNode.getNumber();
		this->next		= 	copyFromNode.getNext();
	}
	
		
	// setters & getters
	int getNumber() {return number;}
	Node * getNext()	{return next;}
	void setNumber(int newNumber)	{number = newNumber;}
	void setNext(Node * newNext)	{next = newNext;}
};

class LinkedList
{
private:
	Node * head;

public:
	LinkedList(){head = NULL;}
	
	// very similar to Stack::push()
	void addFirst(Node *newNode)
	{
		newNode->setNext(head);
		head = newNode;
	}
	
	// somehow similar to Stack::pop()
	void deleteFirst()
	{
		if (head == NULL)
			return;
		else
		{
			Node * temp = head;
			head = head->getNext();
			delete temp;
		}
	}
	
	bool isEmpty() 		{return (head == NULL);}
	Node * getHead()	{return head;}
	
	// there is no setter to head 
	// since head should be maintained by addFirst() & deleteFirst() only.
};

class Stack 
{
private:
	Node * top;
	LinkedList ll;
public:
	Stack(){top = NULL; }
	
	// push new node to the stack
	// new node will become the new top of stack
	void push(Node * newNode);
	
	// it checks if the stack is empty or not. 
	bool isEmpty();
	
	// it copies the top node on stack,
	// without deleting it. 
	Node * peek();
	
	// it copies the top node on stack, 
	// and deletes the node from stack. 
	Node * pop();
};

#endif