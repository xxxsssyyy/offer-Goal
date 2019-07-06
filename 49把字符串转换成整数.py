# -*- coding:utf-8 -*-
"""
题目描述：将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
        但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
        数值为0或者字符串不是一个合法的数值则返回0。
        输入：输入一个字符串,包括数字字母符号,可以为空
        输出：如果是合法的数值表达则返回该数字，否则返回0
        示例：输入为+2147483647、1a33 输出为2147483647、0


解题思路： ord()函数把字符变为ascii值
"""
class Solution:
    def StrToInt(self, s):
        # write code here
        if not s:
            return 0
        sum = 0
        flag = 1
        for i in range(len(s)):
            if s[i]=='+' and i==0:
                flag = 1
            elif s[i]=='-' and i==0:
                flag = -1
            elif s[i]<'0' or s[i] > '9':
                return 0
            else:
                sum = sum*10 + (ord(s[i]) - ord('0'))
        return sum*flag

if __name__=='__main__':
    Solution = Solution()
    a = Solution.StrToInt('+123')
    print(a)


