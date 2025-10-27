int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int v = 0,a = 0;
    int area = 0;

    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < gridColSize[i]; j++)
        {
            v = grid[i][j];
            if(v > 0)
            {
                a = 6 * v - 2 * (v - 1);
            if(j - 1 >= 0)
            {
                if(grid[i][j-1] <= v) a = a - grid[i][j-1];
                else a = a - v;
            }
            if(i - 1 >= 0)
            {
                if(grid[i-1][j] <= v) a = a - grid[i-1][j];
                else a = a - v;
            }
            if(j + 1 < gridColSize[i])
            {
                if(grid[i][j+1] <= v) a = a - grid[i][j+1];
                else a = a - v;
            }
            if(i + 1 <gridSize)
            {
                if(grid[i+1][j] <= v) a = a - grid[i+1][j];
                else a = a - v;
            }
            area += a;
            }
            
        }
    }

    return area;
}