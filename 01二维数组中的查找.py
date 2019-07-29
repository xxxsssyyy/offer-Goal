# -*- coding:utf-8 -*-
# 整理时一次过
"""
题目描述:
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下
递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
解题思路:
对于一个二维数组，其位于左下角的值一定比其第一列其他值都大，比最后一行值都小，
因此每次搜索后，将搜索数组减少一行或者一列，算法时间复杂度为O(m+n)
"""
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        if not array:
            return False
        row,col = len(array)-1,len(array[0])-1
        i,j = row,0
        while i>=0 and j<=col:
            if array[i][j]<target:
                j+=1
            elif array[i][j]>target:
                i-=1
            else:
                return True
        return False