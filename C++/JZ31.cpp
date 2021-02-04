// Created by xingsiyuan on 2021/1/30 11:22.
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
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

输入：13
输出： 6

解题思路:
31056 , 31156 , 31256 考虑这三个数字百位数为1的次数
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int i = 1;
        int count = 0;
        while (i <= n) {
            int a = n / i;
            int b = n % i;
            if (a % 10 >= 2) {
                count += (a / 10 + 1) * i;
            }
            else if (a % 10 == 1) {
                count += a / 10 * i + b +1;
            }
            else {
                count += a / 10 * i;
            }
            i *= 10;
        }
        return count;
    }
};