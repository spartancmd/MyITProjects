
# f is a decorator
def f(func):
    def inner(a, b):
        print("Start")
        func(a, b)
        print("Finish")

    return inner

@f
def add(x, y):
    print("Add beginning")
    res = x + y
    return res

@f
def sub(x, y):
    print("Sub beginning")
    res = x - y
    return res

# same that @
# add = f(add)
# sub = f(sub)

a = add(3, 5)
b = add(3, 5)
c = sub(3, 5)

