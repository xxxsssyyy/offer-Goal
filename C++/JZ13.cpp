// Created by xingsiyuan on 2021/1/26 17:56.
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
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

输入：
输出：

解题思路:

*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int > array1, array2;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 1) {
                array1.push_back(array[i]);
            }
            else {
                array2.push_back(array[i]);
            }
        }
        array1.insert(array1.end(), array2.begin(), array2.end());
        copy(array1.begin(), array1.end(), array.begin());
    }
};