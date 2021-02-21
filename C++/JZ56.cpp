// Created by 邢思远 on 2021/2/17 10:47 上午.
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
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

输入：{1,2,3,3,4,4,5}
输出：{1,2,5}

解题思路:

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (!pHead) {
            return pHead;
        }
        ListNode *pre_head = new ListNode(-1);
        pre_head->next = pHead;
        ListNode *pre = pre_head;
        while (pHead && pHead->next) {
            ListNode *temp = pHead->next;
            if (pHead->val == temp->val) {
                while (temp && pHead->val == temp->val) {
                    temp = temp->next;
                }
                pre->next = temp;
                pHead = temp;
            }
            else {
                pre = pre->next;
                pHead = pHead->next;
            }
        }
        return pre_head->next;
    }
};


int main() {
    Solution sol;
    ListNode *x1 = new ListNode(1);

    ListNode *x2 = new ListNode(1);
    ListNode *x3 = new ListNode(1);
    ListNode *x4 = new ListNode(1);
    x1->next = x2;
    x2->next = x3;
    x3->next = x4;

    ListNode* x = sol.deleteDuplication(x1);
    while (x) {
        std::cout << x->val << " ";
        x = x->next;
    }
    std::cout << std::endl;
    return 0;
}