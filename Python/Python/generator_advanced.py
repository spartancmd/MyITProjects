
# yield from

def f(n):
    print("Begin of f")
    for i in range(n):
        print(f"Yielding {i}")
        yield i
    print("End of f")

def g(n):
    print("Begin of g")
    # for x in f(n):
    #     yield x

    yield from f(n)

    print("End of g")

# for x in g(10):
#     print(x)

# send

# 1
def f(n):
    for i in range(n):
        print("Yielding", i)
        x = (yield i)
        print("Yield returned", x)

# for x in f(10):
#     print("Value is", x)

# gen = f(10)

# next(gen)

# print(gen.send(42))

# 2

def echo():
    ...
    x = yield "Let's start talking"

    while True:
        x = yield x

g = echo()

print(g.send(None))

print(g.send("Hello!"))
print(g.send("Bye!"))

# g.close()

print(g.send("42"))
print(g.send(123))

# g.throw(RuntimeError())


# 3

def h():
    x, y = (yield None)
    print(x, y)

a = h()
next(a)

a.send((1, 2))