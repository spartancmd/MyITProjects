from random import randint


def f(begin):
    print("Start of iterator")
    begin += 1
    print("Before yield")
    yield begin
    print("After yield")

def random_gen(begin, end, cnt=10):
    for i in range(cnt):
        yield randint(begin, end)

    print("End of generator lifetime!")

for x in random_gen(1, 10, 3):
    print(x)

gen = f(0)

for x in gen:
    print(x)

# print(next(gen))
# print(next(gen))
# print(next(gen))
# print(next(gen))

# for i in range(10):
#     print(next(x))