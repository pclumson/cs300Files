/* This is for CS 300 pgm 02
 * PRINCE CLUMSON-EKLU & H888A642
 * Last update: 09/22/2016
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>		// for numeric_limits<streamsize>::max()


#include "pgm02.h"		// Note: use double quote to include pgm02.h

/*
 * Memeber functions for class Part__begin
 */
void Part::printPart()
{
	std::cout<<"Part #: \t"		<<partNum		<<std::endl;
	std::cout<<"Description: \t"<<description	<<std::endl;
	std::cout<<"Quantity: \t"	<<quantity		<<std::endl;
	std::cout<<"Unit Price: \t"	<<unitPrice		<<std::endl;
}
/*
 * Memeber functions for class Part__end
 */
////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Member functions for class ArrayList__begin
 */
bool ArrayList::addElement(ArrayList::value_type newElement)
{
	if (count < ARRAY_CAPACITY)
	{
		array[count] = newElement;
		count++;
		return true;
	}
	else 
		return false;	

}

bool ArrayList::deleteElement(int index)
{
	if (index < count)
	{
		for (int i = index; i < count - 1; i ++)
		{
			array[i] = array[i + 1];
		}
		count--;
		return true;
	}
	else 
		return false;
}

// pre-condition for getElement(): index must be in range, i.e. less than count
ArrayList::value_type ArrayList::getElement(int index)
{
	return array[index];
}

// pre-condition for setElement(): index must be in range, i.e. less than count
void ArrayList::setElement(int index, ArrayList::value_type newElement)
{
	array[index] = newElement;
}

int ArrayList::getCount()
{
	return count;
}

void ArrayList::printList()
{
	for (int i = 0; i < count; i++)
	{
		std::cout<<"--------"<<std::endl;
		array[i].printPart();
	}
}
/*
 * Member functions for class ArrayList__end
 */



/*
 * functions for Program 02
 */
 
int printMenuGetUserChoice();
void readFileToArrayList(ArrayList&);
void addNewPart(ArrayList&);
void modifyPart(ArrayList&);  // TO_DO: declare modify part function.
void deletePart(ArrayList&);// TO_DO: declare delete part function.
void printTotalPart(ArrayList&);// TO_DO: declare print total function.
void writeToFile(ArrayList& partList);

int main()
{
	// first thing first: we need an object of class ArrayList
	ArrayList partList;
	
	// read file into arrayList 
	readFileToArrayList(partList);

	
	
	int choice = printMenuGetUserChoice();
	while (choice != 6)	// if choice == 6, then save file and exit program.
	{
		switch (choice)
		{
		case 0:
			cout<<"Invalid choice Please choose between 1 and 6."<<endl;
			break;
		case 1: 
			partList.printList();
			break;
		case 2:
			addNewPart(partList);
			break;
		case 3:
			// TO_DO: modify part function.
			modifyPart(partList);
			break;
		case 4:
			// TO_DO: delete part function.
			 deletePart(partList);
			break;
		case 5:
			// TO_DO: print total inventory total function.
			printTotalPart(partList);
			break;
		default:
			break;	
		}
		
		// prompt user to enter choice again. 
		choice = printMenuGetUserChoice();
	}	
	
	// TO_DO: write parts from partList to inventory.txt file.
	
	
	return 0;
}

void writeToFile(ArrayList& partList)
	
  {
       ofstream output;
       output.open("inventory.txt", ios::out);
       for(int i = 0; i < partList.getCount(); i++)
           {
                 // partList holds all part objects
                 // we need to get part out. 
                 // here is how to get part out: 
                  Part tempPart = partList.getElement(i);
                 // remeber we are not directly touching array, 
                 // so we use this getElement() function.


                 // now we have tempPart, 
                 // we need to get partNumber, description, quantity and unitPrice out
                 // and we need to call getters from tempPart to do this. 
                 int pn = tempPart.getPartNum();
                 string desc = tempPart.getDescription();
                 int quan = tempPart.getQuantity();
                 float up = tempPart.getUnitPrice();
                // that is why these functions are called getters: they get stuff for you.
 
                // now we have each piece info ready. Let's write to the file.
                     output << pn << endl;
                     output << desc << endl;
                     output << quan << endl;
                     output << up << endl;
 
               // almost done. remeber to close file after loop.
             }
 
                     output.close();
     }
	

	
int printMenuGetUserChoice()
{
	int choice = 0;
	
	cout<<"Welcome to Tiny Part Mgmt"<<endl;
	cout<<"********************"<<endl;
	cout<<"1. Print the part"<<endl;
	cout<<"2. Create a new part"<<endl;
	cout<<"3. Modify a part"<<endl;
	cout<<"4. Delete a part"<<endl;
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


// please note the & followed ArrayList: we use reference of partList,
//   so that changes made to partList will be made. 
void readFileToArrayList(ArrayList& partList)
{
	std::fstream file("inventory.txt", std::ios::in);
	if(file)
	{
		int partNum = 0;
		std::string description = "";
		int quantity = 0;
		float unitPrice = 0;
		
		// use a loop to keep reading file.
		// if reading file fails, the loop will end
		while(file >> partNum)
		{
			file.ignore(2);
			std::getline(file, description);
			file >> quantity;
			file >> unitPrice;	
			
			// now create a Part object, and add to ArrayList object
			// Part object is created by constructor
			// Part object is added by calling addElement() of ArrayList object.
			Part onePart(partNum, description, quantity, unitPrice);
			partList.addElement(onePart);
		}	
	}
	else
	{
		std::cout<<"Error when reading from file \"inventory.txt\""<<std::endl;
	}
	
	// close file when done
	file.close();
}

void addNewPart(ArrayList& partList)
{
	int partNum = partList.getCount();
	std::string description = "";
	int quantity = 0;
	float unitPrice = 0;
		
	cout<<"New Part Number: "<<partNum<<endl;
	cout<<"Description: ";
	getline(cin, description);
	cout<<"Quantity: ";
	cin>>quantity;
	cout<<"Unit Price: ";
	cin>>unitPrice;
		
	Part newPart(partNum, description, quantity, unitPrice);
	
	partList.addElement(newPart);
		
}

// TO_DO: implement modify part function
void modifyPart(ArrayList& partList)
{
	cout<<"please enter part number to modify :";
	int partNumber;
	cin>>partNumber;

	Part tempPart;
	if( partNumber , partList.getCount() )
	tempPart = partList.getElement(partNumber);

	cout<<"Enternew Description :";
	string newDesc ;
	cin.ignore();
	getline(cin,newDesc);
	tempPart.setDescription(newDesc);
	cout<<"Enter new quantity";
	int quantity;
	cin>>quantity;
	tempPart.setQuantity(quantity);
	// do the same for unitPrice
	partList.setElement(partNumber,tempPart);

}


// TO_DO: implement delete part function
void deleteElement( partList[], int size) {
	system("cls");
	cout <<"Enter Item you wish to remove from your inventory: " << endl;// This is being displayed so user can see items in the inventory
	double cost = 0;
  
  if(size < 1) {
    cout << "Nothing to display" << endl;
  } else {
    cout << "All Items in your inventory" << endl << endl;
    cout << fixed << setprecision(2);   
    cout << "Item Name              Qty     Value" << endl;// It is not displaying right the alignment is off
    cout << "~~~~~~~~~~~~~~~~~~" << endl;
	/* from here I do not know what to do! What I want is have use type the item name they want removed
							also display an error if they enter an  item wrong*/
    cout << left;     
    for (int i = 0; i < size; i++) {
      cout << setw(21) << list[i].name << right
           << setw(4)  << list[i].qty
           << setw(10) << list[i].value << left << endl;
           cost = cost + list[i].value * list[i].qty;
	
    
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << right << setw(3) << size;
    cout << " items listed";
    cout << right << setw(19) << cost << endl << endl;

   

	}}}

// TO_DO: implement print total function
subTotal();