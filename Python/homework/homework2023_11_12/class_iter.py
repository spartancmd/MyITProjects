import random

class RandomIter:
    def __init__(self, min_num, max_num, cnt=10):
        self.min_num = min_num
        self.max_num = max_num
        self.cnt = cnt

#    def __iter__(self): return self    Скажи пожалуйста, это вообще нужно?

    def __next__(self):
        if self.cnt < 0:
            raise StopIteration
        
        self.cnt -= 1
        return random.randint(self.min_num, self.max_num)
        
r_it = RandomIter(1, 100)

for i in range(5):
    res = next(r_it)
    print(res)