

# 1
def factorial(x):
    if x == 0:
        return 1

    return x * factorial(x - 1)

print(factorial(5))

# 2
def fib(N):
    if N == 0:
        return 0
    if N == 1:
        return 1

    return fib(N - 1) + fib(N - 2)

print(fib(1000))