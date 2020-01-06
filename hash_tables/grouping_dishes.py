def groupingDishes(dishes):
    """Groups dishes by ingredients if there 2 or more dishes per ingredient

    Args:
        dishes: 2D list of ingredients, first element of inner array are dishes

    Returns:
        Grouped dishes
    """
    dict = {}
    list = []

    for rows in dishes:
        for e in rows[1:]:
            dict.setdefault(e, []).append(rows[0])

    for k in sorted(dict):
        if len(dict[k]) > 1:
            list.append([k] + sorted(dict[k]))
    return list
