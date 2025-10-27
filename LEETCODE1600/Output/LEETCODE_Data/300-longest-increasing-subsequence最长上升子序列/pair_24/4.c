int max(int a,int b)
{
    return a>b?a:b;
}

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize < 1)
        return 0;//在用函数参数作为数组维度之前，对参数特殊情况（numsSize == 0）做处理
    int dp[numsSize];//定义dp[i]表示以nums[i]这个数结尾的最长递增子序列的长度
    for(int i = 0;i < numsSize;++i)
        dp[i] = 1;//dp数组初始化为1，因为最长递增子序列最短都是1（包括nums此位置上的那个数）
    for(int i = 0;i < numsSize;++i){
        for(int j = 0;j < i;++j){
            if(nums[j] < nums[i])
                dp[i] = max(dp[i],dp[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0;i < numsSize;++i)
        ans = max(ans,dp[i]);//dp数组中的最大值就是最长递增子序列的长度
    return ans;
}