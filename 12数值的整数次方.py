# -*- coding:utf-8 -*-
"""
题目描述：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
        保证base和exponent不同时为0
解题思路：快速求幂算法是基于二分算法，所以时间复杂度位O(logn)，其核心思想是通过二进制思想和位运算，
         将幂指数每次向右移动一位，将每次移位后判断最后一位是否为1，若为1则乘上其基本项
"""
class Solution:
    def Power(self, base, exponent):
        if base == 0:
            return 0
        if exponent == 0:
            return 1
        count = 1
        tmp = base
        a = abs(exponent)
        while a:
            if a&1 == 1:
                count *= tmp
            tmp = tmp**2
            a = a>>1
        return count if exponent>0 else 1.0/count



