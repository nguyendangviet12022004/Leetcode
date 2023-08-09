'''Solution: add from right to left using way to plus to number normally, don't forget use remember variable
Complexity: O(n)'''

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        rem = 0
        l = max(len(num1),len(num2))
        ans = ""

        while(len(num1) < l):
            num1 = "0" + num1

        while(len(num2) < l):
            num2 = "0" + num2

        
        for i in range(l-1,-1,-1):
            k = int(num1[i]) + int(num2[i]) + rem 
            rem = k // 10
            k %= 10

            ans = str(k) + ans

        if rem == 1 :
            ans = "1" + ans

        return ans 
    
print(Solution().addStrings("456","77"))


