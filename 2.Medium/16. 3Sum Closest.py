'''Solution : for i in range(len(nums)-1): using to variable x , y to cacl sum of 3 nums: if sum > target : y -- else x ++
Complexity: O(n2) '''
class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        ans = nums[0] + nums[1] + nums[2] 
        for i in range(len(nums)-2):
            x = i + 1
            y = len(nums) - 1
            while(x < y):
                print(i,x,y,end=" ")
                print(nums[i],nums[x],nums[y])
                if nums[i] + nums[x] + nums[y] == target:
                    return target
                elif nums[i] + nums[x] + nums[y] > target:
                    if nums[i] + nums[x] + nums[y] - target < abs(ans - target):
                        ans = nums[i] + nums[x] + nums[y]
                    y -= 1
                else :
                    if target - (nums[i] + nums[x] + nums[y] ) < abs(ans - target):
                        ans = nums[i] + nums[x] + nums[y]
                    x += 1
        return ans 
print(Solution().threeSumClosest([1,1,1,0],100))