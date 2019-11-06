#include<iostream>
#define MAX 10
using namespace std;

/*  function to print input errors  */
void printerror(string err="\nInvalid input, enter again:")
{
	cin.clear();
	cin.ignore(100,'\n');
	cout << err;
}//printerror()

class Queue
{
	int queue[MAX];		//queue array
	int first;			//index of first element
	int last;			//index of last element

public:
	Queue()	{ first = last = -1; }

	void enque(int);
	int deque();
	void print();
	bool isEmpty();
	bool isFull();
};

int main()
{
	Queue q;		//queue
	int choice;
	int element;
	
	while(true)
	{
		system("clear");
		cout << "\n\t\t\t<----- QUEUE USING CIRCULAR ARRAY----->";

		cout << "\n\nOperations available on queue:\n";
		cout << "\t1. Add an element    [enque]\n";
		cout << "\t2. Remove an element [deque]\n";
		cout << "\t3. Print the queue\n";
		cout << "\t4. EXIT\n";
		cout << "\nEnter your choice :";

		while( !(cin>>choice) || choice < 0 || choice > 4 )  printerror("Invalid choice, enter again: ");

		switch( choice )
		{
			case 1:
				if( !q.isFull() )
				{
					cout << "\nEnter the element: ";
					while( !(cin>>element) )  printerror("Invalid element, enter again: ");
					q.enque(element);
					cout << "\n\n" << element << " added to the queue.";
				}
				else	cout << "\n[!] Queue full";
				break;

			case 2:
				if( !q.isEmpty() )
				{
					element = q.deque();
					cout << "\n\n" << element << " removed from the queue.";
				}
				else	cout << "\n\n[!] Current queue empty!";
				break;
				
			case 3:
				if( !q.isEmpty() )
				{
					cout << "\n\nCurrent queue is:\t";
					q.print();
				}
				else	cout << "\n\n[!] Current queue empty!";
				break;

			case 4:
				return 0;	
		}

		cout << "\n\nPress ENTER to continue ...";
		cin.ignore(100,'\n');
		char ch = getchar();
	}//while(true)

	return 0;
}

bool Queue:: isEmpty()
{
	if( first == -1 )	return true;
	return false;
}

bool Queue:: isFull()
{
	if( first == 0 && last == MAX-1 || first == last+1 )	return true;
	return false;
}


void Queue:: enque(int element)
{
	if( !isFull() )
	{
		if( last == MAX-1 &&  first != 0 )	last = -1;
		queue[++last] = element;
		if(first == -1)	first = last;
	}
}

int Queue:: deque()
{
	int del_element = queue[first++];
	
	if( first == last+1 )	first = last = -1;
	else if( first == MAX )	first = 0;

	return del_element;	
}

void Queue:: print()
{
	for( int i=first; ; i++)
	{
		if( i == MAX )	i = 0;
		cout << queue[i] << ' ';
		if( i == last )		break;
	}
}