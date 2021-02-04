// Created by xingsiyuan on 2021/1/26 14:19.
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
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

输入： 4
输出： 5

解题思路: f(n) = f(n-1) + f(n-2)

*/

class Solution {
public:
    int jumpFloor(int number) {
        vector<int > array = {1, 1};
        for (int i = 2; i <= number; i++) {
            array.push_back(array[i-2]+array[i-1]);
        }
        return array[number];
    }
};