# -*- coding:utf-8 -*-
"""
丑数
题目描述：把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
"""
"""
如果一个数为丑数，那么其*2，*3，*5也为丑数
创建3个指针维护，相当于创建3个list，分别储存当前丑数成倍后的丑数
指针是指向更新位置
"""
class Solution:
    def GetUglyNumber_Solution(self, index):
        if index<1:
            return 0
        t2 = t3 = t5 = 0
        res = [1]
        i = 1
        while i<=index:
            ugly_number = min(res[t2]*2, res[t3]*3, res[t5]*5)
            res.append(ugly_number)
            if res[t2]*2==ugly_number:
                t2 += 1
            if res[t3]*3==ugly_number:
                t3 += 1
            if res[t5]*5==ugly_number:
                t5+=1
            i+=1
        return res[index-1]