// Created by xingsiyuan on 2021/1/26 10:48.
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
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

示例:
输入：[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
输出：{1,2,5,3,4,6,7}

解题思路:
前序遍历: 跟左右
中序遍历: 左跟右
后序遍历: 左右跟
简单记忆方法: 前、中、后是跟的位置，左永远在右的前面
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return helper(pre, vin,0, pre.size()-1, 0, vin.size()-1);
    }
    TreeNode* helper(vector<int> pre, vector<int> vin, int pre_start, int pre_end, int vin_start, int vin_end) {
        if (pre_start > pre_end) {
            return NULL;
        }
        TreeNode *node = new TreeNode(pre[pre_start]);
        for (int i=vin_start; i <= vin_end; i++) {
            if (vin[i] == pre[pre_start]) {
                node->left = helper(pre, vin, pre_start+1, pre_start+i-vin_start, vin_start, i-1);
                node->right = helper(pre, vin, pre_start+i-vin_start+1, pre_end, i+1, vin_end);
                break;
            }
        }
        return node;
    }
};

int main() {
    Solution sol;
    vector<int > pre = {1,2,3,4,5,6,7};
    vector<int > vin = {3,2,4,1,6,5,7};
    TreeNode *node = sol.reConstructBinaryTree(pre, vin);
    std::cout << node->val << std::endl;
    return 0;
}