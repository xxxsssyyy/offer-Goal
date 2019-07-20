# -*- coding:utf-8 -*-
# 归并排序需要重点掌握
"""
数组中的逆序
题目描述：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
即输出P%1000000007
实例：
输入[1,2,3,4,5,6,7,0]
输出7
"""
"""
第一想法思路：二次遍历，时间复杂度0(N^2)
网上的思路1：归并排序，时间复杂度O(logn)
网上的思路2:复制一份数组进行快排，对快排后的数组从头开始每次拿出一个元素看其在原始数组中出现的位置，
          并进行出栈
"""
class Solution:
    def InversePairs(self, data):
        # write code here
        sorted_data = sorted(data)
        count = 0
        for i in sorted_data:
            count += data.index(i)
            data.pop(data.index(i))
        return count
    def InversePairs2(self, data):
        # 归并排序法
        if not data:
            return 0
        temp = data.copy()
        return self.helper(data,temp,0,len(data)-1)
    def helper(self,data,temp,start,end):
        if start==end:
            temp[start] = data[start]
            return 0
        mid = (start + end)//2
        left = self.helper(data,temp,start,mid)
        right = self.helper(data,temp,mid+1,end)
        i,j = start,mid+1
        index,count = start,0
        while i<=mid and j<=end:
            if data[i] <= data[j]:
                temp[index] = data[i]
                i+=1
            else:
                temp[index] = data[j]
                j+=1
                count+=1
            index += 1
        while i<= mid:
            temp[index] = data[i]
            i+=1
            index+=1
        while j<= end:
            temp[index] = data[j]
            j+=1
            index+=1
        return left+count+right

if __name__=='__main__':
    Solution = Solution()
    a = Solution.InversePairs2([2,1,1,3,3,3])
    print(a)
