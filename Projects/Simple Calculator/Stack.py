class Stack:
    def __init__(self):
        self.stack = []

    def append(self, val):
        self.stack.append(val)
    
    def pop(self):
        return self.pop()

    def top(self):
        if len(self.stack) == 0:
            return None
        return self.stack[len(self.stack) - 1]