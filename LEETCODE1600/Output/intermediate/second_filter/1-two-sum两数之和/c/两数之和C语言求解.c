/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i,j;
int *p = NULL;
p = (int *)malloc(sizeof(int)*2);
for (i=0;i<numsSize;i++){
    for (j=i+1;j<numsSize;j++)
    {
        if (nums[i]+nums[j]==target){
            p[0] = i;
            p[1] = j;
            *returnSize = 2;
            return p;
        }
    }
}
return 0;
}