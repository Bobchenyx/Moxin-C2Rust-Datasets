/** dp[m,n] = dp[m-1,n]+dp[m,n-1];
*   dp[0,0] = 0;
*   dp[x,0] = 1; dp[0,y]=1;
*/

int uniquePaths(int m, int n){
    int dp[100][100];
    int x = 0;
    int y = 0;

    while (x < m) {
        dp[x++][0] = 1;
    }
    while (y < n) {
        dp[0][y++] = 1;
    }

    for (x = 1; x < m; x++) {
        for (y = 1; y < n; y++) {
            dp[x][y] = dp[x-1][y] + dp[x][y-1];
        }
    }
    return dp[m-1][n-1];

}