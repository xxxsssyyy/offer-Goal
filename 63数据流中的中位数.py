# -*- coding:utf-8 -*-
#这个题很重要，涉及到堆的数据结构，同时可以参考29题
"""
题目描述:
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法
读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
解题思路:
对于数据流取中位数的问题，利用最大堆和最小堆来管理
在每次插入时先插入到最小堆，如果最小堆中数据数目比最大堆大，则把最小堆中最小的数插入最大堆
每次插入的时间复杂度为O(logn),每次取出中位数的时间复杂度为O(1)
"""
"""
由于堆是一棵完全二叉树，存在n个元素，那么他的高度为:log2(n+1)，这就说明代码中的for循环会执行
O(log2(n))次。因此插入函数的时间复杂度为：O(log(n))
"""
class Solution:
    def __init__(self):
    # small代表数字小的大根堆
    # large代表数字大的小根堆
        self.large = []
        self.small = []
    # 大根堆插入
    def maxHeapInsert(self,array,num):
        array.append(num)
        i = len(array)-1
        while i>0:
            if array[i] > array[(i-1)//2]:
                array[i],array[(i-1)//2] = array[(i-1)//2],array[i]
                i = (i-1)//2
            else:
                break
    # 大根堆弹出,弹出后要对大根堆重排，先把最后一个数放在堆顶，然后
    def maxHeapPop(self,array):
        t = array[0]
        array[0] = array[-1]
        array.pop()
        i = 0
        n = len(array)
        while 2*i+1<n:
            nexti = 2*i+1
            # 如果分别有左右子结点并且找值最大的结点
            if nexti + 1<n and array[nexti+1]>array[nexti]:
                nexti+=1
            if array[nexti]>array[i]:
                array[i],array[nexti] = array[nexti],array[i]
                i =nexti
            else:
                break
        return t

    def Insert(self, num):
        #先将插入数字放入大根堆
        self.maxHeapInsert(self.small,num)
        #将大根堆最大数字弹出插入小根堆，其中小根堆用负数的大根堆实现
        self.maxHeapInsert(self.large,-self.maxHeapPop(self.small))
        if len(self.large)>len(self.small):
            self.maxHeapInsert(self.small,-self.maxHeapPop(self.large))
    def GetMedian(self,ss):# ss无任何意义，只是牛客网的bug必须加个输入
        #读取数据中的中位数
        if len(self.large)<len(self.small):
            return self.small[0]
        else:
            return (self.small[0]-self.large[0])/2.0

from heapq import *
class Solution2:
        def __init__(self):
            self.heaps = [], []
        def Insert(self, num):
            # write code here
            small, large = self.heaps
            # 将num放入大根堆，并弹出大根堆的最小值，取反，放入大根堆small
            heappush(small, -heappushpop(large, num))
            if len(large) < len(small):
                heappush(large, -heappop(small))
            # 弹出small中最小的值，取反，即最大的值，放入large

        def GetMedian(self, ss):
            # write code here
            small, large = self.heaps
            if len(large) > len(small):
                return float(large[0])
            return (large[0] - small[0]) / 2.0

if __name__=='__main__':
    Solution = Solution()
    Solution.Insert(5)
    Solution.Insert(8)
    Solution.Insert(11)
    Solution.Insert(2)
    print(Solution.GetMedian(1))