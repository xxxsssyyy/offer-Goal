# -*- coding:utf-8 -*-
"""
题目描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
        输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
        例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
        NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
解题思路:二分查找，时间复杂度O(logN)
"""
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if not rotateArray:
            return 0
        left,right = 0,len(rotateArray)-1
        while left<right:
            mid = (left + right)//2
            if rotateArray[mid]>rotateArray[left]:
                left = mid
            elif rotateArray[mid]<rotateArray[left]:
                right = mid
            else:
                left = mid + 1
        return rotateArray[left]

if __name__=="__main__":
    Solution = Solution()
    print(Solution.minNumberInRotateArray([4,5,1,2]))