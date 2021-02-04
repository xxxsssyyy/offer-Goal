// Created by xingsiyuan on 2021/1/27 10:05.
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
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

输入：{8,8,#,9,#,2,#,5},{8,9,#,2}
输出： true

解题思路: 递归
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2) {
            return false;
        }
        if (!pRoot1) {
            return false;
        }
        int temp = isSubTree(pRoot1, pRoot2);
        int temp1 = isSubTree(pRoot1->left, pRoot2);
        int temp2 = isSubTree(pRoot1->right, pRoot2);
        bool res = temp | temp1 | temp2;
        return res;
    }
    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2) { //子结构不是子树, 这里面包含即可, 因此无需 !pRoot1
            return true;
        }
        if (!pRoot1) {
            return false;
        }
        if (pRoot1->val != pRoot2->val) {
            return false;
        }
        return isSubTree(pRoot1->left, pRoot2->left) & isSubTree(pRoot1->right, pRoot2->right);
    }
};