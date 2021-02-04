// Created by xingsiyuan on 2021/1/26 17:13.
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
输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。

输入： 10
输出： 2

解题思路: 位运算 n & (n-1) 清理二进制n右面最后一个1，其余位仍为0

*/

class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        if (n < 0) {
            n = n & 0xffffffff;
        }
        while (n) {
            count += 1;
            n = n & (n-1);
        }
        return count;
    }
};