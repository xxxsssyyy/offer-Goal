// Created by xingsiyuan on 2021/2/1 19:22.
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
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）

输入："google"
输出： 4

解题思路: 哈希表

*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }
        map<char, int> char_count, char_index;

        for (int i = 0; i < str.length(); i++) {
            char_count[str[i]]++;
            char_index[str[i]] = i;
        }
        int min_index = INT_MAX;
        for (auto p : char_count) {
            if (p.second == 1) {
                min_index = min(min_index, char_index[p.first]);
            }
        }
        return (min_index == INT_MAX ? -1 : min_index);
    }
};