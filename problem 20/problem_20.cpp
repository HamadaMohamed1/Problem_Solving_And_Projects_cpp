/*
write a program to print random Small letter , Capital letter , Special character , and Digit in order


Output:
i
G
$
7

*/


#include <iostream>
#include <cstdlib>
using namespace std;


int Random_number(int from, int to)
{
    return rand()%(to - from) + from;
}

char Random_small_letter()
{
    return char(Random_number( toascii('a'), toascii('z') )); // 'a' = 97 , 'z' = 122
}

char Random_capital_letter()
{
    return char(Random_number( toascii('A'), toascii('Z') )); // 'a' = 65 , 'z' = 90
}
char Random_special_character()
{
    return char(Random_number( toascii('#'), toascii('&') )); // '#' = 35 , '&' = 38
}


typedef enum {
    SMALL_LETTER = 1 ,
    CAPITAL_LETTER ,
    SPECIAL_CHARACTER ,
    DIGIT ,
    ALL
}random_t;

int number;

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    cout << "Choose from the list\n";
    cout << "1- small letter\n";
    cout << "2- capital letter\n";
    cout << "3- special character\n";
    cout << "4- digit\n";
    cout << "5- all \n";

    cin >> number;

    switch (number)
    {
    case SMALL_LETTER:
        cout << Random_small_letter() << endl;
        break;
    case CAPITAL_LETTER:
        cout << Random_capital_letter() << endl;
        break;
    case SPECIAL_CHARACTER:
        cout << Random_special_character() << endl;
        break;
    case DIGIT:
        cout << Random_number(0,100) << endl;
        break;
    case ALL:
        cout << Random_small_letter() << endl;
        cout << Random_capital_letter() << endl;
        cout << Random_special_character() << endl;
        cout << Random_number(0,100) << endl;
        break;
    default:
        break;
    }





}

