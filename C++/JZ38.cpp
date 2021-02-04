// Created by xingsiyuan on 2021/2/2 15:43.
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
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

输入：{1,2,3,4,5,#,6,#,#,7}
输出： 4

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
