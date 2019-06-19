# -*- coding:utf-8 -*-
# 重点看，第一遍没思路
"""
题目描述：在一个排序的链表中，存在重复的结点，
请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
思路：1.递归实现，子过程是考虑一个节点
     2.循环实现:双指针，last指针寻找最后一个连续值相同的节点
"""
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if pHead is None or pHead.next is None:
            return pHead
        if pHead.val == pHead.next.val:
            node = pHead.next
            while node is not None and node.val == pHead.val:
                node = node.next
            return self.deleteDuplication(node)
        else:
            pHead.next = self.deleteDuplication(pHead.next)
            return pHead

    def DeleteDuplication(self, pHead):
        if pHead is None or pHead.next is None:
            return pHead
        pre_head = ListNode(-1)
        pre_head.next = pHead
        pre = pre_head
        node = pHead
        last = None
        while node.next:
            last = node.next
            if node.val == last.val:
                while node.val == last.val and last:
                #这步条件有last!=None
                    last = last.next
                pre.next = last
                node = last
            else:
                node = node.next
                pre = pre.next
        return pre_head.next
if __name__=='__main__':
    Solution = Solution()
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(4)
    head.next.next.next.next.next = ListNode(4)
    head.next.next.next.next.next.next = ListNode(5)
    res = Solution.deleteDuplication(head)
    print(res.val,res.next.val,res.next.next.val)
    res1 = Solution.DeleteDuplication(head)
    print(res1.val, res1.next.val, res1.next.next.val)