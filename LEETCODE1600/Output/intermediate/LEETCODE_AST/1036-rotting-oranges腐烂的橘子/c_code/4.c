int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i,j,flag=1,tmp=0;
    while(flag==1)
    {
        flag=0;
        for(i=0;i<gridSize;i++){
            for(j=0;j<*gridColSize;j++){
                if(grid[i][j]==2){
                    if(i+1<gridSize&&grid[i+1][j]==1){
                        grid[i+1][j]=-1;
                        flag=1;
                    }
                    if(j+1<*gridColSize&&grid[i][j+1]==1){
                        grid[i][j+1]=-1;
                        flag=1;
                    }
                    if(i-1>=0&&grid[i-1][j]==1){
                        grid[i-1][j]=-1;
                        flag=1;
                    }
                    if(j-1>=0&&grid[i][j-1]==1){
                        grid[i][j-1]=-1;
                        flag=1;
                    }
                }
            }
        }
        for(i=0;i<gridSize;i++){
            for(j=0;j<*gridColSize;j++){
                if(grid[i][j]==-1) grid[i][j]=2;
            }
        }
        if(flag==1) tmp++;
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<*gridColSize;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    return tmp;
}