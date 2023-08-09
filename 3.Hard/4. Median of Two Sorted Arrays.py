'''Solution: Similar to mergeing two sorted arr and find the number of index (l1 + l2)//2 to find the median
Complexity : O(n)'''
class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        l1 = len(nums1)
        l2 = len(nums2)
        idmax = (l1+l2) // 2
        
        id = 0
        id1 = 0
        id2 = 0  
        pre = now = min(nums1[0],nums2[0])

        for i in range(min(l1,l2)):
            if nums1[id1] < nums2[id2]:
                pre = now
                now = nums1[id1]
                id1 += 1
            else :
                pre = now 
                now = nums2[id2]
                id2 += 1
            id += 1
        while id1 < l1 and id <= idmax:
            pre = now 
            now = nums1[id1]
            id1 += 1
            id += 1
        while id2 < l2 and id <= idmax:
            pre = now 
            now = nums2[id2]
            id2 += 1
            id += 1
        
        if idmax & 1 :
            return float (now)
        return (now + pre)/2

                    

print(Solution().findMedianSortedArrays([1,3], [2]))