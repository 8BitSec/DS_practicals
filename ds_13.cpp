/*
	Q. WAP to add two polynomials using linked list representation.
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
class Node
{
	public:
	int coeff;
	int power;
	Node *next, *prev;
	Node(int coeff, int power)
	{
		this->coeff = coeff;
		this->power = power;
		next = NULL;
	}
};

// LIST CLASS
class List
{
	public: 
	Node* head;
	Node* tail;
	
	List() { head = tail = NULL; }

	void add_element(int coeff, int power)
	{
		if( head == NULL )
		{
			head = tail = new Node(coeff,power);
			return;
		}

		else
		{
			Node *p = new Node(coeff,power);

			if( head == tail )
			{
				if( power < head->power )
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

			else if( power < head->power )
			{
				p->next = head;
				head->prev = p;
				head = p;	
			}

			else if( power > tail->power )
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

				while( temp!= NULL && temp->power < power && temp->next->power < power )	temp = temp->next;

				//temp = temp->prev; 		//since it moves 1 step ahead
				p->next = temp->next;
				p->prev = temp;
				temp->next = p;
				p->next->prev = p;			
			}
		}//else	
	}//add_element()

	void print()
	{
		if( head == NULL )
		{
			cout << "\nThe polynomial is empty!";
			return;
		}
	
	    else
	    {
	    	std::cout << "\nThe final polynomial is :\t";
	        Node *p = head;

	        while( p != NULL )
	        {
	            cout <<'('<<p->coeff<<')'<<".x^"<<p->power;
	            if( p->next != NULL)	cout << " + ";
				p = p->next;				
	        }
	        return;
	    }        
	}//print()
};

int main(){

	List poly1, poly2, polysum;
	int coeff,power;

	cout << "\nEnter the first polynomial (enter 0,0 when done):\n\n";
	
	do{
		cout << "Coefficient = ";
		while( !(cin >> coeff) ) 	printerror("Not a valid coefficient, enter again: ");

		cout << "Power = ";
		while( !(cin >> power) ) 	printerror("Invalid power, enter again: ");

		if( coeff != 0 )	poly1.add_element(coeff,power);
	} while( coeff!=0 && power!=0);

	cout << "\nEnter the second polynomial (enter 0,0 when you're done):\n\n";

	do{
		cout << "Coefficient = ";
		while( !(cin >> coeff) ) 	printerror("Not a valid coefficient, enter again: ");

		cout << "Power = ";
		while( !(cin >> power) || power < 0 ) 	printerror("Invalid power, enter again: ");

		if( coeff != 0 )	poly2.add_element(coeff,power);
	} while( coeff!=0 &&  power!=0);

	Node *p1 = poly1.head;
	Node *p2 = poly2.head;

	while( p1 != NULL && p2 != NULL )
	{		
		if( p1->power == p2->power )
		{
			polysum.add_element( ( p1->coeff + p2->coeff ) , p1->power );
			p1 = p1->next;
			p2 = p2->next;
		}

		else if ( p1->power < p2->power )
		{
			polysum.add_element( p1->coeff , p1->power );
			p1 = p1->next;
		}
		
		else if( p1->power > p2->power )
		{
			polysum.add_element( p2->coeff , p2->power );
			p2 = p2->next;
		}		
	}

	if( p1 != NULL || p2 != NULL )
	{
		while( p1 != NULL)
		{
			polysum.add_element(p1->coeff,p1->power);
			p1 = p1->next;
		}
		while(p2 != NULL )
		{
			polysum.add_element(p2->coeff,p2->power);
			p2 = p2->next;
		}
	}

	cout << "\n\nThe final polynomial is:\n\n";
	polysum.print();
	cout << endl;
	return 0;
}
