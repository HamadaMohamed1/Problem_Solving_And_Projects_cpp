/*
Write a program to fill a 3x3 matrix with random numbers ,
then stor the sum of each raw in 1D array
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

void CopySumOfRaws(int src[3][3] , int dest[3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           sum+= src[i][j];
        }
        dest[i] = sum;
        sum = 0;
    }
}

void PrintArray1D(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << i + 1 << " : " << arr[i] << endl;
    }
}
int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));

    int my_matrix[3][3];
    cout << "3x3 matrix with random numbers : " << endl;
    FillMatrix3x3(my_matrix);
    PrintMatrix3x3(my_matrix);
    PrintSumOfRaws(my_matrix);
    int arr[3];
    CopySumOfRaws(my_matrix, arr);
    cout << "1D array : " << endl;
    PrintArray1D(arr , 3);

    return 0;
}

