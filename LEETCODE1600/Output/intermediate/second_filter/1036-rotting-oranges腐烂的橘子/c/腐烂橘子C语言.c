int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int timeCount = 0;
    int mark = 0;
    do{
        mark = 0;
        for(i=0;i<gridSize;i++){
            for(j=0;j<gridColSize[i];j++){
                if(grid[i][j]==2){
                    if(i-1>=0 && grid[i-1][j]==1) //上
                    {
                        grid[i-1][j] = 3;
                        mark = 1;
                    }
                    if(j-1>=0 && grid[i][j-1]==1)//左
                    {
                        grid[i][j-1] = 3;
                        mark = 1;
                    }
                    if(i+1<gridSize && grid[i+1][j]==1){//下
                        grid[i+1][j] = 3;
                        mark = 1;
                    }
                    if(j+1<gridColSize[i] && grid[i][j+1]==1){//右
                        grid[i][j+1] = 3;
                        mark = 1;
                    }
                }
            }
        }

        for(i=0;i<gridSize;i++){
            for(j=0;j<gridColSize[i];j++){
                if(grid[i][j]==3)
                    grid[i][j] = 2;
            }
        }
        timeCount++;
    }while(mark==1);

    for(i=0;i<gridSize;i++){//检查是否有橘子不可能被感染
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1)
                return -1;
        }
    }

    return timeCount-1;//因为do while会多跑一次
}