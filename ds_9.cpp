/*
    Q. WAP to evaluate postfix expression using stack.
    The Program currently works on only 1 digit numbers
*/

#include<iostream>
#include<cmath>
#include<cctype>
#include "stacktemplate.cpp"
using namespace std;

bool isOperator(char c);                //to check if given char is an operator
bool isOperand(char c);                 //to check if given char is an operand
int parseInt(char c);                   //to convert char to int (acc. to ascii value);
int operation(int a,int b, char op);    // to perform the given operation

int main()
{
    Stack <int> stack;
    string postfix;
    char c;
    int result = 0, i = 0;

    cout << "\n\t<-- Evaluating Postfix expressions using Stack -->\n";
    cout << "\nEnter the postfix expression : ";
        cin >> postfix ;

    while( (c = postfix[i++]) != '\0' )
    {
        if( isalpha(c) )
        {
            cout << c << '=' ;
            while( !(cin>>c) || !isOperand(c) )     printerror("\nNot a valid value, enter again :");
            postfix[i-1] = c ;
        }
    }

    i = 0 ;

    while( (c = postfix[i++]) != '\0' )
    {
        if( isOperand(c) )
            stack.push( parseInt(c) );

        else if( isOperator(c) )
        {
            int a = stack.topel() ;
            if( !stack.pop() )
            {
                cout << "\nInvalid postfix expression!\n";
                exit(1);
            }
            int b = stack.topel() ;
            if( !stack.pop() )
            {
                cout << "\nInvalid postfix expression!\n";
                exit(1);
            }

            result = operation(b,a,c);
            stack.push( result );
        }

        else
        {
            cout << "\nYour expression contains invalid operands/operators!\n";
            exit(1);
        }
    }
    cout << "\nThe result is : " << result << endl ;
    return 0;
}

int parseInt( char c )
{
    if( c >= '0' && c <= '9' )
        return ( (int) c ) - 48 ;
    else
        return -1;
}

bool isOperator( char c )
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
                return true;
        default :
                return false;
    }
}//isOperator()

bool isOperand(char c)
{
    if( c >= '0' && c<='9' )    return true;
    else                        return false;
}//isOperand()

int operation( int a , int b , char op )
{
    switch(op)
    {
        case '+':   return a + b ;
        case '-':   return a - b ;
        case '*':   return a * b ;
        case '/':   return a / b ;
        case '^':   return pow(a,b);
        default :   return 0;
    }
}
