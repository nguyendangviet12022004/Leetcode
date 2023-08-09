#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val,ListNode*next)
	{
		this -> val = val;
		this -> next = next;
	}
};

void swapNode(vector<ListNode*>arr)
{
	int l = arr.size();
	for(int i = 0 ;i < l / 2; i++)
	{
		int k = arr[i] -> val;
		arr[i] -> val = arr[l - 1 - i] -> val;
		arr[l-i - 1] -> val = k;
	}
	for(int i =0;i < arr.size();i ++) cout<<arr[i] -> val;

}

ListNode*reverseKGroup(ListNode* head, 	int k){
	ListNode *ans = head ;
	if(k == 1) return ans;
	vector<ListNode*> arr;
	while(head)
	{
		for(int i = 1;i <= k;i ++) 
		{
			if(head) {
				arr.push_back(head);
				head = head -> next;
			}
			else break;
		}
		if(arr.size() == k)
		{
			swapNode(arr);
			arr.clear();
		}
	}
	return ans;
}
int main()
{
	ListNode* root = new ListNode(1,nullptr);
	root -> next = new ListNode(2,nullptr);
	root -> next -> next = new ListNode(3,nullptr);
	root -> next -> next -> next = new ListNode(4,nullptr);
	cout<<root -> val<<endl;
	reverseKGroup(root,4);
}
