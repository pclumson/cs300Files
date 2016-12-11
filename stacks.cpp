// implementation for the stack : EXTRA CREDIT
// PRINCE CLUMSON-EKLU  
//LAST MODIFIED : 10/19/2016
 
 
#include <iostream>
#include <stack>


using namespace std;
 
int main()
{
	
	std::stack<int>mystack ;
	
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
	    mystack.push(reminder);
	  
	    
	    
	   }
	  
	while(!mystack.isEmpty())
	   {
	     std::cout <<'  '<<mystack.top();
	     mystack.pop();
	    cout<<mystack.pop()<<endl;
	    
	    }
	  cout<< "************************************************"<<endl;
	std::cout<<'\n';
	}
	return 0;
}
