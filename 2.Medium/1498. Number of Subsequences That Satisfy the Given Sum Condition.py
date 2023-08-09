'''
Solution: Using array "pre" to store result or pow(2,x,mod). From index i -> j there are pow(2,j-i+1) subsequences
For exmaple : 1 2 3 4 5 , target = 6
            --> "1" ceratinly come 
            --> 2,3,4,5 can come or not --> pow(2,4)
Complexity : O(n)
'''
class Solution:
    def numSubseq(self, nums: list[int], target: int) -> int:
        pre = [1]
        mod = int(10e9 + 7)
        for i in range(1,len(nums)):
            pre.append((pre[i-1] << 1 ) % mod)

        nums.sort()
        res = 0

        l = 0
        r = len(nums)-1
        while(l <= r):
            if(nums[l] + nums[r] > target):
                r -= 1
            else :
                res = (res + pre[r-l]) % mod
                l += 1
        return res

a = Solution()
print(a.numSubseq([3,5,6,7], 9))

