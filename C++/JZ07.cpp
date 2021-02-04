// Created by xingsiyuan on 2021/1/26 14:14.
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
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。

输入：4
输出：3

解题思路:

*/

class Solution {
public:
    int Fibonacci(int n) {
        vector<int > array = {0, 1};
        for (int i = 2; i <= n; i++) {
            array.push_back(array[i-2]+array[i-1]);
        }
        return array[n];
    }
};