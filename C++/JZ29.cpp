// Created by xingsiyuan on 2021/1/29 15:25.
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
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

输入：[4,5,1,6,2,7,3,8],4
输出： [1,2,3,4]

解题思路:
堆的性质
1.堆是一种完全二叉树
2.堆有两种类型: 大根堆 小根堆
    两种类型的概念如下：
    大根堆：每个结点的值都大于或等于左右孩子结点
    小根堆：每个结点的值都小于或等于左右孩子结点

堆排序有两个过程： 1.建堆 2.交换堆顶和堆底,再去掉堆底,对剩余进行排序
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k || k <= 0) {
            return {};
        }
        // 建立大根堆
        heapify(input, k);

        for (int i = 0; i < k; i++) {
            std::cout << input[i] << " ";
        }
        std::cout << std::endl;

        for (int i = k; i < input.size(); i++) {
            if (input[i] < input[0]) {
                swap(input[0], input[i]);
                h_sort(input, 0, k-1);
            }
        }

        vector<int> res;
        res.assign(input.begin(), input.begin()+k);
        return res;
    }
    void heapify(vector<int> &input, int k) {
        int n = k / 2 - 1;
        while (n >= 0) {
            h_sort(input, n, k-1);
            n--;
        }
    }
    void h_sort(vector<int> &input, int start, int end) {
        if (start * 2 >= end) {
            return;
        }
        else if (start * 2 + 1 == end) {
            if (input[start] < input[end]) {
                swap(input[start], input[end]);
            }
        }
        else {
            int left = input[2*start+1];
            int right = input[2*start+2];
            if (left >= right && left > input[start]) {
                swap(input[start], input[2*start+1]);
                h_sort(input, 2*start+1, end);
            }
            if (left < right && right > input[start]) {
                swap(input[start], input[2*start+2]);
                h_sort(input, 2*start+2, end);
            }
        }
    }
};

// 第k大
class Solution2 {
public:
    int GetLeastNumbers_Solution(vector<int>& input, int k) {
        if (input.empty() || input.size() < k || k <= 0) {
            return -1;
        }
        return search(input, 0, input.size()-1, k);
    }
    int search(vector<int>& input, int left, int right, int k) {
        int index = partition(input, left, right);
        int N = input.size();
        if (index == N-k) {
            return input[index];
        }
        else if (index > N-k) {
            return search(input, left, index-1, k);
        }
        else {
            return search(input, index+1, right, k);
        }
    }
    int partition(vector<int>& input, int left, int right) {
        int i = left;
        int j = left;
        int base = input[i];
        while (i < j) {
            while (i < j && input[j] >= base)
                j--;
            input[i] = input[j];
            while (i < j && input[i] <= base)
                i++;
            input[j] = input[i];
        }
        input[i] = base;
        return i;
    }
}


int main() {
    Solution sol;
    vector<int> array = {4,5,1,6,2,7,3,8};
    int k = 4;
    vector<int> res = sol.GetLeastNumbers_Solution(array, k);
    for (auto s: res) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}
