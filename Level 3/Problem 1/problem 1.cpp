/*
Write a program to fill a 3x3 matrix with random numbers
*/
#include <iostream>
#include <cmath>
#include <string>

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
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));

    int my_matrix[3][3];
    FillMatrix3x3(my_matrix);
    PrintMatrix3x3(my_matrix);



    return 0;
}

