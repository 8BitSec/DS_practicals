/*
    Q. Implementation of Linked list using templates. Include functions for insertion,
       deletion and search of a number, reverse the list and concatenate two linked
       lists(include a function and also overload operator +).
*/

#include<iostream>
using namespace std;

//NODE CLASS
template <class t>
class Node
{
public:
    t info;
    Node *next;

    Node(t data)
    {
        info = data;
        next = NULL;
    }
};//NODE CLASS


//LIST CLASS
template <class T>
class SLList
{
    Node <T> *head, *tail ;

public :
    SLList()
    {
        head = tail = NULL ;
    }

    //operations on list
    void add_at_head(T data)
    {
        if( head == NULL )
            head = tail = new Node<T>(data);
        
        else
        {
            Node <T> *p = new Node<T>(data);
            p->next = head;
            head = p;
        }       
    }//add_at_head()

    void add_at_tail(T data)
    {
        if( tail == NULL )
            head = tail = new Node<T>(data);

        else
        {
            Node <T> *p = new Node<T>(data);
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

    int search(T element)
    {
        if( head == NULL )  return -2;
        
        Node <T> *p = head;

        while( p!= NULL && p->info!=element )   p = p->next;

        return ( p == NULL )? -1 : 0 ;        
    }//search()

    int count_nodes()
    {
        if( head == NULL )  return 0;

        int count = 0;
        Node <T> *p =head;

        while( p!=NULL && count++ )    p = p->next;

        return count;
    }//count_nodes()

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
            Node <T> *p =head;
            head = head->next;
            delete(p);
            return true;        
        }
    }//delete_from_head()

    bool delete_from_tail()
    {
        if( tail == NULL )  return false;

        else if( head == tail )
        {
            delete(head);
            head = tail = NULL;
            return true;
        }

        else
        {
            Node <T> *p = head;

            while( p->next->next != NULL )  p = p->next;

            tail = p;
            p = p->next;
            tail->next = NULL;
            delete(p);

            return true;
        }
    }//delete_from_tail()

    void reverse()
	{
		IntSLLNode<t> *temp1 = head;
		IntSLLNode<t> *temp2 = NULL;
		IntSLLNode<t> *next = NULL;
				
		while(temp1!=NULL)
		{
			next = temp1->next;
			temp1->next = temp2;
			temp2 = temp1;
			temp1 = next;
		}
		
		head = temp2;
		traverse();
					
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
    SLList <T> list;
    int choice;
    T data;

  while(1){
    cout << "\nOperations available are :\n";
    cout << "\t1. Add new element at Head\n";
    cout << "\t2. Add new element at Tail\n";
    cout << "\t3. Print the list\n";
    cout << "\t4. Search the list for presence of an element\n";
    cout << "\t5. Print the number of elements in list\n";
    cout << "\t6. Delete an element from head\n";
    cout << "\t7. Delete an element from tail\n";
    cout << "\t8. Reverse the list\n";
    cout << "\t9. EXIT";
    cout << "\nEnter your choice :";
    
    while( !(cin>>choice) || choice<=0 || choice>9 ) printerror("Invalid choice, enter again :");

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

        case 5:
            cout << "\nThere are " << list.count_nodes() << " nodes in the list.\n";
            break;

        case 6:
            if( list.delete_from_head() )
                cout << "\nSuccessfull!\n";
            else
                cout << "\nFailed, list is empty!\n";            
            break;

        case 7:
            if( list.delete_from_tail() )
                cout << "\nSuccessfull!";
            else
                cout << "\nFailed, list is empty!";
            break;

        case 8:
            if( list.reverse_list() )
            {
                cout << "\nAfter reversing: ";
                list.traverse();
            }
            else
            {
                cout << "\n[!] Current list empty.\n";
            }
            break;
            
        case 9:
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

    cout << "\n\t\t<--- SINGLE LINKED LISTS --->\n";

 do{
    cout << "\nAvailable list types are :-";
    cout << "\n\t1. Linked list of Integers";
    cout << "\n\t2. Linked list of Characters";
    cout << "\n\t3. Linked list of Floats";
    cout << "\n\nEnter your choice :";

    while( !(cin>>type) || type <= 0 || type>3 )    printerror("Invalid choice, enter again :");

    
    
    if( type == 1)          operations <int> ();   
    else if( type == 2)     operations <char>();   
    else                    operations <float>();

 
    cout << "\n\nTry another type of linked list? (y/n) :";
    while( !(cin>>ch) || ( tolower(ch)!='y' && tolower(ch)!='n' ) )
        printerror("Please enter only 'y' or 'n' :");

  }while( tolower(ch) == 'y' );     //do-while

    return 0;
}//main() 
