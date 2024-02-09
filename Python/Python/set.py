from time import time
from random import randint

a = [randint(1, 10)] * 1000000  # 1 million elements

begin = time()
for i in range(1000):
    res = 11 in a
end = time()

print("Result time is " + str(end - begin))   # 4.2

s = set()
for i in range(10**8):
    s.add(i)

begin = time()
for i in range(1000):
    res = -1 in s
end = time()

print("Result time is {:f}".format(end - begin))  # 0.00005
