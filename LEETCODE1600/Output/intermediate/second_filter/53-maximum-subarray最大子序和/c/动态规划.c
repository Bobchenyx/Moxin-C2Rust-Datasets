#define MAX(a,b)  ((a)>(b)?(a):(b))
int maxSubArray(int* nums, int numsSize)
{
     int *dp = (int *)malloc(sizeof(int)*numsSize);
    int temp_max;
    dp[0] = nums[0];
    temp_max = dp[0];
    for(int i=1;i<numsSize;i++)
    {
        dp[i] = MAX(dp[i-1]+nums[i],nums[i]);
        if(dp[i]>temp_max)
        {
            temp_max = dp[i];
        }
    }
    return temp_max;
}