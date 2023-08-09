'''
Solution: using two var x,y to check profit 
Example:
    arr =  7  1  5  3  6  4
    id =   0  1  2  3  4  5

    1 ) x = 0, y = 1 -> a[x] > a[y] -> x = y, y ++
    2 ) x = 1 ,y = 2 -> a[x] < a[y] -> ans = max(a[y]-a[x] , ans) -> y ++
    3 ) ....

Complexity:
    O(n)
'''


class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        x = 0
        y = 1
        ans = 0
        while(y < len(prices)):
            profit = prices[y] - prices[x]
            if(profit <= 0):
                x = y
                y += 1
            else :
                ans = max(ans,profit)
                y += 1
        return ans