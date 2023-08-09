'''Solution: Check if s[id] >= g[i] ans ++; else id ++
Complexity: O(n)'''

class Solution:
    def findContentChildren(self, g: list[int], s: list[int]) -> int:
        g.sort()
        s.sort()
        ans = 0
        id = 0 
        for x in g :
            while id < len(s) :
                if x > s[id]:
                    id += 1
                else :
                    break 
            if id < len(s):
                ans += 1
                id += 1
        return ans 