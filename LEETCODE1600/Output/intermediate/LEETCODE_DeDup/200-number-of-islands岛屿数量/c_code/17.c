//递归DFS
void DFS(char** grid, int gridSize, int* gridColSize,int x,int y)
{
    grid[x][y]='0';
    //for direction
    int dir_y[4]={0,0,-1,1};//横列竖行
    int dir_x[4]={-1,1,0,0};
    int i;
    
    int new_x,new_y;
    for(i=0;i<4;i++)
    {
        new_x=x+dir_x[i];
        new_y=y+dir_y[i];
        if((new_x>=0&&new_x<gridSize)&&(new_y>=0&&new_y<*gridColSize))//在网格之内
        {
            if(grid[new_x][new_y]=='1')
            {
                DFS(grid,gridSize,gridColSize,new_x,new_y);
            }
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j;
    int count=0;
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++)
        if(grid[i][j]=='1')
        {
            count++;
            DFS(grid,gridSize,gridColSize,i,j);
        }
    return count;
}