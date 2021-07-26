// Created by 邢思远 on 2021/2/22 7:09 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

/*
题目描述:
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
窗口大于数组长度的时候，返回空

输入： [2,3,4,2,6,2,5,1],3
输出： [4,4,6,6,6,5]

解题思路: 双向队列中暂存, 对于上述用例, 暂存值分别为 4, 42, 46, 62, 65, 51

*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if (!num.size() || size > num.size()) {
            return res;
        }
        int left = 0;
        deque<int> dq; // 双端队列
        while (left < num.size()) {
            // 判断头部下标是否过期
            if (dq.front()+size-1 < left) {
                dq.pop_front();
            }
            // 队列后面值小于当前数, 持续删除
            while (!dq.empty() && num[dq.back()] < num[left]) {
                dq.pop_back();
            }
            dq.push_back(left);
            if (left >= size-1) {
                res.push_back(num[dq.front()]);
            }
            left++;
        }
        return res;
    }
};
