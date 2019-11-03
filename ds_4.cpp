/*
	Q. Perform the following Stack operations using Linked List implementation
		a) Push
		b) Pop
		c) Clear
*/

#include<iostream>
using namespace std;

//function to print input errors
void printerror(string str="\nInvalid input, enter again :")
{
    cin.clear();
    cin.ignore(100,'\n');
    cout << str ;
}//printerror()

//NODE CLASS
template <class t>
class StackNode
{
public:

	t info;
	StackNode *next;

	StackNode( int data )
	{
		info = data;
		next = NULL;
	}
};

//STACK CLASS
template <class T>
class Stack
{    
    StackNode <T> *top;                    // pointer to the top node

    public :
    Stack() { top = NULL; }
    
    bool isEmpty()              //to check if the stack is empty
    {
		return ( top == NULL )? true : false ;
    }

    void push( T element )      //to push an element in the stack
    {
		if( top == NULL )
		{
			top = new StackNode<T>(element);
			return;
		}

		else
		{
			StackNode <T> *p = new StackNode<T>(element);
			p->next = top;
			top = p;
		}		
	}//push()

    T pop()                  //to pop an element from the stack
    {
		if( top == NULL )
		{
			return NULL;
		}

		else
		{
			T node_info = top->info;
			StackNode <T> *p = top;
			top = top->next;
			delete(p);
			return node_info;		
		}		
    }//pop()

	void clear()
	{
		StackNode <T> *p = top;
		StackNode <T> *temp;

		while( p != NULL )
		{
			temp = p->next;
			delete(p);
			p = temp;
		}
	}
};//End of Stack class

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