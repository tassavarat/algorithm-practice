from tree import Tree
from printTree import printTree


class Static:
    """Contains static variable used to index preorder array"""
    preIdx = 0


def createTree(preord, inord, inSt, inEnd, inHt):
    """Recursively creates binary tree nodes

    Args:
        preord: array of preorder traversal values of a tree
        inord: array of inorder traversal values of a tree
        inSt: inorder traversal left boundry
        inEnd: inorder traversal right boundry
        inHt: hash table of inord array with index for each value

    Returns:
        newly created tree node
    """
    if inSt > inEnd:
        return None
    cur = preord[Static.preIdx]
    Static.preIdx += 1
    new = Tree(cur)
    if inSt == inEnd:
        return new
    inIdx = inHt[cur]
    new.left = createTree(preord, inord, inSt, inIdx - 1, inHt)
    new.right = createTree(preord, inord, inIdx + 1, inEnd, inHt)
    return new


def restoreBinaryTree(inorder, preorder):
    """Creates hash table of inorder array with index for each value

    Calls createTree recursive method

    Returns:
        root node of tree created by createTree
    """
    inordHt = {}
    for i in range(len(inorder)):
        inordHt[inorder[i]] = i
    return createTree(preorder, inorder, 0, len(preorder) - 1, inordHt)


if __name__ == "__main__":
    preorder = [1, 2, 4, 3, 5, 6]
    inorder = [4, 2, 1, 5, 3, 6]
    tree = restoreBinaryTree(inorder, preorder)
    printTree(tree)
