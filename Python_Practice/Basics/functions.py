# Global variable to be used in a function
x = "This is a global variable"

# Simple function declaration
def globalVarFunc() :
    print(x)

def localVarFunc() :
    # Creating local variable which will only exist within func
    x = "This is a local variable"
    print(x)

def newGlobalVar() :
    # This function create a global variable
    global y # Worth noting that you can't assign in same line
    y = "Wow (Also global variable)"

# Call functions
globalVarFunc()
localVarFunc()
newGlobalVar()

print("")
print("Main using global variables:")
print(x)
print(y)