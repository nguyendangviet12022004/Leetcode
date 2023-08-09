#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){
	}
	ListNode(int val) : val(val),next(nullptr){
	}
	ListNode(int val, ListNode*next): val(val),next(next){
	}
};

class Solution {
public:
	ListNode* merge(ListNode *node1, ListNode *node2)
	{
		ListNode *ans = new ListNode();
		ListNode *res = ans;
		while(node1 && node2)
		{
			if(node1 -> val < node2 -> val)
			{
				ans -> next = node1 ;
				node1 = node1 -> next;
				ans = ans -> next;
			}
			else 
			{
				ans -> next = node2 ;
				node2 = node2 -> next;
				ans = ans -> next;
			}
		}
		while(node1) 
		{
			ans -> next = node1 ;
			node1 = node1 -> next;
			ans = ans -> next;
		}
		while(node2)
		{
			ans -> next = node2;
			node2 = node2 -> next;
			ans = ans -> next;
		}
		return res -> next ;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode *ans= new ListNode();
        for(int i = 1;i < lists.size();i ++)
        {
        	ans = merge(lists[i-1],lists[i]);
		}
		return ans;
    }
};

void printList(ListNode* node)
{
	ListNode*head = node;
	while(head)
	{
		cout<<head -> val << " ";
		head = head -> next;
	}
}
int main()
{
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = nullptr;
	printList(Solution().merge(node1,node2));
	return 0;
}
