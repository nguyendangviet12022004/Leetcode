class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        check = dict()
        check.update({nums2[-1]:-1})
        for i in range(len(nums2)-1):
            for j in range(i+1,len(nums2)):
                if nums2[j] > nums2[i]:
                    check.update({nums2[i]:nums2[j]})
                    break
            if nums2[i] not in check.keys():
                check.update({nums2[i]:-1})


        return [check[x] for x in nums1]