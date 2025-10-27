int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int rook1, rook2;
    int black = 0;
    int sum = 0;
    int i, j;
    for(i = 0; i < boardSize; i++) {
        for(j = 0; j < boardSize; j++) {
            if(board[i][j] == 'R' || board[i][j] == 'r') {
                rook1 = i;
                rook2 = j;
                black = board[i][j] == 'R' ? 1 : 2;
                break;
            }
        }
    }

    if(black == 1) {
        for(j = rook2 + 1; j < boardSize; j++) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'p') {
                sum++;
                break;
            } else {
                break;
            }
        }
        for(j = rook2 - 1; j >= 0; j--) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'p') {
                sum++;
                break;
            } else {
                break;
            }         
        }
        for(i = rook1 + 1; i < boardSize; i++) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'p') {
                sum++;
                break;
            } else {
                break;
            }           
        }
        for(i = rook1 - 1; i >= 0; i--) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'p') {
                sum++;
                break;
            } else {
                break;
            }           
        }
    }
    if(black == 2) {
        for(j = rook2 + 1; j < boardSize; j++) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'P') {
                sum++;
                break;
            } else {
                break;
            }
        }
        for(j = rook2 - 1; j >= 0; j--) {
            if(board[rook1][j] == '.') {
                continue;
            } else if(board[rook1][j] == 'P') {
                sum++;
                break;
            } else {
                break;
            }         
        }
        for(i = rook1 + 1; i < boardSize; i++) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'P') {
                sum++;
                break;
            } else {
                break;
            }           
        }
        for(i = rook1 - 1; i >= 0; i--) {
            if(board[i][rook2] == '.') {
                continue;
            } else if(board[i][rook2] == 'P') {
                sum++;
                break;
            } else {
                break;
            }           
        }
    }
    return sum;
}