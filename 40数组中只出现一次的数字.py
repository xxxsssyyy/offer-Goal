# -*- coding:utf-8 -*-
"""
题目描述：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
         请写程序找出这两个只出现一次的数字。
思路:1.HashMap,即python中的dict
"""
class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        m = {}
        for i in array:
            if i not in m:
                m[i] = 1
            else:
                m.pop(i)
        res = []
        for i in m.keys():
            res.append(i)
        return res

if __name__=="__main__":
    m = {1:1,2:3,5:6}
    m.pop(2)
    print(m)