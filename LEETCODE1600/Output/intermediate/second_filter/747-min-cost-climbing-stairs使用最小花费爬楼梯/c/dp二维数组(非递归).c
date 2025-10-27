#define MIN(a, b)  (((a)<(b)) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize){
    int *dp[2];
    for(int i = 0; i < 2; i++)
        dp[i] = malloc(sizeof(int) * costSize);
    
    dp[0][0] = cost[0];
    dp[1][0] = cost[0];
    dp[0][1] = cost[0];
    dp[1][1] = cost[1];

    for(int i = 2; i < costSize; i++)
    {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = cost[i] + MIN(dp[0][i-1], dp[1][i-1]);
    }
    return MIN(dp[0][costSize-1], dp[1][costSize-1]);
}