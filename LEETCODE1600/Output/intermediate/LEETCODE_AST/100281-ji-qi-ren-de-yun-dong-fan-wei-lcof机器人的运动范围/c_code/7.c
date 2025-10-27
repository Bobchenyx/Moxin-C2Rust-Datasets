int movingCount(int m, int n, int k)
{
    int hasVisited[m][n];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            hasVisited[i][j] = 0;
        }
    }
    int dfs(int i, int j, int sumi, int sumj)
    {
        if(i >= m || j >= n || (sumi + sumj) > k || hasVisited[i][j] == 1)
        return 0;
        hasVisited[i][j] = 1;
        return 1 + dfs(i, j + 1, sumi, (j + 1)%10 == 0 ? (sumj - 8) : (sumj + 1)) + dfs(i + 1, j, (i + 1)%10 == 0 ? (sumi - 8) : (sumi + 1), sumj);
    }
    return dfs(0, 0, 0, 0);
}