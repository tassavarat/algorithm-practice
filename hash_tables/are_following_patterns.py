def are_following_patterns(strings, patterns):
    """Determines whether strings follows sequence given in patterns

    Args:
        strings: List of strings
        patterns: list of strings

    Returns:
        True if strings follows given sequence, otherwise False
    """
    dict = {}

    for i in range(len(patterns)):
        if patterns[i] in dict and dict[patterns[i]] != strings[i]:
            return False
        dict[patterns[i]] = strings[i]
    return len(dict) == len(set(dict.values()))
