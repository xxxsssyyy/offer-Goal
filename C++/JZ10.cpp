// Created by xingsiyuan on 2021/1/26 14:32.
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
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
比如n=3时，2*3的矩形块有3种覆盖方法

输入： 4
输出： 5

解题思路: f(n) = f(n-1) + f(n-2)
        f(0) = 1 f(1) = 1 f(2) = 2

*/

class Solution {
public:
    int rectCover(int number) {
        if (number == 0) {
            return  0;
        }
        vector<int> array = {1, 1};
        for (int i = 2; i <= number; i++) {
            array.push_back(array[i-1]+array[i-2]);
        }
        return array[number];
    }
};