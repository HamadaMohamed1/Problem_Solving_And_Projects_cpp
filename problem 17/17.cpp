/*
write a program to guess a 3-letter password (all capital)

Input : 
AAF
Output:
Trial[1] : AAA
Trial[2] : AAB
Trial[3] : AAC
Trial[4] : AAD
Trial[5] : AAE
Trial[6] : AAF

Password is AAF
Found after 6 Trial(s)

*/

#include <iostream>
using namespace std;
int main()
{


	// A = 65 , Z = 90
	string password;
	int counterTrials = 0;
	cout << "Enter the password" << endl;
	cin >> password;

	int i, j, k;
	for (i = 65; i <= 90; i++)
	{
		for (j = 65; j <= 90; j++)
		{
			for (k = 65; k <= 90; k++)
			{
				cout <<"Trial("<< counterTrials <<") : " << char(i) << char(j) << char(k) << endl;
				counterTrials++;
				if (password[0] == char(i) && password[1] == char(j)&& password[2] == char(k))
				{
					break;
				}
			}
			if (password[0] == char(i) && password[1] == char(j) && password[2] == char(k))
			{
				break;
			}
		}
		if (password[0] == char(i) && password[1] == char(j) && password[2] == char(k))
		{
			break;
		}
	}
	cout << "The password is " << char(i) << char(j) << char(k) << endl;
	cout << "Number of trials = " << counterTrials << endl;




return 0;
}