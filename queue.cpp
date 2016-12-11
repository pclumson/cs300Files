// this is the implementation file for queue

#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue()
{
	head = 0;
	tail = 0;
	count = 0;
}


void Queue::enqueue(int newNumber)
{
	array[tail] = newNumber;
	tail = (tail + 1) % CAPACITY;
	count++;
}

int Queue::dequeue()
{
	int result = array[head];
	head = (head + 1) % CAPACITY;
	count--; 
	return result;
}


int main()
{
	Queue queue;
	
	cout<<"Is the queue empty: "<< queue.isEmpty()<<endl;
	
	cout<<"Is the queue full: "<< queue.isFull()<<endl;

for (int j = 0 ; j < 10; j++)
{	
	for (int i = 0; i < 20; i++)
	{
		if(!queue.isFull())
			queue.enqueue(i);
		
	}
	
	for (int i = 0; i < 20; i++)
	{
		cout<<"Dequeue ... ";
		if(!queue.isEmpty())
			cout<<queue.dequeue()<<endl;
	}
}	
	
	return 0;
}