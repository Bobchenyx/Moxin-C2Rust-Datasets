#define FINDMIN(x,y) (x<y)?x:y

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int sum = 0;
    int sub = 0;
    int i,j,m;
    
    //统计所有正方形的所有面之和
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[0];j++)
        {
            sum += grid[i][j] * 6;
        }
    }

    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[0];j++)
        {
            m = grid[i][j];
            if(m)
            {
                //寻找同一层上下立方体重叠的面
                
                sub += 2*(m-1);
                if(i+1 < gridSize)
                    sub =sub + 2*(FINDMIN(m,grid[i+1][j]));
                if(j+1<gridColSize[0])
                    sub =sub + 2*(FINDMIN(m,grid[i][j+1]));
            }
        }
    }

    return sum - sub;
}