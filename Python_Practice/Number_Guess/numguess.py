# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#   Author:    Rykir Evans
#   Email:     rykirjoe@yahoo.com
#   Title:     Number Guessing Game
#   Repo:      Personal_Projects
#   Date:      1-15-2025 (Initial Creation)
#
#   Description:
#        This program was made to reinforce the usage of loops, flags, and
#        introduce the random library. Utilizing the terminal to interact
#        with the user, it prompts for a random number between 1 and 100.
#        Subsequently, the user will attempt to guess the random number
#        until they have done so successfully, using hints from the game.
# 
#   Usage:
#        Other than simplistic fun, this game is for nothing more than to
#        reinforce learning concepts of the Python Programming Language.
#
#   Files:
#        numguess.py
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #   

import random

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#
#    Function: game()
#
#    Description:
#          Main game loop handling guesses and number generation
#
#    Params:
#          None
#
#    Returns:
#          None
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
def game():
    # Initial game prompt
    print("Please enter a number between 1 and 100 to try and guess it correctly.")

    # Game variables
    rand_num = random.randint(1,100)
    counter = 1
    guess = None

    # Main game loop
    while guess != rand_num:
        try:
            # Obtain initial guess
            guess = int(input(f"\nGuess #{counter}: "))

            # Compare guess to target
            if guess < rand_num:
                print("Too low! Try a bigger number...")
            elif guess > rand_num:
                print("Too high! Try a smaller number...")
            else:
                # Grammar handling
                if counter == 1:
                    grammar = "guess."
                else:
                    grammar = "guesses."
                
                # Winning statement
                print(f"Congrats! Your guess, {guess}, is the correct number. You achieved this in {counter} " + grammar)
                break

            # Increment for guesses
            counter += 1

        # Error handling
        except ValueError:
            print("That is not a valid number, please try again.")
            
# End of game()



###########################################################################
#               ___  ___      _        ______           _                 #
#               |  \/  |     (_)       | ___ \         | |                #
#               | .  . | __ _ _ _ __   | |_/ / ___   __| |_   _           #
#               | |\/| |/ _` | | '_ \  | ___ \/ _ \ / _` | | | |          #
#               | |  | | (_| | | | | | | |_/ / (_) | (_| | |_| |          #
#               \_|  |_/\__,_|_|_| |_| \____/ \___/ \__,_|\__, |          #
#                                                          __/ |          #
#                                                         |___/           #
###########################################################################    
                 

# Initial Welcome
print("Welcome to the Random Number Guessing Game")

# Initial call to run game
game()

# Restart flag
Playing = True

# Restart loop
while Playing:
    answer = input("Would you like to play again? y/n")

    if answer == "y" or answer == "Y":
        game()
    elif answer == "n" or answer == "N":
        print("Sorry to see you go, hope you had fun!")
        Playing = False
    else:
        print("Invalid answer, please try again.")