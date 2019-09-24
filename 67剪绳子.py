# -*- coding:utf-8 -*-
"""
题目描述：给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为
         k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长
         度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
         输入一个数n，意义见题面。（2 <= n <= 60）

         输入：8 输出：18

解题思路：动态规划
        res[n] = max(i*(n-i),i*res[n-i],res[i]*res[n-i]), i from 1 to n-1
"""

class Solution:
    def cutRope(self, number):
        res = [0,1,1]
        for i in range(3,number+1):
            temp = 0
            for j in range(1,i):
                if max(res[j]*res[i-j], j*(i-j), j*res[i-j]) > temp:
                    temp = max(res[j]*res[i-j],j*(i-j), j*res[i-j])
            res.append(temp)
        print(res)
        return res[-1]

if __name__=="__main__":
    Solution = Solution()
    print(Solution.cutRope(8))
