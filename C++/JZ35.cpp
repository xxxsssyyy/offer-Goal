// Created by xingsiyuan on 2021/2/1 19:32.
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
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

输入：[1,2,3,4,5,6,7,0]
输出： 7

解题思路: 归并排序, 时间复杂度为O(nlogn)

*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty()) {
            return 0;
        }
        vector<int> temp(data);
        return merge_sort(data, temp, 0, data.size()-1)%1000000007;
    }

    int merge_sort(vector<int> &data, vector<int> &temp, int start, int end) {
        if (end - start <= 0) {
            return 0;
        }
        int mid = (start + end) / 2;
        int left = merge_sort(data, temp, start, mid);
        int right = merge_sort(data, temp, mid+1, end);
        // Merge
        int i = start, j = mid + 1;
        int index = start, count = 0;
        while (i <= mid && j <= end) {
            if (data[i] <= data[j]) {
                temp[index] = data[i];
                i++;
                index++;
            }
            else {
                temp[index] = data[j];
                count = count + (mid - i + 1);
                j++;
                index++;
            }
        }

        while (i <= mid) {
            temp[index++] = data[i++];
        }
        while (j <= end) {
            temp[index++] = data[j++];
        }
        for (i = start; i <= end; i++) {
            data[i] = temp[i];
        }
        return left+count+right;
    }
};


int main() {
    Solution2 sol;
    vector<int> data = {1,2,3,4,5,6,7,0};
    int num = sol.InversePairs(data);
    std::cout << num << std::endl;
    return 0;
}