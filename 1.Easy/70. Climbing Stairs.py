'''
    Solution:
    - Using recusion :
    - at step n :
        +) if choose 1 step , we have Solution(n-1) ways
        +) if choose 2 steps, we have Solution(n-2) ways 
        --> Totally, we have Solution(n-1) + Solution(n-2) --> Fibonaci 
'''

class Solution:

    def __init__(self,n) -> None:
        self.n = n
    def climbStairs(self, n: int) -> int:
        if(n == 1):
            return 1
        if(n == 2):
            return 2
        a = 1
        b = 1 
        ans = 2
        for i in range(3,n+1):
            ans = a + b
            a = b
            b = ans
        return ans
    

a = Solution(45)
print(a.climbStairs(a.n))