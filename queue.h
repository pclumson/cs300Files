// this is header file for array based queue implementation


#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#define CAPACITY 50

class Queue
{
private:
	int head;
	int tail;
	int count;
	int array[CAPACITY];
	
public:
	Queue();	// default constructor
	~Queue() {}
	bool isEmpty() 	{return count == 0;}
	bool isFull()	{return count == CAPACITY;}
	
	// pre-condition: the queue must not be full
	void enqueue(int newNumber);
	
	// pre-condition: the queue must not be empty
	int dequeue();
};

#endif