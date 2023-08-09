#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
	
    TreeNode *BST(vector<int>& nums,int start, int end)
    {
    	if (start > end) return nullptr;
    	else 
    	{
    		int mid = (end + start )/2;
    		TreeNode *ans = new TreeNode(nums[mid],BST(nums,start,mid-1),BST(nums,mid+1,end));
    		return ans;
    		
		}
	}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return BST(nums,0,nums.size()-1);
    }
};
int main()
{
	
}
