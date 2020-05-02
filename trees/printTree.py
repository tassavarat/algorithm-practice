def printTree(tree):
    if not tree:
        return
    print(tree.value)
    printTree(tree.left)
    printTree(tree.right)
