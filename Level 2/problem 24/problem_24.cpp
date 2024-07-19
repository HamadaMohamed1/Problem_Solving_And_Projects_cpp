/*
Write a program to fill array with max size 100 with random numbers from 1 to 100
then print max
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

int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));
    int my_array[100];

    int num = read_number("Enter the length of array");

    fill_array(my_array, num);
    print_array(my_array, num);
    cout << "Max element : " << get_max(my_array, num) << endl;
    
}
