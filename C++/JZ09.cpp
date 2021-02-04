// Created by xingsiyuan on 2021/1/26 14:26.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

/*
题目描述:
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

输入： 3
输出： 4

解题思路: f(n) = f(n-1) +f(n-2) + ... + f(0) = 2f(n-1)

*/

class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0 || number == 1) {
            return 1;
        }
        return pow(2, number-1);
    }
};