class Solution:
    def search(self, nums: list[int], target: int) -> int:
        l = 0 
        r = len(nums) -1 
        while l < r :
            m = (r-l)//2 + l 
            if nums[m] < target : 
                l = m + 1
            else :
                r = m 
        return l if nums[l] == target else -1 