# -*- coding:utf-8 -*-
"""
题目描述：给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
解题思路：用一个list存储遍历过的结点，如果之后遍历发现当前结点在list中，则当前结点就是
        环的入口，否则遍历结束没找到环返回None
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        m = []
        while pHead:
            if pHead not in m:
                m.append(pHead)
                pHead = pHead.next
            else:
                return pHead
        return None

if __name__=='__main__':
    Solution = Solution()
    node = ListNode(0)
    node.next = ListNode(1)
    node.next.next = ListNode(2)
    b = node.next.next
    node.next.next.next = ListNode(3)
    node.next.next.next.next = ListNode(4)
    node.next.next.next.next.next = b
    k = Solution.EntryNodeOfLoop(b)
    print(k.val)

