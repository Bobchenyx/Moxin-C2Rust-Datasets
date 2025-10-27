int singleNumber(int* nums, int numsSize){
    int res = nums[0];
    int index = 0;

    for (index = 1; index <= numsSize - 1; index++)
    {
        res ^= nums[index];
    }

    return res;
}