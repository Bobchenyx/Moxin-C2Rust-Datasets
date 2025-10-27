int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int good=0,bad=0,t=2,q=0;//t为坏橘子代号，q计算时间
    for(int i = 0; i < gridSize; i++)
        for(int j = 0; j < gridColSize[0]; j++)
        {
            if     (grid[i][j] == 1) good++;//记录好橘子数
            else if(grid[i][j] == 2) bad++; //记录坏橘子数
        }
    if(!good) return 0;
    if(!bad) return -1;
    int new_good = good;
    while(new_good) //直到好橘子数为零
    {
        q++;//时间加一
        for(int i = 0; i < gridSize; i++)
            for(int j = 0; j < gridColSize[0]; j++)
                if(grid[i][j] == t)//检查坏橘子四周
                {
                    if(i && grid[i - 1][j] == 1)                       {grid[i-1][j]   = t+1; new_good--;}
                    if(j && grid[i][j - 1] == 1)                       {grid[i]  [j-1] = t+1; new_good--;}
                    if(i != gridSize - 1 && grid[i + 1][j] == 1)    {grid[i+1][j]   = t+1; new_good--;}
                    if(j != gridColSize[0] - 1 && grid[i][j + 1] == 1){grid[i]  [j+1] = t+1; new_good--;}
                }
        t++;//坏橘子代号增一
        if(new_good == good) return -1;//没有新的橘子变坏
        good = new_good;//还剩的好橘子
    }
    return q;
}