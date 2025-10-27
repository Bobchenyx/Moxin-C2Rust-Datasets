int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i; //按行遍历
    int j; //按列遍历
    int cnt=0;
    int cntValid=0;
    

    //1.求出总的有效的格子数
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<*gridColSize;j++)
        {
            if(grid[i][j]==1)
                cntValid++;
        }
    }

    //2.从左到右按行确定相邻的边
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<*gridColSize-1;j++)  //注意：最后一列不用看了
        {
            if(grid[i][j]==0)
                continue;          //如果是0，就不用管了，  
            if(grid[i][j+1]==0)    //如果这个格不是0，但它的下一个是0，不用管了
            {
                    j++;           //这样直接经过本次循环j=j+2，减少了判断次数
                    continue;
            }
            else
                cnt++;             //都是0的话，那么

        }
    }

    //3.从上到下按列确定相邻的边
    for(j=0;j<*gridColSize;j++)
    {
         for(i=0;i<gridSize-1;i++)
        {
            if(grid[i][j]==0)
                continue;
            if(grid[i+1][j]==0)
            {
                i++;
                continue;
            }
            else
                cnt++;
        }
    }

    return cntValid*4-cnt*2;
}