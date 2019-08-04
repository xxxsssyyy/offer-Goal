# -*- coding:utf-8 -*-
"""
题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶
        总共有多少种跳法。
解题思路：dp[i] = dp[i-1]+dp[i-2]+...+dp[2]+dp[1]
         dp[i-1] = dp[i-2]+...+dp[2]+dp[1]
         所以dp[i] = 2dp[i-1]
"""
class Solution:
    def jumpFloorII(self, number):
        # write code here
        dp = [0,1]
        if number>=2:
            for i in range(2,number+1):
                dp.append(dp[i-1]*2)
        return dp[number]