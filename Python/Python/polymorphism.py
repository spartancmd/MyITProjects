

def f_int(x):
    ...

def f(x):
    if type(x) == int:
        f_int(x)
    elif type(x) == float:
        ...

    print("Starting f...")
    print(x + 1)


f(5)
f(3.14)
f(True)

f("Hello")
# f([1, 2, 3])