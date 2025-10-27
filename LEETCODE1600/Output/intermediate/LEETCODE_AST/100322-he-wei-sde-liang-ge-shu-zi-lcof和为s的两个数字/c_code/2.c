/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    
    int *rel = (int*)malloc(sizeof(int)*2);
    memset(rel, 0, sizeof(int)*2);

    int i =0, j = numsSize-1;
    while(i <j)
    {
        if(nums[i] + nums[j] == target)
        {
            rel[0] = nums[i];
            rel[1] = nums[j];
            break;
        }
        else if(nums[i] + nums[j] >target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    *returnSize = 2;
    return rel;
}