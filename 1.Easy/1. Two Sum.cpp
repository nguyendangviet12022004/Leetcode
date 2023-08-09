#include<iostream>

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)

using namespace std;
struct num{
	int val ;
	int index; 

};

void swap(num &a, num &b)
{
	num t ;
	t.val = a.val;
	t.index = a.index;
	
	a.val = b.val ;
	a.index = b.index;
	
	b.val = t.val;
	b.index = t.index;
}

int pivot(num a[], int l, int r)
{
	int id = l ;
	int p = a[r].val;
	for(int i = l;i < r;i ++)
	{
		if(a[i].val < p) 
		{
			swap(a[i],a[id++]);
		}
	}
	swap(a[id],a[r]);
	return id;
}

void quickSort(num a[],int l, int r)
{
	if (l < r)
	{
		int p = pivot(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}

int binSearch(num a[],int l,int r,int target)
{
	while (l < r)
	{
		int m = (r - l) / 2 + l ;
		if (a[m].val >= target)
		{
			r = m ;
		}
		else 
		{
			l = m + 1; 
		}
	}
	return (a[l].val == target) ? a[l].index : -1 ;
}

class Solution {
	public :
		int *twoSum(num arr[], int len, int target)
		{
			int *ans = new int[2];
			quickSort(arr,0,len-1);
			ff(i,0,len-1,1)
			{
				int y = binSearch(arr,i+1,len-1,target-arr[i].val);
				if (y != -1)
				{ 
					ans[0] = arr[i].index;
					ans[1] = y;
					break;
				}
			}
			return ans;
		}
};


int main()
{

	
}
