#include <iostream>
#include <cstdlib>
using namespace std;
int check_wins(int player_1, int player_2)//check if player 1 wins, player_1 and player_2 are interchangeable
{
    if (player_1 == 1 && player_2 == 3)//if player_1 draws Rock and computer draws Scisors
        return 1;//player 1 wins, return 1 for true
    else if (player_1 == 2 && player_2 == 1)//if player_1 draws Paper and computer draws Rock
        return 1;//player 1 wins, return 1 for true
    else if (player_1 == 3 && player_2 == 2)//if player_1 draws Scisors and computer draws Paper
        return 1;//player 1 wins, return 1 for true
    else//if every condition is false
        return 0;//player doesn't wins, not looses, this is done to reuse the function for the computer later
}
void check_draw(int player_1, int player_2, string hands[])//player_1 and player_2 are interchangeable
{
    if (player_1 == player_2)//if computer_hand is equal to user_hand
        cout << hands[player_1] << " is useless against " << hands[player_2] << endl;//player_1 and player_2 are index of hands
}
int ask_continue()//function to ask to continue
{
    char input;//declare input
    cout << "do you want to continue, Y/N: "; cin >> input;//ask to continue and take input
    if (input == 'Y' || input == 'y')//if unser inputs Y
    {
        return 1;//return 1 for true
    }
    else if (input == 'N' || input == 'n')//if user inputs N
    {
        return 0;//return 0 for false
    }
    else//if user inputs something else
    {
        ask_continue();//ask again
    }
}
int main()
{
    int user_hand;//declare user hand
    int computer_hand;//declare computer hand
    int user_score = 0;//declare user score
    int computer_score = 0;//declare computer score
    string hands[] = { "","Rock","Paper","Scisors" };
    //declare a string array named hands with 3 element  
    //Rock is 1, Paper is 2, Cisors is 3
    //the first element 0 is empty to simplidy later
    while (true)//start the programm loop
    {
        cout << "insert a move Rock(1), Paper(2), Scisors(3): "; cin >> user_hand;
        if (user_hand > 0 && user_hand < 4)//if the user input accepted numbers
        {
            computer_hand = rand() % 3 + 1;// estract a random number from 1 to 3, this is the computer hand
            check_draw(user_hand, computer_hand, hands);//call function check_draw with argument user_hand, computer hand and the array hands
            if (check_wins(user_hand, computer_hand) == 1)//use the output of the function as true or false 
            {
                user_score++;//add one to the user score
                cout << "You Won ";//user wins
                cout << hands[user_hand] << " is strong against " << hands[computer_hand] << endl;//user_hand is the index that call a name inside hands
            }
            if (check_wins(computer_hand, user_hand) == 1)//use the output of the function as true or false
            {
                computer_score++;//add one to the computer score
                cout << "You lost ";//user looses
                cout << hands[user_hand] << " is weak against " << hands[computer_hand] << endl;//user_hand is the index that call a name inside hands
            }
        }
        else//if the user inputs uneccepted
        {
            cout << "error, inser a numer from 1 to 3\n";//display an error message
            continue;//continue to the next loop
        }
        if (user_score == 3 || computer_score == 3)//if one of the 2 player has 3 points
        {
            cout << "| player | computer |\n";//display the scores
            cout << "|   " << user_score << "    |    " << computer_score << "     |\n";//display the scores
            int c = ask_continue();//c equals to the output of the function
            if (c == 0)//if c is 0 for false
            {
                break;//break the loop / end the program
            }
            else//if c is 1 for true
            {
                user_score = 0;//reset the user score
                computer_score = 0;//reset the computer score
                continue;//continue to the next loop
            }
        }
    }
}