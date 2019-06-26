# -*- coding:utf-8 -*-
"""
题目描述：地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
思路：array数组中保存节点是否访问过，dfs搜索到底，对于以访问过的节点进行回溯
"""
class Solution:
    def __init__(self):
        self.count = 0
    def movingCount(self, threshold, rows, cols):
        # write code here
        array = [[0 for i in range(cols)] for j in range(rows)]
        self.dfs(threshold,0,0,array)
        return self.count

    def dfs(self,threwshold,i,j,array):
        if i<0 or j<0 or i>len(array)-1 or j>len(array[0])-1:
            return
        num_i = list(map(int,list(str(i))))
        num_j = list(map(int,list(str(j))))
        if sum(num_i) + sum(num_j)>threwshold or array[i][j] != 0:
            return
        array[i][j] = 1
        self.count += 1
        self.dfs(threwshold,i-1,j,array)
        self.dfs(threwshold,i+1,j,array)
        self.dfs(threwshold, i, j-1, array)
        self.dfs(threwshold, i, j+1, array)

if __name__=="__main__":
    a = Solution()
    print(a.movingCount(1,2,2))