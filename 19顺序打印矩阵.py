# -*- coding:utf-8 -*-
"""
题目描述：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
        如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
        则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
解题思路：先pop(0)出第一行，随后将矩阵逆时针旋转90度，类似魔方的做法
         优点：思路简单  缺点：矩阵比较大时，算法时间复杂度高
"""
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        new = []
        while matrix:
            new += matrix.pop(0)
            matrix = self.turn(matrix)
        return new

    def turn(self,matrix):
        if not matrix:
            return []
        m,n = len(matrix),len(matrix[0])
        t_matrix = []
        for j in range(n-1,-1,-1):
            temp = []
            for i in range(m):
                temp.append(matrix[i][j])
            t_matrix.append(temp)
        return t_matrix

    def printMatrix2(self, matrix):
    # 时间复杂度为O(n)
        left,right = 0,len(matrix[0])-1
        up,down = 0,len(matrix)-1
        res = []
        p1,p2 = 0,0
        while left<right or up<down:
            if p1==left and p2==up:
                while p1<=right:
                    res.append(matrix[p2][p1])
                    p1+=1
                p1-=1
                up+=1
                p2+=1
            if p1==right and p2==up:
                while p2<=down:
                    res.append(matrix[p2][p1])
                    p2+=1
                p2-=1
                right-=1
                p1-=1
            if p1==right and p2==down:
                while p1>=left:
                    res.append(matrix[p2][p1])
                    p1-=1
                p1+=1
                p2-=1
                down-=1
            if p1==left and p2==down:
                while p2>=up:
                    res.append(matrix[p2][p1])
                    p2-=1
                p2+=1
                p1+=1
                left+=1
        return res



if __name__=="__main__":
    Solution = Solution()
    #print(Solution.turn([[1,2,3],[4,5,6],[7,8,9]]))
    #print(Solution.printMatrix([[1,2,3],[4,5,6],[7,8,9]]))
    #print(Solution.printMatrix2([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]))
    print(Solution.printMatrix([[1, 2, 3,4], [ 5, 6,7,8], [9, 10, 11,12]]))
