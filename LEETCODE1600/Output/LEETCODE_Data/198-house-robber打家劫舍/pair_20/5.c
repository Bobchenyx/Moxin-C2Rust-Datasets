#define MAX(a,b) ((a)>(b)?(a):(b))
int rob(int* nums, int numsSize){
    int i, max = 0;
    int *dp = malloc(numsSize * sizeof(int));

    if (numsSize == 0)
        return 0;
    
    if (numsSize == 1)
        return nums[0];

    if (numsSize == 2)
        return MAX(nums[0], nums[1]);

    dp[0] = nums[0];
    dp[1] = MAX(nums[0],nums[1]);
    for (i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
        max = MAX(max, dp[i]);
    }
    return max;
}