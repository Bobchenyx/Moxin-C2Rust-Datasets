void DFS(int i,int j,char** grid,int m,int n,int sign[][n]){
    sign[i][j] = 1;
    if(i-1>=0 && sign[i-1][j]==0 && grid[i-1][j]=='1'){
        DFS(i-1,j,grid,m,n,sign);
    }   
    if(i+1<m && sign[i+1][j]==0 && grid[i+1][j]=='1'){
        DFS(i+1,j,grid,m,n,sign);
    }
    if(j>0 && sign[i][j-1]==0 && grid[i][j-1]=='1'){
        DFS(i,j-1,grid,m,n,sign);
    }
    if(j+1<n && sign[i][j+1]==0 && grid[i][j+1]=='1'){
        DFS(i,j+1,grid,m,n,sign);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize < 1){
        return 0;
    }
    int sign[gridSize][gridColSize[0]];
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            sign[i][j] = 0;
        }
    }
    int result = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(sign[i][j]==0 && grid[i][j] == '1'){
                result++;
                DFS(i,j,grid,gridSize,gridColSize[0],sign);
            }
        }
    }
    return result;
}