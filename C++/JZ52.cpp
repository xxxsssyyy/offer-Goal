// Created by 邢思远 on 2021/2/6 11:29 上午.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/*
题目描述:
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

输入： "aaa","a*a"
输出： true

解题思路:
动态规划, dp[i][j] 代表 字符串s的前i位 和 字符串p的前j位 是否匹配
*/


class Solution {
public:
    bool match(char* str, char* pattern)
    {
        string s = str, p = pattern;
        int m = s.size(), n = p.size();
        s = "  " + s; //拓展字符串防止越界
        p = "  " + p;
        std::vector<std::vector<bool> > dp(m+2, std::vector<bool>(n+2, false));
        dp[0][0] = true;
        for (int i=1; i<m+2; ++i) {
            for (int j=1; j<n+2; ++j) {
                if (s[i] == p[j] || p[j] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j] == '*') {

                    if (p[j-1] == s[i] || p[j-1] == '.') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    }
                    else if (p[j-1] != s[i]) {
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }

        for (int i = 1; i < m + 2; i++) {
            for (int j = 1; j < n+2; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[m+1][n+1];

    }
};

