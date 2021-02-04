// Created by xingsiyuan on 2021/2/4 11:31.
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
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

输入： 1, 2
输出： 3

解题思路:
&:按位与，两个数按位与结果显示哪些位为进位，<<1左移后为进位的值
^:异或，两个数异或表示每位相加的值，不算进位

*/


class Solution {
public:
    int Add(int num1, int num2)
    {
        while (num2) {
            int temp = num1 ^ num2;
            num2 = (num1 & num2) << 1;
            num1 = temp;
        }
        return num1;
    }
};

