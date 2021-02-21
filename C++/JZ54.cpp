// Created by 邢思远 on 2021/2/17 10:16 上午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
题目描述:

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 如果当前字符流没有存在出现一次的字符，返回#字符

输入：
输出：

解题思路: 哈希表

*/

class Solution
{
public:
    //Insert one char from stringstream
    string strs = "";
    unordered_map<char, int> char2count;
    void Insert(char ch)
    {
        strs += ch;
        char2count[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for (auto c : strs) {
            if (char2count[c] == 1) {
                return c;
            }
        }
        return '#';
    }

};
