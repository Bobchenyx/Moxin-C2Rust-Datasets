/*
 * (*gridColSize)是列数，为什么要使用指针？
 */
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    // 初始化队列
    int queue[gridSize * (*gridColSize)][2];
    int head = 0, rear = 0;
    // 寻找所有初值为2的点，入队
    for(int i = 0; i < gridSize; ++i)
    for(int j = 0; j < *gridColSize; ++j)
        if(grid[i][j] == 2) {
            queue[rear][0] = i;
            queue[rear][1] = j;
            rear++;
        }
    // 时间
    int time = 0;
    // 记录每次感染后队尾位置
    int pos = rear;
    // 开始遍历，队空时说明遍历完毕
    while(head != rear) {
        // head == pos说明一遍感染完毕
        if(head == pos) {
            pos = rear;
            time++;
        }
        // 队头出队
        int row = queue[head][0];
        int col = queue[head][1];
        head++;
        // 判断四个方向是否有好橘子，有则入队，值改为2
        if(row-1 >= 0 && grid[row-1][col] == 1) {   // 上
            grid[row-1][col] = 2;
            // 入队
            queue[rear][0] = row-1;
            queue[rear][1] = col;
            rear++;
        }
        if(row+1 < gridSize && grid[row+1][col] == 1) { // 下
            grid[row+1][col] = 2;
            queue[rear][0] = row+1;
            queue[rear][1] = col;
            rear++;
        }
        if(col-1 >= 0 && grid[row][col-1] == 1) {   // 左
            grid[row][col-1] = 2;
            queue[rear][0] = row;
            queue[rear][1] = col-1;
            rear++;
        }
        if(col+1 < *gridColSize && grid[row][col+1] == 1) { // 右
            grid[row][col+1] = 2;
            queue[rear][0] = row;
            queue[rear][1] = col+1;
            rear++;
        }
    }
    // 查看是否还有好橘子，有返回-1，没有返回time
    for(int i = 0; i < gridSize; ++i)
    for(int j = 0; j < *gridColSize; ++j)
        if(grid[i][j] == 1)
            return -1;
    return time;
}