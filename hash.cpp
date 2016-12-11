// This is cpp file for CS 300 hash table program. 
// It takes 100,000 integers from cin (using Linux I/O redirection), 
//   make a hash table and read and search another 100,000 integers
// Written by: PRINCE CLUMSON EKLU  H888A642  11/ 28 /2016


#include <iostream>
#include <ctime>
#include <vector>
#include <list>

using namespace std;


bool searchNumber(vector< list<int> > &, int);

int main()
{

	// hash table container: 	vector
	// hash table size:			100003
	// hash table size is about three times of size of input (10000)
	// hash table size, 100003 is a prime number for better hashing
	// collision handle:		STL list 			
	
	vector < list<int> > hashTable (100003);
		
	// read 100000 numbers to hash table
	int number = 0 ; 
	for (int i = 0; i < 100000; i ++)
	 {
		cin >> number;

		// TO_DO:
		
		// calc the index using hash function, which is number % 100003
		 
		
		
	// vector[index].push_back() function to push number into that index's linked list
		hashTable[ number % 100003].push_back(number);
        
     }
   
	

	// calc elapsed time on searching 
	const clock_t begin_time = clock();
	
	// search 10000 target numbers in hash table
	int found = 0;
	int notFound = 0;
	for (int i = 0; i < 100000; i ++)
	{
		cin >> number;
		searchNumber(hashTable, number) ? found++ : notFound++ ;
	}
	
	// output result
	cout << "Found:\t\t" << found << endl;
	cout << "Not Found:\t" << notFound << endl;
	
	// calc elapsed time on searching
	cout << "Running time:\t" << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;

	return 0;
}


// searchNumber returns true if target number can be found, 
// returns false if cannot be found. 
// para:
// - hashTable,	type: vector <  list<int> > &
// - target,	type: int
bool searchNumber(vector< list<int> > & hashTable, int target)

{

      int index = target % 100003;
      
     
	if (hashTable[index].size() > 0)
	{
		for (list<int>::const_iterator ci = hashTable[index].begin();
				 ci != hashTable[index].end();
				 ci ++
			)
		{
			if ( (*ci) == target )
				return true;
		}
		
		return false;
	
	}
	else 
		return false;

}
	


