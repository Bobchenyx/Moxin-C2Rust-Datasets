#define max(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int i, j;
    int *dp = (int *)malloc((numsSize + 1) * sizeof(int));
    int length;

    for (i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }
    for (i = 1; i < numsSize; i++) {
        for(j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    length = dp[0];
    for (i = 1; i < numsSize; i++) {
        if (dp[i] > length) {
            length = dp[i];
        }
    }
    free(dp);
    return length;    
}