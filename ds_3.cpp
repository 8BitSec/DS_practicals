/*
	Q. WAP to reverse a user entered string using recursion.

	After running the executable file, just enter the string and hit ENTER to reverse it.
*/

#include<iostream>
#include <stdio>
using namespace std;

int main()
{
	char ch;
	cin >> std::noskipws >> ch;

	if( ch != '\n' )
	{
		main();
		cout << ch;
	}
}