/*
Write a program to read a number and print the sum of its digits
num = 1234 => sum = 1+2+3+4 = 10
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

int sum_of_digits(int num)
{
    int sum =0 ;  
    while (num > 0)
    {
        int remainder = num % 10;
        num /= 10;
        sum += remainder;
    }
    return sum;
}


int main()
{
    int number = read_number("Enter the number");

   
    cout << sum_of_digits(number);



    return 0;
}

