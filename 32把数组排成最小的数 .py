# -*- coding:utf-8 -*-
"""
把数组排成最小的数
题目描述：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
"""
# map()是 Python 内置的高阶函数，它接收一个函数f和一个list，
# 并通过把函数f依次作用在list的每个元素上，得到一个新的 list 并返回。
# map()的返回值已经不再是list,而是iterators
# -*- coding:utf-8 -*-
# 快速排序，时间复杂度为O(nlogn)
class Solution:
    def PrintMinNumber(self,numbers):
        # write code here
        # 首先转成字符串形式
        numbers = list(map(lambda x: str(x), numbers))
        numbers = self.quick_sort(numbers)
        return ''.join(numbers)
    def quick_sort(self, numbers):
        if len(numbers)<2:
            return numbers
        # 快速排序在排序规则上与一般不同，此问题中，按照两个字符串和小的排序
        left = [x for x in numbers[1:] if x+numbers[0] <= numbers[0]+x]
        right = [x for x in numbers[1:] if x+numbers[0] > numbers[0]+x]
        return self.quick_sort(left) + [numbers[0]] + self.quick_sort(right)


