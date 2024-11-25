# Variables don't need a type when declaring and can change
x = 1
print(x)
print(type(x))

x = "Rykir"
x = 'Rykir' #Single or double quotes don't matter
print(x)
print(type(x))

#Casting exits for cases like this
x = str(3)
y = int(3)
z = float(3)

print(x, y, z)

# Variable names are case sensitive 
a = 1
A = 2
print(a, A)

# Variables can only start with letters of underscore `_`
# Can only contain alphanumeric characters and the underscore
# Can NOT be any keyword

# Can assign multiple vars to different things on one line
a, b, c = "First", "Second", "Third"
print(a)
print(b)
print(c)

# Can also assign one thing to multiple variables
a = b = c = "Letter"
print(a)
print(b)
print(c)

# Assign variables to a collection and extract them
animals = ["Dog", "Cat", "Fish"]
a, b, c = animals
print(a)
print(b)
print(c)