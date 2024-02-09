

def f(a, b):
    return a + b

# generic function
def function_name(param1, param2):
    # function body

    # return statements
    pass

def f1(): # no params
    return 0

def f2(a, b): # no return statement
    print(a, b)

def f3(): # no params, no return statement
    print(5)

def f4(*args): # variadic function
    print(args)
    print(type(args))

print(f(1, 2))    # 3
print(f1())       # 0
print(f2(3, 5))   # 3 5 None
print(f3()) # 5 None
print(f4())
f4(1, 2)
f4(1)
f4(1, "Hello", True)