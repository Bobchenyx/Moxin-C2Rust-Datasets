int massage(int* nums, int numsSize){
    if(numsSize==1)
    {
        return *(nums);
    }
    if(numsSize==0)
    {
        return 0;
    }
    int dp[numsSize];
    dp[0]=*(nums);
    dp[1]=*(nums)>*(nums+1)?*(nums):*(nums+1);
    for(int i=2;i<numsSize;i++)
    {
        dp[i]=(dp[i-2]+nums[i])>dp[i-1]?(dp[i-2]+nums[i]):dp[i-1];
    }
    return dp[numsSize-1];
}