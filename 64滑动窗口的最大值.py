# -*- coding:utf-8 -*-
"""
暴力法：时间复杂度O(m*n)
辅助队列方法：时间复杂度O(m)
"""
class Solution:
    def baoli_maxInWindows(self, num, size):
        # write code here
        if size > len(num) or size<=0:
            return []
        res = []
        i = 0
        while i+size-1 < len(num):
            res.append(max(num[i:i+size]))
            i += 1
        return res


    """
    用一个双端队列，队列第一个位置保存当前窗口的最大值，当窗口滑动一次
    1.判断当前最大值是否过期
    2.新增加的值从队尾开始比较，把所有比他小的值丢掉
    """
    def maxInWindows(self, num, size):
        if size > len(num) or size<=0:
            return []
        res = []
        queue = []
        i = 0
        while i<len(num):
            if len(queue) > 0 and i-size+1 > queue[0]:
                queue.pop(0)
            while len(queue) > 0 and num[queue[-1]] < num[i]:
                queue.pop()
            queue.append(i)
            if i>=size-1:
                res.append(num[queue[0]])
            i+=1
        return res