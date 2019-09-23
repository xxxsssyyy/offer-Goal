# -*- coding:utf-8 -*-
"""
题目描述：操作给定的二叉树，将其变换为源二叉树的镜像。
解题思路：
             8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11

    	     8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

"""
class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
    # 我第二次的解法是考虑使用队列 循环实现
        if not root:
            return root
        m = root
        queue = [root]
        while queue:
            root = queue.pop(0)
            root.left,root.right = root.right,root.left
            if root.left:
                queue.append(root.left)
            if root.right:
                queue.append(root.right)
        return m

#简短的递归代码实现：
class Solution1:
    # 返回镜像树的根节点
    def Mirror(self, root):
        if not root:
            return root
        node=root.left
        root.left=root.right
        root.right=node
        self.Mirror(root.left)
        self.Mirror(root.right)
        return root
