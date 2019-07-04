# -*- coding:utf-8 -*-
"""
题目描述：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
        字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14",
        "1.2.3","+-5"和"12e+4.3"都不是。
解题思路：
        搞清楚满足的条件，ps:条件太多了，很难搞清楚
        这时候尽量想全测试用例:
        这道题可以联想我们学FPGA中的状态机,最好画一个
"""
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        hasE, hassign, hasdian = 0,0,0
        for i in range(len(s)):
            if s[i] == 'e' or s[i]=='E':
                if i == len(s)-1: # E不能位于最后一位
                    return False
                if hasE:  # 不能有两个E
                    return False
                hasE = 1
            elif s[i] =='+' or s[i] == '-':
                if hassign and s[i-1]!='e' and s[i-1]!='E':
                # 第二次出现符号必须出现在e后面
                    return False
                if not hassign and i>0 and s[i-1]!='e' and s[i-1]!='E':
                # 第一次出现符号且不在最前面也必须出现在e后面
                    return False
                hassign = 1
            elif s[i] == '.':
                if hasE or hasdian:
                # .必须出现在e前面且只能出现一次
                    return False
                hasdian = 1
            elif s[i] < '0' or s[i]>'9':
                return False
        return True

if __name__=='__main__':
    Solution = Solution()
    a = Solution.isNumeric("1.2e")
    print(a)


