int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int *dp = (int*)malloc(sizeof(int) * gasSize);
    if (!dp) {
        return -1;
    }
    dp[0] = gas[0] - cost[0];
    int min = dp[0];
    int minIndex = 0;
    for (int i = 1; i < gasSize; i++) {
        dp[i] = dp[i-1] + gas[i] - cost[i];
        if (min > dp[i]) {
            min = dp[i];
            minIndex = i;
        }
    }
    if (dp[gasSize - 1] >= 0) {
        return (minIndex + 1) % gasSize;
    } else {
        return -1;
    }    
}