#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	void backtrack(int k, int num , int even)
	{
		
	}
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int l = 0;
        int even = 0 ;
        bool ok[10];
        fill(ok,ok+10,false);
        vector<int> ans;
        
        for(int i: digits) 
        {
        	if(i&1) even ++;
        	ok[i] = true;
		}
    }
};

int main()
{
	return 0;
}
