/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *left=(int *)malloc(sizeof(int)*numsSize);
    int *right=(int *)malloc(sizeof(int)*numsSize);
    int leftOut=1,rightOut=1;
    for(int i=0;i<numsSize;i++){
        left[i]=leftOut;
        right[numsSize-i-1]=rightOut;
        leftOut*=nums[i];
        rightOut*=nums[numsSize-i-1];
    }
    *returnSize = numsSize;
    for(int i=0;i<numsSize;i++){
        nums[i]=left[i]*right[i];
    }
    return nums;
}