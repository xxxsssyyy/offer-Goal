# -*- coding:utf-8 -*-
"""
题目描述：请实现两个函数，分别用来序列化和反序列化二叉树
解题思路：
     序列化二叉树：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串。需要注意
     的是，序列化二叉树的过程中，如果遇到空节点，需要以某种符号（这里用#）表示。
     序列化可以基于先序/中序/后序/按层等遍历方式进行，这里采用先序遍历的方式实现，
     字符串之间用","隔开。

     主要用递归思想，每次递归返回的是结点，递归中处理好结点终止的条件，并且递归
     处理该节点的左右子结点
     类中变量self.count记录每次调用递归时的结点在序列化中的位置
"""
class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right =None

class Solution:
    def __init__(self):
        self.count = -1
    def Serialize(self, root):
        # 序列化
        if not root:
            return '#'
        return str(root.val)+','+self.Serialize(root.left)+','+self.Serialize(root.right)

    def Deserialize(self, s):
        # 反序列化
        self.count += 1
        tree_list = s.split(',')
        if tree_list[self.count] == '#':
            return None
        node = TreeNode(int(tree_list[self.count]))
        node.left = self.Deserialize(s)
        node.right = self.Deserialize(s)
        return node
