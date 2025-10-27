int min(a,b){
    return a>b?b:a;
}
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j]==0)
                continue;
            count+=4*grid[i][j]+2;
            //如果不是第一行，减去和上一行两者之间小的那个*2
            if(i!=0)
                count-=(2*min(grid[i-1][j],grid[i][j]));
            //如果不是第一列，减去和左一列两者之间小的那个*2   
            if(j!=0)
                count-=2*min(grid[i][j-1],grid[i][j]);
        }
    }
    return count;
}