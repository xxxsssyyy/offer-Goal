# -*- coding:utf-8 -*-
"""
题目描述：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
思路：BFS,辅助queue
"""

class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        res = []
        queue = [pRoot]
        temp = []
        line = []
        while queue:
            root = queue.pop(0)
            line.append(root.val)
            if root.left:
                temp.append(root.left)
            if root.right:
                temp.append(root.right)
            #当一行队列打印完后，更新队列
            if not queue:
                res.append(line)
                line = []
                queue = temp
                temp = []
        return res

class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        res = []
        queue = [pRoot]
        while queue:
            next_queue = []
            temp = []
            for root in queue:
                temp.append(root.val)
                if root.left:
                    next_queue.append(root.left)
                if root.right:
                    next_queue.append(root.right)
            res.append(temp)
            queue = next_queue
        return res

#讨论区的递归做法，不断扩容
class Solution:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        result = []
        def align(root, depth):
            if root:
                if len(result)<depth:
                    result.append([])
                result[depth-1].append(root.val)
                align(root.left, depth + 1)
                align(root.right, depth + 1)
        align(pRoot,1)
        return result