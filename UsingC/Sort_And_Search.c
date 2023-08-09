#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define ff(i,a,b,s) for(int i = a; i <= b; i += s)
#define fl(i,a,b,s) for(int i = a; i >= b; i -= s)
#define f(i,n) for(int i = 0 ;i < n;i ++)
#define PI 3.14

typedef unsigned long long int ull;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int l, int r){
    int pivot = *(a + r);
    int id = l;

    for(int i = l; i < r ; i ++){
        if(*(a+i) > pivot) swap(a+i,a+(id++));
    }
    swap(a+id,a+r);
    return id;
}


void sort(int* a,int l ,int r){
    if(l < r){
        int m = partition(a,l,r);
        sort(a,l,m-1);
        sort(a,m+1,r);
    }
}

//mode : 0: equal to but smallest index,
//       1: greater than or equal to
//       2: smaller than or equal to
int binary_search(int *a,int len, int target, int mode){
    int ans = -1;
    int low = 0;
    int high = len -1;
    if(mode == 0){
        while(low <= high){
            int mid = (high - low )/2 + low;
            if(a[mid] > target)
                high = mid - 1;
            else if(a[mid] < target)
                low = mid +1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
    }
    else if(mode == 1){
        while(low <= high){
            int mid = (high - low)/2 + low;
            if(a[mid] >= target){
                 high = mid - 1 ;
                 ans = mid;
            }
            else low = mid + 1;
        }
    }
    else
    {
        while(low <= high){
            int mid = (high - low)/2 + low;
            if(a[mid] <= target){
                low = mid + 1;
                ans = mid;
            }
            else high = mid -1;
        }
    }
    return ans;
}





int main()
{
;
}

