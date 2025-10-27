int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int row, col;
    int cnt, new_cnt, i, j, flag;

    row = gridSize;
    col = *gridColSize;

    cnt = 0;
    new_cnt = -1;
    /* 循环遍历数组，直至前后两次完全相同 */
    while (new_cnt != cnt) {
        new_cnt = cnt;
        flag = 0;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    if ((i > 0 && (grid[i - 1][j] == 1)) || 
                        (i < row - 1 && (grid[i + 1][j] == 1)) ||
                        (j > 0 && (grid[i][j - 1] == 1)) || 
                        (j < col - 1 && (grid[i][j + 1] == 1))) {
                            if (flag == 0) {
                                flag = 1;
                                cnt++;    
                            }
                        }
                    if (i > 0 && (grid[i - 1][j] == 1)) { /* up */
                        grid[i - 1][j] = 3;
                    }
                    if (i < row - 1 && (grid[i + 1][j] == 1)) { /* down */
                        grid[i + 1][j] = 3;
                    }
                    if (j > 0 && (grid[i][j - 1] == 1)) { /* left */                   
                        grid[i][j - 1] = 3;
                    }
                    if (j < col - 1 && (grid[i][j + 1] == 1)) { /* right */
                        grid[i][j + 1] = 3;
                    }
                }
            }
        }

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j] == 3) {
                    grid[i][j] = 2;
                }
            }
        }
    }
        
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return cnt;
}