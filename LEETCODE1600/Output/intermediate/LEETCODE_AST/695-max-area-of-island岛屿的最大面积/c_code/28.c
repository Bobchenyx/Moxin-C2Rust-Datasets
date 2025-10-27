void SubFuncDfs(int** grid, int gridSize, int* gridColSize, int x, int y, int *tmpValue)
{
    if ((x < 0) || (x > gridSize - 1) || (y < 0) || (y > (*gridColSize) - 1)) {
        return;
    }
    if (grid[x][y] == 0) {
        return;
    }

    grid[x][y] = 0;
    (*tmpValue)++;

    //printf("gridSize: %d, *gridColSize: %d, x: %d, y: %d\n", gridSize, *gridColSize, x, y);
    SubFuncDfs(grid, gridSize, gridColSize, x - 1, y, tmpValue);
    SubFuncDfs(grid, gridSize, gridColSize, x + 1, y, tmpValue);
    SubFuncDfs(grid, gridSize, gridColSize, x, y - 1, tmpValue);
    SubFuncDfs(grid, gridSize, gridColSize, x, y + 1, tmpValue);

}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if ((grid == NULL) || (gridSize == 0) || (gridColSize == NULL) || (*gridColSize == 0)) {
        return 0;
    }

    int i;
    int j;

    int returnSize = 0;
    int tmpValue = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] != 0) {
                //printf("input\n");
                tmpValue = 0;
                SubFuncDfs(grid, gridSize, gridColSize, i, j, &tmpValue);
                if (returnSize < tmpValue) {
                    returnSize = tmpValue;
                }
            }
        }
    }

    return returnSize;
}