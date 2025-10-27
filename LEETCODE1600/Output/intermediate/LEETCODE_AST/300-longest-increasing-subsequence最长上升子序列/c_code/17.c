int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
    int max=1,i,j;
    int dp[numsSize];
    for(i=0;i<numsSize;i++)
    dp[i]=1;
    for(i=1;i<numsSize;i++)
    {
        for(j=0;j<i;j++)
        {
            if(nums[i]>nums[j]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                if(dp[i]>max)
                max=dp[i];
            }
        }
    }
    return max;
}