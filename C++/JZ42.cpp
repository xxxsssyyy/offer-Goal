// Created by xingsiyuan on 2021/2/3 13:11.
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
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

输入：[1,2,4,7,11,15],15
输出： [4,11]

解题思路:

*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        int left = 0, right = array.size()-1;
        while (left < right) {
            int temp_sum = array[left] + array[right];
            if (temp_sum == sum) {
                ret.push_back(array[left]);
                ret.push_back(array[right]);
                break;
            }
            else if (temp_sum < sum) {
                left++;
            }
            else {
                right--;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> ret = sol.FindNumbersWithSum({1,2,4,7,11,15},15);
    for (auto p : ret) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    return 0;
}
