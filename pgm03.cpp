// This program is an application of linked list.
// It is a mgmt program for book list. 
// It uses BookNode as node, BookList as linked list.
// Writtern by: PRINCE CLUMSON-EKLU H888A642
// Last modified date: Oct 10, 2016


#include <iostream>
#include <string>
#include "pgm03.h"

using namespace std;

/*
 * Implementation for class BookList STARTS HERE
 */
void BookList::addFirst(BookNode * book)
{
	book->setNext(head);
	head = book;
}

void BookList::addLast(BookNode * book)
{
	if (!head)
	{
		addFirst(book);
	}
	else
	{
		BookNode * temp = head;
		while(temp->getNext() != NULL)
		{
			temp = temp->getNext();
		}
		temp->setNext(book);
	}
}

void BookList::traverse()
{
	BookNode * temp = head;
	while(temp != NULL)
	{
		std::cout<<temp->getTitle()<<std::endl;
		//TO_DO: print out all info about the book
		
		temp = temp->getNext(); 
	}
}
bool BookList::isInTheList(std::string title)
{
	BookNode * temp = head;
	while(temp != NULL)
	{
		if (temp->getTitle() == title)
			return true;
		temp = temp->getNext(); 
	}
	return false;
}

bool BookList::deleteBook(std::string title)
{
	if(!head)
	{
		return false;
	}
	
	BookNode * prev = NULL;
	BookNode * cur = head;
	
	if (cur->getTitle() == title)
	{
		head = head->getNext();
		delete cur;
		return true;
	}
	
	while (cur != NULL && cur->getTitle() != title)
	{
		prev = cur;
		cur = cur->getNext();
	}
	
	if (cur == NULL)
		return false;
	else 
	{
		prev->setNext(cur->getNext());
		delete cur;
		return true;
	}
}

BookList::~BookList()
{
	while(head != NULL){
		string tempTitle = head->getTitle();
		deleteBook(tempTitle);
		cout<<"Book "<<tempTitle<<" has been deleted. "<<endl;
	}
}
/*
 * Implementation for class BookList ENDS HERE
 */


int printMenuGetUserChoice()
{
	int choice = 0;
	cout<<"********************"<<endl;
	cout<<"  ****************"<<endl;
	cout<<"    *************"<<endl;
	cout<<"      *********"<<endl;
	
	cout<<"Welcome to our Bookstore ! Please make a selection:"<<endl;
	cout<<"********************"<<endl;
	cout<<"1. addBookToFirst"<<endl;
	cout<<"2. addBookToLast"<<endl;
	cout<<"3. Find a book in our store"<<endl;
	cout<<"4. DeleteBook"<<endl;
	cout<<"5. Print total"<<endl;
	cout<<"6. Exit the program"<<endl;
	cout<<"Please make a choice: ";	
	
	if(cin >> choice)	// make sure cin succeed, i.e. user input a integer.
	{
		if (choice > 0 && choice < 7)
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


int main()
{
	// create the object of BookList first.
	// booklist is created statically.
	// HAS TO HAVE OBJECT to call member functions from class.
	
	BookList booklist;

	int choice = printMenuGetUserChoice();
	while (choice != 6)	// if choice == 6, then save file and exit program.
	{
	    
	   
		switch (choice)
		{
		
		case 1: 
		      // This will add book to the first node
		  {
			string tempTitle = "";
			cout<<"Please enter Book Title to be add to first node: ";
			getline(cin, tempTitle);
			
			//TO_DO: also ask for description, quantity, unit price then 
		
		
			// Dynamic memory: create the BookNode dynamically by using keyword new
			
			// TO_DO: call modified constructor
	        BookNode * bn1 = new BookNode(tempTitle);
	       	booklist.addFirst(bn1);
	       

	
			break;
		  }
		case 2:
		      // This will add book to the last node
		  {
		       string tempTitle = "";
			cout<<"Please enter the book title to append to last node: ";
			getline(cin, tempTitle);
			
			//TO_DO: also ask for description, quantity, unit price then 


			// Dynamic memory: create the BookNode dynamically by using keyword new
			
			// TO_DO: call modified constructor

	        BookNode * bn1 = new BookNode(tempTitle);
	       	booklist.addLast(bn1);
	       

	
			break;
	       
		    
		  }
		case 3:
			// This will find the book in the list
			{
			    string tempTitle = "";
			cout<<"Please enter the Title of the book you to find: ";
			getline(cin, tempTitle);
			// Dynamic memory: create the BookNode dynamically by using keyword new
	        if (booklist.isInTheList(tempTitle))
	        	cout<<" Yahoo !!!  Your book is in the list!"<<endl;
	        else
	        	cout<<"Oh sorry ,we could not find your book  in the list."<<endl;
	       
			}
			
			
			break;
		case 4:
			// This will delete a book in the list
			{
			    string tempTitle = "";
			cout<<"Please enter the Title of the book you to delete: ";
			getline(cin, tempTitle);
			// Dynamic memory: create the BookNode dynamically by using keyword new
	        if (booklist.deleteBook(tempTitle))
	        	cout<<"The book have been deleted !."<<endl;
	        else
	        	cout<<"It is NOT in the list."<<endl;
	        	
	       
			}
			break;
		case 5:
			// TO_DO: print total inventory total function.
			cout<<"********************"<<endl;
			cout<<"Here is the List of Books on hand :"<<endl;
			booklist.traverse();
			
			break;
			
		case 6:
			cout<<" Thank you for visiting our booklist and see you later !"<<endl;
			//exit(0);
			
			
		default:
			return 0;
			break;
		}
		choice = printMenuGetUserChoice();

	}		
}
			
	
	
	
	
	
	

