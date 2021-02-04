// Created by xingsiyuan on 2021/2/2 17:13.
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
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

输入：
输出：

解题思路:

*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int, int> num2count;
        for (auto x : data) {
            num2count[x]++;
        }
        vector<int> ret;
        for (auto p : num2count) {
            if (p.second == 1) {
                ret.push_back(p.first);
            }
        }
        *num1 = ret[0];
        *num2 = ret[1];
    }
};
