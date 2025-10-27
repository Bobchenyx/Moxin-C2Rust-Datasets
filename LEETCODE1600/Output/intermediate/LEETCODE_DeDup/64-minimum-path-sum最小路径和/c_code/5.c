// Solution 1: DFS recursively
// i: 现在到哪一行了（取值范围是列的长度）
// j: 现在到哪一列了（取值范围是行的长度）
int dfs(int** grid, int j, int i, int cur, int min, int rowLength, int columnLength) {
    // 没走到一个格子内，要加上这个格子的值，即经过此格子，路程要加多少
    cur += grid[i][j];
    // 递归返回条件：走到最后（最右下角）一个格子的时候
    if (j == rowLength - 1 && i == columnLength - 1) {
        // 如果min = -1（第一次走到最后一个格子），把当前次的路程的和（cur）赋值给min
        // 或
        // 其他次走到最后一个格子，把当前次的路程和（cur）与之前的min比较，如果比min小，则赋值给min
        min = (min == -1 || cur < min) ? cur : min;
        // 返回最小值
        return min;
    }
    // 如果没到最后一列，就继续往右面格子递归
    if (j < rowLength - 1) min = dfs(grid, j + 1, i, cur, min, rowLength, columnLength);
    // 如果没到最后一行，就继续往下面格子递归
    if (i < columnLength - 1) min = dfs(grid, j, i + 1, cur, min, rowLength, columnLength);
    return min;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    // 记录当前值
    int cur = 0;
    // 记录全局最小值
    int min = -1;
    // 以递归形式进行DFS搜索
    return dfs(grid, 0, 0, cur, min, *gridColSize, gridSize);
}