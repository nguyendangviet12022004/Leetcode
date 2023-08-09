#include<iostream>
#include<vector>
using namespace std;

/* Solution: Using formal : O(n) = (n & 1) ? O(n -1 ) + 1 : O(n/2) 
Complexity: O(n) */

class Solution {
public:
    vector<int> countBits(int n) {
    	vector<int> ans  = {0};
        for(int i = 1; i <= n;i ++)
        {
        	if(i & 1) ans.push_back(ans[i-1] + 1);
        	else ans.push_back(ans[i / 2]);
		}
		return ans;
    }
};
