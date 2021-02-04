// Created by xingsiyuan on 2021/1/27 19:10.
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
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

输入：[1,2,3,4,5],[4,3,5,1,2]
输出： false

解题思路: 栈模拟
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> temp;
        int i = 0, j = 0;
        while (i < pushV.size()) {
            if (temp.empty() || temp.top() != popV[j]) {
                temp.push(pushV[i]);
                i++;
            }
            while (!temp.empty() && temp.top() == popV[j]) {
                temp.pop();
                j++;
            }

        }
        return temp.empty();
    }
};

int main() {
    Solution sol;
    vector<int> pushV = {1,2,3,4,5}, popV = {4,5,3,2,1};
    std::cout << sol.IsPopOrder(pushV, popV) << std::endl;
    return 0;
}