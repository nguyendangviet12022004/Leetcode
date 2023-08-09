#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    int ans = 1;
    unordered_map<int,int> mp;
    for(int i = 0 ;i < arr.size();i++)
    {
        if(mp[arr[i] - difference]) mp[arr[i]] = mp[arr[i]-difference] + 1;
        else mp[arr[i]]  = 1;
        ans = max(ans,mp[arr[i]]);
    }
    return ans;

}
int main()
{
    vector<int> a = {1,5,7,8,5,3,4,2,1};
    cout << longestSubsequence(a,-2);
}
