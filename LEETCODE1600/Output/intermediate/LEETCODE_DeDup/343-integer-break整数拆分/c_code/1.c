int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int integerBreak(int n){
    int i = 1;
    int *dp;
    dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));

    
    if (n == 1)
        return 1;

    dp[1] = 1;

    for (int i = 2; i <= n; i ++)
    {
        for (int j = 1; j <= i - j; j ++)
        {
            dp[i] = max3(dp[i], j * (i - j), j * dp[i - j]); 
        }
    }

    return dp[n];
}