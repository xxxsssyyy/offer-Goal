// Created by 邢思远 on 2021/2/17 10:28 上午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <unordered_set>
using namespace std;

/*
题目描述:
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

输入：
输出：

解题思路:

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_set<ListNode*> ss;
        while (pHead) {
            if (ss.find(pHead) == ss.end()) {
                ss.insert(pHead);
                pHead = pHead->next;
            }
            else {
                return pHead;
            }
        }
        return NULL;
    }
};

