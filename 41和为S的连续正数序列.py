# -*- coding:utf-8 -*-
"""
题目描述：小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,
他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的
找出所有和为S的连续正数序列? Good Luck!

输出描述：输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
解题思路：1.我最开始的思路是找中间数，分为两种情况
        2.双指针法，两个指针分别指向首端和末端

"""

class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        res = []
        #for i in range(tsum-1,1,-1):#复杂度O(n)
        # ***可优化为O(sqrt(n)):  由于n<sqrt(2tsum)
        h = int((2* tsum) ** 0.5)
        for i in range(h,1,-1):
            mid = tsum*1.0/i
            if mid - int(mid) == 0.5 and i%2==0 and mid- i/2>0 and mid+i/2<tsum:
                res.append([int(int(mid)-i/2+j) for j in range(1,i+1)])
            if mid - int(mid) == 0 and i%2==1 and mid- i/2>0 and mid+i/2<tsum:
                res.append([int(int(mid)-i/2+j) for j in range(i)])
        return res

    def FindContinuousSequence1(self, tsum):
        res = []
        left = 1
        right = 2
        temp_sum = (left + right) * (right - left + 1) / 2
        while left < right and right<tsum:
            temp_sum = (left+right)*(right-left+1)/2
            if temp_sum == tsum:
                res.append(list(range(left,right+1)))
                right+=1
            elif temp_sum <tsum:
                right += 1
            else:
                left += 1
        return res

if __name__=="__main__":
    Solution = Solution()
    res = Solution.FindContinuousSequence1(100)
    print(res)