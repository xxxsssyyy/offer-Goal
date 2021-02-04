// Created by xingsiyuan on 2021/2/3 12:43.
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
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输入：9
输出： [[2,3,4],[4,5]]

解题思路: 双指针法, 一般区间问题都可以考虑双指针法

*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        if (sum <= 0) {
            return ret;
        }
        int left = 1, right = 2;

        while (left < right && right < sum) {
            int temp_sum = (left + right) * (right - left + 1) / 2;
            if (temp_sum == sum) {
                vector<int> temp;
                for (int i = left; i <= right; i++) {
                    temp.push_back(i);
                }
                ret.push_back(temp);
            }
            if (temp_sum < sum) {
                right++;
            }
            else {
                left++;
            }
        }
        return ret;
    }
};
