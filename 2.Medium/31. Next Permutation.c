// check if any a[i+1] > a[i] , find any number greater than a[i] (from i + 1 to n ) then swap them, reverse a[id+1:]
// 12534 -> 12435

#include<stdio.h>
#include<stdlib.h>

void swap(int *a ,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void reverse(int*a ,int l,int r)
{
    for(int i = l ;i <= (l + r)/2 ; i ++)  swap(&a[i],&a[r-i+l]);
}


void nextPermutation(int* nums, int numsSize){
    int i = numsSize-2;
    for(;i >= 0;i--) if(nums[i] < nums[i+1]) break;
    for(int j = numsSize -1;j > i ;j --){
        if(nums[j] > nums[i])
        {
            swap(&nums[j],&nums[i]);
            break;
        }
    }
    reverse(nums,i+1,numsSize-1);


}

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int*)(malloc(n * sizeof(int)));
    for(int i = 0 ;i < n ;i ++) scanf("%d",&a[i]);

    nextPermutation(a,n);
    for(int i = 0 ;i < n;i ++) printf("%d ",a[i]);
}
