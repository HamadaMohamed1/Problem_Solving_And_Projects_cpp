/*
ًWrite a program to check if the number is perfect or not,
perfect number = sum(all divisor)
28 = 1+2+4+7+14  => 28 is perfect
6 = 1+2+3  => 6 is perfect

Write a program to print the perfect numbers from 1 to N

*/
#include <iostream>
using namespace std;

enum enPerfectNotPerfect
{
    Perfect = 0 , NotPerfect
};
int read_number(string message)
{
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}

enPerfectNotPerfect check_number(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        return enPerfectNotPerfect::Perfect;
    }
    else
    {
        return enPerfectNotPerfect::NotPerfect;
    }
}

void print_result(enPerfectNotPerfect perfect_or_not)
{
    if (perfect_or_not == enPerfectNotPerfect::Perfect)
    {
        cout << "Perfect number" << endl;
    }
    else if (perfect_or_not == enPerfectNotPerfect::NotPerfect)
    {
        cout << "Not perfect number" << endl;
    }
}

void print_perfect_numbers_from1_to_n(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if(check_number(i) == enPerfectNotPerfect::Perfect)
        {
            cout << i << " : ";
            print_result(check_number(i));
        }
    }
}
int main()
{
    int number = read_number("Enter the number");
    print_perfect_numbers_from1_to_n(number);

    return 0;
}

