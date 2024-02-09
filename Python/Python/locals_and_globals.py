
cnt = 0
x = 5

def main():
    a = 5
    b = 3
    global x
    x = 10

def count():
    global cnt

    cnt = 10


count()
main()

print(cnt)
print(x)