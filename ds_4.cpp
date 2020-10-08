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

//NEW CODE
//cpp

#include<bits/stdc++.h>
using namespace std;
template <class t>
class SLLNode
{
public:
t info;
SLLNode*next;

SLLNode()
{
info = 0;
next = NULL;
}

SLLNode(t element)
{
info = element;
next = NULL;
}

};

template <class t>
class SLLList
{
public:
SLLNode<t> *head;
SLLNode<t> *tail;


SLLList()
{
head = NULL; // 0
tail = NULL; // 0
}

void insertatHead(t element)
{
SLLNode<t> * N = new SLLNode<t>(element);

if(head==NULL)
{
head = N;
tail = N;
}

else
{
N->next = head;
head = N;
}
}

void del()
{
if(head==NULL) //list is empty
{
return;
}

else if(head == tail) //list has one element
{
delete(head);
head=NULL;
tail=NULL;
}

else
{
SLLNode<t> *temp= head;
head = head->next;
delete(temp);
}
}

void traverse()
{

SLLNode<t> *temp;
temp =  head;
while(temp != NULL)
{
cout<<temp -> info <<"--> ";
temp = temp->next;
}
}
};

template<class t>
class Stack
{
   public:
   SLLList<t> SL;

Stack()
{
SL.head = NULL;
}

void push(t element)
{
SL.insertatHead(element);
}

void pop()
{
SL.del();
}

t top_element()
{
return SL.head->info;
}

bool is_empty()
{
if(SL.head == NULL)
return true;
else
return false;
}

void display()
{
    SL.traverse();
}

void stack_menu(t element)
{
int option;

do
{
cout<<"\n\n ** MENU **\n";
cout<<"Press 1. PUSH\n";
cout<<"Press 2. POP\n";
cout<<"Press 3. DISPLAY\n";
cout<<"Press 4. TOP_ELEMENT\n";
cout<<"Press 5. IS_EMPTY\n";
cout<<"Press 6. EXIT\n";
cout<<"Enter Option: ";
cin>>option;

switch(option)
{
case 1: t element;
cout<<"Enter Element: ";
cin>>element;
push(element);
break;

case 2: pop();
break;

case 3: display();
break;

case 4: cout<<"Top Element is: ";
cout<<top_element();
break;

case 5: cout<<"Stack ";
if(is_empty() == 1)
{
cout<<"is empty";
}
else
cout<<"is not empty";
break;

case 6: cout<<"\nExiting";
exit(0);

default: cout<<"\nInvalid input";
      break;
}
}while(option!=6);
}
};

void type_menu()
{
cout<<"\n\n\tTYPES\n";
cout<<"1. Int \n";
cout<<"2. Char \n";
cout<<"3. Float\n";
cout<<"4. Long \n";
cout<<"Enter Choice: ";

}

int main()
{
int choice;

type_menu();
cin>>choice;
cout<<endl;

if(choice==1)
{
int element;
Stack<int> sk;
sk.stack_menu(element);
}

else if(choice == 2)
{
char element;
Stack<char> sk;
sk.stack_menu(element);
}

else if(choice==3)
{
float element;
Stack<float> sk;
sk.stack_menu(element);
}

else if(choice==4)
{
long element;
Stack<long> sk;
sk.stack_menu(element);
}

else
{
cout<<"Invalid Input";
}
return 0;
}
