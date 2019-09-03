# -*- coding:utf-8 -*-
"""
题目描述：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
解题思路：
        1.首先介绍Python中关于int类型的定义
		对于32位计算机，int类型位数为32；对于64位，int类型位数为64
		Python中对于负数同样以补码形式保存，但与c的区别是补码中最高位前面全部为1，
		所以以下代码中对于负数补码形式的处理n = n& 0xffffffff作用是将其限制在32位中，
		去掉高位的所有1
		2.对于本题中巧妙的位运算思路 n&(n-1)的作用是清理n的二进制形式中从右边数最后一个1
		以及其右边所有0，使迭代后的n刷新知道其为0，count用于记录其1的个数
"""
class Solution:
    def NumberOf1(self, n):
        count = 0
        if n < 0:
            n = n & 0xffffffff
        while (n != 0):
            count += 1
            n = n & (n - 1)
        return count