int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int area=0;
    int row = gridSize,col = *gridColSize;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j] == 0)
                continue;
            else
            {
                int v=grid[i][j];
                int up =0,right = 0;
                if(i-1>=0&&grid[i-1][j])
                    up=grid[i-1][j]<=v?grid[i-1][j]:v;
                if(j+1<col&&grid[i][j+1])
                    right=grid[i][j+1]<=v?grid[i][j+1]:v;
                 area+=4*v+2-up*2-right*2;
            }
        }
    }
    return area;
}