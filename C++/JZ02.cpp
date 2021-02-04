// Created by xingsiyuan on 2021/1/25 19:34.
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
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy

示例:
输入：We Are Happy.
输出：We%20Are%20Happy

解题思路:先找到几个空格，然后从右向左替换（这样复制过程中不会被覆盖）

*/
class Solution {
public:
    void replaceSpace(char *str, int length) {
        int count = 0;
        for (int i=0; i < length; i++) {
            if (str[i] == ' ')
                count++;
        }
        for (int i=length-1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[i+count*2] = '0';
                str[i+count*2-1] = '2';
                str[i+count*2-2] = '%';
                count--;
            }
            else {
                str[i+count*2] = str[i];
            }
        }
    }
};
