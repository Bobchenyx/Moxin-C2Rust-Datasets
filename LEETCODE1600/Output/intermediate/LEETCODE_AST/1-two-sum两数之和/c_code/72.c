/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* returns = (int *)malloc(sizeof(int) * 2);
    int i = 0;
    int j = 1;
    * returnSize=0;
    for(i;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
             returns[0]=i;
             returns[1]=j;
             *returnSize = 2;
             return returns;
             }
        }
    }
    return returns;
}