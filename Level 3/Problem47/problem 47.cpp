/*
* Problem #47
* Write a program to ask you to enter cleints and save them into file
*/
#include <iostream>
#include <cmath>
#include <string>
#include<iomanip>
#include <vector>
#include <fstream>
using namespace std;

int ReadNumber(string message)
{
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}

int RandomNumberInRange(int from, int to)
{
    return rand() % (to - from) + from;
}

void FillMatrix3x3WithRandomNumbers(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = RandomNumberInRange(1, 20);
        }
    }
}

void PrintMatrix3x3(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void PrintSumOfRaws(int arr[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of raw [" << i + 1 << "] = " << sum << endl;
        sum = 0;
    }
}

void PrintSumOfCol(int arr[3][3])
{
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of col [" << j + 1 << "] = " << sum << endl;
        sum = 0;
    }
}

void CopySumOfRaws(int src[3][3], int dest[3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += src[i][j];
        }
        dest[i] = sum;
        sum = 0;
    }
}

void CopySumOfCol(int src[3][3], int dest[3])
{
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            sum += src[i][j];
        }
        dest[j] = sum;
        sum = 0;
    }
}
void PrintArray1D(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << i + 1 << " : " << arr[i] << endl;
    }
}

void FillMatrixWithOrderedNumber(int arr[3][3], short from)
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = from++;
        }
    }
}

void TransposeMatrix(int src[3][3], int dest[3][3])
{
    /*
            1  2  3         1  4  7
            4  5  6     =>  2  5  8
            7  8  9         3  6  9
    */
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            dest[j][i] = src[i][j];
        }
    }
}

void Multiply2Matrecies(int src1[3][3], int src2[3][3], int dest[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            dest[i][j] = src1[i][j] * src2[i][j];
        }
    }
}

void PrintMiddleRaw(int arr[3][3])
{
    short i;
    cout << "Middle raw : ";
    for (i = 0; i < 3; i++)
    {
        cout << arr[1][i] << "  ";
    }
    cout << endl;
}

void PrintMiddleCol(int arr[3][3])
{
    short i;
    cout << "Middle column : ";
    for (i = 0; i < 3; i++)
    {
        cout << arr[i][1] << "  ";
    }
    cout << endl;
}

int SumOfMatrix(int arr[3][3])
{
    short i, j;
    int sum = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

bool AreEquals(int arr1[3][3], int arr2[3][3])
{
    bool ret;
    ret = SumOfMatrix(arr1) == SumOfMatrix(arr2) ? true : false;
    return ret;
}

bool AreTypical(int arr1[3][3], int arr2[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool IsIdentity(int arr[3][3])
{
    //  identity matrix
    //  1   0   0
    //  0   1   0
    //  0   0   1
    short i, j;
    for (i = 0; i < 3; i++)
    {                                                                  
        for (j = 0; j < 3; j++)
        {
            if ((i==j) && (arr[i][j] != 1))
            {
                return false;
            }
            else if ((i!=j) && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IsScalar(int arr[3][3])
{
    //  scalar matrix
    //  8   0   0
    //  0   8   0           diagonal are equals numbers & the rest element are zeros
    //  0   0   8           
    short i, j;
    int diagonal_element = arr[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if ((i == j) && (arr[i][j] != diagonal_element))
            {
                return false;
            }
            else if ((i != j) && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int CountNumberInMatrix(int arr[3][3] , int number)
{
    int counter = 0;
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == number)
            {
                counter++;
            }
        }
    }
    return counter;
}

bool IsSparce(int arr[3][3])
{
    //  Sparce matrix : number of zeros in matrix larger than the rest numbers
    short i, j;
    int zero_count = 0 , rest_numbers_count = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                zero_count++;
            }
            else
            {
                rest_numbers_count++;
            }
        }
    }
    if (zero_count > rest_numbers_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LinearSearch(int arr[3][3], int number)
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] == number)
                return true;
        }
    }
    return false;
}

void PrintIntersectedNumbers(int arr1[3][3], int arr2[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (LinearSearch(arr2, arr1[i][j]))
            {
                cout << arr1[i][j] << "\t";
            }
        }
    }
    cout << endl;
}

int GetMin(int arr[3][3])
{
    short i, j;
    int min = arr[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int GetMax(int arr[3][3])
{
    short i, j;
    int  max = arr[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

void PrintMin_MaxOfMatrix(int arr[3][3])
{
    cout << "Min number : " << GetMin(arr) << endl;
    cout << "Max number : " << GetMax(arr) << endl;
}

bool IsPalindrom(int arr[3][3])
{
    short i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i][0] != arr[i][2])
            {
                return false;
            }
        }
    }
    return true;
}

void PrintFibonacciSeries(int num)
{
    int prievus1 = 0, prievus2 = 1;
    int fibonacci_number = 1;
    cout << fibonacci_number << "\t";
    for (int i = 1; i < num; i++)
    {
        fibonacci_number = prievus1 + prievus2;
        cout << fibonacci_number << "\t";  
        prievus1 = prievus2;
        prievus2 = fibonacci_number;
    }
    cout << endl;
}

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin , str);
    return str;
}

void Print1stLetterOfString(string str)
{
    short i;
    cout << str[0] << "\t";
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            cout << str[i+1] << "\t";
        }
    }
}

void Convert1stToUppercase(string &str)
{
    short i;
    str[0] = toupper(str[0]);
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str[i+1] = toupper(str[i+1]);
        }
    }
}

void Convert1stToLowercase(string& str)
{
    short i;
    str[0] = tolower(str[0]);
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str[i + 1] = tolower(str[i + 1]);
        }
    }
}

void ConvertToUppercase(string& str)
{
    for (short i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

void ConvertToLowercase(string& str)
{
    for (short i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

char ReadCharacter(string message)
{
    char ch;
    cout << message << endl;
    cin >> ch;
    return ch;
}

char InvertCharacterCase(char ch)
{
    if (isupper(ch))
    {
        return tolower(ch);
    }
    else 
    {
        return toupper(ch);
    }
}

void InvertStringCase(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = InvertCharacterCase(str[i]);
    }
}

int CountCapitalLetters(string str)
{
    int counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
            counter++;
    }
    return counter;
}

int CountSmallLetters(string str)
{
    int counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            counter++;
    }
    return counter;
}

int CountCharInString(string str, char ch , bool MatchCase)
{
    int counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (MatchCase)
        {
            if (str[i] == ch)
                counter++;
        }
        else
        {
            if (tolower(str[i]) == ch)
                counter++;
        }
    }
    return counter;
}

bool CharIsVowel(char ch)
{
    if (   ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' 
        || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int CountVowles(string str)
{
    int counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (CharIsVowel(str[i]))
            counter++;
    }
    return counter;
}

void PrintVowles(string str)
{
    cout << "Vowles :\t";
    for (short i = 0; i < str.length(); i++)
    {
        if (CharIsVowel(str[i]))
            cout << str[i] << "\t";
    }
    cout << endl;
}

void PrintEachWordInString(string str)
{
    string delim = " "; // delimiter      
    cout <<"\nYour string wrords are: \n\n"; 
    short pos = 0; 
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters  
    while ((pos = str.find(delim)) != std::string::npos)
    {
        sWord = str.substr(0, pos); // store the word   
        if (sWord !="") 
        { 
            cout << sWord << endl;         
        } 
        str.erase(0, pos + delim.length());  /* erase() until positon and move to next word. */
    } 
    if(str != "") 
    {
        cout << str << endl; // it print last word of the string.    
    }
}

void CountWordsInString(string str)
{
    string delim = " "; // delimiter    
    int counter = 0;
    cout << "\nNumber of words : ";
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters  
    while ((pos = str.find(delim)) != std::string::npos)
    {
        counter++;
        str.erase(0, pos + delim.length());  /* erase() until positon and move to next word. */
    }
    if (str != "")
    {
        counter++;
    }
    cout << counter << endl;
}

vector<string> My_Split(string str , string delimeter)
{
    vector<string> tokens;     
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters  
    while ((pos = str.find(delimeter)) != std::string::npos)
    {
        sWord = str.substr(0, pos); // store the word   
        if (sWord != "")
        {
            tokens.push_back(str.substr(0, pos));
        }
        str.erase(0, pos + delimeter.length());  /* erase() until positon and move to next word. */
    }
    if (str != "")
    {
        tokens.push_back(str.substr(0, pos)); // store last word of the string.    
    }
    return tokens;
}

void PrintVector(vector<string> vect)
{
    for (string& str : vect)
    {
        cout << str << endl;
    }
}

string TrimLeft(string str)
{
    char delimiter = ' ';
    for (short i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            return str.substr(i , str.length()-1);
    }
    return "";
}
string TrimRight(string str)
{
    char delimiter = ' ';
    for (short i = str.length()-1; i >= 0; i--)
    {
        if (str[i] != ' ')
            return str.substr(0 , i+1);
    }
    return "";
}
string TrimAll(string str)
{
    return TrimRight(TrimLeft(str));
}

string JionString(vector<string> vect , string delimeter)
{
    string str ="";
    for (string& token : vect)
    {
        str = str + token + delimeter;
    }
    return str.erase(str.length()-1, str.length());
}

string JionString(string arr[10] , int length, string delimeter)
{
    string str = "";
    for (short i = 0 ; i < length ;i++)
    {
        str = str + arr[i] + delimeter;
    }
    return str.erase(str.length() - 1, str.length());
}

string ReverseString(string str)
{
    string reversed_string = "";
    vector <string> original_string = My_Split(str, " ");
    while (!original_string.empty())
    {
        reversed_string += original_string.back();
        reversed_string += " ";
        original_string.pop_back();
    }
    return reversed_string;
}

string ReplaceWordInString(string str, string from_word , string to_word)
{
    string newstring = str;
    short pos = newstring.find(from_word);
    while (pos != std::string::npos)
    {
        newstring = newstring.replace(pos, to_word.length() , to_word);
        pos = newstring.find(from_word);
    }
    return newstring;
}

string ReplaceWordInStringCustom(string str, string from_word, string to_word)
{
    string newstring;
    vector <string> str_vect = My_Split(str , " ");
    for (string& st : str_vect)
    {
        if (st == from_word)
        {
            st = to_word;
        }
    }
    for (string& st : str_vect)
    {
        newstring += st;
        newstring += " ";
    }
    return newstring;
}

string RemovePuncituationsFromString(string str)
{
    string newstring = "";
    for (short i = 0; i < str.length(); i++)
    {
        if (!ispunct(str[i]))
        {
            newstring += str[i];
        }
    }
    return newstring;
}

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient ReadNewClient()
{
    stClient client;
    cout << "Enter account number : ";
    getline(cin >>ws , client.AccountNumber);

    cout << "Enter PinCode : ";
    getline(cin, client.PinCode);

    cout << "Enter Name : ";
    getline(cin, client.Name);

    cout << "Enter Phone number : ";
    getline(cin, client.Phone);

    cout << "Enter account balance : ";
    cin >>client.AccountBalance;
    return client;
}

string ConvertClientDataToString(stClient client)
{
    string ClientData = "";
    string Separator = "@//@";

    ClientData += client.AccountNumber;
    ClientData += Separator + client.PinCode ;
    ClientData += Separator + client.Name;
    ClientData += Separator + client.Phone;
    ClientData += Separator + to_string(client.AccountBalance);

    return ClientData;
}

stClient ConvertStringToClientData(string str)
{
    stClient client;
    string Separator = "@//@";
    vector <string> vect = My_Split(str , Separator);

    client.AccountNumber = vect[0];
    client.PinCode = vect[1];
    client.Name = vect[2];
    client.Phone = vect[3];
    client.AccountBalance = stod(vect[4]);

    return client;
}

void PrintClientData(stClient client)
{
    cout << "AccountNumber : " << client.AccountNumber << endl;
    cout << "PinCode       : " << client.PinCode << endl;
    cout << "Name          : " << client.Name << endl;
    cout << "Phone         : " << client.Phone << endl;
    cout << "AccountBalance: " << client.AccountBalance << endl;
}

void AddClientToFile(stClient client , string FileName)
{
    string client1_str = ConvertClientDataToString(client);
    fstream my_file;
    static int client_number = 1;

    my_file.open(FileName, ios::out | ios::app);
    if (my_file.is_open())
    {
        my_file << client_number++ << " : " << client1_str << endl;
        cout << "Recored saved successfully" << endl;
    }
    my_file.close();
    
}

void ReadClientsAndSaveThemIntoFile(string FileName)
{
    char ch;
    do 
    {
        stClient client = ReadNewClient();
        AddClientToFile(client, FileName);
        cout << "Do you want to add new client ? y:n" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}


int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));

    ReadClientsAndSaveThemIntoFile("Clients.txt");

    return 0;
}

