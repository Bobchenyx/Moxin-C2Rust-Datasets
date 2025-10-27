int maxSubArray(int* nums, int numsSize){
    int i;
    int dp[100010] = {0};
    dp[0] = nums[0];
    int max = dp[0];
    for(i = 1; i < numsSize; i++){
        if(dp[i-1] + nums[i] >= nums[i]){
            dp[i] = dp[i-1] + nums[i];
        }else{
            dp[i] = nums[i];
        }
        if(max < dp[i]){
            max = dp[i];
        }
    }
    return max;
}