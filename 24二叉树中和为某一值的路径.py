# coding:utf-8
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
"""
class Solution1:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        self.res = []
        self.m = []
        # write code here
        if root is None:
            return []
        def aaa(temp_sum,root):
            temp_sum += root.val
            self.m.append(root.val)
            if temp_sum==expectNumber and root.left==None and root.right==None:#是末尾节点且和满足
                self.res.append(self.m[:])
                # 这个位置涉及Python可变与不可变对象的问题，因为一直将符合要求的路径self.m加入
                # 到self.result结果中，当对self.m进行变动时，由于其为可变对象，导致self.res中多个self.m同时
                # 变化，所以在append时要加入一个不可变对象
            if temp_sum<expectNumber:
                if root.left:
                    aaa(temp_sum,root.left)
                if root.right:
                    aaa(temp_sum,root.right)
            self.m.pop()

        aaa(0,root)
        self.res.sort(key = lambda x: len(x), reverse = True)
        return self.res
class Solution:
    def __init__(self):
        self.res = []
        self.m = []
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        if root is None:
            return self.res
        expectNumber -= root.val
        self.m.append(root.val)
        if root.left==None and root.right==None and expectNumber==0:
            self.res.append(self.m[:])
            # 这个位置涉及Python可变与不可变对象的问题，因为一直将符合要求的路径self.m加入
            # 到self.result结果中，当对self.m进行变动时，由于其为可变对象，导致self.res中多个self.m同时
            # 变化，所以在append时要加入一个不可变对象
        if expectNumber>0:
            if root.left:
                self.FindPath(root.left,expectNumber)
            if root.right:
                self.FindPath(root.right,expectNumber)
        self.m.pop()
        # 回溯法：没找到返回到上一层
        self.res.sort(key=lambda x: len(x), reverse=True)
        return self.res




if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(1)
    root.right = TreeNode(2)
    root.left.left = TreeNode(4)
    root.right.left = TreeNode(1)
    root.right.left.left = TreeNode(2)
    root.right.right = TreeNode(3)
    Solution = Solution()
    m = Solution.FindPath(root,6)
    print(m)
    """
    a=[]
    b=[]
    b.append(root.val)
    b.append(root.left.val)
    a.append(b)
    print(a)
    b.pop()
    a.append(b)
    print(a)
    """
    add = (1, 2, 3)
    aee = add
    print(id(aee), id(add))  # 这两个id一样
    aee += (4, 5, 6)
    print(id(aee))  # aee的id变了！
    print(add)  # add还是(1, 2, 3)没有变
    #所以tuple是不可变对象