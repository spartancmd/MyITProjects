
from pathlib import Path

# wrapper
class Vector:
    __i_am_private_field = True

    def __init__(self):
        self.numbers = []
        self.__i_am_private_object_field = True

    def push_back(self, element):
        self.numbers.append(element)

    def pop_back(self):
        return self.numbers.pop()

    def get_size(self):
        return len(self.numbers)

    def get_element(self, idx):
        return self.numbers[idx]

    def print_elements(self):
        print(*self.numbers)

    def __i_am_private(self):
        ...

    def _i_am_private(self):
        self.__i_am_private()


def main():
    v = Vector()

    v.push_back(-1)
    v.push_back(-2)
    v.push_back(-3)
    v.print_elements()

    print(v.get_size())
    v.pop_back()
    print(v.get_size())

    print(v.get_element(1))

    v._i_am_private()

    # print(v.__i_am_private_object_field)
    # print(v.__i_am_private_field)
    # v.__i_am_private()

    print(dir(v))


if __name__ == "__main__":
    main()