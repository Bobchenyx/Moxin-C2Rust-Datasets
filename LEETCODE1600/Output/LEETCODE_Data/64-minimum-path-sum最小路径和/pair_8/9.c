#define MIN(a, b) ((a<b) ? a : b)

int minPathSum(int** grid, int gridSize, int* gridColSize){
    
    int **dp;
    dp = (int **)malloc(gridSize * sizeof(int *));
    for (int i = 0; i < gridSize; i ++)
    {
        dp[i] = (int *)calloc((* gridColSize), sizeof(int));
    }
    
    for (int i = 0; i < gridSize; i ++)
    {
        for (int j = 0; j < *gridColSize; j ++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = grid [0][0];
            }
            else if (i == 0 && j > 0)
            {
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            }
            else if (j == 0 && i > 0)
            {
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = grid[i][j] + MIN(dp[i][j - 1], dp[i - 1][j]);
            }
        }

    }
    return dp[gridSize - 1][(*gridColSize) - 1];
}