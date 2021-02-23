// Created by 邢思远 on 2021/2/22 7:49 下午.
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
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如
 ABCE
 SFCS
 ADEE
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入该格子。

输入： "ABCESFCSADEE",3,4,"ABCCED"
输出： true

解题思路:

*/

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (strlen(str) == 0) {
            return true;
        }
        bool res = false;
        vector<vector<char> > mat;
        for (int i = 0; i < rows; i++) {
            vector<char> temp;
            for (int j = 0; j < cols; j++) {
                temp.push_back(matrix[cols*i+j]); // 这里注意 *cols
            }
            mat.push_back(temp);
        }


        vector<vector<bool> > is_visited(rows, vector<bool> (cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(mat, i, j, is_visited, 0, str)) {
                    return true;
                }
            }
        }
        return res;
    }
    bool dfs(vector<vector<char> > mat, int i, int j, vector<vector<bool> > is_visited, int index, char* str) {
        int rows = mat.size(), cols = mat[0].size();
        if (index == strlen(str)) {
            return true;
        }
        if (i < 0 || j < 0 || i > rows-1 || j > cols-1 || str[index] != mat[i][j] || is_visited[i][j]) {
            return false;
        }
        is_visited[i][j] = true;
        if (dfs(mat, i-1, j, is_visited, index+1, str)) {
            return true;
        }
        if (dfs(mat, i+1, j, is_visited, index+1, str)) {
            return true;
        }
        if (dfs(mat, i, j-1, is_visited, index+1, str)) {
            return true;
        }
        if (dfs(mat, i, j+1, is_visited, index+1, str)) {
            return true;
        }
        is_visited[i][j] = false;
        return false;
    }
};

int main() {
    Solution sol;
    string a = "ABCESFCSADEE";
    int rows = 3;
    int cols = 4;
    string s = "ABCCED";
    char* matrix = new char[a.length()];
    strcpy(matrix, a.c_str());
    char* str = new char[s.length()];
    strcpy(str, s.c_str());
    cout << sol.hasPath(matrix, rows, cols, str) << endl;
    return 0;
}