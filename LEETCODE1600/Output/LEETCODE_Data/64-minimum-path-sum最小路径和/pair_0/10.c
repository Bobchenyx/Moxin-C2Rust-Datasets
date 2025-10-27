#define min(a, b) ((a) > (b) ? (b) : (a))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i, j;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                grid[i][j] = grid[i][j - 1] + grid[i][j];
            } else if (j == 0) {
                grid[i][j] = grid[i - 1][j] + grid[i][j];
            } else {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
    }
    return grid[gridSize - 1][*gridColSize - 1];
}