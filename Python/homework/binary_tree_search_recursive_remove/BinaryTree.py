
class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, x):
        if self.root is None:
            self.root = Node(x, None, None)

        self.__insert(self.root, x)

    def __insert(self, root, x):
        if x < root.val:
            if root.left is None:
                root.left = Node(x, None, None)
            else:
                self.__insert(root.left, x)
        if root.val < x:
            if root.right is None:
                root.right = Node(x, None, None)
            else:
                self.__insert(root.right, x)

    def exists(self, x):
        if self.root is None:
            return False
        if self.root.val == x:
            return True

        return self.__exists(self.root.left, x) or self.__exists(self.root.right, x)

    def __exists(self, root, x):
        if root is None:
            return False
        if root.val == x:
            return True

        return self.__exists(root.left, x) or self.__exists(root.right, x)

    def pop_min_node(self, root, prev):
        if root.left is not None:
            return self.pop_min_node(root.left, root)
        
        bfr = root.val
        prev.left = root.right

        return bfr

    def remove(self, x):
        if self.root == None:
            raise Exception

        if x < self.root.val:
            self.__remove(self.root.left, x, self.root)
        elif x > self.root.val:
            self.__remove(self.root.right, x, self.root)
        else:
            if self.root.left is not None and self.root.right is not None:
                self.root.val = self.pop_min_node(self.root.right, self.root)
            elif self.root.left is None and self.root.right is None:
                self.root = None
            else:
                if self.root.left is not None:
                    self.root = self.root.left
                else:
                    self.root = self.root.right

                
    def __remove(self, root, x, prev_root):
        if root == None:
            raise Exception # x doesn't exist
        
        if x < root.val:
            self.__remove(root.left, x, self.root)
        elif x > root.val:
            self.__remove(root.right, x, self.root)
        else:
            if root.left is None and root.right is None:
                if x < prev_root.val:
                    prev_root.left = None
                else:
                    prev_root.right = None
            elif root.left is not None and root.right is not None:
                root.val = self.pop_min_node(root.right, root)
            else: # when at least one
                if root.left is not None:
                    bfr_root = root.left
                else:
                    bfr_root = root.right
                
                if x < prev_root.val:
                    prev_root.left = bfr_root
                else:
                    prev_root.right = bfr_root

                

    def dfs_printer(self):
        self.__dfs_printer(self.root)

    def __iter__(self):
        return self.__dfs_generator(self.root)

    def __dfs_generator(self, root):
        if root is None:
            return

        yield from self.__dfs_generator(root.left)
        yield root.val
        yield from self.__dfs_generator(root.right)

bst = BinarySearchTree()
bst.insert(2)
bst.insert(1)
bst.insert(3)

assert bst.exists(2)
assert bst.exists(1)
assert bst.exists(3)
assert not bst.exists(4)

bst.insert(4)
assert bst.exists(4)

bst.insert(-1)
bst.insert(10)
bst.insert(100)

for x in bst:
    print(x)
print()
# output:
# -1
# 1
# 2
# 3
# 4
# 10




bst.remove(-1) # Почему тут не так удаляется? 



for x in bst:
    print(x)
# output:
# 2
# 3
# 4
# 10
# 100