# -*- coding:utf-8 -*-
"""
题目描述:统计一个数字在排序数组中出现的次数。
解题思路:看到排序直接想二分法，递归实现起来很好想，时间复杂度O(logn)
"""
class Solution:
    def GetNumberOfK(self, data, k):
        # write code here
        if not data:
            return 0
        return self.helper(data,k)
    # 递归函数
    def helper(self,data,k):
        if not data:
            return 0
        left, right = 0, len(data) - 1
        mid = (left + right) // 2
        if data[mid] > k:
            return self.helper(data[:mid], k)
        elif data[mid] < k:
            return self.helper(data[mid + 1:], k)
        else:
            return 1 + self.helper(data[:mid], k) + self.helper(data[mid + 1:], k)
    # 循环实现,分别找第一个k和最后一个k
    def GetNumberOfK_circle(self, data, k):
        # write code here
        if not data:
            return 0
        left = self.GetFirstK(data,k)
        right = self.GetLastK(data,k)
        if left== -1:
            count = 0
        else:
            count = right - left + 1
        return count
    def GetFirstK(self,data,k):
        left, right = 0, len(data) - 1
        while left<right:
            mid = (left + right) // 2
            if data[mid]<k:
                left = mid+1
            elif data[mid]>k:
                right = mid
            elif mid>=1 and data[mid-1]==k:
                right = mid
            else:
                return mid
        return -1
    def GetLastK(self,data,k):
        left, right = 0, len(data) - 1
        while left <= right:
            mid = (left + right) // 2
            if data[mid] < k:
                left = mid + 1
            elif data[mid] > k:
                right = mid
            elif mid <=len(data)-2 and data[mid + 1] == k:
                left = mid + 1
            else:
                return mid
        return -1
if __name__=='__main__':
    Solution = Solution()
    a = Solution.GetNumberOfK_circle([1,1,1,3,3,3],3)
    print(a)
