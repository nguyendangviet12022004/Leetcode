#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();

        vector<int> calc (n1+n2,0);
        for(int i = n1 - 1; i >= 0 ; i --)
        {
            for(int j = n2 - 1;j >= 0 ;j --)
            {
                calc[i+j+1] += (num1[i]-'0') * (num2[j] - '0');
                calc[i+j] += calc[i+j+1] / 10;
                calc[i+j+1] %= 10;
            }
        }
        string ans = "";
        int i = 0;
        while(!calc[i]) i ++;
        while(i < n1 + n2) ans += to_string(calc[i++]);
        return ans;
    }
};
int main()
{

}
