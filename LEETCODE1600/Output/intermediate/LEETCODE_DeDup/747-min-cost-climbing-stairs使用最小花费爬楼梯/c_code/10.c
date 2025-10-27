#define MIN(a,b) ((a)<(b)?(a):(b))
int minCostClimbingStairs(int* cost, int costSize){
    int* dp = malloc((costSize+1) * sizeof(int)), i;

    dp[0] = dp[1] =0;
    for (i = 2; i <= costSize; i++)
        dp[i] = MIN(dp[i-2] + cost[i - 2], dp[i-1] + cost[i-1]);

    return dp[costSize];
}