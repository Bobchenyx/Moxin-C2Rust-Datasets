int searchInsert(int* nums, int numsSize, int target)
{
    int low=0,i=0;
    int high=numsSize-1;
    int mid=0,guess=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        guess=nums[mid];
        if(guess==target)
            return mid;
        else if(guess>target)
            high=mid-1;
        else
            low=mid+1;
    }
    for(i=0;i<numsSize;i++)
    {
        if(target<nums[i])
            return i;
    }
    return numsSize;
}