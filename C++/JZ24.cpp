// Created by xingsiyuan on 2021/1/28 14:07.
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
输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

输入：{10,5,12,4,7},22
输出： [[10,5,7],[10,12]]

输入: {10,5,12,4,7},15
输出: []

解题思路: 回溯
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs (TreeNode* root, vector<vector<int> > ret, vector<int> path, int num) {
        // 剪枝

        if (root->val > num) {
            return;
        }
        path.push_back(root->val);
        if (num == root->val && !root->left && !root->right) {
            ret.push_back(path);
        }
        if (root->left) {
            dfs(root->left, ret, path, num-root->val);
        }
        if (root->right) {
            dfs(root->right, ret, path, num-root->val);
        }
        path.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > ret;
        vector<int> path;
        if (!root) {
            return ret;
        }
        dfs(root, ret, path, expectNumber);
        return ret;
    }
};