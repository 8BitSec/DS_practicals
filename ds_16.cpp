#include<iostream>
#include<cctype>
using namespace std;

//function for input errors
void printerror(string err="Invalid input, enter again: ")
{
	cin.clear();
	cin.ignore(100,'\n');
	cout << err;
}

//functions
void BubbleSort(int[],int);
void InsertionSort(int[],int);
void SelectionSort(int[],int);
void merge(int[],int,int,int);
void MergeSort(int[],int,int);
int partition (int[],int,int);
void QuickSort(int[],int,int);
int LinearSearch(int[],int,int);
int BinarySearch(int[],int,int,int);
void print(int[],int);

int main()
{
	int size;
	int choice;
	int element, position;
	char ch;

	do
	{
		system("clear");
		cout << "\n\t\t\t<----- Searching & Sorting ----->";
		cout << "\n\nEnter the size of the array: ";
		while( !(cin>>size) || size <= 0 )	printerror("Invalid size, enter again: ");

		int array[size];

		cout << "\n\nEnter the array: ";

		for(int i=0; i<size; i++)	cin>>array[i];

		cout << "\nOperations available are: ";
		cout << "\nSORTING:";
		cout << "\n\t1. Bubble Sort";
		cout << "\n\t2. Insertion Sort";
		cout << "\n\t3. Selection Sort";
		cout << "\n\t4. Merge Sort";
		cout << "\n\t5. Quick Sort";
		cout << "\nSEARCHING:";
		cout << "\n\t6. Linear Search";
		cout << "\n\t7. Binary Search";
		cout << "\n\t8. EXIT";
		cout << "\n\nEnter your choice: ";
		while( !(cin>>choice) || choice<=0 || choice>8 )	printerror("Invalid choice, enter again: ");
		
		switch(choice)
		{
			case 1:
				BubbleSort(array,size);
				cout << "\n\nArray after BubbleSort is:\t";
				print(array,size);
				break;
			
			case 2:
				InsertionSort(array,size);
				cout << "\n\nArray after InsertionSort is:\t";
				print(array,size);
				break;

			case 3:
				SelectionSort(array,size);
				cout << "\n\nArray after SelectionSort is:\t";
				print(array,size);
				break;

			case 4:
				MergeSort(array,0,size-1);
				cout << "\n\nArray after MergeSort is:\t";
				print(array,size);
				break;

			case 5:
				QuickSort(array,0,size-1);
				cout << "\n\nArray after QuickSort is:\t";
				print(array,size);
				break;			
			
			case 6:
				cout << "\n\nEnter the element to be searched: ";
				while(!(cin>>element))	printerror();
				if( (position = LinearSearch(array,size,element)) > 0 )
				cout << "\n\n" << element << " found at position " << position;
				else
				cout << "\n\n" << element << " not present in given array!";
				break;

			case 7:
				cout << "\n\nEnter the element to be searched: ";
				while(!(cin>>element))	printerror();
				InsertionSort(array,size);
				if( (position = BinarySearch(array,0,size-1,element)) != -1 )
				cout << "\n\n" << element << " found at position " << position+1;
				else
				cout << "\n\n" << element << " not present in given array!";
				break;

			case 8:
				return 0;
		}

		cout << "\n\n\nTry another operation? (y/n): ";
		while( !(cin >> ch) || (tolower(ch)!='y' && tolower(ch)!='n')) printerror("'y' or 'n' only: ");

	} while( tolower(ch) == 'y' );

	return 0;
}

void BubbleSort(int array[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=0;j<(size-i-1);j++)
		{
			if( array[j] > array[j+1] )
			{
				array[j] += array[j+1];
				array[j+1] = array[j] - array[j+1];
				array[j] -= array[j+1];
			}
		}
	}
}

void InsertionSort(int array[],int size)
{
	int j, temp;
	for(int i=1; i<size; i++)
	{
		temp=array[i];
		j=i-1;
		while( ( temp < array[j] ) && j >= 0 )
		{
			array[j+1]=array[j];
			j=j-1;
		}
		array[j+1]=temp;
	}
}
void SelectionSort(int array[],int size)
{
	int min, temp, index, count=0;
	for(int i=0; i<(size-1); i++)
    {
        min = array[i];
        for(int j=(i+1); j<size; j++)
        {
            if(min>array[j])
            {
                min = array[j];
                count++;
                index = j;
            }
        }
        if(count!=0)
        {
            temp = array[i];
            array[i] = min;
            array[index] = temp;
        }
        count=0;
    }
}

void merge(int array[], int left, int middle, int right)
{ 
    int i, j, k; 
    int n1 = middle - left + 1; 
    int n2 =  right - middle; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 	L[i] = array[left+i]; 
    for (j = 0; j < n2; j++) 	R[j] = array[middle + 1 + j]; 
  
    i = 0; 
	j = 0;
    k = left;

    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            array[k] = L[i]; 
            i++; 
        } 
        else
        { 
            array[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy remaining elements of L[]
    while (i < n1) 
    { 
        array[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy remaining elements of R[]
    while (j < n2) 
    { 
        array[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void MergeSort(int array[], int left, int right)
{ 
    if (left < right) 
    { 
        int middle = (left + right)/2; 
  
        //Sort first and second halves 
        MergeSort(array, left, middle); 
        MergeSort(array, middle+1, right); 
  
        merge(array, left, middle, right); 
    } 
}//MergeSort() 
 
int partition (int array[], int low, int high)
{  
    int pivot = array[high];
    int i = low - 1;
  
    for (int j=low; j<=high-1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (array[j] < pivot)  
        {  
            i++; // increment index of smaller element
			array[i] += array[j];
			array[j] = array[i] - array[j];
			array[i] -= array[j];  
        }  
    }
	array[i+1] += array[high];
	array[high] = array[i+1]-array[high];
	array[i+1] -= array[high];
    return (i+1);  
}  

void QuickSort(int arr[], int low, int high)
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        QuickSort(arr, low, pi - 1);  
        QuickSort(arr, pi + 1, high);  
    }  
}//QuickSort()

int LinearSearch(int array[], int size, int element)
{
	for(int i=0; i<size; i++)
	{
		if( array[i] == element )	return i+1;
	}
	return 0;
}

int BinarySearch(int array[], int left, int right, int element)
{
	if (right >= left)
	{ 
        int mid = left + (right - left) / 2; 
  
        if (array[mid] == element) return mid; 
  
        if (array[mid] > element) 	return BinarySearch(array, left, mid - 1, element); 
  
        return BinarySearch(array, mid + 1, right, element); 
    } 
    return -1; 
}

void print(int array[], int size)
{
	for(int i=0;i<size;i++)	cout << array[i] << ' ';
}