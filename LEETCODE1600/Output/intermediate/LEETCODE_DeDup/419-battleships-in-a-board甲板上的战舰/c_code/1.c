int countBattleships(char** board, int boardSize, int* boardColSize){
    int ret = 0;
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < *boardColSize; j++) {
            if(board[i][j] == 'X') {
                ret++;
                board[i][j] = 'B';
                m = j + 1;
                while(m < *boardColSize && board[i][m] == 'X' ) {
                    board[i][m] = 'B';
                    m++;
                } 
                 n = i + 1;
                 while( n < boardSize && board[n][j] == 'X') {
                     board[n][j] = 'B';
                     n++;
                }
            }
        }
    }
#if 0
    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < *boardColSize; j++) {
            if(board[i][j] == '.') {
                printf(".");
            }
            else {
                printf("%d",board[i][j]);
            }
        }
        printf("\n");
    }
#endif
    return ret;

}