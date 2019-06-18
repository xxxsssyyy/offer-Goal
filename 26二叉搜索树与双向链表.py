# coding:utf-8
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
验证是否为二叉搜索树
"""
class Solution1:
    def Convert(self, pRootOfTree):
        # write code here
        self.res = []
        if pRootOfTree is None:
            return True
        def dfs(root):
            if root.left:
                dfs(root.left)
            self.res.append(root.val)
            if root.right:
                dfs(root.right)
        dfs(pRootOfTree)

        for i in range(len(self.res)-1):
            if self.res[i]>self.res[i+1]:
                return False
        return True
"""
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
"""
class Solution:
    def Convert(self, pRootOfTree):
        # write code here
        self.res = []
        if pRootOfTree is None:
            return pRootOfTree
        def dfs(root):
            if root.left:
                dfs(root.left)
            self.res.append(root)
            if root.right:
                dfs(root.right)
        dfs(pRootOfTree)
        for i, v in enumerate(self.res[:-1]):
            v.right = self.res[i+1]
            self.res[i+1].left = v
        return self.res[0]

if __name__ == '__main__':
    Solution = Solution()
    root = TreeNode(1)
    root.right = TreeNode(2)
    print(Solution.Convert(root))