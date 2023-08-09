#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int m = nums1.size();
        int n = nums2.size();
        int id1 = 0 ;
        int id2 = 0;
        
        while(id1 < m && id2 < n)
        {
        	if(nums1[id1] < nums2[id2]) arr.push_back(nums1[id1++]);
        	else arr.push_back(nums2[id2++]);
		}
        while(id1 < m) arr.push_back(nums1[id1++]);
        while(id2 < n) arr.push_back(nums2[id2++]);
        for(int i = 0;i < arr.size();i ++) cout<<arr[i]<<" ";
        
        if(arr.size() % 2 == 1) return (double)arr[arr.size()/2];
        else return (double(arr[arr.size()/2] + double(arr[arr.size()/2-1]))) /2; 
    }
};

int main()
{
	vector<int> a1 = {1,2,3,4};
	vector<int> a2 = {2,3,4,5,6};
	Solution().findMedianSortedArrays(a1,a2);
}
