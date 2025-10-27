int firstMissingPositive(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > 0 && nums[i] <= numsSize)
            nums[i] <<= 1;
        else
            nums[i] = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] >> 1)
            nums[(nums[i] >> 1) - 1] |= 1;
    for (int i = 0; i < numsSize; i++)
        if (!(nums[i] & 1))
            return i + 1;
    return numsSize + 1;
}