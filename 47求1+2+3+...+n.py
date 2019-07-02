# -*- coding:utf-8 -*-
"""
题目描述：求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字
        及条件判断语句（A?B:C）。
解题思路：利用短路特性：
        Python中短路特性:
        即 a and xxx
        如果a为False:则直接返回False
        如果a为True:则返回xxx
"""
class Solution:
    def Sum_Solution(self, n):
        # write code here
        return n and n + self.Sum_Solution(n - 1)