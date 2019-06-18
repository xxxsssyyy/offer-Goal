# coding:utf-8
class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code
        if pushV==[]:
            return True
        #https://www.cnblogs.com/xueli/p/4952063.html
        # 直接赋值：python中对象的赋值是对象的引用，当把它赋值给另一个变量时，并没有拷贝这个对象
        # copy浅拷贝：没有拷贝子对象，所以原始数据改变，子对象会改变
        # 深拷贝：包含对象里面的自对象的拷贝，所以原始对象的改变不会造成深拷贝里任何子元素的改变
        a = pushV.copy()
        for i in range(len(popV)-1):
            if pushV.index(popV[i+1])>pushV.index(popV[i]):
                a.pop(a.index(popV[i+1]))
            else:
                break
        a.pop(a.index(popV[0]))
        print(popV[i+1:])
        a.reverse()
        if(a==popV[i+1:]):
            return True
        else:
            return False

class solution1:
    # 解题方法为建议辅助栈，模拟进出栈全过程
    def isvalidstack(self,pushV,popV):
        stack =[]
        while popV:
            if stack and stack[-1] == popV[0]:
                stack.pop()
                popV.pop(0)
            elif pushV:
                stack.append(pushV.pop(0))
            else:
                return False
        return True


if __name__ == '__main__':
    solution = solution1()
    print(solution.isvalidstack([1,2,3,4,5],[4,5,3,2,1]))
