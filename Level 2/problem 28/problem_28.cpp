/*
Write a program to fill array with max size 100 with random numbers from 1 to 100
then copy it to another array and print the 2 arrays
*/
#include <iostream>
#include <cmath>
using namespace std;

int read_number(string message)
{
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}

int random_number_in_range(int from, int to)
{
    return rand() % (to - from) + from;
}

void fill_array(int arr[100] , int length)
{
    for (int i = 0; i < length;i++)
    {
        arr[i] = random_number_in_range(1,100);
    }
}

void print_array(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
}

int get_max(int arr[100] ,int length)
{
    int max = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int get_min(int arr[100] ,int length)
{
    int min = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int get_sum(int arr[100] ,int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    return sum;
}
float get_avg(int arr[100] ,int length)
{
    return get_sum(arr, length) / length;
}

void copy_array(int arr1[100], int arr2[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr2[i] = arr1[i];
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));
    int my_array1[100];
    int my_array2[100];

    int num = read_number("Enter the length of array");

    fill_array(my_array1, num);
    cout << "Array 1 :" << endl;
    print_array(my_array1, num);
    copy_array(my_array1, my_array2, num);
    cout << "Array 2 :" << endl;
    print_array(my_array2, num);
    
}
