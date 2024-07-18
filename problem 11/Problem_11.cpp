/*
Write a program to read a number and check it if palindrome or not ,
palindrome is a number that reads the same from right to left

1234   => not palindrome
12321   => palindrome

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

bool check_palindrome(int num)
{
    return (num == reverse_number(num));
}

int main()
{
    int number = read_number("Enter the number");

    check_palindrome(number) ? cout << "palindrome" : cout << "not palindrome";



    return 0;
}

