// Created by 邢思远 on 2021/2/22 9:05 上午.
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
给定一棵二叉搜索树，请找出其中的第k小的TreeNode结点。

输入： {5,3,7,2,4,6,8},3
输出： {4}

解题思路: 中序遍历

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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (!pRoot) {
            return NULL;
        }
        vector<TreeNode*> nodes;
        see_node(pRoot, nodes);
        if (k > nodes.size()) {
            return NULL;
        }
        return nodes[k-1];
    }
    void see_node(TreeNode *node, vector<TreeNode*>& nodes) {
        if (!node) {
            return;
        }
        see_node(node->left, nodes);
        nodes.push_back(node);
        see_node(node->right, nodes);
    }

    TreeNode* KthNode_recurrent(TreeNode* pRoot, int k)
    {
        stack<TreeNode*> stk;
        TreeNode *cur = pRoot;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (--k == 0) {
                return cur;
            }
            cur = cur->right;
        }
        return NULL;
    }

};