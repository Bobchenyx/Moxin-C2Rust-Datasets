#define MIN(a,b)    ((a) < (b) ? (a) : (b))

int surfaceArea(int** grid, int gridSize, int* gridColSize)
{
    int i, j;
    int sum = 0;
    int dup = 0;

    /* 统计总的立方体个数，然后减去重叠的面数量 */
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j ++) {
            /* 如果当前grid没有立方体，则不会有面积计算 */
            if (grid[i][j]) {
                // 统计总数
                sum += grid[i][j];

                // 统计自身重叠的面的数量
                dup += grid[i][j] ? (grid[i][j] - 1) : 0;

                // 每个grid都和自己的右侧、下侧相邻grid进行判断比较，计算最小的重叠面数量
                if (i + 1 < gridSize) {
                    dup += MIN(grid[i][j], grid[i + 1][j]);
                }
                if (j + 1 < gridSize) {
                    dup += MIN(grid[i][j], grid[i][j + 1]);
                }
            }
        }
    }

    return ((sum * 6) - (dup * 2));
}