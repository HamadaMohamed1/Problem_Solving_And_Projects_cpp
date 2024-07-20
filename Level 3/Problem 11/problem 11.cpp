/*
* Problem #11
* Write a program to check two 3x3 matrices if they are equal or not
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

void FillMatrix3x3WithRandomNumbers(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = RandomNumberInRange(1, 20);
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
            sum += arr[i][j];
        }
        cout << "Sum of raw [" << i + 1 << "] = " << sum << endl;
        sum = 0;
    }
}

void PrintSumOfCol(int arr[3][3])
{
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of col [" << j + 1 << "] = " << sum << endl;
        sum = 0;
    }
}

void CopySumOfRaws(int src[3][3], int dest[3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += src[i][j];
        }
        dest[i] = sum;
        sum = 0;
    }
}

void CopySumOfCol(int src[3][3], int dest[3])
{
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            sum += src[i][j];
        }
        dest[j] = sum;
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

void FillMatrixWithOrderedNumber(int arr[3][3], short from)
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = from++;
        }
    }
}

void TransposeMatrix(int src[3][3], int dest[3][3])
{
    /*
            1  2  3         1  4  7
            4  5  6     =>  2  5  8
            7  8  9         3  6  9
    */
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            dest[j][i] = src[i][j];
        }
    }
}

void Multiply2Matrecies(int src1[3][3], int src2[3][3], int dest[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            dest[i][j] = src1[i][j] * src2[i][j];
        }
    }
}

void PrintMiddleRaw(int arr[3][3])
{
    short i;
    cout << "Middle raw : ";
    for (i = 0; i < 3; i++)
    {
        cout << arr[1][i] << "  ";
    }
    cout << endl;
}

void PrintMiddleCol(int arr[3][3])
{
    short i;
    cout << "Middle column : ";
    for (i = 0; i < 3; i++)
    {
        cout << arr[i][1] << "  ";
    }
    cout << endl;
}

int SumOfMatrix(int arr[3][3])
{
    short i, j;
    int sum = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

bool IsEquals(int arr1[3][3], int arr2[3][3])
{
    bool ret;
    ret = SumOfMatrix(arr1) == SumOfMatrix(arr2) ? true : false;
    return ret;
}
int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));

    int matrix1[3][3] , matrix2[3][3];

    FillMatrixWithOrderedNumber(matrix1, 1);
    FillMatrixWithOrderedNumber(matrix2, 1);

    cout << "Matrix 1 elements : " << endl;
    PrintMatrix3x3(matrix1);
    cout << "Matrix 2 elements : " << endl;
    PrintMatrix3x3(matrix2);

    if (IsEquals(matrix1, matrix2))
    {
        cout << "2 matrcies are Equals" << endl;
    }
    else
    {
        cout << "2 matrcies are Not Equals" << endl;
    }



    return 0;
}

