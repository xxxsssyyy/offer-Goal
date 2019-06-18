# -*- coding:utf-8 -*-
#题目描述：输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
#         则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
#         输入描述：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
class Solution:
    def __init__(self):
        self.res = []
        self.temp = ''
    def Permutation(self, ss):
        # write code here
        if not ss:
            return []
        length = len(ss)
        def aaa(str):
            for i in range(len(str)):
                self.temp += str[i]
                if len(self.temp) == length and self.temp not in self.res:
                    self.res.append(self.temp)
                aaa(str[:i]+str[i+1:])
                self.temp=self.temp[:-1]
        aaa(ss)
        return self.res

if __name__=='__main__':
    Solution = Solution()
    print(Solution.Permutation('abc'))