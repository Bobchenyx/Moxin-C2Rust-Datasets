int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1) cnt++, max = cnt > max ? cnt : max;
        else cnt = 0;
    }
    return max;
}