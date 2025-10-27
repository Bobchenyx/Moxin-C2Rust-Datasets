int findLengthOfLCIS(int* nums, int numsSize){
    int max=0,count=1,i;//对于序列的长度，至少会达到1
    if(numsSize==0)//考虑到极端情况
    return 0;
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]<nums[i+1])//经过试验，相同的元素不算入递增
                count++;
        else//逆序的情况
        {
            if(count>max)
            {
                max=count;
            }
            count=1;
        }
    }
    if(count>max)//防止全部顺序，不出现逆序的情况
        max=count;
    return max;
}