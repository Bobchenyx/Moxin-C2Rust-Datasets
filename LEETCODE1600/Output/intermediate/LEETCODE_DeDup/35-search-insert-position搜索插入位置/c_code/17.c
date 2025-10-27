int searchInsert(int* nums, int numsSize, int target){
    if(numsSize==0)
    {
        return 0;
    }
    if(nums[0]>=target)
    {
        return 0;
    }
    if(nums[numsSize-1]<target)//可能存在 1 2 2 2 2 这种情况。
    {
        return numsSize;
    }
    int i,middle=nums[numsSize/2];
    if(middle>=target)
    {
        for(i=0;i<numsSize/2+1;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else if(nums[i]<target&&nums[i+1]>target)
            {
                return i+1;
            }
        }
    }
    else
    {
        for(i=numsSize/2;i<numsSize;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else if(nums[i]<target&& nums[i+1]>target)
            {
                return i+1;
            }
        }
    }
    return 0;

}