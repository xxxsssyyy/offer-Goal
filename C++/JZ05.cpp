// Created by xingsiyuan on 2021/1/26 12:34.
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
题目描述:
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

解题思路:
队列: 先入先出;  栈: 先入后出

*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }

        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};