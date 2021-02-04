// Created by xingsiyuan on 2021/1/25 19:00.
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
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下
递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
输入：7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
输出：true

解题思路:
抓住右上角的特点，比它小的数一定在左边，比它大的数一定在下边
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size(), n = array[0].size();
        int row = 0, col = n-1;
        while (row < m && col >= 0) {
            if (array[row][col] == target) {
                return true;
            }
            else if (array[row][col] > target) {
                col--;
            }
            else {
                row++;
            }
        }
        return false;
    }
};

int main(){
    Solution solution;
    int target = 7;
    vector<vector<int> > array = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
    bool res = solution.Find(target, array);

    std::cout << res << std::endl;
    return 0;
}
