/*
	Q. Write a menu driven program to implement the following sparse matrices using one-dimensional 
		array:
		a. Diagonal Matrix 
		b. Lower Triangular Matrix 
		c. Upper Triangular Matrix 
		d. Symmetric Matrix 
*/

#include <iostream>
#define SIZE 50
using namespace std;

class DiagonalMatrix
{
public:
    int ar[SIZE];
	int n;

    DiagonalMatrix(int n)
    {
		this->n = n;
    }

    void set()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if( i == j )
                {
                    cout<<"\nEnter the element: ";
                    cin >> ar[i];
                }
            }
        }
    }

    void set(int i,int val)
    {
        ar[i]=val;
    }

    int get(int i,int j)
    {
        return ar[i];
    }
};

class LowerTriangularMatrix
{
public:
    int ar[SIZE];
    int n;

    LowerTriangularMatrix(int n)
    {
		this->n = n;
    }

    void set(int i, int j,int val)
    {
        int index = i * (i+1) / 2 + j;
        ar[index]=val;
    }

    void set()
    {
        cout<<"\nEnter Elements Row-Wise:: \n";
        int val;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i>=j)
                {
                    cout<<"\nEnter the element: ";
                    cin>>val;
                    int index= i*(i+1)/2 + j;
                    ar[index]=val;
                }
            }
        }
    }

    int get(int i,int j)
    {
        return ar[i*(i+1)/2 + j];
    }
};

class UpperTriangularMatrix
{
public:
    int ar[SIZE];
    int n;

    UpperTriangularMatrix(int n)
    {
		this->n=n;
    }

    void set(int i, int j,int val)
    {
        int index= n*i + j - (i*(i+1)/2);
        ar[index]=val;
    }

    void set()
    {
        cout<<"\nEnter Elements Row-Wise:: \n";
        int i,j,val;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i<=j)
                {
                    cout<<"\nEnter the element: ";
                    cin>>val;
                    int index= n*i + j - (i*(i+1)/2);
                    ar[index]=val;
                }
            }
        }
    }

    int get(int i,int j)
    {
        return ar[n*i + j - (i*(i+1)/2)];
    }
};

class SymmetricMatrix
{
public:
    int ar[SIZE];
    int n;

    SymmetricMatrix(int n)
    {
		this->n=n;
    }

    void set(int i, int j,int val)
    {
        int index;

        if(i<=j)	index= n*i + j - (i*(i+1)/2);
        else		index=n*j + i - (j*(j+1)/2);
        ar[index]=val;
    }

    void set()
    {
        cout<<"\nEnter Elements Row-Wise:: \n";
        int val,len=n*(n+1)/2;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i<=j)
                {
                    cout<<"\nEnter the element: ";
                    cin>>val;
                    int index= n*i + j - (i*(i+1)/2);
                    ar[index]=val;
                }
            }
        }
    }

    int get(int i,int j)
    {
        if(i<=j)	return ar[n*i + j - (i*(i+1)/2)];

        return ar[n*j + i - (j*(j+1)/2)];
    }
};

int main()
{
    int ch,n,element,op;

    cout<<"\nEnter Size of the 2D Square Matrix: ";
    cin >> n;

    do
    {
        bool out=1;
        cout<<"\nMenu::\n1)Diagonal Matrix.\n2)Lower Triangular Matrix.\n3)Upper Triangular Matrix.\n4)Symmetric Matrix.\n5)Exit.\n";
        cout<<"\nSelect an Option: ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            do
            {
                DiagonalMatrix dm(n);
                int val,i,j;
                out=1;
                cout<<"\nDiagonal Matrix::\n1)Set Elements.\n2)Reset an element.\n3)Get element.\n4)Exit.\n";
                cout<<"Select option: ";
                cin>>op;
                switch(op)
                {
                case 1:
                    dm.set();
                    break;
                case 2:
                    do
                    {
                        cout<<"\nEnter the indexes (i & j,i==j): ";
                        cin>>i>>j;
                    }
                    while(i!=j || i>=n || j>=n);

                    cout<<"\nEnter value to be stored: ";
                    cin>>val;
                    dm.set(i,val);
                    break;

                case 3:
                    do
                    {
                        cout<<"\nEnter the indexes to retrieve element(i & j, i==j): ";
                        cin>>i>>j;
                    }
                    while(i>=n || j>=n || i!=j);
                    element=dm.get(i,j);
                    cout<<"\nElement is "<<element<<endl;
                    break;
                case 4:
                    out=0;
                }

            }
            while(out);

            break;

        case 2:
            do
            {
                LowerTriangularMatrix lm(n);
                int val,i,j;
                out=1;
                cout<<"\nLower Triangular Matrix::\n1)Set All Elements(Row-Major).\n2)Reset an element.\n3)Get element(Row-Major).\n4)Exit.\n";
                cout<<"Select option: ";
                cin>>op;
                switch(op)
                {
                case 1:
                    lm.set();
                    break;
                case 2:
                    do
                    {
                        cout<<"\nEnter the indexes (i & j, i>=j): ";
                        cin>>i>>j;
                    }
                    while(i<j || i>=n || j>=n);

                    cout<<"\nEnter value to be stored: ";
                    cin>>val;
                    lm.set(i,j,val);
                    break;

                case 3:
                    do
                    {
                        cout<<"\nEnter the indexes to retrieve element(i & j, i>=j): ";
                        cin>>i>>j;
                    }
                    while(i>=n || j>=n || i<j);
                    element=lm.get(i,j);
                    cout<<"\nElement is "<<element<<endl;
                    break;
                case 4:
                    out=0;
                }
            }
            while(out);
            break;

        case 3:
            do
            {
                UpperTriangularMatrix um(n);
                int val,i,j;
                out=1;
                cout<<"\nUpper Triangular Matrix::\n1)Set All Elements(Row-Major).\n2)Reset an element.\n3)Get element(Row-Major).\n4)Exit.\n";
                cout<<"Select option: ";
                cin>>op;
                switch(op)
                {
               case 1:
                    um.set();
                    break;
                case 2:
                    do
                    {
                        cout<<"\nEnter the indexes (i & j, i<=j): ";
                        cin>>i>>j;
                    }
                    while(i>j || i>=n || j>=n);

                    cout<<"\nEnter value to be stored: ";
                    cin>>val;
                    um.set(i,j,val);
                    break;

                case 3:
                    do
                    {
                        cout<<"\nEnter the indexes to retrieve element(i & j, i<=j): ";
                        cin>>i>>j;
                    }
                    while(i>=n || j>=n || i>j);
                    element=um.get(i,j);
                    cout<<"\nElement is "<<element<<endl;
                    break;
                case 4:
                    out=0;
                }
            }
            while(out);
            break;

        case 4:
            do
            {
                SymmetricMatrix sm(n);
                int val,i,j;
                out=1;
                cout<<"\nSymmetric Matrix::\n1)Set All Elements(Row-Major).\n2)Reset an element.\n3)Get an element(Row-Major).\n4)Exit.\n";
                cout<<"Select option: ";
                cin>>op;
                switch(op)
                {
                case 1:
                    sm.set();
                    break;
                case 2:
                    do
                    {
                        cout<<"\nEnter the indexes (i & j): ";
                        cin>>i>>j;
                    }
                    while(i>=n || j>=n);

                    cout<<"\nEnter value to be stored: ";
                    cin>>val;
                    sm.set(i,j,val);
                    break;

                case 3:
                    do
                    {
                        cout<<"\nEnter the indexes to retrieve element(i & j): ";
                        cin>>i>>j;
                    }
                    while(i>=n || j>=n);
                    element=sm.get(i,j);
                    cout<<"\nElement is "<<element<<endl;
                    break;
                case 4:
                    out=0;
                }
            }
            while(out);
            break;

        case 5:
            return 0;
        }
    }
    while(true);

    return 0;
}