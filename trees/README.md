# [has_path_with_given_sum](./has_path_with_given_sum.c)
Given a binary tree `t` and integer `s`, determine whether there is a root to leaf path such that the sum equals `s`.

## Example
```
t = {
    "value": 4,
    "left": {
        "value": 1,
        "left": {
            "value": -2,
            "left": null,
            "right": {
                "value": 3,
                "left": null,
                "right": null
            }
        },
        "right": null
    },
    "right": {
        "value": 3,
        "left": {
            "value": 1,
            "left": null,
            "right": null
        },
        "right": {
            "value": 2,
            "left": {
                "value": -2,
                "left": null,
                "right": null
            },
            "right": {
                "value": -3,
                "left": null,
                "right": null
            }
        }
    }
}
s = 7

has_path_with_given_sum(t, s) = true

t = {
    "value": 4,
    "left": {
        "value": 1,
        "left": {
            "value": -2,
            "left": null,
            "right": {
                "value": 3,
                "left": null,
                "right": null
            }
        },
        "right": null
    },
    "right": {
        "value": 3,
        "left": {
            "value": 1,
            "left": null,
            "right": null
        },
        "right": {
            "value": 2,
            "left": {
                "value": -4,
                "left": null,
                "right": null
            },
            "right": {
                "value": -3,
                "left": null,
                "right": null
            }
        }
    }
}
s = 7

has_path_with_given_sum(t, s) = false
```

# [is_tree_symmetric](./is_tree_symmetric.c)
Given a binary tree `t`, check if `t` is symmetric.

## Example
```
t = {
    "value": 1,
    "left": {
        "value": 2,
        "left": {
            "value": 3,
            "left": null,
            "right": null
        },
        "right": {
            "value": 4,
            "left": null,
            "right": null
        }
    },
    "right": {
        "value": 2,
        "left": {
            "value": 4,
            "left": null,
            "right": null
        },
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    }
}

is_tree_symmetric(t) = true

t = {
    "value": 1,
    "left": {
        "value": 2,
        "left": null,
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    },
    "right": {
        "value": 2,
        "left": null,
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    }
}

is_tree_symmetric(t) = false
```

# [find_profession](./find_profession.c)
For a special family represented as a binary tree where:
* Every node has two children
* The left child node of an engineer is an engineer and the right is a doctor
* The left child node of a doctor is a doctor and the right is an engineer
* Root node is an engineer
Find the profession of the node given the level and position

## Example
* `level = 3` and `pos = 3` `find_profession(level, pos) = "Doctor"`
* `level = 4` and `pos = 2` `find_profession(level, pos) = "Doctor"`
* `level = 1` and `pos = 1` `find_profession(level, pos) = "Engineer"`

# [kth_smallest_in_bst](./kth_smallest_in_bst.c)
Given BST `t`, find `k` smallest element in it.

## Example
```
t = {
    "value": 3,
    "left": {
        "value": 1,
        "left": null,
        "right": null
    },
    "right": {
        "value": 5,
        "left": {
            "value": 4,
            "left": null,
            "right": null
        },
        "right": {
            "value": 6,
            "left": null,
            "right": null
        }
    }
}
kth_smallest_in_bst(t, k) = 5

t = {
    "value": 1,
    "left": {
        "value": -1,
        "left": {
            "value": -2,
            "left": null,
            "right": null
        },
        "right": {
            "value": 0,
            "left": null,
            "right": null
        }
    },
    "right": null
}
kth_smallest_in_bst(t, k) = -2
```

# [is_subtree](./is_subtree.c)
Given two binary trees `t1` and `t2`, determine whether `t2` is a subtree of `t1`

## Example
```
      t1:             t2:
       5              10
      / \            /  \
    10   7          4    6
   /  \            / \    \
  4    6          1   2   -1
 / \    \
1   2   -1
is_sub_tree(t1, t2) = true

        t1:            t2:
         5             10
       /   \          /  \
     10     7        4    6
   /    \           / \    \
  4     6          1   2   -1
 / \   /
1   2 -1
is_sub_tree(t1, t2) = false
```

# [restore_binary_tree](./restore_binary_tree.py)
Given array of values for preorder and inorder traversal of a tree, create the binary tree

## Example
```
preorder = [1, 2, 4, 3, 5, 6]
inorder  = [4, 2, 1, 5, 3, 6]
restoreBinaryTree(inorder, preorder) =
    1
   / \
  2   3
 /   / \
4   5   6
```

# [valid_bst](./valid_bst.c)
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.

## Example
```
    2
   / \
  1   3

Input: [2,1,3]
Output: true

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

# [invert_tree](./invert_tree.c)
Invert a binary tree.

## Example
```
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
```
