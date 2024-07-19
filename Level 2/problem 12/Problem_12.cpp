/*
Write a program to read a number and print inverted pattern as follows :

input : 3
output :
333
22
1

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

void print_inverted_pattern(int num)
{
    for (int i = num; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    int number = read_number("Enter the number");

    print_inverted_pattern(number);


    return 0;
}

