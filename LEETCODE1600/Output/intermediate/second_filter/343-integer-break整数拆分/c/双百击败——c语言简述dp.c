int max(int a,int b){
    return a>b?a:b;
}
int integerBreak(int n){
    int dp[60];
    memset(dp,0,sizeof(dp));
    int i,j;
    dp[1] = 1;
    for(i = 2; i <= n; i++){
        for(j = 1; j < i; j++){
            dp[i] = max(dp[i],(i-j)*max(dp[j],j));
        }
    }
    return dp[n];
}