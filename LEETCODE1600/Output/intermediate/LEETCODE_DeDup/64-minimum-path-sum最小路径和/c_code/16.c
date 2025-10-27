#define D2
#define CAN_USE_ORIGIN

int minPathSum(int** grid, int gridSize, int* gridColSize) {
  int m = gridSize;
  int n = gridColSize[0];
  
// Method 1: 2-D array, time O(mn), space O(n)
#ifdef D2

// Method 2: reuse grid array, time O(mn), space O(1)
#ifdef CAN_USE_ORIGIN
  int **dp = grid;  // Can use origin grid array
#else
  int dp[m][n];     // Can not use origin grid array
#endif
  
  dp[0][0] = grid[0][0];
  for (int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
  for (int i = 1; i < n; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
  
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      dp[i][j] = grid[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]);
    }
  }
  
  return dp[m - 1][n - 1];

// Method 3: 1-D array, time O(mn), space O(n)
#else

  int dp[n];
  dp[0] = grid[0][0];
  for (int i = 1; i < n; ++i) dp[i] = dp[i - 1] + grid[0][i];
  for (int i = 1; i < m; ++i) {  // The first row used to initialize Dp array
    for (int j = 0; j < n; ++j) {
      if (j == 0) {
        dp[j] = grid[i][j] + dp[j];
      } else {
        dp[j] = grid[i][j] + (dp[j] > dp[j - 1] ? dp[j - 1] : dp[j]);
      }
    }
  }
  return dp[n - 1];
#endif
}