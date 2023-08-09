#include<iostream>
#include<vector>
using namespace std;


 
struct ListNode {
	int val;
	ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	void swap(ListNode* node1 , ListNode* node2 )
	{
		int temp = node1 -> val;
		node1 -> val = node2 ->val ;
		node2 -> val = temp ;
	}
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return head;
        int len = 0 ;
        ListNode *copy = head;
        while (copy)
        {
        	len ++;
        	copy = copy -> next;
		}
		
		delete copy;
		
		ListNode *node1 = head;
		ListNode *node2 = head;
		for(int i = 2;i <= k;i ++)
			node1 = node1 -> next;
		for(int i = 2;i <= len - k + 1;i ++)
			node2 = node2 -> next;
		
		swap(node1 , node2);
		return head;	
    }
};

int main()
{
	return 0;
}
