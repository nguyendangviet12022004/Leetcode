'''Solution : Check all node to determine if it can be reach 
Complexity: O(n)'''

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: list[list[int]]) -> list[int]:
        arr = [False for i in range(n)]
        for x in edges :
            arr[x[1]] = True 
        ans = [i for i in range(n) if arr[i] == False]
        return ans