'''Solution : Using 2 pointer technical : using 2 vairable name l, r to calc max water a tank can store 
Complexity:O(n)'''
class Solution:
    def maxArea(self, height: list[int]) -> int:    
        l = 0
        r = len(height)-1
        ans = 0
        while l < r :
            if min(height[r],height[l]) * (r - l) > ans :
                ans = min(height[r],height[l]) * (r - l)
            
            if height[l] < height[r]:
                l += 1
            else :
                r -= 1
        return ans 