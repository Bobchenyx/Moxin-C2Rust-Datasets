// BFS
#define MAX_LEN 100000
#define DIR 4
int dir[DIR+1] = {0,1, 0, -1, 0};
int **g_visited;
typedef struct {
    int x;
    int y;
}Node;
typedef struct {
    int tail;
    int top;
    Node node[MAX_LEN];
}Que;
void EnQue(Que *que, Node *node) {
    que->node[que->top] = *node;
    que->top++;
}
void DelQue(Que *que, Node *node) {
   *node = que->node[que->tail];
    que->tail++;
}
int  GetQue(Que *que) {
    return (que->top - que->tail);
}

void PrQue(Que *que) {
   int tail = que->tail;
   printf("\r\n que \r\n");
   while(tail != que->top) {
       printf("%3d,%3d     ",que->node[tail].x,que->node[tail++].y );
   }
}
Que g_que;
void BFS(char** grid, int row, int col, int x, int y) {
    Node delNode, enNode;
    int loop, i, j;

    enNode.x = x;
    enNode.y = y;
    EnQue(&g_que,&enNode);
    //PrQue(&g_que);
    while(GetQue(&g_que)) {
        DelQue(&g_que,&delNode);
        for(loop = 0; loop < DIR; loop++) {
            i = delNode.x + dir[loop];
            j = delNode.y + dir[loop + 1];
            if(i >= 0 && i <= row -1 && j >= 0 && j <= col - 1) {
                if(grid[i][j] == '1' && g_visited[i][j] == 0) {
                    enNode.x = i;
                    enNode.y = j;
                    EnQue(&g_que,&enNode);
                    g_visited[i][j] = 1;
                }
            }
        }
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rst = 0;
    int i, j;

    memset(&g_que, 0 ,sizeof(g_que));
    g_visited = calloc(gridSize, sizeof(int*));
    for(i = 0; i< gridSize; i++){
        g_visited[i] = calloc(gridColSize[0],sizeof(int));
    }

    for(i = 0; i < gridSize; i++) {
        for(j = 0; j< gridColSize[0]; j++) {
            if(grid[i][j] == '1' && g_visited[i][j] == 0) {
                BFS(grid, gridSize, gridColSize[0],i,j);
                rst++;
            }
        }
    }
    return rst;

}