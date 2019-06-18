# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        left,right = 0,len(rotateArray)-1
        while left < right:
            mid = (left + right)//2
            if rotateArray[mid]>rotateArray[right]:#考虑只剩两个数的情况，确定判断条件写法
                #左半有序
                left = mid+1
            else:#左半无序
                right = mid
        return rotateArray[right]
    def binary_Search(self, array, target):
        left ,right = 0, len(array)-1
        while left<right:
            mid = (left + right)//2
            if array[mid]<target:
                left = mid +1
            else:
                right = mid
        if array[right] == target:
            return True
        return False


if __name__=='__main__':
    Solution = Solution()
    #print(Solution.minNumberInRotateArray([3,4,5,6,1,2]))
    print(Solution.binary_Search([1,3,5,6,7,8,35],4))