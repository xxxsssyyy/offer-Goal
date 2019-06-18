class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        def length(node):
            count = 0
            while node:
                count+=1
                node = node.next
            return count
        def walkStep(node,n):
            while n>0:
                node = node.next
                n-=1
            return node
        h1,h2=pHead1,pHead2
        l1 = length(h1)
        l2 = length(h2)
        if l1>=l2:
            pHead1 = walkStep(pHead1,l1-l2)
        else:
            pHead2 = walkStep(pHead2,l2-l1)
        while pHead1:
            # 注意，这里直接判断两个表头是否相等（就包括后序链表都相等了）
            if pHead1 == pHead2:
                return pHead1
            pHead1 = pHead1.next
            pHead2 = pHead2.next
        return None