/*
Write a program to print round of numbers , don't use built in round function
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
float read_float_number(string message)
{
    float num;
    cout << message << endl;
    cin >> num;
    return num;
}

int random_number_in_range(int from, int to)
{
    return rand() % (to - from) + from;
}

void fill_array_in_range(int arr[100], int length , int from , int to)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = random_number_in_range(from, to);
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

void add_array_element(int arr[100], int num, int &length)
{
    length++;
    arr[length - 1] = num;
}

void copy_array(int src[100] , int dest[100] , int length)
{
    int l_length = 0;
    for (int i = 0; i < length; i++)
    {
        add_array_element(dest, src[i], l_length);
    }
}

int copy_odd_numbers_in_array(int src[100], int dest[100], int length)
{
    int l_length = 0;
    for (int i = 0; i < length; i++)
    {
        if(src[i] %2 !=0)
            add_array_element(dest, src[i], l_length);
    }
    return l_length;
}

bool is_prim(int number)
{
    int m = round(number / 2);
    for (int i = 2; i <= m; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int copy_prime_numbers_in_array(int src[100], int dest[100], int length)
{
    int l_length = 0;
    for (int i = 0; i < length; i++)
    {
        if (is_prim(src[i]))
            add_array_element(dest, src[i], l_length);
    }
    return l_length;
}

int copy_distnict_numbers_in_array(int src[100], int dest[100], int length)
{
    int l_length = 0;
    add_array_element(dest, src[0], l_length);
    for (int i = 1; i < length; i++)
    {
        if (-1 == linear_search(dest, l_length, src[i]))
        {
            add_array_element(dest, src[i], l_length);
        }
    }
    return l_length;
}
bool compare_2_arrays(int arr1[100] , int arr2[100] , int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
bool is_palindrome_array(int arr[100] , int length)
{
    int reversed_array[100];
    reverse_array(arr, reversed_array, length);
    return compare_2_arrays(arr , reversed_array , length);
}
int count_of_odd_numbers_in_array(int arr[100], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 != 0)
            count++;
    }
    return count;
}
int count_of_even_numbers_in_array(int arr[100], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 == 0)
            count++;
    }
    return count;
}
int count_of_positive_numbers_in_array(int arr[100], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
            count++;
    }
    return count;
}
int count_of_nigative_numbers_in_array(int arr[100], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
            count++;
    }
    return count;
}

int my_absolute(int num)
{
    if (num > 0)
        return num;
    else
        return (num * -1);
}

float get_fraction_part(float number)
{
    return number - (int)number;
}
int my_round(float number)
{
    float fraction_part = get_fraction_part(number);
    int int_part = (int)number;
    if (fraction_part >= 0.5)
    {
        int_part++;
    }
    return int_part;
}
int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));
    float number = read_float_number("Enter a number");

    cout << "The result = " << my_round(number) << endl;
  
	return 0;
}
