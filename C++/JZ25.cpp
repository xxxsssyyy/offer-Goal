// Created by xingsiyuan on 2021/1/28 19:35.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/*
题目描述:
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。
 （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

输入：
输出：

解题思路:
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) {
            return NULL;
        }
        RandomListNode *p = pHead;
        // 复制当前节点, 并在next顺序中添加
        while (p) {
            RandomListNode *m = p->next;
            RandomListNode *temp = new RandomListNode(p->label);
            p->next = temp;
            temp->next = m;
            p = m;
        }
        // 添加random连接
        p = pHead;
        while (p) {
            RandomListNode *m = p->next;
            if (p->random) {
                m->random = p->random->next;
            }
            p = m->next;
        }
        // 分割为两个链表
        p = pHead;
        RandomListNode *copy_head = p->next;
        while (p) {
            RandomListNode *m = p->next;
            RandomListNode *b = m->next;
            p->next = b;
            if (b) {
                m->next = b->next;
            }
            else {
                m->next = NULL;
            }
            p = b;
        }
        return copy_head;
    }
};

