# -*- coding:utf-8 -*-
"""
题目描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。
"""
class Solution:
    # 算法思路：创建dict解决
    # 时间复杂度O(N)
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        a = {}
        for i in numbers:
            if i not in a.keys():
                a[i] = 1
            else:
                a[i] += 1
        for key,value in a.items():
            if value*2>len(numbers):
                return key
        return 0

    def quick_sort(self,array):
        # https://www.jianshu.com/p/2b2f1f79984e
        if len(array) < 2:
            return array
        else:
            pivot = array[0]
            less_than_pivot = [x for x in array[1:] if x <= pivot]
            more_than_pivot = [x for x in array[1:] if x > pivot]
            return self.quick_sort(less_than_pivot) + [pivot] + self.quick_sort(more_than_pivot)
    """
    快速排序(quick sort)的采用了分治的策略:
    分治策略指的是：
    将原问题分解为若干个规模更小但结构与原问题相似的子问题。递归地解这些子问题，
    然后将这些子问题的解组合为原问题的解。
    快排的基本思想是：
    在序列中找一个划分值，通过一趟排序将未排序的序列排序成 独立的两个部分，
    其中左边部分序列都比划分值小，右边部分的序列比划分值大，此时划分值的位置已确认，
    然后再对这两个序列按照同样的方法进行排序，从而达到整个序列都有序的目的。

    """
    def QuickSort(self,numbers):
        i,j=0,len(numbers)-1
        if j<2:
            return numbers
        base = numbers[i]
        while i<j:
            while i<j and numbers[j]>=base:
                j-=1
            numbers[i] = numbers[j]
            while i<j and numbers[i]<base:
                i+=1
            numbers[j] = numbers[i]
        numbers[i]=base
        return self.QuickSort(numbers[:i])+[numbers[i]]+self.QuickSort(numbers[i+1:])


if __name__=='__main__':
    Solution = Solution()
    #print(Solution.MoreThanHalfNum_Solution([1,2,3,2,2,2,5,4,2]))
    print(Solution.quick_sort([49,38,65,97,76,13,27,49]))
    print(Solution.QuickSort([49, 38, 65, 97, 76, 13, 27, 49]))