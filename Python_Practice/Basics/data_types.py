# str
x = "Hello World"
print(x)
print(type(x))

# int
x = 20
print(x)
print(type(x))
# ints are stated to have unlimited length

# float
x = 2.5
print(x)
print(type(x))

# complex
x = 1j # j is the imaginary part
print(x)
print(type(x))

# list
x = [1, 2, 3]
print(x)
print(type(x))

# tuple
x = (1, 2, 3)
print(x)
print(type(x))

# range
x = range(6)
print(x)
print(type(x))

# dict
x = {"name" : "John", "age" : 36}
print(x)
print(type(x))

# set
x = {"apple", "banana", "cherry"}
print(x)
print(type(x))

# frozenset
x = frozenset({"apple", "banana", "cherry"})
print(x)
print(type(x))

# bool
x = True
print(x)
print(type(x))

# bytes
x = b"Hello"
print(x)
print(type(x))

# bytearray
x = bytearray(5)
print(x)
print(type(x))

# memoryview
x = memoryview(bytes(5))
print(x)
print(type(x))

# NoneType
x = None
print(x)
print(type(x))


# Can convert by casting
x = 1
y = 2.0
z = 3j

a = float(x)
b = complex(y)
c = int(y)
# Can't convert complex to anything non-complex
print(a, b, c)