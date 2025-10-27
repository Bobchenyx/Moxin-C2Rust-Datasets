int climbStairs(int n) {
    unsigned int dp[2] = { 1, 2 };
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    unsigned int result = 0;;
    for (int i = 3; i <= n; i++) {
        unsigned int tmp = dp[0] + dp[1];
        result = tmp;
        dp[(i + 1) % 2] = tmp;
    }
    return result;
}