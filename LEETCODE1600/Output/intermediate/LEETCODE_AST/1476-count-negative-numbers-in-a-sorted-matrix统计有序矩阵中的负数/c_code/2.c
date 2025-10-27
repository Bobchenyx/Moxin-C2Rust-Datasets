int countNegatives(int** grid, int gridSize, int* gridColSize){
    int sum = 0;
    int columnK = gridColSize[0];
    int height = 0;

    while (columnK) {
        height = 0;
        while ((grid[height][columnK - 1] >= 0)) {
            height++;  // 往下一直走，直到遇到负数
            if (height >= gridSize) {
                break;
            }
        }
        if (height < gridSize) {  // 往下还没有走到底，说明确实遇到了负数，计算并往左走
            sum += (gridSize - height);
        }
        columnK--;
    }
    return sum;
}