int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i, j;
    int fresh_orange = 0, rotten_orange=0; // fresh_orange:新鲜橘子个数; rotten_orange:腐烂的个数
    int round;  // 2:已经腐烂; 3:第一轮腐烂, 4:第二轮腐烂, 5:第三轮腐烂, ...

    // 新鲜橘子个数
    for(i=0; i<gridSize; i++){
        for(j=0; j<gridColSize[i]; j++){
            if(grid[i][j] == 1){
                fresh_orange++;
            }
        }
    }

    // 按轮进行腐烂，第一轮round=3，第二轮round=4，...
    for(round=3; round-3 <= fresh_orange; round++){
        // 判断是否已经全部腐烂
        if(rotten_orange == fresh_orange){
            return round-3;
        }
        // 进行腐烂, 找出将要腐烂的橘子标记为round
        for(i=0; i<gridSize; i++){
            for(j=0; j<gridColSize[i]; j++){
                if(grid[i][j] == 1){
                    // 判断上、下、左、右是否有已经腐烂的橘子
                    if((i-1>=0 && grid[i-1][j]>=2 && grid[i-1][j]<round) || \
                    (i+1<gridSize && grid[i+1][j]>=2 && grid[i+1][j]<round) || \
                    (j-1>=0 && grid[i][j-1]>=2 && grid[i][j-1]<round) || \
                    (j+1<gridColSize[i] && grid[i][j+1]>=2 && grid[i][j+1]<round)){
                        grid[i][j] = round;
                        rotten_orange++;
                    }
                }
            }
        }
    }

    return -1;
}