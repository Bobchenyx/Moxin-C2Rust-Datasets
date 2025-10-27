int min(int a, int b){
    return a<b?a:b;
}
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int all = 0;
    int more = 0;
    for(i = 0;i < gridSize;i++){
        for(j = 0;j < gridColSize[i];j++){
            all +=grid[i][j];
            if(grid[i][j]>0){
                more+=(grid[i][j]-1)*2;
            }
            if(i-1>=0){
                more+=min(grid[i-1][j],grid[i][j]);
            }
            if(i+1<gridSize){
                more+=min(grid[i+1][j],grid[i][j]);
            }
            if(j-1>=0){
                more+=min(grid[i][j-1],grid[i][j]);
            }
            if(j+1<gridColSize[i]){
                more+=min(grid[i][j+1],grid[i][j]);
            }
        }
    }
    return all*6-more;
}