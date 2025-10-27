int min(int x, int y) {
    return x>y?y:x;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){

    int result = 0;
    int below = 0;
    int left = 0;

    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<*gridColSize; j++) {

            if (i > 0) {
                below = grid[i-1][j];
            } else {
                below = 0;
            }

            if (j > 0) {
                left = grid[i][j-1];
            } else {
                left = 0;
            }
            if (grid[i][j] == 0) continue;
            result += grid[i][j] * 4 + 2 - 2*min(left, grid[i][j]) - 2*min(below, grid[i][j]);

        }
    }
    return result;
}