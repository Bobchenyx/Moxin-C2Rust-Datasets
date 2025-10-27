int abs(int n)
{
    return n>0?n:0-n;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){
   
    // for(int i=0;i<gridSize;i++)
    // {
    //     for(int j=0;j<*gridColSize;j++)
    //     {
    //         printf("%d ",grid[i][j]);
    //     }
    //     printf("\n");
    // }
   
    int side1=0;
    int bottom=0;
    
    for(int i=0;i<gridSize;i++)
    {
        side1+=grid[i][0];
        bottom+=grid[i][0]>0?1:0;
        for(int j=1;j<*gridColSize;j++)
        {
            bottom+=grid[i][j]>0?1:0;
            side1+=abs(grid[i][j]-grid[i][j-1]);
        }
        side1+=grid[i][*gridColSize-1];
    }
    
    int side2=0;
    for(int i=0;i<*gridColSize;i++)
    {
        side2+=grid[0][i];
        for(int j=1;j<gridSize;j++)
        {
            side2+=abs(grid[j][i]-grid[j-1][i]);
        }
        side2+=grid[gridSize-1][i];
    }
   // printf("s1=%d s2=%d b=%d ",side1,side2,bottom);
    return side2+side1+bottom*2;
}