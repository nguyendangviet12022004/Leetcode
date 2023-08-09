'''Solution 1 : Using sort function and id array to find the nearest element which has the same value and check if the distance <= k
Complexity : O(n)
'''
class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        id = [i for i in range(len(nums))]
        id.sort(key = lambda x : nums[x])

        for i in range(len(nums)-1):
            if nums[id[i]] == nums[id[i+1]] and abs(id[i+1]-id[i] )<= k:
                return True
            
        
        return False


'''Solution 2 : Using hash map (dictionary) to store location of each element and use it to check 
Complexity: O(n)
'''

class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        check = dict()

        for i in range (len(nums)):
            if nums[i] not in check.keys():
                check.update({nums[i]:i})
            else :
                if i - check.get(nums[i]) <= k :
                    return True
                else :
                    check[nums[i]] = i
        return False