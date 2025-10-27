#define Min(a,b) ((a)<(b)?(a):(b))
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int sum=0;
    int i,j;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridSize;j++){
            if(grid[i][j]!=0){
                sum+=grid[i][j]*6-(grid[i][j]-1)*2;
            }
            if(i<gridSize-1&&j<gridSize-1){
                sum-=Min(grid[i][j+1],grid[i][j])*2;
                sum-=Min(grid[i][j],grid[i+1][j])*2;
            }
        }
    }
    for(i=0;i<gridSize-1;i++){
        sum-=Min(grid[gridSize-1][i],grid[gridSize-1][i+1])*2;
    }
    for(i=0;i<gridSize-1;i++){
        sum-=Min(grid[i][gridSize-1],grid[i+1][gridSize-1])*2;
    }
    return sum;
}