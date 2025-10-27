int Max(int a, int b){
    return a<b?b:a;
}
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int maxsubsequence = 0;
    for(int i=1; i<numsSize; i++){
        int tmp = 1;
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j])
                tmp = Max(tmp, dp[j]+1);
        }
        dp[i] = tmp;
        maxsubsequence = Max(dp[i], maxsubsequence);
    }
    return maxsubsequence;
}