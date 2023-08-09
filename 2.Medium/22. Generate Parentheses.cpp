#include<iostream>
#include<vector>
// Solution: Using backtrack technical to solve 
using namespace std;
class Solution
{
	public:
	int open = 2;
	int close = 2;
	backtrack(string s, int k, int n)
	{
		if(open >= 1) 
		{
			open --;
			s += '(';
			if(k == n) cout<<s + ")"<<" ";
			else backtrack(s,k+1,n);
			s.pop_back();
			open ++;
		}
		if(close >= open)
		{
			close --;
			s += ')';
			if(k == n) cout<<s + ")"<<" ";
			else backtrack(s,k+1,n);
			s.pop_back();
			close ++;
		}
	}	
};


void backtrack(int open,int close,int n, string s)
{
	if(open + close == 2 * n) cout<<s<<" ";
	if(open < n) backtrack(open+1,close,n,s + '(');
	if(close < open) backtrack(open,close +1, n, s +')');
}

int main()
{
	backtrack(0,0,3,"");
}
