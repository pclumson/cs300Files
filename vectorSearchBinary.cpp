#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

bool searchNumber(vector<int>, int);

int main()
{
	vector<int> vec;
		
	// read 10000 numbers to hash table
	int number = 0 ; 
	for (int i = 0; i < 100000; i ++)
	{
		cin >> number;
		vec.push_back(number);
	}
	
	// sort the vector before binary search
	std::sort(vec.begin(), vec.end());
	
	
	// calc elapsed time on searching 
	const clock_t begin_time = clock();

	// search 10000 target numbers in vector
	int found = 0;
	int notFound = 0;
	for (int i = 0; i < 100000; i ++)
	{
		cin >> number;
		// searchNumber(vec, number) ? found++ : notFound++ ;
		std::binary_search (vec.begin(), vec.end(), number) ? found++ : notFound++ ;
	}
	
	// output result
	cout << "Found:\t\t" << found << endl;
	cout << "Not Found:\t" << notFound << endl;

	// calc elapsed time on searching
	cout << "Running time:\t" << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;



	return 0;
}

bool searchNumber(vector<int> vec, int target)
{
	if (vec.size() > 0)
	{
		for (vector<int>::const_iterator ci = vec.begin();
				 ci != vec.end();
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