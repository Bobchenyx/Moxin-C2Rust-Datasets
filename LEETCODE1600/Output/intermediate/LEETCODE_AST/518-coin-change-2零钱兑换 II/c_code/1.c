int change(int amount, int* coins, int coinsSize){
    int dp[amount+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0;i<coinsSize;i++){
        int coin = coins[i];
        for(int j=1;j<=amount;j++){
            if(j<coin) continue;
            dp[j] += dp[j-coin]; 
        }
    }
    return dp[amount];
}