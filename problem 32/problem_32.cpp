/*
Write a program to fill array with max size 100 with random numbers from 1 to 100 ,
copy it in  another array with reverse order and print it
*/
#include <iostream>
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

void fill_array(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = random_number_in_range(1, 100);
    }
}

void print_array(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void reverse_array(int src[100] , int dest[100] , int length)
{
    for (int i = length - 1 , j = 0; i >= 0; i-- , j++)
    {
        dest[j] = src[i];
    }
}

int main()
{
    int source[100] , destination[100], length;

    length = read_number("Enter the length");
    fill_array(source, length);
    cout << "Source array : " << endl;
    print_array(source, length);

    reverse_array(source, destination, length);

    cout << "destination array : " << endl;
    print_array(destination, length);



	return 0;
}
