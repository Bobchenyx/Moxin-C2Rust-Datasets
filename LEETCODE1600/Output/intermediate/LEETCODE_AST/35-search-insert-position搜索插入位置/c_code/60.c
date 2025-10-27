int searchInsert(int* nums, int numsSize, int target)
{
    int i=0;
    if(numsSize==0)
        return i;
    if(target>nums[numsSize-1])
        return numsSize;
    while(nums[i]<=target&&i<numsSize)
    {
        if(nums[i]==target)
            return i;
        else
            i++;
    }
    return i;
}