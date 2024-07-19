/*
Write a program to fill array woth ordered numbers from 1 to N ,
then print it , after that shuffle this array and print it after shuffle.
Input:
10
Output:
Array elements before shuffle:
1 2 3 4 5 6 7 8 9 10

Array elements after shuffle:
2 4 6 3 10 1 7 8 5 9
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int Random_Number(int from, int to)
{
    return rand() % (to - from) + from;
}


void Print_Array(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int array_size;
int arr[100];
int random_index;
int main()
{
    cout << "Enter the array size\n";
    cin >> array_size;

    for (int i = 0; i < array_size; i++)
    {
        arr[i] = i + 1;
    }

    cout << "Array elements before shuffle:\n";
    Print_Array(arr , array_size);


    for (int i = 0; i < array_size; i++)
    {
        random_index = Random_Number(i , array_size);
        swap(arr[i] , arr[random_index]);
    }
    cout << "Array elements before shuffle:\n";
    Print_Array(arr, array_size);

}

