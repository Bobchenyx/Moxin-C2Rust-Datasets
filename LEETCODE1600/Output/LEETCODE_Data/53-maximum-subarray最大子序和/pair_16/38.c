#define MAX(x, y) ((x) > (y)) ? (x) : (y)

int maxSubArray(int* nums, int numsSize){
    int dp[numsSize];
    dp[0] = nums[0];
    int i;
    for(i = 1; i < numsSize; i++){
        dp[i] = MAX(nums[i], nums[i] + dp[i-1]);
    }
    int max = dp[0];
    for(i = 1; i < numsSize; i++){
        if(dp[i] > max)
            max = dp[i];
    }
    return max;
}