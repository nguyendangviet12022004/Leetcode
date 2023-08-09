#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

typedef unordered_map<int,int>::iterator map_it;

unordered_map<int,int> m; 

int pivot(vector<int>& nums,int l,int r)
{
	int p = m[nums[r]];
	int id = l;
	for(int i = l;i < r;i++)
		if(m[nums[i]] > p) swap(nums[i],nums[id++]);
	swap(nums[id],nums[r]);
	return id;
}

void sort(vector<int>& nums,int l, int r,int k)
{
	if(l < r && l <= k)
	{
		int p = pivot(nums,l,r);
		sort(nums,l,p-1,k);
		sort(nums,p+1,r,k);
	}
}

vector<int> topKFrequent(vector<int>& nums, int k){

	for(int i = 0 ;i < nums.size();i ++){

		if(m.find(nums[i]) != m.end()) m[nums[i]] ++;
		else m.insert({nums[i],1});
	}
	
	set<int> s(nums.begin(),nums.end());
	nums.clear();
	nums.assign(s.begin(),s.end());
	sort(nums,0,nums.size()-1,k);
	
	
	int l = nums.size();
	for(int i = 1; i<= l-k;i ++) nums.pop_back();
	return nums;
;
}

int main()
{
	vector<int> nums = {1};
	vector<int> ans = topKFrequent(nums,1);
	for(int i = 0 ;i < ans.size();i ++) cout<<ans[i]<<' ';
	return 0;
}
