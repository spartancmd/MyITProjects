


# lambda (lambda function)
# in python: unnamed function

# def squarify(x):
#     return x**2


a = [1, 2, 3, 4, 5, 6, 7]

# for idx, val in enumerate(a):
#     a[idx] = squarify(val)

# a = list(map(lambda x: x**2, a))
a = list(filter(lambda x: x > 2 and x < 5, a))

print(a)



f = lambda x, y: x + y
assert f(1, 5) == 1 + 5

f = lambda: print("Hello!")
assert f() is None



# callback
cb = lambda: print("Operation is done!")


# tricky lambdas


length = 5
a = [lambda val=i: print(val) for i in range(length)]

# for i in range(length):
#     a.append(lambda: print(i))

# for f in a:
#     f()
