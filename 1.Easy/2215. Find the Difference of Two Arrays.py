'''Solution: Using difference_update()'''


class Solution:
    def findDifference(self, nums1: list[int], nums2: list[int]) -> list[list[int]]:
        ans = []
        set1 = set(nums1)
        set2 = set(nums2)
        set1.difference_update(nums2)
        set2.difference_update(nums1)
        ans.append(list(set1))
        ans.append(list(set2))
        return ans


arr = [1,2,3,4]
arr2 = [3,4,5,6]

test = Solution()
print(test.findDifference(arr,arr2))