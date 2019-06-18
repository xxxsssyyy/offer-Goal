# -*- coding:utf-8 -*-
"""
题目描述：给定一棵二叉搜索树，请找出其中的第k小的结点。例如：
     5
   /  \
  3    7
 / \  / \
2  4 6  8
中，按结点数值大小顺序第三小结点的值为4。

题目思路：二叉树中序遍历
"""
class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def __init__(self):
        self.midlist = []
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        self.aaa(pRoot)
        if k>len(self.midlist):
            return None
        return self.midlist[k-1]
    def aaa(self,root):
        if root is None:
            return
        self.aaa(root.left)
        self.midlist.append(root)
        self.aaa(root.right)