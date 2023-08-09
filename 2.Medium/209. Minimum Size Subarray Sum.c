#include<stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize){
    int i,j,sum;
    i = j = sum = 0;
    int result = numsSize + 1;

    while(j < numsSize){
        sum += nums[j];
        while(i <= j && sum >= target) {
            result = min(result,j-i+1);
            sum -= nums[i++];
        }
        j ++;
    }
    return result;
}

int main(){

}
