int lengthOfLIS(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int dp[numsSize];
    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
    }
    int max = 1;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if(dp[i] > max)
                max = dp[i];
            }
        }
    }


    return max;
}