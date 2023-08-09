class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        l = 0 
        r = len(letters)-1
        ans= 0 
        while l <= r :
            m = (r - l ) //2 + 1 
            if letters[m] > target:
                ans = m 
                r = m - 1
            else :
                l = m + 1
        return letters[ans]
