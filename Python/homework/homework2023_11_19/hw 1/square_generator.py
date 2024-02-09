def square_generator(n):
    for i in range(1, n + 1):
        yield i * i


for i in square_generator(10):
    print(i)