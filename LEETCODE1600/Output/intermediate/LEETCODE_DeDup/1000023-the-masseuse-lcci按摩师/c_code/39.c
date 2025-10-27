int massage(int* nums, int numsSize){
    int *dp = (int *)malloc(numsSize * sizeof(int));
    memset(dp, -1, numsSize * sizeof(int));
    int result = dfs(nums, numsSize, dp, 0);
    free(dp);
    return result;

}

int dfs(int* nums, int numsSize, int *dp, int seq){
    if (nums == NULL || numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    
    if (dp[seq] != -1) return dp[seq];
    
    int a = nums[0] + dfs(nums + 2, numsSize - 2, dp, seq + 2);
    int b = nums[1] + dfs(nums + 3, numsSize - 3, dp, seq + 3);
    int result = a > b ? a : b;
    dp[seq] = result;
    return result;
}
/*

*/