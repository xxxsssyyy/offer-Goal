// Created by xingsiyuan on 2021/1/29 14:41.
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
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

输入：{1,2,3,2,2,2,5,4,2}
输出： 2

解题思路:
1. 哈希表, 记录每个数字出现次数
2. 众数法, 用一个数字记录当前出现次数最多数字减去其他数字的次数， 最终要是>0， 就出现了一半以上
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }
        map<int, int> key_num;
        for (auto i: numbers) {
            key_num[i] += 1;
        }
        /*
        for (auto s : key_num) {
            if (s.second > numbers.size()/2) {
                return s.first;
            }
        }
        */
        map<int, int>::iterator it = key_num.begin();
        for ( ;it != key_num.end(); it++) {
            if (it->second > numbers.size()/2) {
                return it->first;
            }
        }
        return 0;
    }

};
