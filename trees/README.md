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
