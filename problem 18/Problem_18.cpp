/*
Write a program to reada text and incrypt it ,decrypt it


*/
#include <iostream>
#include <string>
using namespace std;

int read_number(string message)
{
    int num;
    cout << message << endl;
    cin >> num;
    return num;
}
int reverse_number(int num)
{
    int reversed_number =0 , remainder;
    while (num > 0)
    {
        remainder = num % 10;
        num /= 10;
        reversed_number = remainder + reversed_number * 10;
    }
    return reversed_number;
}

string read_text()
{
    string text;
    cout << "Enter a text" << endl;
    cin >> text;
    return text;
}

string incrypt_text(string text, int key)
{
    for (int i = 0 ; i < text.length() ; i++)
    {
        text[i] = char((int)text[i] + key);
    }
    return text;
}

string decrypt_text(string text, int key)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] - key);
    }
    return text;
}

int main()
{
    int key =3;
    string inc_text, dec_text;
    string or_text = read_text();

    inc_text = incrypt_text(or_text, key);
    dec_text = decrypt_text(inc_text, key);


    cout << "Original message : " << or_text << endl;
    cout << "Incrypted message : " << inc_text << endl;
    cout << "Decrypted message : " << dec_text << endl;
    return 0;
}

