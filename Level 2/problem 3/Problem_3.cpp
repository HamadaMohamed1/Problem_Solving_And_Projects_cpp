/*
ًWrite a program to check if the number is perfect or not,
perfect number = sum(all divisor)
28 = 1+2+4+7+14  => 28 is perfect
6 = 1+2+3  => 6 is not perfect

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
    int m = round(num / 2);
    int j = 0;
    for (int i = 1; i <= m; i++)
    {
        if (num % i == 0)
        {
            j += i;
        }
    }
    if (j == num)
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

int main()
{
    int number = read_number("Enter the number");

    print_result(check_number(number));

    return 0;
}

