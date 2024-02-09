

# 1
a = 0
b = 1

a, b = b, a

print(a, b)

# 2
a = [1, 2, 3]
x, y, z = a

a = (1, 2, 3)
x, y, z = a

a = {1, 2, 3}
x, y, z = a

print(x, y, z)

# 3
def do_complicated_work(x):
    # some complicated work here

    return x + 1, 0

res, err = do_complicated_work(5)
print("Result is", res, ", error is", err)
if err != 0:
    print("Error happened!!")

res, err = do_complicated_work(6)
print("Result is", res, ", error is", err)
if err != 0:
    print("Error happened!!")
