# -*- coding:utf-8 -*-
"""
题目描述：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
         注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
解题思路：
        1.当前节点有右孩子，则为右孩子
        2.当前节点无右孩子，为父亲节点的左孩子：则为父亲节点
        3.当前节点无右孩子，为父亲节点的右孩子：则向上不断迭代右节点，直至该节点节点为父亲的
          左孩子节点
        时间复杂度：O(1) <----> O(logn)、O(n)

        第二种思路：中序遍历后取下一个节点，时间复杂度O(n)
"""
class TreeLinkNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None #指向父亲节点
class Solution:
    def GetNext(self, pNode):
        # write code here
        if not pNode:
            return None
        if pNode.right: # 有右节点
            pNode = pNode.right
            while pNode.left:
                pNode = pNode.left
            return pNode
        while pNode.next:
            if pNode.next.left == pNode: # 如果是父亲节点的左节点
                return pNode.next
            pNode = pNode.next # 父亲节点的右节点
        return None