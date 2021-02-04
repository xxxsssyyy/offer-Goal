// Created by xingsiyuan on 2021/1/27 13:05.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>

using namespace std;

/*
题目描述: 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

输入：
输出：

解题思路: 两个栈, 一个正常存数据, 一个存当前的最小值
*/

class Solution {
public:
    stack<int> normal, minval;
    void push(int value) {
        normal.push(value);
        if (minval.empty()) {
            minval.push(value);
        }
        else {
            if (value < minval.top()) {
                minval.push(value);
            }
            else {
                minval.push(minval.top());
            }
        }
    }
    void pop() {
        normal.pop();
        minval.pop();
    }
    int top() {
        return normal.top();
    }
    int min() {
        return minval.top();
    }
};