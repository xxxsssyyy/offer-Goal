# -*- coding:utf-8 -*-
"""
题目描述：请实现一个函数，用来判断一颗二叉树是不是对称的。
         注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
思路：递归，对称的性质是节点的左子节点与其对称节点的右子节点值相同，右子节点与其对称节点的左子节点值相同
"""
class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetrical(self, pRoot):
        # write code here
        if pRoot is None:
            return True
        def compare(root1,root2):
            if not root1 and not root2:
                return True
            if not root1 or not root2:
                return False
            if root1.val == root2.val:
                return compare(root1.left,root2.right) and compare(root1.right,root2.left)
            return False
        return compare(pRoot.left,pRoot.right)
