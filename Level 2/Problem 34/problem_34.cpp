/*
Write a program to read how many keys to generate and fill them in array ,
read number and return its index in array if found , otherwise return -1
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

void print_array(string arr[100] , int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << "\n";
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

char get_random_char()
{
    return char(random_number_in_range(65, 90));
}

string generate_random_key()
{
    string key;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            key += get_random_char();
        }
        if (i == 3)
            continue;
        key += '-';
    }
    return key;
}
void fill_array_with_keys(string arr[100] ,int length)
{
    string key;
    for (int i = 0; i < length; i++)
    {
        key = generate_random_key();
        arr[i] = key;
    }
}

int linear_search(int arr[100] ,int length , int number)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == number)
        {
            return i;
            break;
        }
    }
    return -1;
}

int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));
     
    int length , number;
    int arr[100];
    length= read_number("Enter the length");
    fill_array(arr, length);
    print_array(arr, length);
    number = read_number("Enter the number");
    cout << "Index = " << linear_search(arr , length , number);


	return 0;
}
