#include<iostream>

using namespace std;

//Solution: convert ans to binary base 
class Solution {
public:
    int divide(int a, int b) {
        if(a == b) return 1;
        if(a < b || a == 0) return 0;
        bool positive = ((a > 0 && b > 0) || (a < 0 && b < 0));
        unsigned int ans = 0 ;
        unsigned c = abs(a);
        unsigned d = abs(b);
        while(c >= d)
        {
        	int q = 0 ;
        	while(c > (d << (q+1))) q ++;
        	ans += 1 << q;
        	c -= d << q;
		}
		if(ans == (1 <<31) and positive) return INT_MAX;
		return (positive ? ans : -ans); 
    }
};

int main()
{
	cout<<Solution().divide(10,2);
}
