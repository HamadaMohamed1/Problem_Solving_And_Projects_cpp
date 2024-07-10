/*
write a program to print 3 random numbers from 1 to 10


Output:
5
7
9

*/

#include <iostream>
#include <cstdlib>
using namespace std;


int Random_number(int from, int to)
{
    return rand()%(to - from) + from;
}

int main()
{
    //Seeds the random number generator in C++, called only once
   // srand((unsigned)time(NULL));


    cout << Random_number(1,10) << endl;
    cout << Random_number(1,10) << endl;
    cout << Random_number(1,10) << endl;




}

