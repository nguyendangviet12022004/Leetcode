'''
Solution: using recursion and mark(decrease complexity from 2^n to n^2)
'''


class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        arr = []
        for i in range(rowIndex+1):
            arr.append([])
            for j in range(i+1):
                arr[i].append(0)
        def Combination(n:int,k:int)->int:
            if(arr[n][k] != 0) :
                return arr[n][k]
            else:
                if k == 0 or k == n:
                    arr[n][k] = 1
                elif k == 1 :
                    arr[n][k] = n
                else:
                    arr[n][k] = Combination(n-1,k-1) + Combination(n-1,k)
                return arr[n][k]
        ans = []
        for i in range(rowIndex+1):
            ans.append(Combination(rowIndex,i))
        for i in range(len(arr)):
            for j in range(len(arr[i])):
                print(arr[i][j],end=" ")
            print()
        return ans
    

a = Solution()
print(a.getRow(3))
            
            

