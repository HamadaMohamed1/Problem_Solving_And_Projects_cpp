/*
write a program to read how many keys to generate and print them on the screen

Input:
5

Output:
Key[1] : EJKF-FNNS-LFJF-LFNJ
Key[2] : KGLU-MBPR-SGDY-MNBC
Key[3] : KJHG-SDFG-TREW-VNBB
Key[4] : TREW-KGLU-MBPR-LFNJ
Key[5] : EJKF-FNNS-SDFG-XVZS
*/

#include <iostream>
#include <cstdlib>
using namespace std;


int Random_Number(int from, int to)
{
    return rand() % (to - from) + from;
}

char Random_Capital_Letter()
{
    return char(Random_Number(toascii('A'), toascii('Z')));
}

string Generate_Random_Key()
{
    string key;
    int counter1=4, counter2=4;

    while (counter2-- !=0)
    {
        while (counter1-- != 0)
        {
            key+=Random_Capital_Letter();
        }
        if (counter2 == 0)
        {
            continue;
        }
        key += '-';
        counter1 = 4;
    }
    return key;
}



int number_of_keys;

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    cout << "Enter the number of keys\n";
    cin >> number_of_keys;

    for (int i = 1; i <= number_of_keys; i++)
    {
        cout << "Key ["<<i<<"] : " << Generate_Random_Key() << endl;
    }






}


