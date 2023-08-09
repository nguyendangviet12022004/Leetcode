'''Solution : Like when we conver int() to bin(), but remember there is no character represent for number 0 so carefully
Complexity: O(log n )
'''

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        query = "ZABCDEFGHIJKLMNOPQRSTUVWXY"
        ans = str()
        while columnNumber != 0 :
            k = columnNumber % 26
            ans = query[k] + ans
            if k == 0:
                columnNumber -= 1
            columnNumber //= 26

        return ans 
    
print(str(bin(13)))