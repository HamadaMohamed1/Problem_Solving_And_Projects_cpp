/*
write a program read a number and print inverted letter pattern as follows

in => 3        |       in => 5
out:             |       out:
a                  |        a
bb	|        bb
ccc	|        ccc
	|        dddd
	|         eeeee

*/

#include <iostream>
using namespace std;
int main()
{

		int number;
	cout << "Enter the number" << endl;
	cin >> number;

	for (int i = 0; i < number ; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << char(65 + i);
		}
		cout << endl;
	}
	




return 0;
}