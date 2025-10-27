int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize==0)
        return 0;
    int flag=0;
    int temp=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]!=temp)
        {
            nums[flag]=nums[i-1];
            flag++;
            temp=nums[i];
        }
    }
    nums[flag]=nums[numsSize-1];
    return flag+1;
}