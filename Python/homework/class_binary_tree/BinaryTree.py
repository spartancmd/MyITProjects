class ElementNotFound(Exception):
    pass

class Node:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

    def insert(self, new_val):
        if new_val < self.val:
            if self.left == None:
                self.left = Node(new_val)
            else:
                self.left.insert(new_val)
        elif new_val >= self.val:
            if self.right == None:
                self.right = Node(new_val)
            else:
                self.right.insert(new_val)
    
    def exists(self, searched_val):
        if searched_val == self.val:
            return True
        elif searched_val < self.val:
            if self.left == None: 
                return False
            else: 
                return self.left.exists(searched_val)
        elif searched_val > self.val:
            if self.right == None: 
                return False
            else:
                return self.right.exists(searched_val)
    
    def popMaxNode(self):
        if self.right == None: 
            bfr = self
            try:        # I'm not sure about this
                del self
            except: pass

            return bfr

        return self.right.popMaxNode()


    def remove(self, target_val):
        if target_val < self.val:
            if self.left == None: 
                raise ElementNotFound
            else:
                self.left.remove(target_val)
        elif target_val > self.val:
            if self.right == None:
                raise ElementNotFound
            else:
                self.right.remove(target_val)
        else:   # else if the elements value equals the target value
            if self.left == None or self.right == None:
                self = self.right if self.left == None else self.left
            else:
                maxNode = self.left.popMaxNode()
                self.val = maxNode.val


        

node = Node(6)

node.insert(4)
node.insert(8)
node.insert(7)

print(node.exists(6))
print(node.exists(4))
print(node.exists(8))
print(node.exists(7))
print(node.exists(9))

node.remove(4)
print("removed 4")
print(node.exists(4))       # Тут ошибка, выводит true вместо false, так как лист должен быть удалён

                




