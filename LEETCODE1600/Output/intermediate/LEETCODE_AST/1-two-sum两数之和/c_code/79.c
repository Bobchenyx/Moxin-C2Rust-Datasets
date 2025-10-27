/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *res = (int *)malloc(sizeof(int)*2);

    for(i = 0; i < numsSize; ++i)
    {
        for(j = i + 1; j < numsSize; ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return (int *)res;
            }
            
        }
    }
    return (int *)res;
}