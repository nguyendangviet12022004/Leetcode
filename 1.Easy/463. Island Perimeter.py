class Solution:
    def islandPerimeter(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        ans = 0 
        for x in range(m):
            for y in range(n):
                if grid[x][y]:
                    add = 4 
                    if y >= 1 and grid[x][y-1] == 1 : add -=1
                    if x >= 1 and grid[x-1][y] == 1: add -=1 
                    if x <= m -2 and grid[x+1][y] == 1 : add -=1 
                    if y <= n - 2 and grid[x][y+1] == 1 : add -=1 
                    ans += add 
        return ans 
