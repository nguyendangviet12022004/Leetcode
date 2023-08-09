#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class Node{
	public:
	int val;
	vector<Node*> children;
		
	Node(){
	}
	Node(int val)
	{
		this -> val = val;
	}
	Node(int val, vector<Node*>children)
	{
		this -> val = val;
		this -> children = children ;
	}
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {{}};
        vector<vector<int>> ans;
        
        queue<Node*>qu;
        qu.push(root);

        
        while(!qu.empty())
        {
        	vector<int> add;
        	int len = qu.size();
        	while(len >= 1)
        	{
        		Node*fr = qu.front();
        		add.push_back(fr->val);
        		for(int j = 0 ;j < fr ->children.size();j++)
        			qu.push(fr->children[j]);
        			
        		qu.pop();
        		len --;
			}
			ans.push_back(add);
		}
		return ans;
    }
};


int main()
{
	Node *root = new Node(1);
    (root->children).push_back(new Node(3));
    (root->children).push_back(new Node(2));
    (root->children).push_back(new Node(4));
    (root->children[0]->children).push_back(new Node(5));
    (root->children[0]->children).push_back(new Node(6));
    vector<vector<int>> arr = Solution().levelOrder(root);


    for(int i =0 ;i < arr.size();i ++)
    {
    	for(int j = 0 ;j < arr[i].size();j ++)
    		cout<<arr[i][j]<<" ";
    	cout<<endl;
	}
	return 0;
}
