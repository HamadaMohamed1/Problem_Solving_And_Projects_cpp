/*
* Problem #23
* Write a program to read a string then uppercase the first letter of each word in that string
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

bool AreEquals(int arr1[3][3], int arr2[3][3])
{
    bool ret;
    ret = SumOfMatrix(arr1) == SumOfMatrix(arr2) ? true : false;
    return ret;
}

bool AreTypical(int arr1[3][3], int arr2[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool IsIdentity(int arr[3][3])
{
    //  identity matrix
    //  1   0   0
    //  0   1   0
    //  0   0   1
    short i, j;
    for (i = 0; i < 3; i++)
    {                                                                  
        for (j = 0; j < 3; j++)
        {
            if ((i==j) && (arr[i][j] != 1))
            {
                return false;
            }
            else if ((i!=j) && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsScalar(int arr[3][3])
{
    //  scalar matrix
    //  8   0   0
    //  0   8   0           diagonal are equals numbers & the rest element are zeros
    //  0   0   8           
    short i, j;
    int diagonal_element = arr[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if ((i == j) && (arr[i][j] != diagonal_element))
            {
                return false;
            }
            else if ((i != j) && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int CountNumberInMatrix(int arr[3][3] , int number)
{
    int counter = 0;
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == number)
            {
                counter++;
            }
        }
    }
    return counter;
}

bool IsSparce(int arr[3][3])
{
    //  Sparce matrix : number of zeros in matrix larger than the rest numbers
    short i, j;
    int zero_count = 0 , rest_numbers_count = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                zero_count++;
            }
            else
            {
                rest_numbers_count++;
            }
        }
    }
    if (zero_count > rest_numbers_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LinearSearch(int arr[3][3], int number)
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == number)
                return true;
        }
    }
    return false;
}

void PrintIntersectedNumbers(int arr1[3][3], int arr2[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (LinearSearch(arr2, arr1[i][j]))
            {
                cout << arr1[i][j] << "\t";
            }
        }
    }
    cout << endl;
}

int GetMin(int arr[3][3])
{
    short i, j;
    int min = arr[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int GetMax(int arr[3][3])
{
    short i, j;
    int  max = arr[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

void PrintMin_MaxOfMatrix(int arr[3][3])
{
    cout << "Min number : " << GetMin(arr) << endl;
    cout << "Max number : " << GetMax(arr) << endl;
}

bool IsPalindrom(int arr[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][0] != arr[i][2])
            {
                return false;
            }
        }
    }
    return true;
}

void PrintFibonacciSeries(int num)
{
    int prievus1 = 0, prievus2 = 1;
    int fibonacci_number = 1;
    cout << fibonacci_number << "\t";
    for (int i = 1; i < num; i++)
    {
        fibonacci_number = prievus1 + prievus2;
        cout << fibonacci_number << "\t";  
        prievus1 = prievus2;
        prievus2 = fibonacci_number;
    }
    cout << endl;
}

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin , str);
    return str;
}

void Print1stLetterOfString(string str)
{
    short i;
    cout << str[0] << "\t";
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            cout << str[i+1] << "\t";
        }
    }
}

void Convert1stToUppercase(string &str)
{
    short i;
    str[0] = toupper(str[0]);
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str[i+1] = toupper(str[i+1]);
        }
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));

    string my_str = ReadString("Enter a string");

    Convert1stToUppercase(my_str);

    cout << my_str;

    return 0;
}

