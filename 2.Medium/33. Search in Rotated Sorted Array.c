#include<stdio.h>

int search(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize - 1;
    while( low <= high ){
        int mid = ( high - low ) / 2 + low;
        if(nums[mid] == target) return mid;
        if(nums[low] <= target && target < nums[mid]) high = mid -1;
        else low = mid +1;

        if(nums[mid] < target && target <= nums[high]) low = mid + 1;
        else high = mid -1;
    }

    return -1;
}

int main(){

}
