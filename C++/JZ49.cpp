// Created by xingsiyuan on 2021/2/4 13:43.
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
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

输入： "+2147483647"
输出： 2147483647

解题思路:

*/

class Solution {
public:
    int StrToInt(string str) {
        int flag = 1;
        int ret = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '+' && i == 0) {
                flag = 1;
            }
            else if (str[i] == '-' && i == 0) {
                flag = -1;
            }
            else if (str[i] > '9' || str[i] < '0') {
                return 0;
            }
            else {
                ret = ret*10 + str[i] - '0';
            }
        }
        return flag*ret;
    }
};
