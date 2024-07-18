/*
Problem #1
Write a program to print the multiplecation table from 1 to 10
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "\t\t\t\tMultiplecation Table from 1 to 10\n\n";

    cout << "\t \t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n--------------------------------------------------------------------------------------------"<<endl;

    for (int row = 1; row <= 10; row++)
    {
        cout << row << "\t|\t";
        for (int col = 1; col <= 10; col++)
        {
            cout << row * col << "\t";
        }
        cout << endl;
    }


}
