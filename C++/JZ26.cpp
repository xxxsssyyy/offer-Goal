// Created by xingsiyuan on 2021/1/28 20:29.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
题目描述:
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

解题思路:
*/

class Solution {
public:
    TreeNode* head = NULL;
    TreeNode* p = NULL; // 标记起始节点
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) {
            return pRootOfTree;
        }
        midDFS(pRootOfTree);
        return p;
    }
    void midDFS(TreeNode* cur) {
        if (!cur) {
            return;
        }
        midDFS(cur->left);
        if (!head) {
            head = cur;
            p = cur;
        }
        else {
            head->right = cur;
            cur->left = head;
            head = cur;
        }
        midDFS(cur->right);
    }
};
