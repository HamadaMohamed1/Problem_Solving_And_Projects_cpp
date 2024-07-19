/*
write a program to read N elements and store them an array then print all array elements and ask
for a number to check , then print how many number a certain element repeated in that array

Input:
5
Enter Array elements
Element [1] : 1
Element [2] : 1
Element [3] : 1
Element [4] : 2
Element [5] : 13

Enter the number you want to check : 1

output :
Original array : 111213
1 is repeated 3 time(s)
*/


#include <iostream>
using namespace std;



int main()
{
    int size ;
    int arr[50];
    int number;
    int frequency = 0;
    cout << "Enter the size of array : ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter Element [" << i+1 << "] : ";
        cin >> arr[i];
    }

    cout << "\nEnter a number you want to check : ";
    cin >> number;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number)
            frequency++;
    }

    cout << "\nOriginal array : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }

    cout << "\n" << number << " is repeated " << frequency << " time(s)" << endl;


}

