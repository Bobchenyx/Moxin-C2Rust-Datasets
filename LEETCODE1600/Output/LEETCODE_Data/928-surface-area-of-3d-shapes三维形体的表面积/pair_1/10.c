int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int res = 0;
    int tmp;
    for(i = 0; i < gridSize;i++) {
        for(j=0;j< * gridColSize;j++) {
            if(grid[i][j]!=0) {
                res += 6 * grid[i][j];
                res = res - 2*(grid[i][j]-1); // 下面 
                // 比如3块摞在一起，则其中有2个夹层，则减去2*(3-1)
                
                if(i>0){  // 左面  若有左邻居，则减去双方较矮的面*2
                    tmp = grid[i-1][j]>grid[i][j]? grid[i][j]:grid[i-1][j];
                    res = res - 2*tmp;
                }
                
                if(j>0){ // 前面 若有前邻居，则减去双方较矮的面*2
                    tmp = grid[i][j-1]>grid[i][j]? grid[i][j]:grid[i][j-1];
                    res = res - 2*tmp;
                }             
            }
        }
            
    }
    return res;
}