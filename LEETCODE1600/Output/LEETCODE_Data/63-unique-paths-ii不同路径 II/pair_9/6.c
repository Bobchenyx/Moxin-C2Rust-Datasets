int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int i,j;
    int m,n;
    long long int DP[101][101];
    if (obstacleGrid == NULL || obstacleGridSize <= 0 || obstacleGridColSize == NULL)
        return 0;
    m = obstacleGridSize;
    n = obstacleGridColSize[0];
    printf("m = %d, n=%d\n", m, n);
    for (i = 0; i < m; i++) { //DP内存初始化为0
        for (j = 0; j < n; j++)
            DP[i][j] = 0;
    }
    DP[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0; //第一格特殊处理一下
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                DP[i][j] += i > 0 ? DP[i-1][j] : 0; //DP公式
                DP[i][j] += j > 0 ? DP[i][j-1] : 0; //DP公式
            }
        }
    }
    return DP[m-1][n-1];
}