class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        def partion(a:list[int],l:int,r:int):
            id = l 
            p = a[r]
            for i in range(l,r):
                if a[i] < p:
                    (a[i],a[id]) = (a[id],a[i])
                    id += 1
            (a[id],a[r]) = (a[r],a[id])
            return id 
        def sort(a:list[int], l:int,r : int):
            if l < r:
                p = partion(a,l,r)
                sort(a,l,p-1)
                sort(a,p+1,r)
        
        sort(nums,0,len(nums)-1)
      
      
        pre = 0 
        ans = list()
        for x in nums:
            while x > pre + 1 :
                ans.append(pre+1)
                pre += 1
            if x == pre + 1:
                pre += 1
        for i in range(pre + 1,len(nums)+1):
            ans.append(i)
        return ans
    

print(Solution().findDisappearedNumbers([4,3,2,7,8,2,3,1]))


        