int climbStairs(int n){
    
    int i;
    int *dp = malloc((n+1)*sizeof(int));
    dp[0] = 1;
    dp[1] = 2; 
    for(i=2;i<n;i++){
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    i = dp[n-1];
    free(dp);
    return i;
}