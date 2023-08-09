'''Solution: firstly, sort the array then using to loop to find two first elemet, then use 2 pointer l, r to find 2 rest element , 
            if sum < 4 -> l ++ , else l -- 
    Complexity: O(n3)'''

class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        ans = set()
        nums.sort()
        for i in range(len(nums)-3):
            for j in range(i+1,len(nums)-2):
                l  = j + 1
                r = len(nums)-1
                while l < r : 
                    if nums[i] + nums[j] + nums[l] + nums[r] == target:
                        ans.add((nums[i],nums[j],nums[l],nums[r]))
                        l += 1
                        r -= 1
                    elif nums[i] + nums[j] + nums[l] + nums[r] < target:
                        l += 1
                    else :
                        r -=1 
        if len(ans) == 0:
            return []
        return [list(x) for x in ans ]

print(Solution().fourSum( [1,0,-1,0,-2,2],0))