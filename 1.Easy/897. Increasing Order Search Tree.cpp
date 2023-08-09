#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val): val(val) ,left(nullptr) , right(nullptr){
	}
	TreeNode(int val, TreeNode* left, TreeNode* right): val(val),left(left),right(right){
	}
};


class Solution {
	TreeNode* ans = new TreeNode(0);
	TreeNode* head = ans;
public:
	void in_order(TreeNode* root)
	{
		if(root)
		{
			in_order(root -> left);
			head -> right = new TreeNode(root -> val) ;
			head -> left = nullptr;
			head = head -> right;
			cout<<head -> val<<" ";
			in_order(root -> right);
		}
	}
    TreeNode* increasingBST(TreeNode* root) {
        in_order(root);
        return ans -> right;
    }
};


int main()
{
	
	TreeNode*root = new TreeNode(5);
	root -> left = new TreeNode(3);
	root -> right = new TreeNode(6);
	root -> left -> left = new TreeNode(2);
	root -> left -> right = new TreeNode(4);
	root -> left -> left -> left = new TreeNode(1);
	root -> right -> right = new TreeNode(8);
	root -> right -> right -> left = new TreeNode(7);
	root -> right -> right -> right = new TreeNode(9);
	Solution().increasingBST(root);

}
