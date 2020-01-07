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
