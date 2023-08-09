#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(nullptr), right(nullptr){
	}
	TreeNode(int val):val(val),left(nullptr),right(nullptr){
	}
	TreeNode(int val, TreeNode*left, TreeNode*right): val(val), left(left), right(right){
	}
};

class Solution {
public:
    int min_dif = INT_MAX;
    int val = -1;
int getMinimumDifference(TreeNode* root) {
    if (root->left != NULL)
        getMinimumDifference(root->left);
    if (val >= 0)
        min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL)
        getMinimumDifference(root->right);
    return min_dif;
    }
};
int main(){

}
