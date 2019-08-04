# -*- coding:utf-8 -*-
"""
题目描述：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）
"""
class Solution:
    def Fibonacci(self, n):
        # write code here
        dp = [0,1]
        if n>=2:
            for i in range(2,n+1):
                dp.append(dp[i-1]+dp[i-2])
        return dp[n]
