# coding:utf-8
class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if not sequence:
            return False
        root = sequence[-1]
        for i in range(len(sequence)):
            if sequence[i]>root:
                break
        for j in range(i,len(sequence)):
            if sequence[j]<root:
                return False
        left = right = True
        if i > 0:
            left = self.VerifySquenceOfBST(sequence[:i])
        if i < len(sequence) - 1:
            right = self.VerifySquenceOfBST(sequence[i:-1])
        return left and right

if __name__ == '__main__':
    for i in range(5,6):
        print(1)