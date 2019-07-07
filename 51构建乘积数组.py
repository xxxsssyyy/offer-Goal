# -*- coding:utf-8 -*-
"""
题目描述：给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的
        元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
解题思路：1.首先是都能想到的O(n^2)的解法
        2.时间复杂度O(n)的解法有动态规划的思想
"""
class Solution:
    def multiply(self, A):
        # 时间复杂度O(n^2)
        B = []
        for i in range(len(A)):
            value = 1
            for j in range(len(A)):
                if i!=j:
                    value *= A[j]
            B.append(value)
        return B

    def multiply2(self,A):
        #时间复杂度O(n)
        left = [1]
        right = [1]
        for i in range(len(A)-1):
            left.append(left[i]*A[i])
            right.append(right[i]*A[-i-1])
        return [left[i]*right[-i-1] for i in range(len(A))]
