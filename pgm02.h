/* Header file for CS 300 program 02
 * 
 * 
 *
 * 
 *
 * Last modified: 09/27/2016
 */
 

#include <string>

using namespace std;

#define ARRAY_CAPACITY 100

class Part 
{
public: 
	// default constructor must be presented if you have custom constructor
	Part(){}
	
	// custom constructor, which initialize all varialbes in part
	Part(int pn, string desc, int quan, float up)
	{
		partNum = pn;
		description = desc;
		quantity = quan;
		unitPrice = up;
	}
	
	// printPart() will print all information for a part
	void printPart();

	// subTotal() will return the sub-total for this kind of part.
	float subTotal(){return quantity * unitPrice;}
	
	// getter and setter function for each variable in part
	// setter and getters are simple functions that returns value to caller, 
	//   or set new value for variables. 
	int		getPartNum(){return partNum;}
	void 	setPartNum(int newNumber){partNum = newNumber;}
	string 	getDescription(){return description;}
	void 	setDescription(string newDescription){description = newDescription;}
	int 	getQuantity(){return quantity;}
	void 	setQuantity(int newQuantity){quantity = newQuantity;}
	float 	getUnitPrice(){return unitPrice;}
	void 	setUnitPrice(float newPrice){unitPrice = newPrice;}
	
	
private: 
	int partNum;
	string description;
	int quantity;
	float unitPrice;	
	
};

// define class ArrayList
class ArrayList
{
public:
 	
	// type can be easily changed here, and just here. 
	// for program 02 we use Part
	typedef Part value_type;

	// default constructor 
	ArrayList(){count = 0;}
	
	// we don't need copy constructor or custom constructor so far
	
	// addElement() function will add an element at the end. 
	//   return true if success. 
	//   return false if Array List is full.
	bool addElement(value_type newElement);
		
	// deleteElement() function will delete the element given by index. 
	//   return true if deleted.
	//   return false if incorrect index
	bool deleteElement(int index);
	
	// getElement() function will get element on index.
	//   pre-condition: index must be in proper range. 
	//   return the element to caller. 
	value_type getElement(int index);
	
	// setElement() function will set element on index. 
	//   pre-conditionL index must be in proper range. 
	void setElement(int index, value_type newElement);
	
	// getCount() function will return count to caller. 
	int getCount();
	
	// printList() function will travese the list and call print from Part.
	void printList();
	
	
private:
	// two variables will be created here:
	//  1. one array to store elements, with preset capacity
	//  2. one integer to count how many elements in array. 
 	value_type array[ARRAY_CAPACITY];
 	int count;

};
