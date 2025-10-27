int maxDistance(int** grid, int gridSize, int* gridColSize) {
    typedef unsigned short u16;
#define POP(x,y)     \
    do {                \
        *x=queue[dequeue]>>8;  \
        *y=queue[dequeue++]&(~0xFF00);\
    } while(0)
#define PUSH(x,y) queue[enqueue++]=(x)<<8|(y)
    int enqueue = 0, dequeue = 0;
    u16 *queue = (u16*)malloc(gridSize*gridSize * 2);
    for (u16 i = 0; i < gridSize;i++) {
        for (int j = 0; j < gridSize;j++) {
            if (grid[i][j])PUSH(i, j);
        }
    }
    if (enqueue == 0 || enqueue == gridSize*gridSize)return -1;
    int dx[] = { 1,0,-1,0 };
    int dy[] = { 0,1,0,-1 };
    int level=-1;
    while (dequeue < enqueue) {
        level++;
        int curr_enqueue = enqueue;
        for (int i = dequeue; i < curr_enqueue; i++) {
            u16 x, y;
            POP(&x, &y);
            for (int j = 0; j < 4;j++) {
                int cx = x + dx[j];
                int cy = y + dy[j];
                if (cx < 0 || cy < 0 || cx >= gridSize || cy >= gridSize || grid[cx][cy])continue;
                PUSH(cx, cy);
                grid[cx][cy] = 2;
            }
        }
    }
    return level;
}