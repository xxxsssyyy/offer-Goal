// Created by 邢思远 on 2021/2/18 9:54 上午.
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
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

输入：
输出：

解题思路:

*/

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
}
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (!pNode) {
            return pNode;
        }
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }
        else {
            while (pNode->next) {
                if (pNode->next->left == pNode) { // 父亲结点的左孩子
                    return pNode->next;
                }
                else {
                    pNode = pNode->next; // 父亲结点的右孩子: 不断迭代右孩子结点, 直到该结点为父结点的左孩子
                }
            }
        }
        return NULL;
    }
};
