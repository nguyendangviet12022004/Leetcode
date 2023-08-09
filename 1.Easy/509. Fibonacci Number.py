'''Using formula fn = fn-1 + fn-2 
Complexity: O(1)'''
class Solution:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            return n
        
        a = 0
        b = 1

        for i in range(2,n+1):
            temp = b
            b += a 
            a  = b 
        
        return b
