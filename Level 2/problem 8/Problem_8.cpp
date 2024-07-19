/*
Write a program to read a number and a digit ,then print the digit frequency in that number
num = 122113442
2
digit 2 frequency is 3 time(s)

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

int frequency_of_digit(int num , int digit)
{
    int freq =0 ;  
    while (num > 0)
    {
        int remainder = num % 10;
        num /= 10;
        if (remainder == digit)
            freq++;
    }
    return freq;
}

void print_freq(int freq , int digit)
{
    cout << "Digit " << digit << " frequency is " << freq << " time(s)" << endl;
}

int main()
{
    int number = read_number("Enter the number");
    int digit = read_number("Enter the digit");

    print_freq(frequency_of_digit(number, digit) , digit);


    return 0;
}

