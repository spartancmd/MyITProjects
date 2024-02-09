


class File:
    def __init__(self, name):
        print("__init__ is called")
        self.f = open(name)

    def read(self, n):
        return self.f.read(n)

    def close(self):
        self.f.close()

    def __enter__(self):
        print("Method enter is called")
        return self

    def __exit__(self, exc_type, exc_value, exc_tb):
        print("Exit is called")

        print(exc_type, exc_value, exc_tb)
        self.close()

with File("testTxt.txt") as f:
    print("f is", f)
    print("Inside ctx mngr")
    f.read(1)

    try:
        raise RuntimeError("Hello", 2)
    except:
        print("RuntimeError happened!")
        raise

# f =

# f.close()

# with open("testTxt.txt") as f:
#     raise RuntimeError

# f is already closed!

