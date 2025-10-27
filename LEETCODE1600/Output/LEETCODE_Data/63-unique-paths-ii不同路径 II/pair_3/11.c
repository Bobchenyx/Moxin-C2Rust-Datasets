int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    unsigned int **dp = NULL;
    int i, j;
    dp = (int **)malloc(sizeof(int *) * obstacleGridSize);
    for (i = 0; i < obstacleGridSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (*obstacleGridColSize));
        memset(dp[i], 0, sizeof(int) * (*obstacleGridColSize));
    }
    int flag = 1; // init the first row
    for (i = 0; i < *obstacleGridColSize; i++) {
        if (obstacleGrid[0][i] == 0) {
            dp[0][i] = flag;
        } else {
            flag = 0;
        }
    }
    flag = 1; // init the first colomn
    for (i = 0; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = flag;
        } else {
            flag = 0;
        }
    }
    for (i = 1; i < obstacleGridSize; i++) {
        for (j = 1; j < *obstacleGridColSize; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[obstacleGridSize - 1][*obstacleGridColSize - 1];
}