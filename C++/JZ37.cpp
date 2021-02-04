// Created by xingsiyuan on 2021/2/2 14:26.
// Copyright (c) xingsiyuan2019@ia.ac.cn

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<ctime>

using namespace std;

/*
题目描述:
统计一个数字在升序数组中出现的次数。

输入：[1,2,3,3,3,3,4,5],3
输出： 4

解题思路: 二分法, 时间复杂度为O(logn)

*/

class Solution {
public:
    int GetNumberOfK2(vector<int> data ,int k) {

        int first_k, last_k;
        int left = 0, right = data.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (data[mid] >= k) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        first_k = left;

        left = 0, right = data.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (data[mid] <= k) {
                left = mid;
            }
            else {
                right = mid-1;
            }
        }
        last_k = left;

        std::cout << first_k << " " << last_k << std::endl;
        return last_k - first_k + 1;
    }

    int GetNumberOfK(vector<int> data ,int k) {
        int first = find_first_k(data, k, 0, data.size()-1);

        int last = find_last_k(data, k, 0, data.size()-1);

        return (first == -1 ? 0 : last-first+1);
    }
    int find_first_k(vector<int> data, int k, int start, int end) {
        if (start == end) {
            if (data[start] == k) {
                return start;
            }
            else {
                return -1;
            }
        }
        int n;
        int mid = (start + end) / 2;
        if (data[mid] >= k) {
            n = find_first_k(data, k, start, mid);
        }
        else {
            n = find_first_k(data, k, mid+1, end);
        }
        return n;
    }
    int find_last_k(vector<int> data, int k, int start, int end) {
        if (start == end) {
            if (data[start] == k) {
                return start;
            }
            else {
                return -1;
            }
        }
        int n;
        int mid = (start + end) / 2;
        if (data[mid] <= k) {
            n = find_last_k(data, k, mid, end);
        }
        else if (data[mid] > k) {
            n = find_last_k(data, k, start, mid-1);
        }
        return n;
    }

};

int main() {
    Solution sol;
    vector<int> data = {1,2,3,3,3,3,6,7};
    int k = 3;
    int n = sol.GetNumberOfK2(data, k);
    std::cout << n << std::endl;
    return 0;
}