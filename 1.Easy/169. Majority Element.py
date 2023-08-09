'''Solution: Sort and use binary search to find the last element that equal to current element
    Complexity : O(n)
'''
from math import * 
class Solution1:
    def majorityElement(self, nums: list[int]) -> int:
        def partition(a, l, r):
            id = l
            pivot = a[r]
            for i in range(l,r):
                if(a[i] < pivot ):
                    (a[i], a[id]) = (a[id],a[i])
                    id += 1
            (a[id],a[r]) = (a[r],a[id])
            return id
        def quicksort(a, l, r):
            if(l < r):
                p = partition(a,l,r)
                quicksort(a,l,p-1)
                quicksort(a,p+1,r)

        def upper_bound(a,l,r,x):
            while(l < r):
                print(str(l),str(r))
                m = ceil((r - l)/2 + l)
                if(a[m] <= x) :
                    l = m 
                else :
                    r = m - 1
            return r 
        
        l = len(nums)
        quicksort(nums,0,l-1)
        lenght = 1
        ans = nums[0]
        id = 0
        while(id < l): 
            end = upper_bound(nums,id,l-1,nums[id])
            if(end-id + 1 > lenght):
                ans = nums[id]
                lenght = end-id+1
            id = end + 1    
        return ans

'''
Solution2: Using set and dictionary to count

'''
class Solution2:
    def majorityElement(self, nums: list[int]) -> int:
        ele = set(nums)
        mark = dict()
        for x in ele:   
            mark.update(x=nums.count())
        return max(mark,key=mark.get)

'''
Solution 3: Check from 1 -> end : if x == ele , count ++ else count -- 
Complexity: O(n)
''' 

class Soltion3:
    def majorityElement(self, nums: list[int]) -> int:
        ele = nums[0]
        ans = 0
        for i in range(1,len(nums)):
            if ans == 0 : 
                ele = nums[i]
            else :
                if ele == nums[i]:
                    ans += 1
                else :
                    ans -= 1
        return ans 