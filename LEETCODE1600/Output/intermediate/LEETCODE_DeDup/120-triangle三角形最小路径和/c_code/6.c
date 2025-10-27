int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int dp[triangleSize][triangleSize];
    
    for (int i = 0; i < triangleSize; i ++)
    {
        for (int j = 0; j < triangleSize; j ++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < triangleSize; i ++)
    {
        dp[triangleSize - 1][i] = triangle[triangleSize - 1][i];
    }

    for (int i = triangleSize - 2; i >= 0; i --)
    {
        for (int j = 0; j < triangleColSize[i]; j ++)
        {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }

    
    return dp[0][0];
}