# -*- coding:utf-8 -*-
"""
题目描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
         所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
解题思路：将奇数、偶数分别放入两个list再合并输出
"""
class Solution:
    def reOrderArray(self, array):
        # write code here
        a,b = [],[]
        for i in array:
            a.append(i) if i%2 == 1 else b.append(i)
        return a+b