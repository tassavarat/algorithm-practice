# [grouping_dishes](./grouping_dishes.py)
Given list of strings `dishes` where first element is name of a dish followed by its ingredients, group dishes by ingredients. Only include ingredients used by more than one dish.

## Example
```
dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
          ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
          ["Quesadilla", "Chicken", "Cheese", "Sauce"],
          ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]

grouping_dishes(dishes) = 
	 [["Cheese", "Quesadilla", "Sandwich"],
          ["Salad", "Salad", "Sandwich"],
          ["Sauce", "Pizza", "Quesadilla", "Salad"],
          ["Tomato", "Pizza", "Salad", "Sandwich"]]

dishes = [["Pasta", "Tomato Sauce", "Onions", "Garlic"],
            ["Chicken Curry", "Chicken", "Curry Sauce"],
            ["Fried Rice", "Rice", "Onions", "Nuts"],
            ["Salad", "Spinach", "Nuts"],
            ["Sandwich", "Cheese", "Bread"],
            ["Quesadilla", "Chicken", "Cheese"]]

grouping_dishes(dishes) =
	 [["Cheese", "Quesadilla", "Sandwich"],
          ["Chicken", "Chicken Curry", "Quesadilla"],
          ["Nuts", "Fried Rice", "Salad"],
          ["Onions", "Fried Rice", "Pasta"]]

```

# [are_following_patterns](./are_following_patterns.py)
Given lists `strings` and `patterns`, determine whether `strings` follows the sequence given in `patterns`.

## Example
* For `strings = ["cat", "dog", "dog"]` and `patterns = ["a", "b", "b"]`, the output should be `are_following_patterns(strings, patterns) = true`
* For `strings = ["cat", "dog", "doggy"]` and `patterns = ["a", "b", "b"]`, the output should be `are_following_patterns(strings, patterns) = false`

# [contains_close_nums](./contains_close_nums.py)
Given list of integers `num` and integer `k`, check if the distance of two duplicate values is less than or equal to k.

## Example
* For `nums = [0, 1, 2, 3, 5, 2]` and `k = 3`, the output should be `contains_close_nums(nums, k) = true`
* For `nums = [0, 1, 2, 3, 5, 2]` and `k = 2`, the output should be `contains_close_nums(nums, k) = false`
