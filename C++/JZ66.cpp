// Created by 邢思远 on 2021/2/23 9:50 上午.
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
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

输入： 5,10,10
输出： 21

解题思路: dfs但不用回溯

*/

class Solution {
public:
    int count = 0;
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool> > is_visited(rows, vector<bool> (cols, false));
        dfs(0, 0, threshold, rows, cols, is_visited);
        return count;
    }
    void dfs(int i, int j, int threshold, int rows, int cols, vector<vector<bool> >& is_visited) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || is_visited[i][j] || compute(i, j) > threshold) {
            return;
        }
        is_visited[i][j] = true;
        count++;
        dfs(i-1, j, threshold, rows, cols, is_visited);
        dfs(i+1, j, threshold, rows, cols, is_visited);
        dfs(i, j-1, threshold, rows, cols, is_visited);
        dfs(i, j+1, threshold, rows, cols, is_visited);
    }
    int compute(int i, int j) {
        int res = 0;
        while (i) {
            res += (i % 10);
            i = i / 10;
        }
        while (j) {
            res += (j % 10);
            j = j / 10;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.movingCount(5, 10, 10) << endl;
    return 0;
}