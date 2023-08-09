'''Solution: use fomular: people = int(squrt(candiest) * squrt(2)) -1 
    Complexity: O(n): 
'''
from math import sqrt
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> list[int]:
        people = int(sqrt(2) * sqrt(candies))
        while people*(people+1)//2 > candies:
            people -= 1
        rest = candies - ((people)*(people+1)//2)            

        ans = []
        for i in range(num_people):
            ans.append(0)
        
        id = 0
        candi = 1
        for i in range(people):
            ans[id] += candi
            candi += 1
            id += 1
            if(id == num_people):
                id -= num_people
        ans[id] += rest

        return ans
print(Solution().distributeCandies(100,4))
