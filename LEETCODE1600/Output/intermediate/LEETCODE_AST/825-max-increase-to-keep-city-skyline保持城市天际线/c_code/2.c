int get_min(int a, int b)
{
    return a <= b ? a : b;
}

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int *row = calloc(gridSize, sizeof(int));
    int *col = calloc(gridSize, sizeof(int));

    for (int i = 0; i < gridSize; i++) {
        int max = 0;
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > max) {
                max = grid[i][j];
            }
        }
        row[i] = max;
    }

    for (int i = 0; i < gridColSize[0]; i++) {
        int max = 0;
        for (int j = 0; j < gridSize; j++) {
            if (grid[j][i] > max) {
                max = grid[j][i];
            }
        }
        col[i] = max;
    }

    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            res += get_min(row[i], col[j]) - grid[i][j];
        }
    }

    return res;
}