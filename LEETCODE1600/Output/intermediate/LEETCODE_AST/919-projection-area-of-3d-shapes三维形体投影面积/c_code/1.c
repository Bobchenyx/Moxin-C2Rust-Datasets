int projectionArea(int** grid, int gridSize, int* gridColSize){
    int i,j,
        total = 0,
        frontmax = 0,
        *sidemax = calloc(*gridColSize,sizeof(int));

    for(i = 0; i < gridSize;i++){
        frontmax = 0;
        for(j = 0; j < *gridColSize;j++){
            total += (grid[i][j] > 0);
            if(grid[i][j] > frontmax){
                frontmax = grid[i][j];
            }
            if(grid[i][j] > sidemax[j]){
                sidemax[j] = grid[i][j];
            }            
        }
        total += frontmax;
    }

    for(i = 0; i < *gridColSize;i++){
        total += sidemax[i];
    }
    free(sidemax);
    return total;
}