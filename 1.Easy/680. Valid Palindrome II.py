'''
Solution: Using 2 var x, y and check if(s[x] == s[y])
Example:
    s  = "a b c a"
    if(s[x] != s[y]) delete s[x] or s[y] then use s[:] == s::-1
    
'''
class Solution:
    def validPalindrome(self, s: str) -> bool:
        x = 0
        y = len(s)- 1
        while(x < y):
            if(s[x] != s[y]):
                s1 = s[:x] + s[x+1:]
                s2 = s[:y] + s[y+1:]
                return s1==s1[::-1] or s2 == s2[::-1]
            x -= 1
            y += 1
        return True
