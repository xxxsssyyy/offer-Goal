# 重点看，第二次做写不出
# -*- coding:utf-8 -*-
"""
题目描述：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
        注意，本题中树的子结构是指大树中包含小树即可，即s=[3,4,5,1,2,#,#],t=[4,1,2]的结果
        为True,意思是子结构不是指子树
解题思路：
        3         4
       / \       / \
      4  5      1  2
     / \
    1  2
    意思是子结构不是指子树，这与leetcode572所描述的意思不同
    有树的题：首先考虑递归求解，函数中考虑单个root的子过程即可
"""
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
        if not pRoot2:
            return False
        if not pRoot1:
            return False
        return self.HasSubtree(pRoot1.left,pRoot2) or self.HasSubtree(pRoot1.right,pRoot2) \
             or self.searchSubtree(pRoot1,pRoot2)
    def searchSubtree(self,pRoot1,pRoot2):
        if not pRoot2:
            return True
        if not pRoot1:
            return False
        if pRoot1.val == pRoot2.val:
            return self.searchSubtree(pRoot1.left,pRoot2.left) and self.searchSubtree(pRoot1.right,pRoot2.right)
        else:
            return False



