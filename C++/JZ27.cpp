// Created by xingsiyuan on 2021/1/29 13:55.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;

/*
题目描述:
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

输入：
输出：

解题思路: 回溯
*/

class Solution {
public:
    set<string> res;
    vector<string> Permutation(string str) {

        if (!str.length()) {
            return {};
        }
        dfs(0, str);
        vector<string> res_v;
        res_v.assign(res.begin(), res.end());
        return res_v;
    }
    void dfs(int index, string str) {

        if (index == str.length()-1) {
            res.insert(str);
            return;
        }
        for (int i = index; i < str.length(); i++) {
            swap(str[index], str[i]);
            dfs(index+1, str);
            swap(str[i], str[index]);
        }
    }
};

int main() {
    Solution sol;
    string str = "aaa";
    vector<string> res = sol.Permutation(str);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] <<std::endl;
    }

    return 0;
}
