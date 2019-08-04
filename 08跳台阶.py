# -*- coding:utf-8 -*-
"""
题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
       （先后次序不同算不同的结果）。
解题思路：dp[i] = dp[i-1]+dp[i-2]
"""
class Solution:
    def jumpFloor(self, number):
        # write code here
        dp = [1, 1]
        if number >= 2:
            for i in range(2, number + 1):
                dp.append(dp[i - 1] + dp[i - 2])
        return dp[number]
