# -*- coding:utf-8 -*-
"""
题目描述：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
"""
class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def Print(self, pRoot):
        if not pRoot:
            return []
        node_list = [pRoot]
        result = []
        while node_list:
            res = []
            next_list = []
            for node in node_list:
                res.append(node.val)
                if node.left:
                    next_list.append(node.left)
                if node.right:
                    next_list.append(node.right)
            node_list = next_list
            result.append(res)
        rr = []
        for i,v in enumerate(result):
            if i%2==0:
                rr.append(v)
            else:
                rr.append(v[::-1])
        return rr