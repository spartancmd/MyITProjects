

class Cat:
    # def __new__(self, *args, **kwargs):
    #     ...

    animal_type = "Cat"

    # constructor
    # magic methods
    def __init__(self, age, color, name):
        self.age_ = age  # age_ is class field
        self.color_ = color
        self.name_ = name

    @staticmethod
    def say_meow():
        print("Meow!")

    @classmethod  # decorator
    def get_type(cls):
        return cls.animal_type

    # snake case
    @staticmethod
    def print_class_name():
        print("Cat")

def main():
    cat = Cat(2, "Grey", "Kitty")
    cat2 = Cat(2, "Grey", "Kitty")

    cat.name_ = "Kitty2"
    cat.animal_type = "Hello"
    print(Cat.animal_type) # Cat

    print(cat.name_)
    print(cat2.name_)

    # TypeError   -> camel case

    # cat.say_meow()

    # print(Cat.animal_type)

    # Cat.animal_type = "BadCat"

    # # print(cat.animal_type is cat2.animal_type)

    # # cat.animal_type = "BadCat"

    # # print(cat.animal_type is cat2.animal_type)


    # print(cat.animal_type)
    # print(cat2.animal_type)

    # print(Cat.getType())
    # Cat.printClassName()


if __name__ == "__main__":
    main()