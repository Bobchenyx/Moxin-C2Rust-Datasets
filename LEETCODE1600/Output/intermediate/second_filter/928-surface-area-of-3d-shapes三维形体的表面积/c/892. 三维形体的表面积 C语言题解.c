int surfaceArea(int** grid, int gridSize, int* gridColSize)
{
    int ret=0;
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<*gridColSize;j++)
        {
            if(grid[i][j]>0) //给出的测试数据有数值为0的情况，这个时候直接跳过数据就好了。
            {
                ret+=(grid[i][j]<<2)+2;
                if(j>0)
                {
                    ret-=grid[i][j-1]>grid[i][j]?grid[i][j]*2:grid[i][j-1]*2;
                }
                if(i>0)
                {
                    ret-=grid[i-1][j]>grid[i][j]?grid[i][j]*2:grid[i-1][j]*2;
                }
            }       
            //printf("grid[%d][%d]=%d ret=%d ",i,j,grid[i][j],ret);
        }
    }
    //printf("\n");

    return ret;
}