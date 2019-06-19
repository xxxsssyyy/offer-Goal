# -*- coding:utf-8 -*-
# 第一遍没看懂题意思
"""
题目描述：请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
思路：递归，要考虑测试用例，极端情况(很难考虑全面)
逻辑：
if s==''&& pattern=='': True
if s==''&& pattern!='': False
if s==''&& pattern!='':
    1.pattern[1] == '*': 递归match("",pattern[2:])
    2.pattern[1] != '*': False
if s!=''&& pattern!='':
    1.pattern[1] == '*': (1) s[0]==pattern[0] or pattern[0]=='.'(相当于*打掉1个和*打掉0个):递归match(s[1:],pattern) or match(s,pattern[2:])
                             打掉0个：例如s="a" pattern="a*a" 打掉1个： 例如s="bba" pattern="b*a",递归为match("ba","b*a")
                         (2) else: 相当于*打掉0个
    2.pattern[1]!='*' and s[0]==pattern[0] or patten[0]=='.': 递归match(s[1:],pattern[1:])
"""
class Solution:
    # s, pattern都是字符串
    def match(self, s, pattern):
        # write code here
        if not s and not pattern:
            return True
        if s and not pattern:
            return False
        if not s and pattern:
            if len(pattern) > 1 and pattern[1] == '*':
                return self.match(s,pattern[2:])
            return False
        if len(pattern) > 1 and pattern[1] == '*':
            if s[0] == pattern[0] or pattern[0] == '.':
                return self.match(s[1:],pattern) or self.match(s,pattern[2:])
            else:
                return self.match(s, pattern[2:])
        if s[0] == pattern[0] or pattern[0] == '.':
            return self.match(s[1:],pattern[1:])



if __name__=='__main__':
    Solution = Solution()
    print (Solution.match("aaa","a.a"))
    print(Solution.match("aaa", "ab*ac*a"))
    print(Solution.match("aaa", "ab*a"))
    print(Solution.match("a", ".*"))
    print(Solution.match("a", "a*a"))
    #print(Solution.match("aaa", "a*a"))