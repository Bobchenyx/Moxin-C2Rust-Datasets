/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0, j  = 0;

    int* returnNums = (int*)malloc(sizeof(int)*2);

    for (i = 0; i < numsSize-1; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnNums[0] = i;
                returnNums[1] = j;
                *returnSize = 2;
                return returnNums;
            }
        }
    }

    return returnNums;
}