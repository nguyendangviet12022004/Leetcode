#include<iostream>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        int l = s.size();
        bool a[l][l];
        for(int i = 0;i < l;i ++)
		{
			for(int j = 0;j < l ;j ++) 
			{
				a[i][j] = 0;
			}
		}
        for(int i = 0;i < l ;i ++) a[i][i] = 1;
		
		for(int i = l - 2; i >= 0 ;i --)
		{
			for(int j = i + 1; j < l ;j ++)
			{
				if(s[i] == s[j])
				{
					a[i][j] = (j - i == 1 || a[i+1][j-1]);
				}
				else
				{
					a[i][j] = 0;
				}
			}
		}
		
		int ans = 1;
		for(int i = 0; i < l-1;i ++)
		{
			for(int j = i + 1;j < l;j ++) 
			{
				if (a[i][j] && j - i + 1 > ans) ans = j - i + 1;
			}
		}
		return ans;
    }
    
};


int main()
{
	return 0;
}
