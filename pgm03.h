// This program is an application of linked list.
// It is a mgmt program for book list. 
// It uses BookNode as node, BookList as linked list.
// Writtern by: PRINCE CLUMSON-EKLU  H888A642
// Last modified date: Oct 10, 2016


#ifndef world_PGM_03_H_hello
#define world_PGM_03_H_hello

#include <string>
using namespace std;

/* 
 * class definition for BookNode
 * which is node-compatible
 * i.e. it has a pointer to next BookNode.
 */
class BookNode {
private:
	std::string bookTitle;
	BookNode * next;
	// std::string bookDescription;
	// int bookQuantity;
	// double bookUnitPrince;
	
public:
	// default constructor
	// TO_DO: add new fileds to constructor
	BookNode(){bookTitle = ""; next = NULL;}
	
	// custom constructor
	// it initializes bookTitle with title
	//TO_DO: add new fields to constructor
	BookNode(string title){bookTitle = title; next = NULL;}
	
	// getter functions
	std::string getTitle(){return bookTitle;}
	BookNode * getNext(){return next;}
	//TO_DO: add getters for new fields
		
	// setter functions
	void setTitle(std::string newTitle) {bookTitle = newTitle;}
	void setNext(BookNode * newNext) {next = newNext;}
	//TO_DO: add new setters for new fields
};

/* 
 * class definition for BookList
 * which is a linked list that uses object of BookNode as node.
 * it has only one variable: head, which is a BookNode pointer.
 */
class BookList {
private:
	BookNode * head;
public: 
	// default constructor
	BookList(){head = NULL;}
	
	// destructor, which will be called automatically
	// it deletes all nodes in the linked list
	~BookList();
	
	// add new node as first node of linked list
	void addFirst(BookNode *);
	
	// add new node as last node of linked list
	void addLast(BookNode *);
	
	// traverse function, which will print out BookNode info
	void traverse();
	
	// test if the given book is in the list.
	bool isInTheList(std::string);
	
	// delete the given book
	// return true if found and deleted
	// return false if not found.
	bool deleteBook(std::string);
};

#endif