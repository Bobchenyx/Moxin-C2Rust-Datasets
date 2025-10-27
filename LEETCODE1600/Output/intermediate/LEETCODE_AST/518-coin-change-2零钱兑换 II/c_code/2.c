int change(int amount, int* coins, int coinsSize){
    int dp[5000+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int idx = 0; idx < coinsSize; idx++) {
        for (int m = coins[idx]; m < amount + 1; ++m) {
            dp[m] += dp[m - coins[idx]];
            printf("m=%d dp=%d\n", m, dp[m]);
        }
    }
    return dp[amount];
}