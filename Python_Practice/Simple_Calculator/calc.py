# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#   Author:    Rykir Evans
#   Email:     rykirjoe@yahoo.com
#   Title:     Simple Calculator
#   Repo:      Personal_Projects
#   Date:      1-15-2025 (Initial Creation)
#
#   Description:
#        This program was made to reinforce the usage of conditionals,
#        simple comparisons, error checking, and formatted strings. The 
#        program will prompt the user for two numbers and a desired
#        operation. It will then perform said operation if no error occurs.
# 
#   Usage:
#        Other than simplistic calculations, this program serves as more
#        of a learning experience than anything.
#
#   Files:
#        calc.py
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 


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

# Prompt for username input
user_name = input("Please enter your name: ")

# Welcome message
print(f"Hello {user_name}, welcome to a simple calculator. Please follow the directions below:")
print("")

# Obtaining numbers
num1 = int(input("Please enter the first number: "))
num2 = int(input("Please enter the second number: "))

# Operations list
print("Using the list below, please indicate an operation.")
print("+ | Addition")
print("- | Substraction")
print("* | Multiplication")
print("/ | Division")
print("")

operation = input()
result = None

# if - elif chain for each operation
if(operation == '+'):
    result = num1 + num2

elif(operation == '-'):
    result = num1 - num2

elif(operation == '*'):
    result = num1 * num2

elif(operation == '/'):
    # Basic error handling
    if(num2 == 0):
        print("Error: Divide by 0")
        pass
    else:
        result = num1 / num2
else:
    print("Invalid operation, initiating self-destruct...")
    pass

# Don't print result if we don't have one
if(result != None):
    print("Calculating...")
    print(f"The answer to your calculation is {result}!")
else:
    pass
