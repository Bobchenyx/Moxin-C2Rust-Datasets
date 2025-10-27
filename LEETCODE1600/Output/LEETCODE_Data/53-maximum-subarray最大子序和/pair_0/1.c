int maxSubArray(int* nums, int numsSize){
    int max=(int)((((unsigned)1)<<(sizeof(int)*8-1))|1);
    int sum=0;
    for(int i=0;i<numsSize;++i)
    {   
        max=max>sum+nums[i]?max:sum+nums[i];
        sum=sum+nums[i]>0?sum+nums[i]:0;
    }
    return max;
}