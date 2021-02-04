// Created by xingsiyuan on 2021/1/26 17:31.
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
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
保证base和exponent不同时为0.

输入： 2, 3
输出： 8.00

解题思路: 位运算 例如：3^{7} = 3^{1+2+4}

*/

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        int a = abs(exponent);
        double count = 1;
        double tmp = base;
        while (a) {
            if (a & 1) {
                count *= tmp;
            }
            tmp = tmp * tmp;
            a = a>>1;
        }
        return (exponent > 0 ? count : 1/count);
    }
};
