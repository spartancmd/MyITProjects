def calc_gen():
    x, y = yield None

    while True:
        x, y = yield x + y
        x, y = yield x - y
        x, y = yield x * y
        x, y = yield x / y

    
gen = calc_gen()

print(next(gen))

assert gen.send((1, 2)) == 3
assert gen.send((1, 2)) == -1
assert gen.send((3, 2)) == 6
assert gen.send((4, 2)) == 2
assert gen.send((5, 7)) == 12

