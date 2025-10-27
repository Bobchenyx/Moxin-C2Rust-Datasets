void dfs(char **grid, int gridSize, int* gridColSize, int i, int j){
    grid[i][j] = '0';
    if((i - 1) >= 0 && grid[i-1][j]=='1') {
        //这个改成0可以统一方向递归入口做，否则多处修改还是容易出问题
        //grid[i-1][j] = '0';
        dfs(grid, gridSize, gridColSize, i -1,j);
    }
    /*这里是数组， 所以这里要<，不能<=,否则下面数组越界了*/
    if((i + 1) < gridSize && grid[i+1][j]=='1') {
        //grid[i+1][j] = '0';
        dfs(grid, gridSize, gridColSize, i + 1,j);
    }
    if((j - 1) >= 0 && grid[i][j-1]=='1') {
        //grid[i][j-1] = '0';
        dfs(grid, gridSize, gridColSize, i ,j -1);
    }

    if((j + 1) < gridColSize[i] && grid[i][j+1]=='1') {
        //grid[i][j+1] = '0';
        dfs(grid, gridSize, gridColSize, i, j+1);
    }
}


/*这个 gridSize 是行数意思，  *gridColSize貌似是每行对应的列数*/
int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j,col,row;
    int cnt=0;

    col = *gridColSize;
    row = gridSize;
   // printf("grid=%d colzie=%d\n", gridSize, *gridColSize);
    for(i=0;i< row; i++) {
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j] == '1'){
                dfs(grid, gridSize, gridColSize, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}