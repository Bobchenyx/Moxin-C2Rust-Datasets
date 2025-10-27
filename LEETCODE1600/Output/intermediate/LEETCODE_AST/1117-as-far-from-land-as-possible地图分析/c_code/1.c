typedef struct {
    int x;
    int y;
    int lev;
} Node;

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    Node *queue = (Node *)malloc(sizeof(Node) * gridSize * gridColSize[0]);
    int front = 0;
    int tail = 0;
    int res = 0;
    
    // 陆地先入队
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                queue[tail].x = i;
                queue[tail].y = j;
                queue[tail++].lev = 0;
            }
        }
    }
    // 如果全是陆地或者全是海洋，返回-1
    if (tail == front || tail == gridSize * gridColSize[0]) {
        return -1;
    }
    
    while (front < tail) {
        int x = queue[front].x;
        int y = queue[front].y;
        res = queue[front].lev;
        front++;
        
        for (int i = 0; i < 4; i++) {
            int xx = x + direction[i][0];
            int yy = y + direction[i][1];
            if (xx < 0 || xx >= gridSize || yy < 0 || yy >= gridColSize[0] || grid[xx][yy] == 1){
                continue;
            }
            grid[xx][yy] = 1;
            queue[tail].x = xx;
            queue[tail].y = yy;
            queue[tail].lev = res + 1;
            tail++;
        }
    }
    return res;
    
    
}