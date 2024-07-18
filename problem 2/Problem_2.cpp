/*
Problem #2
Write a program to print all prime numbers from 1 to N
*/

#include <iostream>
#include<cmath>
using namespace std;

enum enPrimNotPrim {
    Prim = 0,
    NotPrim
};

enPrimNotPrim is_prim(int number)
{
    int m = round(number / 2);
    for (int i = 2; i <= m; i++)
    {
        if (number % i == 0)
            return enPrimNotPrim::NotPrim;
    }
    return enPrimNotPrim::Prim;
}

void print_prime_numbers_from_1_to_n(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if (is_prim(i) == enPrimNotPrim::Prim)
            cout << i << endl;
    }
}

int read_positive_number(string message)
{
    int number;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <0);
    return number;
}

int main()
{
    print_prime_numbers_from_1_to_n(read_positive_number("Enter positive number"));

    return 0;
}
