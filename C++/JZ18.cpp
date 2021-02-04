// Created by xingsiyuan on 2021/1/27 10:38.
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
操作给定的二叉树，将其变换为源二叉树的镜像。

二叉树的镜像定义：源二叉树
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

解题思路:
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot) {
            return;
        }
        else if (!pRoot->left && !pRoot->right) {
            return;
        }
        else if (!pRoot->left) {
            pRoot->left = pRoot->right;
            pRoot->right = NULL;
        }
        else if (!pRoot->right) {
            pRoot->right = pRoot->left;
            pRoot->left = NULL;
        }
        else {
            TreeNode* temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
        }
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

