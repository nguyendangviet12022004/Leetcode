'''Solution: Firstly, we need to sort the arry, pick a element then use 2 pointer l, r two find 2 rest elemnt as long as sum of 3 equal to 0
Complexity: O(n)'''

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        if(len(nums) < 3):
            return []
        
        ans = []
        nums.sort()
        for i in range(len(nums)-2):
            if len(ans) != 0 : 
                if nums[i] == ans[-1][0]:
                    continue
            l = i + 1
            r = len(nums)-1
            while(l < r):
                if nums[l] + nums[r] + nums[i] == 0:
                    if(len(ans) != 0 and nums[l]==ans[-1][1] and nums[i] == ans[-1][0]):
                        pass
                    else:
                        ans.append([nums[i],nums[l],nums[r]]) 
                    l += 1
                    r -= 1
                elif nums[l] + nums[r] + nums[i] > 0:
                    r -= 1
                else :
                    l += 1
        return ans

print(Solution().threeSum([-1,0,1,2,-1,-4]))
        