import random


def check_wins(player_1, player_2):  # check if player 1 wins, player_1 and player_2 are interchangeable
    if player_1 == 1 and player_2 == 3:  # if player_1 draws Rock and computer draws Scissors
        return True  # player 1 wins, return 1 for true
    elif player_1 == 2 and player_2 == 1:  # if player_1 draws Paper and computer draws Rock
        return True  # player 1 wins, return 1 for true
    elif player_1 == 3 and player_2 == 2:  # if player_1 draws Scissors and computer draws Paper
        return True  # player 1 wins, return 1 for true
    else:  # //if every condition is false
        return False  # player doesn't win, not looses, this is done to reuse the function for the computer later


def check_draw(player_1, player_2):  # player_1 and player_2 are interchangeable
    if player_1 == player_2:  # if computer_hand is equal to user_hand
        text = "{} is useless against {}"
        print(text.format(hands[player_1], hands[player_2]))  # player_1 and player_2 are index of hands


def ask_continue():  # function to ask to continue
    user_input = str(input("do you want to continue, Y/N: "))  # ask to continue and take input
    if user_input == 'Y' or user_input == 'y':  # if user inputs Y
        return True  # return 1 for true
    elif user_input == 'N' or user_input == 'n':  # if user inputs N
        return False  # return 0 for false
    else:  # if user inputs something else
        ask_continue()  # ask again


hands = ["", "Rock", "Paper", "Scissors"]
'''
declare a string array named hands with 3 element  
Rock is 1, Paper is 2, Scissors is 3
the first element 0 is nothing to simplify later
'''
user_score = 0  # set user score to 0
computer_score = 0  # set computer score to 0
while True:  # start the program loop
    user_hand = int(input("insert a move: Rock(1), Paper(2), Scissors(3): "))
    if 0 < user_hand < 4:  # if the user input accepted numbers
        computer_hand = random.randrange(1, 4)  # extract a random number from 1 to 3, this is the computer hand
        check_draw(user_hand, computer_hand)  # call function check_draw with argument user_hand, computer hand and
        # the array hands
        if check_wins(user_hand, computer_hand):  # use the output of the function as true or false
            user_score += 1  # add one to the user score
            txt = "You Won {} is strong against {}"  # user wins
            print(txt.format(hands[user_hand],hands[computer_hand]))  # user_hand is the index that call a name inside hands
        if check_wins(computer_hand, user_hand):  # use the output of the function as true or false
            computer_score += 1  # add one to the computer score
            txt = "you Lost {} is weak against {}"  # user looses
            print(txt.format(hands[user_hand],
                             hands[computer_hand]))  # user_hand is the index that call a name inside hands
    else:  # if the user inputs unaccepted
        print("error, insert a numer from 1 to 3")  # display an error message
        continue  # continue to the next loop
    if user_score == 3 or computer_score == 3:  # if one of the 2 player has 3 points
        print("| player | computer")  # display the scores
        print("|   ", user_score, "    |    ", computer_score, "     |")  # display the scores
        c = ask_continue()  # c equals to the output of the function
        if c == 0:  # if c is 0 for false
            break  # break the loop / end the program
        else:  # if c is 1 for true
            user_score = 0  # reset the user score
            computer_score = 0  # reset the computer score
            continue  # continue to the next loop
