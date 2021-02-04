// Created by xingsiyuan on 2021/1/27 9:57.
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
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

输入：{1,3,5},{2,4,6}
输出： {1,2,3,4,5,6}

解题思路: 递归思想
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1) {
            return pHead2;
        }
        if (!pHead2) {
            return pHead1;
        }
        ListNode* p;
        if (pHead1->val <= pHead2->val) {
            p = pHead1;
            p->next = Merge(pHead1->next, pHead2);
        }
        else {
            p = pHead2;
            p->next = Merge(pHead1, pHead2->next);
        }
        return p;
    }
};