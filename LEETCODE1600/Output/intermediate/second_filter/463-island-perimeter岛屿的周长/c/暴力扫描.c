int count_one(int x, int y, int** grid, int a, int b){
    int res = 0;
    if (x-1 < 0 || grid[x-1][y] == 0) res++;
    if (x+1 > a-1 || grid[x+1][y] == 0) res++;
    if (y-1 < 0 || grid[x][y-1] == 0) res++;
    if (y+1 > b-1 || grid[x][y+1] == 0) res++;
    return res;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    for (int i=0; i<gridSize; i++){
        for (int j=0; j<*gridColSize; j++){
            if (grid[i][j] == 1){
                res += count_one(i, j, grid, gridSize, *gridColSize);
            }
        }
    }
    return res;
}