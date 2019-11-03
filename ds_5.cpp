/*
	Q. Perform the following Stack operations using Array implementation using templates:
		a) Push
		b) Pop
		c) Clear
*/

#include<iostream>
#define MAX 50
using namespace std;

//function to print input errors
void printerror(string str="\nInvalid input, enter again :")
{
    cin.clear();
    cin.ignore(100,'\n');
    cout << str ;
}//printerror()

template <class T>
class Stack
{
    T stack[MAX];               //stack array
    int top;                    //index of stack top

    public :
    Stack() { top = 0; }

    bool isFull()               //to check if the stack is full
    {
        if( top >= MAX - 1 )
            return true;
        else
            return false;
    }

    bool isEmpty()              //to check if the stack is empty
    {
        if( top <= 0 )
            return true;
        else
            return false;
    }

    bool push( T element )      //to push an element in the stack
    {
        if( !isFull() )
        {
            stack[top++] = element ;
            //top++;
            return true;
        }
        else
            return false;
    }

    bool pop()                  //to pop an element from the stack
    {
        if( !isEmpty() )
        {
            top--;
            return true;
        }
        else return false;
    }

    T topel()                   //to return the topmost element of the stack
    {
        if( !isEmpty() )
            return stack[top-1] ;
        else
            return NULL;
    }

    void revstack()             //to reverse the stack contents
    {
        for( int i=0; i < (top/2); i++ )
        {
            T temp = stack[i];
            stack[i] = stack[top-1-i];
            stack[top-1-i] = temp;
        }
    }
	
	void clear()
	{
		while( !isEmpty() ) pop();
	}
};
//End of Stack class

int main()
{
	Stack <int> stack;
	int choice,data;

 while(1){
	system("clear");

	cout << "\n\t<--- Stack using Linked List --->\n";
    cout << "\nOperations available are :\n";
    cout << "\t1. Add new element [push]\n";
	cout << "\t2. Delete an element [pop]\n";
    cout << "\t3. Clear the stack [clear]";
    cout << "\t4. EXIT";
    cout << "\nEnter your choice :";
    while( !(cin>>choice) || choice<=0 || choice>4 )     printerror("Invalid choice, enter again :");

    if( choice == 1 )
	{
		cout << "\nEnter the element: ";
		while( !(cin>>data) ) printerror("Invalid element, enter again: ");

		stack.push(data);
		cout << "\nDONE!\n";		
	}

	else if( choice == 2 )
	{
		if( stack.pop() )	cout << "\nDone!";
		else				cout << "\n[!] Stack empty!\n";
	}
	
	else if( choice == 3 )
	{
		stack.clear();
		cout << "\nDone!\n";
	}

	else	return 0;

	cout << "\n\n\nPress ENTER to continue ...";
	cin.ignore(100,'\n');
	char ch = getchar();
 	}//while

	return 0;
}