# -*- coding:utf-8 -*-
"""
题目描述：请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:如果当前字符流没有存在出现一次的字符，返回#字符。
思路：
"""

class Solution:
    # 返回对应char
    def __init__(self):
        self.s = ""
    def FirstAppearingOnce(self):
        # write code here
        char_dict = {}
        char_list = []
        for i in self.s:
            if i not in char_list:
                char_list.append(i)
                char_dict[i] = 1
            else:
                char_dict[i] += 1
        for i in char_list:
            if char_dict[i] == 1:
                return i
        return "#"

    def Insert(self, char):
        self.s += char

if __name__=='__main__':
    Solution = Solution()
    print(Solution.FirstAppearingOnce("google"))
    print(Solution.FirstAppearingOnce("microsoft"))