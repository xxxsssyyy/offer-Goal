// Created by xingsiyuan on 2021/1/29 16:55.
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
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).

输入：[1,-2,3,10,-4,7,2,-5]
输出： 18

解题思路:

*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max_num = -INT_MAX;
        int temp = 0;
        for (int i = 0; i < array.size(); i++) {
            temp += array[i];
            max_num = max(temp, max_num);
            if (temp < 0) {
                temp = 0;
            }
        }
        return max_num;
    }
};
