'''Soluton: Using while loop to check factor 
Complexity: o(logn)'''
class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0 :
            return False
        
        k = 2
        while n != 1 : 
            if k > 5 : 
                return False
            while n % k == 0 :
                n //= k 
            k += 1 
        return True
print(Solution().isUgly(905391974))

