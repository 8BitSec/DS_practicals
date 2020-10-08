/*
    Q. Implement Doubly linked lists using templates. Include functions for insertion,
        deletion and search of a number, reverse the list.
*/

#include<iostream>
using namespace std;

//NODE CLASS
template <class t>
class Node
{
public:
    t info;
    Node *next, *prev;

    Node(t data)
    {
        info = data;
        next = prev = NULL;
    }
};//NODE CLASS

//LIST CLASS
template <class T>
class DLList
{
    Node <T> *head, *tail;

public:

    DLList()
    {
        head = tail = NULL;
    }

    bool search (int element)
    {
	Node<T> *temp=head;
	while(temp!=NULL)
	{
		if(temp->info == element)
		{
		 return true;
		 break;
	    }	    
		 temp=temp->next;
	}
     }
	
    void add_at_head(T data)
    {
        if( head == NULL )
            head = tail = new Node<T>(data);

        else
        {
            Node <T> *p = new Node<T>(data);
            p->next = head;
            head->prev = p;     //later - head = head->prev = p;
            head = p;
        }
    }//add_at_head()

    int add_at_N_position(T data,int pos)
    {
        if( head == NULL )      return -2;
        
        Node <T> *p = head;
        int i = 1;

        while( p!=NULL && ++i<pos )   p = p->next;

        if( p == NULL )     return -1;
        
        else
        {
            Node <T> *N = new Node<T>(data);

            N->next = p->next;
            N->prev = p;
            N->next->prev = N;
            p->next = N;
            return 0;                
        }
    }//add_at_N_position()

    void add_at_tail(T data)
    {
        if( tail == NULL )
            head = tail = new Node<T>(data);
        
        else
        {
            Node <T> *p = new Node<T>(data);
            p->prev = tail;
            tail = tail->next = p;              
        }
    }//add_at_tail()

    bool traverse()
    {
        if( head == NULL )  return false;
        
        else
        {
            std::cout << "\nThe present list is :\t";
            Node <T> *p = head;

            while( p != NULL )
            {
                std::cout << p->info << ' ';
                p = p->next;
            }
            return true;
        }        
    }//traverse()

    bool reverse_traverse()
    {
        if( tail == NULL )  return false;

        else
        {
            std::cout << "\nThe present list is:";
            Node <T> *p = tail;

            while( p != NULL )
            {
                std::cout << p->info << ' ';
                p = p->prev;
            }
            return true;
        }        
    }//reverse_traverse()

    int search(T element)
    {
        if( head == NULL )  return -2;
        
        Node <T> *s = head, *e = tail;

        while( s!= NULL && s!=e && s->info!=element && e->info!=element )
        {
            s = s->next;    //increment start
            e = e->prev;    //increment end
        }

        return ( s == NULL || s == e )? -1 : 0 ;
    }

    bool delete_from_head()
    {
        if( head == NULL )  return false;

        else if( head == tail )
        {
            delete(head);
            head = tail = NULL;
            return true;
        }

        else
        {
            head = head->next;
            delete(head->prev);
            head->prev = NULL;
            return true;
        }      
    }//delete_from_head()

    int delete_from_N_position(int pos)
    {
        if( head == NULL )  return -2;

        Node <T> *p = head;
        int i = 1;

        while ( p!=NULL && ++i < pos )  p = p->next;

        if( p == NULL )     return -1;

        else
        {
            p->next = p->next->next;
            delete(p->next->prev);
            p->next->prev = p;
            return 0;
        }      
    }//delete_from_N_position()

    bool delete_from_tail()
    {
        if( head == NULL )  return false;

        else if( head == tail )
        {
            delete(head);
            head = tail = NULL;
            return true;
        }

        else
        {
            tail = tail->prev;
            delete(tail->next);
            tail->next = NULL;
            return true;
        }        
    }//delete_from_tail()

    bool reverse_list()
    {
        if( head == NULL )  return false;

        Node <T> *current = head;
        Node <T> *temp = NULL;
        while ( current != NULL )  
        {  
            temp = current->prev;  
            current->prev = current->next;  
            current->next = temp;              
            current = current->prev;  
        }
        if(temp != NULL ) head = temp->prev;
        return true;  
    }
};//LIST CLASS


//function to print input errors
void printerror(string str="\nInvalid input, enter again :")
{
    cin.clear();
    cin.ignore(100,'\n');
    cout << str ;
}

template <class T>
void operations()
{
    DLList <T> list;
    int choice,position,status;
    T data;

  while(1){
    cout << "\nOperations available are :\n";
    cout << "\t1. Add new element at Head\n";
    cout << "\t2. Add new element at Nth position\n";
	cout << "\t3. Add new element at Tail\n";
    cout << "\t4. Print the list\n";
	cout << "\t5. Print the list in reverse\n";
    cout << "\t6. Search the list for presence of an element\n";
    cout << "\t7. Delete an element from head\n";
    cout << "\t8. Delete an element from Nth position\n";
	cout << "\t9. Delete an element from tail\n";
    cout << "\t10. Reverse the list\n";
    cout << "\t11. EXIT";
    cout << "\nEnter your choice :";
    
	while( !(cin>>choice) || choice<=0 || choice>11 )  
 	printerror("Invalid choice, enter again :");

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
			cout << "\nEnter the position :";
			while( !(cin>>position) )   printerror("Not a valid position, enter again :");

			status = list.add_at_N_position(data,position);
			if( status == -2 )
				cout << "\nFailed, list is empty!\n";
			else if( status == -1 )
				cout << "\nFailed, insufficient no. of elements in the list!\n";
			else
				cout << "\nDone!\n";
			break;

        case 3:
            cout << "\nEnter the data :";
            while( !(cin>>data) )   printerror("Not a valid data for your list, enter again :");

            list.add_at_tail(data);
            cout << "\nDone!\n";
            break;

        case 4:
            if( list.traverse() ); 
            else
                cout << "\nThe list is Empty!";
            break;

		case 5:
			if( list.reverse_traverse() );
			else
				cout << "\nThe list is Empty!";
			break;
			
        case 6:
            T element;
            cout << "\nEnter the element to search for :";
            while( !(cin>>element) )   printerror("Invalid element, enter again :");

            int stat;
            stat = list.search(element);

            if( stat == -2 )
                cout << "\nSearch failed, list is empty!\n";
            else
            {
                cout << "\nThe element " << element << " is ";
                if( stat == -1 )  cout << "NOT ";
                cout << "present in the list.\n";
            }
            break;

        case 7:
            if( list.delete_from_head() )
                cout << "\nSuccessfull!\n";
            else
                cout << "\nFailed, list is empty!\n";            
            break;

		case 8:
			cout << "\nPosition :";
			while( !(cin>>position) )   printerror("Invalid position, enter again :");

			status = list.delete_from_N_position(position);
			if( status == -2 )		cout << "\nFailed, list is empty!";
			else if(status == -1)	cout <<"\nFailed, insufficient no. of elements in list!";
			else					cout <<"\nDone!";
			break;
        case 9:
            if( list.delete_from_tail() )
                cout << "\nSuccessfull!";
            else
                cout << "\nFailed, list is empty!";
            break;

        case 10:
            if( list.reverse_list() )
            {
                cout << "After reversing, ";
                list.traverse();
            }
            else
            {
                cout << "\n[!] Current list is empty!";
            }
            break;
            
        case 11:
                return;
    }//switch(choice)

    cout << "\nPress ENTER to continue ...";
    cin.ignore(100,'\n');
    char ch = getchar();
    }//while(1)
    return;
}//operations()

int main()
{
    int type;
    char ch;

    cout << "\n\t\t<--- DOUBLE LINKED LISTS --->\n";

 do{
    cout << "\nAvailable list types are :-";
    cout << "\n\t1. Linked list of Integers";
    cout << "\n\t2. Linked list of Characters";
    cout << "\n\t3. Linked list of Floats";
    cout << "\n\nEnter your choice :";

    while( !(cin>>type) || type <= 0 || type>3 )    printerror("Invalid choice, enter again :");
    
    if( type == 1)          operations <int>  ();   
    else if( type == 2)     operations <char> ();   
    else                    operations <float>();

 
    cout << "\n\nTry another type of linked list? (y/n) :";
    while( !(cin>>ch) || ( tolower(ch)!='y' && tolower(ch)!='n' ) )
        printerror("Please enter only 'y' or 'n' :");

  }while( tolower(ch) == 'y' );     //do-while

    return 0;
}//main() 
