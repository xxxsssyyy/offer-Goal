// Created by xingsiyuan on 2021/1/26 12:48.
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
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

输入： [3,4,5,1,2]
输出： 1

解题思路:

*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size()-1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (rotateArray[left] < rotateArray[right]) { // 升序序列直接退出
                break;
            }
            if (rotateArray[left] > rotateArray[mid]) {
                right = mid;
            }
            else if (rotateArray[left] < rotateArray[mid]) {
                left = mid + 1;
            }
            else { //两个元素时候, 肯定是递减情况，不然升序序列直接退出了
                ++left;
            }
        }
        return rotateArray[left];
    }
};