#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
    	if(s.size() != goal.size()) return false;
    	
    	vector<int> count1(26,0);
		vector<int> count2(26,0);
    	if(s == goal)
    	{
    		for(int i = 0 ;i < s.size();i ++)
    			if(count1[s[i]- 'a'] == 1) return false;
    			else count1[s[i] - 'a'] = 1;
    		return true;
		}

		else 
		{
			for(int i = 0;i < s.size();i ++)
			{
				count1[s[i] - 'a'] ++;
				count2[goal[i] - 'a'] ++;
			}
			for(int i = 0;i < 26;i ++)
			{
				if(count1[i] != count2[i])return false;
			}
			return true;
		}
	}
        
};

int main()
{

}
