class Tree(object):
    """Creates binary tree node

    Attributes:
        value: value of node
        left: left Tree object
        right: right Tree object
    """
    def __init__(self, x):
        self.value = x
        self.left = None
        self.right = None
