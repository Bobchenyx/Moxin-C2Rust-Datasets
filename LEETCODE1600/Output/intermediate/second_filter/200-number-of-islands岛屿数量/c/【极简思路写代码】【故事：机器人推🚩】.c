/* 检查地图上时候还有旗子（grid[y][x] == '1'），若有，则找到旗子，返回旗子的位置 */
bool check(char** grid, int gridSize, int* gridColSize, int* xRet, int* yRet) {
    for (int y = 0; y < gridSize; y++) {
        for (int x = 0; x < gridColSize[y]; x++) {
            if (grid[y][x] == '1') {
                *yRet = y;
                *xRet = x;
                return true;
            }
        }
    }
    return false;
}

/* 从上下左右四个维度尽可能的推倒所有旗子 */
void clearFlag(char** grid, int gridSize, int* gridColSize, int x, int y) {
    if (grid[y][x] == '0') { // 此处旗子如果已经推倒，则不做任何操作
        return;
    }       
    grid[y][x] = '0'; // 推倒旗子
    if (y - 1 >= 0) {
        clearFlag(grid, gridSize, gridColSize, x, y - 1); // 向上推倒下一个
    }
    if (x - 1 >= 0) {
        clearFlag(grid, gridSize, gridColSize, x - 1, y); // 向左推倒下一个
    }
    if (y + 1 < gridSize) {
        clearFlag(grid, gridSize, gridColSize, x, y + 1); // 向下推倒下一个
    }
    if (x + 1 < gridColSize[y]) {
        clearFlag(grid, gridSize, gridColSize, x + 1, y); // 向右推倒下一个
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    int x, y;
    while (check(grid, gridSize, gridColSize, &x, &y)) {
        clearFlag(grid, gridSize, gridColSize, x, y);
        ans++;
    }
    return ans;
}