'''Solution : Using a array to store element then check if it == arr[i]-1 , by and large , it's very easy 
Complexity: O(n)'''
class Solution:
    def summaryRanges(self, nums: list[int]) -> list[str]:
        ans = []
        arr = []
        for i in range(len(nums)):
            if len(arr) == 0 or arr[-1] == nums[i] - 1 :
                arr.append(nums[i])
            else :
                if len(arr) == 1 :
                    ans.append(str(arr[0]))
                else:
                    ans.append(str(arr[0]) + "->"+ str(arr[-1]))
                arr.clear()
                arr.append(nums[i])
        if len(arr) == 1 :
            ans.append(str(arr[0]))
        elif len(arr) != 0:
            ans.append(str(arr[0]) + "->"+ str(arr[-1]))
      
        
        return ans

            