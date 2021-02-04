// Created by xingsiyuan on 2021/2/3 13:33.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>

using namespace std;

/*
题目描述:
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

输入： "nowcoder. a am I"
输出： "I am a nowcoder."

解题思路:

*/

class Solution {
public:
    string ReverseSentence(string str) {
        string res, temp;

        stack<string> ss;
        for (auto c: str) {
            if (c == ' ') {
                ss.push(temp);
                ss.push(" ");
                temp.clear();
            }
            else {
                temp += c;
            }
        }
        ss.push(temp);
        while (!ss.empty()) {
            res += ss.top();
            ss.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    string res = sol.ReverseSentence("   ");
    std::cout << res.length() << std::endl;
    return 0;
}