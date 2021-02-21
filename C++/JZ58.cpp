// Created by 邢思远 on 2021/2/21 5:48 下午.
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
请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

输入：{8,6,6,5,7,7,5}
输出：true

解题思路:

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot) {
            return true;
        }
        return compare(pRoot->left, pRoot->right);
    }
    bool compare(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2) {
            return false;
        }
        if (root1->val == root2->val) {
            return compare(root1->left, root2->right) & compare(root1->right, root2->left);
        }
        return false;
    }

};
