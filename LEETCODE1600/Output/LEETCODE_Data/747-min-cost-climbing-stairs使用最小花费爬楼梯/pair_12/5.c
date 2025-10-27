int minCostClimbingStairs(int* cost, int costSize){
    if(costSize == 1)return cost[0];
    if(costSize == 2)return (cost[0]>cost[1])?cost[1]:cost[0];
    int dp[costSize+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i<costSize + 1; i++){
        dp[i] = ((dp[i-1] + cost[i-1]) < (dp[i-2] + cost[i-2]))?(dp[i-1] + cost[i-1]):(dp[i-2] + cost[i-2]);
    }
    return dp[costSize];
}