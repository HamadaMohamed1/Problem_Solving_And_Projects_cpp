/*
Project #1
Problem : 
Write a small game program for Stone , Paper , Scissor (حجر ورقه مقص) 
The paper wins over the stone , The stone wins over the scissor , The scissor wins over the paper
*/
#include <iostream>
using namespace std;

/******************************************************************/
enum players {
    User = 0 ,
    Computer ,
    Draw //تعادل
};
enum StonePaperScissor
{
    Stone = 1 ,
    Paper ,
    Scissor
};
int random_number_in_range(int from, int to)
{
    return rand() % (to - from) + from;
}
int read_number()
{
    int num;
    cin >> num;
    while (num <=0)
    {
        cout << "Enter a positive number" << endl;
        cin >> num;
    }
    return num;
}

players check_the_winner(StonePaperScissor user_choice , StonePaperScissor computer_choice)
{
   // The paper wins over the stone, The stone wins over the scissor, The scissor wins over the paper 
    if (user_choice == StonePaperScissor::Paper && computer_choice == StonePaperScissor::Stone)
    {
       return players::User;
    }
    else if(computer_choice == StonePaperScissor::Paper && user_choice == StonePaperScissor::Stone)
    {
        return players::Computer;
    }
    else if (user_choice == StonePaperScissor::Stone && computer_choice == StonePaperScissor::Scissor)
    {
        return players::User;
    }
    else if (computer_choice == StonePaperScissor::Stone && user_choice == StonePaperScissor::Scissor)
    {
        return players::Computer;
    }
    else if (user_choice == StonePaperScissor::Scissor && computer_choice == StonePaperScissor::Paper)
    {
        return players::User;
    }
    else if (computer_choice == StonePaperScissor::Scissor && user_choice == StonePaperScissor::Paper)
    {
        return players::Computer;
    }
    else if ((int)user_choice == (int)computer_choice)
    {
        return players::Draw;
    }   
}

void print_result(players the_winner, StonePaperScissor user_choice , StonePaperScissor computer_choice)
{
    string user_ch, computer_ch , winner;

    user_ch = user_choice == StonePaperScissor::Paper ? "Paper" : user_choice == StonePaperScissor::Scissor ? "Scissor" : "Stone";
    computer_ch = computer_choice == StonePaperScissor::Paper ? "Paper" : user_choice == StonePaperScissor::Scissor ? "Scissor" : "Stone";
    if (the_winner == players::Computer)
    {
        system("Color 4E"); // Red color
        winner = "Computer";
    }
    else if (the_winner == players::User)
    {
        system("Color 2E");// Green color
        winner = "Player";
    }
    else
    {
        system("Color 6E");// Yellow color
        winner = "No Winner";
    }
    
    cout << "Player choise   : " << user_ch << endl;
    cout << "Computer choise : " << computer_ch << endl;
    cout << "The winner      : [" << winner << "]" << endl;
}

void print_final_game_result(int game_rounds, int player_won_times ,int computer_won_times ,int draw_times )
{
    cout << "\n-----------------------------------------------------------------------------" << endl;
    cout << "--------------------------------- Game Over ---------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "--------------------------------- [ Game Results ]---------------------------\n" << endl;
    cout << "Game Rounds        : " << game_rounds << endl;
    cout << "Player Won Times   : " << player_won_times << endl;
    cout << "Computer Won Times : " << computer_won_times << endl;
    cout << "Draw Times         : " << draw_times << "\n" << endl;
    cout << "-----------------------------------------------------------------------------\n" << endl;
}

void increment_won_times(players the_winner ,int& player_won_times , int& computer_won_times , int& draw_times)
{
    if (the_winner == players::User)
    {
        player_won_times++;
    }
    else if (the_winner == players::Computer)
    {
        computer_won_times++;
    }
    else
    {
        draw_times++;
    }
}

void start_game()
{
    char yes_no;
    int number_of_round , choice;
    players the_winner;
    StonePaperScissor user_choice, computer_choice;
    do {
        int player_won_times = 0, computer_won_times = 0, draw_times = 0;

        cout << "How many rounds the game will be?" << endl;
        number_of_round = read_number();
        for (int i = 1; i <= number_of_round; i++)
        {
            cout << "Enter your choice [1]: Stone , [2]: Paper , [3]: Scissor" << endl;
            user_choice = (StonePaperScissor)read_number();
            computer_choice = (StonePaperScissor)random_number_in_range(1, 3);
            the_winner = (players)check_the_winner(user_choice, computer_choice);

            increment_won_times(the_winner, player_won_times, computer_won_times, draw_times);

            cout << "--------------------------------- Round [" << i << "] ---------------------------------" << endl;
            print_result(the_winner, user_choice, computer_choice);
            cout << "-----------------------------------------------------------------------------" << endl;
        }
        print_final_game_result(number_of_round , player_won_times,computer_won_times,draw_times);
        cout << "Do you want to play again? Y/N" << endl;
        cin >> yes_no;
    } while (yes_no == 'y' || yes_no == 'Y');
    
    
    
}


int main()
{
    //Seeds the random number generator in C++, called only once    
    srand((unsigned)time(NULL));
   
    start_game();
    
	return 0;
}
