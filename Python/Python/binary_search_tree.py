

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

    # def remove(self, x):
    #     if not self.exists(x):
    #         return
    #     if self.root.val == x:
    #         # remove root
    #         return

    #     self.__remove(self.root, x)

    # def __pop_min_from_right_subtree(self, root):
    #     if root is None:
    #         raise RuntimeError

    #     rt_val = None
    #     right_child = root.right
    #     if right_child.left is None:
    #         rt_val = right_child.val
    #         root.right = None
    #         return

    #     while

    # def __remove(self, root, x):
    #     if root.left.val == x:
    #         child = root.left

    #         if child.left is None and child.right is None:
    #             root.left = None
    #         elif child.left is None and child.right is not None:
    #             root.left = child.right
    #         elif child.left is not None and child.right is None:
    #             root.left = child.left
    #         else: # both children are alive
    #             mn_el = self.__get_min(child.right)

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

