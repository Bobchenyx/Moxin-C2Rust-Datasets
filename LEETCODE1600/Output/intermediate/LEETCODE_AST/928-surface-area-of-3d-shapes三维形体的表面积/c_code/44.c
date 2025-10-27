#define  MIN(a,b) ((a) > (b) ? (b) : (a))
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int row = gridSize;
    int col = *gridColSize;
    int sum = 0;
    int sub = 0;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            sum += grid[i][j];    

    sum = sum * 6;  //求总面积

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (grid[i][j] > 0)
            {
                sum -= (2 * (grid[i][j] - 1));    //减去每个点的上下重合面
                if (i + 1 < row)   //计算右面
                {
                    if (grid[i][j] != grid[i+1][j])
                    {
                        sub += MIN(grid[i][j],  grid[i+1][j]);
                    }
                    else
                    {
                        sub += grid[i][j];
                    }
                }
                if (j + 1 < col)  //计算前面
                {
                    if (grid[i][j] != grid[i][j+1])   //如果两个面数量不相等，则较小的面即为重合面
                    {
                        sub += MIN(grid[i][j], grid[i][j+1]);
                    }
                    else
                    {
                        sub += grid[i][j];   //相等，则此面完全重合
                    }
                }
                if (i - 1 >= 0)   //计算左面
                {
                    if (grid[i][j] != grid[i-1][j])
                    {
                        sub += MIN(grid[i][j],  grid[i-1][j]);
                    }
                    else
                    {
                        sub += grid[i][j];
                    }
                }
                if (j - 1 >= 0)   //计算后面
                {
                    if (grid[i][j] != grid[i][j-1])
                    {
                        sub += MIN(grid[i][j], grid[i][j-1]);
                    }
                    else
                    {
                        sub += grid[i][j];
                    }
                }
            }
        }
    }
    return sum - sub;
}