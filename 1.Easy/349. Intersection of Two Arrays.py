'''Solution: Using intersection_update method in set method'''
class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        set1 = set(nums1)
        set1.intersection_update(nums2)
        return list(set1)
    
