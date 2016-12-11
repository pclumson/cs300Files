// OCTOBER 31 2016
// PRINCE CLUMSON-EKLU  H888A642
// PROGRAMMING 05


#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include <stack>      // Provides the stack template class
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
double read_and_evaluate(istream& ins);


void evaluate_stack_tops(stack<double>& numbers);
// Precondition: The top of the operations stack contains + - * or /, and the
// numbers stack contains at least two numbers.


int main( )
{
    double answer;

    cout << "*****PLEASE TYPE IN YOUR FULL POSTFIX EXPRESSION:****" << endl;
    cout << "********INPUT MUST BE SEPERATED BY SPACE !:**********" << endl;
    answer = read_and_evaluate(cin);
    cout << "***YOUR POSTFIX EXPRESSION EVALUATED TO :  " << answer << endl;
    

    return EXIT_SUCCESS;
}


double read_and_evaluate(istream& ins)
// Library facilities used: cstring, iostream, stack
{
    const char DECIMAL = '.';
    // Declaration of stack double that will hold all the numbers.
    stack<double> numbers;
    //stack<char> operations;
    double number;
    char symbol;
    
    // Loop continues while istream is not “bad” (tested by ins) and next character isn’t newline.
    while (ins && ins.peek( ) != '\n')
    {
        if (isdigit(ins.peek( )) || (ins.peek( ) == DECIMAL))
        {
            ins >> number;
            numbers.push(number);
        }
        
        else if (strchr("+-*/", ins.peek( )) != NULL)
        {
            ins >> symbol;
             double operand1, operand2;
             if ( numbers.size ()>= 2 )
                {
    		     operand2 = numbers.top( );
    		     numbers.pop( );
    		     operand1 = numbers.top( );
    		     numbers.pop( );
                }
    
            switch (symbol)
    		{
        		case '+': numbers.push(operand1 + operand2);
                  break;
        		case '-': numbers.push(operand1 - operand2);
                  break;
        		case '*': numbers.push(operand1 * operand2);
                  break;
        		case '/': numbers.push(operand1 / operand2);
                  break;
    		}
            
        }
        
        else
            ins.ignore( );
    }
         if ( numbers.size () > 1)
          {
          cout<< " You have entered incorrect input format for postfix expression"<<endl;
          cout<< " PLEASE CHECK THE POSTFIX EXPRESSION AND TRY AGAIN "<<endl;
          cout << "***THERE IS ERROR IN EVALUATING YOUR POSTFIX EXPRESSION:" << endl;
          }

    return numbers.top( );
}

