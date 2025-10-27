void setToOne(char** grid, int i, int j, int gridSize, int colSize)
{
    if(i < 0 || i >= gridSize || j < 0 || j >= colSize || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    setToOne(grid, i - 1, j, gridSize, colSize);
    setToOne(grid, i + 1, j, gridSize, colSize);
    setToOne(grid, i, j - 1, gridSize, colSize);
    setToOne(grid, i, j + 1, gridSize, colSize);
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j,colSize;
    int count = 0;
    if(gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }
    colSize = gridColSize[0];
    for(i = 0; i < gridSize; i++)
    {
        for(j = 0; j < colSize; j++)
        {
            if(grid[i][j] == '1') {
                setToOne(grid, i, j, gridSize, colSize);
                count++;
            }
        }
    }
    return count;
}