#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> & matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0 ; i < n-1 ;i ++)
        {
            int k = matrix[0][i];
            int y = i + 1;
            int x = 1;
            while (x < m && y < n)
            {
                if ( matrix[x][y] != k ) return false;
                x ++;
                y ++;
            } 
        }

        for(int i = 1;i < m -1;i ++)
        {
            int k = matrix[i][0];
            int y = 1;
            int x = i + 1;
            while(x < m && y < n)
            {
                if ( matrix[x][y] != k ) return false;
                x ++;
                y ++;
            }
        }
        return true;
    }
};

int main()
{
    Solution a();
    vector<int> arr;
    return 0;
}
