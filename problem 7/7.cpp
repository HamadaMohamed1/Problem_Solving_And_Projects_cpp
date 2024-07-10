/*
write a program to read a number and print it reveersed

in => 1234   , out => 4321

*/



#include <iostream>
using namespace std;
int main()
{

	int num;
	cout << "Enter the number" << endl;
	cin >> num;

	while (num != 0)
	{
		cout << num % 10;
		num /= 10;
	}




return 0;
}