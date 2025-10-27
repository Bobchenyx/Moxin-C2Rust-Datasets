int dp[m+1][n+1];
// 全部置0
memset(dp, 0, sizeof(dp));
// 先把这两个坐标设为1
dp[1][2] = 1;
dp[2][1] = 1;