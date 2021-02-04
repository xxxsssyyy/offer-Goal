// Created by xingsiyuan on 2021/1/30 11:47.
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
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

输入：[3,32,321]
输出： "321323"

解题思路:
思路是比较大小 a+b 和 b+a比较
*/

bool compare(string a, string b) {
    return a+b < b+a;
}

class Solution {
public:

    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty()) {
            return "";
        }
        vector<string> strs;
        for (auto num : numbers) {
            strs.push_back(to_string(num));
        }
        quick_sort(strs, 0 ,strs.size()-1);
        // 用内置sort函数
        // sort(strs.begin(), strs.end(), compare);
        string res = "";
        for (auto st : strs) {
            res += st;
        }
        return res;
    }

    void quick_sort(vector<string> &numbers, int start, int end) {
        if (end - start <= 0) {
            return;
        }
        int i = start, j = end;
        string base = numbers[start];
        while (i < j) {
            while (i < j && numbers[j] + base >= base + numbers[j]) {
                j--;
            }
            numbers[i] = numbers[j];
            while (i < j && numbers[i] + base <= base + numbers[i]) {
                i++;
            }
            numbers[j] = numbers[i];
        }
        numbers[i] = base;
        quick_sort(numbers, start, i-1);
        quick_sort(numbers, i+1, end);

    }

};

int main() {
    Solution sol;
    vector<int> nums = {3,32,321};
    string res = sol.PrintMinNumber(nums);
    std::cout << res <<std::endl;
    return 0;
}