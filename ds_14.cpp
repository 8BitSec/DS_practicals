/*
	Q. Write a menu driven program to implement the following operations on sorted
		linked list:
		a) insertion
		b) deletion
*/

#include<iostream>
using namespace std;	

//FUNCTION TO PRINT INPUT ERRORS
void printerror(string err="Invalid input, enter again :")
{
	cin.clear();
	cin.ignore(100,'\n');
	cout << err;
}

//NODE CLASS
class Node
{
public:
    int info;
    Node *next, *prev;

    Node(int data)
    {
        info = data;
        next = prev = NULL;
    }
};//NODE CLASS

//LIST CLASS
class DLList
{
    Node *head, *tail;

public:

    DLList()
    {
        head = tail = NULL;
    }

	void add_element(int data);
    void traverse();
    void reverse_traverse();    
    int search(int element);
    int delete_element(int element);   
};//LIST CLASS

int main()
{
	DLList list;

	int choice, data, status;

	cout << "\n\t\t<--- SORTED LINKED LIST --->\n";

  do{
	cout << "\nOperations available are :";
	cout << "\n\t1. Add new element to the list";
	cout << "\n\t2. Print the list";
	cout << "\n\t3. Print the list in reverse";
	cout << "\n\t4. Search for presence of an element in the list";
	cout << "\n\t5. Delete an element from the list";
	cout << "\n\t6. EXIT";
	cout << "\n\nEnter your choice : ";

	while( !(cin>>choice) || choice<=0 || choice>6 )	printerror("Invalid choice, enter again :");

	switch( choice )
	{
		case 1:
			cout << "\nEnter the element :";
			while( !(cin>>data) )	printerror("Invalid element for your list, enter again :");
			if( list.search(data) != 0 )
			{
				list.add_element(data);
				cout << "\nSuccessfull!";
			}
			else	cout << "\nElement already present in the list!";			
			break;
		
		case 2:
			list.traverse();
			break;
		
		case 3:
			list.reverse_traverse();
			break;

		case 4:
			cout << "\nEnter the element to search for :";
			while( !(cin >> data) )	printerror("Invalid search element for your list, try another :");
			status = list.search(data);

			if( status == -2 )	cout << "\nFailed, list is empty!";
			else
			{
				cout << "\nThe element " << data << " is ";
                if( status == -1 )  cout << "NOT ";
                cout << "present in the list.";
			}
			break;

		case 5:
			cout << "\nEnter the element to delete :";
			while( !(cin>>data) )	printerror("Invalid element for your list, enter again :");
			status = list.delete_element(data);
			
			if( status == -2 )	cout << "\nFailed, list is empty!";
			else if( status == -1 )	cout << "\nFailed, element not present in the list!";
			else	cout << "\nSuccessfull!";
	}//switch(choice)

	cout << "\n\nPress ENTER to continue ...";
	cin.ignore(100,'\n');
	char c = getchar();
  }while( choice != 6 );
	
	return 0;
}

void DLList:: add_element(int data)
{
	if( head == NULL )
	{
		head = tail = new Node(data);
		return;
	}

	else
	{
		Node *p = new Node(data);
		
		if( head == tail )
		{
			if( data < head->info )
			{
				p->next = head;
				head->prev = p;
				head = p;
			}
			else
			{
				tail->next = p;
				p->prev = tail;
				tail = p;
			}			
		}

		else if( data < head->info )
		{
			p->next = head;
			head->prev = p;
			head = p;	
		}

		else if( data > tail->info )
		{
			tail->next = p;
			p->prev = tail;
			tail = p;
		}

		else if(head->next == tail )
		{
			p->next = tail;
			p->prev = head;
			head->next = p;
			tail->prev=p;
		}

		else
		{
			Node *temp = head;

			while( temp!= NULL && temp->info < data && temp->next->info < data )	temp = temp->next;

			//temp = temp->prev; 		//since it moves 1 step ahead
			p->next = temp->next;
			p->prev = temp;
			temp->next = p;
			p->next->prev = p;			
		}
	}//else	
}//add_element()

int DLList:: search(int element)
{
	if( head == NULL )	
		return -2;

	else if( element < head->info || element > tail->info )	
		return -1;

	else
	{
		Node *temp = head;
		
		while( temp != NULL && temp->info <= element )
		{
			if( temp->info == element )		
				return 0;
			temp = temp->next;
		}		
		return -1;
	}	
}//search()

void DLList:: traverse()
{
	if( head == NULL )
	{
		cout << "\nThe list is empty!";
		return;
	}
        
    else
    {
    	std::cout << "\nThe present list is :\t";
        Node *p = head;

        while( p != NULL )
        {
            cout << p->info << ' ';
            p = p->next;
        }
        return;
    }        
}//traverse()

void DLList:: reverse_traverse()
{
    if( tail == NULL )
	{
		cout << "\nThe list is empty!";
		return;
	}

    else
    {
    	cout << "\nThe present list in reverse fashion is:\t";
        Node *p = tail;

        while( p != NULL )
        {
            cout << p->info << ' ';
            p = p->prev;
        }
        return;
    }        
}//reverse_traverse()

int DLList:: delete_element(int element)
{
	if( head == NULL )	return -2;

	else if( element < head->info || element > tail->info )	return -1;
	
	else
	{
		Node *temp = head;

		while( temp!=NULL && temp->info <= element )
		{
			if( temp->info == element )	break;
			else	temp = temp->next;
		}

		if( temp == NULL || temp->info!=element )	return -1;

		else if( temp == tail )
		{
			tail = tail->prev;
			delete(tail->next);
			tail->next = NULL;
			return 0;
		}

		else if(temp == head)
		{
			head = head->next;
			delete(head->prev);
			head->prev = NULL;
			return 0;
		}

		else
		{
			temp->next = temp->next->next;
			delete(temp->next->prev);
			temp->next->prev = temp;
			return 0;
		}		
	}	
}//delete_element()
