/** Solution: Using 2 pointer 
Complexity: O(n + m ) **/

#inlucde<iostream>
#include<vector>

using namespace std;

class Solution {
	public :
		int countNegatives(vector<vector<int>>& grid)
		{
			int m = grid.size();
			int n = grid[0].size();
			
			int x = m -1; 
			int y = 0;
			int ans = 0 ;
			while (x >= 0 && y < n)
			{
				if (grid[x][y] < 0)
				{
					ans += n - y ;
					x --;
				}
				else 
				{
					y ++;
				}
			}
			return ans ;
		}
};

int main()
{
	
}
