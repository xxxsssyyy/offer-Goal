# -*- coding:utf-8 -*-
"""
题目描述：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
解题思路：
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

    def Print1(self, pRoot):
        if not pRoot:
            return []
        node_list = [pRoot]
        result = []
        i = 0
        while node_list:
            res = []
            next_list = []
            for node in node_list:
                if i%2 == 0:
                    res.append(node.val)
                    if node.left:
                        next_list.append(node.left)
                    if node.right:
                        next_list.append(node.right)
                else:
                    res.append(node.val)
                    if node.right:
                        next_list.append(node.right)
                    if node.left:
                        next_list.append(node.left)
            next_list.reverse()
            i+=1
            result.append(res)
            node_list = next_list
        return result
if __name__ == '__main__':
    Solution = Solution()
    node = TreeNode(8)
    node.left = TreeNode(4)
    node.right = TreeNode(12)
    node.left.left = TreeNode(2)
    node.left.right = TreeNode(6)
    node.right.left = TreeNode(10)
    node.right.right = TreeNode(14)
    node.left.left.left = TreeNode(1)
    node.left.left.right = TreeNode(3)
    node.left.right.left = TreeNode(5)
    node.left.right.right = TreeNode(7)
    res = Solution.Print1(node)
    print(res)
