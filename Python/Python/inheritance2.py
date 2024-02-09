from math import sqrt

class Number:
    def __init__(self, x):
        self.x = x

    def __add__(self, rhs):
        if type(rhs) == Number:
            return Number(self.x + rhs.x)
        elif type(rhs) in (int, float):
            return Number(self.x + rhs)

    def __sub__(self, rhs):
        return Number(self.x - rhs.x)

    def __str__(self):
        return str(self.x)

a = Number(5)
b = Number(6)

print(a + b + Number(7))
print(a + 5)
print(a + 3.14)
print(a - b)
