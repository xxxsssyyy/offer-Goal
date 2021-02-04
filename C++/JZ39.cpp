// Created by xingsiyuan on 2021/2/2 16:00.
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
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

输入：{1,2,3,4,5,6,7}
输出： true

解题思路:

*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) {
            return true;
        }
        int left_depth = TreeDepth(pRoot->left);
        int right_depth = TreeDepth(pRoot->right);
        bool r1 = false;
        if (abs(right_depth - left_depth) <= 1) {
            r1 = true;
        }
        bool r2 = IsBalanced_Solution(pRoot->left);
        bool r3 = IsBalanced_Solution(pRoot->right);
        return r1 & r2 & r3;
    }
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot) {
            return 0;
        }
        int depth;
        if (!pRoot->left && !pRoot->right) {
            depth = 1;
        }
        else if (!pRoot->left) {
            depth = 1 + TreeDepth(pRoot->right);
        }
        else if (!pRoot->right) {
            depth = 1 + TreeDepth(pRoot->left);
        }
        else {
            depth = 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
        }
        return depth;
    }
};
