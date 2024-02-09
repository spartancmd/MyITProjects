from math import sqrt

class Point2D:
    dim = 2

    def __init__(self, x, y):
        print("Inside __init__ of Point2D")
        self.x = x
        self.y = y

    def __str__(self):
        print("__str__ is called!")
        return f"[Point2D] x: {self.x}, y: {self.y}"

    def squares_sum(self):
        return self.x**2 + self.y**2


class B(Point2D):
    dim = 3

    def __init__(self, x, y):
        print("Inside __init__ of B")
        super().__init__(x, y)
        self.z = x + y

    def get_magic_number(self):
        return self.z

    def __eq__(self, rhs):
        print("__eq__ is called!")
        return True

    def __ge__(self, rhs):
        print("__ge__ is called!")
        return True

    def __hash__(self):
        return 5

a = B(4, 4)
b = B(4, 5)
print(dir(a))
print(a == b)
print(a >= b)
print(str(a))
print(hash(a))

# print(b.get_magic_number())
# print(b.squares_sum())

# print(str(123))
print(dir(123))

# str(x) is same that x.__str__()

# print(B(4, 4).squares_sum())


# class Point3D:
#     dim = 3

#     def __init__(self, x, y, z):
#         self.x = x
#         self.y = y
#         self.z = z

#     def __str__(self):
#         return f"[Point3D] x: {self.x}, y: {self.y}, z: {self.z}"

#     def squares_sum(self):
#         return self.x**2 + self.y**2 + self.z**2


# a = Point2D(-1, -1)
# b = Point3D(-1, -2, -3)

# print(a)
# print(b)