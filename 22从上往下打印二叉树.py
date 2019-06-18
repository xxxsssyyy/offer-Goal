# coding:utf-8
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#解题思路：二叉树层次遍历，实际上就是广度优先搜索BFS,遇到这种问题考虑使用辅助队列，辅助队列中
#存储需处理的元素及其优先顺序
class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        # write code here
        queue = []
        res =[]
        if root is None:
            return []
        queue.append(root)
        while queue:
            node = queue.pop(0)
            res.append(node.val)
            if node.left!=None:
                queue.append(node.left)
            if node.right!=None:
                queue.append(node.right)
        return res

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    Solution = Solution()
    print(Solution.PrintFromTopToBottom(root))