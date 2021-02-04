// Created by xingsiyuan on 2021/1/26 19:21.
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
输入一个链表，输出该链表中倒数第k个结点。

输入：1,{1,2,3,4,5}
输出： {5}

解题思路: 尺子的方法

*/


class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL) {
            return NULL;
        }
        ListNode* pre_node = pListHead;
        while (k--) {
            if (pre_node) {
                pre_node = pre_node->next;
            }
            else {
                return NULL;
            }
        }
        while (pre_node != NULL) {
            pre_node = pre_node->next;
            pListHead = pListHead->next;
        }
        return pListHead;
    }
};