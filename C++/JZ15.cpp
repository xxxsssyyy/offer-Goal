// Created by xingsiyuan on 2021/1/25 21:53.
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
输出：{58,24,0,67}

解题思路:

*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) {
            return NULL;
        }
        ListNode *pre = NULL;
        ListNode *aft;
        // 这里注意while条件
        while (pHead!= NULL) {
            aft = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = aft;
        }
        return pre;
    }
};

int main() {
    Solution sol;
    sol.ReverseList();
    return 0;
};