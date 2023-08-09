#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> check;
        for(int i = 0 ;i < nums.size();i++) 
            if(check.find(nums[i]) != check.end()) check[nums[i]] ++;
            else check.insert({nums[i],1});
        int ans = 0 ;
        for(unordered_map<int,int>::iterator it = check.begin();  it != check.end(); it ++)
            if(check.find(it->first + 1) != check.end()) ans = max(ans,it -> second + check[it->first+1]);
        return ans;
    }
};

int main()
{
	return 0;
}
