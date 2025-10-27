int climbStairs(int n){
	//int dp[n+1] = {0};
	
	int *dp;
	dp = (int *) calloc(n+1, sizeof(int));	
	
	if (n < 1) {
		return 0;
	} else if (n < 3) {
		return n;
	} else {
		dp[1] = 1;
		dp[2] = 2;
		for (int i=3; i<=n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		} 
		return dp[n];
	}
}