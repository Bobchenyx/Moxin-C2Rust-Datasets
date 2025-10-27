#define max(a,b) (a)>(b)?(a):(b)
int massage(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int dp[numsSize][2];
    dp[0][0]=0;
    dp[0][1]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = dp[i-1][0]+nums[i];
    }
    return max(dp[numsSize-1][0],dp[numsSize-1][1]);
}