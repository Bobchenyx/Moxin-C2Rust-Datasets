/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i=0,j;
int *result_nums;
for (;i<numsSize;i++)
{
    for (j=i+1;j<numsSize;j++)
    {
        if((nums[i]+nums[j])==target)
        {
                *returnSize = 2;
                result_nums = (int*)malloc(sizeof(int)* 2);
                result_nums[0] = i;
                result_nums[1] = j;
                return result_nums;
        }
    }
}
return 0;
}