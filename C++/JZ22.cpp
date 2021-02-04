// Created by xingsiyuan on 2021/1/27 19:53.
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
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

输入：{5,4,#,3,#,2,#,1}
输出： [5,4,3,2,1]

解题思路: 借助队列 BFS 宽度优先搜索
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> temp;
        temp.push(root);
        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();
            res.push_back(node->val);
            if (node->left) {
                temp.push(node->left);
            }
            if (node->right) {
                temp.push(node->right);
            }
        }
        return res;
    }
};