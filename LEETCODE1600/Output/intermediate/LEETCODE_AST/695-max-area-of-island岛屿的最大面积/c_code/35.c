int check(int x,int y,int** grid,int gridSize,int* gridColSize){
    int next_step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int i;
    int sum=1;
    for(i=0;i<4;i++){
        int next_x=x+next_step[i][0];
        int next_y=y+next_step[i][1];
        if(next_x>=0&&next_x<gridSize&&next_y>=0&&next_y<gridColSize[x]&&grid[next_x][next_y]==1){
            grid[next_x][next_y]=-1;
            sum+=check(next_x,next_y,grid,gridSize,gridColSize);
        }
    }
    return sum;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i,j,num=0,sum=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                grid[i][j]=-1;
                num=check(i,j,grid,gridSize,gridColSize);
                if(num>sum){
                    sum=num;
                }
            }
        }
    }
    return sum;
}