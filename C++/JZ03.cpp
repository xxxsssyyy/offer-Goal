// Created by xingsiyuan on 2021/1/25 21:23.
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
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

示例:
输入：{67,0,24,58}
输出：[58,24,0,67]

解题思路:

*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while(head != NULL) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
};