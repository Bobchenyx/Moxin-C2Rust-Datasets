void dfs(char**grid,int i,int j,int m,int n){
    if(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]=='1')
    grid[i][j]='0';
    else
    return;
    dfs(grid,i-1,j,m,n);
    dfs(grid,i,j+1,m,n);
    dfs(grid,i+1,j,m,n);
    dfs(grid,i,j-1,m,n);
}
int numIslands(char** grid, int gridSize, int* gridColSize){
int i,j,count=0;
if(grid==NULL||gridSize==0||gridColSize==NULL)
return 0;
int colsize=gridColSize[0];
for(i=0;i<gridSize;i++){
    for(j=0;j<colsize;j++){
        if(grid[i][j]=='1'){
            dfs(grid,i,j,gridSize,colsize);
            count++;
        }
    }
}
return count;
}