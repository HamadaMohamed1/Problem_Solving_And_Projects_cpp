/*
write a program read a number and print it in order from left to right

in => 1234
out:
1
2
3
4
*/

#include <iostream>
using namespace std;
int main()
{

	int number1 =0  , number2 =0 ,remainder =0;

	cout << "Enter the number" << endl;
	cin >> number1;

	while (number1 != 0)
	{
		remainder = number1 % 10;
		number1 /= 10;
		number2 = number2 * 10 + remainder;
	}

	while (number2 != 0)
	{
		remainder = number2 % 10;
		number2 /= 10;
		cout << remainder << endl;
	}



return 0;
}