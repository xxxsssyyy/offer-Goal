# -*- coding:utf-8 -*-
"""
题目描述:请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
例如
a b c e
s f c s
a d e e
这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入该格子。

解题思路：带记忆的DFS：回溯与递归
"""
# 输入示例："ABCESFCSADEE",3,4,"ABCB"
class Solution:
    def hasPath(self, matrix, rows, cols, path):
        # write code here
        def dfs(array,did, i, j, path):
            if not path:
                return True
            if i<0 or j<0 or i>rows-1 or j>cols-1 or did[i][j] or array[i][j]!=path[0]:
                return
            else:
                did[i][j]=1
                if dfs(array,did,i-1,j,path[1:]):
                    return True
                if dfs(array, did, i+1, j, path[1:]):
                    return True
                if dfs(array, did, i, j-1, path[1:]):
                    return True
                if dfs(array, did, i, j+1, path[1:]):
                    return True
                did[i][j]= 0
            return False
        if not path:
            return True
        matrix_list = [list(matrix[i*cols:i*cols+cols]) for i in range(rows)]
        # 注意did定义必须在这，否则不通过，原因是？。。。
        # 原来写的是
        """
        for i in range(rows):
            for j in range(cols):
                did = [[0 for i in range(cols)] for j in range(rows)]
                执行上面一句后i、j值被改变了
                if dfs(matrix_list,did,i,j,path):
                        res = True
        """
        did = [[0 for m in range(cols)] for n in range(rows)]
        res = False
        for i in range(rows):
            for j in range(cols):
                if dfs(matrix_list,did,i,j,path):
                        res = True

        return res


    # 牛客通过的版本
    def hasPath(self, matrix, rows, cols, path):
        # write code here
        def findWord(matrix, visited, m, n, path, index):
            if index == len(path):
                return True
            if m < 0 or n < 0 or m >= len(matrix) or n >= len(matrix[0]) or visited[m][n] or path[index] != matrix[m][
                n]:
                return False

            visited[m][n] = True
            if findWord(matrix, visited, m - 1, n, path, index + 1):
                return True
            if findWord(matrix, visited, m + 1, n, path, index + 1):
                return True
            if findWord(matrix, visited, m, n - 1, path, index + 1):
                return True
            if findWord(matrix, visited, m, n + 1, path, index + 1):
                return True
            visited[m][n] = 0

            return False

        if rows * cols == 0 and not path:
            return False
        if not path:
            return True
        visited = [[0 for i in range(cols)] for j in range(rows)]
        matrix1 = [list(matrix[i * cols:i * cols + cols]) for i in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if findWord(matrix1, visited, i, j, path, 0):
                    return True
        return False



if __name__=="__main__":
    a = Solution()
    print(a.hasPath("ABCESFCSADEE",3,4,"ABCB"))
    print(a.hasPath("ABCESFCSADEE", 3, 4, "ABCCED"))
    print(a.hasPath("ABCESFCSADEE", 3, 4, "ABCCEES"))
    print(a.hasPath("abcesfcfadee", 3, 4, "ccfd"))
    """
    abce
    sfcf
    adee
    """
