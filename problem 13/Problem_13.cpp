/*
Write a program to read a number and print pattern as follows :

input : 3
output :
1
22
333

*/
#include <iostream>
using namespace std;

int read_number(string message)
{
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}

int reverse_number(int num)
{
    int reversed_number =0 , remainder;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        reversed_number = remainder + reversed_number * 10;
    }
    return reversed_number;
}

void print_pattern(int num)
{
    for (int i = 1; i <= num ;i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    int number = read_number("Enter the number");

    print_pattern(number);


    return 0;
}

