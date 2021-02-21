// Created by 邢思远 on 2021/2/6 11:27 上午.
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

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
对于A长度为1的情况，B无意义，故而无法构建，因此该情况不会存在

输入： [1,2,3,4,5]
输出： [120,60,40,30,24]

解题思路:

*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        vector<int> left = {1};
        vector<int> right = {1};
        for (int i = 0; i < A.size()-1; i++) {
            left.push_back(A[i] * left[left.size()-1]);
            right.push_back(A[A.size()-1-i] * right[right.size()-1]);
        }
        for (int i = 0; i < A.size(); i++) {
            B.push_back(left[i]*right[A.size()-1-i]);
        }
        return B;
    }
};

int main() {
    Solution sol;
    vector<int> B = sol.multiply({1,2,3,4,5});

    for (auto b : B) {
        cout << b << " ";
    }
    cout << endl;
    return 0;
}
