# -*- coding:utf-8 -*-
"""
题目描述：输入一棵二叉树，判断该二叉树是否是平衡二叉树（AVL树）。
        AVL树概念:它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右
        两个子树都是一棵平衡二叉树。
解题思路：1。第一想法是遍历树上每个结点，求其左右子树长度，判断。时间复杂度O(n^2)
        2。如何O(n)解决问题呢:在遍历求结点左右子树长度时,能不能一次同时判断是否
        是AVL树。这就设置一个记号变量，在遍历n个结点是，只要每个结点的左右子树长度
        相差大于1，记号变量赋值为0

AVL树参考：https://blog.csdn.net/qq_25940921/article/details/82183093
"""
class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def __init__(self):
        self.res = 1
    def IsBalanced_Solution(self, pRoot):
        # write code here
        self.helper(pRoot)
        return self.res

    def helper(self, root):
        # 计算当前结点的子树长度
        if not root:
            return 0
        left = 1+self.helper(root.left)
        right = 1+self.helper(root.right)
        if abs(left - right)>1:
            self.res = 0
        return max(left,right)

