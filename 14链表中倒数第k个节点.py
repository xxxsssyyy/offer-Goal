# -*- coding:utf-8 -*-
"""
题目描述：输入一个链表，输出该链表中倒数第k个结点。
解题思路：时间复杂度O(n),双指针法，第一个指针先走k-1步，到达第k个节点，再将两个指针同时移动，当
         第二个指针到达链表尾部时，第一个指针刚好到达倒数第k个节点
         相当于造了一把长度为k的尺子，尺子从前向后移动，当尺子尾部与链表尾部对齐的时候，尺子前部
         刚好与倒数第k个节点对齐
"""
class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if k<=0 or not head:
            return None
        p1,p2 = head,head
        while k>1:
            if p1.next is not None:
                p1 = p1.next
                k-=1
            else:
                return None
        while p1.next != None:
            p1 = p1.next
            p2 = p2.next
        return p2