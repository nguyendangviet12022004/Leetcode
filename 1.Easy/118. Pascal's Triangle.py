'''
Solution: Using Pascal's Triangle formula
    - The number at row n(start from 0 ) and column k(start from 0) : C(n,k)
    - Sum of number in a row = 2^n 
'''

class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        ans = [[1]]
        if(numRows == 1):
            return ans
        for i in range(1,numRows):
            add = [1]
            for j in range(1,i):
                add.append(ans[i-1][j-1] + ans[i-1][j])
            add.append(1)
            ans.append(add)
        return ans
