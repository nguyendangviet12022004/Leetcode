#include<iostream>
#include<vector>
using namespace std;

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
struct num{
	int val;
	int id;
	num(int val,int id): val(val),id(id){
	}	
};

void take_input(vector<num> &a) // check  
{
	int lenght;
	cin >> lenght;
	ff(id,0,lenght-1,1) 
	{
		int val ;
		cin >> val ;
		num add(val,id);
		a.push_back(add);
	}
}

void give_output(vector<num> a) // check
{
	ff(i,0,a.size()-1,1) cout<<a[i].val<<" ";
	cout<<endl;
}

void merge(vector<num>&arr , int low, int medium , int high) // check 
{
	vector<num> b;
	vector<num> c;
	
	int len1  = medium - low + 1;
	int len2 = high - medium ;
	
	ff(i,0,len1-1,1) b.push_back(arr[low + i]);
	ff(i,0,len2-1,1) c.push_back(arr[medium + i + 1] );
	
	int k = low;
	int i = 0;
	int j = 0;
	
	while (i < len1 && j < len2)
		arr[k++] = (b[i].val < c[j].val) ? b[i++] : c[j++];
		
	while (i < len1)
		arr[k++] = b[i++] ;
		
	while(j < len2)
		arr[k++] = c[j++] ;	

}

mergeSort(vector<num>&arr, int low, int high) // check 
{
	if (low < high){

	int medium = (high + low) / 2;
	
	mergeSort(arr,low,medium);
	mergeSort(arr,medium+1,high);
	
	merge(arr,low,medium,high);
	}
}


void swap(int &a, int &b)
{
	int t = a;
	a = b; 
	b = t;
}

int pivot(vector<num> &arr, int low, int high)
{
	int id = low;
	int p = arr[high].val;
	ff(i,low,high-1,1)
		if(arr[i].val < p ) swap(arr[i],arr[id++]);
	
	swap(arr[id],arr[high]);
	return id;
}

void quickSort(vector<num> &arr, int low, int high)
{
	if (low < high)
	{
		int p = pivot(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}

int binarySearch(vector<num> arr,int target)
{
	int low = 0;
	int high = arr.size() - 1;
	while (low < high)
	{
		int mid = (high - low) / 2 + low;
		if (arr[mid].val >= target) high = mid;
		else low = mid + 1;
	}
	return (arr[low].val == target) ? arr[low].id : -1;
}


int main()
{
	vector<num> arr;
	take_input(arr);
	quickSort(arr,0,arr.size()-1);
	give_output(arr);
	
	return 0;
}
