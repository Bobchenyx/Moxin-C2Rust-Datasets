//int max;

int dfs(int** grid, int rowSize, int colSize, int row, int col){

    if (row < 0 || row >= rowSize || col < 0 || col >= colSize || grid[row][col] == 0) {
        //max += 1;
        return 1;
    }

    if (grid[row][col] == -1)
        return 0;

    grid[row][col] = -1;
    
    return dfs(grid, rowSize, colSize, row - 1, col) +
            dfs(grid, rowSize, colSize, row + 1, col) +
            dfs(grid, rowSize, colSize, row, col - 1) +
            dfs(grid, rowSize, colSize, row, col + 1);
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i, j;
    //max = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                return dfs(grid, gridSize, gridColSize[0], i, j);
                //return max;
            }
        }
    }
    return 0;
}