int countNegatives(int** grid, int gridSize, int* gridColSize){
    int sum=0;
    int i;
    for(i=0;i<gridSize;++i)
    {
        int j;
        for(j=0;j<*gridColSize;++j)
            if(grid[i][j]>=0)
            ++sum;
    }
    return gridSize**gridColSize-sum;
}