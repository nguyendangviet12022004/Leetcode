#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
};

class Solution {
public:
	int sum = 0 ; 
	void BFS(TreeNode* root,int l, int h)
	{
		if(root -> val >= l && root -> val <= h) 
		{
			sum += root -> val;
			BFS(root -> left, l, h);
			BFS(root -> right, l, h);
		}
		else if(root -> val < l) BFS(root -> right,l,h);
		else BFS(root -> left, l, h);
	}
    int rangeSumBST(TreeNode* root, int low, int high) {
        BFS(root,low,high);
        return sum;
    }
};

int main()
{
	
}
