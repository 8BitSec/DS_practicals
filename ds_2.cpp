/* 
	Q. WAP to compute br using recursion where b represents base and r represents power.
*/

#include<iostream>
using namespace std;

double power( double b, int r)
{
	if( r == 0 )	return 1;
	return b * power(b,r-1);
}//power()

int main()
{
	double base;
	int pwr;

	cout << "base = ";
	cin >> base;
	cout << "power = ";
	cin >> pwr;

	cout << base <<'^'<< pwr << " = " << power(base,pwr);
	cout << endl;

	return 0;	
}