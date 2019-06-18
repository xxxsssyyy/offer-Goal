# coding:utf-8
# 复杂链表的复制
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead):
        # write code here
        if not pHead:
            return None
        a = pHead
        while a:
            m = a.next
            copynode = RandomListNode(a.label)
            copynode.next = m
            a.next = copynode
            a = m

        a = pHead
        while a:
            m = a.random
            copynode = a.next
            if m:
                copynode.random = m.next
            a = copynode.next

        a = pHead
        copyHead = a.next
        while a:
            copynode = a.next
            b = copynode.next
            a.next = b
            if b:
                copynode.next = b.next
            else:
                copynode.next = None
            a = b
        return copyHead
if __name__ == '__main__':
    Solution = Solution()
