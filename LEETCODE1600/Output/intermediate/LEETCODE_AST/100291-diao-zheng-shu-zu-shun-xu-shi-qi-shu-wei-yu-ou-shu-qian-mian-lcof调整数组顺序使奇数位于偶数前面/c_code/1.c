/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize)
{
    //入参检查
    if(nums == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    //分配和初始化数组
    int *result = (int*)malloc(sizeof(int)*numsSize);
    memset(result, 0, sizeof(int)*numsSize);

    int m = 0; //奇数区间指针
    int n = numsSize-1; //偶数区间指针
    for(int i =0; i < numsSize;i++)
    {
        if(nums[i] % 2 == 1)
        {
            result[m] = nums[i];
            m++;
        }
        else
        {
            result[n] = nums[i];
            n--;
        }
    }
    *returnSize = numsSize;
    return result;
}