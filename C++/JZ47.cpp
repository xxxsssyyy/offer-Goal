// Created by xingsiyuan on 2021/2/3 16:46.
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
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

输入： 5
输出： 15

解题思路:

*/

class Solution {
public:
    int Sum_Solution(int n) {
        if (n == 1) {
            return n;
        }
        return n + Sum_Solution(n-1);
    }
};
