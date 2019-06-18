# -*- coding:utf-8 -*-
"""
第一个只出现一次的字符
题目描述：在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）
"""
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        if not s:
            return -1
        a = {}
        for i in range(len(s)):
            if s[i] not in a:
                a[s[i]] = i
            else:
                a[s[i]] = -1
        min_index = 10000
        for key in a.keys():
            if  -1 <a[key] < min_index:
                min_index = a[key]
        if min_index == 10000:
            return -1
        else:
            return min_index
#简单写法实现
    def aaa(self,s):
        return [i for i in range(len(s)) if s.count(s[i]) == 1][0] if s else -1