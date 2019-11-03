/*
	Q. Create and perform the following operations on Queues using Linked List implementation
		a) Enque
		b) Deque
*/

#include<iostream>
using namespace std;

/*  function to print input errors  */
void printerror(string err="\nInvalid input, enter again:")
{
	cin.clear();
	cin.ignore(100,'\n');
	cout << err;
}//printerror()

// NODE CLASS
class QNode
{
public:
	
	int info;
	QNode *next;

	QNode(int data)
	{
		info = data;
		next = NULL;
	}
};

// QUEUE CLASS
class Queue
{
	QNode *head;
	QNode *tail;

	public:

	Queue()
	{
		head = tail = NULL;
	}

	bool isEmpty()
	{
		return ( head == NULL )? true : false ; 
	}

	void enque(int data)
	{
		if( head == NULL )
		{
			head = tail = new QNode(data);
			return;
		}

		else
		{
			tail->next = new QNode(data);
			tail = tail->next;
		}
	}//enque()

	int deque()
	{
		int node_info;

		if( head == NULL )
		{
			node_info =  NULL;
		}

		else if( head == tail )
		{
			node_info = head->info;
			delete(head);
			head = tail = NULL;
		}

		else
		{
			node_info = head->info;
			QNode *p = head;
			head = head->next;
			delete(p);			
		}

		return node_info;
	}// deque()

	bool print()
	{
		if( head == NULL )	return false;
		else
		{
			QNode *p = head;

			cout << "\nCurrent queue is:\t";
			
			while( p != NULL )
			{
				cout << p->info << ' ';
				p = p->next;
			}
			return true;
		}
	}
};

int main()
{
	Queue q;
	int choice;
	int element;
	
	while(true)
	{
		system("clear");
		cout << "\n<----- QUEUE USING LINKED LIST ----->";

		cout << "\n\nOperations available on queue:\n";
		cout << "\t1. Add an element    [enque]\n";
		cout << "\t2. Remove an element [deque]\n";
		cout << "\t3. Print the queue\n";
		cout << "\t4. EXIT\n";
		cout << "\nEnter your choice :";

		while( !(cin>>choice) || choice < 0 || choice > 4 )  printerror("Invalid choice, enter again: ");

		if( choice == 1 )
		{
			cout << "\nEnter the element: ";
			while( !(cin>>element) )  printerror("Invalid element, enter again: ");
			q.enque(element);
			cout << "\n\n" << element << " added to the queue.";
		}

		else if ( choice == 2 )
		{
			int deleted_element;
			if ( ( deleted_element = q.deque() ) != NULL )
			{
				cout << "\n\n" << deleted_element << " removed from the queue.";
			}
			else
			{
				cout << "\n\n[!] Current queue empty!";
			}			
		}
		
		else if( choice == 3 )
		{
			if( q.print() );
			else
			{
				cout << "\n[!] Current queue empty!";
			}		
		}

		else 	return 0;
		
		cout << "\n\n\nPress ENTER to continue ...";
		cin.ignore();
		char ch = getchar();
	}	
}