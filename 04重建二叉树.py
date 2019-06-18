# -*- coding:utf-8 -*-
"""
思考方法：根据前序确定根节点，再根据中序划分左右子树
        递归实现：对于每个子树，创建根节点，再根据上述条件规划其左右子树
        边界条件：若子树为空，返回None；若子树为长度1，返回Treenode(x)
"""
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        # 边界条件
        if len(pre) == 0:
            return None
        elif len(pre) == 1:
            return TreeNode(pre[0])
        else:
            node_val = pre[0]
            root = TreeNode(pre[0])
            root.left = self.reConstructBinaryTree(pre[1:tin.index(node_val)+1],tin[:tin.index(node_val)])
            root.right = self.reConstructBinaryTree(pre[tin.index(node_val)+1:],tin[tin.index(node_val)+1:])
        return root