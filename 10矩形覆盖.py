# -*- coding:utf-8 -*-
"""
题目描述：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
         请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
解题思路： 动态规划：dp[i] = dp[i-2] + dp[i-1]
"""
class Solution:
    def rectCover(self, number):
        # write code here
        if not number:
            return 0
        dp = [1,1]
        if number >= 2:
            for i in range(2,number+1):
                dp.append(dp[i-2]+dp[i-1])
        return dp[number]