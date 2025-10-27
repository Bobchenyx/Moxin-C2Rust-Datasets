int findRepeatNumber(int* nums, int numsSize){
    int i = 0,temp = 0;
    if(numsSize == 0 || numsSize == 1)
    {
        return 0;
    }
    for(i = 0; i<numsSize; ++i)
    {
        if(i < 0 || i>numsSize)
        {
            return 0;
        }
    }
    for(i = 0; i<numsSize; ++i)
    {
        if(nums[i] != i)
        {
            if(nums[i] == nums[nums[i]])
            {
                return nums[i];
            }
            else
            {
                temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[temp] = temp;
            }
        }
    }
    return 0;
}