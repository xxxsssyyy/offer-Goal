// Created by xingsiyuan on 2021/2/1 18:59.
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
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

输入：7
输出： 8

解题思路:

*/


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> nums = {1};
        int t2 = 0, t3 = 0, t5 = 0;
        int i = 1;
        while (i < index) {
            int ugly_num = min(nums[t2]*2, min(nums[t3]*3, nums[t5]*5));
            nums.push_back(ugly_num);
            if (nums[t2]*2 == ugly_num) {
                t2++;
            }
            if (nums[t3]*3 == ugly_num) {
                t3++;
            }
            if (nums[t5]*5 == ugly_num) {
                t5++;
            }
            i++;
        }
        return nums[index-1];
    }
};

