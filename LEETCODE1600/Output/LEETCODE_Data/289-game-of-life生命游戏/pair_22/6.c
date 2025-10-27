void gameOfLife(int** board, int boardSize, int* boardColSize){
    if ( !boardColSize[0] ||  !boardSize) {
        return ;
    }
    int row[ boardSize * (*boardColSize) ];//行
    int col[ boardSize * (*boardColSize) ];//列
    int amount = 0;//记录有多少个1
    for ( int i = 0 ; i < boardSize ; i++ ) {
        for ( int j = 0 ; j < (*boardColSize) ; j++ ) {
            int num = 0;
            if ( (i - 1) >= 0 && (j - 1) >= 0 ) {//1
                if ( board[i - 1][j - 1] == 1 ) {
                    num++;
                }
            }
            if ( (i - 1) >= 0 ) {//2
                if ( board[i - 1][j] == 1 ) {
                    num++;
                }
            }
            if ( (i - 1) >= 0 && (j + 1) < (*boardColSize) ) {//3
                if ( board[i - 1][j + 1] == 1 ) {
                    num++;
                }
            }
            if ( (j - 1) >= 0 ) {//4
                if ( board[i][j - 1] == 1 ) {
                    num++;
                }
            }
            if ( (j + 1) < (*boardColSize) ) {//6
                if ( board[i][j + 1] == 1 ) {
                    num++;
                }
            }
            if ( (i + 1) < boardSize && (j - 1) >= 0 ) {//7
                if ( board[i + 1][j - 1] == 1 ) {
                    num++;
                }
            }
            if ( (i + 1) < boardSize ) {//8
                if ( board[i + 1][j] == 1 ) {
                    num++;
                }
            }
            if ( (i + 1) < boardSize && (j + 1) < (*boardColSize) ) {//9
                if ( board[i + 1][j + 1] == 1 ) {
                    num++;
                }
            }
            if ( board[i][j] == 0 ) {
                if ( num == 3 ) {
                    row[amount] = i;
                    col[amount] = j;
                    amount++;
                }
            }
            if ( board[i][j] == 1 ) {
                if ( num >= 2 && num <= 3 ) {
                    row[amount] = i;
                    col[amount] = j;
                    amount++;
                }
            }
        }
    }
    for ( int k = 0 ; k < boardSize ; k++ ) {
        for ( int l = 0 ; l < (*boardColSize) ; l++ ) {
            board[k][l] = 0;
        }
    }

    for ( int m = 0 ; m < amount ; m++ ) {
        board[ row[m] ][ col[m] ] = 1;
    }
}