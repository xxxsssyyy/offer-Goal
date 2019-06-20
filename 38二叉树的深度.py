# -*- coding:utf-8 -*-
"""
题目描述:输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
        形成树的一条路径，最长路径的长度为树的深度。
思路:递归
"""

class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def TreeDepth(self, pRoot):
        # write code here
        if pRoot is None:
            return 0
        return max(self.TreeDepth(pRoot.left),self.TreeDepth(pRoot.right))+1

if __name__=="__main__":
    Solution = Solution()
    root = TreeNode(1)
    m = root
    for i in range(4):
        m.left = TreeNode(i)
        m = m.left
    for i in range(3):
        m.right = TreeNode(i)
        m = m.right
    depth = Solution.TreeDepth(root)
    print(depth)