# -*- coding:utf-8 -*-
"""
题目描述:输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
        如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:对应每个测试案例，输出两个数，小的先输出。
"""
# 34ms 5732K
class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # write code here
        for num in array:
            if tsum-num in array:
                return [num,tsum-num]
        return []
# 28ms 5732K
    # 双指针法
    def FindNumbersWithSum2(self, array, tsum):
        # write code here
        i, j = 0,len(array) - 1
        while i < j:
            if array[i] + array[j] > tsum:
                j-=1
            elif array[i] + array[j] < tsum:
                i+=1
            else:
                return [array[i],array[j]]
        return []