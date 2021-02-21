// Created by 邢思远 on 2021/2/21 6:44 下午.
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
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

输入：{8,6,10,5,7,9,11}
输出：[[8],[6,10],[5,7,9,11]]

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
        vector<vector<int> > ret;
        if (!pRoot) {
            return ret;
        }
        queue<TreeNode*> temp_nodes;
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
            ret.push_back(temps);
        }
        return ret;
    }
};

