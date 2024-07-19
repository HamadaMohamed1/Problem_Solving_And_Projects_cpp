/*
write a program read a number , then print all digit frequency in that number

in => 1223222
out:
Digit 1 frequency is 1 Time(s)
Digit 2 frequency is 5 Time(s)
Digit 3 frequency is 1 Time(s)
*/



#include <iostream>
using namespace std;
int main()
{

int number;
int remainder;
int frequency = 0;

cout << "Enter the number" << endl;
cin >> number;
int temp = number;
for (int i = 1 ; i < 10 ; i++)
{
	while (temp !=0)
	{
		remainder = temp % 10;
		temp /= 10;
		if (remainder == i)
		{
			frequency++;
		}
	}
	if (frequency != 0)
	{
		cout << "Digit  " << i << "  frequency is  " << frequency << "  times" << endl;
		frequency = 0;
	}
	
	temp = number;
}



return 0;
}