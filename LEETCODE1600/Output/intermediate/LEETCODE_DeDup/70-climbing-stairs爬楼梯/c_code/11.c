int dp[1000] = {0};
int climbStairs(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(dp[n] != 0)
        return dp[n];
    else
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
    return dp[n];
}