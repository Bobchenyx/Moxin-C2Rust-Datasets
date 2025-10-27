typedef struct tagPOS_S {
    int x;
    int y;
    int dist;
}POS_S;

int GetSeaCnt(int** grid, int gridSize, int* gridColSize){
    int i,j,cnt = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0) {
                cnt++;
            }
        }
    }

    return cnt;
}

void initSeaInfo(int** grid, int gridSize, int* gridColSize, int *sea, int seaCnt) {
    int i, j, n = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0 && n < seaCnt) {
                sea[i * gridSize + j] = -1;
                n++;
            }
        }
    }

    return;
}

int g_MaxDis = -1;
int g_x = -1;
int g_y = -1;

void bfs(int** grid, int gridSize, int* gridColSize, POS_S *curPos, int curCnt, int *sea, POS_S *nextPos) {

    /* 查找一步范围内的海域，更新他们的dist */
    int i, j, c;
    int dDist[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dX, dY, x, y;
    int nextCnt = 0;
    //printf("....curCnt = %d \n", curCnt);
    for (c = 0; c < curCnt; c++) {
        for (i = 0; i < 4; i++) {
            int curDist = curPos[c].dist + 1;
            dX = dDist[i][0];
            dY = dDist[i][1];
            x = curPos[c].x;
            y = curPos[c].y;
            if (!((0 <= x + dX && x + dX <= gridSize -1) && (0 <= y + dY && y + dY <= gridColSize[x + dX] - 1))) {
                continue;
            }
            //printf("%d %d\n", x + dX, y + dY);
            if (grid[x + dX][y + dY] == 1) {
                continue;
            }

            if (sea[(x + dX) * gridSize + (y + dY)] == -1 || sea[(x + dX) * gridSize + (y + dY)] > curDist) {
                sea[(x + dX) * gridSize + (y + dY)] = curDist;
            } else {
                continue;
            }

            nextPos[nextCnt].x = x + dX;
            nextPos[nextCnt].y = y + dY;
            nextPos[nextCnt].dist = curDist;
            nextCnt++;
            //printf("nextCnt = %d \n", nextCnt);
        }
    }
    
    if (nextCnt == 0) {
        return;
    }
    //printf("bfs\n");
    /* 如果存在一步范围内的海域，则再扩散一步继续查找 */
    bfs(grid, gridSize, gridColSize, nextPos, nextCnt, sea, curPos);

    return;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return -1;
    }

    if (gridSize == 1) {
        return -1;
    }
    
    int seaCnt = GetSeaCnt(grid, gridSize, gridColSize);
    if (seaCnt == 0 || seaCnt == gridSize * gridColSize[gridSize - 1]) {
        return -1;
    }

    /* 所有的海洋用数组存一下：坐标、最小距离 */
    int *sea = (int *)malloc(sizeof(int) * gridSize * gridColSize[gridSize - 1]);
    if (sea == NULL) {
        return -1;
    }
    initSeaInfo(grid, gridSize, gridColSize, sea, gridSize * gridColSize[gridSize - 1]);

    /* 遍历找陆地，然后BFS方法更新附近海洋距离陆地的最小距离。更新最小距离最大的海洋坐标。 */
    int i,j, curCnt, nextCnt;
    POS_S *curLand = (POS_S *)malloc(sizeof(POS_S) * gridSize * gridColSize[gridSize - 1]);
    if (curLand == NULL) {
        free(sea);
        return -1;
    }

    POS_S *nextLand = (POS_S *)malloc(sizeof(POS_S) * gridSize * gridColSize[gridSize - 1]);
    if (nextLand == NULL) {
        free(sea);
        free(curLand);
        return -1;
    }
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                curLand[0].x = i;
                curLand[0].y = j;
                curLand[0].dist = 0;
                curCnt = 1;
                bfs(grid, gridSize, gridColSize, curLand, curCnt, sea, nextLand);
            }
        }
    }

    int maxDist = -1;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0) { 
                maxDist = maxDist >= sea[i * gridSize + j] ? maxDist : sea[i * gridSize + j];
            }
        }
    }

    free(nextLand);
    free(curLand);
    free(sea);
    
    return maxDist;
}