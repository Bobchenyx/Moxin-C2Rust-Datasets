#define min(a,b) a>b?b:a
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    if(gridSize==0) return 0;
    int i,j,surface=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==0) continue;
            surface=6*grid[i][j]-2*(grid[i][j]-1)+surface;
            if(i>0) surface-=min(grid[i-1][j],grid[i][j]);
            if(j>0) surface-=min(grid[i][j-1],grid[i][j]);
            if(i<gridSize-1) surface-=min(grid[i+1][j],grid[i][j]);
            if(j<gridColSize[i]-1) surface-=min(grid[i][j+1],grid[i][j]);
        }
    }
    return surface;
}