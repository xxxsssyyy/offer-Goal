# -*- coding:utf-8 -*-
"""
题目描述：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
         则经过替换之后的字符串为We%20Are%20Happy
"""
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        res = ''
        for i, letter in enumerate(s):
            if letter != ' ':
                res += letter
            else:
                res += '%20'
        return res