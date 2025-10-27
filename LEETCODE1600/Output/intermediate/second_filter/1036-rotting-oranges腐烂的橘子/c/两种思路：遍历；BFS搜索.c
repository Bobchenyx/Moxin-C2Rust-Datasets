typedef struct myListNode {
    int x;
    int y;
    int level;
    struct myListNode *next;
} MYLISTNODE;

void enQue(MYLISTNODE **qtail, int x, int y, int l) {
    MYLISTNODE *node = (MYLISTNODE*)malloc(sizeof(MYLISTNODE));
    MYLISTNODE *que = *qtail;

    node->x = x;
    node->y = y;
    node->level = l;
    node->next = NULL;

    if (que) {
        que->next = node;
    }
    *qtail = node;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i;
    int j;
    int level = 0;

    MYLISTNODE *que = NULL;
    MYLISTNODE *last = NULL;

    for (i=0; i<gridSize; i++) {
        for (j=0; j<gridColSize[0]; j++) {
            if (grid[i][j] == 2) {
                enQue(&last, j, i, level);
                if (!que) que=last;
            }
        }
    }

    int x[] = {-1, 0, 1, 0};
    int y[] = {0, -1, 0, 1};

    while (que) {
        if (que->level != level) level++;

        int i;
        for (i=0; i<sizeof(x)/sizeof(x[0]); i++) {
            int tmpx = que->x + x[i];
            int tmpy = que->y + y[i];

            if (tmpx < 0 || tmpx >= gridColSize[0] || tmpy < 0 || tmpy >= gridSize) continue;

            if (grid[tmpy][tmpx] == 1) {
                enQue(&last, tmpx, tmpy, level+1);
                grid[tmpy][tmpx] = 2;
            }
        }
        que = que->next;

    }

    for (i=0; i<gridSize; i++) {
        for (j=0; j<gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return level;
}