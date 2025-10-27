int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    //入参检查
    if(grid == NULL)
    {
        return 0;
    }

    //循环遍历矩阵中的各元素
    int num = 0;
    for(int i=0; i<gridSize;i++)
    {
        for(int j =0;j<(*gridColSize);j++)
        {
            if(grid[i][j] <0)
            {
                num++;
            }
        }
    }
    return num;
}