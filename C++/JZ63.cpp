// Created by 邢思远 on 2021/2/22 12:05 下午.
// Copyright (c) xingsiyuan2019@ia.ac.cn
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

/*
题目描述:
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。

输入：
输出：

解题思路: 保证在小根堆和大根堆之间跳转的 数字 比小根堆所有值都大, 比大根堆所有值都小

*/

class Solution {
public:
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    void Insert(int num)
    {
        max_heap.push(num); // 放入大根堆
        min_heap.push(-max_heap.top()); // 小根堆插入大根堆的最大值
        max_heap.pop(); // 弹出大根堆最大值
        if (max_heap.size() < min_heap.size()) {  // 大根堆数目少于小根堆
            max_heap.push(-min_heap.top());
            min_heap.pop();
        }

    }

    double GetMedian()
    {
        if (max_heap.size() != min_heap.size()) {
            return max_heap.top();
        }
        else {
            return (max_heap.top() - min_heap.top()) / 2.0;
        }
    }

};


int main() {
    Solution sol;
    sol.Insert(10);
    sol.Insert(1);
    sol.Insert(6);
    sol.Insert(8);
    sol.Insert(5);
    double res = sol.GetMedian();

    cout << res << endl;

    priority_queue<int> max_heap_test = sol.max_heap;
    while(max_heap_test.size() !=0 )
    {
        cout << max_heap_test.top() << " ";
        max_heap_test.pop();
    }
    cout << endl;

    return 0;
}