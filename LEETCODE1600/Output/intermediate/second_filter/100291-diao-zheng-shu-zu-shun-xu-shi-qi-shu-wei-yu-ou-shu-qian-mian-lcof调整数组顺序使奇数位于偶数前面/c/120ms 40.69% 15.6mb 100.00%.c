/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int i=0,j=numsSize-1;
    while(i<j){
        while(i<j&&nums[i]%2==1){
            i++;
        }
        while(i<j&&nums[j]%2==0){
            j--;
        }
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    return nums;
}