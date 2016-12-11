/* CS300 Extra Credit- Infix to Postfix
 * PRINCE CLUMSON-EKLU  H888642
 * Last Update: 10/31/2016
 * 
 */


#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include <stack>      // Provides the stack template class
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
bool read_and_evaluate(istream& ins);


bool evaluate_stack_tops(stack<char>& symbols);



int main( )
{
    
	
    cout << "PLEASE TYPE IN YOUR INFIX EXPRESSION TO BE CONVERTED :" << endl;
    
    if (read_and_evaluate(cin))
    {
		 cout<<  endl;
		cout << "YOUR INFIX EXPRESSION HAVE BEEN EVALUATED TO POSTFIX :"  << endl;
		
	}
	else
	
		cout<<"Invalid expression"<<endl;
    return EXIT_SUCCESS;
}


bool read_and_evaluate(istream& ins)
// Library facilities used: cstring, iostream, stack
{
    const char DECIMAL = '.';
    double number;
    char symbol;
    stack<char> symbols;
    
    // Loop continues while istream is not "bad" (tested by ins) and next character isn't newline.
    while (ins && ins.peek( ) != '\n')
    {
		//display numbers
        if (isdigit(ins.peek( )) || (ins.peek( ) == DECIMAL))
        {
            
            ins >> number;
            cout<<number<<" ";
            
            
        }
        //push operators to the stack
        else if (strchr("+-*/", ins.peek( )) != NULL)
        {
            ins >> symbol;
            symbols.push(symbol);
            //eval. oparators
            if (!evaluate_stack_tops(symbols))
				return false;
        }
        //ignore extra characters
        else
            ins.ignore( );
        
    }
    //check to see if symbol stack is empty
	if (symbols.size() >= 1)
	{	
		char temp;
		
		while (symbols.size() >= 1)
		{
				temp = symbols.top();
				symbols.pop();
				cout<<temp<<" ";
		}
		
		return true;
	}
	
	
	else
		return false;
		
    
}

bool evaluate_stack_tops(stack<char>& symbols)
// Library facilities used: stack
{
    
    //check it theres atleast 2 symbols to compare
	if (symbols.size() == 1)
		return true;
		
	//compare symbols
    else if (symbols.size()>1)
    {
		char operand1, operand2;

		operand2 = symbols.top( );
		symbols.pop( );
		
		operand1 = symbols.top( );
		symbols.pop( );
		
		
		if (operand2 == '-' || operand2 == '+')
			operand2 = 1;
			
		else if (operand2 == '*' || operand2 == '/')
			operand2 = 2;
			
		if (operand1 == '-' || operand1 == '+')
			operand1 = 1;
			
		else if (operand1 == '*' || operand1 == '/')
			operand1 = 2;
		
		if (operand2 > operand1)
		{
				symbols.push(operand1);
				symbols.push(operand2);
		}	
			
		else if (operand2 == operand1 || operand2 < operand1)
		{
				cout<<operand1<<" ";
				symbols.push(operand2);
		}
		
		
		return true;
    }
   
	else
		return false;
    
}

