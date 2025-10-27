int rob(int* nums, int numsSize){
    if(!nums || numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    dp[1] = fmax(nums[1], nums[0]);
    for(int i = 2; i < numsSize; i++){
        dp[i] = fmax(dp[i-2] + nums[i], dp[i-1]);
    }
    return dp[numsSize - 1];
}