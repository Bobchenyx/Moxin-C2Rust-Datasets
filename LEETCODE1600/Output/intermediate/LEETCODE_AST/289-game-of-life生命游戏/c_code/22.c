struct Direction {
    int x;
    int y;
};

struct Direction directions[8] = {
    {-1, -1},
    {0, -1},
    {1, -1},
    {-1, 0},
    {1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
};

int GetPointStatus(int x, int y, int** board, int boardSize, int* boardColSize) {
    int liveNum = 0;
    int deadNum = 0;
    int newX = 0;
    int newY = 0;
    for (int i = 0; i < 8; i++) {
        newX = x + directions[i].x;
        newY = y + directions[i].y;
        
        if (newX >= 0 && newX < boardSize && newY >= 0 && newY < boardColSize[0]) {
            printf("newX[%d] :: newY[%d]\n", newX, newY);
            if (board[newX][newY] == 1) {
                liveNum++;
            } else if (board[newX][newY] == 0) {
                deadNum++;
            }
        }
    }

    int ret = 0;
    if (board[x][y] == 1) {
        if (liveNum < 2) {
            ret = 0;
        } else if (liveNum == 2 || liveNum == 3) {
            ret = 1;
        } else if (liveNum > 3) {
            ret = 0;
        }
    } else {
        if (liveNum == 3) {
            ret = 1;
        }
    }

    return ret;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize <=0 || boardColSize == NULL || boardColSize[0] <= 0) {
        return;
    }

    printf("boardSize[%d]   boardColSize[%d] \n", boardSize, boardColSize[0]);

    int *newBoard = (int *)calloc(boardSize * boardColSize[0], sizeof(int));

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            newBoard[i * boardColSize[0] + j] = GetPointStatus(i, j, board, boardSize, boardColSize);
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            board[i][j] = newBoard[i * boardColSize[0] + j];
        }
    }

    return;
}