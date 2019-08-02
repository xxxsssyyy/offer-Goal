# -*- coding:utf-8 -*-
# 这道题重点看
"""
题目描述：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
栈：先入后出；队列：先入先出
"""
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, node):
        # write code here
        self.stack1.append(node)
    def pop(self):
        # return xx
        if self.stack2:
            return self.stack2.pop()
        elif not self.stack1:
            return None
        else:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
            return self.stack2.pop()