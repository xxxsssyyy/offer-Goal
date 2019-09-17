# -*- coding:utf-8 -*-
"""
题目描述：输入一个链表，反转链表后，输出新链表的表头。
解题思路：
0 -> 1 -> 2 -> 3 -> 4 -> NULL 的反转形式为 4 -> 3 -> 2 -> 1 -> 0 -> NULL
     反转后链表的表尾都是空值，利用三指针法迭代求解
"""
class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        if not pHead:
            return None
        p1 = pHead
        p2 = None
        while p1:
            temp = p1.next
            p1.next = p2
            p2 = p1
            p1 = temp
        return p2

