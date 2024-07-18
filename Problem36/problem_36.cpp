/*
Write a program to dynamically read numbers and save them in array , max size = 100 ,
allocate simi-dynamic array length
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

bool is_number_in_array(int arr[100], int length, int number)
{
    if (linear_search(arr, length, number) == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void add_num_to_array(int arr[100], int num, int &length)
{
    length++;
    arr[length - 1] = num;
}

int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));
     
    int array[100];
    int length = 0;
    int number;
    int choice;
    do {
        number = read_number("please enter a number");
        add_num_to_array(array, number, length);
        cout << "do you want to add more numbers? 0 : NO  ,  1 : Yes" << endl;
        cin >> choice;
    } while (choice == 1);

    cout << "Array length = " << length<<endl;
    print_array(array, length);


	return 0;
}
