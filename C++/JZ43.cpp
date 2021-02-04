// Created by xingsiyuan on 2021/2/3 13:20.
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
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

输入："abcXYZdef",3
输出： "XYZdefabc"

解题思路:

*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (n > str.size()) return str;
        string res = "";
        res.insert(res.end(), str.begin()+n, str.end());
        res.insert(res.end(), str.begin(), str.begin()+n);
        return res;
    }
};