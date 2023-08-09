#include<iostream>
#include<vector>
#include<queue>
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
	Node(int val, vector<Node*> children)
	{
		this -> val = val ;
		this -> children = children;
	}
};



void BFS(Node* root)
{
	queue<Node*> travel ;
	if (!root) return ;
	travel.push(root);
	while(!travel.empty()) 
	{
		int len = travel.size();
		for(int i = 0 ;i < len;i ++)
		{
			Node* q = travel.front();
			cout<<q -> val<<" ";
			for(int j = 0;j < q-> children.size();j ++)
				travel.push(q->children[j]);
			travel.pop();
		}		
		cout<<endl;
	}
}

void preorder_traversal(Node* root)
{
	if(root)
	{
		cout<<root -> val<<" ";
		for(int i = 0; i < root->children.size();i ++)
			preorder_traversal(root->children[i]);
	}
}

void postorder_traversal(Node* root)
{
	if(root)
	{
		for(int i = 0 ;i < root-> children.size();i ++) postorder_traversal(root->children[i]);
		cout<<root -> val<<" ";
	}
}
int main()
{
	Node *root = new Node(1);
    (root->children).push_back(new Node(3));
    (root->children).push_back(new Node(2));
    (root->children).push_back(new Node(4));
    (root->children[0]->children).push_back(new Node(5));
    (root->children[0]->children).push_back(new Node(6));
    postorder_traversal(root);
	return 0;
}
