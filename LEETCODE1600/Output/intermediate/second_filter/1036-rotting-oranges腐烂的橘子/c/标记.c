int flushArray(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    int i, j;

    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == 1){
                if((i-1 >= 0 && grid[i-1][j] == 2)||\
                (j-1 >= 0 && grid[i][j-1] == 2)||\
                (j+1 < gridColSize[0] && grid[i][j+1] == 2)||\
                (i+1 < gridSize && grid[i+1][j] == 2)){
                    grid[i][j] = 3;
                    count++;
                }
            }
        }
    }

    for(i = 0; i < gridSize; i++){
         for(j = 0; j < gridColSize[0]; j++){
             if(grid[i][j] == 3){
                grid[i][j] = 2;
             }
        }
    }

    return count;

}


int orangesRotting(int** grid, int gridSize, int* gridColSize){

    int i, j;
    int flag = 0;
    int count = 0;
    int time = 0;

    for(i = 0; i < gridSize; i++){
         for(j = 0; j < gridColSize[0]; j++){
             if(grid[i][j] == 2){
                flag++;
             }
             else if(grid[i][j] == 1){
                count++;
             }
        }
    }

    if(flag == 0){
        if(count == 0){
            return 0;
        }
        else{
            return -1;
        }
    }
        

    
    while(count > 0){
        i = 0;
        i = flushArray(grid, gridSize, gridColSize);
        count -= i;
        if(i == 0 && count > 0){
            return -1;
        }
        time++;
    }

    return time;

}