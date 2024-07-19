/*
Write a program to read a number and print in a reversed order
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

int reversed_the_number(int num)
{
    int reversed_num =0 ;  //1234
    while (num > 0)
    {
        int remainder = num % 10;
        num /= 10;
        reversed_num = remainder + reversed_num * 10;
    }
    return reversed_num;
}

int main()
{
    int number = read_number("Enter the number");

   
    cout << reversed_the_number(number);



    return 0;
}

