int maxSubArray(int* nums, int numsSize){
    int dp[numsSize];
    int dpp[numsSize];
    int res = nums[0];
    memset(dp,INT_MIN,sizeof(dp));
    dp[0] = nums[0];
    for(int i = 1; i < numsSize; i ++){
        dp[i] = dp[i - 1] + nums[i];
        dpp[i] = dp[i];
        if(res < dp[i])res = dp[i];
        //printf("%d ",dp[i]);
    }
    //printf("\n");
    
    for(int i = 1; i < numsSize; i ++){
        for(int j = i; j < numsSize; j ++){
            if(i == j) dp[i] = nums[i];
            if(i != j) dp[j] = dpp[j] - nums[i - 1];
            if(res < dp[j])res = dp[j];
        }
        memcpy(dpp,dp,sizeof(dp));
        //for(int i = 0; i < numsSize; i ++)printf("%d ",dp[i]);
        //printf("\n");
    }
    return res;
}