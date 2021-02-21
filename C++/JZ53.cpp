// Created by 邢思远 on 2021/2/6 11:30 上午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

/*
题目描述:
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

输入： "123.45e+6"
输出： true

解题思路:

*/

class Solution {
public:
    bool isNumeric(char* string)
    {
        int n = strlen(string);
        bool has_e = false, has_sign = false, has_dian = false;
        for (int i = 0; i < n; i++) {
            if (string[i] == 'e' || string[i] == 'E') {
                // e不能位于最后一位
                if (i == n-1) return false;
                // 不能有两个e
                if (has_e) return false;
                has_e = true;
            }
            else if (string[i] == '+' || string[i] == '-') {
                // 第二次出现符号必须出现在e后面
                if (has_sign && string[i-1] != 'E' && string[i-1] != 'e') return false;
                // 第一次出现符号且不在最前面也必须出现在e后面
                if (!has_sign && i>0 && string[i-1]!='e' && string[i-1]!='E') return false;
                has_sign = true;
            }
            else if (string[i] == '.') {
                // .必须出现在e前面且只能出现一次
                if (has_e || has_dian) return false;
                has_dian = true;
            }
            else if (string[i] < '0' or string[i]>'9') return false;

        }
        return true;
    }

};
