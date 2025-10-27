int uniquePaths(int m, int n){
    int result;
    /* 一维数组当二维来用 */
    int *dp = (int *) malloc(m * n * sizeof(int));
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
             if (i == 0 || j == 0) {
                 dp[i * n + j] = 1;
                 continue;
            }
            dp[i * n + j] = dp[(i-1)*n + j] + dp[i*n + j-1];
        } 
    }
    result = dp[m * n - 1];
    free(dp);
    return result;
}