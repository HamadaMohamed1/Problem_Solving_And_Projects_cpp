/*
Write a program to fill a 3x3 matrix with random numbers ,
then print the sum of each raw
*/
#include <iostream>
#include <cmath>
#include <string>
#include<iomanip>
using namespace std;

int ReadNumber(string message)
{
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}

int RandomNumberInRange(int from, int to)
{
    return rand() % (to - from) + from;
}

void FillMatrix3x3(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = RandomNumberInRange(1, 100);
        }
    }
}

void PrintMatrix3x3(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void PrintSumOfRaws(int arr[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           sum+= arr[i][j];
        }
        cout << "Sum of raw [" << i + 1 << "] = " << sum << endl;
        sum = 0;
    }
}
int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));

    int my_matrix[3][3];
    FillMatrix3x3(my_matrix);
    PrintMatrix3x3(my_matrix);
    PrintSumOfRaws(my_matrix);



    return 0;
}

