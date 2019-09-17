# -*- coding:utf-8 -*-
"""
题目描述：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
解题思路：
1-3-4-7-None
2-3-5-8-None

1-2-None
7-9-None
"""
class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
    # 循环实现
        # write code here
        p = ListNode(0)
        res = p
        while pHead1 or pHead2:
            if pHead1 == None:
                p.next = pHead2
                break
            if pHead2 == None:
                p.next = pHead1
                break
            if pHead1.val<=pHead2.val:
                p.next = pHead1
                p = p.next
                pHead1 = pHead1.next
            else:
                p.next = pHead2
                p = p.next
                pHead2 = pHead2.next
        return res.next

    def Merge2(self, pHead1, pHead2):
        # 递归做法
        if pHead1 == None:
            return pHead2
        if pHead2 == None:
            return pHead1
        if pHead1.val <= pHead2.val:
            res = pHead1
            res.next = self.Merge2(pHead1.next,pHead2)
        else:
            res = pHead2
            res.next = self.Merge2(pHead1,pHead2.next)
        return res

