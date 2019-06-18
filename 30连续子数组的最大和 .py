# -*- coding:utf-8 -*-
"""
连续子数组的最大和
题目描述：HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,
他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,
问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
"""
# 思路1：双循环两次遍历，时间复杂度O(n^2)
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        max_num = array[0]
        for i in range(len(array)):
            temp = 0
            for j in range(i,len(array)):
                temp += array[j]
                if temp>max_num:
                    max_num = temp
        return max_num

# 思路2：动态规划，时间复杂度为O(n)
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        dp = [i for i in array]
        for i in range(1,len(array)):
            dp[i] = max(dp[i-1]+array[i],array[i])
        return max(dp)
if __name__ == '__main__':
    Solution = Solution()
