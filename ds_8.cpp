/*
    Q. WAP to add 2 large integers using stack
*/

#include<iostream>
#include "stacktemplate.cpp"
using namespace std;

void digit_by_digit(Stack <int> &stack);    //for digit by digit entry of inegers

int main()
{
    Stack <int> num1, num2, sum ;
    int digit, i = 0, carry = 0, dsum;

    cout << "\n\t<-- Addition of large integers -->\n";
    cout << "\nEnter the first integer digit by digit (ESC when done) :";
        digit_by_digit(num1);

    cout << "\nEnter the second integer digit by digit (ESC when done) :";
        digit_by_digit(num2);

    while( !( num1.isEmpty() ) && !( num2.isEmpty() ) )
    {
        dsum = num1.topel() + num2.topel() + carry ;

        if( !sum.push( dsum % 10 ) )
        {
            cout << "\nSum stack full!";
        }

        num1.pop();
        num2.pop();
        carry = dsum/10 ;
    }

    if( num1.isEmpty() )
    {
        while( !num2.isEmpty() )
        {
            sum.push( num2.topel() );
            num2.pop();
        }
    }
    else if( num2.isEmpty() )
    {
        while( !num1.isEmpty() )
        {
            sum.push( num1.topel() );
            num1.pop();
        }
    }

    cout << "\nSum : ";

    while( !sum.isEmpty() )
    {
        cout << sum.topel() ;
        sum.pop();
    }
    cout << endl ;

    return 0;
}

void digit_by_digit(Stack <int> &stack)
{
    int digit;
    while( cin >> digit )
    {
        if( cin.fail() )
        {
            cout << "\nNot a valid digit, enter again :";
            cin.clear();
            cin.ignore(100,'\n');
        }
        else
        {
            if( !stack.push(digit) )
            {
                cout << "\nMax number of digits reached!";
                break;
            }
        }
    }
    cin.clear();
    cin.ignore(100,'\n');
}//digit_by_digit()