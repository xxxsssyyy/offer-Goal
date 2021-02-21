// Created by 邢思远 on 2021/2/21 6:15 下午.
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
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

输入：{8,6,10,5,7,9,11}
输出：[[8],[10,6],[5,7,9,11]]

解题思路:

*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        int level = 0;
        vector<vector<int> > ret;
        queue<TreeNode*> temp_nodes;
        if (!pRoot) {
            return ret;
        }
        temp_nodes.push(pRoot);
        while (!temp_nodes.empty()) {
            int ns = temp_nodes.size();
            vector<int> temps;
            while (ns--) {
                TreeNode *node = temp_nodes.front();
                temp_nodes.pop();
                temps.push_back(node->val);
                if (node->left) temp_nodes.push(node->left);
                if (node->right) temp_nodes.push(node->right);
            }
            if (level % 2 == 1) {
                reverse(temps.begin(), temps.end());
            }
            level++;
            ret.push_back(temps);
        }
        return ret;
    }

};
