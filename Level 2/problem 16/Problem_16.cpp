/*
Write a program to print all words from AAA to ZZZ


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

void print_wards()
{
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                cout << char(i) << char(j) << char(k) << endl;
            }
        }
    }
}

int main()
{
    print_wards();
   

    return 0;
}

