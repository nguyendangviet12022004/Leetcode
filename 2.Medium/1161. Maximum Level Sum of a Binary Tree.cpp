#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val ;
	TreeNode *left ;
	TreeNode *right;
	TreeNode (int val , TreeNode* left, TreeNode* right){
	}
	
};


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int sum  = INT_MIN;
        int level = 1;
        int ans = 1;
        if (!root) return -1;
        vector<TreeNode*> qu;
        qu.push_back(root); 
        while(qu.size()!=0)
        {
            int s = 0 ;
            vector<TreeNode*> add;
            for(int i = 0;i < qu.size();i ++)
            {
                s += qu[i] -> val;
                if(qu[i] -> left) add.push_back(qu[i] -> left);
                if(qu[i] -> right) add.push_back(qu[i] -> right);
            }
            if(s > sum) {
                ans = level;
                sum = s;
            }
            level ++;
            qu.clear();
            qu.assign(add.begin(),add.end());
        }
        return ans;        
    }
};

int main()
{
	
}
