'''
Solution : using 2 var x,y to check and set to check (queue)
Example :
    string = a b c b a  c b b
    1) x = 0, y = 0 -> OK -> x = 0, y = 1
    2) x = 0, y = 1 -> OK -> x = 0, y = 2
    3) x = 0, y = 2 -> OK -> x = 0, y = 3
    4) x =0, y = 3 -> !OK -> x = 1, y = 4 
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        check = set()
        x = 0
        y = 0
        ans = 0
        while(y < len(s)):
            while(s[y] in check):
                check.remove(s[x])
                x += 1
            check.add(s[y])
            ans = max(ans,y-x + 1)
            y += 1
        return ans

a = Solution()
print(a.lengthOfLongestSubstring("tmmzuxt"))                
