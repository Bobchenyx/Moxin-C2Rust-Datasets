#define MAX(x, y) ((x) > (y))?(x):(y)

int massage(int* nums, int numsSize) {
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    int i;
    for (i = 0; i < numsSize; i++) {
        dp[i] = 0;
    }
    if (numsSize == 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    } 

    if (numsSize == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }

    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    for (i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[i - 1];
}