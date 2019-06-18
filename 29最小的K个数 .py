# -*- coding:utf-8 -*-
"""
堆排序
题目描述：输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
"""
# 想法1:快速排序,基于划分的方法，时间复杂度O(nlogn)
class Solution1:
    def GetLeastNumbers_Solution(self, tinput, k):
        length = len(tinput)
        if k>length:
            return []
        left,right = 0,length-1
        base = tinput[0]
        self.partition(tinput)
        return tinput[:k]

    def partition(self,tinput):
        length = len(tinput)
        if length<2:
            return tinput
        left, right = 0, length - 1
        base = tinput[0]
        while left<right:
            while left<right and tinput[right]>base:
                right -= 1
            tinput[left] = tinput[right]
            while left<right and tinput[left]<=base:
                left += 1
            tinput[right] = tinput[left]
            tinput[left] = base
        return self.partition(tinput[:left]) +[tinput[left]]+self.partition(tinput[left+1:])


#想法2：堆排序
# https://blog.csdn.net/u010005281/article/details/80084994
# 思路详解：https://www.jianshu.com/p/d174f1862601
# 排序过程视频：https://www.bilibili.com/video/av18980178?from=search&seid=3518072115040122033
class Solution2:
    def main(self,ori_array):
        x = len(ori_array)-1
        self.heapfiy(ori_array,x)
        print(ori_array)
        while x>1:
            #交换堆顶（当前最大值）与堆底后，去除堆底对子堆进行排序
            ori_array[1],ori_array[x] = ori_array[x], ori_array[1]
            x-=1
            self.sort(ori_array,1,x)
        return ori_array

    def heapfiy(self,array,end): #创建堆并对堆进行排序
        n = end//2
        x = len(array)-1
        #注意这里一定要从堆底向堆顶进行排序
        while n>0:
            self.sort(array,n,x)
            n-=1

    def sort(self,array,start,end):#对堆进行排序
            if end<2*start:
                return
            elif end == 2*start:
                if array[start]<array[end]:
                    array[start],array[end] = array[end],array[start]
            else:
                left = array[2*start]
                right = array[2*start+1]
                if left>=right and left>array[start]:
                    array[2*start],array[start] = array[start],array[start*2]
                    self.sort(array,start*2,end)
                if left<right and right>array[start]:
                    array[2*start+1],array[start] = array[start],array[2*start+1]
                    self.sort(array,start*2+1,end)
"""
**************************
关于堆，可参考：https://www.jianshu.com/p/d174f1862601
利用堆排序，创建一个k的大根堆（堆是一种完全二叉树）
对堆进行一次sort排序时间复杂度为O(logk)，其组成为k个数的排序O(klogk)+
另外n-k个数(次)的O((n-k)logk)
所以总体时间复杂度为nlogk，当n>>k时，这种算法的时间优势会更明显，
因此适用于海量数据的情况
"""
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        if len(tinput)<k or k==0:
            return []
        res = [0] + tinput[:k]
        self.heapfiy(res,k)
        for m in tinput[k:]:
            if m<res[1]:
                res[1] = m
                self.sort(res,1,k)
        return res[1:]

    def heapfiy(self, array, end):  # 创建堆并对堆进行排序
        n = end // 2
        x = len(array) - 1
        # 注意这里一定要从堆底向堆顶进行排序
        while n > 0:
            self.sort(array, n, x)
            n -= 1

    def sort(self, array, start, end):  # 对堆进行排序
        if end < 2 * start:
            return
        elif end == 2 * start:
            if array[start] < array[end]:
                array[start], array[end] = array[end], array[start]
        else:
            left = array[2 * start]
            right = array[2 * start + 1]
            if left >= right and left > array[start]:
                array[2 * start], array[start] = array[start], array[start * 2]
                self.sort(array, start * 2, end)
            if left < right and right > array[start]:
                array[2 * start + 1], array[start] = array[start], array[2 * start + 1]
                self.sort(array, start * 2 + 1, end)
"""
利用python中heapq模块实现：
Python中的heapq模块用来建立“堆”这种数据结构。 
heapq.heappush(res, -i) 意为：向堆res中添加一个元素-i 
heapq.heappushpop(res, -i)意为：将元素-i与堆顶的元素比较。如果该元素值大于堆顶元素，
则将该元素与堆顶元素替换。否则不改变堆元素。
"""
import heapq
def GetLeastNumbers_Solution(tinput, k):
    if len(tinput) < k:
        return []
    res = []
    for i in tinput:
        heapq.heappush(res, -i) if len(res) < k else heapq.heappushpop(res, -i)
    # map()映射
    return sorted(list(map(lambda x: -x, res)))
    #return res

"""
TopK处理大数据参考：
https://blog.csdn.net/CSDN___LYY/article/details/82909081
"""
if __name__ == '__main__':
    Solution = Solution()
    Solution2 = Solution2()
    #print(Solution.GetLeastNumbers_Solution([4,5,1,6,2,7,3,8],4))
    print(Solution2.main([0, 74, 73, 59, 72, 64, 69, 43, 36, 70, 61, 40, 16, 47, 67, 17, 31, 19, 24, 14, 20, 48, 5, 7, 3, 78, 84, 92, 97, 98, 99]))
    #print(Solution.main([0,4,10,3,5,1]))
    print(Solution.GetLeastNumbers_Solution([74, 73, 59, 72, 64, 69, 43, 36, 70, 61, 40, 16, 47, 67, 17, 31, 19, 24, 14, 20, 48, 5, 7, 3, 78, 84, 92, 97, 98, 99],5))
    print(GetLeastNumbers_Solution([4,5,1,6,2,7,3,8],4))