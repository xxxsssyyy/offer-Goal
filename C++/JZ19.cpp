// Created by xingsiyuan on 2021/1/27 10:54.
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
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

解题思路:
1.指针法
2.削苹果(旋转)
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> p_matrix;
        int left = 0, right = matrix[0].size()-1, top = 0 ,bottom = matrix.size()-1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                p_matrix.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; i++) {
                p_matrix.push_back(matrix[i][right]);
            }
            if (top != bottom) {
                for (int i = right - 1; i >= left; i--) {
                    p_matrix.push_back(matrix[bottom][i]);
                }
            }
            if (left != right) {
                for (int i = bottom - 1; i >= top + 1; i--) {
                    p_matrix.push_back(matrix[i][left]);
                }
            }
            top++, left++, bottom--, right--;
        }
        return p_matrix;
    }
};