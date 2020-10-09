/*
	Q. Implement Circular Linked List. Include functions for insertion, deletion and
	   search of a number.
*/
#include<iostream>
using namespace std;

void printerror( string err="Invalid input, enter again :")
{
	cin.clear();
	cin.ignore(100,'\n');
	cout << err;
}

class Node
{
	public:
	int info;
	Node *next;

	Node(int data)
	{
		info = data;
		next = NULL;
	}
};

class CLList
{	
	Node *head, *tail;

	public:
	CLList()
	{
		head = tail = NULL;
	}

	void add_at_head(int data)
	{
		if( head == NULL )
		{
			head = tail = new Node(data);
			tail->next = head;
		}
		else
		{
			Node *p = new Node(data);
			p->next = head;
			head = tail->next = p;
		}				
	}

	void add_at_tail(int data)
	{
		if( head == NULL )
			head = tail = new Node(data);
		else
		{
			Node *p = new Node(data);
			p->next = head;
			tail->next = p;
			tail = p;
		}		
	}

	bool traverse()
	{
		if( head == NULL )	return false;

		else
		{
			cout << "\nThe present list is :\t";

			Node *p = head;

			do
			{
				cout << p->info << ' ';
				p = p->next;
			} while ( p != head );	
			return true;
		}		
	}

	int search(int data)
	{
		if( head == NULL )	return -2;

		else
		{
			Node *p = head;

			do{
				if( p->info == data)	return 0;
				else					p = p->next;				
			}while( p != head );

			return -1;
		}		
	}
	
	bool search (int element)
        {
          Node *temp=tail->next;
	  while(temp!=tail)
	  {
		if(temp->info == element)
		{
		 return true;
		 break;
	        }	    
		 temp=temp->next;
	  }
        }

	bool delete_from_head()
	{
		if(head == NULL )	return false;

		else if( head == tail )
		{
			delete(head);
			head = tail = NULL;
			return true;
		}

		else
		{
			tail->next = head->next;
			delete(head);
			head = tail->next;
			return true;
		}		
	}
		void del_after_pos(int pos)
	{
		if(tail==0)
		{
			cout<<"\nList is Empty";	
		}	
		
		else if(tail->next==tail)
		{
			delete(tail);
			tail=0;
		}
		
		else if(tail->next!=tail)
		{
			CDLLNode<t> *pre = tail->next;
			CDLLNode<t> *curt= tail->next;
			int index = 0;
			while(1)
			{
				index++;
				if(index==pos+1)
					break;
				pre = curt;
				curt = curt->next;
			}
			curt->next->prev=pre;
			pre->next=curt->next;
			delete(curt);
		}
	}

	bool delete_from_tail()
	{
		if( head == NULL )	return false;

		else if (head == tail)
		{
			delete(head);
			head  = tail = NULL;
			return true;
		}

		else
		{
			Node *p = head;

			while( p->next != tail )	p = p->next;

			p->next = head;
			delete(tail);
			tail = p;
			return true;
		}
	}
};

int main()
{
	CLList list;

	int choice, data;

	cout << "\n\t\t<--- CIRCULAR LINKED LIST --->\n";

	do{
	cout << "\nOperations available are :\n";
    cout << "\t1. Add new element at Head\n";
    cout << "\t2. Add new element at Tail\n";
    cout << "\t3. Print the list\n";
    cout << "\t4. Search the list for presence of an element\n";    
    cout << "\t5. Delete an element from head\n";
    cout << "\t6. Delete an element from tail\n";
    cout << "\t7. EXIT";
    cout << "\nEnter your choice :";
    while( !(cin>>choice) || choice<=0 || choice>7 )     printerror("Invalid choice, enter again :");

    switch(choice)
    {
        case 1:
            cout << "\nEnter the data :";
            while( !(cin>>data) )   printerror("Not a valid data for your list, enter again :");
            list.add_at_head(data);
            cout << "\nDone!\n";
            break;

        case 2:
            cout << "\nEnter the data :";
            while( !(cin>>data) )   printerror("Not a valid data for your list, enter again :");

            list.add_at_tail(data);
            cout << "\nDone!\n";
            break;

        case 3:
            if( list.traverse() ); 
            else
                cout << "\nThe list is Empty!";
            break;

        case 4:
            cout << "\nEnter the element to search for :";
            while( !(cin>>data) )   printerror("Invalid element, enter again :");

            int stat;
            stat = list.search(data);

            if( stat == -2 )
                cout << "\nSearch failed, list is empty!\n";
            else
            {
                cout << "\nThe element " << data << " is ";
                if( stat == -1 )  cout << "NOT ";
                cout << "present in the list.\n";
            }
            break;
        
        case 5:
            if( list.delete_from_head() )
                cout << "\nSuccessfull!\n";
            else
                cout << "\nFailed, list is empty!\n";            
            break;

        case 6:
            if( list.delete_from_tail() )
                cout << "\nSuccessfull!";
            else
                cout << "\nFailed, list is empty!";
            break;
        }//switch(choice)

    cout << "\nPress ENTER to continue ...";
    cin.ignore(100,'\n');
    char ch = getchar();
   } while( choice != 7 );

	return 0;
}
