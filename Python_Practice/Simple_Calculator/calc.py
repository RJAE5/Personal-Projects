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