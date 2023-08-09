#include<stdio.h>

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s )


void takeArr(int* arr, int* arrSize){
    scanf("%d",arrSize);
    ff(i,0,*arrSize-1,1)
        scanf("%d",&arr[i]);
}

void printArr(int* arr, int arrSize){
    for(int i = 0 ;i < arrSize;i ++) printf("%d ",arr[i]);
    printf("\n");
}

void swap(int *a, int*b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int index = low;

    ff(i,low , high-1,1){
        if(arr[i] < pivot){
            swap(&arr[i], &arr[index]);
            index ++;
        }
    }

    swap(&arr[index], &arr[high]);
    return index;
}

void quickSort(int* arr, int low, int high)
{
    if(low < high)
    {
        int medium = partition(arr, low, high);
        quickSort(arr, low, medium-1);
        quickSort(arr, medium+1, high);
    }
}

int binarySearch(int* arr,int arrSize, int target)
{
    int low = 0;
    int high = arrSize-1;

    int ans = -1;
    while(low <= high){
        int mid = (high - low )/2 + low;
        if(arr[mid] > target)
            high = mid - 1;
        else if(arr[mid] < target)
            low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}


int main()
{
    int arr[100001];
    int len;

    takeArr(arr,&len);

    quickSort(arr,0,len-1);

    printArr(arr,len);

    printf("%d",binarySearch(arr,len,3));
}
