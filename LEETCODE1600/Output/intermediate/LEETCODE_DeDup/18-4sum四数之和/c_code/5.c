#include<stdio.h>
#include<stdlib.h>

int combineNum(int n, int m)   //Cnm 的组合情况
{
    if (n < m)
        return 0;
    if (m == 0)
        return 1;
    if (m == n)
        return 1;
    int temp = (m <= n - m) ? m : n - m;
    unsigned int a = 1, b = 1;
    for (; temp > 0; temp--,n--)
    {
        a *= n;
        b *= temp;
    }
    return a / b;
}

int cmp ( const void  *a , const void  *b ) 
{
	return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    int **res = NULL;
    *returnSize = 0;
    if (numsSize < 4)
    {
        return res;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int sum_start = nums[0] + nums[1] + nums[2] + nums[3];
    int sum_end = nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] + nums[numsSize - 4];
    if (sum_start > target || sum_end < target)
    {
        return res;
    }
    int len = 3;
    for (int i = 3; i < numsSize && nums[i] <= (target - nums[0] - nums[1] - nums[2]); i++)
    {
        len ++;
    }
    if (len < 8)
        res = (int**)calloc(combineNum(len, 4), sizeof(int*));
    else
        res = (int**)calloc(combineNum(len, 3), sizeof(int*));
    if (NULL == res)
    {
        exit(0);
    }
    if (len < 8)
        *returnColumnSizes = (int*)calloc(combineNum(len, 4), sizeof(int));
    else
        *returnColumnSizes = (int*)calloc(combineNum(len, 3), sizeof(int));
    for (int i = 0; i < numsSize - 3; i++)
    {
        if (nums[i] > (target - nums[0] - nums[1] - nums[2]))
        {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left = j + 1, right = numsSize - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    res[*returnSize] = (int*)calloc(4, sizeof(int));
                    if (NULL == res[*returnSize])
                    {
                        exit(0);
                    }
                    (*returnColumnSizes)[*returnSize] = 4;
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnSize)++;
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left ++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right --;
                    }
                    left ++;
                    right --;
                }
                else if (sum > target)
                {
                    right --;
                }
                else
                {
                    left ++;
                }
            }
        }
    }
    return res;
}