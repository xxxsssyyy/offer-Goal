// Created by 邢思远 on 2021/2/23 10:18 上午.
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
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]
可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

输入： 8
输出： 18

解题思路:
 动态规划 res[n] = max(i*(n-i),i*res[n-i],res[i]*res[n-i]), i from 1 to n-1

*/

class Solution {
public:
    int cutRope(int number) {
        vector<int> res = {0, 1, 1};
        for (int i = 3; i <= number; i++) {
            int temp = 0;
            for (int j = 1; j < i; j++) {
                if (max(j*(i-j), max(j*res[i-j], res[j]*res[i-j])) > temp) {
                    temp = max(j * (i - j), max(j * res[i - j], res[j] * res[i - j]));
                }
            }
            res.push_back(temp);
        }
        return res[number];
    }
};