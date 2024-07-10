/*
write a program read a number and print inverted letter pattern as follows

in => 3        |       in => 5
out:             |       out:
ccc              |        eeeee
bb	|        dddd
a	|        ccc
	|        bb
	|         a

*/

#include <iostream>
using namespace std;
int main()
{

	
	int number;
	cout << "Enter the number" << endl;
	cin >> number;

	for (int i = number-1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			cout << char(65 + i);
		}
		cout << endl;
	}
	




return 0;
}