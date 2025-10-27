int massage(int* nums, int numsSize){
    if (!nums || numsSize == 0) return 0;

    int dp[numsSize];
    int ans = 0;

    (void)memset(dp, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (i < 2) {
            dp[i] = nums[i];
        }
        else {
            dp[i] = fmax(dp[i-2] + nums[i], dp[i-1]-nums[i-1]+nums[i]);
        }
        ans = fmax(dp[i], ans);
    }

    return ans;
}