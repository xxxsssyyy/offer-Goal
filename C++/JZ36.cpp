// Created by xingsiyuan on 2021/2/2 13:53.
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
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

输入：1->3->4->5->6 和 8->9->5->6
输出： 5->6

解题思路:  两个链表最主要问题是长度可能不一致, 对于长度不一致 通过 a+b 和 b+a进行比较

如 8->9->5->6->1->3->4->5->6 和 8->9->5->6->1->3->4->5->6 比较

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1, *p2 = pHead2;
        while (p1 != p2) {
            p1 = (p1 != NULL ? p1->next : pHead2);
            p2 = (p2 != NULL ? p2->next : pHead1);
        }
        return p1;
    }
};