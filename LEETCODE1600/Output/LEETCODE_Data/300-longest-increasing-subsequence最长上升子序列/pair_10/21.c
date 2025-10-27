#define MAX(a,b) ((a)>(b)?(a):(b))

int lengthOfLIS(int* nums, int numsSize) {
    int dp[10000] = {0};
    int i, j, max = 1;

    if (numsSize == 0)
        return 0;

    dp[0] = 1;
    for (i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = MAX(dp[i], dp[j] + 1);
        }
        max = MAX(dp[i], max);
    }
    
    return max;
}