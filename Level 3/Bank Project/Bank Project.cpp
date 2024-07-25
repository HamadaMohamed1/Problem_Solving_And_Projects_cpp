/*
* Bank Project
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

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

char ReadCharacter(string message)
{
    char ch;
    cout << message << endl;
    cin >> ch;
    return ch;
}

vector<string> My_Split(string str, string delimeter)
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

string JionString(vector<string> vect, string delimeter)
{
    string str = "";
    for (string& token : vect)
    {
        str = str + token + delimeter;
    }
    return str.erase(str.length() - 1, str.length());
}

string JionString(string arr[10], int length, string delimeter)
{
    string str = "";
    for (short i = 0; i < length; i++)
    {
        str = str + arr[i] + delimeter;
    }
    return str.erase(str.length() - 1, str.length());
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
    getline(cin >> ws, client.AccountNumber);

    cout << "Enter PinCode : ";
    getline(cin, client.PinCode);

    cout << "Enter Name : ";
    getline(cin, client.Name);

    cout << "Enter Phone number : ";
    getline(cin, client.Phone);

    cout << "Enter account balance : ";
    cin >> client.AccountBalance;
    return client;
}

string ConvertClientDataToString(stClient client)
{
    string ClientData = "";
    string Separator = "@//@";

    ClientData += client.AccountNumber;
    ClientData += Separator + client.PinCode;
    ClientData += Separator + client.Name;
    ClientData += Separator + client.Phone;
    ClientData += Separator + to_string(client.AccountBalance);

    return ClientData;
}

stClient ConvertStringToClientData(string str)
{
    stClient client;
    string Separator = "@//@";
    vector <string> vect = My_Split(str, Separator);

    client.AccountNumber = vect[0];
    client.PinCode = vect[1];
    client.Name = vect[2];
    client.Phone = vect[3];
    client.AccountBalance = stod(vect[4]);

    return client;
}

void PrintClientData(stClient client)
{
    if (client.AccountNumber == "")
    {
        return;
    }
    cout << client.AccountNumber << "\t";
    cout << setw(13) << client.PinCode << "\t";
    cout << setw(19) << client.Name << "\t";
    cout << client.Phone << "\t";
    cout << client.AccountBalance << "\n";
}

void AddClientToFile(stClient client, string FileName)
{
    string client1_str = ConvertClientDataToString(client);
    fstream my_file;

    my_file.open(FileName, ios::out | ios::app);
    if (my_file.is_open())
    {
        my_file << client1_str << endl;
        //cout << "Recored saved successfully" << endl;
    }
    my_file.close();
}

void DeleteFileContent(string FileName)
{
    fstream my_file;
    my_file.open(FileName, ios::out);

    my_file.clear();

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

vector<string> LoadClientsFromFileToVector(string FileName)
{
    fstream my_file;
    vector<string> vect;
    my_file.open(FileName, ios::in);
    if (my_file.is_open())
    {
        string l_line;
        while (getline(my_file, l_line))
        {
            vect.push_back(l_line);
        }
        my_file.close();
    }
    return vect;
}

void ReadClientsFromFileAndPrintThem(string FileName)
{
    vector<string> vect = LoadClientsFromFileToVector(FileName);

    stClient client;
    cout << "\t\t\t\t Client List ";
    cout << "\n___________________________________________________________________________\n";
    cout << "Account Number " << setw(7) << "| Pin Code " << setw(15) << "| Cleint Name " << setw(13) << "| Phone " << setw(17) << "| Balance";
    cout << "\n___________________________________________________________________________\n";
    for (string& i : vect)
    {
        client = ConvertStringToClientData(i);
        PrintClientData(client);
    }
    cout << "\n___________________________________________________________________________\n";
}

stClient FindClientInFile(string FileName, string AccountNumber)
{
    stClient EmptyClient, client;
    vector<string> vect = LoadClientsFromFileToVector(FileName);
    for (string& i : vect)
    {
        client = ConvertStringToClientData(i);
        if (client.AccountNumber == AccountNumber)
        {
            return client;
        }
    }
    cout << "Client with account number : " << AccountNumber << " Not found" << endl;
    return EmptyClient;
}

bool DeleteClientInFile(string FileName, string AccountNumber)
{
    char ch;
    vector <string> vect;
    string client_string;
    stClient Client_st = FindClientInFile(FileName, AccountNumber);
    if (Client_st.AccountNumber == "")
    {
        return false;
    }
    else
    {
        cout << "\n                 Client Info:\n" << endl;
        PrintClientData(Client_st);
        cout << "Are you sure you want to delete this client? : y/n" << endl;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            client_string = ConvertClientDataToString(Client_st);
            vect = LoadClientsFromFileToVector(FileName);

            DeleteFileContent(FileName);

            for (string& l_record : vect)
            {
                if (l_record == client_string)
                {
                    l_record = "";
                    continue;
                }
                stClient l_client = ConvertStringToClientData(l_record);
                AddClientToFile(l_client, FileName);
            }
            cout << "Client deleted successfully" << endl;
            return true;
        }
    }


}

bool UpdateClientInFile(string FileName, string AccountNumber)
{
    char ch;
    vector <string> vect;
    string client_string;
    stClient Client_st = FindClientInFile(FileName, AccountNumber);
    if (Client_st.AccountNumber == "")
    {
        return false;
    }
    else
    {
        cout << "\n                 Client Info:\n" << endl;
        PrintClientData(Client_st);
        cout << "Are you sure you want to update this client? : y/n" << endl;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            client_string = ConvertClientDataToString(Client_st);
            vect = LoadClientsFromFileToVector(FileName);

            DeleteFileContent(FileName);

            stClient udated_client;
            udated_client.AccountNumber = AccountNumber;
            cout << "Enter PinCode : ";
            getline(cin >> ws, udated_client.PinCode);
            cout << "Enter Name : ";
            getline(cin, udated_client.Name);
            cout << "Enter Phone number : ";
            getline(cin, udated_client.Phone);
            cout << "Enter account balance : ";
            cin >> udated_client.AccountBalance;

            string udated_client_str = ConvertClientDataToString(udated_client);

            for (string& l_record : vect)
            {
                if (l_record == client_string)
                {
                    l_record = udated_client_str;
                }
                stClient l_client = ConvertStringToClientData(l_record);
                AddClientToFile(l_client, FileName);
            }
            cout << "Client updated successfully" << endl;
            return true;
        }
    }

}
/*****************************************************************************/
enum enChoice
{
    ShowClientList = 1,
    AddNewClient,
    DeleteClient,
    UpdateClientInfo,
    FindClient,
    Exit
};
void ShowMainScreen(enChoice &UserChoice)
{
    int choice;
    cout << "=====================================================" << endl;
    cout << "                  Main Menue Screen                  " << endl;
    cout << "=====================================================" << endl;
    cout << "\t[1] Show Client List." << endl;
    cout << "\t[2] Add New Client. " << endl;
    cout << "\t[3] Delete Client. " << endl;
    cout << "\t[4] Update Client Info." << endl;
    cout << "\t[5] Find Client. " << endl;
    cout << "\t[6] Exit. " << endl;
    cout << "=====================================================" << endl;
    cout << "Choose what do you want to do ?" << endl;
    cin >> choice;
    UserChoice = (enChoice)choice;
}

void ShowClientListScreen(string FileName)
{
    ReadClientsFromFileAndPrintThem(FileName);
    cout << "Press any key to go back to Main Screen" << endl;
    system("pause >0");
}

void AddNewClientsScreen(string FileName)
{
    cout << "=====================================================" << endl;
    cout << "                Add New Client Screen                " << endl;
    cout << "=====================================================" << endl;
    ReadClientsAndSaveThemIntoFile(FileName);
    cout << "Press any key to go back to Main Screen" << endl;
    system("pause >0");
}

void DeleteClientsScreen(string FileName)
{
    string account_number;
    cout << "=====================================================" << endl;
    cout << "                Delete Client Screen                " << endl;
    cout << "=====================================================" << endl;
    do {
        cout << "Enter Account Number" << endl;
        cin >> account_number;
    }while (! DeleteClientInFile(FileName, account_number));
    cout << "Press any key to go back to Main Screen" << endl;
    system("pause >0");
}

void UpdateClientsScreen(string FileName)
{
    string account_number;
    cout << "=====================================================" << endl;
    cout << "                Update Client Screen                 " << endl;
    cout << "=====================================================" << endl;
    do {
        cout << "Enter Account Number" << endl;
        cin >> account_number;
    } while (!UpdateClientInFile(FileName, account_number));
    cout << "Press any key to go back to Main Screen" << endl;
    system("pause >0");
}

void FindClientsScreen(string FileName)
{
    string account_number;
    stClient l_client;
    cout << "=====================================================" << endl;
    cout << "                 Find Client Screen                  " << endl;
    cout << "=====================================================" << endl;
    while(true)
    {
        cout << "Enter Account Number" << endl;
        cin >> account_number;
        l_client = FindClientInFile(FileName , account_number);
        if (l_client.AccountNumber == account_number)
        {
            cout << "\n                 Client Info:\n" << endl;
            PrintClientData(l_client);
            cout << "Press any key to go back to Main Screen" << endl;
            system("pause >0");
            return;
        }
    } 
}



void BankProject(string FileName)
{
    string file_name = FileName;
    enChoice UserChoice;
    while (true)
    {
        system("cls");
        ShowMainScreen(UserChoice);
        system("cls");
        switch (UserChoice)
        {
        case enChoice::ShowClientList:
            ShowClientListScreen(file_name);
            break;
        case enChoice::AddNewClient:
            AddNewClientsScreen(file_name);
            break;
        case enChoice::DeleteClient:
            DeleteClientsScreen(file_name);
            break;
        case enChoice::UpdateClientInfo:
            UpdateClientsScreen(file_name);
            break;
        case enChoice::FindClient:
            FindClientsScreen(file_name);
            break;
        case enChoice::Exit:
            return;
            break;
        }
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));

    BankProject("Clients.txt");
    
    return 0;
}

