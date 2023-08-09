#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
	int findShortestSubArray(vector<int>& nums)
	{
		unordered_map<int,vector<int>> m; 				
		for(int i = 0 ;i < nums.size();i ++)
		{
			if(m.find(nums[i]) == m.end())
				m.insert({nums[i],{i,i,1}});
			else
			{
				m[nums[i]] [1] = i;
				m[nums[i]] [2] ++;
			}
		}
		int count = 1;
		int ans = nums.size();
		for(unordered_map<int,vector<int>>::iterator it = m.begin(); it != m.end(); it ++)
		{
			vector<int> arr = it -> second;
			if(arr[2] > count)
			{
				ans = arr[1] - arr[0] + 1;
				count = arr[2];
			}
			else if(arr[2] == count)
			{
				ans = min(ans,arr[1] - arr[0] + 1);
			}
		}
		return ans;
	}
};

int main()
{
	return 0;
}
