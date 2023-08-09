#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// Declaration of tree
struct node{
	int val;
	node *left;
	node *right;
	node() : val(0) , left(nullptr), right(nullptr){
	}
	node(int val) : val(val) , left(nullptr), right(nullptr){
	}
	node(int val, node*left, node*right) : val(val), left(left) , right(right){
	}
};

// Function to insert a value to tree node
node *insert(node* root,int val)
{
	if (!root)
	{
		node *temp = new node(val);
		return temp;
	}
	else
	{
		if (val > root -> val)
		{
			root->right = insert(root->right, val);
		}
		else
		{
			root -> left = insert(root->left, val);
		}
		return root;
	}
}

// List of traveral technical
void inorderTraveral(node*root)
{
	if (root)
	{
		inorderTraveral(root->left);
		cout<<root -> val<<" ";
		inorderTraveral(root-> right);
	}
}

void preorderTraveral(node*root)
{
	if(root)
	{
		cout<<root -> val <<" ";
		preorderTraveral(root -> left);
		preorderTraveral(root -> right);
	}
}

void postorderTraveral(node*root)
{
	if(root)
	{
		postorderTraveral(root -> left);
		postorderTraveral(root -> right);
		cout<< root -> val <<" ";
	}
}

void BFS(node * root)
{
	queue<node*> que;
	que.push(root);
	while (que.size() != 0)
	{
		node *k = que.front();
		cout << k -> val <<endl;
		if(k->left) que.push(k->left);
		if(k->right) que.push(k->right);
		que.pop();
	}
}

int level(root)
{
	if (!root) return 0;
	else return 1 + max(level(root->left),level(root->right));
}

bool checkBalance(node *root)
{
	if (!root) return true;
	if (abs(level(root->left)- level(root->right)) > 1) return false;
	return checkBalance(root->left) && checkBalance(root->right);
}


int main()
{
	int arr[] = {1,-1,2,4,5};
	node *root = new node(2);
	for(int i = 0;i < 5;i ++)
	{
		root = insert(root,arr[i]);
	}
	BFS(root);
	return 0;
}
