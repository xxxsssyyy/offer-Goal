// Created by 邢思远 on 2021/2/21 6:56 下午.
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
请实现两个函数，分别用来序列化和反序列化二叉树
二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），
以 ！表示一个结点值的结束（value!）。二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自己的函数来解析回这个二叉树

输入：{8,6,10,5,7,9,11}
输出：{8,6,10,5,7,9,11}

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
    void Serialize_helper(TreeNode *root, string& strs) {
        if (!root) {
            strs += '#';
            strs += ',';
            return;
        }
        strs += to_string(root->val);
        strs += ',';
        Serialize_helper(root->left, strs);
        Serialize_helper(root->right, strs);
    }
    char* Serialize(TreeNode *root) {
        string strs = "";
        Serialize_helper(root, strs);
        char *res = new char[strs.length()+1];
        strcpy(res, strs.c_str());
        return res;
    }
    TreeNode* Deserialize_helper(string& strs) {
        if (strs.empty()) {
            return NULL;
        }
        if (strs[0] == '#') {
            strs = strs.substr(2);
            return NULL;
        }

        TreeNode *node = new TreeNode(stoi(strs));
        strs = strs.substr(strs.find_first_of(',') + 1);
        node->left = Deserialize_helper(strs);
        node->right = Deserialize_helper(strs);
        return node;
    }

    TreeNode* Deserialize(char *str) {
        if (!str) {
            return NULL;
        }
        string strs(str);
        return Deserialize_helper(strs);
    }

};

int main() {
    string a = "123";
    int k = stoi(a);
    char *str = new char[a.length()+1];
    strcpy(str, a.c_str());
    int m = atoi(str);
    cout << k << endl;
    cout << "m: " << m << endl;
    return 0;
}