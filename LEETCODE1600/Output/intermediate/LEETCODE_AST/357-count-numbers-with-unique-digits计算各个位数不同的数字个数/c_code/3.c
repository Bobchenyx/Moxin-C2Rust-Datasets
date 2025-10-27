int countNumbersWithUniqueDigits(int n){
    if(n == 0)
     return 1;
    if(n == 1)
     return 10;
     int dp[n+1];
     dp[0] = 1;
     dp[1] = 10;
    for(int i = 2; i <= n; i++)
    {
        int temp = 9;
        for(int j = 0; j < i-1;j++)
        {
            temp *= 9-j;
        }
        dp[i] = dp[i-1] + temp;
    }
    return dp[n];
}