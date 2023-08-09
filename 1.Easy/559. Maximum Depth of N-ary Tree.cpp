#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
	public:
	int val;
	vector<Node*> children;
	Node(){
		this -> val = 0 ;
	}
	Node(int val){
		this -> val = val;
	}
	Node(int val, vector<Node*> children)
	{
		this -> val = val ;
		this -> children = children;
	}
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int ans = 0;
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
        	int len = que.size();
        	while(len >= 1)
        	{
        		Node*q = que.front();
        		for(int i = 0;i < q-> children.size();i ++ )
        			que.push(q->children[i]);
        		que.pop();
        		len --;
			}
			ans ++;
		}
		return ans;
    }
};
int main()
{
	return 0 ;
}
