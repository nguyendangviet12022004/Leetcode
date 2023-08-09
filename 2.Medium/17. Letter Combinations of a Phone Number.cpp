#include<iostream>
#include<vector>
using namespace std;

class Solution {
vector<string> dict = {""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> ans;

void backtrack(int k,int n,string s,string digits)
{
	string num = dict[digits[k] - '0'];

	for(int i = 0;i < num.size();i ++)
	{
		s += num[i];
		if(k == n) 
		{
			ans.push_back(s);
		}
		else 
		{
			backtrack(k+1,n,s,digits);
		}
		s.pop_back();
	}
}
public:
    vector<string> letterCombinations(string digits) {
        int l = digits.size();
        if(l == 0) return {};
        backtrack(0,l-1,"",digits);
        return ans;
    }
};
int main()
{
	Solution().letterCombinations("");
	return 0;
}
