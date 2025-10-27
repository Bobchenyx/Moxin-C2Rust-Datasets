int dfs(int **grid, int i, int j,int gridSize, int* gridColSize){
    int sum = 1;
    grid[i][j] = 0;
    if(i-1 >= 0 && grid[i-1][j] == 1){
        //grid[i-1][j] = 0;
        sum += dfs(grid,i-1,j,gridSize,gridColSize);
    }

    if(i+1 < gridSize && grid[i+1][j] == 1){
       // grid[i+1][j] = 0;
        sum += dfs(grid,i+1,j,gridSize,gridColSize);
    }

    if(j-1 >= 0 && grid[i][j-1] == 1){
       // grid[i][j-1] = 0;
        sum += dfs(grid,i,j-1,gridSize,gridColSize);
    }
    
    if(j+1 < gridColSize[0] && grid[i][j+1] == 1){
       // grid[i][j+1] = 0;
        sum += dfs(grid,i,j+1,gridSize,gridColSize);
    }
    return sum;
}



int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i, j;
    int max = 0,sum=0;
    //int res[50][50] = {0};
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            if(grid[i][j] == 1){
                grid[i][j] == 0;
                
                sum = dfs(grid,i,j,gridSize,gridColSize);
                if(max < sum)  max =sum;
                sum = 0;
            }
        }
    }

    return max;
}