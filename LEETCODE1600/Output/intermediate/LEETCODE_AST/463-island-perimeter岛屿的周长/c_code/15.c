int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i;
    int j;
    int cnt = 0;
    int cntValid = 0;
    int result = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                cntValid++;
            }
        }
    }

    // from left to right
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize - 1; j++) {
            if (grid[i][j] == 0) {
                continue;
            } else {
                if (grid[i][j + 1] == 0) {
                    continue;
                } else {
                    cnt++;
                }
            }
        }
    } 

    // from up to down
    for (j = 0; j < *gridColSize; j++) {
        for (i = 0; i < gridSize - 1; i++) {
            if (grid[i][j] == 0) {
                continue;
            } else {
                if (grid[i + 1][j] == 0) {
                    continue;
                } else {
                    cnt++;
                }
            }
        }
    }

    result = cntValid * 4 - cnt* 2;

    return result;
    
}