
# list
a = [1, 2, 3]
a[0] = 2
a[1] = 2
a[2] = 2

print(a)

# tuple
a = (1, 2, 3)
# a[0] = 1  -> ERROR
a = (1, 2) + (3, 4)
print(a)
a = (1, True, "Hello", 3.14)
print(a)

a = ()
print(type(a), a)

a = (1,)
print(type(a), a)


a = (1, 2, 3, 4)
a = (i + 1 for i in range(4))  # NOT A TUPLE!!!!
print(a) # generator object