// Created by xingsiyuan on 2021/1/28 13:44.
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
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。

输入：[4,8,6,12,16,14,10]
输出： true

解题思路:
*/

class Solution {
public:
    bool helpVerify(vector<int> sequence, int start, int end) {
        if (start > end) {
            return true;
        }
        int base = sequence[end];
        // 找到左右子树分割点
        int i = start;
        for ( ; i < end; i++) {
            if (sequence[i] > base) {
                break;
            }
        }
        // 判断右子树中是否有小于跟节点的值
        for (int j = i+1; j < end; j++) {
            if (sequence[j] < base) {
                return false;
            }
        }
        bool left = helpVerify(sequence, start, i-1);
        bool right = helpVerify(sequence, i, end-1);
        return left & right;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) {
            return false;
        }
        return helpVerify(sequence, 0, sequence.size()-1);
    }
};