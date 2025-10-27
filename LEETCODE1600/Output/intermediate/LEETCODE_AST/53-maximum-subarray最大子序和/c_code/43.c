int maxSubArray(int* nums, int numsSize){
    int dp[numsSize];
    dp[0]=nums[0];
    int i;
    for(i=1;i<numsSize;i++){
        if(dp[i-1]<0)
            dp[i]=nums[i];
        else
            dp[i]=dp[i-1]+nums[i];
    }
    int max=dp[0];
    for(i=1;i<numsSize;i++){
        max=max>dp[i]?max:dp[i];
    }
    return max;
}